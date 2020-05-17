#pragma once
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>

class Graph
{
	std::vector<std::vector<int>> matrix;
	std::vector<std::vector<int>> next;
	std::map<std::string, int> cities_map;
	std::vector<std::string> cities;
	int size;
public:
	Graph(std::vector<std::vector<std::string>>);
	void Floyd();
	std::vector<std::string> route(std::string, std::string);
	int cost(std::string, std::string);
	std::vector<std::vector<int>> get_matrix();
	std::vector<std::string> get_cities();
	std::map<std::string, int> get_cities_map();
};
