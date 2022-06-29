//
// pch.h
//

#pragma once

#include "gtest/gtest.h"
#include <fstream>
#include<regex>

using namespace std;

void File_IsOpen(string& FileName, fstream& fs);
void File_Fill(string& FileStr, fstream& fs);
