#include "Layer.h"

namespace Framework
{
    Layer::Layer(const std::string name)
        : graphics(),
        alias(name)
    {
    }

    Layer::Layer(const Layer& other)
        : graphics(other.graphics),
        alias(other.alias)
    {
    }

    Layer::Layer(Layer&& other)
        : graphics(),
        alias(std::move(other.alias))
    {
        graphics.splice(graphics.begin(), other.graphics);
    }

    Layer& Layer::operator=(const Layer& other)
    {
        auto temp = other;
        temp.swap(*this);
        return *this;
    }

    // Swap member function
    void Layer::swap(Layer& src)
    {
        std::swap(graphics, src.graphics);
        std::swap(alias, src.alias);
    }

    Layer& Layer::operator=(Layer&& other)
    {
        graphics = std::move(other.graphics);
        alias = std::move(other.alias);
        return *this;
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