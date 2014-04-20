#pragma once

#include "Timer.h"
#include "GameObject.h"

const int spawnXPositions[4] = { 100, 300, 500, 700 };
const int spawnXPositionsCount = 4;

class DifficultyController : public GameObject
{
public:
	DifficultyController();
	~DifficultyController();

	void OnCreation() override;

	void Start();
	void Stop();

	void AddAICar();

private:
	Timer* timer;
};

