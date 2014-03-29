#pragma once
#include "pch.h"
#include "RenderableComponent.h"
#include "Texture2D.h"
#include "Shader.h"


class SpriteComponent :
	public RenderableComponent
{
public:
	
	SpriteComponent();
	~SpriteComponent();

	bool Load(char* spritePath);
	void Render();
	void Release() override;

	OpenGLKey GetKey() override;

private:
	GLuint texture2DObj;



};

