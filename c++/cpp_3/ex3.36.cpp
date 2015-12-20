#include <iostream>
#include <vector>
#include <iterator>

using std::begin;
using std::end;
using std::cout;
using std::endl;
using std::vector;

bool compare(int* const pb1, int* const pe1, int* const pb2, int* const pe2)
{
    if ((pe1 - pb1) != (pe2 - pb2))
            return false;
    else
    {
        for (int* i = pb1, *j = pb2; (i != pe1) && (j != pe2); ++i, ++j)
            if (*i != *j)
                return false;
    }
    return true;
}

int main()
{
    int arr1[3] = { 0, 1, 2};
    int arr2[3] = { 0, 1, 2};

    if (compare(begin(arr1), end(arr1), begin(arr2), end(arr2)))
        cout << "The two arrays are equal." << endl;
    else
        cout << "The two arrays are not equal." << endl;


}
