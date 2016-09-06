#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <string>
#include <vector>

#include "State.h"

class FileWriter
{
public:
	FileWriter(std::vector <double> * source, std::string generalFileName,
		   std::string generalHeaderName, std::string path,
		   const int precision, std::vector <int> gridSize);
	void write(const int stepNumber) const;
	void clean() const;
private:
	std::vector <double> * m_source;
	const std::string m_generalFileName;
	const std::string m_generalHeaderName;
	const std::string m_path;
	int               m_precision;
	std::vector <int> m_gridSize;
};

#endif // FILEWRITER_H
