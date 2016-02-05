#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

class Complex
{
private:
    float re, im;
public:
    Complex(float x = 0, float y = 0)
      { re = x; im = y; }
    float Re() const { return re; }
    float Im() const { return im; }
    Complex& operator*=(const Complex& rhs)
    {
        float t = Re();
        re = Re()*rhs.Re() - Im()*rhs.Im();
        im = t*rhs.Im() + Im()*rhs.Re();
        return *this;
    }

};
ostream& operator<<(ostream& t, const Complex& c)
  { t << c.Re() << " " << c.Im(); return t; }

int main(int argc, char *argv[])
{
    int N = atoi(argv[1]);
    cout << N << " complex roots of unity" << endl;
    for (int k = 0; k < N; k++)
    {
        float theta = 2.0*3.14159*k/N;
        Complex t(cos(theta), sin(theta)), x = t;
        cout << k << ": " << t << " ";
        for (int j = 0; j < N-1; j++)
            x *= t;
        cout << x << endl;
    }
}
