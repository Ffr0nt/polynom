
#include "polynom.h"
//class polynom contains degree and array of koefs
//initialization with different amount of parameters
//redefinition of + - = == != << [] () functions for our class

int main() {
    using namespace std;
    polynom poly_1;
    cout << poly_1 << endl;
    cout << poly_1[0] << endl;
    polynom poly_2(5);
    cout << poly_2 << endl;
    polynom poly_3(5, 3);
    cout << poly_3 << endl;
    polynom poly_4 = poly_3;
    cout << poly_4 << endl;
    poly_4 = poly_2;
    cout << poly_4 << endl;
    if (poly_2 == poly_4) cout << poly_2<< endl << "same as: " << poly_4 << endl;
    if (poly_3 != poly_4) cout << poly_3<< endl << "different with: " << poly_4 << endl;
    polynom poly_5(6, 3);
    cout << poly_5 << endl;
    poly_5[6] = 0;
    cout << poly_5 << endl;
    if (poly_5 == poly_3) cout << poly_5 << " same as: " << poly_4 << endl;
        return 0;

}