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

void Particle::checkRebound(float left, float right, float up, float down)
{
	if(pos.x - radius <= left)
	{
		pos.x = left + radius;
		vel.x = -vel.x;
	}
	else if(pos.x + radius> right)
	{
		pos.x = right - radius;
		vel.x = -vel.x;
	}
	if (pos.y - radius <= up)
	{
		pos.y = up + radius;
		vel.y =-vel.y;
	}
	else if (pos.y + radius> down)
	{
		pos.y = down - radius;
		vel.y = -vel.y;
	}
}

void Particle::updatePos(double dt)
{
	pos += vel * dt;
}

void Particle::drawParticle(Graphics & gfx)
{
	gfx.DrawLineCircle(int(pos.x), int(pos.y), radius-1, radius, Colors::White);
}
