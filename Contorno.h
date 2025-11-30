#pragma once
#include <cmath>
#include "Cube.h"
#include "Model.h"
class Contorno
{
	Vector3D p;
	float r;	//Height/Width/length
public:
	Contorno(Vector3D p, float r) :p(p), r(r) {}
	virtual ~Contorno();
	
	bool colision(Cube* c);
	bool colisionModelo(Model* m);

	const Vector3D& getP() const { return p; }
	float getR() const { return r; }

	void setP(const Vector3D& p) { this->p = p; }
	void setR(float r) { this->r = r; }
};

