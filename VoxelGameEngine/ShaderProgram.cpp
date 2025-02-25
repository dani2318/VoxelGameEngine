#include "ShaderProgram.h"


ShaderProgram::ShaderProgram(std::string vertexShaderPath, std::string fragmentShaderPath) {
	this->programID = -1;
	this->reader->setFilePath(vertexShaderPath);
	this->vertexShaderSource = reader->ReadFile();

	this->reader->setFilePath(fragmentShaderPath);
	this->fragmentShaderSource = reader->ReadFile();

	this->vertexShaderSourceCstr = this->vertexShaderSource.c_str();
	this->fragmentShaderSourceCstr = this->fragmentShaderSource.c_str();
}

unsigned int ShaderProgram::CompileShader(const char* source, GLuint type) {
	unsigned int vertexShader;
	vertexShader = glCreateShader(type);

	glShaderSource(vertexShader, 1, &source, NULL);
	glCompileShader(vertexShader);


	return vertexShader;
}

void ShaderProgram::init() {
	unsigned int vertexShader = CompileShader(vertexShaderSourceCstr, GL_VERTEX_SHADER);
	unsigned int fragmentShader = CompileShader(fragmentShaderSourceCstr, GL_FRAGMENT_SHADER);
}

ShaderProgram::~ShaderProgram() {

}

void ShaderProgram::use() {
	glUseProgram(programID);
}