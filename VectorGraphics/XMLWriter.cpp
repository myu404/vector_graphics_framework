#pragma once

#include "XMLWriter.h"
#include <sstream>


namespace Xml
{
    void Writer::writeXml(Xml::HElement rootElement, std::ostream& os)
    {
        tinyxml2::XMLDocument xmlDoc;
        tinyxml2::XMLElement* rootXmlElement = xmlDoc.NewElement(rootElement->getName().c_str());
        
        auto rootAttributes = rootElement->getAttributes();
        for (auto attr : rootAttributes)
        {
            rootXmlElement->SetAttribute(attr.first.c_str(), attr.second.c_str());
        }

        xmlDoc.InsertFirstChild(rootXmlElement);

        writeXml(rootElement, xmlDoc, rootXmlElement);

        //xmlDoc.SaveFile("xmlFilename.xml");

        tinyxml2::XMLPrinter xmlPrinter;
        xmlDoc.Print(&xmlPrinter);
        
        os << xmlPrinter.CStr() << std::endl;
    }

    void Writer::writeXml(Xml::HElement element, tinyxml2::XMLDocument& xmlDoc, tinyxml2::XMLNode* xmlElement)
    {
        auto childElements = element->getChildElements();

        for (auto element : childElements)
        {
            auto childXmlElement = xmlDoc.NewElement(element->getName().c_str());
            auto elementAttributes = element->getAttributes();
            for (auto attr : elementAttributes)
            {
                childXmlElement->SetAttribute(attr.first.c_str(), attr.second.c_str());
            }

            xmlElement->InsertEndChild(childXmlElement);

            if (element->hasComments())
            {
                for (auto comment : element->getComments())
                {
                    auto xmlComment = xmlDoc.NewComment(comment->getName().c_str());
                    xmlElement->InsertEndChild(xmlComment);
                }
            }

            writeXml(element, xmlDoc, childXmlElement);
        }
    }
}