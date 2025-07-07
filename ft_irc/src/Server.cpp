#include "../inc/Server.hpp"
#include "../inc/Admin.hpp"

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::remove;
using std::istringstream;

Server::Server( int port, string passWord ) : _port(port), _serverFd(-1),
_epollFD(-1), _userLimit(10), _currentUsers(0), _passWord(passWord),
_running(true), _invite(false)
{
    string nickName;
    string userName;

    _admin.setAdminStatus();

    cout << "Enter admin nick name : ";
    getline(cin, nickName);
    cout << endl << "Enter admin user name : ";
    getline(cin, userName);
    cout << endl;
    cout << "Enter the Topic of the channel : ";
    getline(cin, _topic);
    cout << endl;

    _admin.setAdminNames(nickName, userName);
}

Server::~Server(){}

const string& Server::getPassWord() const
{
    return _passWord;
}

const string& Server::getTopic() const
{
    return _topic;
}

int Server::getPort() const
{
    return _port;
}

const std::string& Server::getAdminNickName() const
{
    return _admin.getNickName();
}

const std::string& Server::getAdminUserName() const
{
    return _admin.getUserName();
}

const std::string& Server::getStaffNickName() const
{
    return _admin.getNickName();
}

const std::string& Server::getStaffUserName() const
{
    return _admin.getUserName();
}

void Server::printMsgAdmin( int fd, const string& msg ) const
{
    if (fd != 0)
    {
        write(fd, VIOLET, strlen(VIOLET));
        write(fd, "(ADMIN😎)", 12);
        write(fd, RESET, strlen(RESET));
        write(fd, " ", 1);

        string nick = this->getAdminNickName();
        write(fd, nick.c_str(), nick.length());
        write(fd, " ", 1);
        string time = getCurrentTime();
        write(fd, time.c_str(), time.length());

        write(fd, "\n", 1);
        write(fd, msg.c_str(), msg.length());
        return ;
    }
    cout << VIOLET "(ADMIN😎)" RESET
        << " " + this->getAdminNickName()
        << " " + getCurrentTime()
        << endl
        << msg;
}

void Server::printMsgUser( int fd, const string& msg, const string& nickName ) const
{
    write(fd, CYAN, strlen(CYAN));
    write(fd, "(USER🙂)", 11);
    write(fd, RESET, strlen(RESET));
    write(fd, " ", 1);

    write(fd, nickName.c_str(), nickName.length());
    write(fd, " ", 1);
    string time = getCurrentTime();
    write(fd, time.c_str(), time.length());

    write(fd, "\n", 1);
    write(fd, msg.c_str(), msg.length());
}

void Server::printMsgStaff( int fd, const std::string& msg, const std::string& nickName ) const
{
    write(fd, BLEU, strlen(BLEU));
    write(fd, "(STAFF🤓)", 12);
    write(fd, RESET, strlen(RESET));
    write(fd, " ", 1);

    write(fd, nickName.c_str(), nickName.length());
    write(fd, " ", 1);
    string time = getCurrentTime();
    write(fd, time.c_str(), time.length());

    write(fd, "\n", 1);
    write(fd, msg.c_str(), msg.length());
}

string getCurrentTime()
{
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%H:%M", t);
    return string(buffer);
}

int Server::commandAdmin()
{
    string input;
    getline(std::cin, input);

    if (input == "QUIT")
    {
        this->printMsgAdmin(0, "Shutting down server.\n");
        _running = false;
        return -1;
    }

    istringstream iss(input);
    string cmd;
    iss >> cmd;

    if (cmd == "MODE")
    {
        string subcmd, nickname;
        iss >> subcmd;

        if (subcmd == "k")
        {
            string rest;
            getline(iss, rest); // récupère tout ce qui reste après "k"
            
            // Trim leading spaces
            rest.erase(0, rest.find_first_not_of(" \t"));

            if (rest.empty())
            {
                _passWord = "";
                cout << "[MODE] Password deleted." << endl;
            }
            else
            {
                _passWord = rest;
                cout << "[MODE] The new password is : " << _passWord << "." << endl;
            }
            return 0;
        }

        iss >> nickname;

        // MODE i : active/désactive le mode "invitation-only" du canal
        if (subcmd == "i" && nickname.empty())
        {
            _invite = !_invite;
            cout << "[MODE] Canal mode invitation ";
            cout << (_invite ? "ACTIVÉ." : "DÉSACTIVÉ.") << endl;
            return 0;
        }

        // MODE o <nickname> : promotion/démotion
        if (subcmd == "o" && !nickname.empty())
        {
            // Promotion
            std::map<int, User*>::iterator uit;
            for (uit = _users.begin(); uit != _users.end(); ++uit)
            {
                if (uit->second->getNickName() == nickname)
                {
                    if (userToStaff(uit->first) == 0)
                        cout << "[PROMOTION] " << nickname << " est maintenant staff." << endl;
                    else
                        cout << "[ERREUR] Impossible de promouvoir " << nickname << endl;
                    return 0;
                }
            }

            // Démotion
            std::map<int, Admin*>::iterator sit;
            for (sit = _staffs.begin(); sit != _staffs.end(); ++sit)
            {
                if (sit->second->getNickName() == nickname)
                {
                    if (staffToUser(sit->first) == 0)
                        cout << "[RÉTROGRADATION] " << nickname << " est redevenu user." << endl;
                    else
                        cout << "[ERREUR] Impossible de rétrograder " << nickname << endl;
                    return 0;
                }
            }

            cout << "[!] Aucun utilisateur trouvé avec le nickname : " << nickname << endl;
            return 0;
        }

        if (subcmd == "t" && !nickname.empty())
        {
            std::map<int, Admin*>::iterator sit;
            for (sit = _staffs.begin(); sit != _staffs.end(); ++sit)
            {
                if (sit->second->getNickName() == nickname)
                {
                    if (sit->second->getTStatus() == true)
                    {
                        sit->second->setTStatus(false);
                        string msg = "You are no longer entitled to the topic command.\n";
                        write(sit->first, msg.c_str(), msg.length());
                        return 0;
                    }
                    else if (sit->second->getTStatus() == false)
                    {
                        sit->second->setTStatus(true);
                        string msg = "You have rights again for the topic command.\n";
                        write(sit->first, msg.c_str(), msg.length());
                        return 0;
                    }
                }
            }
            cout << "[!] Aucun utilisateur trouvé avec le nickname : " << nickname << endl;
            return 0;
        }

        if (subcmd == "l")
        {
            if (nickname.empty())  // Pas de paramètre => suppression de la limite
            {
                _userLimit = -1;
                cout << "[MODE] Limite d'utilisateurs supprimée." << endl;
            }
            else  // MODE l <nombre>
            {
                istringstream numStream(nickname);
                int limit;
                numStream >> limit;
                if (limit < _currentUsers)
                    cout << "[MODE] Cannot define limit of users under number of current users." << endl;
                else if (limit > -1)
                {
                    _userLimit = limit;
                    cout << "[MODE] Limite d'utilisateurs définie à " << limit << "." << endl;
                }
                else
                    cout << "[ERREUR] Valeur invalide pour la limite : " << nickname << endl;
            }
            return 0;
        }

        // Commande invalide
        cout << "[ERREUR] Syntaxe invalide pour MODE." << endl;
    }
    else if (cmd == "KICK")
    {
        string kick_nick;
        iss >> kick_nick;

        if (!kick_nick.empty())
        {
            int fdToKick = -1;
            std::map<int, User*>::iterator it;
            for (it = _users.begin(); it != _users.end(); ++it)
            {
                if (it->second->getNickName() == kick_nick)
                {
                    fdToKick = it->first;
                    break;
                }
            }

            if (fdToKick != -1)
            {
                _userStates[fdToKick] = REGISTERED;
                _currentUsers -= 1;
                string kickMsg = ":server KICK " + kick_nick + " : " + getTopic() + "\r\n";
                write(fdToKick, kickMsg.c_str(), kickMsg.size());
                cout << "[KICK] " << kick_nick << " a été retiré du channel." << std::endl;
            }
            else
                cout << "[!] Aucun utilisateur trouvé avec le nickname : " << kick_nick << endl;
        }
        else
            cout << "[ERREUR] Syntaxe : KICK <nickname>" << endl;
    }
    else if (cmd == "INVITE")
    {
        string invite_nick;
        iss >> invite_nick;

        if (!invite_nick.empty())
        {
            bool found = false;

            std::map<int, User*>::iterator uit;
            for (uit = _users.begin(); uit != _users.end(); ++uit)
            {
                if (uit->second && uit->second->getNickName() == invite_nick)
                {
                    if (_currentUsers >= _userLimit)
                    {
                        string msg = "Cannot invite " + _users[uit->first]->getNickName() + " : the user limit is reached.";
                        cout << msg << endl;
                        return 0;
                    }
                    _userStates[uit->first] = JOINED;
                    _currentUsers += 1;
                    cout << "[INVITE] " << invite_nick << " a été invité à rejoindre le canal." << endl;

                    string notice = ":server NOTICE " + invite_nick + " : Vous avez été invité à rejoindre le channel.\r\n";
                    write(uit->first, notice.c_str(), notice.size());

                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "[!] Aucun utilisateur trouvé avec le nickname : " << invite_nick << endl;
        }
        else
            cout << "[ERREUR] Syntaxe : INVITE <nickname>" << endl;
    }
    else if (cmd == "TOPIC")
    {
        string channel_or_topic;
        getline(iss, channel_or_topic);

        // Trim leading spaces
        channel_or_topic.erase(0, channel_or_topic.find_first_not_of(" \t"));

        if (channel_or_topic.empty())
        {
            if (_topic.empty())
                cout << "[TOPIC] Aucun topic n'est défini." << endl;
            else
                cout << "[TOPIC] Sujet actuel : " << _topic << endl;
        }
        else
        {
            // Nouveau sujet
            size_t pos = channel_or_topic.find(':');
            if (pos != string::npos)
                _topic = channel_or_topic.substr(pos + 1);
            else
                _topic = channel_or_topic;

            cout << "[TOPIC] Nouveau sujet défini : " << _topic << endl;
        }
    }
    else if (cmd == "PRIVMSG")
    {
        string rest;
        getline(iss, rest);

        // Nettoyer les espaces en début
        rest.erase(0, rest.find_first_not_of(" \t"));

        // Séparer la cible et le message (message commence par :)
        size_t msg_pos = rest.find(" :");
        string target, msg;

        if (msg_pos != string::npos)
        {
            target = rest.substr(0, msg_pos);
            msg = rest.substr(msg_pos + 2); // saute " :"
        }
        else
        {
            target = rest;
            msg = "";
        }

        // Nettoyage
        target.erase(0, target.find_first_not_of(" \t"));
        target.erase(target.find_last_not_of(" \t") + 1);

        // Vérif de base
        if (target.empty() || msg.empty())
        {
            cout << "[PRIVMSG] Erreur : PRIVMSG <cible> :<message>\n";
            return 0;
        }

        string adminNick = this->getAdminNickName();

        // Cas 1 : message vers un canal
        if (target == "#" + this->getTopic())
        {
            string fullMsg = string("Channel ") + ("#") + _topic + " : " + msg + "\r\n";

            // Envoyer aux users
            for (std::map<int, User*>::iterator it = _users.begin(); it != _users.end(); ++it)
            {
                int fd = it->first;
                if (_userStates[fd] == JOINED)
                    this->printMsgAdmin(fd, fullMsg);
            }

            // Envoyer aux autres staffs
            for (std::map<int, Admin*>::iterator it = _staffs.begin(); it != _staffs.end(); ++it)
                this->printMsgAdmin(it->first, fullMsg);
            return 0;
        }

        // Cas 2 : message privé à un user/staff
        int receiver_fd = -1;

        // Cherche parmi les users
        for (std::map<int, User*>::iterator it = _users.begin(); it != _users.end(); ++it)
        {
            if (it->second && it->second->getNickName() == target)
            {
                receiver_fd = it->first;
                break;
            }
        }

        // Sinon cherche parmi les staffs
        if (receiver_fd == -1)
        {
            for (std::map<int, Admin*>::iterator it = _staffs.begin(); it != _staffs.end(); ++it)
            {
                if (it->second && it->second->getNickName() == target)
                {
                    receiver_fd = it->first;
                    break;
                }
            }
        }

        string fullMsg = "MP to you : " + msg + "\r\n";

        if (receiver_fd != -1)
            this->printMsgAdmin(receiver_fd, fullMsg);
        else
        {
            string err = ":server 401 " + target + " :No such nick/channel\r\n";
            cout << "[PRIVMSG] Erreur : utilisateur " << target << " introuvable.\n";
        }

        return 0;
    }
    else
        cout << "[Server command] " << input << endl;

    return 0;
}

int Server::commandUserStaff( int event_fd )
{
    memset(_buffer, 0, IRC_MESSAGE_MAX);
    int count = read(event_fd, _buffer, IRC_MESSAGE_MAX);
    if (count <= 0)
    {
        if (_users[event_fd] && _users[event_fd]->getStatus())
        {
            cout << "Client disconnected: " << _users[event_fd]->getNickName() << endl;
            close(event_fd);
            epoll_ctl(_epollFD, EPOLL_CTL_DEL, event_fd, NULL);
            delete _users[event_fd];
            _users.erase(event_fd);
            _userStates.erase(event_fd);
            _tempNick.erase(event_fd);
            _tempUser.erase(event_fd);
            _currentUsers -= 1;
            return -1;
        }
        else if (_staffs[event_fd] && _staffs[event_fd]->getStatus())
        {
            cout << "Staff disconnected: " << _staffs[event_fd]->getNickName() << endl;
            close(event_fd);
            epoll_ctl(_epollFD, EPOLL_CTL_DEL, event_fd, NULL);
            delete _staffs[event_fd];
            _staffs.erase(event_fd);
            _staffStates.erase(event_fd);
            _currentUsers -= 1;
            return -1;
        }
    }

    string input(_buffer, count);
    input.erase(remove(input.begin(), input.end(), '\n'), input.end());
    input.erase(remove(input.begin(), input.end(), '\r'), input.end());

    if (_userStates[event_fd] == REGISTERED || _userStates[event_fd] == JOINED
        || _staffStates[event_fd] == JOINED)
    {

        istringstream iss(input);
        string command;
        iss >> command;

        if (_staffStates[event_fd] == JOINED)
        {
            if (command == "MODE")
            {
                string subcmd, nickname;
                iss >> subcmd;

                if (subcmd == "k")
                {
                    string rest;
                    getline(iss, rest); // récupère tout ce qui reste après "k"
                    
                    // Trim leading spaces
                    rest.erase(0, rest.find_first_not_of(" \t"));

                    if (rest.empty())
                    {
                        _passWord = "";
                        write(event_fd, "[MODE] Password deleted.\n", 26);
                    }
                    else
                    {
                        _passWord = rest;
                        string msg = "[MODE] The new password is : " +  _passWord + ".\n";
                        write(event_fd, msg.c_str(), msg.length());
                    }
                    return 0;
                }

                iss >> nickname;

                // MODE i : active/désactive le mode "invitation-only" du canal
                if (subcmd == "i" && nickname.empty())
                {
                    _invite = !_invite;
                    string msg = string("[MODE] Canal mode invitation ") + (_invite ? "ACTIVÉ.\n" : "DÉSACTIVÉ.\n");
                    write(event_fd, msg.c_str(), msg.length());
                    return 0;
                }

                // MODE o <nickname> : promotion/démotion
                if (subcmd == "o" && !nickname.empty()
                    && nickname != _staffs[event_fd]->getNickName())
                {
                    // Promotion
                    string msg = "[PROMOTION] " + nickname + " est maintenant staff.\n";
                    string msg2 = "[PROMOTION] " + nickname + " you are now staff.\n";
                    string err = "[ERREUR] Impossible de promouvoir " + nickname + ".\n";
                    std::map<int, User*>::iterator uit;
                    for (uit = _users.begin(); uit != _users.end(); ++uit)
                    {
                        if (uit->second->getNickName() == nickname)
                        {
                            if (userToStaff(uit->first) == 0)
                            {
                                write(event_fd, msg.c_str(), msg.length());
                                write(uit->first, msg2.c_str(), msg2.length());
                            }
                            else
                                write(event_fd, err.c_str(), err.length());
                            return 0;
                        }
                    }

                    // Démotion
                    msg = "[RÉTROGRADATION] " + nickname + " est redevenu user.\n";
                    msg2 = "[RÉTROGRADATION] " + nickname + " you are now user.\n";
                    err = "[ERREUR] Impossible de rétrograder " + nickname + ".\n";
                    string err2 = "[!] Aucun utilisateur trouvé avec le nickname : " + nickname + ".\n";
                    std::map<int, Admin*>::iterator sit;
                    for (sit = _staffs.begin(); sit != _staffs.end(); ++sit)
                    {
                        if (sit->second->getNickName() == nickname)
                        {
                            if (staffToUser(sit->first) == 0)
                            {
                                write(event_fd, msg.c_str(), msg.length());
                                write(sit->first, msg2.c_str(), msg2.length());
                            }
                            else
                                write(event_fd, err.c_str(), err.length());
                            return 0;
                        }
                    }

                    write(event_fd, err2.c_str(), err2.length());
                    return 0;
                }

                if (subcmd == "t" && !nickname.empty()
                    && _staffs[event_fd]->getTStatus() == true)
                {
                    string err = "[!] Aucun utilisateur trouvé avec le nickname : " + nickname + ".\n";
                    std::map<int, Admin*>::iterator sit;
                    for (sit = _staffs.begin(); sit != _staffs.end(); ++sit)
                    {
                        if (sit->second->getNickName() == nickname)
                        {
                            if (sit->second->getTStatus() == true)
                            {
                                sit->second->setTStatus(false);
                                string msg = "You are no longer entitled to the topic command.\n";
                                write(sit->first, msg.c_str(), msg.length());
                                return 0;
                            }
                            else if (sit->second->getTStatus() == false)
                            {
                                sit->second->setTStatus(true);
                                string msg = "You have rights again for the topic command.\n";
                                write(sit->first, msg.c_str(), msg.length());
                                return 0;
                            }
                        }
                    }
                    write(event_fd, err.c_str(), err.length());
                    return 0;
                }

                if (subcmd == "l")
                {
                    if (nickname.empty())  // Pas de paramètre => suppression de la limite
                    {
                        _userLimit = -1;
                        string msg = "[MODE] Limite d'utilisateurs supprimée.\n";
                        write(event_fd, msg.c_str(), msg.length());
                    }
                    else  // MODE l <nombre>
                    {
                        istringstream numStream(nickname);
                        int limit;
                        numStream >> limit;
                        string err1 = "[MODE] Cannot define limit of users under number of current users.\n";
                        std::ostringstream oss;
                        oss << "[MODE] Limite d'utilisateurs définie à " << limit << ".\n";
                        std::string msg = oss.str();
                        string err2 = "[ERREUR] Valeur invalide pour la limite : " + nickname + ".\n";
                        if (limit < _currentUsers)
                            write(event_fd, err1.c_str(), err1.length());
                        else if (limit > -1)
                        {
                            _userLimit = limit;
                            write(event_fd, msg.c_str(), msg.length());
                        }
                        else
                            write(event_fd, err2.c_str(), err2.length());
                    }
                    return 0;
                }
                // Commande invalide
                string err3 = "[ERREUR] Syntaxe invalide pour MODE.\n";
                write(event_fd, err3.c_str(), err3.length());
                return 0;
            }
            else if (command == "KICK")
            {
                string kick_nick;
                iss >> kick_nick;

                if (!kick_nick.empty())
                {
                    int fdToKick = -1;
                    std::map<int, User*>::iterator it;
                    for (it = _users.begin(); it != _users.end(); ++it)
                    {
                        if (it->second->getNickName() == kick_nick)
                        {
                            fdToKick = it->first;
                            break;
                        }
                    }

                    if (fdToKick != -1)
                    {
                        _userStates[fdToKick] = REGISTERED;
                        _currentUsers -= 1;
                        string kickMsg = ":server KICK " + kick_nick + " : " + getTopic() + "\r\n";
                        string msg = "[KICK] " + kick_nick + " a été retiré du channel.\n";
                        write(fdToKick, kickMsg.c_str(), kickMsg.size());
                        write(event_fd, msg.c_str(), msg.length());
                    }
                    else
                    {
                        string err = "[!] Aucun utilisateur trouvé avec le nickname : " + kick_nick + ".\n";
                        write(event_fd, err.c_str(), err.length());
                        return 0;
                    }
                }
                else
                {
                    string err = "[ERREUR] Syntaxe : KICK <nickname>\n";
                    write(event_fd, err.c_str(), err.length());
                }
                return 0;
            }
            else if (command == "INVITE")
            {
                string invite_nick;
                iss >> invite_nick;

                if (!invite_nick.empty())
                {
                    bool found = false;

                    std::map<int, User*>::iterator uit;
                    for (uit = _users.begin(); uit != _users.end(); ++uit)
                    {
                        if (uit->second && uit->second->getNickName() == invite_nick)
                        {
                            if (_currentUsers >= _userLimit)
                            {
                                string msg = "Cannot invite " + _users[uit->first]->getNickName() + " : the user limit is reached.\n";
                                write(event_fd, msg.c_str(), msg.length());
                                return 0;
                            }
                            _userStates[uit->first] = JOINED;
                            _currentUsers += 1;

                            string notice = ":server NOTICE " + invite_nick + " : Vous avez été invité à rejoindre le channel.\r\n";
                            write(uit->first, notice.c_str(), notice.size());

                            found = true;
                            break;
                        }
                    }

                    if (!found)
                    {
                        string err = "[!] Aucun utilisateur trouvé avec le nickname : " + invite_nick + ".\n";
                        write(event_fd, err.c_str(), err.length());
                    }
                    return 0;
                }
                else
                {
                    string err = "[ERREUR] Syntaxe : INVITE <nickname>\n";
                    write(event_fd, err.c_str(), err.length());
                }
                return 0;
            }
            else if (command == "TOPIC" && _staffs[event_fd]->getTStatus() == true)
            {
                string channel_or_topic;
                getline(iss, channel_or_topic);

                // Trim leading spaces
                channel_or_topic.erase(0, channel_or_topic.find_first_not_of(" \t"));

                string msg;
                if (channel_or_topic.empty())
                {
                    if (_topic.empty())
                    {
                        msg = "[TOPIC] Aucun topic n'est défini.\n";
                        write(event_fd, msg.c_str(), msg.length());
                    }
                    else
                    {
                        msg = "[TOPIC] Sujet actuel : " + _topic + ".\n";
                        write(event_fd, msg.c_str(), msg.length());
                    }
                }
                else
                {
                    // Nouveau sujet
                    size_t pos = channel_or_topic.find(':');
                    if (pos != string::npos)
                        _topic = channel_or_topic.substr(pos + 1);
                    else
                        _topic = channel_or_topic;

                    msg = "[TOPIC] Nouveau sujet défini : " + _topic + ".\n";
                    write(event_fd, msg.c_str(), msg.length());
                }
                return 0;
            }
        }

        // Récupère le reste de la ligne après la commande
        string rest;
        getline(iss, rest);

        // Nettoyer les espaces en début
        rest.erase(0, rest.find_first_not_of(" \t"));

        // Séparer le message (commence par :)
        size_t msg_pos = rest.find(" :");
        string target, msg;

        if (msg_pos != string::npos)
        {
            target = rest.substr(0, msg_pos);
            msg = rest.substr(msg_pos + 2); // saute " :"
        }
        else
        {
            target = rest;
            msg = "";
        }

        // Trim le target
        target.erase(0, target.find_first_not_of(" \t"));
        target.erase(target.find_last_not_of(" \t") + 1);

        // Vérification
        if (command == "PRIVMSG")
        {
            if (target.empty() || msg.empty())
            {
                string err = ":server 461 * PRIVMSG :Not enough parameters\r\n";
                write(event_fd, err.c_str(), err.size());
                return -1;
            }
        }

        if ((_users.count(event_fd) || _staffs.count(event_fd)) && command == "PRIVMSG")  // On vérifie que l'expéditeur existe
        {
            // Vérifie que l'expéditeur est valide et récupère son nickname
            string nickname;
            if (_users.count(event_fd) && _users[event_fd])
                nickname = _users[event_fd]->getNickName();
            else if (_staffs.count(event_fd) && _staffs[event_fd])
                nickname = _staffs[event_fd]->getNickName();
            else
                return -1; // Expéditeur non valide

            // Recherche d'un destinataire avec ce nick
            int receiver_fd = -1;
            std::map<int, User*>::iterator uit;
            for (uit = _users.begin(); uit != _users.end(); ++uit)
            {
                if (uit->second && uit->second->getNickName() == target)
                {
                    receiver_fd = uit->first;
                    break;
                }
            }

            if (receiver_fd == -1)
            {
                std::map<int, Admin*>::iterator ait;
                for (ait = _staffs.begin(); ait != _staffs.end(); ++ait)
                {
                    if (ait->second && ait->second->getNickName() == target)
                    {
                        receiver_fd = ait->first;
                        break;
                    }
                }
            }

            string fullMsg = nickname + " to you : " + msg + "\r\n";
            if (target == this->getAdminNickName())
                cout << fullMsg;
            else if (receiver_fd != -1)
                write(receiver_fd, fullMsg.c_str(), fullMsg.size());
            else
            {
                string topic = this->getTopic();
                if (target != topic && target != "#" + topic)
                {
                    string err = ":server 401 " + target + " :No such nick/channel\r\n";
                    write(event_fd, err.c_str(), err.size());
                }
            }
        }
    }

    switch (_userStates[event_fd])
    {
        case WAIT_NICK:
        {
            istringstream iss(input);
            string command;
            iss >> command;

            string nick;
            getline(iss, nick);
            nick.erase(0, nick.find_first_not_of(" \t"));

            if (command != "NICK" || nick.empty())
            {
                const char* msg = ":server 431 * :No nickname given\r\n";
                write(event_fd, msg, strlen(msg));
            }
            else
            {
                bool nicknameTaken = false;

                // Vérifier si le nickname existe déjà dans les utilisateurs
                for (std::map<int, User*>::iterator it = _users.begin(); it != _users.end(); ++it)
                {
                    if (it->second && it->second->getNickName() == nick)
                    {
                        nicknameTaken = true;
                        break;
                    }
                }

                // Vérifier si le nickname existe déjà dans les admins
                if (!nicknameTaken)
                {
                    for (std::map<int, Admin*>::iterator it = _staffs.begin(); it != _staffs.end(); ++it)
                    {
                        if (it->second && it->second->getNickName() == nick)
                        {
                            nicknameTaken = true;
                            break;
                        }
                    }
                }

                // Vérifier si un autre client l’a temporairement pris
                if (!nicknameTaken)
                {
                    for (std::map<int, std::string>::iterator it = _tempNick.begin(); it != _tempNick.end(); ++it)
                    {
                        if (it->first != event_fd && it->second == nick)
                        {
                            nicknameTaken = true;
                            break;
                        }
                    }
                }

                if (!nicknameTaken)
                {
                    if (this->getAdminNickName() == nick)
                        nicknameTaken = true;
                }

                if (nicknameTaken)
                {
                    string err = ":server 433 * " + nick + " :Nickname is already in use\r\n";
                    write(event_fd, err.c_str(), err.size());
                }
                else
                {
                    _tempNick[event_fd] = nick;
                    _userStates[event_fd] = WAIT_USER;
                }
            }
            break;
        }
        case WAIT_USER:
        {
            istringstream iss(input);
            string command, username, hostname, servername, realname;
            iss >> command >> username >> hostname >> servername;
            getline(iss, realname);
            if (!realname.empty() && realname[0] == ' ')
                realname.erase(0,1);
            if (command != "USER" || username.empty())
            {
                const char* msg = ":server 461 * USER :Not enough parameters\r\n";
                write(event_fd, msg, strlen(msg));
            }
            else
            {
                _tempUser[event_fd] = username;
                _userStates[event_fd] = REGISTERED;
                _users[event_fd]->setNickName(_tempNick[event_fd]);
                _users[event_fd]->setUserName(_tempUser[event_fd]);
                _users[event_fd]->setStatus(true);

                string welcome = ":server 001 " + _tempNick[event_fd] + " :Welcome to the IRC server!\r\n";
                write(event_fd, welcome.c_str(), welcome.size());

                _tempNick.erase(event_fd);
                _tempUser.erase(event_fd);
            }
            break;
        }
        case REGISTERED:
        {
            istringstream iss(input);
            string command;
            iss >> command;

            if (command == "JOIN")
            {
                string channel;
                getline(iss, channel);
                channel.erase(0, channel.find_first_not_of(" \t"));
                if (channel.empty())
                {
                    const char* msg = ":server 461 * JOIN :Not enough parameters\r\n";
                    write(event_fd, msg, strlen(msg));
                    break;
                }
                if (channel != this->getTopic())
                {
                    string msg = ":server 403 * " + channel + " :No such channel\r\n";
                    write(event_fd, msg.c_str(), msg.size());
                    break;
                }
                if (_invite == true)
                {
                    string msg = ":server 473 * " + channel + " :This channel is by invitation only\r\n";
                    write(event_fd, msg.c_str(), msg.length());
                    break;
                }
                if (_currentUsers == _userLimit)
                {
                    string err = ":server 471 " + _users[event_fd]->getNickName() + " #" + _topic + " : Cannot join channel (limit reached)\r\n";
                    write(event_fd, err.c_str(), err.size());
                    break;
                }
                if (_passWord.empty())
                {
                    string msg = "✅ You have joined channel " + this->getTopic() + "\r\n";
                    write(event_fd, msg.c_str(), msg.size());

                    cout << "User " << _users[event_fd]->getNickName()
                                << " joined channel: " << this->getTopic() << endl;

                    _users[event_fd]->setStatus(true);
                    _userStates[event_fd] = JOINED;
                    _currentUsers += 1;
                    break;
                }

                channel = "Please enter password : ";
                write(event_fd, channel.c_str(), channel.length());
                _userStates[event_fd] = WAIT_PASSWORD;
            }
            else if (command == "PRIVMSG")
                break;
            else
            {
                string msg = ":server 421 * " + command + " :Unknown command\r\n";
                write(event_fd, msg.c_str(), msg.size());
            }
            break;
        }
        case WAIT_PASSWORD:
        {
            string password = input;
            password.erase(remove(password.begin(), password.end(), '\n'), password.end());
            password.erase(remove(password.begin(), password.end(), '\r'), password.end());

            if (password == this->getPassWord())
            {
                string msg = "✅ You have joined channel " + this->getTopic() + "\r\n";
                write(event_fd, msg.c_str(), msg.size());

                cout << "User " << _users[event_fd]->getNickName()
                            << " joined channel: " << this->getTopic() << endl;

                _users[event_fd]->setStatus(true);
                _userStates[event_fd] = JOINED;
                _currentUsers += 1;
            }
            else
            {
                const char* msg = "❌ Password invalid!\r\n";
                write(event_fd, msg, strlen(msg));
                _userStates[event_fd] = REGISTERED;
            }
            break;
        }
        case JOINED:
        {
            istringstream iss(input);
            string command;
            iss >> command;

            // Récupère le reste de la ligne après la commande
            std::string rest;
            std::getline(iss, rest);

            // Nettoyer les espaces en début
            rest.erase(0, rest.find_first_not_of(" \t"));

            // Séparer le message (commence par :)
            size_t msg_pos = rest.find(" :");
            string target, msg;

            if (msg_pos != string::npos) {
                target = rest.substr(0, msg_pos);
                msg = rest.substr(msg_pos + 2); // saute " :"
            } else {
                target = rest;
                msg = "";
            }

            // Trim le target
            target.erase(0, target.find_first_not_of(" \t"));
            target.erase(target.find_last_not_of(" \t") + 1);

            // Vérification
            if (_users.count(event_fd))
            {
                if (command != "PRIVMSG" || target.empty() || msg.empty()) {
                    string err = ":server 461 * PRIVMSG :Not enough parameters\r\n";
                    write(event_fd, err.c_str(), err.size());
                }
            }


            if (target == ("#" + this->getTopic()))
            {
                string nickname;
                void (Server::*function)(int, const string &, const string &) const;

                if (_users.count(event_fd))
                {
                    nickname = _users[event_fd]->getNickName();
                    function = &Server::printMsgUser;
                }
                else if (_staffs.count(event_fd))
                {
                    nickname = _staffs[event_fd]->getNickName();
                    function = &Server::printMsgStaff;
                }

                string fullMsg = "Channel " + target + " : " + msg + "\r\n";

                for (std::map<int, User*>::iterator it = _users.begin(); it != _users.end(); ++it)
                {
                    int fd = it->first;
                    if (_userStates[fd] == JOINED && fd != event_fd)
                        (this->*function)(fd, fullMsg, nickname);
                }
                for (std::map<int, Admin*>::iterator it = _staffs.begin(); it != _staffs.end(); ++it)
                {
                    int fd = it->first;
                    if (fd != event_fd)
                        (this->*function)(fd, fullMsg, nickname);
                }
                (this->*function)(1, fullMsg, nickname);
            }
            break;
        }
        default:
            break;
    }
    return 0;
}

void Server::run()
{
    while (_running)
    {
        int n = epoll_wait(_epollFD, _events, MAX_EVENTS, -1);
        if (n == -1)
        {
            perror("epoll_wait");
            break;
        }

        for (int i = 0; i < n; ++i)
        {
            int event_fd = _events[i].data.fd;

            if (event_fd == _serverFd)
            {
                if (this->createNewUser() == -1)
                    continue;
            }
            else if (event_fd == STDIN_FILENO)
            {
                if (this->commandAdmin() == -1)
                    continue;
            }
            else
            {
                if (this->commandUserStaff(event_fd) == -1)
                    continue;
            }
        }
    }
    this->freeData();
    close(_epollFD);
    close(_serverFd);
}
