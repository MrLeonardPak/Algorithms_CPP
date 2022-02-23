#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void MergeSort(int* buf, size_t bLen);
void Merge(int* firstBuf, size_t firstLen, int* secondBuf, size_t secondLen, int* out);

const size_t n = 10;
int a[n];

int main()
{
    srand(time(NULL) / 3600);
    
    
    for (auto&& m : a)
    {
        m = rand() % 100;
    }
    for (const auto& m : a)
    {
        cout << m << " ";
    }
    cout << endl;

    MergeSort(a, n);
    
    for (const auto& m : a)
    {
        cout << m << " ";
    }

    return 0;
}

void MergeSort(int buf[], size_t bLen)
{
    if (bLen <= 1) return;
    size_t firstLen = bLen / 2;
    size_t secondLen = bLen - firstLen;
    MergeSort(buf, firstLen);
    MergeSort(buf + firstLen, secondLen);
    int* tmp = new int[bLen];
    Merge(buf, firstLen, buf + firstLen, secondLen, tmp);
    memcpy(buf, tmp, sizeof(int) * bLen);
    delete[] tmp;
}

void Merge(int* firstBuf, size_t firstLen, int* secondBuf, size_t secondLen, int* out)
{
    for (size_t i = 0, f = 0, s = 0; (f < firstLen) || (s < secondLen); ++i)
    {
        if (f >= firstLen)
        {
            out[i] = secondBuf[s++];
        } else if (s >= secondLen)
        {
            out[i] = firstBuf[f++];
        } else 
        {
            out[i] = (firstBuf[f] > secondBuf[s]) ? (secondBuf[s++]) : (firstBuf[f++]);
        }
    }
}