#include "SceneWriter.h"
#include "VectorGraphic.h"
#include "Scene.h"
#include "Element.h"
#include <sstream>
#include <iostream>

namespace Framework
{
    Xml::HElement SceneWriter::writeScene(Scene& scene)
    {
        Xml::Element sceneElement("Scene");
        sceneElement.addAttribute("width", std::to_string(scene.getWidth()));
        sceneElement.addAttribute("height", std::to_string(scene.getHeight()));
        
        for (auto layer = scene.begin(); layer != scene.end(); ++layer)
        {
            Xml::Element layerElement("Layer");
            layerElement.addAttribute("alias", layer->getAlias());

            for (auto placedGraphic = layer->begin(); placedGraphic != layer->end(); ++placedGraphic)
            {
                Xml::Element placedGraphicElement("PlacedGraphic");
                auto placementPoint = placedGraphic->getPlacementPoint();
                placedGraphicElement.addAttribute("x", std::to_string(placementPoint.getX()));
                placedGraphicElement.addAttribute("y", std::to_string(placementPoint.getY()));
                

                Xml::Element vectorGraphicElement("VectorGraphic");
                auto vectorGraphic = placedGraphic->getGraphic();
                vectorGraphicElement.addAttribute("closed", (vectorGraphic->isClosed()) ? "true" : "false");
                
                for (size_t index = 0; index < vectorGraphic->getPointCount(); ++index)
                {
                    Xml::Element pointElement("Point");
                    auto point = vectorGraphic->getPoint(index);
                    pointElement.addAttribute("x", std::to_string(point.getX()));
                    pointElement.addAttribute("y", std::to_string(point.getY()));

                    vectorGraphicElement.addChildElement(pointElement);
                }

                placedGraphicElement.addChildElement(vectorGraphicElement);
                layerElement.addChildElement(placedGraphicElement);
            }
            sceneElement.addChildElement(layerElement);
        }
        return std::make_shared<Xml::Element>(sceneElement);
    }
}