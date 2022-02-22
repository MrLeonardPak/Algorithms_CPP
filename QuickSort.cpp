#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void QuickSort(int* buf, size_t len);
size_t Partition(int* buf, size_t len);

int main()
{
    srand(time(NULL) / 3600);
    const size_t n = 10;
    int a[n];
    
    for (auto&& m : a)
    {
        m = rand() % 100;
    }
    for (const auto& m : a)
    {
        cout << m << " ";
    }
    cout << endl;

    QuickSort(a, n);
    
    for (const auto& m : a)
    {
        cout << m << " ";
    }

    return 0;
}

void QuickSort(int* buf, size_t len)
{
    size_t part = Partition(buf, len);
    if (part > 0) QuickSort(buf, part);
    if (part < len - 1) QuickSort(buf + part + 1, len - (part + 1));
}

size_t Partition(int* buf, size_t len)
{
    if (len <= 1) return 0;
    const int& pivot = buf[len - 1];
    int i = 0;
    int j = len - 2;
    while (i <= j)
    {
        for (;buf[i] < pivot; ++i) {}
        for (;(j >= 0) && (buf[j] > pivot); --j) {}
        if (i < j) 
        {
            swap(buf[i++], buf[j--]);
        }
    }
    swap(buf[i], buf[len - 1]);
    return i;
}