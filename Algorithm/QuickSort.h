#pragma once
#include <functional>
#include "RandomNumberGen.h"

template <typename Container, typename Comparator>
size_t Partion(Container& container, size_t begin, size_t end, Comparator compare)
{
	size_t pivotIndex = CreatePseudoRandomNumberGen(begin, end)();
	std::swap(container[begin], container[pivotIndex]);
	size_t start = begin;
	size_t partionIndex = start;
	for (size_t i = partionIndex + 1; i <= end; i++)
	{
		if (compare(container[i], container[start]))
		{
			std::swap(container[i], container[++partionIndex]);
		}
	}
	std::swap(container[start], container[partionIndex]);
	return partionIndex;
}

template <typename Container, typename Comparator = std::less<>>
void QuickSort(Container& container, size_t begin, size_t end, Comparator compare = std::less<>{})
{
	if (begin < end)
	{
		size_t partionIndex = Partion(container, begin, end, compare);
		if (begin < partionIndex)
		{
			QuickSort(container, begin, partionIndex - 1, compare);
		}
		if (partionIndex < end)
		{
			QuickSort(container, partionIndex + 1, end, compare);
		}
	}
	
}

template <typename Container, typename Comparator = std::less<>>
void QuickSort(Container& container, Comparator compare = std::less<>{})
{
	QuickSort(container, 0, container.size() - 1, compare);
}
