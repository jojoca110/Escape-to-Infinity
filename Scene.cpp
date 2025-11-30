#include "Scene.h"

void Scene::AddGameObject(Solid* objectToAdd) 
{ 
	gameObjects.push_back(objectToAdd); 
}

void Scene::DeleteGameObject() {

	if (this->GetCamera()->GetSpeed().GetZ() != 0) {
		std::vector<Solid*>::iterator it;

		for (it = gameObjects.begin(); it != gameObjects.end();) {
			if ((*it)->GetPosition().GetZ() > this->camera->GetPosition().GetZ() - 5.0f) {
				delete* it;
				it = gameObjects.erase(it);

			}
			else {
				++it;
			}
		}
	}
}

void Scene::deleteObject(int num) {
	gameObjects.erase(gameObjects.begin() + num);
}

void Scene::Render() {
	this->camera->Render();
	std::vector<Solid*>::iterator iter, end;
	for (iter = gameObjects.begin(), end = gameObjects.end(); iter != end; ++iter) {
		(*iter)->Render();
	}
}

void Scene::Update(const float& time) {
	this->camera->Update(time);
	std::vector<Solid*>::iterator iter, end;
	for (iter = gameObjects.begin(), end = gameObjects.end(); iter != end; ++iter) {
		(*iter)->Update(time);
		//checkBoundary(iter);
	}
}

void Scene::ProcessMouseMovement(int x, int y) {
	
	this->camera->ProcessMouseMovement(x, y);
	
}

void Scene::ProcessKeyPressed(unsigned char key, int px, int py) {
	this->camera->ProcessKeyPressed(key, px, py);
}