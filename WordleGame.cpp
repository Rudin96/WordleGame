// WordleGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
	std::ifstream myfile("test.txt");
	std::string fileContents;
	std::vector<std::string> strings;
	if (myfile.is_open())
	{
		while (getline(myfile, fileContents))
		{
			strings.push_back(fileContents);
		}

		for (size_t i = 0; i < strings.size(); i++)
		{
			std::cout << strings[i] << std::endl;
		}
		myfile.close();
	}
}