#include "../inc/easyfind.hpp"

int main(){
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    std::list<int> l;
    l.push_back(40);
    l.push_back(50);
    l.push_back(60);

    std::deque<int> d;
    d.push_back(70);
    d.push_back(80);
    d.push_back(90);
    try{
        int& found = easyfind(v, 20);
        std::cout << found << std::endl;

        found = easyfind(l, 40);
        std::cout << found << std::endl;

        found = easyfind(d, 90);
        std::cout << found << std::endl;

        found = easyfind(v, 0);
        std::cout << found << std::endl;
    } catch (const std::exception& e){
        std::cout << "Exception cath : " << e.what() << std::endl;
    }
}