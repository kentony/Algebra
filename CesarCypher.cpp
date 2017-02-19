#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;


int gcd(int a, int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}


char crypto_function(const char C, long & input_size, int n, int k) {
	char result = (C * n + k) % input_size;
	//char result = C ^ n;
	return result;
}

char de_crypto_function(const char C, long & input_size, int n, int k) {
	char result = ((C - 4)*(5^(-1))) % input_size;
	//char result = C ^ n;
	return result;
}


void read_file(const char * path, unsigned char* & temp, long & input_size) {
	ifstream in(path, ios::in);
	in.seekg(0, in.end);
	input_size = in.tellg();
	in.seekg(0, in.beg);

	if (input_size > 0) {
		char* file = new char[input_size];
		in.read(file, input_size);
		temp = new unsigned char[input_size];
		for (long i = 0; i < input_size; i++) {
			temp[i] = file[i];
		}
		delete[] file;
	}
	in.close();
}

void write_file(const char * path, unsigned char* file, long & input_size, int n, int k) {
	ofstream output(path, ios::out);
	for (long i = 0; i < input_size - 2; i++) { // КОСТЫЛЬ. НИХРЕНА НЕ ПОНЯТНО ПОЧЕМУ "- 2".
		output << crypto_function(file[i], input_size, n, k);
	}
	output.flush();
	output.close();
}

void decode_write_file(const char * path, unsigned char* file, long & input_size, int n, int k) {
	ofstream output(path, ios::out);
	for (long i = 0; i < input_size; i++) {
		output << crypto_function(file[i], input_size, n, k);
	}
	output.flush();
	output.close();
}


int main() {
	
	unsigned char * temp;
	long input_size;
	
	char * input_path = "input.txt";
	char * output_path = "output.txt";
	char * reoutput_path = "reoutput.txt";

	read_file(input_path, temp, input_size);
	
	bool correct = false;
	int n, k;
	while (!correct) {
		cout << "Enter N and K" << endl;
		cin >> n >> k;
		if (gcd(n, input_size) == 1) break;
		cout << "Not correct: GCD != 1\nRe-";
	}
	cout << "Message Length: " << input_size << endl;
	cout << "You wrote correct N and K\n";
	write_file(output_path, temp, input_size, n, k);
	
	//try to decode
	read_file(output_path, temp, input_size);
	decode_write_file(reoutput_path, temp, input_size, n, k);


	return 0;
}
