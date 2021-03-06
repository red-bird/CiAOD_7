#include <iostream>
#include <fstream>
#include <list>
#include <string>
using namespace std;

struct Process
{
	int begin, end, num;
};


bool readFile(list<Process*> &lst) {
	/// <summary>
	/// Read data from "input.txt" file into your argument
	/// </summary>
	/// <param name="lst">storage of data from file</param>
	string line;
	ifstream input("input.txt");
	if (!input.is_open())
	{
		cout << "Missing input file!\n";
		return false;
	}
	else
	{
		int i = 0;
		while (!input.eof())
		{
			++i;
			Process* prc = new Process();
			getline(input, line, ' ');
			if (line.size()==0)
			{
				cout << "Input file is empty!\n";
				return false;
			}
			prc->begin = stoi(line);
			getline(input, line);
			prc->end = stoi(line);
			prc->num = i;
			lst.push_back(prc);
		}
		return true;
	}
}

bool cmp(const Process* first, const Process* second) {
	return (first->end < second->end);
}

list<Process*> greedyActiveSelector(const list<Process*> &lst) {
	/// <summary>
	///		Select a subset of mutually compatible processes
	/// </summary>
	/// <param name="lst">list of processes, !!!it must be sorted in end time order!!!</param>
	/// <returns></returns>
	list<Process*> selected;
	selected.push_back(lst.front());
	for (auto it = lst.begin(); it != lst.end(); it++)
	{
		if ((*it)->begin >= selected.back()->end)
		{
			selected.push_back((*it));
		}
	}
	return selected;
}

int main()
{

	list<Process*> lst, result;
	if (!readFile(lst))
	{
		return -1;
	}
	lst.sort(cmp);
	result = greedyActiveSelector(lst);
	lst.clear();
	cout << "Multiplicity of process:\n";
	for (auto it = result.begin(); it != result.end(); it++)
	{
		cout << (*it)->num << " process\n";
	}
	return 0;
}