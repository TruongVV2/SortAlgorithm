#include<iostream>
#include<math.h>
#include"../inc/node.h"

namespace abc {
    class test {
        int x = 10;

    };
}

int UCLN(int a, int b)
{   
    

    if (a == 0 && b == 0) {
        std::cout << "No limited UCLN" << std::endl;
        return -1;
    }
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    
    while (b != a) {
        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }

    return b;
}

int BCNN(int a, int b)
{
    if (a == b)
        return a;

    if (a < b) {
        int temp = b;
        b = a;
        a = temp;
    }
    int i = a;
    int maxV = a*b;
    for (i; i < maxV; i += a) {
        if ((i % a == 0) && (i % b == 0)) {
            return i;
        }
    }
    return maxV;
    // for (i; i <= b; i++) {
    //     if (((b * i) % a) == 0)
    //         return b*i;
    // }
    // if (i > b)
    //     return b*a;
}

bool isCheckSquare(int a)
{
    static int kk = 3;

    int x = sqrt(a);
    for (int i = 2; i <= x; i++) {
        if (i*i == a) {
            return true;
        }
    }
    return false;
}

bool isCheckPerfect(int a)
{
    if (a == 0)
        return true;
    int h = a/2;
    int tong = 0;
    for (int i = 1; i <= h; i++) {
        if (a % i == 0)
            tong += i;
    }
    if (tong == a)
        return true;
    return false;
}

class Base
{
    public:
    virtual void show()
    {
        std::cout << "Base";
    }
};

class Derived:public Base
{
    public:
    void show()
    {
        std::cout << "Derived";
    }
};

void abcx(int p)
{
    std::cout << p;
}

const char* func()
{
    return "ViVi";
}

int increaseF(int k)
{
    k++;
    return k;
}

void recursiveF(int k)
{
    k = increaseF(increaseF(increaseF(k)));
    std::cout << "K: " << k << std::endl;
}


int main()
{
    std::cout << "UCLN: " << UCLN(3, 2) << std::endl;
    std::cout << "UCLN: " << BCNN(15, 20) << std::endl;
    std::cout << "Is check Square: " << isCheckSquare(5) << std::endl;
    std::cout << "Is check Perfect: " << isCheckPerfect(496) << std::endl;

    // ListNode list;
    // Node* head = nullptr;
    // list.InitialNode(&head, 1);
    // std::cout << "List include a node: " << std::endl;
    // list.PrintList(head);
    // list.InsertNode(&head, 3, 1);
    // list.InsertNode(&head, 2, 1);
    // list.InsertNode(&head, 4, 5);
    // std::cout << "List include four nodes: " << std::endl;
    // list.PrintList(head);

    int b = 2;
    int c = 3;
    int a = +b+++ + ++c;
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;

    int x = 1;
    do {
        std::cout << "TruongVi" << std::endl;
    } while (x = 0);

    abc::test test;

    int i=10;
    int& j=i;
    int k=20;
    j=k;
    std::cout << i << j<< k << std::endl;

    Base* base;
    Derived d;
    base = &d;
    base->show();

    float m = 1.23;
	abcx(m);
    std::cout << m;

    int ax[5] = {1, 2, 3, 4, 5};
    for (int i = -1; i < 5; i++) {
        ax[++i] = 1 + 2;
    }
    for (int i = 0; i < 5; i++) {
        std::cout << ax[i] << std::endl;
    }

    const char* xy = func();
    recursiveF(35);

    return 0;
}