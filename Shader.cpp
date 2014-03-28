#include "pch.h"
#include "Shader.h"

using namespace std;


Shader::Shader(GLuint programObj)
{
	programObject = programObj;
}


Shader::~Shader()
{
}

GLuint Shader::LoadFromMemory(GLenum Type, const char* ShaderSource)
{
	GLint compileSuccessfully;

	/*
	Create the shader based on the type of shader. The type indicates to
	the vertex shader, fragment shader or etc
	*/
	this->shader = glCreateShader(Type);
	if (shader == 0) return 0;

	/*
	Load a source code of shader
	*/
	glShaderSource(this->shader, 1, &ShaderSource, NULL);
	//Compile the source code of the shader
	glCompileShader(this->shader);

	//Check the result of compile
	glGetShaderiv(this->shader, GL_COMPILE_STATUS, &compileSuccessfully);

	if (!compileSuccessfully)
	{
		GLint infoLen = 0;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen);
		if (infoLen > 1)
		{
			auto infoLog = unique_ptr<char>(new char[infoLen]);
			glGetShaderInfoLog(shader, infoLen, NULL, infoLog.get());
			cout << "Could not compile the shader with following information : " << infoLog.get() << endl;
		}
		//Release the shader
		Release();

		return 0;
	}

	//Attach this shader to the program object
	glAttachShader(programObject, this->shader);

	return shader;
}

GLuint Shader::LoadFromFile(GLenum Type, const char* filePath)
{
	ifstream file;

	file.open(filePath, ios::in);
	if (!file)
	{
		cout << "Could not open the shader file" << endl;
		return 0;
	}

	auto len = GetFileLength(file);
	if (len == 0)
	{
		cout << "Could not read the shader file, because it is an empty file" << endl;
		return 0;
	}

	auto ShaderSource = new char[len + 1];
	ShaderSource[len] = 0;

	unsigned int i = 0;
	while (file.good())
	{
		ShaderSource[i] = file.get();
		if (!file.eof())
		{
			i++;
		}
	}

	ShaderSource[i] = 0;

	file.close();

	return LoadFromMemory(Type, ShaderSource);
}

string Shader::GetType(GLenum type)
{
	switch (type)
	{
	default:
		return "Unknown Type";
	case GL_FLOAT:
		return "GL_FLOAT";
	case GL_FLOAT_VEC2:
		return "GL_FLOAT_VEC2";
	case GL_FLOAT_VEC3:
		return "GL_FLOAT_VEC3";
	case GL_FLOAT_VEC4:
		return "GL_FLOAT_VEC4";
	case GL_INT:
		return "GL_INT";
	}
}

void Shader::GetActiveUniforms()
{
	/*
	Uniforms variables store read-only constant values, it means that
	they do not change during the rendering.
	Uniforms are available in both vertex and fragment shaders, and shared across a program object.
	When an uniform is declared in both a vertex and fragment shader,
	it must have the same type and value.
	*/
	const int MaxSizeName = 100;
	//Get total number of active uniforms
	int totalUniforms = -1;
	glGetProgramiv(programObject, GL_ACTIVE_UNIFORMS, &totalUniforms);

	this->uniforms.clear();
	this->uniforms.resize(totalUniforms);

	//Read each name and location of uniforms
	for (int i = 0; i < totalUniforms; ++i)
	{
		int name_len = -1;
		int num = -1;
		ShaderParam uniform;
		GLenum type = GL_ZERO;
		char name[MaxSizeName];
		{
			glGetActiveUniform(
				programObject,
				GLuint(i),
				sizeof(name)-1,
				&name_len,
				&num,
				&type,
				name);
		}
		name[name_len] = 0;

		uniform.Name = name;
		uniform.Type = GetType(type);
		uniform.Location = glGetUniformLocation(programObject, name);

		this->uniforms.at(i) = uniform;
	}
}

void Shader::GetActiveAttributes()
{
	/*
	Attributes are only available in vertex shader and change in each frame.
	For example in our sample the vertex position and color of vertex are attributes
	*/
	const int MaxSizeName = 100;
	//Get total number of active uniforms
	int totalAttributes = -1;
	glGetProgramiv(programObject, GL_ACTIVE_ATTRIBUTES, &totalAttributes);

	this->attributes.clear();
	this->attributes.resize(totalAttributes);

	//Read each name and location of uniforms
	for (int i = 0; i < totalAttributes; ++i)
	{
		int name_len = -1;
		int num = -1;
		ShaderParam attribute;
		GLenum type = GL_ZERO;
		char name[MaxSizeName];
		{
			glGetActiveAttrib(
				programObject,
				GLuint(i),
				sizeof(name)-1,
				&name_len,
				&num,
				&type,
				name);
		}
		name[name_len] = 0;

		attribute.Name = name;
		attribute.Type = GetType(type);
		attribute.Location = glGetAttribLocation(programObject, name);

		this->attributes.at(i) = attribute;
	}
}

void Shader::SetUniformVect2(GLint location, GLfloat value[2])
{
	glUniform2f(location, value[0], value[1]);
}

void Shader::SetUniformVect2(const string name, GLfloat value[2])
{
	auto it = find_if(this->uniforms.begin(), this->uniforms.end(),
		[name](ShaderParam u) -> bool
	{
		return u.Name == name;
	});

	if (it != this->uniforms.end())
	{
		//Get the first founded item
		SetUniformVect2(it[0].Location, value);
	}
}

void Shader::SetUniformVect4(GLint location, GLfloat value[4])
{
	glUniform4f(location, value[0], value[1], value[2], value[3]);
}

void Shader::SetUniformVect4(const string name, GLfloat value[4])
{
	auto it = find_if(this->uniforms.begin(), this->uniforms.end(),
		[name](ShaderParam u) -> bool
	{
		return u.Name == name;
	});

	if (it != this->uniforms.end())
	{
		//Get the first founded item
		SetUniformVect4(it[0].Location, value);
	}
}


void Shader::Bind(int index, GLchar* name)
{
	glBindAttribLocation(programObject, index, name);
}

bool Shader::Link()
{
	//Link the shader and program object
	glLinkProgram(programObject);
	//Check th status of link
	glGetProgramiv(programObject, GL_LINK_STATUS, &this->isLinked);

	if (!this->isLinked)
	{
		//If not linked, show the error info and the release the shader
		GLint infoLen = 0;
		glGetProgramiv(programObject, GL_INFO_LOG_LENGTH, &infoLen);
		if (infoLen > 1)
		{
			auto errorInfo = unique_ptr<char>(new char[infoLen]);
			glGetProgramInfoLog(programObject, infoLen, NULL, errorInfo.get());
			esLogMessage("Error linking program:\n%s\n", errorInfo.get());
			errorInfo.release();
		}
		Release();
		return false;
	}

	//We need to store the information of our active uniforms, attributes
	GetActiveUniforms();
	GetActiveAttributes();

	return true;
}

void Shader::Release()
{
	//Detach the shader from program object then delete it
	glDetachShader(programObject, this->shader);
	glDeleteShader(this->shader);
}

void Shader::SetProgramObject(GLuint programObj)
{
	programObject = programObj;
}