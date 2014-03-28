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

	OpenGLRenderer::GetRenderer()->AddSpriteComponent(sprite);
}

void GameObjectFactory::AddCollisionComponent(GameObject* owner, Rect collisionRec)
{
	CollisionComponent* col = new CollisionComponent();
	col->SetOwner(owner);
	owner->AddComponent(col);

	col->SetPosition(owner->GetPosition());

	OpenGLRenderer::GetRenderer()->AddCollisionComponent(col);
}