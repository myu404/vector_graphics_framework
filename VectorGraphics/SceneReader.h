#pragma once

#include "Scene.h"
#include "Element.h"
#include "tinyxml2.h"
//#include "..\tinyxml2-master\tinyxml2.h"

namespace Framework
{
    // SceneReader has static function, readScene, that takes an Element object and further
    // de-serialize XML data into Scene, Layer, PlacedGraphic, VectorGraphic, and Point objects
    class SceneReader
    {
    public:
        static Scene readScene(const Xml::Element& rootElement);

    private:
        static void assertElement(bool condition, const std::string expected, const std::string actual);
    };
}