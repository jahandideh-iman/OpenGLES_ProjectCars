#pragma once
#include "pch.h"
#include "BaseComponent.h"
#include "Texture2D.h"
#include "Shader.h"


class RenderableComponent :
	public BaseComponent
{
public:

	RenderableComponent(GLuint programObj);
	~RenderableComponent();

	virtual void Render()=0;
	virtual void Release();


protected:

	GLuint programObject;
	GLuint vertexBuffer;
	GLuint indexBuffer;
	GLuint indexBufferSize;
	GLuint vertexBufferSize;
	
	std::unique_ptr<Shader> vShader;
	std::unique_ptr<Shader> fShader;


};

