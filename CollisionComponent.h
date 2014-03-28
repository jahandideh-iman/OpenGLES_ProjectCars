#pragma once
#include "BaseComponent.h"
#include "BaseComponent.h"
#include "Utilities.h"

class CollisionComponent :
	public BaseComponent
{
public:
	~CollisionComponent();
	CollisionComponent(Rect _boundingRect);

	void SetBoundingRect(Rect _boundingRect);
	Rect GetBoundingRect();

	void SetShowDebug(bool _bShow);

	void SetPosition(Vect2 _position);
private:
	Rect boundingRect;

	bool bShowDebug;
};

