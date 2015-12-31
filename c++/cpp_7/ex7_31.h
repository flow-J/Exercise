#ifndef CP5_ex7_31_h
#define CP5_ex7_31_h

class Y;

class X {
    Y *y = nullptr;
};

class Y {
    X x;
};

#endif
