CFLAGS=-Wall -pedantic -g

all:	trader_client venue_server matching_engine


trader_client.o:	trader_client.cpp
								g++ $(CFLAGS) -c trader_client.cpp

venue_server.o:	venue_server.cpp
								g++ $(CFLAGS) -c venue_server.cpp

matching_engine.o:	matching_engine.cpp
								g++ $(CFLAGS) -c matching_engine.cpp

trader_client:		trader_client.o 
								g++ $(CFLAGS) trader_client.o -o trader_client

venue_server:		venue_server.o Order_book.o Order.o
								g++ $(CFLAGS) venue_server.o Order_book.o Order.o -o venue_server

matching_engine:		matching_engine.o Order_book.o Order.o
								g++ $(CFLAGS) matching_engine.o Order_book.o Order.o -o matching_engine

clean:
				rm -f trader_client.o venue_server.o trader_client venue_server matching_engine
