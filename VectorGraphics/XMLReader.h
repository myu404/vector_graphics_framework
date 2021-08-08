#pragma once

#include "Element.h"
#include "tinyxml2.h"
//#include "..\tinyxml2-master\tinyxml2.h"
#include <istream>

namespace Xml
{
    class XmlReader
    {
    public:
        static HElement loadXml(std::istream& istream);

    private:
        // Helper recursive function to parse XML
        static Element loadXml(tinyxml2::XMLNode* element);
    };
}