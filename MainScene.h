#pragma once
#include "Scene.h"
#include "ModelLoader.h"
#include "Model.h"
#include "Cuboid.h"
#include "Text.h"
#include "Cube.h"
#include "Interfaz.h"

class MainScene : public Scene
{
	ModelLoader* loader = new ModelLoader();
	ModelLoader* loader2 = new ModelLoader();
	Model* player = new Model();
	//Player* player = new Player();

	
	Text* contadorH = new Text();
	Text* contadorS = new Text();
	int contVidas = 3;
	int contEstrellas = 0;

	Interfaz* interfaz = new Interfaz();;

	Cube* obstacle = new Cube();
	Cube* doubleObstacle = new Cube();
		
	int pos;
	int newLane;
	int contadorObstaculos;

public:
	MainScene() : Scene(), player(nullptr), pos(0), newLane(0), contadorObstaculos(0) {}

	void Initialize();
	void ProceduralGeneratedLane(const int& diff);
	void isColliding();
	

	Interfaz* GetInterfaz() const { return this->interfaz; }

	Model* GetPlayer() const { return this->player; }

	float GetPos() const { return this->pos; }
	void SetPos(const float& posToSet) { this->pos = posToSet; }

	float GetNewLane() const { return this->newLane; }
	void SetNewLane(const float& newLaneToSet) { this->newLane = newLaneToSet; }

	float GetContadorObstaculos() const { return this->contadorObstaculos; }
	void SetContadorObstaculos(const float& contadorToSet) { this->contadorObstaculos = contadorToSet; }

	int GetContadorEstrellas() const { return this->contEstrellas; }
	void SetContadorEstrellas(const int& contadorToSet) { this->contEstrellas = contadorToSet; }

	int GetContadorVidas() const { return this->contVidas; }
	void SetContadorVidas(const int& contadorToSet) { this->contVidas = contadorToSet; }
};

