// IncomeCalculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

//Calculates the gross pay, including time and a half and double time.
class incomeCalculations {
public:
	double grossAdded;
	double taxPercent = 0;
void profitForWeek(double dollarsPerHour, double hoursWorked ) {
	bool exitCondition = false;
	while (exitCondition == false) {
		if (hoursWorked < 40) {
			grossAdded = dollarsPerHour * hoursWorked;
			grossAdded = floor(grossAdded * 100 + 0.5) / 100;
			std::cout << "The amount of gross income made is: " << grossAdded;
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
				grossAdded = grossFirst + grossSecond;
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
				grossAdded = grossFirst + grossSecond;
				grossAdded = floor(grossAdded * 100 + 0.5) / 100;
				std::cout << "The gross amount made is: " << grossAdded;
				exitCondition = true;
			}
			else {
				std::cout << "\n" << "That is not a valid answer";
			}
		}
		else if (hoursWorked == 40) {
			grossAdded = dollarsPerHour * hoursWorked;
			grossAdded = floor(grossAdded * 100 + 0.5) / 100;
			std::cout << "The amount of gross income made is: " << grossAdded;
			exitCondition = true;
		}
	}
}
void netIncome() {
		std::cout << "\nTo calculate net pay, a tax rate is required. Please enter the tax rate in decimal form: ";
		std::cin >> taxPercent;
	std::cout << "\nDEBUG-Current tax percentage is: " << taxPercent << "%";
	double netPay = grossAdded - (grossAdded * taxPercent);
	netPay = floor(netPay * 100 + 0.5) / 100;
	std::cout << "\nYour net pay is: " << netPay;
}
};


int main()
{
	bool calculatorExitCondition = false;
	while (calculatorExitCondition == false) {
		std::cout << "Hello, this is a work-in-progress income calculator.\n" << "Please type the input like this\n10.50(dollars per hour) 40 (amount of hours worked.)\n" << "Enter the numbers now: ";
		double x, y;
		std::cin >> x;
		std::cin >> y;
		incomeCalculations grossCalc;
		grossCalc.profitForWeek(x, y);
		grossCalc.netIncome();
		std::cout << "\nWould you like to make another calculation?\n" << "yes[1] or no[2]: ";
		char quittingProgramAnswer;
		std::cin >> quittingProgramAnswer;
		if (quittingProgramAnswer == '2') {
			return 0;
		}
		else {
		}
	}
	return 0;
}