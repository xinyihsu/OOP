/*************************************************************************
 * File: Document.h
 * Author: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Create Date: 2023-05-18
 * Editor: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Update Date: 2023-05-18
 * Description: Define a class for Email that is derived from Document
 *				and includes member variables for the sender, recipient, and title of an email message.
 *************************************************************************/
#pragma once
#include <iostream>
#include <string>
using namespace std;

class Email : public Document
{
private:
	string sender;
	string recipient;
	string title;
public:
	/**
	 * Intent: constructor
	 * Pre: input string of Document and Email member variable
	 */
	Email(string tempText, string inputSender, string tempRecipient, string tempTitle)
	{
		text = tempText;
		this->sender = inputSender;
		this->recipient = tempRecipient;
		this->title = tempTitle;
	}

	/**
	 * Intent: to get sender
	 * Pre: void
	 * Post: the string sender
	 */
	string getSender(void)
	{
		return sender;
	}

	/**
	 * Intent: to set sender
	 * Pre: an input string
	 * Post: void
	 */
	void setSender(const string& temp)
	{
		this->sender = temp;
	}

	/**
	 * Intent: to get recipient
	 * Pre: void
	 * Post: the string recipient
	 */
	string getRecipient(void)
	{
		return recipient;
	}

	/**
	 * Intent: to set recipient
	 * Pre: an input string
	 * Post: void
	 */
	void setRecipient(const string& temp)
	{
		this->recipient = temp;
	}

	/**
	 * Intent: to get title
	 * Pre: void
	 * Post: the string title
	 */
	string getTitle(void)
	{
		return title;
	}

	/**
	 * Intent: to set title
	 * Pre: an input string
	 * Post: void
	 */
	void setTitle(const string& temp) {
		this->title = temp;
	}

	/**
	 * Intent: the overloaded assignment operator
	 * Pre: an input Email object
	 * Post: an Email object
	 */
	Email& operator=(const Email& other)
	{
		this->sender = other.sender;
		this->recipient = other.recipient;
		this->title = other.title;
		this->text = other.text;

		return *this;
	}

};
