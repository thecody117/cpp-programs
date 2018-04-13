// IncomeCalculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
void netIncome() {
}
//Calculates the gross pay, including time and a half and double time.
void profitForWeek(double dollarsPerHour, double hoursWorked ) {
	bool exitCondition = false;
	while (exitCondition == false) {
		if (hoursWorked < 40) {
			double grossProfit = dollarsPerHour * hoursWorked;
			grossProfit = floor(grossProfit * 100 + 0.5) / 100;
			std::cout << "The amount of gross income made is: " << grossProfit;
			exitCondition = true;
		}
		else if (hoursWorked > 40) {
			char answer;
			double extraDollarAmount = 0;
			std::cout << "Is it time and a half[1] or double time[2]?: ";
			std::cin >> answer;
			//Calculates time and a half.
			if (answer == '1') {
				extraDollarAmount = hoursWorked - 40;
				double timeAndHalf = dollarsPerHour * 1.5;
				double grossFirst = dollarsPerHour * 40;
				double grossSecond = timeAndHalf * extraDollarAmount;
				double grossAdded = grossFirst + grossSecond;
				grossAdded = floor(grossAdded * 100 + 0.5) / 100;
				std::cout << "The gross amount made is: " << grossAdded;
				exitCondition = true;
			}
			//Calculate double time.
			else if (answer == '2') {
				extraDollarAmount = hoursWorked - 40;
				double timeAndHalf = dollarsPerHour * 2;
				double grossFirst = dollarsPerHour * 40;
				double grossSecond = timeAndHalf * extraDollarAmount;
				double grossAdded = grossFirst + grossSecond;
				grossAdded = floor(grossAdded * 100 + 0.5) / 100;
				std::cout << "The gross amount made is: " << grossAdded;
				exitCondition = true;
			}
			else {
				std::cout << "\n" << "That is not a valid answer";
			}
		}
	}
}


int main()
{
	bool calculatorExitCondition = false;
	while (calculatorExitCondition == false) {
		std::cout << "Hello, this is a work-in-progress income calculator.\n" << "Please type the input like this\n10.50(dollars per hour) 40 (amount of hours worked.)\n" << "Enter the numbers now: ";
		double x, y;
		std::cin >> x;
		std::cin >> y;
		profitForWeek(x, y);
		std::cout << "\nWould you like to make another calculation?\n" << "yes[1] or no[2]: ";
		char quittingProgramAnswer;
		std::cin >> quittingProgramAnswer;
		if (quittingProgramAnswer == '1') {
			return 0;
		}
		else {
			return 0;
		}
	}
	return 0;
}

