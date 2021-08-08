#pragma once

#include "Point.h"
#include "VectorGraphic.h"

namespace VG
{
    using HVectorGraphic = std::shared_ptr<VG::VectorGraphic>;
}

namespace Framework
{
    
    class PlacedGraphic 
    {
    public:
        PlacedGraphic();
        PlacedGraphic(VG::Point const& point, VG::HVectorGraphic vectorGraphic);
        ~PlacedGraphic() = default;

        // Implemented move and copy semantics for PlacedGraphic class
        // HVectorGraphic copy semantic performs a deep copy in lieu of shallow copy
        // Object pointed by HVectorGraphic is a copy at another address
        PlacedGraphic(const PlacedGraphic& other);
        PlacedGraphic& operator=(const PlacedGraphic& other);

        // Swap member function
        void swap(PlacedGraphic& src);

        PlacedGraphic(PlacedGraphic&& other) = default;
        PlacedGraphic& operator=(PlacedGraphic&&) = default;


        void setPlacementPoint(VG::Point const& placement);
        VG::Point const& getPlacementPoint() const;
        void setGraphic(VG::HVectorGraphic const& graphic);
        VG::HVectorGraphic const& getGraphic() const;

        bool operator==(const PlacedGraphic&) const;
        bool operator!=(const PlacedGraphic&) const;
    private:
        VG::Point placementPoint;
        VG::HVectorGraphic graphic;
    };
};

