#include "Teapot.h"

void Teapot::Render() {
	glPushMatrix();
	glTranslatef(this->GetPosition().GetX(), this->GetPosition().GetY(), this->GetPosition().GetZ());
	glColor3f(this->GetColor().GetRed(), this->GetColor().GetGreen(), this->GetColor().GetBlue());
	glRotatef(this->GetOrientation().GetX(), 1.0, 0.0, 0.0);
	glRotatef(this->GetOrientation().GetY(), 0.0, 1.0, 0.0);
	glRotatef(this->GetOrientation().GetZ(), 0.0, 0.0, 1.0);
	glutSolidTeapot(this->GetSize());
	glPopMatrix();
}