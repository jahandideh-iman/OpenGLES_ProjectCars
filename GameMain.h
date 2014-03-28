#pragma once
#include "GameObject.h"
#include "PlayerCar.h"
#include "GameObjectFactory.h"

class GameMain: public GameObject
{
public:
	~GameMain();

	void Update(float dt) override;
	void OnCreation() override;
private:
	PlayerCar* playerCar;

};

