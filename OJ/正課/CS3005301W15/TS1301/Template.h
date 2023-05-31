/*************************************************************************
 * File: Template.h
 * Author: 徐欣儀，B11130008@mail.ntust.edu.tw
 * Create Date: 2023-05-31
 * Editor: 徐欣儀，B11130008@mail.ntust.edu.tw
 * Update Date: 2023-05-31
 * Description: Please implement Binary Search using template, and provide both iterative and recursive versions.
 *************************************************************************/
#pragma once

template <class T>
/**
 * Intent: to find the index of key
 * Pre: a[] is the list that will be searched
		first is the start position
		last is the end position
		key is the element to be searched
		found is for recording whether the key exists in the list a[]
		location is the position of key in the list a[]
 * Post: void
 */
void ItrBinarySearch(const T a[], int first, int last, T key, bool& found, int& location)
{
	found = false; //init

	//check all array
	for (int i = first; i <= last; i++) {
		//if the same to key
		if (a[i] == key) {
			found = true;
			location = i;
			return;
		}
	}
}

template <class T>
/**
 * Intent: to find the index of key
 * Pre: a[] is the list that will be searched
		first is the start position
		last is the end position
		key is the element to be searched
		found is for recording whether the key exists in the list a[]
		location is the position of key in the list a[]
 * Post: void
 */
void RecBinarySearch(const T a[], int first, int last, T key, bool& found, int& location)
{
	if (first == 0) found = false; //init
	if (first == last + 1) return; //end

	//if the same to key
	if (a[first] == key) {
		found = true;
		location = first;
		return;
	}
	else {
		return RecBinarySearch(a, first + 1, last, key, found, location); //recursive
	}
}