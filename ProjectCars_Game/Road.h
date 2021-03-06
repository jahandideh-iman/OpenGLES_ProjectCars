#pragma once
#include "GameObject.h"
#include "SpriteComponent.h"

#define ACCEL_UP 100
#define ACCEL_DOWN -500

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

	void SpeedDown();
	void ReleaseSpeedDown();

	float GetSpeed();

	void Reset();


	
private:
	void SetSpeed(float _speed);

	void CalculateSpeed(float dt);
	void CalculateAccel();

private:

	bool bIsSpeedingUp = false;
	bool bIsSpeedingDown = false;
	SpriteComponent* spriteComp;

	float currentSpeed;
	float desiredSpeed;
	float currentAccel = 0;
};

