#pragma once
#include "RenderableComponent.h"
#include "pch.h"
#include "TextObject.h"
#include "GameObjectFactory.h"

typedef std::vector<TextObject*> TextObjects;

class TextComponent_BullShit :
	public RenderableComponent
{
public:
	TextComponent_BullShit();
	~TextComponent_BullShit();

	void SetText(char* _text);

	void AddTextObject(char _char, char* _charImage);

	void SetPosition(Vect2 _pos) override;
	void Render() override;

private:
	void RemoveTextObjects();

private:
	TextObjects textObjects;
};

