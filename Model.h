#pragma once
#include "Solid.h"
#include "Triangle.h"

class Model : public Solid
{
	vector<Triangle> triangles;
	Contorno* contorno;
public:
	Model() {};
	
	void AddTriangle(const Triangle& triangle);
	void Clear();
	void PaintColor(const Color& color);

	inline vector<Triangle> GetTriangles() { return this->triangles; }
	inline void SetModel(Model m) { this->triangles = m.GetTriangles(); }

	Model* Clone()
	{
		Model* clonedModel = new Model();
		clonedModel->triangles = this->triangles;
		//clonedModel->contorno = new Contorno(*this->contorno); // Clonar también el objeto Contorno si es necesario

		return clonedModel;
	}

	Contorno* getContorno();
	void setContorno(const Vector3D& pos, const float& size);
	bool colision(Solid* s);

	void Render();
	
};

