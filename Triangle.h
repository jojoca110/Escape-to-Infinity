#pragma once
#include "Solid.h"
class Triangle : public Solid
{
	Vector3D Vertex0, Vertex1, Vertex2;
	Vector3D Normals0, Normals1, Normals2;
	Color Color0, Color1, Color2;
	
	Vector3D TexCoord0, TexCoord1, TexCoord2;

public:
	Triangle(
		Vector3D vertex0Argument = Vector3D(),
		Vector3D vertex1Argument = Vector3D(),
		Vector3D vertex2Argument = Vector3D(),
		Vector3D Normals0Argument = Vector3D(),
		Vector3D Normals1Argument = Vector3D(),
		Vector3D Normals2Argument = Vector3D(),
		Color color0Argument = Color(1, 0, 0),
		Color color1Argument = Color(0, 1, 0),
		Color color2Argument = Color(0, 0, 1)) :
		Vertex0(vertex0Argument), Vertex1(vertex1Argument), Vertex2(vertex2Argument),
		Normals0(Normals0Argument), Normals1(Normals1Argument), Normals2(Normals2Argument),
		Color0(color0Argument), Color1(color1Argument), Color2(color2Argument) {}

	/*Triangle(Vector3D p = Vector3D(0, 0, 0), Vector3D o = Vector3D(0, 0, 0), Color c = Color(1, 1, 1), Vector3D os = Vector3D(0, 0, 0), Vector3D s = Vector3D(0, 0, 0))
	: Solid(p, o, c, os, s), Vertex0(Vector3D(0, 0, 0)), Vertex1(Vector3D(1, 0, 0)), Vertex2(Vector3D(0, 1, 0)),
	Normals0(Vector3D(1, 1, 1)), Normals1(Vector3D(1, 1, 1)), Normals2(Vector3D(1, 1, 1)),
	Color0(Color(1, 0, 0)), Color1(Color(0, 1, 0)), Color2(Color(0, 0, 1)),
	TexCoord0(Vector3D(0, 0, 0)), TexCoord1(Vector3D(0, 0, 0)), TexCoord2(Vector3D(0, 0, 0)) {}*/
	
	/*Triangle(Vector3D v0, Vector3D v1, Vector3D v2, Vector3D n0, Vector3D n1, Vector3D n2)
		: Vertex0(v0), Vertex1(v1), Vertex2(v2),
		Normals0(n0), Normals1(n1), Normals2(n2) {}
	
	Triangle(Vector3D v0, Vector3D v1, Vector3D v2, Vector3D n0, Vector3D n1, Vector3D n2, Color c0, Color c1, Color c2)
		: Vertex0(v0), Vertex1(v1), Vertex2(v2),
		Normals0(n0), Normals1(n1), Normals2(n2),
		Color0(c0), Color1(c1), Color2(c2) {}
	
	Triangle(Vector3D v0, Vector3D v1, Vector3D v2, Vector3D n0, Vector3D n1, Vector3D n2, Color c0, Color c1, Color c2, Vector3D t0, Vector3D t1, Vector3D t2)
		: Vertex0(v0), Vertex1(v1), Vertex2(v2),
		Normals0(n0), Normals1(n1), Normals2(n2),
		Color0(c0), Color1(c1), Color2(c2),
		TexCoord0(t0), TexCoord1(t1), TexCoord2(t2) {}*/
	
	Vector3D GetVertex0() const { return Vertex0; }
	Vector3D GetVertex1() const { return Vertex1; }
	Vector3D GetVertex2() const { return Vertex2; }
	
	Vector3D GetNormals0() const { return Normals0; }
	Vector3D GetNormals1() const { return Normals1; }
	Vector3D GetNormals2() const { return Normals2; }

	Color GetColor0() const { return Color0; }
	Color GetColor1() const { return Color1; }
	Color GetColor2() const { return Color2; }


	void SetColor0(const Color& Color0ToSet) { this->Color0 = Color0ToSet; }
	void SetColor1(const Color& Color1ToSet) { this->Color1 = Color1ToSet; }
	void SetColor2(const Color& Color2ToSet) { this->Color2 = Color2ToSet; }

	void Render();
};

