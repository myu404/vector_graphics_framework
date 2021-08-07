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
                PlacedGraphic pg;
                VG::Point point(std::stoi(placedGraphicElement->get()->getAttribute("x")), std::stoi(placedGraphicElement->get()->getAttribute("y")));
                pg.setPlacementPoint(point);

                auto vectorGraphicElement = placedGraphicElement->get()->getChildElements();
                if (vectorGraphicElement.size() != 1) throw std::invalid_argument("PlacedGraphic must have only 1 VectorGraphic");

                VG::HVectorGraphic vg(new VG::VectorGraphic);

                if (vectorGraphicElement.at(0)->getAttribute("closed") == "true") vg->closeShape();
                else vg->openShape();
                
                auto pointElements = vectorGraphicElement.at(0)->getChildElements();

                for (auto pointElement = pointElements.begin(); pointElement != pointElements.end(); ++pointElement)
                {
                    vg->addPoint(VG::Point(std::stoi(pointElement->get()->getAttribute("x")), std::stoi(pointElement->get()->getAttribute("y"))));
                }

                pg.setGraphic(vg);
                layer.pushBack(pg);
            }

            scene.pushBack(layer);
        }

        return scene;

    }
}