#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

/*
** Text Reader Class 
*/

template <typename T>
class TextReader
{
	std::string fileName;
public:
	TextReader(std::string file) : fileName(file){}
	std::vector<std::vector<T> > parseReturnData();
	// Other data formatting functions if needed.
};

/*
** Function to read data in text file and return output
*/

template <typename T>
std::vector<std::vector<T> > TextReader<T>::parseReturnData()
{
	T nums;
	// std::string ignore_string;
	std::ifstream file_stream(fileName.c_str(), std::fstream::in); // File Reader (Filestream).
	std::vector<std::vector<T> > dataStore;
	std::vector<T> temp;
	if(file_stream.fail()){
		std::cout << "Error Opening/Reading file." << std::endl;
		exit(EXIT_FAILURE);
	} else {
		// std::getline(file_stream, ignore_string);
		while(!file_stream.eof()){
			for(auto cols = 0; cols < 3; cols++){
				file_stream >> nums;
				temp.push_back(nums);
			}
		if(file_stream.eof()) break; // Last Line Break. No repeat.
		dataStore.push_back(temp);
		temp.clear();
		}
	}
	file_stream.close();
	return dataStore;
}
