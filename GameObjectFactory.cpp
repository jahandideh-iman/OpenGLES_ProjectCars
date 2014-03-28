#include "GameObjectFactory.h"



GameObjectFactory::GameObjectFactory()
{
}


GameObjectFactory::~GameObjectFactory()
{
}

void GameObjectFactory::AddSpiteComponent(GameObject* owner, char* spritePath)
{
	SpriteComponent* sprite = new SpriteComponent(OpenGLRenderer::GetProgramObject());
	sprite->Load(spritePath);
	sprite->SetOwner(owner);
	owner->AddComponent(sprite);

	sprite->SetPosition(owner->GetPosition());

	OpenGLRenderer::GetRenderer()->AddRenderableComponent(sprite);
}

void GameObjectFactory::AddDebugRectangleComponent(GameObject* owner, Rect rec)
{
	DebugRectangleComponent* rectangle = new DebugRectangleComponent(OpenGLRenderer::GetProgramObject(),rec);
	rectangle->Load(rec.GetSize());
	rectangle->SetOwner(owner);
	owner->AddComponent(rectangle);

	rectangle->SetPosition(owner->GetPosition());

	OpenGLRenderer::GetRenderer()->AddRenderableComponent(rectangle);
}

void GameObjectFactory::AddCollisionComponent(GameObject* owner, Rect collisionRec)
{
	CollisionComponent* col = new CollisionComponent(collisionRec);
	col->SetOwner(owner);
	owner->AddComponent(col);

	col->SetPosition(owner->GetPosition());

	OpenGLRenderer::GetRenderer()->AddCollisionComponent(col);
}