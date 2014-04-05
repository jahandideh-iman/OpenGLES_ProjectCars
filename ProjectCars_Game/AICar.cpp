#include "AICar.h"
#include "GameObjectFactory.h"


AICar::AICar(): BaseCar()
{
}


AICar::~AICar()
{
}


void AICar::OnCreation()
{
	SetStaticFlag(false);
	GameObjectFactory::AddSpiteComponent(this, "Assets/Car.tga", 20)->SetOpaciyColor(1, 1, 1);
}

void AICar::Update(float dt)
{
	BaseCar::Update(dt);
	CheckOutOfScreen();
}
void AICar::CheckOutOfScreen()
{
	if (GetPosition().Y < 0)
		Destroy();
}