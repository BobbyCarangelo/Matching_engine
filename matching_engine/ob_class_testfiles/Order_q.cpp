// order_book.cpp --- Order book class
// 
// 
// Author: Robert F. Carangelo III
// Created: Sat Dec  5 11:12:27 2020 (-0500)
// Version: 
// 
// Description: Compiles all orders and matches orders into trades
// 
// 

using namespace std;

#include <iostream>
#include <cstdlib>
#include <queue>
#include <iterator>
#include "Order_q.h"
#include "Order.h"


void Order_q::set_price(float p) {
	price = p;
	return;
}

float Order_q::get_price(){
	return price;
}

void Order_q::print_queue() {
	queue<Order> newq;
	Order holder;

	while(!oq.empty()) {
		holder = oq.front();
		oq.pop();
		cout << "Trader id: " << holder.get_id() << " order quantity: " << holder.get_quantity() << endl;
		newq.push(holder);
	}
	
	while(!newq.empty()) {
		holder = newq.front();
		newq.pop();
		oq.push(holder);
	}

	return;
}