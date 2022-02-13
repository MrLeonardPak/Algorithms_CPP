#include <iostream>

using namespace std;

void BubbleSort(int arr[], int n);

int main()
{
    srand(time(NULL) / 3600);
    const size_t n = 10;
    int a[n];
    
    for (auto&& i : a)
    {
        i = rand() % 100;
    }
    for (const auto& i : a)
    {
        cout << i << " ";
    }
    cout << endl;

    BubbleSort(a, n);
    
    for (const auto& i : a)
    {
        cout << i << " ";
    }
    
    return 0;
}

void BubbleSort(int arr[], int n)
{
    auto tmpN = 0;
    for (size_t i = n; i > 0; --i)
    {
        for (size_t j = 0; j < i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                auto tmp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = tmp;
            }
            ++tmpN;
        }
    }
    cout << n << " -> " << tmpN << endl;
}
