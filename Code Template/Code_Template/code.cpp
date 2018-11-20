#include "Headers/headers.h"

void solution(int argc, char* argv[], char* envp[])
{
    int n,q;
    cin >> n >> q;
    cin.ignore();
    map <string,string> attributeDB; // to store attribute-value pairs
    string inputstr, tag_preamble="";
    // get each HRML line
    for (int i=0;i<n;i++) {
        getline(cin,inputstr);
        // for each HRML line, break it up into token words
        stringstream ss;
        ss << inputstr;
        string word, attribute, value;
        size_t pos;
        while (getline(ss, word, ' ')) { // for each token word
            // tag detected -> adjust tag_preamble by +/- tag
            if (word[0]=='<') {
                string tag;
                if (word[1]=='/') { // it's tag closing
                    tag=word.substr(2);
                    tag=tag.substr(0,tag.length()-1); // rid of ">"
                    pos=tag_preamble.find("."+tag);
                    if (pos==string::npos) tag_preamble="";
                    else tag_preamble=tag_preamble.substr(0,pos);
                }
                else { // it's tag opening
                    tag=word.substr(1);
                    if (tag.find(">")!=string::npos)
                        tag=tag.substr(0,tag.length()-1); // rid of ">"
                    if (tag_preamble=="") tag_preamble=tag;
                    else tag_preamble=tag_preamble+"."+tag;
                }
            }
            // value detected
            else if (word[0]=='"') {
                pos=word.find_last_of('"');
                value=word.substr(1,pos-1);
                attributeDB[attribute]=value; // insert into DB
            }
            // attribute name detected
            else if (word[0]!='=') {
                attribute=tag_preamble + "~" + word;
            }
        }
    }
    // now we process the queries
    for (int i=0;i<q;i++) {
        getline(cin,inputstr);
        if (attributeDB.find(inputstr)==attributeDB.end())
            cout << "Not Found!" << endl;
        else
            cout << attributeDB[inputstr] << endl;
    }
    
}

int main(int argc, char* argv[], char* envp[])
{
#ifdef OFFLINE_START_BUILD
    start_time = clock();
    intialize_io("testcase");
    build_log();
    HackerRank(); /* Unzip and copy files for input */
    // codejam(); /* Unzip and copy files for input */
#endif
    solution(argc, argv, envp);
#ifdef OFFLINE_START_BUILD
    build_solution();
    std::cerr << "Output Accepted : 0/1 -> " << HackerRank_Compare() << std::endl; /* Automated comapre of output files */
    end_time_log(start_time, argc, argv, envp);
#endif
    return 0;
}

