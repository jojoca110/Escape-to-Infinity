#pragma once

using namespace std;
class Color;

class Color {
	float r, g, b;
public:
	Color(float redToSet = 0.0, float greenToSet = 0.0, float blueToSet = 0.0) :r(redToSet), g(greenToSet), b(blueToSet) {}

	inline float GetRed() const { return this->r; }
	inline float GetGreen() const { return this->g; }
	inline float GetBlue() const { return this->b; }
	inline void SetRed(const float& redToSet) { this->r = (redToSet >= 0.0 && redToSet <= 1.0 ? redToSet : this->r); }
	inline void SetGreen(const float& greenToSet) { this->r = (greenToSet >= 0.0 && greenToSet <= 1.0 ? greenToSet : this->g); }
	inline void SetBlue(const float& blueToSet) { this->r = (blueToSet >= 0.0 && blueToSet <= 1.0 ? blueToSet : this->b); }
};

