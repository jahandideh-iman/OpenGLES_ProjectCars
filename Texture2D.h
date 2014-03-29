#pragma once

#include "pch.h"
#include "Utilities.h"

class Texture2D
{
public:
	Texture2D();
	~Texture2D();
	GLuint CreateTexture2D();
	GLuint LoadTexture(char* path);
	bool Load();
	void Release();

	Size GetSize();

private:
	GLuint vertexBuffer;
	GLuint indexBuffer;
	GLuint indexBufferSize;

	Size size;
};
