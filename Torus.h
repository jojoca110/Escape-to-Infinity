#pragma once
#include "Solid.h"
class Torus : public Solid
{
	float intRadius, extRadius;
	int sides, rings;
public:
	Torus(Vector3D p = Vector3D(0, 0, -2), Vector3D o = Vector3D(0, 0, 0), Color c = Color(1, 1, 1), Vector3D os = Vector3D(0,0,0), Vector3D s = Vector3D(0,0,0))
		: Solid(p, o, c, os, s),
		intRadius(0.1f), extRadius(0.3f), sides(10), rings(10) {}

	float GetIntRadius() const { return intRadius; }
	float GetExtRadius() const { return extRadius; }
	int GetSides() const { return sides; }
	int GetRings() const { return rings; }

	void SetIntRadius(const float& IntRadiusToSet) { this->intRadius = IntRadiusToSet; }
	void SetExtRadius(const float& ExtRadiusToSet) { this->extRadius = ExtRadiusToSet; }
	void SetSides(const int& SidesToSet) { this->sides = SidesToSet; }
	void SetRings(const int& RingsToSet) { this->rings = RingsToSet; }

	void Render();
};

