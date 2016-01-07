#include "ex12_27.h"
#include <iostream>

void runQueries(std::ifstream &infile)
{
 /*   TextQuery tq(infile);
    while (true) {
        std::cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(std::cin >> s) || s == "q") break;
        print(std::cout, tq.query(s)) << std::endl;*/

    do {
        std::cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(std::cin >> s) || s == "q") break;
        print(std::cout, tq.query(s)) << std::endl;
    } while (true);
}

int main()
{
    std::ifstream file("../book/storyDataFile.txt");
    runQueries(file);
}
