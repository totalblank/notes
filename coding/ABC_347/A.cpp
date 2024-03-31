#include <bits/stdc++.h>

int main (int argc, char *argv[]) {
	int n, k, a[110];
	std::cin >> n >> k;

	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a, a+n);

	for (int i = 0; i < n; i++) {
		if (a[i]%k == 0) {
			std::cout << a[i]/k << ' ';
		}
	}

	return 0;
}
