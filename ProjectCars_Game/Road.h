#pragma once
#include "GameObject.h"
#include "SpriteComponent.h"

#define ACCEL_UP 100
#define ACCEL_DOWN -200

#define NORMAL_SPEED 400.0
#define MIN_SPEED 200.0
#define MAX_SPEED 1000.0

class Road :
	public GameObject
{
public:
	Road();
	~Road();
	void OnCreation() override;

	void Update(float dt) override;

	void IncreaseSpeed();
	void DecreaseSpeed();


	
private:
	void SetSpeed(int _speed);

	void CalculateSpeed(float dt);

private:
	SpriteComponent* spriteComp;

	int speed = 10;
	float currentAccel = 0;
	float desiredAccel;
};

