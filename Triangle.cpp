#include "Triangle.h"

void Triangle::Render()
{
	glBegin(GL_TRIANGLES);

	glColor3f(this->Color0.GetRed(), this->Color0.GetGreen(), this->Color0.GetBlue());
	glNormal3f(this->Normals0.GetX(), this->Normals0.GetY(), this->Normals0.GetZ());
	glVertex3f(this->Vertex0.GetX(), this->Vertex0.GetY(), this->Vertex0.GetZ());

	glColor3f(this->Color1.GetRed(), this->Color1.GetGreen(), this->Color1.GetBlue());
	glNormal3f(this->Normals1.GetX(), this->Normals1.GetY(), this->Normals1.GetZ());
	glVertex3f(this->Vertex1.GetX(), this->Vertex1.GetY(), this->Vertex1.GetZ());

	glColor3f(this->Color2.GetRed(), this->Color2.GetGreen(), this->Color2.GetBlue());
	glNormal3f(this->Normals2.GetX(), this->Normals2.GetY(), this->Normals2.GetZ());
	glVertex3f(this->Vertex2.GetX(), this->Vertex2.GetY(), this->Vertex2.GetZ());

	glEnd();
}