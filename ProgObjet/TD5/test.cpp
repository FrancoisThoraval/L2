#include <iostream>

class A
{
public:
    A() {}
    virtual ~A() {}
    void init(int) { std::cout << "A\n"; }
};

class B : public A
{
public:
    B() : A() {}
    void init(int) { std::cout << "B\n"; }
};

class C : public A
{
public:
    C() : A() {}
    void init(int) { std::cout << "C\n"; }
};

class D : public A
{
public:
    D() : A() {}
    using A::init;
    void init(const std::string& s) { std::cout << "D -> " << s << "\n"; }
};

int main()
{
    B b; b.init(10);
    C c; c.init(10);
    D d; d.init(10); d.init("a");

    return 0;
}
