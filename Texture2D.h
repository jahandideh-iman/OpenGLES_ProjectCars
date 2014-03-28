#pragma once

#include "pch.h"

class Texture2D
{
public:
	Texture2D();
	~Texture2D();
	GLuint CreateTexture2D();
	GLuint LoadTexture(char* path);
	bool Load();
	void Release();

private:
	GLuint vertexBuffer;
	GLuint indexBuffer;
	GLuint indexBufferSize;
};
