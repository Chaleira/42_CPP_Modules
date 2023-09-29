#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char const *argv[])
{
	if (argc != 4)
	{
		std::cerr << "Usage: <input_file> <string_1> <string_2>" << std::endl;
		return 1;
	}
	std::ifstream inputFile(argv[1]);
    std::string line, new_line, result, s1 = argv[2], s2 = argv[3];
	if (!inputFile.is_open())
	{
		std::cerr << "Error opening file" << std::endl;
        return 1;
	}
	while (std::getline(inputFile, line))
		new_line.append(line + '\n');
	int i = 0;
	while (new_line[i])
	{
		int j = 0;
		while (new_line[i] == s1[j])
		{
			j++;
            i++;
		}
		if (!s1[j])
		{
			i -= 1;
			result.append(s2);
		}
		else
		{
			i -= j;
			result.append(std::string(1, new_line[i]));
		}
		i++;
	}
	std::cout << result;
	inputFile.close();
	return 0;
}
