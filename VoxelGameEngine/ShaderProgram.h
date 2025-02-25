#pragma once
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "FileReader.h"

class ShaderProgram
{
public:
	ShaderProgram(std::string vertexShaderPath, std::string fragmentShaderPath);
	~ShaderProgram();
	void use();
	void init();
	inline unsigned int GetProgramID() {
		return programID;
	}
private:
	FileReader* reader = new FileReader();
	unsigned int programID;
	unsigned int CompileShader(const char* source, GLuint type);
private:
	std::string vertexShaderSource;
	std::string fragmentShaderSource;
	const char* fragmentShaderSourceCstr;
	const char* vertexShaderSourceCstr;

};

