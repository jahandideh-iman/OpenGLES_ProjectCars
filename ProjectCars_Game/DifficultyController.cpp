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

void DifficultyController::AddGameCar()
{
	int lane = GetAProperLane();
	

	GameCar* gameCar = CreateGameCar(lane);
	

	cars.push_back(gameCar);

	timer->RegisterTimer(this, CallBack(&DifficultyController::AddGameCar), 1 + GetRandom() * 1);
}

int DifficultyController::GetAProperLane()
{
	int lane = GetRandom() * laneCount;

	return lane;
}

GameCar* DifficultyController::CreateGameCar(unsigned int lane)
{
	int xPos = laneXPosition[lane];
	AICar* tempCar = (AICar*)GameObjectFactory::CreateActor<AICar>();

	tempCar->SetPosition(xPos, 800);
	tempCar->SetBaseSpeed(GetMinSpeedForLane(lane) + abs(GetMinSpeedForLane(lane) - MAX_GAME_CAR_SPEED) *GetRandom());

	std::cout << "BaseSpeed " << tempCar->GetBaseSpeed() << std::endl;

	tempCar->SetOnDestoryCallBack(this, OnDestoryCallBack(&DifficultyController::OnCarDestory));

	return new GameCar(tempCar, lane);
}

float DifficultyController::GetMinSpeedForLane(unsigned int lane)
{
	float currentMaxSpeedInLane = 0;
	for (int i = 0; i < cars.size(); ++i)
	{
		if (cars[i]->lane = lane
			&& cars[i]->car->GetBaseSpeed() > currentMaxSpeedInLane)
			currentMaxSpeedInLane = cars[i]->car->GetBaseSpeed();
	}

	return currentMaxSpeedInLane;
}

void DifficultyController::Start()
{
	
	timer->RegisterTimer(this, CallBack(&DifficultyController::AddGameCar), 4);
}

void DifficultyController::Stop()
{
	timer->UnRegisterTimer(this, CallBack(&DifficultyController::AddGameCar));
}

void DifficultyController::Clear()
{
	Stop();
	
	for (int i = 0; i < cars.size(); ++i)
	{
		cars[i]->car->Destroy();
	}

}

void DifficultyController::OnCarDestory(AICar* car)
{
	for (int i = 0; i < cars.size(); ++i)
	{
		if (cars[i]->car == car)
		{
			cars.erase(cars.begin() + i);
			break;
		}
	}
	std::cout << "Diff" << std::endl;
}