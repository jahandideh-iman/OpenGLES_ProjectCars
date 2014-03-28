#include "GameMain.h"


GameMain::~GameMain()
{
}

void GameMain::Update(float dt)
{
}

void GameMain::OnCreation()
{
	std::cout << "GameMain::OnCreation" << std::endl;
	playerCar = (PlayerCar*) GameObjectFactory::CreateActor<PlayerCar>();
	playerCar->SetPosition(600, 100);

	GameObjectFactory::CreateActor<SideBlocker>()->SetPosition(300,200);

	

}
