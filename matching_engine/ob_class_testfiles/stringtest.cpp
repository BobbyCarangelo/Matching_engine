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
    
    ob1.handle_order("limit ask 400 57.9",1);
    ob1.handle_order("limit bid 400 55.9",2);
    ob1.handle_order("market sell 400",3);
    ob1.handle_order("limit sell 400",3);
    ob1.handle_order("limit this 50 400",3);
    ob1.handle_order("limit haha 400",3);
    ob1.handle_order("market sell 400 50",3);
    ob1.handle_order("limitsldjf sell 400",3);
    ob1.handle_order("limitsell400",3);



    ob1.print_book();

	return 0;
}
