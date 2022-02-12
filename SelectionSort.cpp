#include <iostream>

using namespace std;

void SelectionSort(int arr[], size_t n);

int main() 
{
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

    SelectionSort(a, n);

    for (const auto& m : a)
    {
        cout << m << " ";
    }

    return 0;
}

void SelectionSort(int arr[], size_t n)
{
    int tmpN = 0;
    for (size_t i = 0; i < n - 1; i++)
    {
        int minV = arr[i];
        size_t minI = i;
        for (size_t j = i + 1; j < n; ++j)
        {
            if (arr[j] < minV)
            {
                minV = arr[j];
                minI = j;
            }
            ++tmpN;
        }
        int tmp = arr[i];
        arr[i] = arr[minI];
        arr[minI] = tmp;
    }
    cout << n << " -> " << tmpN << endl;
}