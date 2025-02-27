#include "VBO.h"

#include <glad/glad.h>

VBO::VBO(){
	glGenBuffers(1, &m_VBO);
}

void VBO::glData(unsigned int size, const float* data) {
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

VBO::~VBO() {
	glDeleteBuffers(1, &m_VBO);
}

void VBO::bind() {
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
}
void VBO::unbind() {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
