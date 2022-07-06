

#ifndef MAIN_CPP_DECLARATIONS_H
#define MAIN_CPP_DECLARATIONS_H
#include <iostream>
#include <list>
using namespace std;

template<typename F_T,typename S_T>
class Hash_Table{
private:

    static const int number_of_hash_groups = 10;
    int size = 0;
    list<pair<F_T,S_T>> table[number_of_hash_groups];

public:
    [[nodiscard]] bool empty()const;
    int hash_function(F_T key);
    void insert(F_T key,S_T value);
    void remove(F_T key);
    string search(F_T key);
    void print();
    auto get_table(){return table;};
};

#include "Implementations.hpp"
#endif //MAIN_CPP_DECLARATIONS_H
