#include "DifficultyController.h"
#include "GameObjectFactory.h"



DifficultyController::DifficultyController() : GameObject()
{
	
	
}


DifficultyController::~DifficultyController()
{
}

void DifficultyController::OnCreation()
{
	timer = (Timer*)GameObjectFactory::CreateActor<Timer>();
}

void DifficultyController::AddAICar()
{
	AICar* tempCar = (AICar*)GameObjectFactory::CreateActor<AICar>();

	int xPos = spawnXPositions[int (GetRandom() * spawnXPositionsCount)];
	std::cout << xPos << std::endl;

	tempCar->SetPosition(xPos, 800);
	tempCar->SetBaseSpeed(300 + GetRandom() * 500);
	tempCar->SetOnDestoryCallBack(this, OnDestoryCallBack(&DifficultyController::OnCarDestory));

	cars.push_back(tempCar);

	timer->RegisterTimer(this, CallBack(&DifficultyController::AddAICar), 1 + GetRandom() * 6);
}

void DifficultyController::Start()
{
	
	timer->RegisterTimer(this, CallBack(&DifficultyController::AddAICar), 4);
}

void DifficultyController::Stop()
{
	timer->UnRegisterTimer(this, CallBack(&DifficultyController::AddAICar));
}

void DifficultyController::Clear()
{
	Stop();
	
	for (int i = 0; i < cars.size(); ++i)
	{
		cars[i]->Destroy();
	}

}

void DifficultyController::OnCarDestory(AICar* car)
{
	for (int i = 0; i < cars.size(); ++i)
	{
		if (cars[i] == car)
		{
			cars.erase(cars.begin() + i);
			break;
		}
	}
	std::cout << "Diff" << std::endl;
}