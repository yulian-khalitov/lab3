#include "pch.h"
#include "CppUnitTest.h"
#include "../lab3sem4/Graph.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab3sem4tests
{
	TEST_CLASS(lab3sem4tests)
	{
	public:
		TEST_METHOD(graph_constructor)
		{
			std::vector<std::vector<std::string>> rows
			{ {"Saint-Petersburg", "Moscow", "10", "20"},
			{"Moscow", "Habarovsk", "40", "35"},
			{"Saint-Petersburg", "Habarovsk", "14", "N/A"},
			{ "Vladivostok", "Habarovsk", "13", "8"},
			{"Vladivostok", "Saint-Petersburg", "N/A", "40"} };
			Graph g(rows);
			std::vector<std::vector<int>> matrix{ 
				{0, 35, 100000, 8},
				{40, 0, 20, 100000},
				{14, 10, 0, 40},
				{13, 100000, 100000, 0} 
			};
			Assert::IsTrue(matrix == g.get_matrix());
		}
		TEST_METHOD(Floyd)
		{
			std::vector<std::vector<std::string>> rows
			{ {"Saint-Petersburg", "Moscow", "10", "20"},
			{"Moscow", "Habarovsk", "40", "35"},
			{"Saint-Petersburg", "Habarovsk", "14", "N/A"},
			{ "Vladivostok", "Habarovsk", "13", "8"},
			{"Vladivostok", "Saint-Petersburg", "N/A", "40"} };
			Graph g(rows);
			std::vector<std::vector<int>> matrix{
				{0, 35, 55, 8},
				{34, 0, 20, 42},
				{14, 10, 0, 22},
				{13, 48, 68, 0}
			};
			g.Floyd();
			Assert::IsTrue(matrix == g.get_matrix());
		}
		TEST_METHOD(route)
		{
			std::vector<std::vector<std::string>> rows
			{ {"Saint-Petersburg", "Moscow", "10", "20"},
			{"Moscow", "Habarovsk", "40", "35"},
			{"Saint-Petersburg", "Habarovsk", "14", "N/A"},
			{ "Vladivostok", "Habarovsk", "13", "8"},
			{"Vladivostok", "Saint-Petersburg", "N/A", "40"} };
			Graph g(rows);
			g.Floyd();
			auto route0 = g.route("Moscow", "Habarovsk");
			std::vector<std::string> route1{ "Moscow", "Saint-Petersburg", "Habarovsk" };
			Assert::IsTrue(route0 == route1);
		}
		TEST_METHOD(cost)
		{
			std::vector<std::vector<std::string>> rows
			{ {"Saint-Petersburg", "Moscow", "10", "20"},
			{"Moscow", "Habarovsk", "40", "35"},
			{"Saint-Petersburg", "Habarovsk", "14", "N/A"},
			{ "Vladivostok", "Habarovsk", "13", "8"},
			{"Vladivostok", "Saint-Petersburg", "N/A", "40"} };
			Graph g(rows);
			g.Floyd();
			int cost = g.cost("Moscow", "Habarovsk");
			Assert::IsTrue(cost == 34);
		}
	};
}
