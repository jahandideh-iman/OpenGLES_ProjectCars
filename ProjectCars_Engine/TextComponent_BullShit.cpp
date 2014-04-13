#include "TextComponent_BullShit.h"


TextComponent_BullShit::TextComponent_BullShit()
{
}


TextComponent_BullShit::~TextComponent_BullShit()
{
}


void TextComponent_BullShit::SetText(char* _text)
{
	RemoveTextObjects();

	int charIndex = 0;

	while (_text[charIndex] != '\0')
	{
		AddTextObject(_text[charIndex]
			, OpenGLRenderer::GetRenderer()->GetCharacterImage(_text[charIndex]));
		++charIndex;
	}
		
}

void TextComponent_BullShit::AddTextObject(char _char, char* _charImage)
{
	TextObject* textObj = (TextObject*)GameObjectFactory::CreateActor<TextObject>();

	GameObjectFactory::AddSpiteComponent(textObj, _charImage, 2000);

	textObj->SetPosition(GetPosition() + Vect2(textObjects.size() * 32,0));

	textObjects.push_back(textObj);
}

void TextComponent_BullShit::RemoveTextObjects()
{
	while (!textObjects.empty())
	{
		textObjects.back()->Destroy();
		textObjects.pop_back();
	}
		
}

void TextComponent_BullShit::SetPosition(Vect2 _pos)
{
	Vect2 OffSet = _pos - GetPosition();
	RenderableComponent::SetPosition(_pos);

	for (int i = 0; i < textObjects.size(); i++)
	{
		textObjects[i]->SetPosition(textObjects[i]->GetPosition() + OffSet);
	}
}

void TextComponent_BullShit::Render()
{
}