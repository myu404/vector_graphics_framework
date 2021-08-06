#pragma once
#include "..\tinyxml2-master\tinyxml2.h"
#include "Scene.h"
//#include "tinyxml2.h"

namespace Framework
{
    class SceneReader
    {
    public:
        static Scene readScene(const tinyxml2::XMLElement& rootElement);
    };
}