#pragma once
#include "..\tinyxml2-master\tinyxml2.h"
#include "Element.h"
#include <istream>
//#include "tinyxml2.h"

namespace Xml
{
    class Reader
    {
    public:
        static HElement loadXml(std::stringstream& istream);

    private:
        // Helper recursive function to parse XML
        static Element loadXml(tinyxml2::XMLElement* element);
    };
}