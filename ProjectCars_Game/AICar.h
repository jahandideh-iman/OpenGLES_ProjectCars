#pragma once
#include "BaseCar.h"
#include "Road.h"
#include <vector>






class AICar :
	public BaseCar
{
public:
	AICar();
	~AICar();
	void Update(float dt) override;
	void OnCreation() override;

	static void InitialCarSprites();

public:
	static Road* road;
	void SetBaseSpeed(float _baseSpeed);
private:
	void CheckOutOfScreen();
	
	static std::vector<char*> carSprites;

private:
	float baseSpeed = 0;
};


