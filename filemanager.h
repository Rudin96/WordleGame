#pragma once

#include <iostream>
#include <fstream>
#include <vector>

using std::string;

class FileManager {
public:
	static std::vector<string> ReadAllLines(string path);
};