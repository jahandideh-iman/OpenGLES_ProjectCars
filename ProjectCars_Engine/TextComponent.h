#pragma once
#include "RenderableComponent.h"
#include "pch.h"

#include "ft2build.h"
#include FT_FREETYPE_H



class TextComponent :
	public RenderableComponent
{
public:
	TextComponent();

	bool Load();
	void Render() override;

	OpenGLKey GetKey() override;
	~TextComponent();

private:
	char* text;

	FT_Library freeTypeLibarary;

	FT_Face face;

	GLuint tex;

	
};

