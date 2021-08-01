#include "Scene.h"



namespace Framework
{
    Scene::Scene(const int width, const int height)
        : layers(),
        width(width),
        height(height)
    {
    }

    Scene::Scene(const Scene& other)
        : layers(other.layers),
        width(other.width),
        height(other.height)
    {
    }

    void Scene::pushBack(Layer const& layer)
    {
        layers.push_back(layer);
    }

    void Scene::remove(Layer const& layer)
    {
        layers.remove_if([&](const auto& layerElement)
            {
                return layer.getAlias() == layerElement.getAlias();
            });
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