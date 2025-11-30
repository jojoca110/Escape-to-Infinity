#include "MainMenu.h"
void MainMenu::Generate() {
	this->t->SetPosition(Vector3D(-4.0f, 25.0f, 8.0f));
	this->t->SetText(string("Scape to Infinity"));
	this->t->SetColor(Color(1, 1, 1));
	this->AddGameObject(t);


	ml->SetScale(.5f);
	ml->LoadModel("../Recuperacion_V2/Models/Ships/Spaceship1.obj", "../Recuperacion_V2/Materials/Ships/Spaceship1.mtl");
	*this->m = ml->GetModel();
	this->m->SetOrientation(Vector3D(90, 180, 0));
	this->m->SetPosition(Vector3D(4, 4.5, 50));
	this->AddGameObject(this->m);
	this->ml->Clear();


	double minX = -30.0;   // Límite inferior en el eje X
	double maxX = 40.0; // Límite superior en el eje X
	double minY = -20.0;   // Límite inferior en el eje Y
	double maxY = 30.0; // Límite superior en el eje Y

	srand(static_cast<unsigned>(time(0)));
	ml->LoadModel("../Recuperacion_V2/Models/PowerUps/Star.obj", "../Recuperacion_V2/Materials/PowerUps/Star.mtl");
	for (size_t i = 0; i < 30; i++)
	{
		double randomX = minX + static_cast<double>(rand()) / (RAND_MAX / (maxX - minX));
		double randomY = minY + static_cast<double>(rand()) / (RAND_MAX / (maxY - minY));

		Model* stars = new Model();
		//ml->LoadModel("../Recuperacion_V2/Models/PowerUps/Star.obj", "../Recuperacion_V2/Materials/PowerUps/Star.mtl");
		*stars= ml->GetModel();
		stars->SetPosition(Vector3D(randomX, randomY, 8));
		this->AddGameObject(stars);
	}
	this->ml->Clear();

	Text* space = new Text();
	space->SetPosition(Vector3D(-10.0f, -15.0f, 8.0f));
	space->SetText(string("Press SPACEBAR to continue"));
	space->SetColor(Color(1, 1, 1));
	this->AddGameObject(space);
}