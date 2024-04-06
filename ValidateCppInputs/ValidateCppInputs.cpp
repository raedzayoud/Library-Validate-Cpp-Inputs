#include <iostream>
#include "clsdate.h"

using namespace std;

class clsInputValidate
{

public:
	static bool IsNumberBetween(int x, int from, int to) {
		return x >= from && x <= to;
	}

	static bool IsNumberBetween(double x, double from, double to) {
		return x >= from && x <= to;
	}

	static bool IsDateBetween(clsDate d, clsDate from, clsDate to) {

		if (clsDate::IsDate1BeforeDate2(from, to)) {

			if ((clsDate::IsDate1BeforeDate2(d, from))) {
				return false;
			}
			if (clsDate::IsDate1AfterDate2(d, to)) {
				return false;
			}

			return true;


		}
		else {

			if ((clsDate::IsDate1AfterDate2(d, from))) {
				return false;
			}
			if (clsDate::IsDate1BeforeDate2(d, to)) {
				return false;
			}

		}

		return true;

	}

	static int ReadIntNumber(string s) {
		int Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << s << endl;
			//cout<<"please entrer a number: ";
		}
		return Number;
	}

	static double ReadDubleNumber(string s) {
		double Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << s << endl;
			//cout<<"please entrer a number: ";
		}
		return Number;
	}

	static int ReadIntNumberbetween(int from, int to, string s) {
		int x;
		x = ReadIntNumber("Invalid Number,Enter again");
		if (IsNumberBetween(x, from, to)) {
			return x;
		}
		else {
			cout << s << endl;
			while (!IsNumberBetween(x, from, to)) {
				x = ReadIntNumber("Invalid Number,Enter again");
			}
			return x;
		}
	}

	static double ReadDoubleNumberbetween(double from, double to, string s) {
		double x;
		x = ReadDubleNumber("Invalid Number,Enter again");
		if (IsNumberBetween(x, from, to)) {
			return x;
		}
		else {
			cout << s << endl;
			while (!IsNumberBetween(x, from, to)) {
				x = ReadDubleNumber("Invalid Number,Enter again");
			}
			return (double)x;
		}
	}


};

