#pragma once

#include <unordered_map>
#include "TextObject.h"
#include "GameObjectFactory.h"
#include "SpriteComponent.h"

#include "pch.h"

typedef std::unordered_map<char, TextObject*> FontContainer;
class FontEngine 
{
public:
	FontEngine();
	~FontEngine();
	TextObject* GetCharacterImage(char key);

	void AddTextObject(char _char, char* _charImage);

private:
	void InitialFontContainer();
private:

	FontContainer fontContainer;


};

