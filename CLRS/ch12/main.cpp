#include <iostream>
#include <string>
#include "node.cpp"
#include "tree.cpp"

int main()
{
  binary_search_tree<int, std::string> tree;

    tree.insert_recur(5,5);
    tree.insert_recur(611,"611");
    tree.insert_recur(6,"006");
    tree.insert_recur(16,"016");


    tree.inorder_print();

    std::cout << "end" << std::endl;
    return 0;
  
}
