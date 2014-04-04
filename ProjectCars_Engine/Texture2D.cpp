#include "pch.h"
#include "Texture2D.h"

using namespace std;

Texture2D::Texture2D()
{
}


Texture2D::~Texture2D()
{
}

GLuint Texture2D::CreateTexture2D()
{
	GLuint textureObj;
	int  width = 256;
	int	height = 256;

	size = Size(width, height);

	auto pixels = unique_ptr<GLubyte[]>(new GLubyte[width * height * 3]);
	if (pixels == nullptr)
	{
		cout << "Could not allocate the memory for the pixels, error in Texture2D" << endl;
		return 0;
	}

	int checkSize = 32;
	for (int j = 0; j < height; ++j)
	{
		for (int i = 0; i < width; ++i)
		{
			GLubyte rColor = 0;
			GLubyte bColor = 0;

			if ((i / checkSize) % 2 == 0)
			{
				rColor = 255 * ((j / checkSize) % 2);
				bColor = 255 * (1 - ((j / checkSize) % 2));
			}
			else
			{
				bColor = 255 * ((j / checkSize) % 2);
				rColor = 255 * (1 - ((j / checkSize) % 2));
			}

			pixels[(j * height + i) * 3] = rColor;
			pixels[(j * height + i) * 3 + 1] = 0;
			pixels[(j * height + i) * 3 + 2] = bColor;
		}
	}

	// Generate a texture object
	glGenTextures(1, &textureObj);
	// Bind to the 2D texture object
	glBindTexture(GL_TEXTURE_2D, textureObj);
	// Set the mipmap level 0
	glTexImage2D(
		GL_TEXTURE_2D,
		0,//Mip Map Level
		GL_RGB,//Internal format
		width,
		height,
		0.0f,//Border of texture, ignored in OpenGL ES and should be 0. it was kept for compatibility with the desktop OpenGL interface
		GL_RGB,//the format of the incoming texture data. Note that in OpenGL ES the format and internalFormat arguments must have the same value. 
		GL_UNSIGNED_BYTE,//Type of data
		pixels.get());

	// Set the filtering mode
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	pixels.release();

	return textureObj;
}

GLuint Texture2D::LoadTexture(char* path)
{
	GLuint textureObj;
	int width;
	int height;
	auto pixels = esLoadTGA(path, &width, &height);

	size = Size(width, height);

	if (pixels == nullptr)
	{
		cout << "Could not allocate the memory for the pixels, error in Texture2D" << endl;
		return 0;
	}
	
	// Generate a texture object
	glGenTextures(1, &textureObj);
	// Bind to the 2D texture object
	glBindTexture(GL_TEXTURE_2D, textureObj);
	// Set the mipmap level 0
	glTexImage2D(
		GL_TEXTURE_2D,
		0,//Mip Map Level
		GL_RGB,//Internal format
		width,
		height,
		0.0f,//Border of texture, ignored in OpenGL ES and should be 0. it was kept for compatibility with the desktop OpenGL interface
		GL_RGB,//the format of the incoming texture data. Note that in OpenGL ES the format and internalFormat arguments must have the same value. 
		GL_UNSIGNED_BYTE,//Type of data
		pixels);

	// Set the filtering mode
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	delete[] pixels;

	return textureObj;
}

Size Texture2D::GetSize()
{
	return size;
}