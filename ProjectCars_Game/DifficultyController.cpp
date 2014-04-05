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
	tempCar->SetPosition(200, 600);
	tempCar->SetVelocity(0, -100);

	timer->RegisterTimer(this, inputCallBack(&DifficultyController::AddAICar), 1 + GetRandom() * 6);
}

