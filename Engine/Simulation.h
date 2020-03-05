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
	Vec2 CheckContactForce(Particle p1, Particle p2);



private:
	Vec2 screenSize;
	Vec2 geometry;
	Vec2 sRatio;
	static constexpr int particles = 2;
	Particle p[particles];

	float dt = 0.0002f;
	float xLeft = 0.0025f;
	float xRight = 0.3175f;
	float yUp = 0.0025f;
	float yDown = 0.2375f;
	float stiffness = 8000; 
	float damping = 20;
	Vec2 F = { 0.0f,0.0f };

};