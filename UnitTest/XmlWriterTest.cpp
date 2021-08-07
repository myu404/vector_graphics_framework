#include "XmlWriter.h"
#include "XmlReader.h"
#include "VectorGraphic.h"
#include "TestHarness.h"
#include <iostream>
#include <fstream>

#define STR(a) #a

const char* const SceneXml = STR(
<Scene width="800" height="600">
  <Layer alias="sky">
    <PlacedGraphic x="0" y="0">
      <VectorGraphic closed="true">
        <Point x="1" y="2" />
        <Point x="3" y="4" />
        <Point x="5" y="6" />
      </VectorGraphic>
    </PlacedGraphic>
    <PlacedGraphic x="700" y="0">
      <VectorGraphic closed="true">
        <Point x="7" y="8" />
        <Point x="9" y="10" />
        <Point x="11" y="12" />
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


TEST(writeXmlStringStream, XmlWriter)
{
    std::stringstream xmlStream(SceneXml);
    Xml::HElement root = Xml::Reader::loadXml(xmlStream);
    //Xml::Writer::writeXml(root, std::cout);

    std::stringstream ssInput;
    Xml::Writer::writeXml(root, ssInput);

    Xml::HElement rootFile = Xml::Reader::loadXml(ssInput);

    CHECK_EQUAL("Scene", rootFile->getName());
    CHECK_EQUAL("800", rootFile->getAttribute("width"));
    CHECK_EQUAL("600", rootFile->getAttribute("height"));
    CHECK(root->getAttribute("depth").empty());

    Xml::AttributeMap attributes = rootFile->getAttributes();
    CHECK(!attributes.empty());
    CHECK_EQUAL(2, attributes.size());
    CHECK_EQUAL("800", attributes["width"])
    CHECK_EQUAL("600", attributes["height"])

    Xml::ElementList children = rootFile->getChildElements();
    CHECK(!children.empty());
    CHECK_EQUAL(2, children.size());

    Xml::HElement layer0 = children[0];
    CHECK_EQUAL("Layer", layer0->getName());
    attributes = layer0->getAttributes();
    CHECK(!attributes.empty());
    CHECK_EQUAL(1, attributes.size());
    CHECK_EQUAL("sky", layer0->getAttribute("alias"));

    Xml::ElementList layerChildren = layer0->getChildElements();
    CHECK(!layerChildren.empty());
    CHECK_EQUAL(2, layerChildren.size());
    Xml::HElement placedGraphic = layerChildren[0];
    CHECK_EQUAL("PlacedGraphic", placedGraphic->getName());
    attributes = placedGraphic->getAttributes();
    CHECK(!attributes.empty());
    CHECK_EQUAL(2, attributes.size());
    CHECK_EQUAL("0", placedGraphic->getAttribute("x"));
    CHECK_EQUAL("0", placedGraphic->getAttribute("y"));

    Xml::ElementList placedGraphicChildren = placedGraphic->getChildElements();
    CHECK(!placedGraphicChildren.empty());
    CHECK_EQUAL(1, placedGraphicChildren.size());
    Xml::HElement vectorGraphic = placedGraphicChildren[0];
    CHECK_EQUAL("VectorGraphic", vectorGraphic->getName());
    attributes = vectorGraphic->getAttributes();
    CHECK(!attributes.empty());
    CHECK_EQUAL(1, attributes.size());
    CHECK_EQUAL("true", vectorGraphic->getAttribute("closed"));

    Xml::HElement layer1 = children[1];
    CHECK_EQUAL("Layer", layer1->getName());
    attributes = layer1->getAttributes();
    CHECK(!attributes.empty());
    CHECK_EQUAL(1, attributes.size());
    CHECK_EQUAL("mountains", layer1->getAttribute("alias"));
}

TEST(writeXmlFileStream, XmlWriter)
{
    std::stringstream xmlStream(SceneXml);
    Xml::HElement root = Xml::Reader::loadXml(xmlStream);

    std::ofstream file("fileStream.xml");
    Xml::Writer::writeXml(root, file);
    file.close();

    std::ifstream fileInput;
    fileInput.open("fileStream.xml");
    Xml::HElement rootFile = Xml::Reader::loadXml(fileInput);
    fileInput.close();

    CHECK_EQUAL("Scene", rootFile->getName());
    CHECK_EQUAL("800", rootFile->getAttribute("width"));
    CHECK_EQUAL("600", rootFile->getAttribute("height"));
    CHECK(root->getAttribute("depth").empty());

    Xml::AttributeMap attributes = rootFile->getAttributes();
    CHECK(!attributes.empty());
    CHECK_EQUAL(2, attributes.size());
    CHECK_EQUAL("800", attributes["width"])
        CHECK_EQUAL("600", attributes["height"])

        Xml::ElementList children = rootFile->getChildElements();
    CHECK(!children.empty());
    CHECK_EQUAL(2, children.size());

    Xml::HElement layer0 = children[0];
    CHECK_EQUAL("Layer", layer0->getName());
    attributes = layer0->getAttributes();
    CHECK(!attributes.empty());
    CHECK_EQUAL(1, attributes.size());
    CHECK_EQUAL("sky", layer0->getAttribute("alias"));

    Xml::ElementList layerChildren = layer0->getChildElements();
    CHECK(!layerChildren.empty());
    CHECK_EQUAL(2, layerChildren.size());
    Xml::HElement placedGraphic = layerChildren[0];
    CHECK_EQUAL("PlacedGraphic", placedGraphic->getName());
    attributes = placedGraphic->getAttributes();
    CHECK(!attributes.empty());
    CHECK_EQUAL(2, attributes.size());
    CHECK_EQUAL("0", placedGraphic->getAttribute("x"));
    CHECK_EQUAL("0", placedGraphic->getAttribute("y"));

    Xml::ElementList placedGraphicChildren = placedGraphic->getChildElements();
    CHECK(!placedGraphicChildren.empty());
    CHECK_EQUAL(1, placedGraphicChildren.size());
    Xml::HElement vectorGraphic = placedGraphicChildren[0];
    CHECK_EQUAL("VectorGraphic", vectorGraphic->getName());
    attributes = vectorGraphic->getAttributes();
    CHECK(!attributes.empty());
    CHECK_EQUAL(1, attributes.size());
    CHECK_EQUAL("true", vectorGraphic->getAttribute("closed"));

    Xml::HElement layer1 = children[1];
    CHECK_EQUAL("Layer", layer1->getName());
    attributes = layer1->getAttributes();
    CHECK(!attributes.empty());
    CHECK_EQUAL(1, attributes.size());
    CHECK_EQUAL("mountains", layer1->getAttribute("alias"));
}