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
	Order_q q1;
	float price = 33.4;
	Order o1, o2, o3, o4, o5, test;
	o1.id = 3;
	o2.set_quantity(5);

	o3.id = o1.get_id();
	o3.quantity = o2.get_quantity();

    o4.id = 1;
    o4.quantity = 10;

    o5.id = 9;
    o5.quantity = 20;

	q1.set_price(price);
	q1.oq.push(o3);
    q1.oq.push(o4);
    q1.oq.push(o5);

	q1.print_queue();

	q1.oq.pop();
    q1.oq.pop();
    test = q1.oq.front();
	
    if(test.get_id() != 9) {
        cout << "failed test 1\n";
        return -1;
    }
    q1.oq.pop();
    
    if(!q1.oq.empty()) {
        cout<<"fail test 2\n";
        return -1;
    }

	return 0;
}
