#pragma once
#include "XmlReader.h"
#include "Scene.h"
#include "SceneReader.h"
#include "SceneWriter.h"
#include "TestHarness.h"

#define STR(a) #a

const char* const TestXml = STR(
<Scene width="800" height="600">
  <Layer alias="sky">
    <PlacedGraphic x="86" y="99">
      <VectorGraphic closed="true">
        <Point x="1" y="2" />
        <Point x="3" y="4" />
        <Point x="5" y="6" />
      </VectorGraphic>
    </PlacedGraphic>
    <PlacedGraphic x="700" y="0">
      <VectorGraphic closed="false">
        <Point x="7" y="8" />
        <Point x="9" y="10" />
        <Point x="11" y="12" />
        <!--- etc. ---------->
      </VectorGraphic>
    </PlacedGraphic>
  </Layer>
  <Layer alias="mountains">
    <PlacedGraphic x="250" y="250">
      <VectorGraphic closed="false">
        <Point x="13" y="14" />
        <Point x="15" y="19" />
        <Point x="17" y="18" />
      </VectorGraphic>
    </PlacedGraphic>
  </Layer>
</Scene>);


TEST(WriteScene1stLayer, SceneWriter)
{
    std::stringstream xmlStream(TestXml);
    
    // Parse the XML stream and create an XML "DOM"
    Xml::HElement readRoot = Xml::XmlReader::loadXml(xmlStream);
    
    // Construct a Scene from the DOM
    Framework::Scene scene = Framework::SceneReader::readScene(*readRoot);
   
    // Go back the other way and construct another DOM from the Scene
    Xml::HElement root = Framework::SceneWriter::writeScene(scene);

    // Now verify some things in the new DOM...
    
    CHECK_EQUAL("Scene", root->getName());
    Xml::AttributeMap attributes = root->getAttributes();
    CHECK_EQUAL(2, attributes.size());
    CHECK_EQUAL("800", root->getAttribute("width"));
    CHECK_EQUAL("600", root->getAttribute("height"));

    Xml::ElementList childElements = root->getChildElements();
    CHECK_EQUAL(2, childElements.size());
    Xml::HElement child = std::make_shared<Xml::Element>(childElements.at(0));

    CHECK_EQUAL("Layer", child->getName());
    CHECK_EQUAL(1, child->getAttributes().size());
    CHECK_EQUAL("sky", child->getAttribute("alias"));

    Xml::ElementList layerElements = child->getChildElements();
    CHECK_EQUAL(2, layerElements.size());

    Xml::HElement layer = std::make_shared<Xml::Element>(layerElements.at(0));
    Xml::AttributeMap placedGraphicAttributes = layer->getAttributes();
    CHECK_EQUAL(2, placedGraphicAttributes.size());
    CHECK_EQUAL("86", layer->getAttribute("x"));
    CHECK_EQUAL("99", layer->getAttribute("y"));

    Xml::ElementList placedGraphicElements = layer->getChildElements();
    CHECK_EQUAL(1, placedGraphicElements.size());
    Xml::Element& vectorGraphic = placedGraphicElements[0];
    CHECK_EQUAL(1, vectorGraphic.getAttributes().size());
    CHECK_EQUAL("true", vectorGraphic.getAttribute("closed"));

    Xml::ElementList pointElements = vectorGraphic.getChildElements();
    CHECK_EQUAL(3, pointElements.size());


    CHECK_EQUAL("Point", pointElements[0].getName());
    CHECK_EQUAL("1", pointElements[0].getAttribute("x"));
    CHECK_EQUAL("2", pointElements[0].getAttribute("y"));

    CHECK_EQUAL("Point", pointElements[1].getName());
    CHECK_EQUAL("3", pointElements[1].getAttribute("x"));
    CHECK_EQUAL("4", pointElements[1].getAttribute("y"));

    CHECK_EQUAL("Point", pointElements[2].getName());
    CHECK_EQUAL("5", pointElements[2].getAttribute("x"));
    CHECK_EQUAL("6", pointElements[2].getAttribute("y"));
}

TEST(WriteScene2ndLayer, SceneWriter)
{
    std::stringstream xmlStream(TestXml);

    // Parse the XML stream and create an XML "DOM"
    Xml::HElement readRoot = Xml::XmlReader::loadXml(xmlStream);

    // Construct a Scene from the DOM
    Framework::Scene scene = Framework::SceneReader::readScene(*readRoot);

    // Go back the other way and construct another DOM from the Scene
    Xml::HElement root = Framework::SceneWriter::writeScene(scene);

    // Now verify some things in the new DOM...

    CHECK_EQUAL("Scene", root->getName());
    Xml::AttributeMap attributes = root->getAttributes();
    CHECK_EQUAL(2, attributes.size());
    CHECK_EQUAL("800", root->getAttribute("width"));
    CHECK_EQUAL("600", root->getAttribute("height"));

    Xml::ElementList childElements = root->getChildElements();
    CHECK_EQUAL(2, childElements.size());
    Xml::HElement child = std::make_shared<Xml::Element>(childElements.at(0));

    CHECK_EQUAL("Layer", child->getName());
    CHECK_EQUAL(1, child->getAttributes().size());
    CHECK_EQUAL("sky", child->getAttribute("alias"));

    Xml::ElementList layerElements = child->getChildElements();
    CHECK_EQUAL(2, layerElements.size());

    Xml::AttributeMap placedGraphicAttributes = layerElements[1].getAttributes();
    CHECK_EQUAL(2, placedGraphicAttributes.size());
    CHECK_EQUAL("700", layerElements[1].getAttribute("x"));
    CHECK_EQUAL("0", layerElements[1].getAttribute("y"));

    Xml::ElementList placedGraphicElements = layerElements[1].getChildElements();
    CHECK_EQUAL(1, placedGraphicElements.size());
    Xml::Element& vectorGraphic = placedGraphicElements[0];
    CHECK_EQUAL(1, vectorGraphic.getAttributes().size());
    CHECK_EQUAL("false", vectorGraphic.getAttribute("closed"));

    Xml::ElementList pointElements = vectorGraphic.getChildElements();
    CHECK_EQUAL(3, pointElements.size());


    CHECK_EQUAL("Point", pointElements[0].getName());
    CHECK_EQUAL("7", pointElements[0].getAttribute("x"));
    CHECK_EQUAL("8", pointElements[0].getAttribute("y"));

    CHECK_EQUAL("Point", pointElements[1].getName());
    CHECK_EQUAL("9", pointElements[1].getAttribute("x"));
    CHECK_EQUAL("10", pointElements[1].getAttribute("y"));

    CHECK_EQUAL("Point", pointElements[2].getName());
    CHECK_EQUAL("11", pointElements[2].getAttribute("x"));
    CHECK_EQUAL("12", pointElements[2].getAttribute("y"));
}

TEST(WriteScene3rdLayer, SceneWriter)
{
    std::stringstream xmlStream(TestXml);

    // Parse the XML stream and create an XML "DOM"
    Xml::HElement readRoot = Xml::XmlReader::loadXml(xmlStream);

    // Construct a Scene from the DOM
    Framework::Scene scene = Framework::SceneReader::readScene(*readRoot);

    // Go back the other way and construct another DOM from the Scene
    Xml::HElement root = Framework::SceneWriter::writeScene(scene);

    // Now verify some things in the new DOM...

    CHECK_EQUAL("Scene", root->getName());
    Xml::AttributeMap attributes = root->getAttributes();
    CHECK_EQUAL(2, attributes.size());
    CHECK_EQUAL("800", root->getAttribute("width"));
    CHECK_EQUAL("600", root->getAttribute("height"));

    Xml::ElementList childElements = root->getChildElements();
    CHECK_EQUAL(2, childElements.size());
    Xml::HElement child = std::make_shared<Xml::Element>(childElements.at(1));

    CHECK_EQUAL("Layer", child->getName());
    CHECK_EQUAL(1, child->getAttributes().size());
    CHECK_EQUAL("mountains", child->getAttribute("alias"));

    Xml::ElementList layerElements = child->getChildElements();
    CHECK_EQUAL(1, layerElements.size());

    Xml::AttributeMap placedGraphicAttributes = layerElements[0].getAttributes();
    CHECK_EQUAL(2, placedGraphicAttributes.size());
    CHECK_EQUAL("250", layerElements[0].getAttribute("x"));
    CHECK_EQUAL("250", layerElements[0].getAttribute("y"));

    Xml::ElementList placedGraphicElements = layerElements[0].getChildElements();
    CHECK_EQUAL(1, placedGraphicElements.size());
    Xml::Element& vectorGraphic = placedGraphicElements[0];
    CHECK_EQUAL(1, vectorGraphic.getAttributes().size());
    CHECK_EQUAL("false", vectorGraphic.getAttribute("closed"));

    Xml::ElementList pointElements = vectorGraphic.getChildElements();
    CHECK_EQUAL(3, pointElements.size());


    CHECK_EQUAL("Point", pointElements[0].getName());
    CHECK_EQUAL("13", pointElements[0].getAttribute("x"));
    CHECK_EQUAL("14", pointElements[0].getAttribute("y"));

    CHECK_EQUAL("Point", pointElements[1].getName());
    CHECK_EQUAL("15", pointElements[1].getAttribute("x"));
    CHECK_EQUAL("19", pointElements[1].getAttribute("y"));

    CHECK_EQUAL("Point", pointElements[2].getName());
    CHECK_EQUAL("17", pointElements[2].getAttribute("x"));
    CHECK_EQUAL("18", pointElements[2].getAttribute("y"));
}