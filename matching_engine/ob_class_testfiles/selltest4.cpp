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
    Order_book ob1;

    
    ob1.ask(4,40.5, 500);
    ob1.ask(4,39.6, 400);
    ob1.bid(4,39.3,500);
    ob1.bid(4,39.3,500);
    ob1.bid(4,39.9,300);
    ob1.buy(4,600);

    ob1.print_book();

	return 0;
}
