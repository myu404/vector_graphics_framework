#pragma once

#include "Scene.h"
#include "Element.h"
#include "tinyxml2.h"
//#include "..\tinyxml2-master\tinyxml2.h"

namespace Framework
{
    // SceneWriter has static function, writeScene, that takes an Element object and
    // serialize Scene, Layer, PlacedGraphic, VectorGraphic, and Point objects into XML data

    class SceneWriter
    {
    public:
        static Xml::HElement writeScene(Scene& scene);
    };
}