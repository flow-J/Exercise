#include <iostream>
#include <math.h>

struct point { float x; float y; };

float distance(point a, point b)
{
    float dx = a.x - b.x, dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

int main()
{
    point a, b;
    a.x = 1.0; a.y = 1.0; b.x = 4.0; b.y = 5.0;
    std::cout << distance(a, b) << std::endl;
}
