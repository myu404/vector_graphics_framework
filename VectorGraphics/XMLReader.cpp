#include "XMLReader.h"
#include <sstream>

namespace Xml
{
    HElement Reader::loadXml(std::stringstream& istream)
    {
        return std::make_shared<Element>(Element(istream));
    }
}