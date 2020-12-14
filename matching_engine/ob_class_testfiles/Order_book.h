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
#ifndef ORDER_BOOK_H
#define ORDER_BOOK_H
#include <iostream>
#include <cstdlib>
#include <queue>
#include <map>
#include "Order.h"
#include "Order_q.h"

using namespace std;

class Order_book {
 public:
	map<float,queue<Order>> bids;
	map<float,queue<Order>> asks;
	int execute_trade(int buyer, int seller, int quantity, float price);
	int bid(int id, float price, int quantity);
	int ask(int id, float price, int quantity);
	int buy(int id, int quantity);
	int sell(int id, int quantity);
	int print_book();
	int print_queue(queue<Order> qp);
	void clear_bids();
	int handle_order(string s, int trader_id);
};


#endif
