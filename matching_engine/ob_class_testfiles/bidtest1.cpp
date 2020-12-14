// init_test.cpp --- first test program of orderBook class
// 
// 
// Author: Robert F. Carangelo III
// Created: Sat Dec  5 11:08:37 2020 (-0500)
// Version: 
// 
// Description: makes sure all compilations work
// 
// 

#include "Order_book.h"
#include "Order.h"
#include "Order_q.h"
#include <iostream>
#include <cstdlib>


using namespace std;

int main(void) {
	cout<<"starting main\n";
	
    Order_book ob1;
    int id = 1;
    float price = 58.07;
    int quantity = 1000;

    ob1.bid(id,price,quantity);
    ob1.bid(id,58.05,800);
    ob1.ask(2,75.4, 200);
    ob1.bid(3,80,500);
    ob1.print_book();

	return 0;
}
