#include "TextComponent.h"

using std::cout;
using std::endl;

TextComponent::TextComponent() : RenderableComponent()
{
}


TextComponent::~TextComponent()
{
}

bool TextComponent::Load()
{
	if (FT_Init_FreeType(&freeTypeLibarary))
		std::cout << "Could not init freetype library" << std::endl;


	if (FT_New_Face(freeTypeLibarary, "Assets/timesbi.ttf", 0, &face))
		std::cout << "Could not open font" << std::endl;

	FT_Set_Pixel_Sizes(face, 0, 48);


	auto hr = this->vShader->LoadFromFile(
		GL_VERTEX_SHADER,
		"Assets/Text_VShader.txt");
	if (!hr)
	{
		cout << "Error on loading vertex shader" << endl;
		return hr;
	}

	//the fragment shader returns the color of pixel
	hr = this->fShader->LoadFromFile(
		GL_FRAGMENT_SHADER,
		"Assets/Text_FShader.txt");
	if (!hr)
	{
		cout << "Error on loading fragment shader" << endl;
		return hr;
	}

	glActiveTexture(GL_TEXTURE0);
	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D, tex);
	glUniform1i(0, 0);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);

}

void TextComponent::Render()
{
	glUseProgram(programObject);


	//GLfloat pos[2] = { 0.5, 0.5 };
	//this->vShader->SetUniformVect2("uPosition", pos);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, tex);
	glUniform1i(0, 0);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	float x = 200;
	float y = 200;

	float sy = 1;
	float sx = 1;

	const char *p;

	FT_GlyphSlot g = face->glyph;

	text = "HELLO";

	for (p = text; *p; p++) 
	{
		if (FT_Load_Char(face, *p, FT_LOAD_RENDER))
			continue;

		glTexImage2D(
			GL_TEXTURE_2D,
			0,
			GL_ALPHA,
			g->bitmap.width,
			g->bitmap.rows,
			0,
			GL_ALPHA,
			GL_UNSIGNED_BYTE,
			g->bitmap.buffer
			);

		float x2 = x + g->bitmap_left * sx;
		float y2 = -y - g->bitmap_top * sy;
		float w = g->bitmap.width * sx;
		float h = g->bitmap.rows * sy;

		GLfloat box[4][4] = {
			{ x2, -y2, 0, 0 },
			{ x2 + w, -y2, 1, 0 },
			{ x2, -y2 - h, 0, 1 },
			{ x2 + w, -y2 - h, 1, 1 },
		};

		glBufferData(GL_ARRAY_BUFFER, sizeof box, box, GL_DYNAMIC_DRAW);
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

		x += (g->advance.x >> 6) * sx;
		y += (g->advance.y >> 6) * sy;
	}


}

OpenGLKey TextComponent::GetKey()
{
	return "OpenGL_Text";
}
