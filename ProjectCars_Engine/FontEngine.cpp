#include "FontEngine.h"
#include <cassert>


FontEngine::FontEngine()
{
	InitialFontContainer();
}


FontEngine::~FontEngine()
{
}

void FontEngine::InitialFontContainer()
{
	AddTextObject('A', "../Assets/EngineAssets/Fonts/A.tga");
	AddTextObject('B', "../Assets/EngineAssets/Fonts/B.tga");
	AddTextObject(' ', "../Assets/EngineAssets/Fonts/blank.tga");
	AddTextObject('S', "../Assets/EngineAssets/Fonts/S.tga");
	AddTextObject('c', "../Assets/EngineAssets/Fonts/c.tga");
	AddTextObject('o', "../Assets/EngineAssets/Fonts/o.tga");
	AddTextObject('r', "../Assets/EngineAssets/Fonts/r.tga");
	AddTextObject('e', "../Assets/EngineAssets/Fonts/e.tga");
	AddTextObject('0', "../Assets/EngineAssets/Fonts/0.tga");
	AddTextObject('1', "../Assets/EngineAssets/Fonts/1.tga");
	AddTextObject('2', "../Assets/EngineAssets/Fonts/2.tga");
	AddTextObject('3', "../Assets/EngineAssets/Fonts/3.tga");
	AddTextObject('4', "../Assets/EngineAssets/Fonts/4.tga");
	AddTextObject('5', "../Assets/EngineAssets/Fonts/5.tga");
	AddTextObject('6', "../Assets/EngineAssets/Fonts/6.tga");
	AddTextObject('7', "../Assets/EngineAssets/Fonts/7.tga");
	AddTextObject('8', "../Assets/EngineAssets/Fonts/8.tga");
	AddTextObject('9', "../Assets/EngineAssets/Fonts/9.tga");
}

TextObject* FontEngine::GetCharacterImage(char _char)
{
	assert(fontContainer.find(_char) != fontContainer.end());

	return fontContainer[_char];
}

void FontEngine::AddTextObject(char _char, char* _charImage)
{
	TextObject* textObj = (TextObject*)GameObjectFactory::CreateActor<TextObject>();

	SpriteComponent* sprite = (SpriteComponent*)GameObjectFactory::AddSpiteComponent(textObj, _charImage, 2000);
	sprite->SetOpaciyColor(0, 0, 0);
	sprite->SetTextureColor(0, 0, 0);
	textObj->SetPosition(Vect2(-600, 0));

	textObj->SetTextSprite(sprite);


	fontContainer[_char] = textObj;
}