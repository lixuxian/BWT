#include "BWT/BWT.h"

#include <iostream>
#include <string>
#include <vector>
#include <forward_list>

using namespace std;

int main() {
	string message = "Alice is the best!";

	cout << message << '\n';

	string encoding = BWT_encode(message);

	cout << encoding << '\n';

	forward_list<char> alphabet;
	for (char i = 32; i <= 126; i++) {
		//' ' to '~'
		alphabet.push_front(i);
	}

	vector<int> MTF_encoding = MTF_encode(encoding, alphabet);

	for (vector<int>::iterator it = MTF_encoding.begin(); MTF_encoding.end() != it; it++) {
		cout << *it << " ";
	}

	cout << '\n';

	RLE_encoding RLE_code;
	RLE_encode(RLE_code, MTF_encoding);
	RLE_code.close();

	cout << '\n' << RLE_code.get_offset() << endl;

	vector<int> RLE_decoding = RLE_decode(RLE_code);

	for (vector<int>::iterator it = RLE_decoding.begin(); RLE_decoding.end() != it; it++) {
		cout << *it << " ";
	}

	cout << '\n';

	/*
	string MTF_decoding = MTF_decode(RLE_decoding, alphabet);

	cout << MTF_decoding << '\n';

	string source = BWT_decode(MTF_decoding);

	cout << source << endl;
	*/
	return 0;
}