#pragma once

#include "Timer.h"
#include "GameObject.h"
class DifficultyController : public GameObject
{
public:
	DifficultyController();
	~DifficultyController();

	void OnCreation() override;

	void AddAICar();

private:
	Timer* timer;
};

