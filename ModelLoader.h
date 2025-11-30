#pragma once
#include "Model.h"
#include "Contorno.h"

class ModelLoader 
{
	float scale = 1.0f;
	Model model;
	vector<Vector3D> vertexes;
	vector<Vector3D> normal;
	vector<Color> colors;
	vector<Vector3D> textures;

	float maxX, maxY, maxZ;
	float minX, minY, minZ;
		

	void calcBoundaries(Vector3D vectorPoint);
	Triangle center(Triangle triangle);
	Vector3D parseObjLineToVector3D(const string& Line);
	Triangle parseObjTriangle(const string& Line , Color color);

	Color parseObjLineToColor(const string& Line);
	Vector3D parseObjLineToVector2D(const string& Line);

public:
	
	ModelLoader(float scaleArgument = 1.0) : scale(scaleArgument),
		maxX(0), maxY(0), maxZ(0), minX(0), minY(0), minZ(0) {}

	Model GetModel() { return this->model; }
	float GetScale() const { return this->scale; }

	void SetScale(const float& scaleToSet) { this->scale = scaleToSet; }
	void LoadModel(const string& filePath);
	void LoadModel(const string& filePath, const string& matPath);

	void LoadMat(const string& matPath);

	float GetWidth() { return this->maxX - this->minX; }
	float GetHeight() { return this->maxY - this->minY; }
	float GetLength() { return this->maxZ - this->minZ; }
	
	void Clear();

 };

