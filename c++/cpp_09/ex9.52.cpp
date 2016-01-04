#include <iostream>
#include <stack>
#include <string>

using std::string;
using std::cout;
using std::stack;
using std::endl;

int main()
{
    string expression{ "This is (flow)." };
    auto repl = '#';
    auto seen = 0;

    stack<char> stk;

    for (auto c : expression)
    {
        stk.push(c);
        if (c == '(') ++seen;
        if (seen && c == ')')
        {
            while (stk.top() != '(') stk.pop();
            stk.pop();
            stk.push(repl);
            --seen;
        }
    }

    string output;
    for (; !stk.empty(); stk.pop())
        output.insert(output.begin(), stk.top());
    cout << output << endl;
}
