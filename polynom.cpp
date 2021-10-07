//
// Created by Фёдор Захаров on 06.10.2021.
//
#include"polynom.h"
#include <iostream>

using namespace std;
//basic initialization
polynom::polynom()
    : m_degree(0) {
    k_arr = new double [1];
    k_arr[0] = 0;
    cout << '\t' << "\t polynom() - default constructor" << endl<< endl;
};
//initialization with default coef and parametric size
polynom::polynom( int x )
    : m_degree( x ){
        k_arr = new  double [m_degree + 1];

        for (int i =0 ;i< m_degree + 1;i++){
            k_arr[i] = 1;
        }
    cout << '\t' << "\t polynom() - one parameter constructor" << endl<< endl;
};
//initialization with parametric size and coefs
polynom::polynom( int x, double coef )
        : m_degree( x ){
    k_arr = new  double [m_degree + 1];

    for (int i =0 ;i< m_degree + 1; i++){
        k_arr[i] = coef;
    }

    cout << '\t' << "\t polynom() - two parameter constructor" << endl<< endl;
};
//initialization with equality
polynom::polynom( const polynom& object )
: m_degree(object.m_degree)
{
    if (m_degree > 0) k_arr = new double [m_degree];
    else k_arr = nullptr;
    for (int i = 0; i < m_degree; ++i)
    {
        k_arr[i] = object.k_arr[i];
    }

}
//developer s tool of print
void polynom::print() {

        if (k_arr[m_degree]> 0){
            cout << "";}
        if (k_arr[m_degree] == 0){
            cout << "";}
    if (k_arr[m_degree] < 0) {
        cout << "- ";
    } else {}


    for (int i = m_degree  ;i > 0 - 1;i--){

        if (i == 0){cout <<  fabs(k_arr[i]); continue;}
        if (k_arr[i] == 0){continue;}
        if (k_arr[i] != 1){cout << fabs(k_arr[i]);}
        cout << "x";
        if (i != 1){cout << "^" << i;}

        if (0 <= (i - 1)){
            if (k_arr[i - 1]> 0){
                cout << " + ";}
            if (k_arr[i - 1] == 0){
                cout << "";}
            if (k_arr[i - 1] < 0){
                cout << " - ";}
        }
    }
    cout  << endl;
}
// analog of initialization with equality
polynom& polynom::operator=(const polynom& object)
{
    delete[] k_arr;
    m_degree = object.m_degree;
    if (m_degree > 0) k_arr = new double[m_degree + 1];
    else k_arr = nullptr;
    for (int i = 0; i < m_degree + 1; ++i)
    {
        k_arr[i] = object.k_arr[i];
    }
    return *this;
}
// check the equality of koefs, even with different length
bool polynom::operator == (const polynom& object){
    if (m_degree == object.m_degree){
        for (int i =m_degree ;i > 0 - 1;i--){
            if(k_arr[i] != object.k_arr[i]) { return false;}
        }
        return true;
    }

    if (m_degree > object.m_degree){
        for (int i =object.m_degree ;i > m_degree - 1;i--){
            if (object.k_arr[i] != 0)  return false;
        }
        for (int i =m_degree ;i > 0 - 1;i--){
            if(k_arr[i] != object.k_arr[i]) { return false;}
        }
        return true;
    }

    if ( object.m_degree > m_degree){
        for (int i = m_degree ;i > object.m_degree - 1;i--){
            if (k_arr[i] != 0)  return false;
        }
        for (int i = object.m_degree ;i > 0 - 1;i--){
            if(object.k_arr[i] != k_arr[i]) { return false;}
        }
        return true;
    }

}
//same, but inequality
bool polynom::operator != (const polynom& object){
    if ( *this  == object ){return false;}
    else{ return true;}
}
// sending all the paly to the stream
std::ostream &operator<<(ostream &out, const polynom &object) {

    if (object.k_arr[object.m_degree]> 0){
        out << "";}
    if (object.k_arr[object.m_degree] == 0){
        out << "";}
    if (object.k_arr[object.m_degree] < 0) {
        out << "- ";
    } else {}


    for (int i = object.m_degree  ;i > 0 - 1;i--){

        if (i == 0){cout <<  fabs(object.k_arr[i]); continue;}
        if (object.k_arr[i] == 0){continue;}
        if (object.k_arr[i] != 1){cout << fabs(object.k_arr[i]);}
        out << "x";
        if (i != 1){out << "^" << i;}

        if (0 <= (i - 1)){
            if (object.k_arr[i - 1]> 0){
                out << " + ";}
            if (object.k_arr[i - 1] == 0){
                out << "";}
            if (object.k_arr[i - 1] < 0){
                out << " - ";}
        }
    }
    out  << endl;
    return out;
}
// calling part of poly by koef
double& polynom::operator[](int index)
{
    if (0 <= index && index <= m_degree) return k_arr[index];
    else throw runtime_error("Error: index out of range of array!");
}
//sum up two polys
polynom& polynom::operator + (const polynom& object){
    if (m_degree == object.m_degree){
        for (int i =m_degree ;i > 0 - 1;i--){
            k_arr[i] += object.k_arr[i];
        }
    }
    if (m_degree > object.m_degree) {
        for (int i = object.m_degree; i > 0 - 1; i--) {
            k_arr[i] += object.k_arr[i];
        }
    }
    if (object.m_degree > m_degree) {
        for (int i = m_degree; i > 0 - 1; i--)
            object.k_arr[i] += k_arr[i];
        k_arr = object.k_arr;
        m_degree = object.m_degree;
    }

    return *this;
}
//difference of two polys
polynom& polynom::operator - (const polynom& object){

        for (int i = object.m_degree ;i > 0-1 ;i--){
            object.k_arr[i] = -1 *  object.k_arr[i];
        }
    if (m_degree == object.m_degree){
        for (int i =m_degree ;i > 0 - 1;i--){
            k_arr[i] += object.k_arr[i];
        }
    }
    if (m_degree > object.m_degree) {
        for (int i = object.m_degree; i > 0 - 1; i--) {
            k_arr[i] += object.k_arr[i];
        }
    }
    if (object.m_degree > m_degree) {
        for (int i = m_degree; i > 0 - 1; i--)
            object.k_arr[i] += k_arr[i];
        k_arr = object.k_arr;
        m_degree = object.m_degree;
    }

    return *this;

}
//increment
void polynom::operator ++ (){
    for (int i = m_degree ;i >= 0 ;i--){
        ++k_arr[i] ;
    }
    return;
}
//decrement
void polynom::operator -- () {
    for (int i = m_degree; i >= 0; i--) {
        --k_arr[i];
    }
    return;
}
//the substitution num into an expression
int polynom::operator() (double num){
    double sum = 0;
    for (int i = m_degree; i >= 0; i--) {
        sum += pow(num,i) * k_arr[i];
    }
    return sum;
}