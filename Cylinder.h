#pragma once
#include "Solid.h"
class Cylinder : public Solid
{
	float baseRadius, topRadius, height;
	int slices, stacks;
public:
	Cylinder(Vector3D p = Vector3D(0, 0, -2), Vector3D o = Vector3D(0, 0, 0), Color c = Color(1, 1, 1), Vector3D os = Vector3D(0,0,0), Vector3D s = Vector3D (0,0,0))
		: Solid(p, o, c, os, s),
		baseRadius(0.4f), topRadius(0.4f), height(1.0f), slices(10), stacks(10) {}

	 
	float GetBaseRadius() { return baseRadius; }
	float GetTopRadius() { return topRadius; }
	float GetHeight() { return height; }
	int GetSlices() { return slices; }
	int GetStacks() { return stacks; }

	void SetBaseRadius(const float& BaseRadiusToSet) { this->baseRadius = BaseRadiusToSet; }
	void SetTopRadius(const float& TopRadiusToSet) { this->topRadius = TopRadiusToSet; }
	void SetHeight(const float& HeightToSet) { this->height = HeightToSet; }
	void SetSlices(const int& SlicesToSet) { this->slices = SlicesToSet; }
	void SetStacks(const int& StacksToSet) { this->stacks = StacksToSet; }

	void Render();

};