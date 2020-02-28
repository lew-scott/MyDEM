#pragma once
#include "Vec2.h"
#include "Graphics.h"


class Particle
{

public:
	void initParticle(Vec2 pos_in, Vec2 vel_in);
	Vec2 getPos();
	Vec2 getVel();
	void checkRebound(float left, float right, float up, float down);
	void updatePos(double dt);
	void drawParticle(Graphics& gfx);

private:
	bool created = false;
	int radius = 10;
	Vec2 pos;
	Vec2 vel;

};