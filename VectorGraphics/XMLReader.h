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
        //static HElement loadXml(std::stringstream& istream);
        static HElement loadXml(std::istream& istream);

    private:
        // Helper recursive function to parse XML
        static Element loadXml(tinyxml2::XMLNode* element);
    };
}