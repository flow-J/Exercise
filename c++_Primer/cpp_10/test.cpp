#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());

    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}


void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
    
}




int main()
{
    /*
    std::vector<int> vec;
    std::fill_n(back_inserter(vec), 10, 0);
    */
/*
    int a1[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int a2[sizeof(a1)/sizeof(*a1)];
    auto ret = std::copy(begin(a1),end(a1), a2);

    for (auto i : a2)
        cout << i << " ";
*/

/*
    vector<string> str = { "c", "b"};
    elimDups(str);
    for (auto i : str)
        cout << i << endl;
*/



}
