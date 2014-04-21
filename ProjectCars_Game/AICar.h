#pragma once
#include "BaseCar.h"
#include "Road.h"
#include <vector>

class AICar;

typedef void (GameObject::* OnDestoryCallBack)(AICar* );

typedef std::pair<GameObject*, OnDestoryCallBack> OnDestoryCallBackInfo;

class AICar :
	public BaseCar
{
public:
	AICar();
	~AICar();
	void Update(float dt) override;
	void OnCreation() override;
	void SetBaseSpeed(float _baseSpeed);

	void SetOnDestoryCallBack(GameObject* object, OnDestoryCallBack callBack);

	static void InitialCarSprites();

public:
	static Road* road;
	
protected:
	void OnDestroy() override;

private:
	void CheckOutOfScreen();
	
	static std::vector<char*> carSprites;

private:
	float baseSpeed = 0;

	OnDestoryCallBackInfo onDestroyCallBack;
};


