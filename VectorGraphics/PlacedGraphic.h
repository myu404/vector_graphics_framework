#pragma once

#include "Point.h"
#include "VectorGraphic.h"


namespace VG
{
    using HVectorGraphic = std::unique_ptr<VG::VectorGraphic>;
}

namespace Framework
{
    
    class PlacedGraphic 
    {
    public:
        PlacedGraphic();
        PlacedGraphic(VG::Point const& point, VG::HVectorGraphic vectorGraphic);
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

