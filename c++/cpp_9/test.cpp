#include <iostream>
#include <list>
#include <vector>
#include <string>
using std::string;
using std::cout;
using std::list;
using std::endl;
using std::vector;
using std::cin;

/*
int main()
{
    list<int> ilist(10, 42);
    ilist.resize(15);
    ilist.resize(25, -1);
    ilist.resize(5);

    for (auto i : ilist)
        std::cout << i << " ";
    std::cout << std::endl;

}*/
/*
int main()
{
    vector<int> ivec;
    cout << " ivec: size: " << ivec.size()
         << " capacity: " << ivec.capacity() << endl;

    for (vector<int>::size_type ix = 0; ix != 24; ++ix)
        ivec.push_back(ix);

    cout << "ivec: size: " << ivec.size()
        << " capacity: " << ivec.capacity() << endl;

    ivec.reserve(50);

    cout << "ivec: size: " << ivec.size()
        << " capacity: " << ivec.capacity() << endl;

    while (ivec.size() != ivec.capacity())
        ivec.push_back(0);


    ivec.push_back(42);
    cout << "ivec: size: " << ivec.size()
        << " capacity: " << ivec.capacity() << endl;

    ivec.shrink_to_fit();
    cout << "ivec: size: " << ivec.size()
        << " capacity: " << ivec.capacity() << endl;
}*/

int main()
{
    vector<string> svec;
    svec.reserve(1024);
    string word;
    while (cin >> word)
        svec.push_back(word);
    svec.resize(svec.size()+svec.size()/2);

    for (auto i : svec)
        cout << i << " ";
    cout << svec.size() ;
}
