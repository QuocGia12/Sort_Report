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

#include <vector>
#include <algorithm>
using namespace std;

int partition(vector<double>& v, int l, int r) {
    double pivot = v[l + (r - l) / 2];  
    int i = l - 1;  
    int j = r + 1;  
    while (true) {
        do {
            i++;
        } while (v[i] < pivot); 
        do {
            j--;
        } while (v[j] > pivot); 
        if (i >= j) {
            return j;
        }
        swap(v[i], v[j]);
    }
}

void quicksort(vector<double>& v, int l, int r)
{
	if (l >= r) return;
	int p = partition(v, l, r);
	quicksort(v, l, p );
	quicksort(v, p + 1, r);
}

int main()
{
	ofstream output("ThoiGianQuickSort.txt");
	output << "Thoi gian Quick Sort: " << endl;
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
		quicksort(v,0,1e6-1);
		auto end = high_resolution_clock::now();
		duration<double, milli> time = end - start;
		output << "Test" << " " << i << ":" << " " << time.count() << " ms" << endl;
	}
}
