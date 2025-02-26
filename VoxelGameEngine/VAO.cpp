#include "VAO.h"

#include <glad/glad.h>

VAO::VAO() {
	glGenVertexArrays(1, &m_VAO);
	bind();
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	unbind();
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