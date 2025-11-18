// Trevor Ohlson
// Professor Fowler
// 11/18/25
// Make a Hash

#include <iostream>
#include <string>
#include <array>
#include <iomanip>
using namespace std;

class Account {
private:
	string name;
	string password;
	int hashValue;

public:
	Account(const string& n, const string& p)
		: name(n), password(p), hashValue(0) {}

	void setHash(int h) {
		hashValue = h;
	}

	string getPassword() const {
		return password;
	}
	
	int getHash() const {
		return hashValue;
	}
};

int main() {
	array<Account, 5> accounts = {
		Account("Alice",   "Dennis Sucks"),
		Account("Bob",     "Ankit Sucks"),
		Account("Charlie", "Dispatch Goated"),
		Account("Dave",    "Pee Pee Poo Poo"),
		Account("Eve",     "HEHEHE HAHA")
	};

	auto hashPassword = [](const string& str) {
		int sum = 0;
		for (char c : str) {
			sum += static_cast<int>(c);
		}
		return sum;
	};

	for (auto &acc : accounts) {
		int hashed = hashPassword(acc.getPassword());
		acc.setHash(hashed);
	}

	cout << left << setw(20) << "PASSWORD"
	     << " | "
	     << left << setw(40) << "HASH VALUE"
	     << "\n";

	cout << string(40, '-') << "\n";

	for (const auto &acc : accounts) {
		cout << left << setw(20) << acc.getPassword()
		     << " | "
		     << left << setw(40) << acc.getHash()
		     << "\n";
	}

	return 0;
}
