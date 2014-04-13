#include "GameObjectFactory.h"



GameObjectFactory::GameObjectFactory()
{
}


GameObjectFactory::~GameObjectFactory()
{
}

SpriteComponent* GameObjectFactory::AddSpiteComponent(GameObject* owner, char* spritePath , int zOrder)
{
	SpriteComponent* sprite = new SpriteComponent();
	sprite->Load(spritePath);
	sprite->SetOwner(owner);
	sprite->SetZOrder(zOrder);
	owner->AddComponent(sprite);

	sprite->SetPosition(owner->GetPosition());
	sprite->SetDestroyCallBack(GameObjectFactory::DestoryComponent);

	OpenGLRenderer::GetRenderer()->AddRenderableComponent(sprite);
	return sprite;
}

void GameObjectFactory::AddDebugRectangleComponent(GameObject* owner, Rect rec)
{
	DebugRectangleComponent* rectangle = new DebugRectangleComponent(rec);
	rectangle->Load(rec.GetSize());
	rectangle->SetOwner(owner);
	owner->AddComponent(rectangle);

	rectangle->SetPosition(owner->GetPosition());
	rectangle->SetDestroyCallBack(GameObjectFactory::DestoryComponent);

	OpenGLRenderer::GetRenderer()->AddRenderableComponent(rectangle);
}

void GameObjectFactory::AddCollisionComponent(GameObject* owner, Rect collisionRec, EPhysicsType physType)
{
	CollisionComponent* col = new CollisionComponent(collisionRec, physType);
	col->SetOwner(owner);
	owner->AddComponent(col);

	col->SetPosition(owner->GetPosition());
	col->SetDestroyCallBack(GameObjectFactory::DestoryComponent);


	OpenGLRenderer::GetRenderer()->AddCollisionComponent(col);
}

TextComponent_BullShit* GameObjectFactory::AddTextComponent(GameObject* owner, char* text, int zOrder)
{
	TextComponent_BullShit* textComp = new TextComponent_BullShit();

	textComp->SetText(text);

	textComp->SetOwner(owner);
	owner->AddComponent(textComp);

	textComp->SetPosition(owner->GetPosition());
	textComp->SetDestroyCallBack(GameObjectFactory::DestoryComponent);


	OpenGLRenderer::GetRenderer()->AddRenderableComponent(textComp);

	return textComp;
}

void GameObjectFactory::DestroyActor(GameObject* actor)
{
	OpenGLRenderer::GetRenderer()->RemoveGameObject(actor);
	actor->OnDestroy();

	delete actor;

}

void GameObjectFactory::DestoryComponent(BaseComponent* comp)
{
	OpenGLRenderer::GetRenderer()->RemoveComponent(comp);
	GameObject * owner = comp->GetOwner();

	owner->RemoveComponent(comp);

	comp->OnDestroy();
	delete comp;
	comp = nullptr;
}
