//
//  sort.h
//  
//  Functions for merge sort, quicksort, and a hybrid sort.
//  You SHOULD modify this file.
//
//  IMPORTANT NOTE: For this particular assignment you may not add
//  any additional utility functions.
//
//  Copyright 2019 David Kopec
//
//  Permission is hereby granted, free of charge, to any person
//  obtaining a copy of this software and associated documentation files
//  (the "Software"), to deal in the Software without restriction,
//  including without limitation the rights to use, copy, modify, merge,
//  publish, distribute, sublicense, and/or sell copies of the Software,
//  and to permit persons to whom the Software is furnished to do so,
//  subject to the following conditions:
//
//  The above copyright notice and this permission notice
//  shall be included in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
//  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
//  OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
//  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//  OTHER DEALINGS IN THE SOFTWARE.

#ifndef sort_hpp
#define sort_hpp

#include <algorithm> // for swap(), merge()
#include <random>
#include <vector>

using namespace std;

namespace csi281 {
    // Performs an in-place ascending sort of *array*
    // using the merge sort algorithm
    // *start* is the first element of the array to start sorting from
    // *end* is the end element for the elements to be sorted
    // *end* will be the length of the array - 1 for a first run
    // NOTE: Your solution MUST use std::inplace_merge
    // http://www.cplusplus.com/reference/algorithm/inplace_merge/
    template <typename T>
	void mergeSort(T array[], const int start, const int end) {
		if (start < end)
		{
			int middle = (start + end) / 2;
			T left[middle + 1 - start];
			T right[last + 1 - middle];
			for (int i = 0; i < left.length(); i++)
			{
				left[i] = array[start + i];
			}
			for (int i = 0; i < right.length(); i++)
			{
				right[i] = array[middle + i];
			}

			std::vector<T> sorted(end - start + 1);
			std::vector<T>::iterator it;

			mergeSort(array, start, middle);
			mergeSort(array, middle + 1, end);

			it = std::copy(left, left + middle, sorted.begin());
			std::copy(right, right + middle, it);

			std::inplace_merge(sorted.begin(), sorted.begin() + middle, sorted.end());

			//Would have been nice to know how to actually use inplace_merge like maybe if it were taught in class
		}
	}
    // setup random number generator
    static random_device rd;
    static mt19937 rng(rd());
    // you can use uniform_int_distribution and rng to create
    // a random int in a certain range
    
    // Performs an in-place ascending sort of *array*
    // using the quicksort algorithm
    // *start* is the first element of the array to start sorting from
    // *end* is the end element for the elements to be sorted
    // *end* will be the length of the array - 1 for a first run
    // NOTE: Your solution should use std::swap
    // http://www.cplusplus.com/reference/algorithm/swap/
    // NOTE: Your solution MUST use a random pivot
    // TIP: It may be helpful to swap the pivot to the end,
    // sort the center of the range, and then move the pivot back to
    // the appropriate place
    template <typename T>
    void quickSort(T array[], const int start, const int end) {
		if (start < end)
		{
			srand(time(NULL));
			int partition = rand() % (end + 1) + start;
			T pivot = array[partition];
			int index = (start - 1);
			for (int i = start; i <= end - 1; i++)
			{
				if (array[i] < pivot)
				{
					index++;
					T temp1;
					temp1 = array[index];
					array[index] = array[i];
					array[i] = temp1;
				}
			}
			T temp2;
			temp2 = array[index + 1];
			array[index + 1] = array[end];
			array[end] = temp2;
			index++;

			quickSort(array, start, index - 1);
			quickSort(array, index + 1, end);
		}
    }
    
    // Performs an in-place ascending sort of *array*
    // using the insertion sort algorithm
    // *start* is the first element of the array to start sorting from
    // *end* is the end element for the elements to be sorted
    // *end* will be the length of the array - 1 for a first run
    // NOTE: You can modify your old implementation from assignment 4
    // OR if you believe yours was incorrect, email me and I will
    // send you mine assuming you are done with assignment 4,
    // but you will still need to modify it for this assignment
    // as described below
    // NOTE: You will need to modify the implementation to only
    // sort part of the array as per the parameters of this version
    template <typename T>
    void insertionSort(T array[], const int start, const int end) {
		T key;
		int j;
		//start iteration through array
		for (int i = start; i < end; i++)
		{
			//set the key element to the element proceeding the one at hand
			key = array[i];
			j = i - 1;
			//compare key element to its predecessors and put key in its sorted place
			while (j >= 0 && array[j] > key)
			{
				array[j + 1] = array[j];
				j -= 1;
			}
			//set next element to key
			array[j + 1] = key;
		}
    }
    
    // Performs an in-place ascending sort of *array*
    // using merge sort until there is less than 10 elements, and then
    // the insertion sort algorithm
    // *start* is the first element of the array to start sorting from
    // *end* is the end element for the elements to be sorted
    // *end* will be the length of the array - 1 for a first run
    // TIP: You can copy your implementation of merge sort in here, and
    // should be able to call the insertionSort above
    template <typename T>
    void hybridSort(T array[], const int start, const int end) {
		while (start < end)
		{
			if (end - start - 1 < 10)
			{
				mergeSort(array, start, end);
				break;
			}
			else
			{
				insertionSort(array, start, end);
			}
		}
    }
    
    
}


#endif /* sort_hpp */
