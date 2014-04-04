#include "BaseComponent.h"

BaseComponent::BaseComponent()
{
}


BaseComponent::~BaseComponent()
{
}

void BaseComponent::SetOwner(GameObject* _owner)
{
	owner = _owner;
}

GameObject* BaseComponent::GetOwner()
{
	return owner;
}

void BaseComponent::SetPosition(Vect2 _position)
{
	position = _position;
}

Vect2 BaseComponent::GetPosition()
{
	return position;
}

