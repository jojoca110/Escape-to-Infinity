#pragma once
#include "Solid.h"
class Cuboid : public Solid
{
    float length, height, width;
public:
    Cuboid(Vector3D p = Vector3D(0, 0, -2), Vector3D o = Vector3D(0, 0, 0), Color c = Color(1, 1, 1), Vector3D os = Vector3D(0,0,0), Vector3D s = Vector3D(0,0,0))
        : Solid(p, o, c, os, s), 
        length(0.4f), height(0.5f), width(0.2f) {}

    float GetLength() const { return length; }
    float GetHeight() const  { return height; }
    float GetWidth() const { return width; }

    void SetLength(const float& LengthToSet) { this->length = LengthToSet; }
    void SetHeight(const float& HeightToSet) { this->height = HeightToSet; }
    void SetWidth(const float& WidthToSet) { this->width = WidthToSet; }

    void Render();
};

