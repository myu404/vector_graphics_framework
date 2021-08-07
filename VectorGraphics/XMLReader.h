#pragma once
#include "..\tinyxml2-master\tinyxml2.h"
#include "Element.h"
#include <istream>
//#include "tinyxml2.h"

namespace Xml
{
    using HElement = std::shared_ptr<Element>;
    using ElementList = std::vector<Element>;
    using AttributeMap = std::unordered_map<std::string, std::string>;

    class Reader
    {
    public:
        static HElement loadXml(std::stringstream& istream);

    private:
        // Helper recursive function to parse XML
        static Element loadXml(tinyxml2::XMLElement* element);
    };
}