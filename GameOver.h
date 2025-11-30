#pragma once
#include "Scene.h"
#include "Text.h"
//#define MAX 100

class GameOver : public Scene
{
	int estrellas;
	
public:
	GameOver(int s = 0): Scene(), estrellas(s){}

	void generateRanking(const int& estrellas, const int& diff);
	void showRanking(const int& diff);
	
};

