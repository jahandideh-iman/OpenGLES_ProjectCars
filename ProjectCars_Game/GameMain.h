#pragma once

#include "GameObjectFactory.h"
#include "PlayerCar.h"
#include "SideBlocker.h"
#include "Road.h"


class GameMain: public GameObject
{
public:
	~GameMain();

	void Update(float dt) override;
	void OnCreation() override;

	void IncreaseSpeed();
	void DecreaseSpeed();

private:
	PlayerCar* playerCar;
	Road* road;

	int speed = 10;

	

};

