#pragma once
#include "pch.h"
#include "BaseComponent.h"
#include "Texture2D.h"
#include "Shader.h"


class SpriteComponent :
	public BaseComponent
{
public:
	
	SpriteComponent(GLuint programObj);
	~SpriteComponent();

	bool Load(char* spritePath);
	void Render();
	void Release();

	void SetPosition(Vect2 _position);

private:

	GLuint programObject;
	GLuint vertexBuffer;
	GLuint indexBuffer;
	GLuint indexBufferSize;
	GLuint vertexBufferSize;
	GLuint texture2DObj;
	std::unique_ptr<Shader> vShader;
	std::unique_ptr<Shader> fShader;


};

