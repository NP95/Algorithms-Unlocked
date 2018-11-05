#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>
using namespace std;
std::vector<string> urlgetCode;
int main()
{
	std::string dump_str;
	std::fstream file_stream, batch_stream_file;
	file_stream.open ("url.txt", std::fstream::in); 
	batch_stream_file.open ("download.bat", std::fstream::out); 
	if(file_stream.fail() || batch_stream_file.fail()){
		cout << "Oops!!. Some Error occured in opening file." << endl; 
		return -1;
	} else {
		while(!file_stream.eof()){
			dump_str.clear();
			file_stream >> dump_str;
			urlgetCode.push_back(dump_str);
		}
	}
	file_stream.close();
	for(const string& url : urlgetCode){
		batch_stream_file << "youtube-dl.exe " << url << endl;
	}
	cout << "Run the .bat file created in elevated command prompt." << endl;
	batch_stream_file.close();
	return 0;
}
