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
	Order o1, o2, o3, o4;
	o1.id = 3;
	o2.set_quantity(5);

	o3.id = o1.get_id();
	o3.quantity = o2.get_quantity();

	q1.set_price(price);
	q1.oq.push(o3);

	o4 = q1.oq.front();

	cout<<"o4 id: "<<o4.get_id()<<" quantity: "<<o4.get_quantity()<<endl;
	
	return 0;
}
