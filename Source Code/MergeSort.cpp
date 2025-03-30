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

void merge(vector<double>& v, int l, int m, int r)
{
	vector<double> x(v.begin() + l, v.begin() + m + 1);
	vector<double> y(v.begin() + m + 1, v.begin() + r + 1);
	int i = 0;
	int j = 0;
	int n = x.size();
	int g = y.size();
	while (i < n && j < g)
	{
		if (x[i] < y[j])
		{
			v[l] = x[i];
			l++;
			i++;
		}
		else
		{
			v[l] = y[j];
			l++;
			j++;
		}
	}
	if (i<n)
	{
		while (i < n)
		{
			v[l] = x[i];
			l++;
			i++;
		}
	}
	else
	{
		while (j < g)
		{
			v[l] = y[j];
			l++;
			j++;
		}
	}
}

void mergesort(vector<double>& v, int l, int r)
{
	if (l >= r) return;
	int m = l+ (r - l) / 2;
	mergesort(v, l, m);
	mergesort(v, m + 1, r);
	merge(v, l, m, r);
}

int main()
{
	ofstream output("ThoiGianMergeSort.txt");
	output << "Thoi gian Merge Sort: " << endl;
	for (int i = 1; i <= 10; i++)
	{
		string TenFile = "Test" + to_string(i) + ".txt";
		ifstream file(TenFile);
		vector<double> v;
		double x;
		while (file >> x)
		{
			v.push_back(x);
		}
		auto start = high_resolution_clock::now();
		mergesort(v,0, 1e6-1);
		auto end = high_resolution_clock::now();
		duration<double, milli> time = end - start;
		output << "Test" << " " << i << ":" << " " << time.count() << " ms" << endl;
	}
}