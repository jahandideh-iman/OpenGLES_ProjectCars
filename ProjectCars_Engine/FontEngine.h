#pragma once

#include <unordered_map>

#include "pch.h"

typedef std::unordered_map<char, char *> FontContainer;
class FontEngine 
{
public:
	FontEngine();
	~FontEngine();
	char* GetCharacterImage(char key);

private:
	void InitialFontContainer();
private:

	FontContainer fontContainer;


};

