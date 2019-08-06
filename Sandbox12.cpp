//Name: Ethan Thomas
//Class: CS 131 Section A
//Description: This program reads into 2 different employee data
//files and outputs them to the user in descending order based
//total hours worked in one week. It does this action one 
//file at a time.



#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
//This function reads into a file and stores the data in
//two different arrays depending on the data type
void read(ifstream & fin, string Emp_Names[], int size,int Emp_Hours[][8]); 

//This funtion will sort the arrays in descending order
//of total hours in a week(Most Hours to Least).
void sort(string Emp_Names[], int size, int Emp_Hours[][8]);

//This funtion will output the arrays to the user
void output(string Emp_Names[], int size, int Emp_Hours[][8]);
int main()
{
	string Emp_Names[50] = { "" };
	int Emp_Hours[50][8] = { 0 };
	ifstream fin;
	string user_input = "";

	fin.open("empdata3.txt");
	
	while (fin.fail())
	{
		cout << "Unable to find the input file." << endl;
		cout << "Would you like to try to access employee files again?"
			 << "If Yes enter Y otherwise enter N to exit program:";
		cin >> user_input;
		if (user_input == "N")
		{
			exit(0);
		}
		else
		{
			fin.close();
			fin.clear();
			fin.open("empdata3.txt");			
		}
	}
	
	read(fin, Emp_Names, 15,Emp_Hours);
	sort(Emp_Names, 15, Emp_Hours);
	output(Emp_Names, 15, Emp_Hours);
	system("pause");
	
	system("CLS");
	fin.close();
	fin.clear();
	fin.open("empdata4.txt");
	
	while (fin.fail())
	{
		cout << "Unable to find the input file." << endl;
		cout << "Would you like to try to access employee files again?"
			<< "If Yes enter Y otherwise enter N to exit program:";
		cin >> user_input;
		if (user_input == "N")
		{
			exit(0);
		}
		else
		{
			fin.close();
			fin.clear();
			fin.open("empdata3.txt");
		}
	}	
	
	read(fin, Emp_Names, 30, Emp_Hours);
	sort(Emp_Names, 30, Emp_Hours);
	output(Emp_Names, 30, Emp_Hours);
	fin.close();
	
	system("pause");
    return 0;
}

void read(ifstream &fin, string Emp_Names[], int size, int Emp_Hours[][8])
{
	int total;
	
	fin >> size;

	for (int i = 0; i < size; ++i)
	{
		fin >> Emp_Names[i];
		total = 0;

		for (int j = 0; j < 7; ++j)
		{
			fin >> Emp_Hours[i][j];
			total += Emp_Hours[i][j];
		}
		Emp_Hours[i][7] = total;
	}
}

void sort(string Emp_Names[], int size, int Emp_Hours[][8])
{
	bool flag = true;
	while (flag)
	{
		flag = false;
		for (int i = 0; i < size-1; i++)
		{
			if (Emp_Hours[i + 1][7] > Emp_Hours[i][7])
			{
				flag = true;
				for (int x = 0; x < 8; x++)
				{
					swap(Emp_Hours[i][x], Emp_Hours[i + 1][x]);
				}
				swap(Emp_Names[i], Emp_Names[i + 1]);
			}
		}
	}	
}

void output(string Emp_Names[], int size, int Emp_Hours[][8])
{
	cout << "Employee Weekly Hours:" << endl;
	cout << setw(8) << left << "Name:"<< setw(16) 
		<< right << "S" << setw(8) << right << "M" << setw(8) 
		<< right <<  "T"<< setw(8) << right << "W" << setw(8) 
		<< right << "TH" << setw(8) << right << "F" << setw(8) 
		<< right << "S"<< setw(8) << right << "TTL" << endl;
	for (int i = 0; i < size; ++i)
	{
		cout << Emp_Names[i] << "\t";
		for (int j = 0; j < 8; ++j)
		{
			cout << setw(8) << right << Emp_Hours[i][j];
		}
		cout << endl;
	}
}

//Output:
//Employee Weekly Hours :
//Name:                  S       M       T       W      TH       F       S     TTL
//Kirk, James            10      10       0      10      12       0       0      42
//Bosco, Sam              7       3       8       7       2       5       7      39
//Rugg, James             7       3       8       7       2       5       7      39
//VanPelt, Grace          5       6       5       6       5       6       5      38
//Peters, Greg            5       6       5       6       5       6       5      38
//Jane, Patrick           9       3       7       5       8       0       0      32
//Lisbon, Teresa          2       3       8       3       6       3       5      30
//Rigsby, Wayne           9      10       4       7       0       0       0      30
//Lilly, Jack             2       3       8       3       6       3       5      30
//Theiss, Bill            9      10       4       7       0       0       0      30
//Cho, Kimball            8       8       3       0       8       2       0      29
//Daniels, Carl           8       8       3       0       8       2       0      29
//Minelli, Virgil         2       5       3       0       4       9       4      27
//McCoy, Lenard           0       4       0       8       4       0       2      18
//Scott, Annis            1       6       2       0       0       1       0      10

//Employee Weekly Hours :
//Name:                  S       M       T       W      TH       F       S     TTL
//Kirk, James            10      10       0      10      12       0       0      42
//Ryan, Kevin             5       6       7       6       5       6       5      40
//Leslie, Eddie           5       6       5       6       7       6       5      40
//Uhura, Nyota           10      10       0       8      12       0       0      40
//Bosco, Sam              7       3       8       7       2       5       7      39
//Rugg, James             7       3       8       7       2       5       7      39
//Chekov, Pavel           7       3       8       7       2       5       7      39
//VanPelt, Grace          5       6       5       6       5       6       5      38
//Peters, Greg            5       6       5       6       5       6       5      38
//Parish, Lanie           7       3       8       6       2       5       7      38
//Esposito, Javier        2       5       3       9       4       9       4      36
//Beckett, Kate           2       8       8       3       6       3       5      35
//Galloway, David         9      10       4       8       0       0       2      33
//Jane, Patrick           9       3       7       5       8       0       0      32
//Castle, Richard         4       3       7       5       8       0       5      32
//Sulu, Hikaru            2       3       8       5       6       3       5      32
//Lisbon, Teresa          2       3       8       3       6       3       5      30
//Rigsby, Wayne           9      10       4       7       0       0       0      30
//Lilly, Jack             2       3       8       3       6       3       5      30
//Theiss, Bill            9      10       4       7       0       0       0      30
//Montgo, Roy             9       2       4       7       0       0       8      30
//Cho, Kimball            8       8       3       0       8       2       0      29
//Daniels, Carl           8       8       3       0       8       2       0      29
//Rodgers, Martha         8       7       3       0       8       2       0      28
//Minelli, Virgil         2       5       3       0       4       9       4      27
//Chapel, Christine       1       6       2       8       9       1       0      27
//Kyle, John              8       8       3       0       2       2       0      23
//McCoy, Lenard           0       4       0       8       4       0       2      18
//Rand, Janice            0       4       0       8       3       0       2      17
//Scott, Annis            1       6       2       0       0       1       0      10
