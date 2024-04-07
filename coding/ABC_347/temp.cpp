/*
 * For testing
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> a = {1, 8, 9, 10, 100, 121};
	for (int i = 0; i < 6; i++) {
		a[i] %= 7;
		cout << a[i] << ' ';
	}
	cout << endl;
	sort(a.begin(), a.end());

	auto last = unique(a.begin(), a.end());
	a.erase(last, a.end());

	for(auto x:a) cout << x << ' ';
	cout << endl;

	return 0;
}
