#pragma once
#include "Solid.h"
#include "Text.h"
#include "Model.h"
#include "ModelLoader.h"
#include <vector>

class Interfaz :public Solid
{
	vector<Solid*> solids;

public:
	Interfaz(){}

	Interfaz(const Interfaz& c) : Solid(c) {
		for (Solid* ps : c.solids) {
			this->solids.push_back(this->clone());
		}
	}
	virtual ~Interfaz() {
		for (Solid* ps : solids)
			delete ps;
		solids.clear();//No necesario, se llama automaticamente
	}
	Interfaz* clone() {
		return new Interfaz(*this);
	}
	vector<Solid*> getSolids() { return solids; }
	void setSolids(vector<Solid*> vs) { solids = vs; }
	Solid* getSolid(int i) {
		if (i >= solids.size() || i < 0)
			throw runtime_error("Out of range index, with value " + to_string(i) + " at Composite::getSolid()");
		return solids[i];
	}
	Solid* operator[](int i) {
		if (i >= solids.size() || i < 0)
			throw runtime_error("Out of range index, with value " + to_string(i) + " at Composite::getSolid()");
		return solids[i];
	}
	void add(Solid* ps) { solids.push_back(ps); }
	void remove(Solid* ps) { std::remove(solids.begin(), solids.end(), ps); }
	void Render();
	void update(double& dt);
	
	
};

