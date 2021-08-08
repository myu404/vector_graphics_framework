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
        if (!element) throw std::invalid_argument("ERROR: Failed to read XML.Bad XML format.");

        return std::make_shared<Element>(loadXml(element));
    }

    // Helper recursive function to parse XML
    Element Reader::loadXml(tinyxml2::XMLNode* xmlElement)
    {
        Element element(xmlElement->ToElement()->Name());

        auto comment = xmlElement->NextSibling();
        while (auto xmlComment = dynamic_cast<const tinyxml2::XMLComment*>(comment))
        {
            element.addComment(Element(xmlComment->Value()));
            comment = comment->NextSibling();
        }

        const tinyxml2::XMLAttribute* pAttr = xmlElement->ToElement()->FirstAttribute();
        while (pAttr)
        {
            std::string attrName = pAttr->Name(); // attribute name
            std::string attrValue = pAttr->Value(); // attribute value
            element.addAttribute(attrName, attrValue);
            pAttr = pAttr->Next();
        }

        auto childElement = xmlElement->FirstChildElement();
        while (childElement) 
        {
            // now loop all children elements
            element.addChildElement(loadXml(childElement));

            //next sibling
            childElement = childElement->NextSiblingElement();
        }
        return element;
    }
}