#include<iostream>
#include"lexer.h"

using namespace std;

int main() {
	string filename;
	int iterator = 0;
	vector<Token> v;
	fstream input;
	string fileline;
	Token endline("Endline", "");

	cout << "Enter file to open: ";
	cin >> filename;

	// Opens Source Code Text File
	input.open(filename);
	if (!input)
	{
		cerr << "Cannot find file" << endl;
		exit(1);
	}

	// Activates Lexer One Line at a time
	while (!input.eof())
	{
		getline(input, fileline);
		if (fileline == "")
		{
			getline(input, fileline);
		}
		lexer(fileline, v, iterator);
		v.push_back(endline); // Used for counting lines in error detection.
	}
	input.close();

	// Begins Syntax Analysis
	// syntax(v);

	for (int i = 0; i < v.size(); i++)
	{
		v[i].print();
	}

	ofstream outf("output.txt");
	if (!outf)
	{
		// Print an error and exit
		cerr << "Could not create output file" << endl;
		exit(1);
	}
	for (int i = 0; i < v.size(); i++)
	{
		outf << v[i].tokentype << " " << v[i].lexeme << endl;
	}

	system("pause");
	return 0;
}