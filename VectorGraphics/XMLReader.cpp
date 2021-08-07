#include "XMLReader.h"
#include <sstream>
#include <iostream>

namespace Xml
{
    HElement Reader::loadXml(std::istream& istream)
    {
        tinyxml2::XMLDocument xmlDoc;
        std::stringstream ss;
        ss << istream.rdbuf();
        xmlDoc.Parse(ss.str().c_str());
        tinyxml2::XMLElement* element = xmlDoc.RootElement();

        return std::make_shared<Element>(loadXml(element));
    }

    // Helper recursive function to parse XML
    Element Reader::loadXml(tinyxml2::XMLElement* xmlElement)
    {
        Element element(xmlElement->Name());
        std::cout << xmlElement->Name() << std::endl;
        const tinyxml2::XMLAttribute* pAttr = xmlElement->FirstAttribute();
        while (pAttr)
        {
            std::string attrName = pAttr->Name(); // attribute name
            std::string attrValue = pAttr->Value(); // attribute value
            element.addAttribute(attrName, attrValue);
            pAttr = pAttr->Next();
        }

        auto childElement = xmlElement->FirstChildElement();
        while (childElement) {
            // now loop all children elements
            element.addChildElement(loadXml(childElement));

            //next sibling
            childElement = childElement->NextSiblingElement();
        }
        return element;
    }
}