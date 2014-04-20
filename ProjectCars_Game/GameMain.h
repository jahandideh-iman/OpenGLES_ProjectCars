#pragma once

#include "GameObjectFactory.h"
#include "PlayerCar.h"
#include "SideBlocker.h"
#include "Road.h"
#include "DifficultyController.h"
#include "AICar.h"

typedef void (GameObject::*ScoreCallBack) (int score);

class GameMain: public GameObject
{

	//THE FUCK IS THIS?
public:
	float score = 0;
public:
	~GameMain();

	void Update(float dt) override;
	void OnCreation() override;

	void StartGame();
	void RestartGame();

	void AddScore(float amount);

	void OnPlayerCarCollision();


private:
	void CreateRoad();
	void CreatePlayerCar();
	void CreateDifficultyController();

private:
	PlayerCar* playerCar;
	Road* road;

	DifficultyController* diffController;



};

