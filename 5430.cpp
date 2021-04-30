#include <iostream>
#include <string>
#include <deque>

using namespace std;
deque<int> d;

void getDQ(string str) {
	int num = 0;
	
	for (int i = 0; i < str.size(); i++) {
		if (str[i] != '[' && str[i] != ']' && str[i] != ',' && num == 0) {
			num = str[i] - '0';
		}
		else if (str[i] != '[' && str[i] != ']' && str[i] != ',' && num != 0) {
			num *= 10;
			num += str[i] - '0';
		}
		else if ((str[i] == ',' || str[i] == ']')&&num!=0) {
			d.push_back(num);
			num = 0;
		}
	}
}

void fShowDQ() {
	if (!d.empty()) {
		cout << "[";
		while (d.size() != 1) {
			cout << d.front() << ",";
			d.pop_front();
		}
		cout << d.front() << "]\n";
	}
	else {
		cout << "[]\n";
	}
}

void rShowDQ() {
	if (!d.empty()) {
		cout << "[";
		while (d.size() != 1) {
			cout << d.back() << ",";
			d.pop_back();
		}
		cout << d.back() << "]\n";
	}
	else {
		cout << "[]\n";
	}
}

void RD(string pattern) {
	
}

int main() {
	int cycle; cin >> cycle;
	for (int i = 0; i < cycle; i++) {
		int n;
		string pattern, str;
		cin >> pattern >> n >> str;
		getDQ(str);

		bool error = false, reverse = false;
		for (int i = 0; i < pattern.size(); i++) {
			if (pattern[i] == 'R') reverse = !reverse;
			else if (pattern[i] == 'D') {
				if (d.empty()) {
					error = true;
					break;
				}

				if (reverse) d.pop_back();
				else d.pop_front();
			}
		}
		if (error) {
			cout << "error\n";
			continue;
		}
		else {
			if (reverse) rShowDQ();
			else fShowDQ();
		}

		//RD(pattern);
		d.clear();
	}
}