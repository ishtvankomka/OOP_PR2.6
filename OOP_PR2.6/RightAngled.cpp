#include "RightAngled.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <sstream>
#include <math.h>
#define PI 3.14159265

using namespace std;

bool Init(RightAngled::Triangle& f)
{
    double d1 = f.get_a();
    double d2 = f.get_b();
    double d3 = f.get_c();

    if(f.get_b() > d1)
    {
        d1 = f.get_b();
        d2 = f.get_a();
    }
    if(f.get_c() > d1)
    {
        d1 = f.get_c();
        d2 = f.get_a();
        d3 = f.get_b();
    }

    if ((d1*d1) == (d2*d2 + d3*d3))
    {
        return true;
    }
    else
    {
        cout << "Sides don't make right angled triangle!" << endl;
        return false;
    }
}

RightAngled::RightAngled() {
    area = 0;
}

RightAngled::RightAngled(double f) {
    area = f;
}

RightAngled::RightAngled(RightAngled& f) {
    triangle = f.triangle;
    area = f.area;
}

RightAngled& RightAngled::operator = (const RightAngled& f) {
    triangle = f.triangle;
    area = f.area;
    return *this;
}

istream& operator >> (istream& in, RightAngled& f)
{
    do
    {
        cin >> f.triangle;
    }
    while(!Init(f.triangle));
    return in;
}

ostream& operator << (ostream& out, const RightAngled& a)
{
    out << string(a);
    return out;
}

RightAngled::operator string () const
{
    stringstream f;
    f << triangle;
    return f.str();
}

void RightAngled::area_calculate(Triangle& t)
{
    double p = t.perimeter() / 2;
    double s1 = t.get_a();
    double s2 = t.get_b();
    double s3 = t.get_c();
    
    double s = sqrt(p * (p - s1) * (p - s2) * (p - s3));
    set_area(s);
}

RightAngled::Triangle RightAngled::get_triangle()
{
    return triangle;
};

double RightAngled::get_area()
{
    area_calculate(triangle);
    return area;
}

void Read(RightAngled& f)
{
    cin >> f;
}

void Display(RightAngled& f)
{
    Display(f.triangle);
    cout << "Area: " << f.get_area() << endl;
}



RightAngled::Triangle::Triangle() {
    a = 0;
    b = 0;
    c = 0;
}

RightAngled::Triangle::Triangle(double a1, double b1, double c1) {
    a = a1;
    b = b1;
    c = c1;
}

RightAngled::Triangle::Triangle(Triangle& f) {
    a = f.a;
    b = f.b;
    c = f.c;
}

RightAngled::Triangle& RightAngled::Triangle::operator = (const Triangle& f) {
    a = f.a;
    b = f.b;
    c = f.c;
    return *this;
}

istream& operator >> (istream& in, RightAngled::Triangle& f)
{
    cout << "Set the sides:" << endl;
    cout << " a = "; in >> f.a;
    cout << " b = "; in >> f.b;
    cout << " c = "; in >> f.c;
    while((f.a >= f.b + f.c) ||
          (f.b >= f.a + f.c) ||
          (f.c >= f.b + f.a))
        {
            cout << "Wrong arguments to init!" << endl;
            cout << " a = "; in >> f.a;
            cout << " b = "; in >> f.b;
            cout << " c = "; in >> f.c;
        }
    return in;
}

ostream& operator << (ostream& out, const RightAngled::Triangle& a)
{
    out << string(a);
    return out;
}

RightAngled::Triangle::operator string () const
{
    stringstream f;
    f << "Your triangle: "
      <<  "[" << a << "] "
      <<  "[" << b << "] "
      <<  "[" << c << "] " << endl;
    return f.str();
}

RightAngled::Triangle& RightAngled::Triangle::operator ++() {
    ++c;
    return *this;
}

RightAngled::Triangle& RightAngled::Triangle::operator --() {
    --c;
    return *this;
}

RightAngled::Triangle RightAngled::Triangle::operator ++(int) {
    Triangle t(*this);
    a++;
    return t;
}

RightAngled::Triangle RightAngled::Triangle::operator --(int) {
    Triangle t(*this);
    a--;
    return t;
}

void Read(RightAngled::Triangle& f)
{
    cin >> f;
}

void Display(RightAngled::Triangle& f)
{
    cout << f;
    cout << "Angles: " <<
    f.angleAlfa() << "°, " <<
    f.angleBeta() << "°, " <<
    f.angleGama() << "°" << endl;
    cout << "Perimeter: " << f.perimeter() << endl;
}

double RightAngled::Triangle::angleAlfa() const
{
    double alfa;
    double a = get_a();
    double b = get_b();
    double c = get_c();
    if(a > b && a > c)
    {
        double beta = angleBeta();
        double gama = angleGama();
        alfa = 180 - (beta + gama);
    }
    else
    {
        double dalfa;
        if (c >= b)
        {
            dalfa = a / c;
        }
        else
        {
            dalfa = a / b;
        }
        dalfa = asin(dalfa) * 180.0 / PI;
        alfa = round(dalfa);
    }
    return alfa;
}

double RightAngled::Triangle::angleBeta() const
{
    double beta;
    double a = get_a();
    double b = get_b();
    double c = get_c();
    if(b > a && b > c)
    {
        double alfa = angleAlfa();
        double gama = angleGama();
        beta = 180 - (alfa + gama);
    }
    else
    {
        double dbeta;
        if (a >= c)
        {
            dbeta = b / a;
        }
        else
        {
            dbeta = b / c;
        }
        dbeta = asin(dbeta) * 180.0 / PI;
        beta = round(dbeta);
    }
    return beta;
}

double RightAngled::Triangle::angleGama() const
{
    double gama;
    double a = get_a();
    double b = get_b();
    double c = get_c();
    if(c > a && c > b)
    {
        double alfa = angleAlfa();
        double beta = angleBeta();
        gama = 180 - (alfa + beta);
    }
    else
    {
        double dgama;
        if (a >= b)
        {
            dgama = c / a;
        }
        else
        {
            dgama = c / b;
        }
        dgama = asin(dgama) * 180.0 / PI;
        gama = round(dgama);
    }
    return gama;
}

double RightAngled::Triangle::perimeter() const
{
    double perimeter = get_a() + get_b() + get_c();
    return perimeter;
}

double RightAngled::Triangle::get_a() const
{
    return a;
}

double RightAngled::Triangle::get_b() const
{
    return b;
}

double RightAngled::Triangle::get_c() const
{
    return c;
}
