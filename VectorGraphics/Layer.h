#include "PlacedGraphic.h"
#include <list>
#include <string>

namespace Framework
{
    class Layer
    {
    public:
        // insert, remove, iteration support.
        // accessors to alias.
        Layer(const std::string name);
        ~Layer() = default;
        Layer(const Layer& other) = default;
        Layer(Layer&& other) = default;
        Layer& operator=(const Layer& other) = default;
        Layer& operator=(Layer&& other) = default;

        void pushBack(PlacedGraphic const& graphic);
        void remove(PlacedGraphic const& graphic);
        std::list<PlacedGraphic>::iterator begin();
        std::list<PlacedGraphic>::iterator end();
        std::string getAlias() const;
    private:
        std::list<PlacedGraphic> graphics;
        std::string alias;
    };
}