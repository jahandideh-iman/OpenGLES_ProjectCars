#pragma once

#include "Timer.h"
#include "GameObject.h"
#include "AICar.h"

const int laneXPosition[4] = { 100, 300, 500, 700 };
const int laneCount = 4;


#define MAX_GAME_CAR_SPEED 900
#define MIN_GAME_CAR_SPEED 100


struct GameCar
{
	GameCar(AICar* _car, unsigned int _lane)
	{
		car = _car;
		lane = _lane;
	}
	AICar* car;
	unsigned int lane;
};

typedef std::vector<GameCar*> Cars;

class DifficultyController : public GameObject
{
public:
	DifficultyController();
	~DifficultyController();

	void OnCreation() override;

	void Start();
	void Clear();
	void Stop();

	

	float GetMinSpeedForLane(unsigned int lane);
	void OnCarDestory(AICar * car);
private:
	void AddGameCar();
	GameCar* CreateGameCar(unsigned int lane);

	int GetAProperLane();

private:
	Timer* timer;
	Cars cars;

	std::vector<int> tempVecForProperLane;
	
};

