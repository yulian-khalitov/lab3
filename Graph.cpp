#include "Graph.h"

Graph::Graph(std::vector<std::vector<std::string>> rows)
{
	for (auto row : rows) cities_map[row[0]] = cities_map[row[1]] = 0;
	int i = 0;
	for (auto& city : cities_map) city.second = i++;
	size = cities_map.size();
	matrix = std::vector<std::vector<int>>(size, std::vector<int>(size, 100000));
	next = std::vector<std::vector<int>>(size, std::vector<int>(size, -1));
	for (auto row : rows)
	{
		int i = cities_map[row[0]];
		int j = cities_map[row[1]];
		if (row[2] != "N/A")
		{
			matrix[i][j] = stoi(row[2]);
			next[i][j] = j;
		}
		if (row[3] != "N/A")
		{
			matrix[j][i] = stoi(row[3]);
			next[j][i] = i;
		}
	}
	for (int i = 0; i < size; ++i)
	{
		matrix[i][i] = 0;
		next[i][i] = i;
	}
	cities = std::vector<std::string>(cities_map.size());
	for (auto& city : cities_map) cities[city.second] = city.first;
}

void Graph::Floyd()
{
	for (int k = 0; k < size; ++k)
		for (int i = 0; i < size; ++i)
			for (int j = 0; j < size; ++j)
			{
				if (matrix[i][j] > matrix[i][k] + matrix[k][j])
				{
					matrix[i][j] = matrix[i][k] + matrix[k][j];
					next[i][j] = next[i][k];
				}
			}
}

std::vector<std::string> Graph::route(std::string dep_city, std::string arr_city)
{
	std::vector<std::string> path;
	int dep = cities_map[dep_city];
	int arr = cities_map[arr_city];
	if (next[dep][arr] == -1) return path;
	path.push_back(cities[dep]);
	while (dep != arr)
	{
		dep = next[dep][arr];
		path.push_back(cities[dep]);
	}
	return path;
}

std::vector<std::vector<int>> Graph::get_matrix()
{
	return matrix;
}

std::vector<std::string> Graph::get_cities()
{
	return cities;
}

std::map<std::string, int> Graph::get_cities_map()
{
	return cities_map;
}

int Graph::cost(std::string dep, std::string arr)
{
	return matrix[cities_map[dep]][cities_map[arr]];
}
