#pragma once
#include "..\tinyxml2-master\tinyxml2.h"
#include "Scene.h"
#include "Element.h"
//#include "tinyxml2.h"

namespace Framework
{
    class SceneReader
    {
    public:
        static Scene readScene(const Xml::Element& rootElement);

    private:
        static void assertElement(bool condition, const std::string expected, const std::string actual);
    };
}