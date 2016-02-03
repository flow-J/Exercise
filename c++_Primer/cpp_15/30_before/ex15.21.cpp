#include <iostream>
#include <string>

class Shape
{
public:
    typedef std::pair<double, double> Coordinate;

    Shape() = default;
    Shape(const std::string &m) : name() { }

    virtual double area()       const = 0;
    virtual double perimeter()  const = 0;

    virtual ~Shape() = default;
private:
    std::string name;
};


class Rectangle : public Shape
{
public:
    Rectangle() = default;
    Rectangle(const std::string &n,
              const Coordinate &a,
              const Coordinate &b,
              const Coordinate &c,
              const Coordinate &d) :
        Shape(n), a(a), b(b), c(c), d(d) { }

    ~Rectangle() = default;

protected:
    Coordinate a;
    Coordinate b;
    Coordinate c;
    Coordinate d;
};





class Square : public Rectangle
{
public:

}
