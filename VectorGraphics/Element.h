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
        Element() = default;
        Element(std::string elementName);
        const std::string getName() const;
        const std::string getAttribute(const std::string& attribute) const;
        const std::vector<std::shared_ptr<Element>>& getChildElements() const;
        const std::unordered_map<std::string, std::string>& getAttributes() const;
        const std::vector<std::shared_ptr<Element>>& getComments() const;

        void setName(const std::string name);
        void addAttribute(const std::string& attributeName, const std::string& attributeValue);
        void addChildElement(const Element& element);
        void addComment(const Element& element);
        bool hasComments();

    private:
        std::string myElementName;
        std::unordered_map<std::string, std::string> myAttributes;
        std::vector<std::shared_ptr<Element>> myChildElements;
        std::vector<std::shared_ptr<Element>> myComments;
    };

    using HElement = std::shared_ptr<Element>;
    using ElementList = std::vector<std::shared_ptr<Element>>;
    using AttributeMap = std::unordered_map<std::string, std::string>;
}