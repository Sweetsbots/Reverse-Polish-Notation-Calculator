#pragma once


#include "stdafx.h"
#include "Bignum.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h> 

using namespace std;

/*
Node to be used for the Stack linkedList
*/
class StackNode
{
public:
	Bignum bignumOnStack;
	StackNode* next;
};
class BignumStack
{
private:
	StackNode * head;
	int count; //head
public:
	BignumStack() {
		head = nullptr;
		count = 0;
	}
	//Creates a copy constructor to allow deepCopy
	BignumStack(const BignumStack& copyMe) {
		head = nullptr;
		count = 0;
	}
	/*
	Pushes the Bignum to the stack. If the head is null,
	it puts the Bignum as the head, else it creates the new node, makes it head
	and makes the old head the next value
	*/
	void push(Bignum pushedBignum)
	{
		StackNode *newTop = new StackNode;
		/*
		If the head pointer is null, it puts the pushedBignum as the head,
		else it moves the head to next and puts the pushedBignum as the new head
		*/
		if (head == nullptr)
		{
			newTop->bignumOnStack = pushedBignum;
			newTop->next = nullptr;
			head = newTop;
			count++;
		}
		else
		{
			newTop->bignumOnStack = pushedBignum;
			newTop->next = head;
			head = newTop;
			count++;
		}
	}
	/*Returns the size of the stack to verify it is not full,
	and to allow the program to verify it can pop off digits properly
	*/
	int stackSize() {
		return count;
	}
	Bignum peek() {
		Bignum returnBignum = head->bignumOnStack;
		return returnBignum;
	}
	/*
	Pops the Bignum from the Stack's linked list, moves the head to the next value
	and then deletes the old head of the stack
	*/
	Bignum pop()
	{
		/*
		If the head of the stack is null, it returns a bignum of 0, else
		it returns the old head of the bignum and moves the head to next
		*/
		if (head == nullptr) {
			cout << "nothing to pop";
			Bignum returnBignum("0");
			return returnBignum;
		}
		else
		{
			StackNode * old = head;
			Bignum returnBignum = old->bignumOnStack;
			head = head->next;
			count--;
			delete(old);
			return returnBignum;
		}
	}
	// Destructs the stack
	~BignumStack() {
		//create a pointer to head and to next, delete head,
		StackNode* currentNode;
		StackNode* nextNode;
		currentNode = head;
		while (currentNode) {
			nextNode = currentNode->next;
			delete currentNode;
			currentNode = nextNode;
		}
	}
};