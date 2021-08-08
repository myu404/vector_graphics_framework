#include "SceneReader.h"
#include "VectorGraphic.h"
#include <sstream>
#include <iostream>

namespace Framework
{
    Scene SceneReader::readScene(const Xml::Element& rootElement)
    {
        assertElement(rootElement.getName() == "Scene", "Scene", rootElement.getName());

        int width = std::stoi(rootElement.getAttribute("width"));
        int height = std::stoi(rootElement.getAttribute("height"));

        Scene scene(width, height);

        auto layerElements = rootElement.getChildElements();

        for (auto layerElement = layerElements.begin(); layerElement != layerElements.end(); ++layerElement)
        {
            assertElement(layerElement->get()->getName() == "Layer", "Layer", layerElement->get()->getName());

            Layer layer(layerElement->get()->getAttribute("alias"));

            auto placedGraphicElements = layerElement->get()->getChildElements();

            for (auto placedGraphicElement = placedGraphicElements.begin(); placedGraphicElement != placedGraphicElements.end(); ++placedGraphicElement)
            {
                assertElement(placedGraphicElement->get()->getName() == "PlacedGraphic", "PlacedGraphic", placedGraphicElement->get()->getName());

                auto vectorGraphicElement = placedGraphicElement->get()->getChildElements();

                if (vectorGraphicElement.size() != 1) throw std::invalid_argument("PlacedGraphic must have only 1 VectorGraphic");
                assertElement(vectorGraphicElement.at(0)->getName() == "VectorGraphic", "VectorGraphic", vectorGraphicElement.at(0)->getName());

                VG::HVectorGraphic vg(new VG::VectorGraphic);

                (vectorGraphicElement.at(0)->getAttribute("closed") == "true") ? vg->closeShape() : vg->openShape();
                
                auto pointElements = vectorGraphicElement.at(0)->getChildElements();

                for (auto pointElement : pointElements)
                {
                    assertElement(pointElement->getName() == "Point", "Point", pointElement->getName());
                    vg->addPoint(VG::Point(std::stoi(pointElement->getAttribute("x")), std::stoi(pointElement->getAttribute("y"))));
                }

                PlacedGraphic pg;
                VG::Point point(std::stoi(placedGraphicElement->get()->getAttribute("x")), std::stoi(placedGraphicElement->get()->getAttribute("y")));
                
                auto graphicWidth = point.getX() + vg->getWidth();
                auto graphicHeight = point.getY() + vg->getHeight();
                if (graphicWidth > width || graphicHeight > height) throw std::out_of_range("Placement of VectorGraphic is out of bounds");

                pg.setPlacementPoint(point);
                pg.setGraphic(vg);
                layer.pushBack(pg);
            }

            scene.pushBack(layer);
        }

        return scene;
    }

    void SceneReader::assertElement(bool condition, const std::string expected, const std::string actual)
    {
        if (!condition)
        {
            std::stringstream ss;
            ss << "Bad XML data. Expected " << expected << ", but read " << actual << "." << std::endl;
            throw std::invalid_argument(ss.str());
        }
    }
}