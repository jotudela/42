#include "../inc/easyfind.hpp"

int main(){
    std::vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    try{
        int& found = easyfind(v, 20);
        std::cout << found << std::endl;
    } catch (const std::exception& e){
        std::cout << e.what() << std::endl;
    }
}