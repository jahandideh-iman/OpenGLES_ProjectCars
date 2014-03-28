#pragma once

#include "pch.h"
#include "BaseComponent.h"
#include "Utilities.h"

class GameObjectFactory;

enum EPhysicsType
{
	Phys_None, Phys_Static, Phys_Dynamic
};

typedef std::vector<BaseComponent*> Components;
class GameObject
{
	friend GameObjectFactory;
public:
	
	virtual ~GameObject();
	
	virtual void Update(float dt);
	virtual void OnCreation();
	virtual void OnCollision(GameObject* other);

	void SetPosition(Vect2 _position);
	void SetPosition(int xPos, int yPos);
	Vect2 GetPosition();

	void SetVelocity(Vect2 _velocity);
	void SetVelocity(int xVel, int yVel);
	Vect2 GetVelocity();

	void SetPhysicsType(EPhysicsType type);
	EPhysicsType GetPhysicsType();


protected:
	GameObject();

	void ProcessMove(float dt);
private:
	void AddComponent(BaseComponent* comp);

	
	
private:
	Components componets;

	Vect2 velocity;
	Vect2 position;

	EPhysicsType physicsType = Phys_Static;

	
};

