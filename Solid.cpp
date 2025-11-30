#include "Solid.h"
#include "Contorno.h"

 Vector3D Solid::GetPosition() const { return pos; }
 Vector3D Solid::GetOrientation() const { return orientation; }
 Color Solid::GetColor() const { return rgb; }

 Vector3D Solid::GetOrientationSpeed() const { return OrientationSpeed; }
 Vector3D Solid::GetSpeed() const { return Speed; }


 void Solid::SetPosition(const Vector3D& PositionToSet) { this->pos = PositionToSet; }
 void Solid::SetOrientation(const Vector3D& OrientationToSet) { this->orientation = OrientationToSet; }
 void Solid::SetColor(const Color& ColorToSet) { this->rgb = ColorToSet; }

 Contorno* Solid::getContorno() {
	 return new Contorno(Vector3D(0, 0, 0), 1);
 }

 void Solid::SetOrientationSpeed(const Vector3D& OrientationToSet) { this->OrientationSpeed = OrientationToSet; }
 void Solid::SetSpeed(const Vector3D& SpeedToSet) { this->Speed = SpeedToSet; }
 void Solid::Update(const float& time) 
 { 
	 this->SetPosition(this->GetPosition() + this->GetSpeed() * time);
	 this->SetOrientation(this->GetOrientation() + this->GetOrientationSpeed() * time);
 }
