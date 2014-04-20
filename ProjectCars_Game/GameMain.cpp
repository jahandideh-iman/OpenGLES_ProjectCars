#include "GameMain.h"
#include "Timer.h"


GameMain::~GameMain()
{
}

void GameMain::Update(float dt)
{
	GameObject::Update(dt);

	AddScore(road->GetSpeed() * dt / 100.0);
}

void GameMain::OnCreation()
{
	CreateRoad();
	CreatePlayerCar();
	CreateDifficultyController();

	StartGame();
	


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
	playerCar->SetOnCollisionCallBack(this, CallBack(&GameMain::OnPlayerCarCollision));
	
}

void GameMain::CreateDifficultyController()
{
	diffController = (DifficultyController*)GameObjectFactory::CreateActor<DifficultyController>();
}

void GameMain::AddScore(float amount)
{
	score += amount;
}

void GameMain::StartGame()
{
	RestartGame();
}

void GameMain::RestartGame()
{
	playerCar->SetPosition(400, 100);
	diffController->Start();
	score = 0;
}

void GameMain::OnPlayerCarCollision()
{
	RestartGame();
}