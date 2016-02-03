#ifndef CP5_ex7_53_h
#define CP5_ex7_53_h

class Debug {
public:
    constexpr Debug(bool b = true) : rt(b), other(b) { }
    constexpr Debug(bool r, bool i, bool o) : rt(r), io(i), other(0) { }
    constexpr bool any() { return rt || io || other; }

    void set_rt(bool b) { rt = b; }
    void set_io(bool b) { io = b;}
    void set_other(bool b) { other = b; }

private:
    bool rt;
    bool io;
    bool other;
};

#endif
