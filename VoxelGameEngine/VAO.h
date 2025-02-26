#pragma once
class VAO
{
public:
public:
	VAO();
	~VAO();
	void bind();
	void unbind();
	unsigned int getID() { return m_VAO; }
private:
	unsigned int m_VAO;
private:
};

