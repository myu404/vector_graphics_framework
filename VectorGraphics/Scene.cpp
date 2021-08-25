#pragma once

#include "Scene.h"
#include <stdexcept>

namespace Framework
{
    Scene::Scene(const int width, const int height)
        : layers(),
        width(width),
        height(height)
    {
    }

    void Scene::pushBack(Layer const& layer)
    {
        layers.push_back(layer);
    }

    void Scene::remove(Layer const& layer)
    {
        auto elementsRemoved = layers.remove_if([&](const auto& layerElement)
            {
                return layer.getAlias() == layerElement.getAlias();
            });

        if (elementsRemoved == 0) throw std::invalid_argument("Layer does not exist in Scene. Nothing is removed.");
    }

    std::list<Layer>::iterator Scene::begin()
    {
        return layers.begin();
    }

    std::list<Layer>::iterator Scene::end()
    {
        return layers.end();
    }

    int Scene::getWidth() const
    {
        return width;
    }

    int Scene::getHeight() const
    {
        return height;
    }
}