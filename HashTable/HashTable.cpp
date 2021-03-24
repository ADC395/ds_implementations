#include <iostream>
#include <list>
#include <cstring>
#include <iterator>

// HashTable implementation - Very weak against collisions

class HashTable {
private:
	static const int hashGroups = 15;
	std::list<std::pair<int, std::string>> table[hashGroups];

public:
	bool isEmpty() const;
	bool contains(std::string value);
	int hashFunction(int key);
	int getKey(std::string value);
	std::string search(int key);
	void insert(int key, std::string value);
	void remove(int key);
	void printTable();
};

bool HashTable::isEmpty() const {
	int sum{};

	for (int i{}; i < hashGroups; i++) {
		sum += table[i].size();
	}

	if (!sum) {
		return true;
	}
	return false;
}

int HashTable::hashFunction(int key) {
	return key % hashGroups;
}

void HashTable::insert(int key, std::string value) {
	int hashValue = hashFunction(key);
	auto& cell = table[hashValue];
	auto bItr = begin(cell);
	bool keyExists = false;

	for (;bItr != end(cell); bItr++) {
		if (bItr->first == key) {
			keyExists = true;
			bItr->second = value;
			std::cout << "Key Exists. Value replaced." << std::endl;
			break;
		}
	}

	if (!keyExists) {
		cell.emplace_back(key, value);
		std::cout << "Added: " << value << std::endl;
	}

	return;
}

void HashTable::remove(int key) {
	int hashValue = hashFunction(key);
	auto& cell = table[hashValue];
	auto bItr = begin(cell);
	bool keyExists = false;

	for (;bItr != end(cell); bItr++) {
		if (bItr->first == key) {
			keyExists = true;
			bItr = cell.erase(bItr);
			std::cout << "Item Removed" << std::endl;
			break;
		}
	}

	if (!keyExists) {
		std::cout << "Item not found. Nothing removed" << std::endl;
	}

	return;
}

void HashTable::printTable() {
	for (int i{}; i < hashGroups; i++) {
		if (table[i].size() == 0) {
			continue;
		}

		auto bItr = table[i].begin();
		for (; bItr != table[i].end(); bItr++) {
			std::cout << "Key: " << bItr->first << " Value: " << bItr->second << std::endl;
		}
	}
	return;
}

int main() {
	HashTable HT;

	if (HT.isEmpty()) {
		std::cout << "Nice." << std::endl;
	}
	else {
		std::cout << "Not Nice." << std::endl;
	}

	HT.insert(26, "Bob");
	HT.insert(300, "Joe");
	HT.insert(42, "Tom");
	HT.insert(16, "Frank");
	HT.insert(5, "Steve");
	HT.insert(928, "Connor");
	HT.insert(9, "Judy");
	HT.insert(25, "Jill");

	HT.printTable();
	std::cout << std::endl;

	HT.remove(9);
	HT.remove(100);

	HT.printTable();
	std::cout << std::endl;

	if (HT.isEmpty()) {
		std::cout << "Uh Oh!" << std::endl;
	}
	else {
		std::cout << "Perfect?" << std::endl;
	}

	return 0;

}

