#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	long long N, A, B, temp;
	vector<long long> D;
	cin >> N >> A >> B;
	for (long long i = 0; i < N; i++) {
		cin >> temp;
		temp %= (A+B);
		D.push_back(temp);
	}

	sort(D.begin(), D.end());
	auto last = unique(D.begin(), D.end());
	D.erase(last, D.end());

	long long i1, i2;
	i1 = D[0];
	i2 = D[D.size() - 1];

	if(i2-i1 < A) cout << "Yes\n";
	else cout << "No\n";

	return 0;
}
