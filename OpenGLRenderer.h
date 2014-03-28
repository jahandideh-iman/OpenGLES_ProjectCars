#pragma once

#include "pch.h"
#include "SpriteComponent.h"
#include "GameObject.h"
#include "CollisionComponent.h"
#include "WindowsInputHandler.h"
#include "Utilities.h"


typedef std::vector<GameObject*> GameObjects;
typedef std::vector<SpriteComponent*> SpriteComponents;
typedef std::vector<CollisionComponent*> CollisionComponents;

class OpenGLRenderer
{
public:
	OpenGLRenderer();
	~OpenGLRenderer();
	void Start();

	void Render(ESContext* context);
	void Update(ESContext* context, float dt);
	void HandleInput(ESContext* context, unsigned char key, int X, int Y);

	static GLuint GetProgramObject();
	static OpenGLRenderer* GetRenderer();

	void AddGameObject(GameObject* obj);

	void AddSpriteComponent(SpriteComponent* sprite);
	void AddCollisionComponent(CollisionComponent* collision);

	void RegisterOnPressKey(GameObject* _obj, EInputKey _key, inputCallBack _callBack);
	void RegisterOnReleaseKey(GameObject* _obj, EInputKey _key, inputCallBack _callBack);

	Size GetWindowSize();

	
private:
	void Initialize();

	void InitializeContext(ESContext * context);
	GLuint LoadShader(GLenum type, const char* shaderSrc);

	void Release();

private:

	static OpenGLRenderer * renderer;
	ESContext* esContext;
	static GLuint programObject;

	SpriteComponents spriteComponents;
	CollisionComponents collisionComponents;

	GameObjects gameObjects;

	WindowsInputHandler* inputHandler;



};

