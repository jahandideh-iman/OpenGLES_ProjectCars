#pragma once

#include "GameObjectFactory.h"
#include "PlayerCar.h"
#include "SideBlocker.h"
#include "Road.h"
#include "WorkInProgressGUI.h"
#include "AICar.h"
#include "DifficultyController.h"

class GameMain: public GameObject
{
public:
	~GameMain();

	void Update(float dt) override;
	void OnCreation() override;

	void IncreaseSpeed();
	void DecreaseSpeed();

	void TestTimer();

private:
	PlayerCar* playerCar;
	Road* road;

	DifficultyController* diffController;

	int speed = 10;

	

	

};

