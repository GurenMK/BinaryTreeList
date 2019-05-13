//Alexander Urbanyak

#include <list>
#include <iostream>
#include <stdlib.h>
#include "bintree.h"

using namespace main_savitch_10;

template <class T>
std::list<T>* create_list();
//Post-condition: return a list
template <class T>
std::list<T>* create_list2();
//Post-condition: return a list
template <class T>
std::list<T>* create_list3();
//Post-condition: return a list
template <class T>
std::list<T>* create_list4();
//Post-condition: return a list
template <class T>
std::list<T>* create_list5();
//Post-condition: return a list

template <class T>
binary_tree_node<T>* list_to_tree(std::list<T> *list, size_t length);
//Post-condition: return a pointer to a balanced tree

template <class T>
void print_list(const std::list<T>* list);
//Post-condition: print list

int main() {
    std::cout << "List 1:   ";
    std::list<int>* list = create_list<int>();
    print_list(list);
    binary_tree_node<int>* tree = list_to_tree<int>(list, list ->size());
    print(tree, 2);
    std::cout << "**********************************" << std::endl;

    std::cout << "List 2:   ";
    std::list<int>* list2 = create_list2<int>();
    print_list(list2);
    binary_tree_node<int>* tree2 = list_to_tree<int>(list2, list2 ->size());
    print(tree2, 2);
    std::cout << "**********************************" << std::endl;

    std::cout << "List 3:   ";
    std::list<int>* list3 = create_list3<int>();
    print_list(list3);
    binary_tree_node<int>* tree3 = list_to_tree<int>(list3, list3 ->size());
    print(tree3, 2);
    std::cout << "**********************************" << std::endl;

    std::cout << "List 4:   ";
    std::list<int>* list4 = create_list4<int>();
    print_list(list4);
    binary_tree_node<int>* tree4 = list_to_tree<int>(list4, list4 ->size());
    print(tree4, 2);
    std::cout << "**********************************" << std::endl;

    std::cout << "List 5:   ";
    std::list<int>* list5 = create_list5<int>();
    print_list(list5);
    binary_tree_node<int>* tree5 = list_to_tree<int>(list5, list5 ->size());
    print(tree5, 2);
    std::cout << "**********************************" << std::endl;

    return 0;
}

template <class T>
std::list<T>* create_list() {
    std::list<T>* list = new std::list<T>;

    list ->push_front(7);
    list ->push_front(6);
    list ->push_front(5);
    list ->push_front(4);
    list ->push_front(3);
    list ->push_front(2);
    list ->push_front(1);

    return list;
}

template <class T>
std::list<T>* create_list2() {
    std::list<T>* list = new std::list<T>;

    list ->push_front(6);
    list ->push_front(5);
    list ->push_front(4);
    list ->push_front(3);
    list ->push_front(2);
    list ->push_front(1);

    return list;
}

template <class T>
std::list<T>* create_list3() {
    std::list<T>* list = new std::list<T>;

    list ->push_front(5);
    list ->push_front(4);
    list ->push_front(3);
    list ->push_front(2);
    list ->push_front(1);

    return list;
}

template <class T>
std::list<T>* create_list4() {
    std::list<T>* list = new std::list<T>;

    list ->push_front(4);
    list ->push_front(3);
    list ->push_front(2);
    list ->push_front(1);

    return list;
}

template <class T>
std::list<T>* create_list5() {
    std::list<T>* list = new std::list<T>;

    list ->push_front(3);
    list ->push_front(2);
    list ->push_front(1);

    return list;
}

template <class T>
binary_tree_node<T>* list_to_tree(std::list<T> *list, size_t length) {
    if(length == 0){
        return NULL;
    }
    binary_tree_node<T>* left;
    binary_tree_node<T>* root;
    binary_tree_node<T>* right;

    left = list_to_tree(list, length/2);
    root = new binary_tree_node<T>(list ->front());
    root ->set_left(left);
    list ->pop_front();

    right = list_to_tree(list, (length - length/2) - 1);
    root ->set_right(right);

    return root;
}

template <class T>
void print_list(const std::list<T>* list) {
    for(typename std::list<T>::const_iterator it = list ->begin(); it != list ->end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << "\n" << std::endl;
}