#include "FileReader.h"
#include <fstream>
#include <iostream>

FileReader::FileReader() {
	
}

FileReader::FileReader(const std::string& filePath) {
	m_FilePath = filePath;
}
std::string FileReader::ReadFile() {
	std::ifstream reader(m_FilePath);

	std::string fileContents;
	std::string output;
	while (std::getline(reader, fileContents)) {
		output += fileContents + "\n";
	}


	return output;
}