// order_book.cpp --- Order book class
// 
// 
// Author: Robert F. Carangelo III
// Created: Sat Dec  5 11:12:27 2020 (-0500)
// Version: 
// 
// Description: Compiles market and limit orders into a structure to be broadcast to all trading clients
// Matches trade orders to execute trades and sends reciept to trading clients
// 
// 

using namespace std;

#include <iostream>
#include <cstdlib>
#include <queue>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <iterator>
#include "Order_book.h"
#include "Order.h"


/*
 * handle_order -- takes a string as input and directs user input to correct function
 *
 * Returns 0 on success and -1 on failure
 */
int Order_book::handle_order(string s, int trader_id) {
	int quantity;
	float price;
	string order_type, position_type;
	int o_type = 0;
	string delimiter = " ";
	size_t pos = 0;
	string holder;
	vector<string> words;

	pos = s.find(delimiter);

	if(pos == string::npos) {
		cout << "input: <market/limit> <bid/ask/buy/sell> <quantity> <price>\n";
		return -1;
	}
	order_type = s.substr(0,pos);
	s.erase(0, pos + delimiter.length());

	if(order_type == "market") {
		o_type = 1;
	} 
	else if(order_type == "limit"){
		o_type = -1;
	} 
	else {
		cout << "input: <market/limit> <bid/ask/buy/sell> <quantity> <price>\n";
		return -1;
	}
	
	while((pos = s.find(delimiter)) != string::npos) {
		holder = s.substr(0,pos);
		words.push_back(holder);
		s.erase(0, pos + delimiter.length());
	}


	if(o_type > 0) {
		if(words.size() != 1) {
			cout << "input: <market/limit> <bid/ask/buy/sell> <quantity> <price>\n";
			return -1;	
		}
		quantity = stoi(s);
		if(words.operator[](0) == "buy") {
			buy(trader_id, quantity);
		}
		else if(words.operator[](0) == "sell") {
			sell(trader_id, quantity);
		}
		else {
			cout << "input: <market/limit> <bid/ask/buy/sell> <quantity> <price>\n";
			return -1;	
		}	
		
	}
	else if(o_type < 0 ) {
		if(words.size() != 2) {
			cout << "input: <market/limit> <bid/ask/buy/sell> <quantity> <price>\n";
			return -1;
		}
		quantity = stoi(words.operator[](1));
		price = stof(s);
		if(words.operator[](0) == "bid") {
			bid(trader_id, price, quantity);
		}
		else if(words.operator[](0) == "ask") {
			ask(trader_id, price, quantity);
		}
		else {
			cout << "input: <market/limit> <bid/ask/buy/sell> <quantity> <price>\n";
			return -1;	
		}
		
	}

	return 0;
}

/*
 * bid -- Handles a bid limit order, if it can be matched with an ask,
 * is executed with a buy order. If there already exists bids at this price, adds them to
 * the queue. If not, makes a new order queue at this price
 *
 * Returns 0 on success and -1 on failure
 */
int Order_book::bid(int id, float price, int quantity) {
	if(quantity <= 0) {
		cout << "Trade quantity must be positive\n";
		return -1;
	}

	map<float,queue<Order>>::iterator itr;
	Order new_order;

	//check if there is a corresponding asking price
	itr = asks.begin();
	if(price >= itr->first && itr != asks.end()) {
		cout << "Converting to buy order\n";
		return buy(id,quantity);
	}

	//create new order
	new_order.set_id(id);
	new_order.set_quantity(quantity);

	//either make a new queue at this price for this order or append this order to an existing queue
	itr = bids.find(price);
	if(itr == bids.end()) {
		queue<Order> newq;
		newq.push(new_order);
		bids.insert(pair<float,queue<Order>>(price,newq));
	} else {
		itr->second.push(new_order);
	}
	return 0;
}

/*
 * ask -- Handles an ask limit order, if it can be matched with a bid,
 * is executed with a sell order. If there already exists asks at this price, adds order to
 * the queue. If not, makes a new order queue at this price
 *
 * Returns 0 on success and -1 on failure
 */
int Order_book::ask(int id, float price, int quantity) {
	if(quantity <= 0) {
		cout << "Trade quantity must be positive\n";
		return -1;
	}

	map<float,queue<Order>>::reverse_iterator ritr;
	map<float,queue<Order>>::iterator itr;
	Order new_order;

	//check if there is a corresponding asking price
	if(!bids.empty()) {
		ritr = bids.rbegin();
		if(price <= ritr->first) {
			cout << "Converting to market order\n";
			return sell(id,quantity);
		}
	}
	

	//create new order
	new_order.set_id(id);
	new_order.set_quantity(quantity);

	//either make a new queue at this price for this order or append this order to an existing queue
	itr = asks.find(price);
	if(itr == asks.end()) {
		queue<Order> newq;
		newq.push(new_order);
		asks.insert(pair<float,queue<Order>>(price,newq));
	} else {
		itr->second.push(new_order);
	}
	return 0;
}

/*
 * buy -- match a buy order with the best (lowest) asking prices (orders)
 */
int Order_book::buy(int id, int quantity) {
	if(quantity <= 0) {
		cout << "Trade quantity must be positive\n";
		return -1;
	}
	map<float,queue<Order>>::iterator itr, itr2;
	Order next_best;
	int prev;

	//loop through the asking prices in order
	itr = asks.begin();
	while(!asks.empty()) {

		//loop through the ask orders at this price in the order they came in FIFO
		while(!itr->second.empty()) {
			next_best = itr->second.front();
			
			//if the buy order size matches the best ask order size
			if(next_best.get_quantity() == quantity) {
				execute_trade(id,next_best.get_id(),quantity,itr->first);
				itr->second.pop();
				if(itr->second.empty()) {
					asks.erase(itr);
				}
				return 0;
			}
			else if(next_best.get_quantity() < quantity) { 		//if the buy order size is less than the best ask order size
				execute_trade(id,next_best.get_id(),next_best.get_quantity(),itr->first);
				quantity -= next_best.get_quantity();
				itr->second.pop();
			} 
			else {										//if the buy order size is greater than the best ask order size
				execute_trade(id,next_best.get_id(),quantity,itr->first);
				prev = next_best.get_quantity();
				itr->second.front().set_quantity(prev-quantity);
				return 0;
			}
		}

		//remove this asking price from order book and increment to next best asking price
		itr2 = itr;
		itr++;
		asks.erase(itr2);
	}

	//if the entire buy order is not filled
	if(quantity > 0) {
		cout<<"***%#!@# Need Liquidity!!!! ***%#!@#" << endl;
		cout << quantity << " shares unable to be filled\n";
	}
	return 0;
}


/*
 * sell -- match a sell order with the best (highest) bidding prices (orders)
 */
int Order_book::sell(int id, int quantity) {
	if(quantity <= 0) {
		cout << "Trade quantity must be positive\n";
		return -1;
	}
	map<float,queue<Order>>::reverse_iterator ritr, ritr2; 
	Order next_best;
	int prev;

	//loop through the bidding prices in order
	for(ritr = bids.rbegin(); ritr != bids.rend(); ++ritr) {

		//loop through the buy orders at this price in the order they came in FIFO
		while(!ritr->second.empty()) {
			next_best = ritr->second.front();

			//if the sell order size matches the best bid order size
			if(next_best.get_quantity() == quantity){
				execute_trade(next_best.get_id(), id, quantity, ritr->first);
				ritr->second.pop();
				clear_bids();
				return 0;
			}
			else if(next_best.get_quantity() < quantity) { 		//if the sell order size is less than the best bid order size
				execute_trade(next_best.get_id(), id, next_best.get_quantity(), ritr->first);
				quantity -= next_best.get_quantity();
				ritr->second.pop();
			} 
			else {										//if the sell order size is greater than the best bid order size
				execute_trade(next_best.get_id(), id, quantity, ritr->first);
				prev = next_best.get_quantity();
				ritr->second.front().set_quantity(prev-quantity);
				clear_bids();
				return 0;
			}
		}
	}
	clear_bids();

	//if the entire sell order is not filled
	if(quantity > 0) {
		cout<<"***%#!@# Need Liquidity!!!! ***%#!@#" << endl;
		cout << quantity << " shares unable to be filled\n";
	}
	return 0;
}


/*
 * print_book -- Prints order books
 *
 * Returns 0 on success and -1 on failure
 */
int Order_book::print_book() {
	map<float,queue<Order>>::iterator itr;

	cout<<"************\n" << "Bids ($): \n";
	for(itr = bids.begin(); itr != bids.end(); ++itr) {
		cout << itr->first<<endl;
		print_queue(itr->second);
	}
	cout<<"************\n" << "Asks ($): \n";
	for(itr = asks.begin(); itr != asks.end(); ++itr) {
		cout << itr->first<<endl;
		print_queue(itr->second);
	}
	return 0;
}

/*
 * print_book -- Prints order queue at certain price
 *
 * Returns 0 on success and -1 on failure
 */
int Order_book::print_queue(queue<Order> qp) {
	queue<Order> newq;
	Order holder;

	while(!qp.empty()) {
		holder = qp.front();
		qp.pop();
		cout << "Trader id: " << holder.get_id() << " order quantity: " << holder.get_quantity() << endl;
		newq.push(holder);
	}
	
	while(!newq.empty()) {
		holder = newq.front();
		newq.pop();
		qp.push(holder);
	}
	return 0;
} 

/*
 * execute_trade -- print out the trade reciept message
 *
 * Returns 0 on success and -1 on failure
 */
int Order_book::execute_trade(int buyer, int seller, int quantity, float price) {
	cout << "Trader: " << seller << " sells " << quantity << " shares to trader: " << buyer << " for $" << price << endl;
	return 0;
}

/*
 * clear_bids -- method that clears out bid prices that don't have any orders in them
 * Is done like this because could not figure out how to erase reverse iterator
 *
 * Returns 0 on success, -1 on failure
 */

void Order_book::clear_bids(){
	map<float,queue<Order>>::iterator itr1, itr2;
	itr1 = bids.begin(); 
	while(itr1 != bids.end()) {
		if (itr1->second.empty()){		
			itr2 = itr1;
			itr1++;
			bids.erase(itr2);
		}
		else {	
			itr1++;
		}
	}
}