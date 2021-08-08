#include "Layer.h"
#include <stdexcept>

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
        auto elementsRemoved = graphics.remove_if([&](const auto& placedGraphic)
            {
                return placedGraphic == graphic;
            });

        if (elementsRemoved == 0) throw std::invalid_argument("PlacedGraphic does not exist in Layer. Nothing is removed.");
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