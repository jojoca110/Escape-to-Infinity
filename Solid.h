#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <GL/glut.h>
#include <vector>
#include <filesystem>

#include "Color.h"
#include "Vector3D.h"


class Contorno;

class Solid
{
	Vector3D pos;
	Vector3D orientation;
	Color rgb;

	Vector3D OrientationSpeed;
	Vector3D Speed;

	string name;
	
public:
	Solid(Vector3D p = Vector3D(0, 0, 0), Vector3D o = Vector3D(0, 0, 0), Color c = Color(1, 1, 1), Vector3D os = Vector3D(0, 0, 0), Vector3D s = Vector3D(0, 0, 0)) :
		pos(p), orientation(o), rgb(c), OrientationSpeed(os), Speed(s), name("Solid") {}
	
	//Solid(Vector3D p) :rgb(1, 1, 0), pos(p), Speed(0, 0, 0) {}

	 Vector3D GetPosition() const;
	 Vector3D GetOrientation() const;
	 Color GetColor() const;

	 Vector3D GetOrientationSpeed() const;
	 Vector3D GetSpeed() const;

	 void SetPosition(const Vector3D& PositionToSet);
	 void SetOrientation(const Vector3D& OrientationToSet);
	 void SetColor(const Color& ColorToSet);

	 void SetOrientationSpeed(const Vector3D& orientationSpeedToSet);
	 void SetSpeed(const Vector3D& SpeedToSet);

	 virtual bool colision(Solid* s) { return false; }
	 virtual Contorno* getContorno();

	 string getName() const { return this->name; }
	 void SetName(const string& nameToSet) { this->name = nameToSet; }

	 

	virtual void Render() = 0;	//Virtual: este método se puede redefinir en las clases de las que hereda. =0, no tiene implementacion en Solid, pero es obligatorio que las clases de las que hereda tengan este método implementado.
	virtual void Update(const float& time);

	
};

