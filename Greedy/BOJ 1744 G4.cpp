#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int twosum(vector<int>& a) {
	int asize = a.size(), result = 0;
	if (asize % 2 == 0) {
		for (int i = 0; i < asize; i += 2) {
			if (a[i] * a[i + 1] > a[i] + a[i + 1]) result += a[i] * a[i + 1];
			else result += a[i] + a[i + 1];
		}
	}
	else {
		for (int i = 0; i < asize - 1; i += 2) {
			if (a[i] * a[i + 1] > a[i] + a[i + 1]) result += a[i] * a[i + 1];
			else result += a[i] + a[i + 1];
		}
		if (a[asize - 1] > 0) result += a[asize - 1];
	}
	return result;
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,num,sum = 0;
	cin >> n;
	vector<int> zero,minus,plus;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num == 0) zero.push_back(num);
		else if (num > 0) plus.push_back(num);
		else minus.push_back(num);
	}
	sort(plus.rbegin(), plus.rend());
	sort(minus.begin(), minus.end());
	sum += twosum(plus);
	sum += twosum(minus);
	if (minus.size() % 2 == 1) {
		if (zero.empty()) sum += minus[minus.size() - 1];
	}
	cout << sum;
}