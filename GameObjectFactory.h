#pragma once

#include "GameObject.h"
#include "SpriteComponent.h"
#include "OpenGLRenderer.h"


class GameObjectFactory
{
public:
	GameObjectFactory();
	~GameObjectFactory();

	template<class ActorClass>
	static GameObject* CreateActor()
	{
		GameObject* obj = (GameObject*) new ActorClass;

		OpenGLRenderer::GetRenderer()->AddGameObject(obj);

		obj->OnCreation();
		return obj;
	}

	static void AddSpiteComponent(GameObject* owner, char* spritePath);

	static void AddCollisionComponent(GameObject* owner, Rect collisionRec);

private:
	


};

