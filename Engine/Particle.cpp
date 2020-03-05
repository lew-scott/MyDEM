#include "Particle.h"
#include <assert.h>
#include <algorithm>

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

float Particle::getRadius()
{
	return radius;
}

void Particle::checkBounds(float left, float right, float up, float down)
{
	if(pos.x - radius <= left)
	{
		pos.x = left + radius;
		vel.x = -vel.x * 0.5f;
	}
	else if(pos.x + radius> right)
	{
		pos.x = right - radius;
		vel.x = -vel.x * 0.5f;
	}
	if (pos.y - radius <= up)
	{
		pos.y = up + radius;
		vel.y = -vel.y * 0.5f;
	}
	else if (pos.y + radius> down)
	{
		pos.y = down - radius;
		vel.y = -vel.y * 0.5f;

		// dummy friction
		if (vel.x > 0.0001f)
		{
			vel.x *= 0.95;
		}
		else
		{
			vel.x = 0;
		}
	}
}

void Particle::updateVel(float dt)
{


	vel += (Force / mass)*dt;
	vel.y +=  9.81f * dt;

}

void Particle::updatePos(float dt)
{
	pos += vel * dt;
}

void Particle::updateForce(const Vec2& F)
{
	Force = F;
}

void Particle::drawParticle(Graphics & gfx)
{
	gfx.DrawLineCircle(int(pos.x * sRatio.x), int(pos.y * sRatio.y), int(radius * sRatio.x -1), int(radius * sRatio.x), Colors::White);
}
