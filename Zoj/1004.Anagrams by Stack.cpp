#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

stack <string> AAA;

void DFS(string &a, string &b, char * ans, int index, int o, int i, int lena, int lenb, stack <char> &temp) {
	if (o == lenb) {
		ans[index] = 0;
		string AA;
		AA.resize(2 * (o + i));
		int now = 0;
		for (int ii = 0; ii < o + i; ++ii) {
			AA[now++] = ans[ii];
			AA[now++] = ' ';
		}
		AAA.push(AA);
		return;
	}
	if (temp.top() == b[o]) {
		ans[index++] = 'o';
		char n = temp.top();
		temp.pop();
		DFS(a, b, ans, index, o + 1, i, lena, lenb, temp);
		index--;
		temp.push(n);
	}
	if (i < lena) {
		ans[index++] = 'i';
		temp.push(a[i]);
		DFS(a, b, ans, index, o, i + 1, lena, lenb, temp);
		temp.pop();
	}
}

int main(int argc, char * argv[]) {
	std::ios::sync_with_stdio(false);
	string a, b;
	while (cin >> a >> b) {
		stack <char> temp;
		int lena = a.length();
		int lenb = b.length();
		temp.push('-');
		char * ans = new char[2 * lena]();
		//      for (int i = 0; i < lena; ++i) {
		//          ans[i] = 'i';
		//          temp.push(a[i]);
		//      }
		cout << "[\n";
		if (lena >= lenb) {
			DFS(a, b, ans, 0, 0, 0, lena, lenb, temp);
		}
		while (!AAA.empty()) { cout << AAA.top() << '\n'; AAA.pop(); }
		delete[] ans;
		cout << "]\n";
	}
	return 0;
}