#include<iostream>
#include<vector>
#include<cmath>
#include<ctime>
using namespace std;

int insertLinear(int x, vector<int> & linear);
int insertQuad(int x, vector<int> & quad);
int insertDuble(int x, int dubHash, vector<int> & duble);

int main()
{
  int linCollides=0;
  int quadCollides= 0;
  int dubCollides = 0;
  int quadInc;
  int tableSize;
  bool fail = false;
  int x, count=0;
  int doubleHash;

  srand(time(NULL));
  cout<<"enter the size of the table ";
  cin>>tableSize;
  vector<int> linear(tableSize,-1);//initalize each table to -1 for empty
  vector<int> quad(tableSize,-1);  //initalize each table to -1 for empty
  vector<int> duble(tableSize,-1);  //initalize each table to -1 for empty
  do{
   doubleHash = rand()%tableSize;
  }while (doubleHash < tableSize/10 && doubleHash%tableSize==0);

  while(count < tableSize && !fail)
  {
    x= rand()%tableSize;// value to insert
	quadInc=insertQuad(x,quad);
	if (quadInc < 0)
		fail = true;
	else
	{
	 quadCollides += quadInc;
	 linCollides+=insertLinear(x,linear);
	 dubCollides+=insertDuble(x,doubleHash, duble);
	}
	count++;
  }
  //cout << x << endl;
  cout<<"Num linear collides "<<linCollides<<endl;
  cout<<"Num quadratic collides "<<quadCollides<<endl;
  cout<<"Num double hash collides "<<dubCollides<<endl;
  return 0;
}

int insertLinear(int x, vector<int> & linear)
{
	//returns the number of collisions inserting the number
	//linear.size() is the table size
	int collisions = 0;
	int i = x%linear.size();
	if(linear[i] == -1){
		linear[i] = x;
	}
	else{
		while(linear[i]!=-1){
			collisions++;
			if(i==linear.size()-1){
				i=0;
			}
			else{
				i++;
			}
		}
		linear[i] = x;
	}
	return collisions;
}

int insertQuad(int x, vector<int> & quad)
{
	int bucketsProbed = 0;
	int collisions = 0;
	int i=0;
	int c1=1;
	int c2=1;
	int j=(j+c1*i+c2*i*i)%quad.size();
	while(bucketsProbed < quad.size()){
		if(quad[j] == -1){
			quad[j] = x;
			break;
		}
		collisions++;
		i++;
		j=(j+c1*i+c2*i*i)%quad.size();
		bucketsProbed++;
	}
  	return collisions;
}

int insertDuble(int x, int dubHash, vector<int> & duble)
{
	int collisions = 0;
	int i = 0;
	int bucketsProbed = 0;
	int j=(x%10 + i*((duble.size()-1)-(x%(duble.size()-1))))%duble.size();
	while(bucketsProbed < duble.size()){
		if(duble[j] == -1){
			duble[j] = x;
			break;
		}
		collisions++;
		i++;
		j=(x%(x+1) + i*(x%(dubHash+1)))%duble.size();
		bucketsProbed++;
	}
  	return collisions;
}
