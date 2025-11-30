#pragma once
#include "Solid.h"

class Teapot : public Solid
{
private:
/*
	Vector3D pos;
	Color rgb;
	Vector3D orientation;
*/	
	float size;

public:
	Teapot(Vector3D p = Vector3D(0.0f, 0.0f, -2.0f), Vector3D o = Vector3D(0.0f, 0.0f, 0.0f), Color c = Color(1.0f, 1.0f, 1.0f), Vector3D os = Vector3D(0.0f, 0.0f, 0.0f), Vector3D s = Vector3D(0.0f, 0.0f, 0.0f)) 
		: Solid(p, o, c, os, s), size(0.4f) {}
	
	/*	
	inline Vector3D GetPos() const { return pos; }
	inline Color GetColor() const { return rgb; }
	inline Vector3D GetOrientation() const { return orientation; }
*/
	float GetSize() const { return this->size; }
/*
	inline void SetPos(const Vector3D& p) { this->pos = p; }
	inline void SetColor(const Color& c) { this->rgb = c; }
	inline void SetOrientation(const Vector3D& o) { this->orientation = o; }
*/	
	void SetSize(const float& sizeToSet) { this->size = sizeToSet; }

	void Render();
};