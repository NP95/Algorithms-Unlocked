/*
* Copyright (c) Sumit Lahiri (CodeObsess) 
*/

#include <iostream>
#include <stdio.h>
#include <regex>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
using namespace std;

int main()
{
	bool found = false;
	int counter = 0;
	smatch text_match;
	std::string text_url_atag;
	regex expr("href=\"/problems/([[:w:]]+)\"", regex_constants::icase);
	fstream HTMLReader("index.html", std::fstream::in);
	stringstream problem_codes_stream;
	if(HTMLReader.fail()){
		std::cout << "Could Not Open HTML/TXT File." << std::endl;
		exit(EXIT_FAILURE);
	} else {
		while(!HTMLReader.eof()){
			HTMLReader >> text_url_atag;
			found = regex_search(text_url_atag, text_match, expr);
			if(HTMLReader.eof()) break;
			else problem_codes_stream << text_match[1] << endl;
		}
		text_url_atag.clear();
		cout << "<html><head><title>Problems-Extractor</title><style>a:link, a:visited {background-color: white; color: black;  border: 2px solid green;  padding: 10px 20px; text-align: center; text-decoration: none;    display: inline-block;} a:hover, a:active { background-color: green; color: white; }</style></head><body><div><p>Please Click on the problem Links given below : </p></div>" << endl;
		while(problem_codes_stream)
		{
			++counter;
			problem_codes_stream >> text_url_atag;
			cout << "<div><p><a"  << " href=\"" << "https://www.codechef.com/problems/" << text_url_atag  << "\">" << counter << ". Problem : " << text_url_atag << " </a></p></div>" << endl;
		}
		cout << "</body></html>" << endl;
		HTMLReader.close();
	}
	return 0;
}
