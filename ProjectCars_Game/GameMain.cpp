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
	SideBlocker * tempBlocker;
	tempBlocker = (SideBlocker*)GameObjectFactory::CreateActor<SideBlocker>();
	tempBlocker->SetPosition(0, 300);
	tempBlocker->InitialBlocker(Size(4, 600));

	tempBlocker = (SideBlocker*)GameObjectFactory::CreateActor<SideBlocker>();
	tempBlocker->SetPosition(800, 300);
	tempBlocker->InitialBlocker(Size(4, 600));



	std::cout << "GameMain::OnCreation" << std::endl;
	playerCar = (PlayerCar*) GameObjectFactory::CreateActor<PlayerCar>();
	playerCar->SetPosition(400, 100);

	road = (Road*)GameObjectFactory::CreateActor<Road>();
	road->SetPosition(400, 300);
	road->SetSpeed(200);
	OpenGLRenderer::GetRenderer()->RegisterOnPressKey(this, Key_Up, inputCallBack(&GameMain::IncreaseSpeed));
	OpenGLRenderer::GetRenderer()->RegisterOnPressKey(this, Key_Down, inputCallBack(&GameMain::DecreaseSpeed));

	//GameObjectFactory::CreateActor<WorkInProgressGUI>()->SetPosition(400,300);


	diffController = (DifficultyController*)GameObjectFactory::CreateActor<DifficultyController>();
	//OpenGLRenderer::GetRenderer()->RegisterOnReleaseKey(this, Key_Up, inputCallBack(&PlayerCar::Stop));
	//OpenGLRenderer::GetRenderer()->RegisterOnReleaseKey(this, Key_Down, inputCallBack(&PlayerCar::Stop));


	
	Timer* timer =(Timer*) GameObjectFactory::CreateActor<Timer>();

	timer->RegisterTimer(this, inputCallBack(&GameMain::TestTimer), 2.0);
	

}

void GameMain::IncreaseSpeed()
{

}

void GameMain::DecreaseSpeed()
{

}


void GameMain::TestTimer()
{
	std::cout << "TestTimer Activated " << std::endl;
}