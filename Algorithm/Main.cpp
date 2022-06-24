#include <iostream>
#include <vector>
#include "MergeSort.h"
#include "QuickSort.h"

template <typename Container>
void PrintContainer(const Container& container)
{
	for (const auto item : container)
	{
		std::cout << item << '\n';
	}
}


// nlogn inversion count with merge
void CountInversionsMerge(std::vector<int>& values, size_t begin, size_t mid, size_t end, size_t& count)
{
	std::vector<int> left(mid - begin + 1);
	std::vector<int> right(end - mid);
	for (size_t i = 0; i < left.size(); i++)
	{
		left[i] = values[begin + i];
	}
	for (size_t i = 0; i < right.size(); i++)
	{
		right[i] = values[mid + 1 + i];
	}
	

	size_t l = 0; 
	size_t r = 0;
	size_t i = begin;

	while (l < left.size() && r < right.size())
	{
		if (left[l] <= right[r])
		{
			values[i] = left[l++];
		}
		else
		{
			values[i] = right[r++];
			// add the remaining items 
			// in the left subarray to count
			// since right[r] is less than them
			count += left.size() - l;
		}
		i++;
	}
	while (l < left.size())
	{
		values[i] = left[l++];
	}
	while (r < right.size())
	{
		values[i] = right[r++];
	}
}

void CountInversions(std::vector<int>& values, size_t begin, size_t end, size_t& count)
{
	if (begin < end)
	{
		size_t mid = (begin + end) / 2;
		CountInversions(values, begin, mid, count);
		CountInversions(values, mid + 1, end, count);
		CountInversionsMerge(values, begin, mid, end, count);
	}
}

int main(int argc, char **argv)
{
	size_t count{};
	std::vector ints{1, 2, 3, 4, 5};
	CountInversions(ints, 0, ints.size() - 1, count);
	std::cout << count << '\n';
}