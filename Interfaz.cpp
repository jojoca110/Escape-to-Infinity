#include "Interfaz.h"
void Interfaz::Render() {
	glPushMatrix();
	glTranslated(this->GetPosition().GetX(), this->GetPosition().GetY(), this->GetPosition().GetZ());
	glRotated(this->GetOrientation().GetX(), 1, 0, 0);
	glRotated(this->GetOrientation().GetY(), 0, 1, 0);
	glRotated(this->GetOrientation().GetZ(), 0, 0, 1);
	for (Solid* ps : solids)
		ps->Render();
	glPopMatrix();
}
void Interfaz::update(double& dt) {
	Solid::Update(dt);
	//for (Solid* ps : solids) {
	//	ps->update(dt);
	//}
	for (vector<Solid*>::iterator i = solids.begin(); i < solids.end(); i++) {
		Solid*& s = *i;
		//(*(*i)).update(dt);
		//(*i)->update(dt);
		s->Update(dt);
	}
}
