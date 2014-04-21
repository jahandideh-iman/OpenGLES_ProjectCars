#include "PlayerCar.h"
#include "GameObjectFactory.h"
#include "OpenGLRenderer.h"




PlayerCar::~PlayerCar() 
{
	
}

void PlayerCar::OnCreation()
{
	SetStaticFlag(false);
	GameObjectFactory::AddSpiteComponent(this, "../Assets/GameAssets/Car2.tga", 30)->SetOpaciyColor(1, 1, 1);
	GameObjectFactory::AddCollisionComponent(this, Rect(64, 160),Phys_Blocking);
	GameObjectFactory::AddDebugRectangleComponent(this, Rect(64, 160));

	OpenGLRenderer::GetRenderer()->RegisterOnPressKey(this,Key_Left, CallBack(&PlayerCar::GoLeft));
	OpenGLRenderer::GetRenderer()->RegisterOnPressKey(this,Key_Right, CallBack(&PlayerCar::GoRight));

	OpenGLRenderer::GetRenderer()->RegisterOnReleaseKey(this, Key_Right, CallBack(&PlayerCar::Stop));
	OpenGLRenderer::GetRenderer()->RegisterOnReleaseKey(this, Key_Left, CallBack(&PlayerCar::Stop));
}


void PlayerCar::GoLeft()
{
	SetVelocity(-400, 0);
	//std::cout << "Going Left"<<std::endl;
}

void PlayerCar::GoRight()
{
	SetVelocity(400, 0);
	//std::cout << "Going Right"<<std::endl;
}

void PlayerCar::OnCollision(GameObject* object)
{
	CALL_MEMBER_FN(onCollisionCallBack.first, onCollisionCallBack.second)(object);
}


void PlayerCar::Stop()
{
	SetVelocity(0,0);
}

void PlayerCar::SetOnCollisionCallBack(GameObject* object, OnCollisionCallBack callBack)
{
	onCollisionCallBack.first = object;
	onCollisionCallBack.second = callBack;
}
