/*************************************************************************
 * File: Document.h
 * Author: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Create Date: 2023-05-18
 * Editor: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Update Date: 2023-05-18
 * Description:  Define a class for File that is derived from Document
 *				 and includes a member variable for the pathname.
 *************************************************************************/
#pragma once
#include <iostream>
#include <string>
using namespace std;

class File : public Document
{
private:
	string pathname;
public:
	/**
	 * Intent: constructor
	 * Pre: input string of Document and File member variable
	 */
	File(string inputText, string inputPathname)
	{
		text = inputText;
		this->pathname = inputPathname;
	}

	/**
	 * Intent: to get pathname
	 * Pre: void
	 * Post: the string pathname
	 */
	string getPathname(void)
	{
		return pathname;
	}

	/**
	 * Intent: to set pathname
	 * Pre: an input string
	 * Post: void
	 */
	void setPathname(const string& tempPathname)
	{
		this->pathname = tempPathname;
	}

	/**
	 * Intent: the overloaded assignment operator
	 * Pre: an input File object
	 * Post: an File object
	 */
	File& operator=(const File& other)
	{
		this->pathname = other.pathname;
		this->text = other.text;

		return *this;
	}

};