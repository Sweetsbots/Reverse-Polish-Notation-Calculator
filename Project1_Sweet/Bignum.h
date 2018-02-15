#pragma once
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <exception>
using namespace std;
/*
Create the DigitNode
*/
class DigitNode {
private:
public:
	int number;
	DigitNode *next;
	DigitNode *previous;

	DigitNode() {
		number = 0;
		next = nullptr;
		previous = nullptr;
	}
	~DigitNode() {

	}
};

class Bignum
{

private:
	DigitNode * head;
	string value;
public:

	//put user input into the constructor of Bignum
	Bignum() {

	}
	Bignum(string value) {
		head = nullptr;
		this->value = value;
		createBignum(value);
	}
	//Creates a copy constructor
	Bignum(const Bignum& copyMe) {
		head = nullptr;
		value = copyMe.value;
		createBignum(value);
	}
	//override = operator
	void operator= (Bignum &copyMe) {
		head = nullptr;
		value = copyMe.value;
		createBignum(value);
	}
	//gets the head of the DigitNode
	DigitNode getHead() {
		return *head;
	}
	//gets the string value of the Bignum
	string getValue() {
		return value;
	}
	//creates the bignum
	void createBignum(string value) {
		//deletes all leading zeroes
		value.erase(0, value.find_first_not_of('0'));
		//verifies it didnt delete the entire string, if it did, adds 1 zero back
		if (value.size() == 0) {
			value.push_back('0');
		}
		int count = 0;
		int stringSize = value.size();
		while (count < stringSize) {
			addNumber(value.at(count) - '0');
			count++;
		}
	}
	//use a doubly linked list
	void addNumber(int number) {
		DigitNode *newDigit, *currentDigit, *previousDigit;
		newDigit = new DigitNode();
		newDigit->number = number;
		//if the head is null make the new grade the head
		if (!head) {
			head = newDigit;
			currentDigit = NULL;
			previousDigit = NULL;
		}
		else {
			//make the currentDigit equal to head of linkedList
			currentDigit = head;
			//while currentDigit pointing to next is not null
			while (currentDigit->next) {
				currentDigit = currentDigit->next;
			}
			//put the newDigit at the end of the linked list
			//point the newDigit to the digit that used to be at the end;
			currentDigit->next = newDigit;
			newDigit->previous = currentDigit;
		}
	}
	//print method
	void print() {
		DigitNode *current = head;
		while (current) {
			cout << current->number;
			current = current->next;
		}
		cout << " ";
	}
	~Bignum() {
		//create a pointer to head and to next, make next the currents next and then delete current
		DigitNode* currentNode;
		DigitNode* nextNode;
		currentNode = head;
		while (currentNode) {
			nextNode = currentNode->next;
			delete currentNode;
			currentNode = nextNode;
		}
	}
};

