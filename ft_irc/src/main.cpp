#include "../inc/Server.hpp"

using std::string;
using std::cout;
using std::endl;
using std::cerr;

int main( int ac, char **av )
{
    if (ac != 3)
    {
        cerr << "Good usage is : ./ircserv <port> <password>" << endl;
        return 1;
    }
    Server serv(std::atoi(av[1]), av[2]);
    cout << serv.getPassWord() << " " << serv.getPort() << endl;
    cout << serv.getAdminNickName() << " " << serv.getAdminUserName() << endl;
}