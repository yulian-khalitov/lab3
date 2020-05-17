#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
#include "Graph.h"

using namespace std;

vector<vector<string>> read_csv(string file_name)
{
	fstream file;
	file.open(file_name, ios::in);
	vector<vector<string>> rows;
	int i = 0;
	string row, word;
	while (getline(file, row)) {
		stringstream ss(row);
		rows.push_back(vector<string>());
		while (getline(ss, word, ';')) rows[i].push_back(word);
		++i;
	}
	file.close();
	return rows;
}

int main()
{
	string file_name;
	cout << "Enter csv file name: ";
	cin >> file_name;
	vector<vector<string>> rows = read_csv(file_name);
	Graph g(rows);
	map<string, int> cities_map = g.get_cities_map();
	cout << "Cities:\n";
	for (auto city : cities_map) cout << city.first << "\n";
	g.Floyd();

	string dep_city;
	do
	{
		cout << "Departure city: ";
		cin >> dep_city;
	} while (cities_map.count(dep_city) == 0);

	string arr_city;
	do
	{
		cout << "Arrival city: ";
		cin >> arr_city;
	} while (cities_map.count(arr_city) == 0);
	int cost = g.cost(dep_city, arr_city);
	auto route = g.route(dep_city, arr_city);
	cout << "Route: ";
	for (auto city : route) cout << city << " ";
	cout << "\nCost: " << cost;
}