#pragma once
#include "BaseCar.h"



typedef void (GameObject::* OnCollisionCallBack)(GameObject*);

typedef std::pair<GameObject*, OnCollisionCallBack> OnCollisionCallBackInfo;

class PlayerCar :
	public BaseCar
{
public:
	//PlayerCar();
	~PlayerCar();

	void GoLeft();
	void GoRight();



	void Stop();
	void OnCreation() override;
	void OnCollision(GameObject* object) override;
	void SetOnCollisionCallBack(GameObject* object, OnCollisionCallBack callBack);


private:
	OnCollisionCallBackInfo onCollisionCallBack;
	

	
};

