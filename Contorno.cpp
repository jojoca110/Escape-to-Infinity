#include "Contorno.h"
Contorno::~Contorno() {
	// TODO Auto-generated destructor stub
}

bool Contorno::colision(Cube* c) {
	Vector3D pc = c->GetPosition();
	float rc = c->GetSize();
	Vector3D vd = pc - p;
	float l = vd.length();
	return l < r/2 + rc/2;
}

bool Contorno::colisionModelo(Model* c) {
	Vector3D pc = c->getContorno()->getP();
	float rc = c->getContorno()->getR();
	Vector3D vd = pc - p;
	float l = vd.length();
	return l < r / 2 + rc / 2;
}