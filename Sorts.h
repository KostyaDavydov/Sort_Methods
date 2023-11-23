#pragma once


#include <iostream>
#include <vector>

template<typename T>
void bubbleSort(std::vector<T>& ar, bool asc = true);

template<typename T>
void insertionSort(std::vector<T>& ar, bool asc = true);

template<typename T>
void selectionSort(std::vector<T>& ar, bool asc = true);

template<typename T>
void quickSort(std::vector<T>& ar, bool asc = true);

template<typename T>
void quickSortImpl(std::vector<T>& ar, int l, int r, bool asc);

template<typename T>
int partitionForQuickSort(std::vector<T>& ar, int l, int r, bool asc);

template<typename T>
void mergeSort(std::vector<T>& ar, bool asc = true);

template<typename T>
void mergeSortImpl(std::vector<T>& ar, std::vector<T>& buf, int l, int r, bool asc);