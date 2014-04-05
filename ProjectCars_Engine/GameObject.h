#pragma once

#include "pch.h"
#include "BaseComponent.h"
#include "Utilities.h"

class GameObjectFactory;


typedef void (GameObject::* inputCallBack)();

typedef std::pair<GameObject*, inputCallBack> CallBackInfo;

typedef std::vector<BaseComponent*> Components;

typedef void(*DestroyCallBack)(GameObject*);

class GameObject
{
	friend GameObjectFactory;
public:
	
	virtual ~GameObject();
	
	virtual void Update(float dt);
	virtual void OnCreation();
	virtual void OnCollision(GameObject* other);

	virtual void Destroy();

	void SetPosition(Vect2 _position);
	void SetPosition(int xPos, int yPos);
	Vect2 GetPosition();

	void SetVelocity(Vect2 _velocity);
	void SetVelocity(int xVel, int yVel);
	Vect2 GetVelocity();

	
	void SetStaticFlag(bool _bIsStatic);
	bool IsStatic();

protected:
	GameObject();

	void ProcessMove(float dt);
private:
	void AddComponent(BaseComponent* comp);

	void SetDestroyCallBack(DestroyCallBack _destroyCallBack);

	
	
private:
	Components componets;

	Vect2 velocity;
	Vect2 position;

	bool bIsStatic= false;

	DestroyCallBack destroyCallBack = nullptr;

	
};

