#include "DifficultyController.h"
#include "GameObjectFactory.h"
#include "AICar.h"


DifficultyController::DifficultyController() : GameObject()
{
	
	
}


DifficultyController::~DifficultyController()
{
}

void DifficultyController::OnCreation()
{
	timer = (Timer*)GameObjectFactory::CreateActor<Timer>();
	timer->RegisterTimer(this, inputCallBack(&DifficultyController::AddAICar), 4);
}

void DifficultyController::AddAICar()
{
	AICar* tempCar = (AICar*)GameObjectFactory::CreateActor<AICar>();

	int xPos = spawnXPositions[int (GetRandom() * spawnXPositionsCount)];
	std::cout << xPos << std::endl;

	tempCar->SetPosition(xPos, 800);
	tempCar->SetBaseSpeed(300 + GetRandom() * 500);

	timer->RegisterTimer(this, inputCallBack(&DifficultyController::AddAICar), 1 + GetRandom() * 6);
}

