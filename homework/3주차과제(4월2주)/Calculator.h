#include <iostream>
using namespace std;

class Add {
    private:
        int a;
        int b;
    
    public:
        Add();
        Add(int x, int y);
        ~Add();
        void setValue(int a, int b);
        int calculate();
};

class Sub {
    private:
        int a;
        int b;
    
    public:
        Sub();
        Sub(int x, int y);
        ~Sub();
        void setValue(int a, int b);
        int calculate();
};

class Mul {
    private:
        int a;
        int b;
    
    public:
        Mul();
        Mul(int x, int y);
        ~Mul();
        void setValue(int a, int b);
        int calculate();
};

class Div {
    private:
        int a;
        int b;
    
    public:
        Div();
        Div(int x, int y);
        ~Div();
        void setValue(int a, int b);
        int calculate();
};
