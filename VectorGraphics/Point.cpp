/*
* Author: Michael Yu
* C++ Programming, Summer 2021
* Vector Graphics Framework: Assignment 01
* 7/20/2021
*/

#include "Point.h"
#include <iostream>

namespace VG
{

    std::ostream& operator<<(std::ostream& os, const Point& p)
    {
        os << "Point x=\"" << p.getX() << "\" y=\"" << p.getY() << "\"";
        return os;
    }

}
