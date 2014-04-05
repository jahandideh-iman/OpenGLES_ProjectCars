#pragma once

#include "pch.h"
#include "Utilities.h"

class GameObject;
class GameObjectFactory;


class BaseComponent
{
	friend GameObjectFactory;
public:
	
	virtual ~BaseComponent();

	void SetOwner(GameObject* _owner);
	GameObject* GetOwner();

	virtual void SetPosition(Vect2 _position);

	Vect2 GetPosition();

	virtual void Destroy();

protected: 
	BaseComponent();

private:
	GameObject* owner;

	Vect2 position;

};




