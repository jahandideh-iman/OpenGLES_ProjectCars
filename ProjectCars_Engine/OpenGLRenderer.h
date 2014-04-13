#pragma once

#include "pch.h"
#include "RenderableComponent.h"
#include "GameObject.h"
#include "CollisionComponent.h"
#include "WindowsInputHandler.h"
#include "FontEngine.h"

#include "Utilities.h"


class TextObject;
class FontEngine;

typedef std::vector<GameObject*> GameObjects;
typedef std::vector<RenderableComponent*> RenderableComponents;
typedef std::vector<CollisionComponent*> CollisionComponents;

class OpenGLRenderer
{
public:
	OpenGLRenderer();
	~OpenGLRenderer();
	void Start();

	void Render(ESContext* context);
	void Update(ESContext* context, float dt);

	static OpenGLRenderer* GetRenderer();

	void AddGameObject(GameObject* obj);
	void RemoveGameObject(GameObject* obj);

	void AddRenderableComponent(RenderableComponent* renderable);
	void AddCollisionComponent(CollisionComponent* collision);
	void RemoveComponent(BaseComponent * comp);

	void RegisterOnPressKey(GameObject* _obj, EInputKey _key, inputCallBack _callBack);
	void RegisterOnReleaseKey(GameObject* _obj, EInputKey _key, inputCallBack _callBack);

	Size GetWindowSize();

	TextObject* GetCharacterImage(char key);

	
private:
	void Initialize();

	void InitializeContext(ESContext * context);
	GLuint LoadShader(GLenum type, const char* shaderSrc);

	void CheckCollisions();
	void CheckCollision(CollisionComponent* col1, CollisionComponent* col2);
	void ResolveCollision(CollisionComponent* col1, CollisionComponent* col2, CollisionInfo &colInfo);

	void AddRenderableComponentWithLinearInsertion(RenderableComponent* renderable);

	void RemoveRenderableComponent(RenderableComponent* comp);
	void RemoveCollisionComponent(CollisionComponent* comp);

	void Release();

private:

	static OpenGLRenderer * renderer;
	ESContext* esContext;

	RenderableComponents renderableComponents;
	CollisionComponents collisionComponents;
	GameObjects gameObjects;

	WindowsInputHandler* inputHandler;

	FontEngine * fontEngine;
};

