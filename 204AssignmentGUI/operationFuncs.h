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
