#include "TextObject.h"


TextObject::TextObject()
{
}


TextObject::~TextObject()
{
}


void TextObject::SetTextSprite(SpriteComponent* _textSprite)
{
	textSprite = _textSprite;
}

SpriteComponent* TextObject::GetTextSprite()
{
	return textSprite;
}