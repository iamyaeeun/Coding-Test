#include <iostream>
using namespace std;

int Max(int a, int b) {
	return (a > b) ? a : b;
}

int main() {
	int A[1001];
	int dp[1001];
	int ans = 0;
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	for (int i = 1; i <= N; i++) {
		dp[i] = 1;
		for (int j = i - 1; j >= 1; j--) {
			if (A[i] > A[j]) {
				dp[i] = Max(dp[i], dp[j] + 1);
			}
		}
		ans = Max(ans, dp[i]);
	}
	cout << ans;

	return 0;
}
