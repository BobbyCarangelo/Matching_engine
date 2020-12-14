// Order.cpp --- Order class
// 
// 
// Author: Robert F. Carangelo III
// Created: Sat Dec  5 11:12:27 2020 (-0500)
// Version: 
// 
// Description: implements order.h interface
// 
// 

using namespace std;

#include <iostream>
#include <cstdlib>
#include "Order.h"


void Order::set_id(int idp) {
	id = idp;
	return;
}

void Order::set_quantity(int quantityp) {
	quantity = quantityp;
	return;
}

int Order::get_id(){
	return id;
}

int Order::get_quantity(){
	return quantity;
}
