#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>
#include<random>
#include<iomanip>
using namespace std;

const int max = 1e6;

int main()
{
	for (int i = 1; i <= 10; i++)// i la thu tu cua test
	{
		string TenFile = "Test" + to_string(i);
		ofstream file(TenFile + ".txt");
		vector<double> v(1e6);
		mt19937 gen(time(0));
		uniform_real_distribution<double> dist(0, 1e6);
		for (int j = 0; j < 1e6; j++)
		{
			v[j] = dist(gen);
		}
		if (i == 1) sort(v.begin(), v.end());
		else if (i == 2) sort(v.begin(), v.end(), greater<double>());
		for (int j = 0; j < 1e6; j++)
		{
			if (j != 1e6) file << fixed<< setprecision(5)<< v[j] << " ";
			else file <<fixed<<setprecision(5)<< v[j];
		}
		file.close();
	}
}