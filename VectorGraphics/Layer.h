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

        Layer(const Layer& other);
        Layer(Layer&& other);

        Layer& operator=(const Layer& other);

        // Swap member function
        void swap(Layer& src);

        Layer& operator=(Layer&& other);

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