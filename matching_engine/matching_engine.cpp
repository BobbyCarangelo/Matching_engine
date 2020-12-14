// matching_engine.cpp --- Matches market and limit market orders
// 
// 
// Author: Bobby Carangelo 
// Created: Sat Dec  5 11:08:37 2020 (-0500)
// Version: 
// 
// Description: Processes bid/ask/buy/sell orders for a financial product, 
// matches and executes trades when appropriate, stores unfilled orders in an Order book.
// Designed and implemented with latency considerations in mind
// 
// Usage: matching_engine: <trader_id (int)> <market/limit> <bid/ask/buy/sell> <quantity> <price (optional)>
//
//
#include "Order_book.h"
#include "Order.h"
#include "Order_q.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <string.h>


using namespace std;

void print_menu() {
    cout << "Welcome to matching engine demonstrator\n";
    cout << "Enter in a trade according to the following usage: \n";
    cout << "<trader_id (int)> <market/limit> <bid/ask/buy/sell> <quantity> <price (optional)>\n";
    cout << "enter d to display current order book\n";
    cout << "enter q to quit\n";
    cout << "enter m to see this menu again\n";
    
}

int main(void) {
    Order_book ob1;
    string input;
    string fword;
    int trader_id;
    string delimiter = " ";
    size_t pos = 0;
    
    print_menu();
    cout << "> ";
    //getting first word
    getline(cin, input);
    pos = input.find(delimiter);
    fword = input.substr(0,pos);
    input.erase(0,pos + delimiter.length());

    //loop until quit
    while(fword != "q") {
        if(fword == "d") {                      //check for display
            ob1.print_book();
        }
        else if(fword == "m") {                 //check for menu
            print_menu();
        }
        else {                                   //execute trade order
            try {
                trader_id = stoi(fword);
                ob1.handle_order(input,trader_id);
            }   
            catch(std::invalid_argument& e){
                cout << "<trader_id (int)> <market/limit> <bid/ask/buy/sell> <quantity> <price (optional)>\n";
            }

        }

        //get next input
        cout << "> ";
        getline(cin, input);
        pos = input.find(delimiter);
        fword = input.substr(0,pos);
        input.erase(0,pos + delimiter.length());
    }
	return 0;
}
