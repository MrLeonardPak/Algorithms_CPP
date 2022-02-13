#include <iostream>

using namespace std;

void InsertionSort(int arr[], size_t n);

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

    InsertionSort(a, n);
    
    for (const auto& m : a)
    {
        cout << m << " ";
    }

    return 0;
}

void InsertionSort(int arr[], size_t n)
{
    int tmpN = 0;
    for (size_t i = 1; i < n; ++i)
    {
        int tmpV = arr[i];
        int tmpI = i - 1;

        for (; (tmpI >= 0) && (arr[tmpI] > tmpV); --tmpI)
        {
            arr[tmpI + 1] = arr[tmpI];
            ++tmpN;
        }

        if (tmpI != i - 1)
        {
            arr[tmpI + 1] = tmpV; 
        } else
        {
            ++tmpN;
        }
    }
    cout << n << " -> " << tmpN << endl;
}