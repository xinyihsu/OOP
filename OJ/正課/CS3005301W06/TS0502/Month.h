#pragma once
class Month
{
public:
	Month(); //Construct a Month class that defaults to January
	Month(char first, char second, char third); //Use the given abbreviation to construct the Month class, the parameters represent each letter of the abbreviation
	Month(int monthInt); //Construct a Month class with the value of¡§monthInt¡¨. **Note that if the given value is invalid, please set the month to January
	~Month();

	void inputInt(); //Read an int x, and modify the current month to x. If x is invalid (x < 1 or x > 12), please set the month value to 1
	void inputStr(); //Read three letters a, b and c. These letters represent each letter of the abbreviation of a month. Modify the letters to the corresponding month value. If the input is invalid, set the month value to 1
	void outputInt(); //Print the month value
	void outputStr(); //Print the abbreviation of the month
	Month nextMonth(); //Increment month value
private:
	int month = 0; //storing the current month
};

