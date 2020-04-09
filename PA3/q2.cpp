#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    /*map<int, int> gquiz1; 
    gquiz1.insert(pair<int, int>(1, 40)); 
    gquiz1.insert(pair<int, int>(2, 30)); 
    gquiz1.insert(pair<int, int>(3, 60)); 
    gquiz1.insert(pair<int, int>(4, 20)); 
    gquiz1.insert(pair<int, int>(5, 50)); 
    gquiz1.insert(pair<int, int>(6, 50)); 
    gquiz1.insert(pair<int, int>(7, 10)); map <string,int> coronamap;
	map<int, int>::iterator itr; 
	    cout << "\nThe map gquiz1 is : \n"; 
	    cout << "\tKEY\tELEMENT\n"; 
	    for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) { 
	        cout << '\t' << itr->first 
	             << '\t' << itr->second << '\n'; 
	    } 
	    cout << endl; */
	
	
    string line, filename;
    map <string,int> coronamap;

    ifstream in;
    cout<<"enter the file name: ";
    cin>>filename;

    in.open(filename.c_str());
    //getline(in,line);
	//cout << line << endl;
    string partOf;
	int i;
	string country = "";
	string cases = "";
	int numCases = 0;
	map<string, int>::iterator itr;
    while (in){
	    getline(in,line);
		i = 0;
		country = "";
		cases = "";
		while(line[i] != ' '){
			country += line[i];
			i++;
		}
		i++;
		while(i < line.size()){
			cases += line[i];
			i++;
		}
		numCases = stoi(cases);		
		
		coronamap.insert(pair<string,int>(country,numCases));
        // your implementation here for building coronamap
    }
	
    string worstCountry= "";
	int worstCase = 0;
	for(itr = coronamap.begin() ; itr != coronamap.end() ; ++itr){
		if(itr->second > worstCase){
			worstCountry = itr->first;
		}
		//cout<<itr->first<<" " << itr->second<<endl;
	}
	cout << "Most confirmed cases are in " << worstCountry << endl;
    // your implementation here to print the country with max cases
    // E.g. Most confirmed cases are in USA

    return 0;
}
