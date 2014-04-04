#pragma once

#include <GLES2/gl2.h>
#include <string>


struct ShaderParam
{
public:
	std::string Name = "";
	std::string Type = "";
	int Location = -1;

	// members
	bool operator==(const ShaderParam& r) const
	{
		return this->Name == r.Name;
	}
};

class Shader
{
public:
	Shader(GLuint programObj);
	~Shader();

	void SetProgramObject(GLuint programObj);
	GLuint LoadFromMemory(GLenum Type, const char* ShaderSource);
	GLuint LoadFromFile(GLenum Type, const char* filePath);

	void Bind(int index, GLchar* name);
	bool Link();
	void Release();

	GLuint GetShader() const { return this->shader; };
	std::vector<ShaderParam> GetUniforms() const { return this->uniforms; };
	std::vector<ShaderParam> GetAttributes() const { return this->attributes; };

	void Shader::SetUniformVect2(GLint location, GLfloat value[2]);
	void Shader::SetUniformVect2(std::string name, GLfloat value[2]);
	void Shader::SetUniformVect4(GLint location, GLfloat value[4]);
	void Shader::SetUniformVect4(std::string name, GLfloat value[4]);


private:
	std::string GetType(GLenum type);
	void GetActiveUniforms();
	void GetActiveAttributes();

private:
	GLuint programObject;

	GLuint shader;
	GLint isLinked;
	std::vector<ShaderParam> uniforms;
	std::vector<ShaderParam> attributes;
};

