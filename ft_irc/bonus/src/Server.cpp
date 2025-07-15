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
_running(true), _invite(false), _OnOff(true)
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

void Server::printMsgServer( int fd, const string& msg ) const
{
    if (fd != 0)
    {
        write(fd, RED, strlen(RED));
        write(fd, "(SERVER", 8);
        write(fd, RESET, strlen(RESET));
        write(fd, "🖥", 5);
        write(fd, RED, strlen(RED));
        write(fd, ")", 1);
        write(fd, RESET, strlen(RESET));
        write(fd, " ", 1);

        string time = getCurrentTime();
        write(fd, time.c_str(), time.length());

        write(fd, "\n", 1);
        write(fd, msg.c_str(), msg.length());
        write(fd, "\n", 1);
        return ;
    }
    write(1, RED, strlen(RED));
    write(1, "(SERVER", 8);
    write(1, RESET, strlen(RESET));
    write(1, "🖥", 5);
    write(1, RED, strlen(RED));
    write(1, ")", 1);
    write(1, RESET, strlen(RESET));
    write(1, " ", 1);

    string time = getCurrentTime();
    write(1, time.c_str(), time.length());

    write(1, "\n", 1);
    write(1, msg.c_str(), msg.length());
    write(1, "\n", 1);
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

    if (cmd == "BOT")
    {
        string subcmd;
        iss >> subcmd;

        if (subcmd == "ON")
        {
            if (_OnOff == true)
            {
                this->printMsgServer(0, "[ERROR] Bot is already ON.");
                return -1;
            }
            _OnOff = true;
            string fullMsg = "Bot Parrot is now ON.\r\n";
            for (std::map<int, User*>::iterator it = _users.begin(); it != _users.end(); ++it)
            {
                int fd = it->first;
                if (_userStates[fd] == JOINED)
                    this->printMsgAdmin(fd, fullMsg);
            }
            for (std::map<int, Admin*>::iterator it = _staffs.begin(); it != _staffs.end(); ++it)
                this->printMsgAdmin(it->first, fullMsg);
            this->printMsgServer(0, "Bot Parrot is now ON.");
            return 0;
        }
        else if (subcmd == "OFF")
        {
            if (_OnOff == false)
            {
                this->printMsgServer(0, "[ERROR] Bot is already OFF.");
                return -1;
            }
            _OnOff = false;
            string fullMsg = "Bot Parrot is now OFF.\r\n";
            for (std::map<int, User*>::iterator it = _users.begin(); it != _users.end(); ++it)
            {
                int fd = it->first;
                if (_userStates[fd] == JOINED)
                    this->printMsgAdmin(fd, fullMsg);
            }
            for (std::map<int, Admin*>::iterator it = _staffs.begin(); it != _staffs.end(); ++it)
                this->printMsgAdmin(it->first, fullMsg);
            this->printMsgServer(0, "Bot Parrot is now OFF.");
            return 0;
        }
        this->printMsgServer(0, "[ERROR] Good format of command BOT is : BOT ON/OFF");
        return -1;
    }

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
                this->printMsgServer(0, "[MODE k] Password deleted.");
            }
            else
            {
                _passWord = rest;
                this->printMsgServer(0, "[MODE k] The new password is : " + _passWord + ".");
            }
            return 0;
        }

        iss >> nickname;

        // MODE i : active/désactive le mode "invitation-only" du canal
        if (subcmd == "i" && nickname.empty())
        {
            _invite = !_invite;
            this->printMsgServer(0, "[MODE i] Channel mode invitation " + string(_invite ? "ON." : "OFF."));
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
                    {
                        this->printMsgServer(0, "[PROMOTION] " + nickname + " is now staff.");
                        this->printMsgServer(uit->first, "[PROMOTION] " + nickname + " you are now staff.");
                    }
                    else
                        this->printMsgServer(0, "[ERROR] Impossible to promote " + nickname + ".");
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
                    {
                        this->printMsgServer(0, "[DEMOTION] " + nickname + " has become again user.");
                        this->printMsgServer(sit->first, "[DEMOTION] " + nickname + " you become again user.");
                    }
                    else
                        this->printMsgServer(0, "[ERROR] Impossible to downgrade " + nickname);
                    return 0;
                }
            }

            this->printMsgServer(0, "[ERROR] No users found with the nickname : " + nickname + ".");
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
                        string msg = "You are no longer entitled to the topic command.";
                        this->printMsgServer(0, nickname + " is no longer entitled to the topic command.");
                        this->printMsgServer(sit->first, msg);
                        return 0;
                    }
                    else if (sit->second->getTStatus() == false)
                    {
                        sit->second->setTStatus(true);
                        string msg = "You have rights again for the topic command.";
                        this->printMsgServer(0, nickname + " have rights again for the topic command.");
                        this->printMsgServer(sit->first, msg);
                        return 0;
                    }
                }
            }
            this->printMsgServer(0, "[ERROR] No admin found with the nickname : " + nickname + ".");
            return 0;
        }

        if (subcmd == "l")
        {
            if (nickname.empty())  // Pas de paramètre => suppression de la limite
            {
                _userLimit = -1;
                this->printMsgServer(0, "[MODE l] User limit removed.");
            }
            else  // MODE l <nombre>
            {
                istringstream numStream(nickname);
                int limit;
                numStream >> limit;
                if (limit < _currentUsers)
                    this->printMsgServer(0, "[MODE l] Cannot define limit of users under number of current users.");
                else if (limit > -1)
                {
                    _userLimit = limit;
                    std::ostringstream oss;
                    oss << limit;
                    string strLimit = oss.str();
                    this->printMsgServer(0, string("[MODE] User limit defined at ") + strLimit + ".");
                }
                else
                    this->printMsgServer(0, "[ERROR] Invalid value for the limit.");
            }
            return 0;
        }

        // Commande invalide
        this->printMsgServer(0, "[ERROR] Syntax invalid for MODE.");
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
                string kickMsg = "You are kick from channel : " + getTopic();
                this->printMsgServer(fdToKick, kickMsg);
                this->printMsgServer(0, "[KICK] " + kick_nick + " has been kicked from channel.");
            }
            else
                this->printMsgServer(0, "[ERROR] No users found with the nickname : " + kick_nick + ".");
        }
        else
            this->printMsgServer(0, "[ERROR] Syntaxe : KICK <nickname>.");
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
                        this->printMsgServer(0, msg);
                        return 0;
                    }
                    _userStates[uit->first] = JOINED;
                    _currentUsers += 1;
                    this->printMsgServer(0, "[INVITE] " + invite_nick + " has been invited to join the channel.");

                    string notice = invite_nick + " : You have been invited to join the channel.";
                    this->printMsgServer(uit->first, notice);

                    found = true;
                    break;
                }
            }

            if (!found)
                this->printMsgServer(0, "[ERROR] No users found with the nickname : " + invite_nick + ".");
        }
        else
            this->printMsgServer(0, "[ERREUR] Syntaxe : INVITE <nickname>.");
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
                this->printMsgServer(0, "[TOPIC] None topic defined.");
            else
                this->printMsgServer(0, "[TOPIC] Current topic : " + _topic);
        }
        else
        {
            // Nouveau sujet
            size_t pos = channel_or_topic.find(':');
            if (pos != string::npos)
                _topic = channel_or_topic.substr(pos + 1);
            else
                _topic = channel_or_topic;

            this->printMsgServer(0, "[TOPIC] New topic defined : " + _topic);
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
            this->printMsgServer(0, "[ERROR] User " + target + " not found.");

        return 0;
    }
    else
        this->printMsgServer(0, "[ERROR] Command not found : " + cmd + ".");

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
            this->printMsgServer(0, "Client disconnected: " + _users[event_fd]->getNickName());
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
            this->printMsgServer(0, "Staff disconnected: " + _staffs[event_fd]->getNickName());
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
                        this->printMsgServer(event_fd, "[MODE k] Password deleted.");
                    }
                    else
                    {
                        _passWord = rest;
                        this->printMsgServer(event_fd, "[MODE k] The new password is : " + _passWord + ".");
                    }
                    return 0;
                }

                iss >> nickname;

                // MODE i : active/désactive le mode "invitation-only" du canal
                if (subcmd == "i" && nickname.empty())
                {
                    _invite = !_invite;
                    this->printMsgServer(event_fd, "[MODE i] Channel mode invitation " + string(_invite ? "ON." : "OFF."));
                    return 0;
                }

                // MODE o <nickname> : promotion/démotion
                if (subcmd == "o" && !nickname.empty()
                    && nickname != _staffs[event_fd]->getNickName())
                {
                    // Promotion
                    std::map<int, User*>::iterator uit;
                    for (uit = _users.begin(); uit != _users.end(); ++uit)
                    {
                        if (uit->second->getNickName() == nickname)
                        {
                            if (userToStaff(uit->first) == 0)
                            {
                                this->printMsgServer(event_fd, "[PROMOTION] " + nickname + " is now staff.");
                                this->printMsgServer(uit->first, "[PROMOTION] " + nickname + " you are now staff.");
                            }
                            else
                                this->printMsgServer(event_fd, "[ERROR] Impossible to promote " + nickname + ".");
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
                            {
                                this->printMsgServer(event_fd, "[DEMOTION] " + nickname + " has become again user.");
                                this->printMsgServer(sit->first, "[DEMOTION] " + nickname + " you become again user.");
                            }
                            else
                                this->printMsgServer(event_fd, "[ERROR] Impossible to downgrade " + nickname);
                            return 0;
                        }
                    }

                    this->printMsgServer(event_fd, "[ERROR] No users found with the nickname : " + nickname + ".");
                    return 0;
                }

                if (subcmd == "t" && !nickname.empty()
                    && _staffs[event_fd]->getTStatus() == true
                    && nickname != _staffs[event_fd]->getNickName())
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
                                this->printMsgServer(event_fd, nickname + " is no longer entitled to the topic command.");
                                this->printMsgServer(sit->first, msg);
                                return 0;
                            }
                            else if (sit->second->getTStatus() == false)
                            {
                                sit->second->setTStatus(true);
                                string msg = "You have rights again for the topic command.\n";
                                this->printMsgServer(event_fd, nickname + " have rights again for the topic command.");
                                this->printMsgServer(sit->first, msg);
                                return 0;
                            }
                        }
                    }
                    this->printMsgServer(event_fd, "[ERROR] No admin found with the nickname : " + nickname + ".");
                    return 0;
                }

                if (subcmd == "l")
                {
                    if (nickname.empty())  // Pas de paramètre => suppression de la limite
                    {
                        _userLimit = -1;
                        this->printMsgServer(event_fd, "[MODE l] User limit removed.");
                    }
                    else  // MODE l <nombre>
                    {
                        istringstream numStream(nickname);
                        int limit;
                        numStream >> limit;
                        if (limit < _currentUsers)
                            this->printMsgServer(event_fd, "[MODE l] Cannot define limit of users under number of current users.");
                        else if (limit > -1)
                        {
                            _userLimit = limit;
                            std::ostringstream oss;
                            oss << limit;
                            string strLimit = oss.str();
                            this->printMsgServer(event_fd, string("[MODE] User limit defined at ") + strLimit + ".");
                        }
                        else
                            this->printMsgServer(event_fd, "[ERROR] Invalid value for the limit.");
                    }
                    return 0;
                }
                // Commande invalide
                string err3 = "[ERROR] Invalid syntax for MODE.";
                this->printMsgServer(event_fd, err3);
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
                        string kickMsg = "You are kick from channel : " + getTopic();
                        this->printMsgServer(fdToKick, kickMsg);
                        this->printMsgServer(event_fd, "[KICK] " + kick_nick + " has been kicked from channel.");
                    }
                    else
                        this->printMsgServer(event_fd, "[ERROR] No users found with the nickname : " + kick_nick + ".");
                }
                else
                    this->printMsgServer(event_fd, "[ERROR] Syntaxe : KICK <nickname>.");
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
                                string msg = "Cannot invite " + _users[uit->first]->getNickName() + " : the user limit is reached.";
                                this->printMsgServer(event_fd, msg);
                                return 0;
                            }
                            _userStates[uit->first] = JOINED;
                            _currentUsers += 1;

                            this->printMsgServer(event_fd, "[INVITE] " + invite_nick + " has been invited to join the channel.");

                            string notice = invite_nick + " : You have been invited to join the channel.";
                            this->printMsgServer(uit->first, notice);

                            found = true;
                            break;
                        }
                    }

                    if (!found)
                        this->printMsgServer(event_fd, "[ERROR] No users found with the nickname : " + invite_nick + ".");
                    return 0;
                }
                else
                    this->printMsgServer(event_fd, "[ERREUR] Syntaxe : INVITE <nickname>.");
                return 0;
            }
            else if (command == "TOPIC" && _staffs[event_fd]->getTStatus() == true)
            {
                string channel_or_topic;
                getline(iss, channel_or_topic);

                // Trim leading spaces
                channel_or_topic.erase(0, channel_or_topic.find_first_not_of(" \t"));

                if (channel_or_topic.empty())
                {
                    if (_topic.empty())
                        this->printMsgServer(event_fd, "[TOPIC] None topic defined.");
                    else
                        this->printMsgServer(event_fd, "[TOPIC] Current topic : " + _topic);
                }
                else
                {
                    // Nouveau sujet
                    size_t pos = channel_or_topic.find(':');
                    if (pos != string::npos)
                        _topic = channel_or_topic.substr(pos + 1);
                    else
                        _topic = channel_or_topic;

                    this->printMsgServer(event_fd, "[TOPIC] New topic defined : " + _topic);
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
                string err = "[ERROR] PRIVMSG : Not enough parameters.";
                this->printMsgServer(event_fd, err);
                return -1;
            }
        }

        if ((_users.count(event_fd) || _staffs.count(event_fd)) && command == "PRIVMSG")  // On vérifie que l'expéditeur existe
        {
            // Vérifie que l'expéditeur est valide et récupère son nickname
            string nickname;
            void (Server::*function)(int, const string &, const string &) const;
            if (_users.count(event_fd) && _users[event_fd])
            {
                nickname = _users[event_fd]->getNickName();
                function = &Server::printMsgUser;
            }
            else if (_staffs.count(event_fd) && _staffs[event_fd])
            {
                nickname = _staffs[event_fd]->getNickName();
                function = &Server::printMsgStaff;
            }
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

            string fullMsg = "MP to you : " + msg + "\r\n";
            if (target == this->getAdminNickName())
                (this->*function)(1, fullMsg, nickname);
            else if (receiver_fd != -1)
                (this->*function)(receiver_fd, fullMsg, nickname);
            else
            {
                string topic = this->getTopic();
                if (target != topic && target != "#" + topic)
                {
                    string err = "[ERROR] PRIVMSG " + target + " : No such nick/channel.";
                    this->printMsgServer(event_fd, err);
                }
            }
            if (_OnOff == true)
                bot.parrot(msg, event_fd, getCurrentTime());
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
                string msg = "[ERROR] No nickname given\r\n";
                this->printMsgServer(event_fd, msg);
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
                    string err = "[ERRROR] " + nick + " : Nickname is already in use.";
                    this->printMsgServer(event_fd, err);
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
                string msg = "[ERROR] Not enough parameters.";
                this->printMsgServer(event_fd, msg);
            }
            else
            {
                _tempUser[event_fd] = username;
                _userStates[event_fd] = REGISTERED;
                _users[event_fd]->setNickName(_tempNick[event_fd]);
                _users[event_fd]->setUserName(_tempUser[event_fd]);
                _users[event_fd]->setStatus(true);

                string welcome = _tempNick[event_fd] + " Welcome to the IRC server!";
                this->printMsgServer(event_fd, welcome);

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
                    string msg = "[ERROR] Not enough parameters.";
                    this->printMsgServer(event_fd, msg);
                    break;
                }
                if (channel != this->getTopic())
                {
                    string msg = "[ERROR] " + channel + " : No such channel.";
                    this->printMsgServer(event_fd, msg);
                    break;
                }
                if (_invite == true)
                {
                    string msg = "[ERROR] " + channel + " : This channel is by invitation only.";
                    this->printMsgServer(event_fd, msg);
                    break;
                }
                if (_currentUsers == _userLimit)
                {
                    string err = "[ERROR] " + _users[event_fd]->getNickName() + " #" + _topic + " : Cannot join channel (limit reached).";
                    this->printMsgServer(event_fd, err);
                    break;
                }
                if (_passWord.empty())
                {
                    string msg = "✅ You have joined channel " + this->getTopic() + ".";
                    this->printMsgServer(event_fd, msg);

                    this->printMsgServer(0, "User " + _users[event_fd]->getNickName()
                        + " joined channel: " + this->getTopic() + ".");

                    _users[event_fd]->setStatus(true);
                    _userStates[event_fd] = JOINED;
                    _currentUsers += 1;
                    break;
                }

                channel = "Please enter password : ";
                this->printMsgServer(event_fd, channel);
                _userStates[event_fd] = WAIT_PASSWORD;
            }
            else if (command == "PRIVMSG")
                break;
            else
            {
                string msg = "[ERROR] " + command + " : Unknown command.";
                this->printMsgServer(event_fd, msg);
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
                string msg = "✅ You have joined channel " + this->getTopic() + ".";
                this->printMsgServer(event_fd, msg);

                this->printMsgServer(0, "User " + _users[event_fd]->getNickName()
                        + " joined channel: " + this->getTopic() + ".");

                _users[event_fd]->setStatus(true);
                _userStates[event_fd] = JOINED;
                _currentUsers += 1;
            }
            else
            {
                string msg = "❌ Password invalid!\r\n";
                this->printMsgServer(event_fd, msg);
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
                    string err = "[ERROR] PRIVMSG : Not enough parameters.";
                    this->printMsgServer(event_fd, err);
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
