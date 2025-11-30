#include "FirstPersonCamera.h"
void FirstPersonCamera::Render()
{
	glRotatef(this->GetOrientation().GetX(), 1, 0, 0);
	glRotatef(this->GetOrientation().GetY(), 0, 1, 0);
	glRotatef(this->GetOrientation().GetZ(), 0, 0, 1);
	glTranslatef(-1 * this->GetPosition().GetX(), -1 * this->GetPosition().GetY(), -1 * this->GetPosition().GetZ());
}

void FirstPersonCamera::Update(const float& time)
{		
	Camera::Update(time);
}

Vector3D FirstPersonCamera::calcSpeedVector()
{
	float yOrientation = degToRad(this->GetOrientation().GetY());
	float xOrientation = degToRad(this->GetOrientation().GetX());

	//FlyCam
	float xComponent = sin(yOrientation) * cos(xOrientation);
	float yComponent = -sin(xOrientation);
	float zComponent = -cos(yOrientation) * cos(xOrientation);

	Vector3D speedVector = { xComponent, yComponent, zComponent};
	return speedVector;
}

void FirstPersonCamera::ProcessKeyPressed(unsigned char key, int px, int py)
{
	switch (key) {
	case ' ':
		//this->Update(this->cameraStep);
		if (this->getDifficulty() == 1)
		{
			this->SetSpeed(/*this->calcSpeedVector() */ Vector3D(0, 0, -1));
		}
		if (this->getDifficulty() == 2)
		{
			this->SetSpeed(/*this->calcSpeedVector() */ Vector3D(0, 0, -1.5));
		}
		break;
	case 's':
	case 'S':
		//this->Update(-1 * this->cameraStep);
		break;
	case 'd':
	case 'D':
		if (this->GetPosition().GetX() == 4.0) {
			this->SetPosition(Vector3D(10.0, 5.0, this->GetPosition().GetZ()));
			//this->SetSpeed(Vector3D(0.05, this->GetSpeed().GetY(), this->GetSpeed().GetZ()));
		} 
		else
		if (this->GetPosition().GetX() == 10.0) {
			this->SetPosition(Vector3D(16.0, 5.0, this->GetPosition().GetZ()));
		}
		break;
	case 'a':
	case 'A':
		if (this->GetPosition().GetX() == 10.0) {
			this->SetPosition(Vector3D(4.0, 5.0, this->GetPosition().GetZ()));
		}else
		if (this->GetPosition().GetX() == 16.0) {
			this->SetPosition(Vector3D(10.0, 5.0, this->GetPosition().GetZ()));
		}
		break;
	}
}

void FirstPersonCamera::ProcessMouseMovement(int x, int y)
{
	if (this->GetMouseX() >= 0 && this->GetMouseY() >= 0)
	{
		Vector3D orientation = this->GetOrientation() + Vector3D(y - this->GetMouseY(), x - this->GetMouseX(), 0);
		this->SetOrientation(orientation);
	}
	this->SetMouseX(x);
	this->SetMouseY(y);
	
}