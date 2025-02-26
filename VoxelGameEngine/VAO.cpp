#include "VAO.h"

#include <glad/glad.h>

VAO::VAO() {
	glGenVertexArrays(1, &m_VAO);
	bind();
	unbind();
}

void VAO::bufferatrib(unsigned int value) {
	glVertexAttribPointer(0, value, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
}

VAO::~VAO() {
	glDeleteVertexArrays(1, &m_VAO);
}

void VAO::bind() {
	glBindVertexArray(m_VAO);
}

void VAO::unbind() {
	glBindVertexArray(0);
}