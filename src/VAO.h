#pragma once
class VAO
{
public:
public:
	VAO();
	~VAO();
	void bind();
	void unbind();
	void bufferatrib(unsigned int value);
	unsigned int getID() { return m_VAO; }
private:
	unsigned int m_VAO;
private:
};

