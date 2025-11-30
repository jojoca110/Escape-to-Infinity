#pragma once
#include "Scene.h"
#include "Text.h"
#include "Model.h"
#include "ModelLoader.h"

class MainMenu : public Scene
{
	Text* t = new Text();;
	Model* m = new Model();
	ModelLoader* ml = new ModelLoader();
public:
	MainMenu(): Scene() {}

	void Generate();
};

