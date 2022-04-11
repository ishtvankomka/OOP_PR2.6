#include <iostream>
#include "RightAngled.hpp"

using namespace std;

int main() {
    RightAngled::Triangle t1(0, 0, 0);
    RightAngled::Triangle t2(t1);
    RightAngled::Triangle t3 = t2;
    cout << "a++" << endl;
    t3++;
    cout << t3.get_a() << endl;
    cout << "a--" << endl;
    t3--;
    cout << t3.get_a() << endl;
    ++t3;
    cout << "++c" << endl;
    cout << t3.get_c() << endl;
    --t3;
    cout << "--c" << endl;
    cout << t3.get_c() << endl;
    
    RightAngled rightangled1;
    Read(rightangled1);
    RightAngled rightangled2(rightangled1);
    Display(rightangled2);
    
    cout << "Class size: " << sizeof(RightAngled::Triangle) << endl;
    return 0;
}

