#pragma once
#include "BaseCar.h"



typedef void (GameObject::* OnCollisionCallBack)(GameObject*);

#define  STRAFE_SPEED 400

typedef std::pair<GameObject*, OnCollisionCallBack> OnCollisionCallBackInfo;

class PlayerCar :
	public BaseCar
{
public:
	//PlayerCar();
	~PlayerCar();

	void GoLeft();
	void GoRight();


	void Update(float dt) override;
	void StopLeft();
	void StopRight();
	void OnCreation() override;
	void OnCollision(GameObject* object) override;
	void SetOnCollisionCallBack(GameObject* object, OnCollisionCallBack callBack);


private:
	OnCollisionCallBackInfo onCollisionCallBack;
	
	float xVelocity = 0;
	
};

