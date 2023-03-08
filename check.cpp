#include<iostream>
#include<string>
#include<fstream>
#include <sstream>
using namespace std;

int main()
{
	fstream file;
	
	file.open("info.csv", ios::in | ios::app);
	string hold, line,name,ext = "post.csv";
	while(getline(file,line))
	{
		stringstream info(line);
		getline(info,name,',');
		getline(info,hold,',');
		getline(info,hold,',');
		getline(info,hold,',');
		getline(info,hold,',');
	
		name = name+ext;
		cout<<name<<endl;
	}
	return 0;
}

