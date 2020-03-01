#include "Simulation.h"

Simulator::Simulator(Vec2 screenSize_in, Vec2 geometry_in)
	:
	screenSize(screenSize_in),
	geometry(geometry_in)
{
	sRatio = { screenSize.x / geometry.x, screenSize.y / geometry.y };
	p.initParticle({ 0.01f,0.02f }, { 0.1f,0.1f }, sRatio);
}

void Simulator::runSimulation()
{
	p.updateVel(dt);
	p.updatePos(dt);
	p.checkRebound(xLeft, xRight, yUp, yDown);
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
	p.drawParticle(gfx);
}
