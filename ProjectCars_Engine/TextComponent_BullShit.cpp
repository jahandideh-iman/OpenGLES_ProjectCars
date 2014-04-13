#include "TextComponent_BullShit.h"


TextComponent_BullShit::TextComponent_BullShit()
{
}


TextComponent_BullShit::~TextComponent_BullShit()
{

}


void TextComponent_BullShit::SetText(Text _text)
{
	text = _text;

}





void TextComponent_BullShit::SetPosition(Vect2 _pos)
{
	Vect2 OffSet = _pos - GetPosition();
	RenderableComponent::SetPosition(_pos);

}

void TextComponent_BullShit::Render()
{
	int charIndex = 0;
	TextObject* textObj;
	SpriteComponent * textSprite;
	while (text[charIndex] != '\0')
	{
		textObj = OpenGLRenderer::GetRenderer()->GetCharacterImage(text[charIndex]);
		
		textSprite = textObj->GetTextSprite();

		textSprite->SetHidden(false);
		textSprite->SetPosition(GetPosition() + Vect2(charIndex * CHAR_WIDTH, 0));
		textSprite->Render();
		textSprite->SetHidden(true);
	
		++charIndex;
	}
}