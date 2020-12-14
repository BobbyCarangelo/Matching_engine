/* Order.h --- Header file for order class
 * 
 * 
 * Author: Robert F. Carangelo III
 * Created: Sat Dec  5 12:00:46 2020 (-0500)
 * Version: 
 * 
 * Description: Order class contains two fields, id: integer that represents the trading client that placed the order, and quantity, the size of the order
 * 
 */
#ifndef ORDER_H
#define ORDER_H
#include <iostream>
#include <cstdlib>


using namespace std;

class Order {
 public:
	int id;
	int quantity;
	void set_id(int idp);
	void set_quantity(int quantityp);
	int get_id();
	int get_quantity();
};


#endif
