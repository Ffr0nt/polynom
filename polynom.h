//
// Created by Фёдор Захаров on 06.10.2021.
//
#include <iostream>

#ifndef UNTITLED_POLYNOM_H
#define UNTITLED_POLYNOM_H

#endif //UNTITLED_POLYNOM_H

class polynom{
public:
    polynom();
    polynom(int x);
    polynom(int degree, double coef);
    polynom(const polynom& object);

//open redifinitions
    polynom& operator = (const polynom& object);
    bool operator == (const polynom& object);
    bool operator != (const polynom& object);
    friend std::ostream& operator << (std::ostream& out, const polynom& object);
    double& operator[](int index);
    polynom& operator +(const polynom& object);
    polynom& operator -(const polynom& object);
    void operator ++();
    void operator --();
    int operator() (double num);

private:
    //developer tool
    void print();
    // fields
    int m_degree ;
    double  *  k_arr ;
};



