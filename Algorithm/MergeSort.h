#pragma once
#include <functional>

template <typename Container, typename Comparator>
void Merge(Container& container, size_t begin, size_t mid, size_t end, Comparator compare)
{
	size_t leftIndex = begin;
	size_t rightIndex = mid + 1;
	
	if (compare(container[mid], container[rightIndex]))
	{
		// Both halves are sorted by definition
		return;
	}
	else
	{
		while (leftIndex <= mid && rightIndex <= end)
		{
			if (compare(container[leftIndex], container[rightIndex]))
			{
				leftIndex++;
			}
	 		else
			{
				typename Container::value_type tempValue = container[rightIndex];
				size_t tempIndex = rightIndex;
				while (tempIndex != leftIndex)
					{
						// Shift all elements in range [leftIndex, rightIndex) +1 right
						container[tempIndex] = container[tempIndex - 1];
						tempIndex--;
					}
				// Move indexes forward
				container[tempIndex] = tempValue;
				leftIndex++;
				mid++;
				rightIndex++;
			}
		}
	}
}

template <typename Container, typename Comparator = std::less<>>
void MergeSort(Container& container, size_t begin, size_t end, Comparator compare = std::less<>{})
{
	if (begin < end)
	{
		size_t mid = (begin + end) / 2;
		MergeSort(container, begin, mid, compare);
		MergeSort(container, mid + 1, end, compare);
		Merge(container, begin, mid, end, compare);
	}
}

template <typename Container, typename Comparator = std::less<>>
void MergeSort(Container& container, Comparator compare = std::less<>{})
{
	MergeSort(container, 0, container.size() - 1, compare);
}
