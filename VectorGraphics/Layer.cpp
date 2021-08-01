#include "Layer.h"

namespace Framework
{
    Layer::Layer(const std::string name)
        : graphics(),
        alias(name)
    {
    }

    void Layer::pushBack(PlacedGraphic const& graphic)
    {
        graphics.push_back(graphic);
    }

    void Layer::remove(PlacedGraphic const& graphic)
    {
        graphics.remove_if([&](const auto& placedGraphic)
            {
                return placedGraphic == graphic;
            });
    }

    std::list<PlacedGraphic>::iterator Layer::begin()
    {
        return graphics.begin();
    }

    std::list<PlacedGraphic>::iterator Layer::end()
    {
        return graphics.end();
    }

    std::string Layer::getAlias() const
    {
        return alias;
    }
}