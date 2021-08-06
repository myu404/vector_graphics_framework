#include "Element.h"

namespace Xml
{
    Element::Element(std::stringstream& inputStream, std::string elementName)
        : myElementName(),
        myAttributes(),
        myChildElements()
    {
        tinyxml2::XMLDocument xmlDoc;
        xmlDoc.Parse(inputStream.str().c_str());
        tinyxml2::XMLElement* element = xmlDoc.RootElement();
        while (element->Name() != elementName)
        {
            element = element->FirstChildElement();
        }
        myElementName = element->Name();

        const tinyxml2::XMLAttribute* pAttr = element->FirstAttribute();
        while (pAttr)
        {
            std::string attrName = pAttr->Name(); // attribute name
            std::string attrValue = pAttr->Value(); // attribute value
            myAttributes.emplace(attrName, attrValue);
            pAttr = pAttr->Next();
        }

        auto childElement = element->FirstChildElement();
        while (childElement) {
            // now loop all children elements
            myChildElements.emplace_back(inputStream, childElement->Name());

            //next sibling
            childElement = childElement->NextSiblingElement();
        }
    }

    const std::string Element::getName() const
    {
        return myElementName;
    }

    const std::string Element::getAttribute(const std::string& attribute) const
    {
        try
        {
            return myAttributes.at(attribute);
        }
        catch (std::out_of_range&)
        {
            return "";
        }
    }

    const std::unordered_map<std::string, std::string>& Element::getAttributes() const
    {
        return myAttributes;
    }

    const std::vector<Element>& Element::getChildElements() const
    {
        return myChildElements;
    }




}