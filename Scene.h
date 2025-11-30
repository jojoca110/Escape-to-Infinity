#pragma once
#include "Solid.h"
#include "Text.h"
#include "Teapot.h"
#include "Cube.h"
#include "Cuboid.h"
#include "Cylinder.h"
#include "Torus.h"
#include "Sphere.h"
#include "Camera.h"
#include "FirstPersonCamera.h"
#include "Triangle.h"
#include "Model.h"
#include "ModelLoader.h"


class Scene
{
private:
	FirstPersonCamera* camera;
	vector<Solid*> gameObjects;
	Vector3D boundary;

	void checkBoundary();

public:
	Scene() 
	{
		camera = new FirstPersonCamera(Vector3D(4.0f, 4.0f, 57.0f));
	}
	//Scene(Vector3D b = Vector3D(8, 6, 4)) : boundary(b) {}

	FirstPersonCamera* GetCamera()const { return camera; }

	void AddGameObject(Solid* objectToAdd);
	void DeleteGameObject();
	void deleteObject(int num);
	vector<Solid*> GetGameObjects() const { return this->gameObjects; }
	
	inline Vector3D GetBoundary() const { return this->boundary; }
	inline void SetBoundary(const Vector3D& boundaryToSet) { this->boundary = boundaryToSet; }

	void Init();
	void Render();
	void Update(const float& time);
	
	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessMouseMovement(int x, int y);
	void ProcessMouseClick(int button, int state, int x, int y);
};

