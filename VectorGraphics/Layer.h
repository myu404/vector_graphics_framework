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