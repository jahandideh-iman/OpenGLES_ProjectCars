#pragma once
#include "pch.h"
#include "RenderableComponent.h"
#include "Texture2D.h"
#include "Shader.h"


class SpriteComponent :
	public RenderableComponent
{
public:
	
	SpriteComponent(GLuint programObj);
	~SpriteComponent();

	bool Load(char* spritePath);
	void Render();
	void Release() override;

private:
	GLuint texture2DObj;



};

