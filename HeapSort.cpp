#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void HeapSort(vector<int>& arr);

int main()
{
    srand(time(NULL) / 3600);
    const size_t n = 10;
    vector<int> a(n);
    
    for (auto&& m : a)
    {
        m = rand() % 100;
    }
    for (const auto& m : a)
    {
        cout << m << " ";
    }
    cout << endl;

    HeapSort(a);
    
    for (const auto& m : a)
    {
        cout << m << " ";
    }

    return 0;
}

void HeapSort(vector<int>& arr)
{
    make_heap(arr.begin(), arr.end());
    int tmpN = 0;
    for (size_t i = 0; i < arr.size(); ++i)
    {
        pop_heap(arr.begin(), arr.end() - i);
        ++tmpN;
    }
    cout << arr.size() << " -> " << tmpN << endl;
}