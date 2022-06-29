#include "pch.h"

TEST(¹1, TestName1) {

	fstream fs;
	fs.open("Test1.txt", fstream::in | fstream::out | fstream::app);

	string expected_str; // "Nowadays, the underground has more comfortable seats. "
	string actual_str = "Nowadays, the has more comfortable seats. ";

	File_Fill(expected_str, fs);

	regex reg("underground ");
	expected_str = regex_replace(expected_str, reg, "");

	fs.close();
	EXPECT_EQ(expected_str, actual_str);
}

TEST(¹2, TestName2) {

	fstream fs;
	fs.open("Test2.txt", fstream::in | fstream::out | fstream::app);

	string expected_str; 
	/*
		"In England the first of April is a very special day.
		This is the day when people make April’s Fools. "
	*/ 

	string actual_str = "In England first of April is a very special day. This is day when people make April Fools. ";

	File_Fill(expected_str, fs);

	regex reg("the ");
	expected_str = regex_replace(expected_str, reg, "");

	fs.close();
	EXPECT_EQ(expected_str, actual_str);
}

TEST(¹3, TestName3) {

	fstream fs;
	fs.open("Test3.txt", fstream::in | fstream::out | fstream::app);

	string expected_str;
	/*
		"OOP OOP OOP OOP OOP OOP OOP "
	*/

	string actual_str = "";

	File_Fill(expected_str, fs);

	regex reg("OOP ");
	expected_str = regex_replace(expected_str, reg, "");

	fs.close();
	EXPECT_EQ(expected_str, actual_str);
}

TEST(¹4, TestName4) {

	fstream fs;
	fs.open("Test4.txt", fstream::in | fstream::out | fstream::app);

	string expected_str;
	/*
		"a b c d e f g "
	*/

	string actual_str = "abcdefg";

	File_Fill(expected_str, fs);

	regex reg(" ");
	expected_str = regex_replace(expected_str, reg, "");

	fs.close();
	EXPECT_EQ(expected_str, actual_str);
}

TEST(¹5, TestName5) {

	fstream fs;
	fs.open("Test5.txt", fstream::in | fstream::out | fstream::app);

	string expected_str;
	/*
		"Im Stuuuuuuuuuuuuuuuudent "
	*/

	string actual_str = "Im Stdent ";

	File_Fill(expected_str, fs);

	regex reg("u");
	expected_str = regex_replace(expected_str, reg, "");

	fs.close();
	EXPECT_EQ(expected_str, actual_str);
}