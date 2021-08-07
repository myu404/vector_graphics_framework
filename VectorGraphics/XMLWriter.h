#pragma once
#include "..\tinyxml2-master\tinyxml2.h"
#include "Element.h"
#include <ostream>
//#include "tinyxml2.h"

namespace Xml
{
    class Writer
    {
    public:
        static void writeXml(Xml::HElement rootElement, std::ostream& os);
    };
}