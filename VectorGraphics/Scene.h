#include "Layer.h"
#include <list>


namespace Framework
{
    class Scene
    {
    public:
        // insert, remove, iteration support.
        // accessors to width and height.
        Scene() = default;
        Scene(const int width, const int height);
        ~Scene() = default;

        // Using default compiler generated move and copy semantics for Scene class
        // Member-wise move and copy semantics will invoke the member's move and copy semantics
        Scene(const Scene& other) = default;
        Scene(Scene&& other) = default;
        Scene& operator=(const Scene& other) = default;
        Scene& operator=(Scene&& other) = default;

        void pushBack(Layer const& layer);
        void remove(Layer const& layer);
        std::list<Layer>::iterator begin();
        std::list<Layer>::iterator end();
        int getWidth() const;
        int getHeight() const;
    private:
        std::list<Layer> layers;
        int width;
        int height;
    };

}