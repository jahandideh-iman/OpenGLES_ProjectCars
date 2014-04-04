#pragma once

#include "GameObjectFactory.h"
#include "PlayerCar.h"
#include "SideBlocker.h"


class GameMain: public GameObject
{
public:
	~GameMain();

	void Update(float dt) override;
	void OnCreation() override;

private:
	PlayerCar* playerCar;

	

};

