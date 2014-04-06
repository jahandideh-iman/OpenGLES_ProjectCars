#pragma once

#include "pch.h"
#include "Utilities.h"

class GameObject;
class GameObjectFactory;


class BaseComponent
{
	typedef void(*DestroyCallBack)(BaseComponent*);

	friend GameObjectFactory;
public:
	
	virtual ~BaseComponent();

	void SetOwner(GameObject* _owner);
	GameObject* GetOwner();

	virtual void SetPosition(Vect2 _position);

	Vect2 GetPosition();

	virtual void Destroy();
	virtual void OnDestroy();

	void SetDestroyCallBack(DestroyCallBack _destroyCallBack);


protected: 
	BaseComponent();

private:
	GameObject* owner;

	Vect2 position;

	DestroyCallBack destroyCallBack = nullptr;

};




