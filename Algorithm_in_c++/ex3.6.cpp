#include <iostream>
#include <string>

using namespace std;
/*
struct poker
{
    const string colors[] = {"heart", "spade", "club", "diamond"};
    const string numers[] = { "3","4","5","6","7","8","9","10","J","Q","K","A","2","BOSS","boss"};

};
*/

struct poker
{
    typedef string colors;
    typedef string numbers;

    colors heart, spade, club, diamond;
    numbers "3", "4", "5", "6", "7", "8", "9", J, Q, K, A, "2", BOSS, boss;
};
