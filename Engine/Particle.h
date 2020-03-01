#pragma once
#include "Vec2.h"
#include "Graphics.h"


class Particle
{

public:
	void initParticle(Vec2 pos_in, Vec2 vel_in, Vec2 sRatio);

	Vec2 getPos();
	Vec2 getVel();

	void checkRebound(float left, float right, float up, float down);
	void updateVel(float dt);
	void updatePos(float dt);
	void drawParticle(Graphics& gfx);

private:

	bool created = false;

	float radius = 0.001f;
	float rho = 1500.0f;
	float cd = 0.5f;
	float pi = 3.1415926f;
	float A = radius * radius * pi;
	float Vol = 4.0f / 3.0f * pi * radius * radius * radius;
	float mass = Vol * rho;

	Vec2 pos;
	Vec2 vel;
	Vec2 sRatio;

};