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

	OpenGLRenderer::GetRenderer()->AddRenderableComponent(rectangle);
}

void GameObjectFactory::AddCollisionComponent(GameObject* owner, Rect collisionRec, EPhysicsType physType)
{
	CollisionComponent* col = new CollisionComponent(collisionRec, physType);
	col->SetOwner(owner);
	owner->AddComponent(col);

	col->SetPosition(owner->GetPosition());

	OpenGLRenderer::GetRenderer()->AddCollisionComponent(col);
}

TextComponent* GameObjectFactory::AddTextComponent(GameObject* owner, char* text, int zOrder)
{
	TextComponent* textComp = new TextComponent();

	textComp->Load();

	textComp->SetOwner(owner);
	owner->AddComponent(textComp);

	textComp->SetPosition(owner->GetPosition());

	OpenGLRenderer::GetRenderer()->AddRenderableComponent(textComp);

	return textComp;
}