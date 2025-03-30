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

void heapify(vector<double>& v,int n, int i)
{
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int largest = i;
	if (l<n && v[l]>v[largest])
		largest = l;
	if (r<n && v[r]>v[largest])
		largest = r;
	if (largest != i)
	{
		swap(v[i], v[largest]);
		heapify(v,n, largest);
	}
}

void heapsort(vector<double>& v, int n)
{
	// tao max heap
	for (int i = n/2 -1; i >= 0; i--)
		heapify(v,n, i);
	for (int i = n - 1; i >= 0; i--)
	{
		swap(v[0], v[i]);
		heapify(v, i,0);
	}
}

int main()
{
	ofstream output("ThoiGianHeapSort.txt");
	output << "Thoi gian Heap Sort: " << endl;
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
		heapsort(v, 1e6);
		auto end = high_resolution_clock::now();
		duration<double, milli> time = end - start;
		output << "Test" << " " << i << ":" << " " << time.count() << " ms" << endl;
	}
}

