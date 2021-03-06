#pragma once

#include "PlacedGraphic.h"
#include <list>
#include <string>

namespace Framework
{
    //using PlacedGraphicIterator = std::list<PlacedGraphic>::iterator;

    class Layer
    {
    public:
        // insert, remove, iteration support.
        // accessors to alias.
        Layer(const std::string name);
        ~Layer() = default;

        // Using default compiler generated move and copy semantics for Layer class
        // Member-wise move and copy semantics will invoke the member's move and copy semantics
        Layer(const Layer& other) = default;
        Layer(Layer&& other) = default;
        Layer& operator=(const Layer& other) = default;
        Layer& operator=(Layer&& other) = default;

        void pushBack(PlacedGraphic const& graphic);
        void remove(PlacedGraphic const& graphic);
        std::list<PlacedGraphic>::iterator begin();
        std::list<PlacedGraphic>::iterator end();
        std::string getAlias() const;

        bool operator==(const Layer&) const = default;
        bool operator!=(const Layer&) const = default;

        /*
        static class PlacedGraphicIterator : public std::list<PlacedGraphic>::iterator
        {
        public:
            ~PlacedGraphicIterator() = default;
        };
        */

    private:
        std::list<PlacedGraphic> graphics;
        std::string alias;
    };
}