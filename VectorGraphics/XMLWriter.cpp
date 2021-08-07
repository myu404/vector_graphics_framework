#include "XMLWriter.h"
#include <sstream>

namespace Xml
{
    void Writer::writeXml(Xml::HElement rootElement, std::ostream& os)
    {
        tinyxml2::XMLDocument xmlDoc;
        tinyxml2::XMLElement* element = xmlDoc.RootElement();
    }
}