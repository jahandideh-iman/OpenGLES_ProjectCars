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


	spriteComp = GameObjectFactory::AddSpiteComponent(this, "../Assets/GameAssets/road.tga", -100);

	OpenGLRenderer::GetRenderer()->RegisterOnPressKey(this, Key_Down, CallBack(&Road::SpeedDown));

	OpenGLRenderer::GetRenderer()->RegisterOnReleaseKey(this, Key_Down, CallBack(&Road::ReleaseSpeedDown));

	Reset();
}

void Road::Reset()
{
	SetSpeed(NORMAL_SPEED);
	currentAccel = ACCEL_UP;
}

void Road::SetSpeed(float _speed)
{
	currentSpeed = _speed;
}

float Road::GetSpeed()
{
	return currentSpeed;
}

void Road::Update(float dt)
{
	CalculateSpeed(dt);

	spriteComp->AddTexCoord(0, currentSpeed*dt);	
}

void Road::CalculateSpeed(float dt)
{
	if (abs(currentSpeed - desiredSpeed) < abs(currentAccel*dt))
		currentSpeed = desiredSpeed;
	else
		currentSpeed += currentAccel*dt;

	//std::cout << currentSpeed << std::endl;
}

void Road::SpeedDown()
{
	currentAccel = ACCEL_DOWN;
	desiredSpeed = MIN_SPEED;
}

void Road::ReleaseSpeedDown()
{
	desiredSpeed = MAX_SPEED;
	currentAccel = ACCEL_UP;
}

