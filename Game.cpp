#include "Game.h"
namespace fs = std::filesystem;

void Game::ProcessKeyPressed(unsigned char key, int px, int py)
{
	//std::cout << "Tecla pulsada: " << key << std::endl;
	if (activeScene == mainScene) {
		if (key == ' ')
		{
			if (getDificultad() == 1) {
				mainScene->GetPlayer()->SetSpeed(
					Vector3D(
						mainScene->GetPlayer()->GetSpeed().GetX(),
						mainScene->GetPlayer()->GetSpeed().GetY(),
						-1));
				mainScene->GetInterfaz()->SetSpeed(Vector3D(0, 0, -1));
				activeScene->GetCamera()->setDifficulty(1);
				activeScene->ProcessKeyPressed(key, px, py);
			}
			if (getDificultad() == 2) {
				mainScene->GetPlayer()->SetSpeed(
					Vector3D(
						mainScene->GetPlayer()->GetSpeed().GetX(),
						mainScene->GetPlayer()->GetSpeed().GetY(),
						-1.5));
				mainScene->GetInterfaz()->SetSpeed(Vector3D(0, 0, -1.5));
				activeScene->GetCamera()->setDifficulty(2);
				activeScene->ProcessKeyPressed(key, px, py);
			}
		}
		if (key == 'd') {
			if (mainScene->GetPlayer()->GetPosition().GetX() == 4)
			{
				mainScene->GetPlayer()->SetPosition(Vector3D(10, mainScene->GetPlayer()->GetPosition().GetY(), mainScene->GetPlayer()->GetPosition().GetZ()));
				mainScene->GetInterfaz()->SetPosition(Vector3D(0, mainScene->GetInterfaz()->GetPosition().GetY(), mainScene->GetInterfaz()->GetPosition().GetZ()));
			}
			else
				if (mainScene->GetPlayer()->GetPosition().GetX() == 10)
				{
					mainScene->GetPlayer()->SetPosition(Vector3D(16, mainScene->GetPlayer()->GetPosition().GetY(), mainScene->GetPlayer()->GetPosition().GetZ()));
					mainScene->GetInterfaz()->SetPosition(Vector3D(6, mainScene->GetInterfaz()->GetPosition().GetY(), mainScene->GetInterfaz()->GetPosition().GetZ()));
				}
			activeScene->ProcessKeyPressed(key, px, py);
		}
		if (key == 'a') {
			if (mainScene->GetPlayer()->GetPosition().GetX() == 10) 
			{
				mainScene->GetPlayer()->SetPosition(Vector3D(4, mainScene->GetPlayer()->GetPosition().GetY(), mainScene->GetPlayer()->GetPosition().GetZ()));
				mainScene->GetInterfaz()->SetPosition(Vector3D(-6, mainScene->GetInterfaz()->GetPosition().GetY(), mainScene->GetInterfaz()->GetPosition().GetZ()));

			}
			else
				if (mainScene->GetPlayer()->GetPosition().GetX() == 16) 
				{
					mainScene->GetPlayer()->SetPosition(Vector3D(10, mainScene->GetPlayer()->GetPosition().GetY(), mainScene->GetPlayer()->GetPosition().GetZ()));
					mainScene->GetInterfaz()->SetPosition(Vector3D(0, mainScene->GetInterfaz()->GetPosition().GetY(), mainScene->GetInterfaz()->GetPosition().GetZ()));

				}
			activeScene->ProcessKeyPressed(key, px, py);
		}
		if (key == 'w') {
			mainScene->GetPlayer()->SetPosition(Vector3D(mainScene->GetPlayer()->GetPosition().GetX(), 4, mainScene->GetPlayer()->GetPosition().GetZ()));
		}
		if (key == 's') {
			mainScene->GetPlayer()->SetPosition(Vector3D(mainScene->GetPlayer()->GetPosition().GetX(), 2, mainScene->GetPlayer()->GetPosition().GetZ()));
		}
		if (key == 'p') {
			mainScene->GetPlayer()->SetSpeed(Vector3D(0,0,0));
			mainScene->GetCamera()->SetSpeed(Vector3D(0,0,0));
			mainScene->GetInterfaz()->SetSpeed(Vector3D(0,0,0));
		}
	}
	if (activeScene == mainMenu) {
		if (key == ' ') {
			activeScene = diffSelector;
		}
	}
	if (activeScene == diffSelector) {
		if (key == '1') {
			this->setDificultad(1);
			activeScene = mainScene;
			activeScene->GetCamera()->SetPosition(Vector3D(10.0f, 5.0f, 59.0f));

			mainScene->GetPlayer()->SetOrientation(Vector3D(0, 180, 0));
			mainScene->GetPlayer()->SetPosition(Vector3D(10, 2, mainScene->GetPlayer()->GetPosition().GetZ()));
		}
		if (key == '2') {
			this->setDificultad(2);
			activeScene = mainScene;
			activeScene->GetCamera()->SetPosition(Vector3D(10.0f, 5.0f, 59.0f));

			mainScene->GetPlayer()->SetOrientation(Vector3D(0, 180, 0));
			mainScene->GetPlayer()->SetPosition(Vector3D(10, 2, mainScene->GetPlayer()->GetPosition().GetZ()));
		}
	}
	if (activeScene == gameOver) {
		if (key == 's') {
			activeScene->GetCamera()->SetSpeed(Vector3D(0, activeScene->GetCamera()->GetSpeed().GetY() - 0.05, 0));
		}
		if (key == 'w') {
			activeScene->GetCamera()->SetSpeed(Vector3D(0, activeScene->GetCamera()->GetSpeed().GetY() + 0.05, 0));
		}
		if (key == 'p') {
			activeScene->GetCamera()->SetSpeed(Vector3D(0, 0, 0));
		}
		if (key == 27) {
			exit(0);
		}
		
	}
}

void Game::ProcessMouseMovement(int x, int y)
{
	// de momento no hacemos nada:::
	//std::cout << "Movimiento del mouse: " << x << ", " << y << std::endl;
	//activeScene->ProcessMouseMovement(x, y);
}

void Game::ProcessMouseClick(int button, int state, int x, int y)
{
	// de momento na hacemos nada...
	std::cout << "Click: " << button << std::endl;
	
}

void Game::Init()
{
		
	Text* text = new Text();
	text->SetPosition(Vector3D(-4.0f, 20.0f, 8.0f));
	text->SetText(string("Select Difficulty:"));
	//text->SetColor(Color(0, 0, 0));
	this->diffSelector->AddGameObject(text);

	Text* normal = new Text();
	normal->SetPosition(Vector3D(-10.0f, 10.0f, 8.0f));
	normal->SetText(string("1) Normal"));
	//normal->SetColor(Color(0, 0, 0));
	this->diffSelector->AddGameObject(normal);

	Text* hard = new Text();
	hard->SetPosition(Vector3D(10.0f, 10.0f, 8.0f));
	hard->SetText(string("2) Hard"));
	//hard->SetColor(Color(0, 0, 0));
	this->diffSelector->AddGameObject(hard);
	this->scenes.push_back(diffSelector);


	this->mainScene->Initialize();
	this->scenes.push_back(mainScene);

	this->mainMenu->Generate();
	this->scenes.push_back(mainMenu);
	this->activeScene = mainMenu;
		
}


void Game::Render() 
{	
	this->activeScene->Render();
}

void Game::Update() {

	milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

	if ((currentTime.count() - this->initialMilliseconds.count()) - this->lastUpdateTime > UPDATE_PERIOD)
	{
		this->activeScene->Update(TIME_INCREMENT);
		this->lastUpdateTime = currentTime.count() - this->initialMilliseconds.count();
	}
	if (activeScene == mainScene) {
		int diff = this->getDificultad();
		this->mainScene->ProceduralGeneratedLane(diff);
		this->mainScene->isColliding();
		this->mainScene->DeleteGameObject();
		if (this->mainScene->GetContadorVidas() == 0) {

			int s = this->mainScene->GetContadorEstrellas();
			int diff = this->getDificultad();
			this->gameOver->generateRanking(s,diff);
			this->gameOver->showRanking(diff);
			activeScene = gameOver;
		}
	}
}