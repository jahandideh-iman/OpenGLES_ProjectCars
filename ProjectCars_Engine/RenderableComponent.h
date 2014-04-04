#pragma once
#include "pch.h"
#include "BaseComponent.h"
#include "Texture2D.h"
#include "Shader.h"
#include <unordered_map>


typedef std::string OpenGLKey;

typedef std::unordered_map<OpenGLKey, GLuint> ProgramObjectMap;

class RenderableComponent :
	public BaseComponent
{

public:
	static ProgramObjectMap programObjectMap;
public:

	RenderableComponent();
	~RenderableComponent();

	virtual void Render()=0;
	virtual void Release();

	virtual OpenGLKey GetKey();

	int GetZOrder();
	void SetZOrder(int _zOrder);


protected:

	GLuint CreateProgramObject();

protected:

	GLuint programObject;
	GLuint vertexBuffer;
	GLuint indexBuffer;
	GLuint indexBufferSize;
	GLuint vertexBufferSize;
	
	std::unique_ptr<Shader> vShader;
	std::unique_ptr<Shader> fShader;

private:
	int zOrder = 0;


};

