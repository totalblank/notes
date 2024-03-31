#include <iostream>
#include <set>

int main (int argc, char *argv[]) {
	std::string s;
	std::cin >> s;
	std::set<std::string> t;

	for (int i = 0; i < s.size(); i++) {
		for (int j = 1; j <= s.size() - i; j++) {
			t.insert(s.substr(i, j));
		}
	}
	std::cout<< t.size() << std::endl;

	return 0;
}
