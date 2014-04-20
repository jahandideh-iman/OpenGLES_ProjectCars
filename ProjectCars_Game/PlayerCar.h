#pragma once
#include "BaseCar.h"

typedef


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
	void SetOnCollisionCallBack(GameObject* object, CallBack callBack);


private:
	CallBackInfo onCollisionCallBack;
	

	
};

