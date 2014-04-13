#pragma once
#include "GameObject.h"

class SpriteComponent;
class TextObject :
	public GameObject
{
public:
	TextObject();
	~TextObject();

	void SetTextSprite(SpriteComponent* _testSprite);
	SpriteComponent* GetTextSprite();

private:
	SpriteComponent* textSprite = nullptr;
};

