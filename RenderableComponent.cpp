#include "RenderableComponent.h"


using namespace std;

ProgramObjectMap RenderableComponent::programObjectMap;

RenderableComponent::RenderableComponent()
{
	this->vertexBuffer = 0;
	this->indexBuffer = 0;


	ProgramObjectMap::iterator it= programObjectMap.find(GetKey());
	if (it == programObjectMap.end())
		programObject = CreateProgramObject();
	else
		programObject = (*it).second;

	this->vShader = unique_ptr<Shader>(new Shader(programObject));
	this->fShader = unique_ptr<Shader>(new Shader(programObject));
}


RenderableComponent::~RenderableComponent()
{
}

void RenderableComponent::Release()
{
	this->vShader->Release();
	this->fShader->Release();
	glDeleteBuffers(1, &this->vertexBuffer);
	glDeleteBuffers(1, &this->indexBuffer);
}



GLuint RenderableComponent::CreateProgramObject()
{
	GLuint programObject = glCreateProgram();
	if (!programObject)
	{
		cout << "Could not load program object";
		Release();
		std::exit(0);
	}

	return programObject;
}

OpenGLKey RenderableComponent::GetKey()
{
	return "OpenGL_None";
}