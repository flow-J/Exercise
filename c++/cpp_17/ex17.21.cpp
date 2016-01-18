#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

struct PersonInfo
{
    string name;
    vector<string> phones;
};

bool valid(const smatch& m)
{
    if (m[1].matched)
        return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
    else
        return !m[3].matched && m[4].str() == m[6].str();
}

bool read_record(istream& is, vector<PersonInfo>& people)
{
    if (is)
    {
        string line, word;

        while (getline(is, line))
        {
            PersonInfo info;
            istringstream record(line);
            record >> info.name;
            while (record >> word)
                info.phones.push_back(word);
            people.push_back(info);
        }
        return true;
    }
    else
        return false;
}

void format_record(ostream& os, const vector<PersonInfo>& people)
{
    string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
    regex r(phone);
    smatch m;

    for (const auto &entry : people)
    {
        ostringstream formatted, badNums;
        for (const auto &nums : entry.phones)
        {
            for (sregex_iterator it(nums.begin(), nums.end(), r), end_it; it != end_it; ++it)
            {
                if (!valid(*it))
                    badNums << " " << nums;
                else
                    formatted << " " << format(nums);
            }
        }
        if (badNums.str().empty())
            os << entry.name << " "
                << formatted.str() << endl;
        else
            cerr << "input error: " << entry.name
                << " invalid number(s)" << badNums.str() << endl;
    }
}

int main()
{
    vector<PersonInfo> people;

    string filename;
    cout << "Please input a record file name: ";
    cin >> filename;
    cout << endl;
    ifstream fin(filename);

    if (read_record(fin, people))
    {
        ofstream fout("data\\result.txt", ofstream::trunc);
        format_record(fout, people);
    }
    else
    {
        cout << "Fail to open file " << filename << endl;
    }

    return 0;
}
