#include "BaseComponent.h"
#include <cassert>

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

void BaseComponent::Destroy()
{
	assert(destroyCallBack != nullptr);
	destroyCallBack(this);
	
}

void BaseComponent::OnDestroy()
{

}

void BaseComponent::SetDestroyCallBack(DestroyCallBack _destroyCallBack)
{
	destroyCallBack = _destroyCallBack;
}
