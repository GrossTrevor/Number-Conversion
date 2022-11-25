#pragma once
#include <iostream>
#include <iomanip>
#include <string>
using std::string;
using std::cout;
using std::to_string;

class Color {
	string name;
	string hex;
	unsigned char red;
	unsigned char green;
	unsigned char blue;

public:
	Color() {
		name = "";
		hex = "0x";
		red = 0;
		green = 0;
		blue = 0;
	}
	void SetValue(int v) {
		
		//Setting RGB
		int temp = 0;
		temp = v >> 16;
		red = (unsigned char)(temp & 255);

		temp = v >> 8;
		green = (unsigned char)(temp & 255);

		temp = v;
		blue = (unsigned char)(temp & 255);

		//Creating and setting Hex
		int hex1;
		int hex2;
		hex1 = (int)red / 16;
		hex2 = (int)red % 16;
		HexAppend(hex1, hex2);

		hex1 = (int)green / 16;
		hex2 = (int)green % 16;
		HexAppend(hex1, hex2);

		hex1 = (int)blue / 16;
		hex2 = (int)blue % 16;
		HexAppend(hex1, hex2);
	}
	void HexAppend(int h1, int h2) {
		string ha1;
		string ha2;
		if (h1 <= 9)
			ha1 = to_string(h1);
		if (h2 <= 9)
			ha2 = to_string(h2);
		if (h1 > 9) {
			if (h1 == 10)
				ha1 = "A";
			else if (h1 == 11)
				ha1 = "B";
			else if (h1 == 12)
				ha1 = "C";
			else if (h1 == 13)
				ha1 = "D";
			else if (h1 == 14)
				ha1 = "E";
			else if (h1 == 15)
				ha1 = "F";
		}
		if (h2 > 9) {
			if (h2 == 10)
				ha2 = "A";
			else if (h2 == 11)
				ha2 = "B";
			else if (h2 == 12)
				ha2 = "C";
			else if (h2 == 13)
				ha2 = "D";
			else if (h2 == 14)
				ha2 = "E";
			else if (h2 == 15)
				ha2 = "F";
		}
		hex += ha1 + ha2;
	}
	void SetName(const string n) {
		name = n;
	}
	unsigned char GetR() const {
		return red;
	}
	unsigned char GetG() const {
		return green;
	}
	unsigned char GetB() const {
		return blue;
	}
	string GetHexValue() const {
		return hex;
	}
	string GetName() const {
		return name;
	}
};