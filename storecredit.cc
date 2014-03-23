#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int N, C, I, P;
	string line;

	ifstream myfile ("A-small-practice.in");
	if ( myfile.is_open() )
	{
		while( getline( myfile, line ))
		{
			cout << line << endl;
		}
	}	

	myfile.close();
	return 0;
}
