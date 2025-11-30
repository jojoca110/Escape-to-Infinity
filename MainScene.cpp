#include "MainScene.h"
void MainScene::Initialize() {

	ModelLoader* loader = new ModelLoader();
	this->player = new Model();
	loader->SetScale(.5f);
	loader->LoadModel("../Recuperacion_V2/Models/Ships/Spaceship1.obj", "../Recuperacion_V2/Materials/Ships/Spaceship1.mtl");
	*this->player = loader->GetModel();
	this->player->SetPosition(Vector3D(4.0f, 2.0f, 50.0f));
	this->player->SetSpeed(Vector3D(0, 0, 0));
	this->player->SetOrientation(Vector3D(0, 180, 0));
	//this->player->SetColor(Color(1, 1, 1));

	this->player->setContorno(this->player->GetPosition(), loader->GetHeight() / 2);
	//this->player = new Player();
	this->AddGameObject(this->player);
	loader->Clear();

	int dist = 0;
	for (int i = 1; i < 5; i++) {

		Cuboid* cbd = new Cuboid();
		cbd->SetPosition(Vector3D(i + dist, 2.0f, 0.0f));
		cbd->SetLength(110);
		cbd->SetColor(Color(1.0f, 1.0f, 1.0f));
		cbd->SetOrientation(Vector3D(0.0f, 90.0f, 0.0f));
		this->AddGameObject(cbd);
		dist += 5;
	}
	
	loader->SetScale(1.0f);
	loader->LoadModel("../Recuperacion_V2/Models/PowerUps/Heart.obj", "../Recuperacion_V2/Materials/PowerUps/Heart.mtl");
	Model* vidas = new Model();
	*vidas = loader->GetModel();
	vidas->SetPosition(Vector3D(2, 10, this->player->GetPosition().GetZ() - 5));
	vidas->SetOrientation(Vector3D(0, 110, 0));
	//vidas->SetColor(Color(1, 0, 0));

	interfaz = new Interfaz();
	interfaz->add(vidas);

	loader->Clear();

	
	Text* X = new Text();
	X->SetPosition(Vector3D(3.0f, 9.5f, this->player->GetPosition().GetZ() - 5));
	X->SetText(string("X"));
	//X->SetColor(Color(0, 0, 0));
	interfaz->add(X);

	contadorH = new Text();
	contadorH->SetPosition(Vector3D(4.0f, 9.5f, this->player->GetPosition().GetZ() - 5));
	contadorH->SetText(string(std::to_string(contVidas)));
	//contadorH->SetColor(Color(0, 0, 0));
	interfaz->add(contadorH);
	interfaz->SetPosition(Vector3D(0, 0, 0));


	loader2->SetScale(1.0f);
	loader2->LoadModel("../Recuperacion_V2/Models/PowerUps/Star.obj", "../Recuperacion_V2/Materials/PowerUps/Star.mtl");
	Model* star = new Model();
	*star = loader2->GetModel();
	star->SetPosition(Vector3D(2, 5, this->player->GetPosition().GetZ() - 5));
	star->SetOrientation(Vector3D(0, 0, 0));

	
	interfaz->add(star);
	double minX = -150.0;   // Límite inferior en el eje X
	double maxX = 150.0; // Límite superior en el eje X
	double minY = -150.0;   // Límite inferior en el eje Y
	double maxY = 150.0; // Límite superior en el eje Y
	
	for (size_t i = 0; i < 30; i++)
	{
		double randomX = minX + static_cast<double>(rand()) / (RAND_MAX / (maxX - minX));
		double randomY = minY + static_cast<double>(rand()) / (RAND_MAX / (maxY - minY));

		Model* stars = new Model();
		//ml->LoadModel("../Recuperacion_V2/Models/PowerUps/Star.obj", "../Recuperacion_V2/Materials/PowerUps/Star.mtl");
		*stars = loader2->GetModel();
		stars->SetPosition(Vector3D(randomX, randomY, -120));
		//this->AddGameObject(stars);
		interfaz->add(stars);
	}

	loader2->Clear();

	Text* X2 = new Text();
	X2->SetPosition(Vector3D(3.0f, 4.5f, this->player->GetPosition().GetZ() - 5));
	X2->SetText(string("X"));
	//X2->SetColor(Color(0, 0, 0));
	interfaz->add(X2);

	contadorS = new Text();
	contadorS->SetPosition(Vector3D(4.0f, 4.5f, this->player->GetPosition().GetZ() - 5));
	contadorS->SetText(string(std::to_string(contEstrellas)));
	////contadorS->SetColor(Color(0, 0, 0));
	interfaz->add(contadorS);
	interfaz->SetPosition(Vector3D(0, 0, 0));

	this->AddGameObject(interfaz);
	
}

void MainScene::ProceduralGeneratedLane(const int& diff) {
	if (this->player->GetPosition().GetZ() < this->GetPos()) {
		
		ModelLoader* loader = new ModelLoader();
		loader->SetScale(.5f);
		int dist = 0;
		int dist2 = 0;
		int vida = 3;
		this->SetNewLane(this->GetNewLane() - 50);

 		
		if (diff == 2) {
			vida = 5;
		}
		this->SetContadorObstaculos(0);
		int contDobleAparcion = 0;
		for (int j = 0; j < 3; j++) {	//Lane number
			int pAparicion = rand() % 100;
			int pDobleAparicion = rand() % 100;
			bool doble = false;
			if (pDobleAparicion > 50 && contDobleAparcion < 2) {
				doble = true;
				contDobleAparcion++;
			}
			if (pAparicion < 80) {		//Probabilidad de aparición
				int altAleatoria = rand() % 100;
				int pVida = rand() % 100;
				
				obstacle = new Cube();
				obstacle->SetSize(2);

				
				if (altAleatoria < 50) {	//Altura (abajo)
					obstacle->SetPosition(Vector3D(j + dist2 + 4, 2, this->GetNewLane() - 50)); 
					if (doble) {	//doble aparción (arriba)

						if (pVida < vida) {
							loader->LoadModel("../Recuperacion_V2/Models/PowerUps/Heart.obj", "../Recuperacion_V2/Materials/PowerUps/Heart.mtl");
							Model* Heart = new Model();
							*Heart = loader->GetModel();
							Heart->SetPosition(Vector3D(j + dist2 + 4, 4, this->GetNewLane() - 50));
							Heart->SetOrientationSpeed(Vector3D(0, 0.5, 0));

							Heart->setContorno(Heart->GetPosition(), loader->GetHeight() / 2);
							Heart->SetName("Heart");
							//this->AddGameObject(HeartCollider);

							this->AddGameObject(Heart);
							loader->Clear();
						}
						else {
							doubleObstacle = new Cube();
							
							doubleObstacle->SetSize(2);
							doubleObstacle->SetPosition(Vector3D(j + dist2 + 4, 4, this->GetNewLane() - 50));
							doubleObstacle->SetName("DoubleObstacle");
							this->AddGameObject(doubleObstacle);
						
							this->SetContadorObstaculos(this->GetContadorObstaculos() + 1);
						}
					}
				}
				else {	//Altura (arriba)
					obstacle->SetPosition(Vector3D(j + dist2 + 4, 4, this->GetNewLane() - 50));
					if (doble) {	//doble aparición (abajo)
						if (pVida < 3) {
							loader->LoadModel("../Recuperacion_V2/Models/PowerUps/Heart.obj", "../Recuperacion_V2/Materials/PowerUps/Heart.mtl");
							Model* Heart = new Model();
							*Heart = loader->GetModel();
							Heart->SetPosition(Vector3D(j + dist2 + 4, 2, this->GetNewLane() - 50));
							Heart->SetOrientationSpeed(Vector3D(0, 0.5, 0));

							Heart->setContorno(Heart->GetPosition(), loader->GetHeight() / 2);
							Heart->SetName("Heart");

							this->AddGameObject(Heart);
							
							loader->Clear();
						}
						else {
						
							doubleObstacle = new Cube();
							
							doubleObstacle->SetSize(2);
							doubleObstacle->SetPosition(Vector3D(j + dist2 + 4, 2, this->GetNewLane() - 50));
							doubleObstacle->SetName("DoubleObstacle");
							this->AddGameObject(doubleObstacle);
							
							this->SetContadorObstaculos(this->GetContadorObstaculos() + 1);
						}
					}
				}
				obstacle->SetName("Obstacle");
				this->AddGameObject(obstacle);
				
				this->SetContadorObstaculos(this->GetContadorObstaculos() + 1);


			}
			else {
				int altAleatoria = rand() % 100;
				loader->LoadModel("../Recuperacion_V2/Models/PowerUps/Star.obj", "../Recuperacion_V2/Materials/PowerUps/star.mtl");
				int dist3 = 0;
				if (altAleatoria < 50) {	//Altura (abajo)
					for (int k = 0; k < 4; k++) {
						Model* star = new Model();
						*star = loader->GetModel();
						star->SetPosition(Vector3D(j + dist2 + 4, 2, this->GetNewLane() - 50 - dist3));
						star->SetOrientationSpeed(Vector3D(0, 0.5, 0));

						star->setContorno(star->GetPosition(), loader->GetHeight() / 2);
						star->SetName("Star");


						dist3 += 5;
						this->AddGameObject(star);

						
					}
				}
				else {	//Altura (arriba)
					for (int k = 0; k < 4; k++) {
						Model* star = new Model();
						*star = loader->GetModel();
						star->SetPosition(Vector3D(j + dist2 + 4, 4, this->GetNewLane() - 50 - dist3));
						star->SetOrientationSpeed(Vector3D(0, 1, 0));

						star->setContorno(star->GetPosition(), loader->GetHeight() / 2);
						star->SetName("Star");

						dist3 += 5;
						this->AddGameObject(star);
						
					}
				}
				loader->Clear();
			}
			dist2 += 5;
		}

		for (int i = 1; i < 5; i++) {

			Cuboid* cbd = new Cuboid();
			cbd->SetPosition(Vector3D(i + dist, 2.0f, this->GetNewLane()));
			cbd->SetLength(110);
			cbd->SetColor(Color(1.0f, 1.0f, 1.0f));
			cbd->SetOrientation(Vector3D(0.0f, 90.0f, 0.0f));
			this->AddGameObject(cbd);
			dist += 5;
		}
		this->SetPos(this->GetPos() - 50);
	}
}



void MainScene::isColliding() {
	
	if (this->player->GetSpeed().GetZ() != 0) {

		
		for (Solid* c : this->GetGameObjects()) {

			if (c != player && c->getContorno() != NULL) {
				this->player->setContorno(this->player->GetPosition(), loader->GetHeight() / 2);
				if (this->player->colision(c)) {
					if (c->getName() == "Star")
					{
						contEstrellas++;
						//this->player->SetStars(this->player->GetStars() + 1);
						//std::cout << "Colision Estrella" << std::endl;
						contadorS->SetText(string(std::to_string(contEstrellas)));
						for (int i = 0; i < this->GetGameObjects().size(); i++)
						{
							if (this->GetGameObjects()[i] == c) {
								this->deleteObject(i);
							}
						}
						
					}
					else
						if (c->getName() == "Heart")
						{
							//this->GetPlayer()->SetLife(this->GetPlayer()->GetLife() + 1);
							contVidas++;
							//std::cout << "Colision Corazon" << std::endl;
							contadorH->SetText(string(std::to_string(contVidas)));
							for (int i = 0; i < this->GetGameObjects().size(); i++)
							{
								if (this->GetGameObjects()[i] == c) {
									this->deleteObject(i);
								}
							}


						}
					if (c->getName() == "Obstacle" || c->getName() == "DoubleObstacle")
					{
						//std::cout << "Colision Obstaculo" << std::endl;
						this->player->SetSpeed(Vector3D(0, 0, 0));
						this->player->SetPosition(Vector3D(this->player->GetPosition().GetX(), this->player->GetPosition().GetY(), this->player->GetPosition().GetZ() + 1));
						this->GetCamera()->SetPosition(Vector3D(this->GetCamera()->GetPosition().GetX(), this->GetCamera()->GetPosition().GetY(), this->GetCamera()->GetPosition().GetZ() + 1));
						this->GetCamera()->SetSpeed(Vector3D(0, 0, 0));
						this->GetInterfaz()->SetPosition(Vector3D(this->GetInterfaz()->GetPosition().GetX(), this->GetInterfaz()->GetPosition().GetY(), this->GetInterfaz()->GetPosition().GetZ() + 1));
						this->GetInterfaz()->SetSpeed(Vector3D(0, 0, 0));
						contVidas--;
						//this->GetPlayer()->SetLife(this->GetPlayer()->GetLife() - 1);
						contadorH->SetText(string(std::to_string(contVidas)));
						for (int i = 0; i < this->GetGameObjects().size(); i++)
						{
							if (this->GetGameObjects()[i] == c) {
								this->deleteObject(i);
							}
						}
						
					}
				}
			}
		}
	}

}

