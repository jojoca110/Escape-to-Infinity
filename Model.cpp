#include "Model.h"
#include "Contorno.h"
void Model::AddTriangle(const Triangle& triangle)
{
	triangles.push_back(triangle);
}


bool Model::colision(Solid* s) {
	Contorno* c = s->getContorno();
	return c->colisionModelo(this);
}

Contorno* Model::getContorno() { return this->contorno; }

void Model::setContorno(const Vector3D& pos, const float& size) {
	this->contorno = new Contorno(pos, size);
}

void Model::Clear()
{
	triangles.clear();
}

void Model::PaintColor(const Color& color)
{
	for (Triangle& triangle : this->triangles)
	{
		triangle.SetColor0(color);
		triangle.SetColor1(color);
		triangle.SetColor2(color);
	}
}

void Model::Render()
{
	
		glPushMatrix();
		glTranslatef(this->GetPosition().GetX(), this->GetPosition().GetY(), this->GetPosition().GetZ());
		glColor3f(this->GetColor().GetRed(), this->GetColor().GetGreen(), this->GetColor().GetBlue());
		glRotatef(this->GetOrientation().GetX(), 1.0, 0.0, 0.0);
		glRotatef(this->GetOrientation().GetY(), 0.0, 1.0, 0.0);
		glRotatef(this->GetOrientation().GetZ(), 0.0, 0.0, 1.0);

		for (Triangle& triangle : this->triangles)
		{
			triangle.Render();
		}

		glPopMatrix();
	
	
};

