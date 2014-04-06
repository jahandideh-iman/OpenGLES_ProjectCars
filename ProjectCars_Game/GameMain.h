#pragma once

#include "GameObjectFactory.h"
#include "PlayerCar.h"
#include "SideBlocker.h"
#include "Road.h"
#include "DifficultyController.h"
#include "AICar.h"



class GameMain: public GameObject
{
public:
	~GameMain();

	void Update(float dt) override;
	void OnCreation() override;


private:
	void CreateRoad();
	void CreatePlayerCar();
	void CreateDifficultyController();

private:
	PlayerCar* playerCar;
	Road* road;

	DifficultyController* diffController;


};

