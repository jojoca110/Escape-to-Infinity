#pragma once
#include "Solid.h"
#include <string>;

class Text : public Solid
{
	string text;
public:
	Text(string t = "Usando la clase Text...", Vector3D p = Vector3D(0, 0, -2), Color c = Color(1, 1, 1), Vector3D o = Vector3D(0, 0, 0), Vector3D os = Vector3D(0, 0, 0), Vector3D s = Vector3D(0, 0, 0))
		: Solid(p, o, c, os, s), text(t) {}
	Text(const Text& c) : Solid(c), text(c.text) {}

	Text* clone() { return new Text(*this); }
	string GetText() const { return this->text; }
	void SetText(const string& textToSet) { this->text = textToSet; }


	void Render();
};

