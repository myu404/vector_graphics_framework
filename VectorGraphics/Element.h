#pragma once
#include "..\tinyxml2-master\tinyxml2.h"
#include <string>
#include <istream>
#include <memory>
#include <list>
#include <sstream>
#include <unordered_map>
#include <vector>

namespace Xml
{

    class Element
    {
    public:
        Element(std::stringstream& inputStream, std::string elementName = "Scene");
        const std::string getName() const;
        const std::string getAttribute(const std::string& attribute) const;
        const std::vector<Element>& getChildElements() const;
        const std::unordered_map<std::string, std::string>& getAttributes() const;

    private:
        std::string myElementName;
        std::unordered_map<std::string, std::string> myAttributes;
        std::vector<Element> myChildElements;
    };
}