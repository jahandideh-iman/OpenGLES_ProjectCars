#pragma once
#include "BaseComponent.h"
#include "Utilities.h"

class CollisionComponent :
	public BaseComponent
{
public:
	~CollisionComponent();

private:
	Rect boundingBox;
};

