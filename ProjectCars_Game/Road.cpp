#include "Road.h"
#include "GameObjectFactory.h"
#include <cmath>


Road::Road() : GameObject()
{
}


Road::~Road()
{
}

void Road::OnCreation()
{

	SetSpeed(NORMAL_SPEED);
	spriteComp = GameObjectFactory::AddSpiteComponent(this, "../Assets/GameAssets/road.tga", -100);

	OpenGLRenderer::GetRenderer()->RegisterOnPressKey(this, Key_Up, inputCallBack(&Road::IncreaseSpeed));
	OpenGLRenderer::GetRenderer()->RegisterOnPressKey(this, Key_Down, inputCallBack(&Road::DecreaseSpeed));

}

void Road::SetSpeed(int _speed)
{
	speed = _speed;
}

void Road::Update(float dt)
{
	CalculateSpeed(dt);
	spriteComp->AddTexCoord(0, speed*dt);
	
}

void Road::CalculateSpeed(float dt)
{
	speed += currentAccel*dt;

	speed = clamp(speed, MIN_SPEED, MAX_SPEED);
}
void Road::IncreaseSpeed()
{
	currentAccel = ACCEL_UP;
}

void Road::DecreaseSpeed()
{
	currentAccel = ACCEL_DOWN;
}
