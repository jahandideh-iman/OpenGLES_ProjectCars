#include "PlayerCar.h"
#include "GameObjectFactory.h"
#include "OpenGLRenderer.h"


PlayerCar::PlayerCar()
{
}


PlayerCar::~PlayerCar()
{
}

void PlayerCar::OnCreation()
{
	GameObjectFactory::AddSpiteComponent(this, "Assets/CPP.tga");

	OpenGLRenderer::GetRenderer()->RegisterOnPressKey(this,Key_Left, inputCallBack(&PlayerCar::GoLeft));
	OpenGLRenderer::GetRenderer()->RegisterOnPressKey(this,Key_Right, inputCallBack(&PlayerCar::GoRight));

	OpenGLRenderer::GetRenderer()->RegisterOnReleaseKey(this, Key_Right, inputCallBack(&PlayerCar::Stop));
	OpenGLRenderer::GetRenderer()->RegisterOnReleaseKey(this, Key_Left, inputCallBack(&PlayerCar::Stop));


}

void PlayerCar::GoLeft()
{
	SetVelocity(-400, 0);
	std::cout << "Going Left"<<std::endl;
}

void PlayerCar::GoRight()
{
	std::cout << "Going Right"<<std::endl;
}

void PlayerCar::Stop()
{
	SetVelocity(0,0);
}