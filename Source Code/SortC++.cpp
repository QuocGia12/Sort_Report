#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>
#include<random>
#include<iomanip>
#include<chrono>
using namespace std;
using namespace chrono;

int main()
{
	ofstream output("ThoiGianSortC++.txt");
	output << "Thoi Gian Sort C++: " << endl;
	for (int i = 1; i <= 10; i++)
	{
		string TenFile = "Test" + to_string(i)+".txt";
		ifstream file(TenFile);
		vector<double> v;
		double x;
		while (file >> x)
		{
			v.push_back(x);
		}
		auto start = high_resolution_clock::now();
		sort(v.begin(), v.end());
		auto end = high_resolution_clock::now();
		duration<double, milli> time = end - start;
		output << "Test" << " " << i << ":" << " " << time.count() << " ms" << endl;
	}
}