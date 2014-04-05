#pragma once
#include "BaseCar.h"
class AICar :
	public BaseCar
{
public:
	AICar();
	~AICar();
	void Update(float dt) override;
	void OnCreation() override;

private:
	void CheckOutOfScreen();
};

