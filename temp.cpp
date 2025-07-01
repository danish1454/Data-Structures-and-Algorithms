#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

int main() {
    auto start = high_resolution_clock::now();

    // Code to measure
    for (int i = 0; i < 1000000; i++) {
        cout << i << endl;
    }

    auto end = high_resolution_clock::now();
    duration<double> elapsed = end - start;

    cout << "Total time taken: " << elapsed.count() << " seconds" << endl;
    return 0;
}
