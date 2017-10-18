#pragma once

#include <iostream>
#include <string>
#include <math.h>
#include <bitset>
using namespace std; 

string intToBin(string inp) {

	signed int num;
	bitset<32> bin; // get bits and store
	string res; 
	int index = 1;

	try {
		num = stoi(inp);
		//cout << num << endl;

		for (int i = 0; i < 32; i++, index <<= 1) {
			bin[i] = (num & index) / index;
			//bin[i] = ((a > 0) ? 1 : 0);
		}

		res = bin.to_string<char, std::string::traits_type, std::string::allocator_type>();

		return res; 
	}
	catch (exception e) {
		return "error";
	}

}


string binToInt(string binInput) {
	char bin[32];
	try {
		for (int i = 0, inpCnt = (int)binInput.size()-1; i < 32; ++i, --inpCnt) {

			if (inpCnt <= 0) {
				bin[i] = '0';
			}
			else {
				bin[i] = binInput.at(inpCnt - 1);
			}

			if (bin[i] != '0' && bin[i] != '1')
				throw exception("exc");
		}

		int my_int = 0;
		for (int i = 30; i >= 0; i--)
		{
			my_int = (my_int * 2) + bin[i] - '0';

		}
		if (bin[31] == '1')
		{
			my_int = my_int + (int)pow(2, 31);
		}
		
		return to_string(my_int);
	} catch (exception e) {
		return "error";
	}
}

void floatToBin() {
	float num;
	string inp;
	int *ptr = (int*)&num;
	cout << "Enter a float value : ";
	getline(cin, inp);
	bitset<32> bin;
	int index = 1;
	try {
		num = stof(inp);
		for (int i = 0; i <= 31; i++)
		{
			bin[i] = ((*ptr)&index) / index;
			index = index * 2;
		}

		cout << bin << endl;
	}
	catch (exception e) {
		cout << "error" << endl;
	}
}

void binToFloat() {

	int s = 0;
	int e = 0;
	float m = 0;
	float res;
	cout << "Enter a number in binary :";
	string binInput;
	char bin[32];
	getline(cin, binInput);
	for (int i = 0, inpCnt = 0; i < 32; ++i, ++inpCnt) {
		if (inpCnt >= binInput.size()) {
			bin[i] = '0';
		}
		else {
			bin[i] = binInput.at(inpCnt);
		}

	}

	if (bin[0] == '1')
		s = 1;
	else
		s = 0;

	for (int j = 1; j < 9; ++j) {
		e = (e * 2) + bin[j] - '0';
	}

	for (int j = 9, i = 2; j < 32; ++j, i *= 2) {
		m += (1.0 / (float)i) * (bin[j] - '0');
	}
	cout << endl;
	cout << "Sign : " << s << endl;
	cout << "Exponent : " << e << endl;
	cout << "Mantissa : " << m << endl;
	res = (1 - (2 * s)) * (1 + m) * pow(2, (e - 127));

	cout << res << endl;
}

