#pragma once
#include "BaseCar.h"




class PlayerCar :
	public BaseCar
{
public:
	//PlayerCar();
	~PlayerCar();

	void GoLeft();
	void GoRight();

	void GoUp();
	void GoDown();

	void Stop();
	void OnCreation() override;


private:

	

	
};

