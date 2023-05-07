#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

int main() {
    std::chrono::time_point<std::chrono::system_clock> start, end;
	double elapsed_seconds;

    start = std::chrono::system_clock::now();

    end = std::chrono::system_clock::now();

	elapsed_seconds = duration_cast<microseconds> (end - start).count() * pow(10, -6);
	cout << "time gen: " << elapsed_seconds << endl;
    return 0;
}