/* order_book.h --- Header file for order_book class
 * 
 * 
 * Author: Robert F. Carangelo III
 * Created: Sat Dec  5 12:00:46 2020 (-0500)
 * Version: 
 * 
 * Description: defines structure and functions relating to order_book data
 * 
 */
#ifndef ORDER_Q_H
#define ORDER_Q_H
#include <iostream>
#include <cstdlib>
#include <queue>
#include "Order.h"

using namespace std;

class Order_q {
 public:
	float price;
	queue<Order> oq;
	void set_price(float p);
	float get_price();
	void print_queue();
};


#endif
