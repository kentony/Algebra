#include <iostream>
#include <io.h>
#include <fstream>
#include <vector>
#include <string>


using namespace std;


int gcd(int a, int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

int main(){
	int m = 76; //26 a 26 A 24 !~
	string alph = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!#$%&'()*+,-./";
	string word, outword;
	ifstream in;
	ofstream out;
	string input = "input.txt";
	string output = "output.txt";

	int code;
	cout << "1 - code, 2 - decode\n";
	cin >> code;

	if(code == 1){

		in.open(input);
		out.open(output);
		int n, k;
		while (true) {
			cout << "Enter N and K" << endl;
			cin >> n >> k;
			if (gcd(n, m) == 1) break;
			cout << "Not correct: GCD(" << n << ", 50) != 1\nRe-";
		}
		int A, B;
		while(!(in.eof())){
			out << " ";
			in >> word;
			outword = "";
			for(int i = 0; i < word.length(); i++){
				for (int j = 0; j < alph.size(); j++){
					if (word[i] == alph[j]){
						A = j;
						B = (A * n + k) % m;
						outword += alph[B];
						break;
					}
				}
			}
			out << outword;
		}
	}
	else{

		in.open(output);
		out.open(input);
		int n, k;
		while (true) {
			cout << "Enter N and K" << endl;
			cin >> n >> k;
			if (gcd(n, m) == 1) break;
			cout << "Not correct: GCD(" << n << ", 50) != 1\nRe-";
		}
		int x = 0;
        while ((((n * x) % m) - 1) != 0)
            x++;
		int A, B;
		while(!(in.eof())){
			out << " ";
			in >> word;
			outword = "";
			for(int i = 0; i < word.length(); i++){
				for (int j = 0; j < alph.size(); j++){
					if (word[i] == alph[j]){
						B = j;
						A = (((B - k + m) % m) * x) % m;
						outword += alph[A];
						break;
					}
				}
			}
			out << outword;
		}
	}
	return 0;
}
