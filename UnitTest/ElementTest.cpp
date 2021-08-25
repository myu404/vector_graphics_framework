#pragma once

#include "Element.h"
#include "TestHarness.h"

TEST(defaultCtor, Element)
{
    Xml::Element element;
    CHECK_EQUAL("", element.getName());
    CHECK_EQUAL(0, element.getAttributes().size());
    CHECK_EQUAL(0, element.getChildElements().size());
    CHECK_EQUAL(0, element.getComments().size());
}

TEST(ctor, Element)
{
    Xml::Element element("test");
    CHECK_EQUAL("test", element.getName());
}

TEST(copyCtor, Element)
{
    Xml::Element element("test");

    element.addAttribute("attrKey1", "attrValue1");
    element.addAttribute("attrKey2", "attrValue2");
    element.addAttribute("attrKey3", "attrValue3");

    element.addChildElement(Xml::Element("childEle1"));
    element.addChildElement(Xml::Element("childEle2"));
    element.addChildElement(Xml::Element("childEle3"));

    element.addComment(Xml::Element("comment1"));
    element.addComment(Xml::Element("comment2"));
    element.addComment(Xml::Element("comment3"));

    Xml::Element elementCopy(element);

    CHECK(element == elementCopy);
}

TEST(copyAssignment, Element)
{
    Xml::Element element("test");

    element.addAttribute("attrKey1", "attrValue1");
    element.addAttribute("attrKey2", "attrValue2");
    element.addAttribute("attrKey3", "attrValue3");

    element.addChildElement(Xml::Element("childEle1"));
    element.addChildElement(Xml::Element("childEle2"));
    element.addChildElement(Xml::Element("childEle3"));

    element.addComment(Xml::Element("comment1"));
    element.addComment(Xml::Element("comment2"));
    element.addComment(Xml::Element("comment3"));

    Xml::Element elementCopy("copy");

    elementCopy = element;

    CHECK(element == elementCopy);
}

TEST(moveCtor, Element)
{
    Xml::Element element("test");

    element.addAttribute("attrKey1", "attrValue1");
    element.addAttribute("attrKey2", "attrValue2");
    element.addAttribute("attrKey3", "attrValue3");

    element.addChildElement(Xml::Element("childEle1"));
    element.addChildElement(Xml::Element("childEle2"));
    element.addChildElement(Xml::Element("childEle3"));

    element.addComment(Xml::Element("comment1"));
    element.addComment(Xml::Element("comment2"));
    element.addComment(Xml::Element("comment3"));

    Xml::Element elementMove(std::move(element));

    Xml::AttributeMap attrMap = elementMove.getAttributes();
    Xml::ElementList elementList = elementMove.getChildElements();
    Xml::ElementList commentList = elementMove.getComments();

    CHECK(elementMove.hasComments());
    CHECK_EQUAL("test", elementMove.getName());
    CHECK_EQUAL(3, attrMap.size());
    CHECK_EQUAL(3, elementList.size());
    CHECK_EQUAL(3, commentList.size());
}

TEST(moveAssignment, Element)
{
    Xml::Element element("test");

    element.addAttribute("attrKey1", "attrValue1");
    element.addAttribute("attrKey2", "attrValue2");
    element.addAttribute("attrKey3", "attrValue3");

    element.addChildElement(Xml::Element("childEle1"));
    element.addChildElement(Xml::Element("childEle2"));
    element.addChildElement(Xml::Element("childEle3"));

    element.addComment(Xml::Element("comment1"));
    element.addComment(Xml::Element("comment2"));
    element.addComment(Xml::Element("comment3"));

    Xml::Element elementMove("copy");

    elementMove = std::move(element);

    Xml::AttributeMap attrMap = elementMove.getAttributes();
    Xml::ElementList elementList = elementMove.getChildElements();
    Xml::ElementList commentList = elementMove.getComments();

    CHECK(elementMove.hasComments());
    CHECK_EQUAL("test", elementMove.getName());
    CHECK_EQUAL(3, attrMap.size());
    CHECK_EQUAL(3, elementList.size());
    CHECK_EQUAL(3, commentList.size());
}

TEST(setName, Element)
{
    Xml::Element element("test");

    element.setName("deploy");

    CHECK_EQUAL("deploy", element.getName());
}

TEST(attributes, Element)
{
    Xml::Element element("test");

    element.addAttribute("attrKey1", "attrValue1");
    element.addAttribute("attrKey2", "attrValue2");
    element.addAttribute("attrKey3", "attrValue3");

    Xml::AttributeMap attrMap = element.getAttributes();

    CHECK_EQUAL(3, attrMap.size());
    CHECK_EQUAL("attrValue1", attrMap["attrKey1"]);
    CHECK_EQUAL("attrValue2", element.getAttribute("attrKey2"));
}

TEST(childElements, Element)
{
    Xml::Element element("test");

    element.addChildElement(Xml::Element("childEle1"));
    element.addChildElement(Xml::Element("childEle2"));
    element.addChildElement(Xml::Element("childEle3"));

    Xml::ElementList elementList = element.getChildElements();

    CHECK_EQUAL(3, elementList.size());
    CHECK_EQUAL("childEle1", elementList.at(0).getName());
    CHECK_EQUAL("childEle2", elementList.at(1).getName());

    bool expectedException = false;
    try
    {
        elementList.at(3).getName();
    }
    catch (std::out_of_range&)
    {
        expectedException = true;
    }

    CHECK(expectedException);
}

TEST(comments, Element)
{
    Xml::Element element("test");

    CHECK(!element.hasComments());

    element.addComment(Xml::Element("comment1"));
    element.addComment(Xml::Element("comment2"));
    element.addComment(Xml::Element("comment3"));

    auto commentList = element.getComments();

    CHECK(element.hasComments());
    CHECK_EQUAL(3, commentList.size());
    CHECK_EQUAL("comment1", commentList.at(0).getName());
    CHECK_EQUAL("comment2", commentList.at(1).getName());

    bool expectedException = false;
    try
    {
        commentList.at(3).getName();
    }
    catch (std::out_of_range&)
    {
        expectedException = true;
    }

    CHECK(expectedException);
}
