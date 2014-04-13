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
	fontContainer['A'] = "../Assets/EngineAssets/Fonts/A.tga";
	fontContainer['B'] = "../Assets/EngineAssets/Fonts/B.tga";
}

char* FontEngine::GetCharacterImage(char _char)
{
	assert(fontContainer.find(_char) != fontContainer.end());

	return fontContainer[_char];
}
