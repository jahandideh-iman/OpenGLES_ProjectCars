#include "GameObject.h"


GameObject::GameObject()
{
	SetPosition(0, 0);
	SetVelocity(0, 0);
}

void GameObject::OnCreation()
{
	
}

void GameObject::OnCollision(GameObject* other)
{

}

void GameObject::Update(float dt)
{
	ProcessMove(dt);
}

void GameObject::ProcessMove(float dt)
{
	if (IsStatic())
		return;
	SetPosition(GetPosition() + (GetVelocity()* dt));
}

void GameObject::SetPosition(Vect2 _position)
{
	position = _position;

	for (int i = 0; i < componets.size(); ++i)
		componets[i]->SetPosition(_position);
}

void GameObject::SetPosition(int xPos, int yPos)
{
	SetPosition(Vect2(xPos, yPos));
}

Vect2 GameObject::GetPosition()
{
	return position;
}

void GameObject::SetVelocity(Vect2 _velocity)
{
	velocity = _velocity;
}

void GameObject::SetVelocity(int xVel, int yVel)
{

	SetVelocity(Vect2(xVel, yVel));
}

Vect2 GameObject::GetVelocity()
{
	return velocity;
}

GameObject::~GameObject()
{
}

void GameObject::AddComponent(BaseComponent * comp)
{
	componets.push_back(comp);
}


void GameObject::SetStaticFlag(bool _bIsStatic)
{
	bIsStatic = _bIsStatic;
}

bool GameObject::IsStatic()
{
	return bIsStatic;
}