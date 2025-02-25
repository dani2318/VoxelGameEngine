#pragma once
#include <string>

class FileReader {
public:
	FileReader();
	FileReader(const std::string& filePath);
	std::string ReadFile();
	void setFilePath(const std::string& filePath) { m_FilePath = filePath; }
private:
	std::string m_FilePath;
};