#include "Particle.h"
#include <assert.h>

void Particle::initParticle(Vec2 pos_in, Vec2 vel_in)
{
	assert(created == false);
	pos = pos_in;
	vel = vel_in;
	created = true;
}

Vec2 Particle::getPos()
{
	return pos;
}

Vec2 Particle::getVel()
{
	return vel;
}

void Particle::updatePos(double dt)
{
	pos += vel * dt;
}

void Particle::drawParticle(Graphics & gfx)
{
	gfx.DrawLineCircle(int(pos.x), int(pos.y), 9, 10, Colors::White);
}
