#include "Simulation.h"

Simulator::Simulator(Vec2 screenSize_in, Vec2 geometry_in)
	:
	screenSize(screenSize_in),
	geometry(geometry_in)
{
	sRatio = { screenSize.x / geometry.x, screenSize.y / geometry.y };
	p[0].initParticle({ 0.03f,0.02f }, { 0.1f,0.1f }, sRatio);
	p[1].initParticle({ 0.055f,0.015f }, { -0.5f,0.1f }, sRatio);
}

void Simulator::runSimulation()
{
	for (int j = 0; j < particles-1; j++)
	{
		for (int i = j + 1; i < particles; i++)
		{
			F = CheckContactForce(p[j], p[i]);

			p[j].updateForce(F * -1.0f);
			p[i].updateForce(F);
		}

	}
	for (int i = 0; i < particles; i++)
	{
		p[i].checkBounds(xLeft, xRight, yUp, yDown);
		p[i].updateVel(dt);
		p[i].updatePos(dt);
	}
}

void Simulator::DrawBounds(Graphics & gfx)
{
	gfx.Drawline({ xLeft * sRatio.x,yUp * sRatio.y }, { xRight * sRatio.x,yUp * sRatio.y }, Colors::MakeRGB(125, 125, 0));
	gfx.Drawline({ xLeft * sRatio.x,yDown * sRatio.y }, { xRight * sRatio.x,yDown * sRatio.y }, Colors::MakeRGB(125, 125, 0));
	gfx.Drawline({ xLeft * sRatio.x,yUp * sRatio.y }, { xLeft * sRatio.x,yDown * sRatio.y }, Colors::MakeRGB(125, 125, 0));
	gfx.Drawline({ xRight * sRatio.x,yUp * sRatio.y }, { xRight * sRatio.x,yDown * sRatio.y }, Colors::MakeRGB(125, 125, 0));
}

void Simulator::DrawSimulation(Graphics & gfx)
{
	DrawBounds(gfx);
	for (int i = 0; i < particles; i++)
	{
		p[i].drawParticle(gfx);
	}
}

Vec2 Simulator::CheckContactForce(Particle p1, Particle p2)
{
	float distance = (p2.getPos() - p1.getPos()).GetLength();
	float overlap = p1.getRadius() + p2.getRadius() - distance;

	if (overlap > 0)
	{
		Vec2 Norm = (p2.getPos() - p1.getPos()) / distance;
		Vec2 nForce = Norm * overlap * stiffness; 
		float vDiff = (p2.getVel() - p1.getVel()).Dot(Norm);
		Vec2 dForce = Norm * vDiff * damping;
		return (nForce - dForce);
	}
	return { 0.0f,0.0f };
}
