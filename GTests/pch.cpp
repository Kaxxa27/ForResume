//
// pch.cpp
//

#include "pch.h"


void File_IsOpen(string& FileName, fstream& fs)
{
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