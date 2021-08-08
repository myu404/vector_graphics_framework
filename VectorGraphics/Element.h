#pragma once

#include "tinyxml2.h"
//#include "..\tinyxml2-master\tinyxml2.h"
#include <string>
#include <memory>
#include <vector>
#include <unordered_map>

namespace Xml
{
    // Intermediate class to bridge XML data to Scene objects
    // Decode/De-serialize XML data to Element instance
    // Also used to encode/serialize Scene instance to XML data
    class Element
    {
    public:
        // Default ctor
        Element() = default;

        // Single parameter ctor
        Element(std::string elementName);

        // Dtor
        ~Element() = default;

        // Copy semantics (copy ctor and copy assignment)
        // Explicitly state that Element could be copied and set to default because member copy semantics are defined
        Element(const Element& other) = default;
        Element& operator=(const Element& other) = default;

        // Move semantics (move ctor and move assignment)
        // Explicitly state that Element could be moved and set to default because member move semantics are defined
        Element(Element&& other) = default;
        Element& operator=(Element&& other) = default;

        const std::string getName() const;
        const std::string getAttribute(const std::string& attribute) const;
        const std::vector<Element>& getChildElements() const;
        const std::unordered_map<std::string, std::string>& getAttributes() const;
        const std::vector<Element>& getComments() const;

        void setName(const std::string name);
        void addAttribute(const std::string& attributeName, const std::string& attributeValue);
        void addChildElement(const Element& element);

        // XML comment implementation
        void addComment(const Element& element);
        bool hasComments();

        bool operator==(const Element&) const = default;
        bool operator!=(const Element&) const = default;

    private:
        std::string myElementName;
        std::unordered_map<std::string, std::string> myAttributes;
        std::vector<Element> myChildElements;
        std::vector<Element> myComments;
    };

    using HElement = std::shared_ptr<Element>;
    using ElementList = std::vector<Element>;
    using AttributeMap = std::unordered_map<std::string, std::string>;
}