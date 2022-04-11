#pragma once
#include <string>
#include <iostream>

using namespace std;

//#pragma pack(push)  /* push current alignment to stack */
//#pragma pack(1)
class RightAngled
{
public:
    class Triangle
    {
    private:
        double a, b, c;
    public:
        Triangle();
        Triangle(double, double, double);
        Triangle(Triangle&);
        Triangle& operator = (const Triangle&);
        
        operator string() const;
        friend ostream& operator << (ostream&, const RightAngled::Triangle&);
        friend istream& operator >> (istream&, RightAngled::Triangle&);
        
        Triangle& operator ++();
        Triangle& operator --();
        Triangle operator ++(int);
        Triangle operator --(int);
        
        friend void Read(Triangle&);
        friend void Display(Triangle&);

        void set_a(double value) { a = value; };
        void set_b(double value) { b = value; };
        void set_c(double value) { c = value; };
        double get_a() const;
        double get_b() const;
        double get_c() const;
        
        double angleAlfa() const;
        double angleBeta() const;
        double angleGama() const;
        double perimeter() const;
    };
private:
    double area;
    Triangle triangle;
public:
    RightAngled();
    RightAngled(double);
    RightAngled(RightAngled&);
    RightAngled& operator = (const RightAngled&);
    
    operator string() const;
    friend ostream& operator << (ostream&, const RightAngled&);
    friend istream& operator >> (istream&, RightAngled&);
    
    friend void Read(RightAngled&);
    friend void Display(RightAngled&);
    friend bool Init(Triangle&);

    
    void set_triangle(Triangle triangle) { this->triangle = triangle; };
    void set_area(double value) { area = value; };
    Triangle get_triangle();
    double get_area();

    void area_calculate(Triangle&);
};
//#pragma pack(pop)   /* restore original alignment from stack */
