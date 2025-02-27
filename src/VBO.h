#pragma once
class VBO
{
public:
	VBO();
	~VBO();
	void bind();
	void unbind();
	void glData(unsigned int size,const float* data);
	unsigned int getID() { return m_VBO; }
private:
	unsigned int m_VBO;
};
#pragma once



