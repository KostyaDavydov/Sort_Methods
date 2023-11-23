#include "Sorts.h"


template<typename T>
void bubbleSort(std::vector<T>& ar, bool asc)
{
	if (ar.size() <= 1)
		return;

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
	if (ar.size() <= 1)
		return;

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


template<typename T>
void selectionSort(std::vector<T>& ar, bool asc)
{
	if (ar.size() <= 1)
		return;

	int sz = ar.size();

	for (int i = 0; i < sz - 1; ++i)
	{
		int replaceInd = i;

		for (int j = i + 1; j < sz; ++j)
		{
			if ((asc == true) && (ar[j] < ar[replaceInd]) || (asc == false) && (ar[j] > ar[replaceInd]))
			{
				replaceInd = j;
			}
		}

		if (replaceInd != i)
		{
			T temp = ar[i];
			ar[i] = ar[replaceInd];
			ar[replaceInd] = temp;
		}
	}
}


template<typename T>
void quickSort(std::vector<T>& ar, bool asc)
{
	if (ar.size() <= 1)
		return;

	quickSortImpl(ar, 0, ar.size() - 1, asc);
}


template<typename T>
void quickSortImpl(std::vector<T>& ar, int l, int r, bool asc)
{
	if (l < r)
	{
		int p = partitionForQuickSort(ar, l, r, asc);
		quickSortImpl(ar, l, p - 1, asc);
		quickSortImpl(ar, p + 1, r, asc);
	}
}


template<typename T>
int partitionForQuickSort(std::vector<T>& ar, int l, int r, bool asc)
{
	T x = ar[r];
	int less = l;

	for (int i = l; i < r; ++i)
	{
		if ((asc == true) && (ar[i] < x) || (asc == false) && (ar[i] > x))
		{
			if (i != less) //to prevent replacing element with itself
			{
				T temp = ar[less];
				ar[less] = ar[i];
				ar[i] = temp;
			}
			less++;
		}
	}

	if (r != less) //to prevent replacing element with itself
	{
		T temp = ar[r];
		ar[r] = ar[less];
		ar[less] = temp;
	}

	return less;
}


template<typename T>
void mergeSort(std::vector<T>& ar, bool asc)
{
	if (ar.size() <= 1)
		return;

	std::vector<T> buf(ar.size());

	mergeSortImpl(ar, buf, 0, ar.size() - 1, asc);
}


template<typename T>
void mergeSortImpl(std::vector<T>& ar, std::vector<T>& buf, int l, int r, bool asc)
{
	if (l >= r)
		return;

	int m = (l + r) / 2;

	mergeSortImpl(ar, buf, l, m, asc);
	mergeSortImpl(ar, buf, m + 1, r, asc);

	int k = l;
	for (int i = l, j = m + 1; i <= m || j <= r; )
	{
		if (j > r || ((i <= m) && ((asc == true) && (ar[i] < ar[j]) || (asc == false) && (ar[i] > ar[j]))))
		{
			buf[k] = ar[i];
			i++;
		}
		else
		{
			buf[k] = ar[j];
			j++;
		}
		k++;
	}

	for (int i = l; i <= r; ++i)
	{
		ar[i] = buf[i];
	}
}