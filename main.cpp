#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <map>
#include "Color.h"
using namespace std;

void ReadFile(const char* filename, map<string, Color>& colors);
void PrintColors(const map<string, Color>& colors);
void PrintColor(const Color& color);
void SearchForColor(map<string, Color>& colors);

int main()
{
	cout << "1-6: Load colors1/2/3/4/5/6.txt" << endl;
	cout << "7. Load all 6 files" << endl;
	int choice;
	cin >> choice;

	map<string, Color> colors;
	if (choice >= 1 && choice <= 6)
	{
		string file = "colors" + to_string(choice) + ".txt";
		ReadFile(file.c_str(), colors);
	}
	else if (choice == 7)
	{
		for (int i = 1; i <= 6; i++)
		{
			string file = "colors" + to_string(i) + ".txt";
			ReadFile(file.c_str(), colors);
		}

	}

	// Secondary menu
	cout << "1. Show all colors" << endl;
	cout << "2. Search for a color" << endl;
	cin >> choice;

	if (choice == 1)
		PrintColors(colors);
	else if (choice == 2)
		SearchForColor(colors);
	return 0;
}

void ReadFile(const char* filename, map<string, Color>& colors)
{
	ifstream file(filename);
	string name = "";
	string value = "";
	string line = "";

	while (getline(file, line)) {
		name = line.substr(0, line.find(" ", 0));
		value = line.substr(line.find(" ", 0));
		Color color;
		color.SetName(name);
		color.SetValue(stoi(value));
		colors.emplace(color.GetName(), color);
	}
	file.close();
}
void PrintColors(const map<string, Color>& colors)
{
	auto itr = colors.begin();
	int count = 0;
	for (; itr != colors.end(); itr++) {
		PrintColor(itr->second);
		count++;
	}
	cout << "Number of colors: " << count;
}
void PrintColor(const Color& color)
{
	cout << left << setw(20) << color.GetName();
	cout << right << setw(10) << color.GetHexValue();
	cout << "\t\t" << (int)color.GetR() << "," << (int)color.GetG() << "," << (int)color.GetB() << endl;
}
void SearchForColor(map<string, Color>& colors)
{
	string term = "";
	bool found = false;
	cin >> term;
	auto itr = colors.begin();
	for (; itr != colors.end(); itr++) {
		if (itr->first == term) {
			PrintColor(itr->second);
			found = true;
		}
	}
	if (found == false)
		cout << term << " not found!";
}