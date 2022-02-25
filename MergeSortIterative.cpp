#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void MergeSort(int* buf, size_t bLen);
void Merge(int* firstBuf, size_t firstLen, int* secondBuf, size_t secondLen, int* out);

const size_t n = 1000;
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
    // разбили по минимальным группам
    int div = 2;
    for (; div < bLen; div *= 2)
    {
        // меняем группы
        size_t i = 0;
        for (; i < bLen / div; ++i)
        {
            int* tmp = new int[div];
            // сливаем в каждой группе
            Merge(  buf + i * div, 
                    div / 2,
                    buf + div / 2 + i * div, 
                    div / 2, 
                    tmp);
            memcpy(buf + i * div, tmp, sizeof(int) * div);
            delete[] tmp;
        }
        if (bLen % div != 0)
        {
            size_t secondLen, firstLen = div / 2;
            size_t firstIx = i * div;
            size_t secondIx = firstIx + firstLen;
            
            if (secondIx < bLen)    
            {
                secondLen = bLen - secondIx;
                int* tmp = new int[firstLen + secondLen];
                
                // сливаем в каждой группе
                Merge(  buf + firstIx, 
                        firstLen,
                        buf + secondIx, 
                        secondLen, 
                        tmp);
                memcpy(buf + i * div, tmp, sizeof(int) * (firstLen + secondLen));
                delete[] tmp;
            }
        }
        
    }
    if (bLen % div != 0)
    {
        int* tmp = new int[bLen];
        // сливаем в каждой группе
        Merge(  buf, 
                div / 2,
                buf + div / 2, 
                bLen - div / 2, 
                tmp);
        memcpy(buf, tmp, sizeof(int) * bLen);
        delete[] tmp;
    }
}
/**
 * @brief Функция слияния
 * 
 * @param firstBuf 
 * @param secondBuf 
 * @param len - длина каждого полубуфера (одинаковая)
 * @param out 
 */
void Merge(int* firstBuf, size_t firstLen, int* secondBuf, size_t secondLen, int* out)
{
    for (int i = 0, s = 0, f = 0; (f < firstLen) || (s < secondLen); ++i)
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