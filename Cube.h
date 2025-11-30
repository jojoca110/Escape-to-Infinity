#pragma once
#include "Solid.h"


class Cube : public Solid
{
private:
	float size;
		
public:
	Cube(float d = 0.4f, Vector3D p = Vector3D(0, 0, -2), Color c = Color(1, 1, 1), Vector3D o = Vector3D(0, 0, 0), Vector3D os = Vector3D(0,0,0), Vector3D s = Vector3D(0,0,0))
		: Solid(p, o, c, os, s), size(d) {}

	float GetSize() const { return this->size; }

	void SetSize(const float& sizeToSet) { this->size = sizeToSet; }
	

	 Contorno* getContorno();
	 bool colision(Solid* s);

	void Render();
};

