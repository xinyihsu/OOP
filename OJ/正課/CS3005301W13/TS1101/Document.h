/*************************************************************************
 * File: Document.h
 * Author: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Create Date: 2023-05-18
 * Editor: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Update Date: 2023-05-18
 * Description: Define a class named Document that contains a member variable of type string
 *				named text that stores any textual content for the document.
 *************************************************************************/
#include <iostream>
#include <string>
using namespace std;

class Document
{
protected:
	string text; //stores any textual content for the document
public:
	/**
	 * Intent: constructor
	 * Pre: void
	 */
	Document(void)
	{

	}

	/**
	 * Intent: constructor
	 * Pre:  a sring (to init text)
	 */
	Document(string text)
	{
		this->text = text;
	}

	/**
	 * Intent: to get the text
	 * Pre: void
	 * Post: the string (text)
	 */
	string getText(void) const
	{
		return text;
	}

	/**
	 * Intent: to set the text
	 * Pre: a string
	 * Post: void
	 */
	void setText(const string& temp)
	{
		this->text = temp;
	}

	/**
	 * Intent: the overloaded assignment operator
	 * Pre: an input Document object
	 * Post: an Document object
	 */
	Document& operator=(const Document& other)
	{
		this->text = other.text;
		return *this;
	}
};
