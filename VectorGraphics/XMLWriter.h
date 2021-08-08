#pragma once

#include "Element.h"
#include "tinyxml2.h"
//#include "..\tinyxml2-master\tinyxml2.h"
#include <ostream>


namespace Xml
{
    class XmlWriter
    {
    public:
        static void writeXml(Xml::HElement rootElement, std::ostream& os);

    private:
        // Helper recursive function to encode/serialize Scene into XML data
        static void writeXml(Xml::HElement element, tinyxml2::XMLDocument& xmlDoc, tinyxml2::XMLNode* xmlElement);
    };

}