#include "../exercise.h"

// READ: 虚函数 <https://zh.cppreference.com/w/cpp/language/virtual>

struct A {
    virtual char virtual_name() const {
        return 'A';
    }
    char direct_name() const {
        return 'A';
    }
};
struct B : public A {
    // READ: override <https://zh.cppreference.com/w/cpp/language/override>
    char virtual_name() const override {
        return 'B';
    }
    char direct_name() const {
        return 'B';
    }
};
struct C : public B {
    // READ: final <https://zh.cppreference.com/w/cpp/language/final>
    char virtual_name() const final {
        return 'C';
    }
    char direct_name() const {
        return 'C';
    }
};
struct D : public C {
    char direct_name() const {
        return 'D';
    }
};

int main(int argc, char **argv) {
    constexpr auto MSG = "Replace '?' with its correct name.";

    A a;
    B b;
    C c;
    D d;

    ASSERT(a.virtual_name() == 'A', MSG);
    ASSERT(b.virtual_name() == 'B', MSG);
    ASSERT(c.virtual_name() == 'C', MSG);
    ASSERT(d.virtual_name() == 'C', MSG);
    ASSERT(a.direct_name() == 'A', MSG);
    ASSERT(b.direct_name() == 'B', MSG);
    ASSERT(c.direct_name() == 'C', MSG);
    ASSERT(d.direct_name() == 'D', MSG);

    A &rab = b;
    B &rbc = c;
    C &rcd = d;

    ASSERT(rab.virtual_name() == 'B', MSG);
    ASSERT(rbc.virtual_name() == 'C', MSG);
    ASSERT(rcd.virtual_name() == 'C', MSG);
    ASSERT(rab.direct_name() == 'A', MSG);
    ASSERT(rbc.direct_name() == 'B', MSG);
    ASSERT(rcd.direct_name() == 'C', MSG);

    A &rac = c;
    B &rbd = d;

    ASSERT(rac.virtual_name() == 'C', MSG);
    ASSERT(rbd.virtual_name() == 'C', MSG);
    ASSERT(rac.direct_name() == 'A', MSG);
    ASSERT(rbd.direct_name() == 'B', MSG);

    A &rad = d;

    ASSERT(rad.virtual_name() == 'C', MSG);
    ASSERT(rad.direct_name() == 'A', MSG);

    return 0;
}

// READ: 扩展阅读-纯虚、抽象 <https://zh.cppreference.com/w/cpp/language/abstract_class>
// READ: 扩展阅读-虚继承 <https://zh.cppreference.com/w/cpp/language/derived_class>

/*
虚函数是用来实现 “多态（polymorphism）” 的成员函数，通过基类指针/引用调用虚函数时，实际运行的是“对象真实类型”的那个版本，而不是“指针/引用类型”的那个版本
虚函数前面会加上virtual关键字

先确定「引用/指针 → 静态类型」和「它绑定的对象 → 动态类型」。
遇到虚函数：用动态类型往继承链里找最后一个重写。
遇到非虚函数：只按静态类型往上找成员函数实现
override表示要重写该虚函数
final表示不能再重写这个虚函数，用于类的话则表示不能再被继承
*/