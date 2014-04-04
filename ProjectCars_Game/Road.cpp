#include "Road.h"
#include "GameObjectFactory.h"


Road::Road() : GameObject()
{
}


Road::~Road()
{
}

void Road::OnCreation()
{
	spriteComp = GameObjectFactory::AddSpiteComponent(this, "Assets/road.tga", -100);

}

void Road::SetSpeed(int _speed)
{
	speed = _speed;
}

void Road::Update(float dt)
{
	spriteComp->AddTexCoord(0, speed*dt);
}