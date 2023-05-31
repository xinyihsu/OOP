/*************************************************************************
 * File: Template.h
 * Author: 徐欣儀，B11130008@mail.ntust.edu.tw
 * Create Date: 2023-05-31
 * Editor: 徐欣儀，B11130008@mail.ntust.edu.tw
 * Update Date: 2023-05-31
 * Description: Please write a template-based function that calculates and returns the absolute value
 *				of the difference between two numeric values passed with Template.h.
 *************************************************************************/
#pragma once

template <class T>
/**
 * Intent: calculate the absolute
 * Pre: two member
 * Post: the different (float)
 */
float absoluteValue(const T& first, const T& second)
{
	float minus = first - second;

	//if negative
	if (minus < 0) minus = -minus;

	return minus;
}
