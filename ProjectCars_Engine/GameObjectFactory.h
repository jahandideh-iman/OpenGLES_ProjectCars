#pragma once

#include "GameObject.h"
#include "SpriteComponent.h"
#include "DebugRectangleComponent.h"
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

	static void AddSpiteComponent(GameObject* owner, char* spritePath, int zOder = 0);
	static void AddDebugRectangleComponent(GameObject* owner, Rect rec);

	static void AddCollisionComponent(GameObject* owner, Rect collisionRec, EPhysicsType physType);

private:
	


};

