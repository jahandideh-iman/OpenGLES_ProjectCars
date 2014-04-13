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

	GameObjectFactory::AddTextComponent(this, "ABA")->SetPosition(Vect2(200,300));
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

	AICar::InitialCarSprites();
	AICar::road = road;
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
