#include <iostream>
#include <string>
using namespace std;

int main() {
	int total = 0;
	for (int i = 0; i < 5; i++) {
		string A, B;
		cin >> A >> B;
		string a, b, c, d;
		// 예시) 10:17 19:34 에서 a = 19, b = 10, c = 34, d = 17
		for (int j = 0; j < 2; j++) {
			a += B[j]; b += A[j]; c += B[j + 3]; d += A[j + 3];
		}
		// 문자열 정수로 바꿔 계산
		int e = stoi(a); int f = stoi(b); int g = stoi(c); int h = stoi(d);
		total += (e - f) * 60 + (g - h);
	}
	cout << total;

	return 0;
}
