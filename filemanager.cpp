#include "filemanager.h"
#include <string>

std::vector<string> FileManager::ReadAllLines(string path)
{
	std::vector<string> lines;
	std::string lineContent;
	std::ifstream ifs(path);
	if (ifs.is_open())
	{
		while (getline(ifs, lineContent))
		{
			lines.push_back(lineContent);
		}
		ifs.close();
	}
	return lines;
}