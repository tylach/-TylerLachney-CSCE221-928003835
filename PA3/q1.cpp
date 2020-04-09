#include <fstream>
#include <cctype>
#include <set>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string line, filename, word;
    int pos;

    ifstream in;
    set<string> idents;
    set<string> reserved;
	vector<char> separator;
    string reserveArray[]= {"for", "if","else", "fstream", "set","string",
        "include", "main", "using", "namespace","std", "iostream", "string", 
        "ifstream","char","auto","size","open","while","return","int","endl"};
	char separatorArray[] = {'[', ']', '(', ')' ,'{', '}', '<', '>', '\'', '\"', ',' , ';', ':', '*', '#', '=','+','-' ,'/', ' ', '.', '!', '%', '@'};
	
    for (int i = 0; i <22; i++)
        reserved.insert(reserved.end(),reserveArray[i]);
	
    for (int i = 0; i <24; i++)
        separator.push_back(separatorArray[i]);

    cout<<"enter the file name: ";
    cin>>filename;

    in.open(filename.c_str());
    //getline(in,line);
	bool isReserved = false;
	bool isSeparator = false;
	bool inQuotes = false;
	word = "";
	
    while (in)
    {
	    getline(in,line);
		//cout << line << endl;
		for(int i = 0 ; i < line.size() ; ++i){
			//cout << line[i] << endl;
			for(int j = 0 ; j < separator.size() ; ++j){
				if(line[i] == separator[j]){
					isSeparator = true;
					//cout << "-------0-------" <<endl;
					break;
				}
			}
			if(line[i] == '\"'){
				if(!inQuotes){
					inQuotes = true;
				}
				else{
					inQuotes = false;
				}
			}
			if(!isSeparator){
				//cout << "-------1-------" <<endl;
				if(!inQuotes){
					word+=line[i];
				}
			}
			else{
				//cout << "-------2-------" <<endl;

				for(auto y:reserved){
					if(word == y){
						//cout << "-------3-------" <<endl;
						isReserved = true;
						word = "";
						break;
					}
				}
				if(line[i] == '/' && line[i+1] == '/'){
						word = "";
						break;
				}
				if(!isReserved && word!=""){
					//cout << "-------4-------" <<endl;
					if(!isdigit(word[0])){
						idents.insert(idents.end(),word);
					}
					word = "";
				}

			}
			isSeparator = false;
			isReserved = false;
		}
        //break;
    }

    for (auto x:idents)
        cout<<x<<endl;
    return 0;
}
