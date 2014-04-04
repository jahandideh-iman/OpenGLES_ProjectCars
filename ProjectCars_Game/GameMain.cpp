#include "GameMain.h"


GameMain::~GameMain()
{
}

void GameMain::Update(float dt)
{

}

void GameMain::OnCreation()
{
	SideBlocker * tempBlocker;
	tempBlocker = (SideBlocker*)GameObjectFactory::CreateActor<SideBlocker>();
	tempBlocker->SetPosition(100, 300);
	tempBlocker->InitialBlocker(Size(50, 200));

	tempBlocker = (SideBlocker*)GameObjectFactory::CreateActor<SideBlocker>();
	tempBlocker->SetPosition(700, 300);
	tempBlocker->InitialBlocker(Size(50, 200));

	tempBlocker = (SideBlocker*)GameObjectFactory::CreateActor<SideBlocker>();
	tempBlocker->SetPosition(400, 500);
	tempBlocker->InitialBlocker(Size(200, 50));

	tempBlocker = (SideBlocker*)GameObjectFactory::CreateActor<SideBlocker>();
	tempBlocker->SetPosition(400, 100);
	tempBlocker->InitialBlocker(Size(200, 50));


	std::cout << "GameMain::OnCreation" << std::endl;
	playerCar = (PlayerCar*) GameObjectFactory::CreateActor<PlayerCar>();
	playerCar->SetPosition(400, 300);

	road = (Road*)GameObjectFactory::CreateActor<Road>();
	road->SetPosition(400, 300);

	road->SetSpeed(200);
	OpenGLRenderer::GetRenderer()->RegisterOnPressKey(this, Key_Up, inputCallBack(&GameMain::IncreaseSpeed));
	OpenGLRenderer::GetRenderer()->RegisterOnPressKey(this, Key_Down, inputCallBack(&GameMain::DecreaseSpeed));

	//OpenGLRenderer::GetRenderer()->RegisterOnReleaseKey(this, Key_Up, inputCallBack(&PlayerCar::Stop));
	//OpenGLRenderer::GetRenderer()->RegisterOnReleaseKey(this, Key_Down, inputCallBack(&PlayerCar::Stop));


	

	

}

void GameMain::IncreaseSpeed()
{

}

void GameMain::DecreaseSpeed()
{

}