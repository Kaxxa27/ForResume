#include<iostream>
#include<fstream>
#include<regex>

/* 
	Kakhnousky Yauheni
	Task for resume.

	I didn't do localization into Russian.
	Program:
	1. Open a file, if the file does not exist, then create it and open it.
	2. Read data from the file using the fstream library into a string of string type.
	3. Using regular expressions, replace a specific word with "nothing" :)
	4. Create a new file and save changes there.

	As for sorting, in my understanding it's just to leave the normal form of the text after changing it,
	if something is wrong, please let me know.
*/

using namespace std;

void File_IsOpen(string& FileName, fstream& fs);
void File_Fill(string& FileStr, fstream& fs);
void Save_InFile(string& FileStr);

int main()
{
	string FileName;
	string FileStr;
	string Word;

	fstream fs;

	cout << "Enter the file name: ";
	cin >> FileName;

	File_IsOpen(FileName, fs);
	File_Fill(FileStr, fs);
	cout << FileStr << endl;

	cout << "Enter the specified word: ";
	cin >> Word;

	regex reg(Word + ' ');

	FileStr = regex_replace(FileStr, reg, "");

	cout << FileStr << endl;

	Save_InFile(FileStr);

	fs.close();
	return 0;
}

void File_IsOpen(string& FileName, fstream& fs)
{
	FileName += ".txt";

	fs.open(FileName, fstream::in | fstream::out | fstream::app);
	if (!fs.is_open()) 
	{
		cout << ("File failed to open!") << endl;
	}
}

void File_Fill(string& FileStr, fstream& fs)
{
	string tmp;
	while (!fs.eof())
	{
		fs >> tmp;
		FileStr += tmp + ' ';
		tmp.clear();
	}
}

void Save_InFile(string& FileStr)
{
	fstream fs;
	string NewFileName;

	cout << "Enter the new file name: "; 
	cin >> NewFileName;
	NewFileName += ".txt";

	fs.open(NewFileName, fstream::in | fstream::out | fstream::app);

	fs << FileStr;
	fs.close();
}