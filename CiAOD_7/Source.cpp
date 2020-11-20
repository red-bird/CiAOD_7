#include <iostream>
#include <fstream>
#include <list>
#include <string>
using namespace std;

struct Process
{
	int begin, end;
};


void readFile(list<Process*> &lst) {
	/// <summary>
	/// Read data from "input.txt" file into your argument
	/// </summary>
	/// <param name="lst">storage of data from file</param>
	string line;
	ifstream input("input.txt");
	if (!input.is_open())
		cout << "Can't find input file\n";
	else
	{
		while (!input.eof())
		{
			Process* prc = new Process();
			getline(input, line, ' ');
			prc->begin = stoi(line);
			getline(input, line);
			prc->end = stoi(line);
			lst.push_back(prc);
		}
	}
}

int main()
{

	list<Process*> lst;
	readFile(lst);
	

}