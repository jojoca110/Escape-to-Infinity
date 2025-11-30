#pragma once
#include "Solid.h"
//#include <GL/glut.h>
//#include "Vector3D.h"
//#include "Color.h"

class Sphere : public Solid
{
private:
	/*
	Vector3D pos;
	Color rgb;
	Vector3D orientation;
	*/
	float radius;
	int slices, slacks;

public:
	Sphere( Vector3D p = Vector3D(0, 0, -2), Vector3D o = Vector3D(0, 0, 0), Color c = Color(1, 1, 1), Vector3D os = Vector3D(0,0,0), Vector3D s = Vector3D(0,0,0)) : Solid(p, o, c, os, s),
		radius(0.4f), slices(10), slacks(10) {}
/*
	inline Vector3D GetPos() const { return pos; }
	inline Color GetColor() const { return rgb; }
	inline Vector3D GetOrientation() const { return orientation; }
*/
	float GetRadius() const { return this->radius; }
	int GetSlices() const { return this->slices; }
	int GetSlacks() const { return this->slacks; }

/*
	inline void SetPos(const Vector3D& p) { this->pos = p; }
	inline void SetColor(const Color& c) { this->rgb = c; }
	inline void SetOrientation(const Vector3D& o) { this->orientation = o; }
*/
	void SetRadius(const float& radiusToSet) { this->radius = radiusToSet; }
	void SetSlices(const int& slicesToSet) { this->slices = slicesToSet; }
	void SetSlacks(const int& slacksToSet) { this->slacks = slacksToSet; }

	void Render();
};

