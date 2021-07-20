#include "Point.h"
#include <iostream>

namespace VG
{

    std::ostream& operator<<(std::ostream& os, const Point& p)
    {
        os << "<Point x=\"" << p.getX() << "\" y=\"" << p.getY() << "\"/>";
        return os;
    }

}
