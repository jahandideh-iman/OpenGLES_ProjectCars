#pragma once

#include "Timer.h"
#include "GameObject.h"
#include "AICar.h"

const int spawnXPositions[4] = { 100, 300, 500, 700 };
const int spawnXPositionsCount = 4;

typedef std::vector<AICar*> Cars;

class DifficultyController : public GameObject
{
public:
	DifficultyController();
	~DifficultyController();

	void OnCreation() override;

	void Start();
	void Clear();
	void Stop();

	void AddAICar();
	void OnCarDestory(AICar * car);

private:
	Timer* timer;
	Cars cars;
	
};

