#include "CollisionComponent.h"


CollisionComponent::CollisionComponent(Rect _boundingRect)
{
	SetBoundingRect(_boundingRect);
}


CollisionComponent::~CollisionComponent()
{
}

void CollisionComponent::SetBoundingRect(Rect _boundingRect)
{
	boundingRect = _boundingRect;
}

Rect CollisionComponent::GetBoundingRect()
{
	return boundingRect;
}

void CollisionComponent::SetPosition(Vect2 _position)
{
	BaseComponent::SetPosition(_position);
	boundingRect.SetOrigin(_position.X, _position.Y);
}

void CollisionComponent::SetShowDebug(bool _bShow)
{
	bShowDebug = _bShow;
}