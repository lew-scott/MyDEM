#include "Particle.h"
#include <assert.h>

void Particle::initParticle(Vec2 pos_in, Vec2 vel_in, Vec2 sRatio_in)
{
	assert(created == false);
	pos = pos_in;
	vel = vel_in;
	sRatio = sRatio_in;
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

void Particle::updateVel(float dt)
{
	//drag = 0.5 * cd * rho * A * v^2;
	Vec2 drag = { 0.5f * cd * 1.225f * A * vel.x * vel.x,
				  0.5f * cd * 1.225f * A * vel.y * vel.y };

	// m*dU/dt = F -> dU = (F * dt)/m

	//vel -= (drag * dt) / mass;
	vel.y += mass * 9.81f * dt;

}

void Particle::updatePos(float dt)
{
	pos += vel * dt;
}

void Particle::drawParticle(Graphics & gfx)
{
	gfx.DrawLineCircle(int(pos.x * sRatio.x), int(pos.y * sRatio.y), int(radius * sRatio.x -1), int(radius * sRatio.x), Colors::White);
}
