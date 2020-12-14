# Matching Engine
# Bobby Carangelo - Dec 2020

 Module that acts as a market venue to compile trade order information and execute trades, written in c++

 Personal project created by Bobby Carangelo to gain exposure to order book structure, socket programming and with a focus on reducing latency 

 Stores market (buy and sell) and limit (bid and ask) orders and executes trades when appropraite

 User can interface with the matching engine in two files:
     1. Through matching_engine program
     2. Through running trader_client and venue_server programs (in separate windows). 
     Input trades in trader client and venue server prints trades and prints orderbook when the
     program is closed. This portion is still a work in progress, I am currently working on 
     multi-threading in the server so that multiple traders can connect to it and place orders. 
