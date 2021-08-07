#pragma once
#include "..\tinyxml2-master\tinyxml2.h"
#include "Scene.h"
#include "Element.h"
#include "XMLReader.h"
//#include "tinyxml2.h"

namespace Framework
{
    class SceneWriter
    {
    public:
        static Xml::HElement writeScene(Scene& scene);
    };
}