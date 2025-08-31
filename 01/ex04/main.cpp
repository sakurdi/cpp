#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Usage: " << av[0] << " <filename> <s1> <s2>" << std::endl;
		return 0;
	}

	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];

	if (s1.empty())
	{
		std::cerr << "Error: s1 is empty" << std::endl;
		return 0;
	}

	std::ifstream infile(filename.c_str());

	if (!infile.is_open())
	{
		std::cerr << "Error: Cannot open file " << filename << std::endl;
		return 0;
	}

	std::string content;
	std::string line;

	while (std::getline(infile, line))
	{
		content += line;
		if (!infile.eof())
		{
			content += "\n";
		}
	}
	infile.close();

	std::string result;
	size_t pos = 0;
	size_t found = 0;

	while ((found = content.find(s1, pos)) != std::string::npos)
	{
		result += content.substr(pos, found - pos);
		result += s2;
		pos = found + s1.length();
	}
	result += content.substr(pos);

	std::string outfilename = filename + ".replace";
	std::ofstream outfile(outfilename.c_str());

	if (!outfile.is_open())
	{
		std::cerr << "Error: Cannot create file " << outfilename << std::endl;
		return 0;
	}
	outfile << result;
	outfile.close();
	std::cout << "All possible occurences of s1 replaced with s2, file created : " << outfilename << std::endl;
	return 1;
}