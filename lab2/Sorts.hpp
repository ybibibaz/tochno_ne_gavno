#pragma once
#include "Sequence.hpp"


template<class T>
Sequence<T>* ShakerSort(Sequence<T>* seq, int (*cmp)(T, T))
{
    int left = 0;
    int right = seq->GetLength() - 1;

    while (left <= right)
    {
        for (int i = left; i < right; i++)
        {
            if (cmp(seq->Get(i), seq->Get(i + 1)) == 1)  // i > i + 1
            {
                seq->Swap(i, i + 1);
                right -= 1;
            }
        }
        for (int i = right; i > left; i--)
        {
            if (cmp(seq->Get(i - 1), seq->Get(i)) == 1)
            {
                seq->Swap(i, i - 1);
                left += 1;
            }
        }
    }

    return seq;
}
