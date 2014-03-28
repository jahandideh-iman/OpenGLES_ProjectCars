#include "RenderableComponent.h"


using namespace std;

RenderableComponent::RenderableComponent(GLuint programObj)
{
	programObject = programObj;
	this->vertexBuffer = 0;
	this->indexBuffer = 0;
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
