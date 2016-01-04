#include <iostream>
#include <string>
#include <vector>

using namespace std;

class My_data {
private:
    unsigned year, month, day;
public:
    My_data(const string &s){

        unsigned tag;
        unsigned format;
        format = tag = 0;

        if (s.find_first_of("/")!= string :: npos)
        {
            format = 0x01;
        }

        if (s.find_first_of(',') >= 4) && s.find_first_of(',')!= string :: npos{
            format = 0x10;
        }
        else{
            if (s.find_first_of(' ') >= 3
                    && s.find_first_of(' ')!= string :: npos){
                format = 0x10;
                tag = 1;
            }
        }

        switch(format)
        {
            case 0x01:
                day = stoi(s.substr(0, s.find_first_of("/")));
                month = stoi
        }
    }
}
