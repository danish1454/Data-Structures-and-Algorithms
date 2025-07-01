#include <iostream>
using namespace std;
int updateBit(int n, int pos, int val)
{
    // Clear Bit

    n = n & ~(1 << pos);

    // Update Bit
    return (n | (val << pos));
}
int main()
{
    cout << updateBit(7, 2, 0) << endl;
    cout << updateBit(7, 3, 1) << endl;
    return 0;
}