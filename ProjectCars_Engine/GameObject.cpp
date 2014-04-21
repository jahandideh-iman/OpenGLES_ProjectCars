#include "GameObject.h"
#include <cassert>


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

void GameObject::Destroy()
{
	assert(destroyCallBack != nullptr);
	destroyCallBack(this);
	
}

void GameObject::DestroyForReal()
{
	while (!componets.empty())
		componets[0]->Destroy();
	OnDestroy();
}

void GameObject::OnDestroy()
{
	std::cout << "OnDestroy" << std::endl;
}

void GameObject::SetDestroyCallBack(DestroyCallBack _destroyCallBack)
{
	destroyCallBack = _destroyCallBack;
}

void GameObject::ProcessMove(float dt)
{
	if (IsStatic())
		return;
	SetPosition(GetPosition() + (GetVelocity()* dt));
}

void GameObject::SetPosition(Vect2 _position)
{

	Vect2 offset = _position - position;
	position = _position;

	for (int i = 0; i < componets.size(); ++i)
		componets[i]->SetPosition(componets[i]->GetPosition() + offset);
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

void GameObject::RemoveComponent(BaseComponent* comp)
{
	int index = -1; 
	for (int i = 0; i < componets.size(); ++i)
	{
		if (componets[i] == comp)
		{
			index = i;
			break;
		}
	}

	if (index == -1)
		return;
	componets.erase(componets.begin() + index);
}


void GameObject::SetStaticFlag(bool _bIsStatic)
{
	bIsStatic = _bIsStatic;
}

bool GameObject::IsStatic()
{
	return bIsStatic;
}
