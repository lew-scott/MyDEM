#pragma once
#include "Graphics.h"
#include "Particle.h"
#include "Vec2.h"


class Simulator 
{
public: 
	Simulator(Vec2 screenSize_in, Vec2 geometry_in);
	void runSimulation();
	void DrawBounds(Graphics& gfx);
	void DrawSimulation(Graphics& gfx);



private:
	Vec2 screenSize;
	Vec2 geometry;
	Vec2 sRatio;
	Particle p;

	float dt = 0.001f;
	float xLeft = 0.0025f;
	float xRight = 0.0775f;
	float yUp = 0.0025f;
	float yDown = 0.0575f;

};