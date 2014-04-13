#pragma once
#include "RenderableComponent.h"
#include "pch.h"
#include "TextObject.h"
#include "GameObjectFactory.h"

#define CHAR_WIDTH 16

typedef std::vector<TextObject*> TextObjects;

class TextComponent_BullShit :
	public RenderableComponent
{

public:
	TextComponent_BullShit();
	~TextComponent_BullShit();

	void SetText(char* _text);


	void SetPosition(Vect2 _pos) override;
	void Render() override;



private:

	char* text = " ";
};

