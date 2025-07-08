#include "../inc/Server.hpp"

using std::string;
using std::cout;
using std::endl;
using std::cerr;

void print_irc()
{
    cout << "\033[34m";
    cout << "FFFFFFFFFFFFFFFFFFFFFFTTTTTTTTTTTTTTTTTTTTTTT                        IIIIIIIIIIRRRRRRRRRRRRRRRRR           CCCCCCCCCCCCC" << endl;
    cout << "F::::::::::::::::::::FT:::::::::::::::::::::T                        I::::::::IR::::::::::::::::R       CCC::::::::::::C" << endl;
    cout << "F::::::::::::::::::::FT:::::::::::::::::::::T                        I::::::::IR::::::RRRRRR:::::R    CC:::::::::::::::C" << endl;
    cout << "FF::::::FFFFFFFFF::::FT:::::TT:::::::TT:::::T                        II::::::IIRR:::::R     R:::::R  C:::::CCCCCCCC::::C" << endl;
    cout << "  F:::::F       FFFFFFTTTTTT  T:::::T  TTTTTT                          I::::I    R::::R     R:::::R C:::::C       CCCCCC" << endl;
    cout << "  F:::::F                     T:::::T                                  I::::I    R::::R     R:::::RC:::::C              " << endl;
    cout << "  F::::::FFFFFFFFFF           T:::::T                                  I::::I    R::::RRRRRR:::::R C:::::C              " << endl;
    cout << "  F:::::::::::::::F           T:::::T                                  I::::I    R:::::::::::::RR  C:::::C              " << endl;
    cout << "  F:::::::::::::::F           T:::::T                                  I::::I    R::::RRRRRR:::::R C:::::C              " << endl;
    cout << "  F::::::FFFFFFFFFF           T:::::T                                  I::::I    R::::R     R:::::RC:::::C              " << endl;
    cout << "  F:::::F                     T:::::T                                  I::::I    R::::R     R:::::RC:::::C              " << endl;
    cout << "  F:::::F                     T:::::T                                  I::::I    R::::R     R:::::R C:::::C       CCCCCC" << endl;
    cout << "FF:::::::FF                 TT:::::::TT                              II::::::IIRR:::::R     R:::::R  C:::::CCCCCCCC::::C" << endl;
    cout << "F::::::::FF                 T:::::::::T                              I::::::::IR::::::R     R:::::R   CC:::::::::::::::C" << endl;
    cout << "F::::::::FF                 T:::::::::T                              I::::::::IR::::::R     R:::::R     CCC::::::::::::C" << endl;
    cout << "FFFFFFFFFFF                 TTTTTTTTTTT                              IIIIIIIIIIRRRRRRRR     RRRRRRR        CCCCCCCCCCCCC" << endl;
    cout << "                                             ________________________                                                   " << endl;
    cout << "                                             _::::::::::::::::::::::_                                                   " << endl;
    cout << "                                             ________________________                                                   " << endl;
    cout << "\033[0m";
    cout << endl << endl << endl;
}

int main( int ac, char **av )
{
    if (ac != 3)
    {
        cerr << "Good usage is : ./ircserv <port> <password>" << endl;
        return 1;
    }
    Server serv(std::atoi(av[1]), av[2]);
    //cout << serv.getPassWord() << " " << serv.getPort() << endl;
    //cout << serv.getAdminNickName() << " " << serv.getAdminUserName() << endl;
    //cout << serv.getTopic() << endl;
    serv.setUpServer();
    print_irc();
    serv.run();
}