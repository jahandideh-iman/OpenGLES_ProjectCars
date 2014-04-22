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
	//GameObjectFactory::AddDebugRectangleComponent(this, Rect(64, 160));

	OpenGLRenderer::GetRenderer()->RegisterOnPressKey(this,Key_Left, CallBack(&PlayerCar::GoLeft));
	OpenGLRenderer::GetRenderer()->RegisterOnPressKey(this,Key_Right, CallBack(&PlayerCar::GoRight));

	OpenGLRenderer::GetRenderer()->RegisterOnReleaseKey(this, Key_Right, CallBack(&PlayerCar::StopRight));
	OpenGLRenderer::GetRenderer()->RegisterOnReleaseKey(this, Key_Left, CallBack(&PlayerCar::StopLeft));
}


void PlayerCar::GoLeft()
{
	xVelocity -= STRAFE_SPEED;
	//std::cout << "Going Left"<<std::endl;
}

void PlayerCar::StopLeft()
{
	xVelocity += STRAFE_SPEED;
}

void PlayerCar::GoRight()
{
	xVelocity += STRAFE_SPEED;
	//std::cout << "Going Right"<<std::endl;
}

void PlayerCar::StopRight()
{
	xVelocity -= STRAFE_SPEED;
}

void PlayerCar::OnCollision(GameObject* object)
{
	CALL_MEMBER_FN(onCollisionCallBack.first, onCollisionCallBack.second)(object);
}

void PlayerCar::Update(float dt)
{
	BaseCar::Update(dt);
	SetVelocity(xVelocity, 0);
}


void PlayerCar::SetOnCollisionCallBack(GameObject* object, OnCollisionCallBack callBack)
{
	onCollisionCallBack.first = object;
	onCollisionCallBack.second = callBack;
}
