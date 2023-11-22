#include "Sorts.h"


template<typename T>
void bubbleSort(std::vector<T>& ar, bool asc)
{
	int sz = ar.size();

	for (int i = 0; i < sz - 1; ++i)
	{
		for (int j = 1; j < sz - i; ++j)
		{
			if (asc == true)
			{
				if (ar[j] < ar[j - 1])
				{
					T temp = ar[j];
					ar[j] = ar[j - 1];
					ar[j - 1] = temp;
				}
			}
			else
			{
				if (ar[j] > ar[j - 1])
				{
					T temp = ar[j];
					ar[j] = ar[j - 1];
					ar[j - 1] = temp;
				}
			}
		}
	}
}


template<typename T>
void insertionSort(std::vector<T>& ar, bool asc)
{
	int sz = ar.size();

	for (int i = 1; i < sz; ++i)
	{
		T curr = ar[i];
		int j = i;

		while (j > 0 && ( (asc == true) && (ar[j - 1] > curr) || (asc == false) && (ar[j - 1] < curr) ))
		{
			ar[j] = ar[j - 1];
			j--;
		}

		ar[j] = curr;	
	}
}