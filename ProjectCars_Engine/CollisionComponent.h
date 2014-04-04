#pragma once
#include "BaseComponent.h"

#include "Utilities.h"

enum EPhysicsType
{
	Phys_None, Phys_Blocking, Phys_Colliding
};

class CollisionComponent :
	public BaseComponent
{
public:
	~CollisionComponent();
	CollisionComponent(Rect _boundingRect, EPhysicsType physType);

	void SetBoundingRect(Rect _boundingRect);
	Rect GetBoundingRect();

	void SetShowDebug(bool _bShow);

	void SetPosition(Vect2 _position);

	void SetPhysicsType(EPhysicsType type);
	EPhysicsType GetPhysicsType();

private:
	Rect boundingRect;

	EPhysicsType physicsType = Phys_None;


};

