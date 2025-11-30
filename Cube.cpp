#include "Cube.h"
#include "Contorno.h"

void Cube::Render() {
	
		glPushMatrix();
		glTranslatef(this->GetPosition().GetX(), this->GetPosition().GetY(), this->GetPosition().GetZ());
		glColor3f(this->GetColor().GetRed(), this->GetColor().GetGreen(), this->GetColor().GetBlue());
		glRotatef(this->GetOrientation().GetX(), 1.0, 0.0, 0.0);
		glRotatef(this->GetOrientation().GetY(), 0.0, 1.0, 0.0);
		glRotatef(this->GetOrientation().GetZ(), 0.0, 0.0, 1.0);
		glutSolidCube(this->GetSize());
		glPopMatrix();
}
 Contorno* Cube::getContorno() {
	return new Contorno(this->GetPosition(), this->GetSize());
}
 bool Cube::colision(Solid* s) {
	Contorno* c = s->getContorno();
	return c->colision(this);
}