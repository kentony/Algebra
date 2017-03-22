#include <iostream>
#include <fstream>
#include <conio.h>
#include <stack>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int main()
{
    string alph = "abcdefghijklmnopqrstuvwxyz1234567890!#$%&'()*+,-./";
    int m = 50;
    int code;
    cout << "input : 1 - code, 2 - decode " << endl;
    cin >> code;

    int k, n, A, B;
    cin >> k;
    cin >> n;

    string str;
    cin >> str;
    if (code == 1)
    {
        string s1 = "";
        for (int i = 0; i < str.length(); i++)
        {
            for (int j = 0; j < alph.size(); j++)
                if (str[i] == alph[j]){
                    A = j;
                    B = (A * n + k) % m;
                    s1 += alph[B];
                    break;
                }
        }
        cout << s1;
    }

    if (code == 2)
    {
        int x = 0;
        while ((((n * x) % m) - 1) != 0)
            x++;
        string s1 = "";
        for (int i = 0; i < str.length(); i++)
        {
            for (int j = 0; j < alph.size(); j++)
                if (str[i] == alph[j]){
                    B = j;
                    A = (((B - k + m) % m) * x) % m;
                    s1 += alph[A];
                    break;
                }
        }
        cout << s1;
    }
    system("pause");
    return 0;
}
