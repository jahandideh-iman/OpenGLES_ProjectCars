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

	void AddTexCoord(float xPixel, float yPixel);
	void SetOpaciyColor(float R, float G, float B);
	void SetTextureColor(float R, float G, float B);

	OpenGLKey GetKey() override;

private:
	GLuint texture2DObj;

	std::unique_ptr<Texture2D> texture2D;

	GLfloat texCoord[2] ;

	GLfloat opacityColor[4];

	GLfloat texColor[4];



};

