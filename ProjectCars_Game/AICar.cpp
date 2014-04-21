#include "AICar.h"
#include "GameObjectFactory.h"


Road* AICar::road = nullptr;

struct CarInfo
{
	CarInfo(char* _spritePath, Rect _collisionRect)
	{
		spritePath = _spritePath;
		collisionRect = _collisionRect;
	}

	char* spritePath;
	Rect collisionRect;
};


std::vector<CarInfo> carsInfo;

AICar::AICar(): BaseCar()
{
}

void AICar::InitialCarSprites()
{
	carsInfo.clear();
	carsInfo.push_back(CarInfo("../Assets/GameAssets/Car4.tga",Rect(72,244)));
	carsInfo.push_back(CarInfo("../Assets/GameAssets/Car5.tga",Rect(92,231)));
	carsInfo.push_back(CarInfo("../Assets/GameAssets/Car6.tga",Rect(84,221)));
	carsInfo.push_back(CarInfo("../Assets/GameAssets/Car7.tga",Rect(83,210)));
	carsInfo.push_back(CarInfo("../Assets/GameAssets/Car9.tga",Rect(71,184)));
}


AICar::~AICar()
{
}


void AICar::OnCreation()
{
	SetStaticFlag(false);
	int carIndex = GetRandom() * carsInfo.size();

	GameObjectFactory::AddSpiteComponent(this, carsInfo[carIndex].spritePath, 10)->SetOpaciyColor(1, 1, 1);
	GameObjectFactory::AddCollisionComponent(this, carsInfo[carIndex].collisionRect, Phys_Colliding);
	GameObjectFactory::AddDebugRectangleComponent(this, carsInfo[carIndex].collisionRect);
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

void AICar::SetOnDestoryCallBack(GameObject* object, OnDestoryCallBack callBack)
{
	onDestroyCallBack.first = object;
	onDestroyCallBack.second = callBack;
}

void AICar::OnDestroy()
{
	BaseCar::OnDestroy();
	CALL_MEMBER_FN(onDestroyCallBack.first, onDestroyCallBack.second)(this);
}