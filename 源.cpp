#include<iostream>
#include<string>
#include<math.h>
using namespace std;
int min(int a, int b, int c) {
	if (a < b) {
		if (a < c)return a;
		else return c;
	}
	else {
		if (b < c)return b;
		else return c;
	}
}
int main() {
	int k;
	string s1, s2;
	cin >> s1;
	cin >> s2;
	cin >> k;
	int a = s1.length();
	int b = s2.length();
	int*matrix;
	matrix = new int[b + 1];
	int*matrix2;
	matrix2 = new int[b + 1];
	for (int i = 0; i <= a; i++) {
		for (int j = 0; j <= b; j++) {
			if (i == 0 || j == 0) {
				matrix[j] = k * (i + j);
			}
			else {
				matrix[j] = min(matrix[j - 1] + k, matrix2[j] + k, matrix2[j - 1] + abs(s1[i - 1] - s2[j - 1]));
			}
		}
		for (int j = 0; j <= b; j++)
		matrix2[j] = matrix[j];
	}
	cout << matrix[b] << endl;
	return 0;
}