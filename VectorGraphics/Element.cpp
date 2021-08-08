#pragma once

#include "Element.h"
#include <stdexcept>

namespace Xml
{
    Element::Element(std::string elementName)
        : myElementName(elementName),
        myAttributes(),
        myChildElements()
    {
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

    const std::vector<Element>& Element::getComments() const
    {
        return myComments;
    }

    void Element::addAttribute(const std::string& attributeName, const std::string& attributeValue)
    {
        myAttributes.emplace(attributeName, attributeValue);
    }

    void Element::addChildElement(const Element& element)
    {
        myChildElements.push_back(element);
    }

    void Element::setName(const std::string name)
    {
        myElementName = name;
    }

    void Element::addComment(const Element& element)
    {
        myComments.push_back(element);
    }

    bool Element::hasComments()
    {
        return myComments.size() > 0;
    }

}