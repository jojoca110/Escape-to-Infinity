#pragma once

#include <chrono>;
#include "Scene.h"
#include "MainMenu.h"
#include "MainScene.h"
#include "GameOver.h"

using namespace std::chrono;

class Game
{
private:
	
	const double TIME_INCREMENT = 1; //ms tiempo en el juego
	const long UPDATE_PERIOD = 10; //ms tiempo en el mundo real

	milliseconds initialMilliseconds;
	long lastUpdateTime;

	Scene* activeScene;
	vector<Scene*> scenes;
	float dificultad = 0;
		
public:
	Game() : activeScene(nullptr), initialMilliseconds(duration_cast<milliseconds>(system_clock::now().time_since_epoch())), lastUpdateTime(0) {}

	
	MainMenu* mainMenu = new(nothrow) MainMenu();
	MainScene* mainScene = new (nothrow) MainScene();
	Scene* diffSelector = new (nothrow) Scene();
	GameOver* gameOver = new (nothrow) GameOver();

	void Init();
	void Render();
	void Update();

	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessMouseMovement(int x, int y);
	void ProcessMouseClick(int button, int sate, int x, int y);
	
	void setDificultad(const float& dificultyToSet) { this->dificultad = dificultyToSet; }
	float getDificultad() { return this->dificultad; }
};

