#pragma once
#include "GameObject.h"
#include "SpriteComponent.h"

class Road :
	public GameObject
{
public:
	Road();
	~Road();
	void OnCreation() override;

	void Update(float dt) override;

	void SetSpeed(int _speed);

private:
	SpriteComponent* spriteComp;

	int speed = 0;
};

