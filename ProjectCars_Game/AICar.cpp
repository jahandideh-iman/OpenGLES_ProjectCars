#include "AICar.h"
#include "GameObjectFactory.h"


Road* AICar::road = nullptr;

std::vector<char*> AICar::carSprites;

AICar::AICar(): BaseCar()
{
}

void AICar::InitialCarSprites()
{
	carSprites.clear();
	carSprites.push_back("../Assets/GameAssets/Car4.tga");
	carSprites.push_back("../Assets/GameAssets/Car5.tga");
	carSprites.push_back("../Assets/GameAssets/Car6.tga");
	carSprites.push_back("../Assets/GameAssets/Car7.tga");
	carSprites.push_back("../Assets/GameAssets/Car9.tga");
}


AICar::~AICar()
{
}


void AICar::OnCreation()
{
	SetStaticFlag(false);
	int randomSprite = GetRandom() * carSprites.size();
	GameObjectFactory::AddSpiteComponent(this, carSprites[randomSprite] ,10)->SetOpaciyColor(1, 1, 1);
	GameObjectFactory::AddCollisionComponent(this, Rect(128, 256), Phys_Colliding);
	GameObjectFactory::AddDebugRectangleComponent(this, Rect(128, 256));
}

void AICar::Update(float dt)
{
	BaseCar::Update(dt);

	SetVelocity(0, baseSpeed - road->GetSpeed());
	CheckOutOfScreen();
}

void AICar::SetBaseSpeed(float _baseSpeed)
{
	baseSpeed = _baseSpeed;
}

void AICar::CheckOutOfScreen()
{
	if (GetPosition().Y < -200 || GetPosition().Y > 900)
		Destroy();
}