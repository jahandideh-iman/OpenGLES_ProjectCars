#pragma once

#include "GameObject.h"
#include "SpriteComponent.h"
#include "DebugRectangleComponent.h"
#include "OpenGLRenderer.h"
#include "TextComponent.h"
#include "TextComponent_BullShit.h"


class TextComponent_BullShit;


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
		obj->SetDestroyCallBack(GameObjectFactory::DestroyActor);
		obj->OnCreation();
		return obj;
	}


	static SpriteComponent* AddSpiteComponent(GameObject* owner, char* spritePath, int zOrder = 0);
	static void AddDebugRectangleComponent(GameObject* owner, Rect rec);

	static void AddCollisionComponent(GameObject* owner, Rect collisionRec, EPhysicsType physType);

	static TextComponent_BullShit* AddTextComponent(GameObject* owner, char * text, int zOrder = 0);

	static void DestroyActor(GameObject* actor);
	static void DestoryComponent(BaseComponent* component);
	static bool IsStoredInEngine(BaseComponent* comp);

private:
	


};

