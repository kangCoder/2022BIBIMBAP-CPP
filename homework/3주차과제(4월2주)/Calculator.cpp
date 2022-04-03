#include "Calculator.h"

Add::Add()
    : a(0), b(0)
{
}

Add::Add(int x, int y)
    : a(x), b(y)
{
}

Add::~Add() {}

void Add::setValue(int a, int b)
{
    this->a = a;
    this->b = b;
}

int Add::calculate()
{
    return a+b;
}

Sub::Sub()
    : a(0), b(0)
{
}

Sub::Sub(int x, int y)
    : a(x), b(y)
{
}

Sub::~Sub() {}

void Sub::setValue(int a, int b)
{
    this->a = a;
    this->b = b;
}

int Sub::calculate()
{
    return a-b;
}

Mul::Mul()
    : a(0), b(0)
{
}

Mul::Mul(int x, int y)
    : a(x), b(y)
{
}

Mul::~Mul() {}

void Mul::setValue(int a, int b)
{
    this->a = a;
    this->b = b;
}

int Mul::calculate()
{
    return a*b;
}

Div::Div()
    : a(0), b(0)
{
}

Div::Div(int x, int y)
    : a(x), b(y)
{
}

Div::~Div() {}

void Div::setValue(int a, int b)
{
    this->a = a;
    this->b = b;
}

int Div::calculate()
{
    return a/b;
}
