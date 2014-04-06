#include "GameMain.h"
#include "Timer.h"


GameMain::~GameMain()
{
}

void GameMain::Update(float dt)
{

}

void GameMain::OnCreation()
{
	CreateRoad();
	CreatePlayerCar();
	CreateDifficultyController();
}

void GameMain::CreateRoad()
{
	SideBlocker * tempBlocker;
	tempBlocker = (SideBlocker*)GameObjectFactory::CreateActor<SideBlocker>();
	tempBlocker->SetPosition(0, 300);
	tempBlocker->InitialBlocker(Size(4, 600));

	tempBlocker = (SideBlocker*)GameObjectFactory::CreateActor<SideBlocker>();
	tempBlocker->SetPosition(800, 300);
	tempBlocker->InitialBlocker(Size(4, 600));

	road = (Road*)GameObjectFactory::CreateActor<Road>();
	road->SetPosition(400, 300);
}

void GameMain::CreatePlayerCar()
{
	playerCar = (PlayerCar*)GameObjectFactory::CreateActor<PlayerCar>();
	playerCar->SetPosition(400, 100);
}

void GameMain::CreateDifficultyController()
{
	diffController = (DifficultyController*)GameObjectFactory::CreateActor<DifficultyController>();
}
