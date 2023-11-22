#include "Sorts.cpp"

#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>
#include <vector>


//Generate "size" integers in range [a, b] (distribution is discrete uniform)
void genUniformIntegers(std::vector<int>& ar, int size, int a = 0, int b = 1)
{
	std::minstd_rand engine; //generates integers in range [1, 2147483646 = 2^31 - 2]
	engine.seed(std::time(nullptr));
	

	ar.clear();

	for (int i = 1; i <= size; ++i)
	{
		int newNum = a + round((engine() - 1) * 1.0 / (engine.max() - 1) * (b - a));
		ar.push_back(newNum);
	}
}


//Print sequence of T type elements
template<typename T>
void printSequence(std::vector<T> ar)
{
	std::cout << "\n";

	if (ar.size() > 20)
	{
		for (int i = 0; i < 6; ++i)
		{
			std::cout << std::setw(5) << std::setiosflags(std::ios_base::left) << ar[i];
		}

		std::cout << std::setw(5) << "...";

		for (int i = ar.size() - 6; i < ar.size(); ++i)
		{
			std::cout << std::setw(5) << std::setiosflags(std::ios_base::left) << ar[i];
		}
	}
	else
	{
		for (int i = 0; i < ar.size(); ++i)
		{
			std::cout << std::setw(5) << std::setiosflags(std::ios_base::left) << ar[i];
		}
	}

	std::cout << "\n";
}


int main()
{
	int n; //quantity of numbers to be sorted
	int left_b, right_b; //left and right boundaries of segment

	std::vector<int> ar;

	std::minstd_rand engine;
	engine.seed(std::time(nullptr));

	std::cout << "------------------------Testing of sort methods------------------------\n\n";

	std::cout << "How many numbers you want to generate?\n\n";
	std::cout << "-> ";
	std::cin >> n;

	std::cout << "\nInput boundary values:\n\n";
	std::cout << "Left boundary: ";
	std::cin >> left_b;
	std::cout << "Right boundary: ";
	std::cin >> right_b;

	genUniformIntegers(ar, n, left_b, right_b);

	std::cout << "\nGenerated sequence:\n";
	printSequence(ar);
	std::cout << "\n-------------------------------------------------\n";

	int choice = 0; //number corresponding to sort method that user chose
	int start_time, end_time;


	while (choice == 0)
	{
		std::cout << "\nChoose sort method:\n";
		std::cout << "1 - Bubble sort\n";
		std::cout << "2 - Insertion sort\n";

		std::cout << "\n-> ";
		std::cin >> choice;

		switch (choice)
		{
			case 1:
			{
				start_time = clock();
				bubbleSort(ar);
				end_time = clock();
				break;
			}
			case 2:
			{
				start_time = clock();
				insertionSort(ar);
				end_time = clock();
				break;
			}
			default:
			{
				std::cout << "\nInvalid input! Please try again.\n";
				choice = 0;
			}
		}
	}

	std::cout << "\n-------------------------------------------------\n";
	std::cout << "\nSorted sequence:\n";
	printSequence(ar);

	std::cout << "\nSort time: " << (end_time - start_time) * 1.0 / 1000 << " s";

	std::cout << "\n\n\n";

	return 0;
}