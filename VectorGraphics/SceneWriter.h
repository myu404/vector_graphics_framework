#pragma once

#include "Scene.h"
#include "Element.h"
#include "tinyxml2.h"
//#include "..\tinyxml2-master\tinyxml2.h"

namespace Framework
{
    class SceneWriter
    {
    public:
        static Xml::HElement writeScene(Scene& scene);
    };
}