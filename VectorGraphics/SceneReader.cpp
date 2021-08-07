#include "SceneReader.h"
#include "VectorGraphic.h"
#include <sstream>
#include <iostream>

namespace Framework
{
    Scene SceneReader::readScene(const Xml::Element& rootElement)
    {
        if (rootElement.getName() != "Scene") throw std::invalid_argument("Bad XML data");

        int width = std::stoi(rootElement.getAttribute("width"));
        int height = std::stoi(rootElement.getAttribute("height"));

        Scene scene(width, height);

        auto layerElements = rootElement.getChildElements();

        for (auto layerElement = layerElements.begin(); layerElement != layerElements.end(); ++layerElement)
        {
            Layer layer(layerElement->get()->getAttribute("alias"));

            auto placedGraphicElements = layerElement->get()->getChildElements();

            for (auto placedGraphicElement = placedGraphicElements.begin(); placedGraphicElement != placedGraphicElements.end(); ++placedGraphicElement)
            {
                auto vectorGraphicElement = placedGraphicElement->get()->getChildElements();
                if (vectorGraphicElement.size() != 1) throw std::invalid_argument("PlacedGraphic must have only 1 VectorGraphic");

                VG::HVectorGraphic vg(new VG::VectorGraphic);

                (vectorGraphicElement.at(0)->getAttribute("closed") == "true") ? vg->closeShape() : vg->openShape();
                
                auto pointElements = vectorGraphicElement.at(0)->getChildElements();

                for (auto pointElement : pointElements)
                {
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
}