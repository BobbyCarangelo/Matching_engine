CXX=g++
CXXFLAGS=-Wall -g -pedantic

all: selltest4 stringtest asktest1

init_test.o:	init_test.cpp
				$(CXX) $(CXXFLAGS) -c init_test.cpp

stringtest.o:	stringtest.cpp
				$(CXX) $(CXXFLAGS) -c stringtest.cpp

qtest1.o:	qtest1.cpp
				$(CXX) $(CXXFLAGS) -c qtest1.cpp

bidtest1.o:	bidtest1.cpp
				$(CXX) $(CXXFLAGS) -c bidtest1.cpp

bidtest2.o:	bidtest2.cpp
				$(CXX) $(CXXFLAGS) -c bidtest2.cpp

asktest1.o:	asktest1.cpp
				$(CXX) $(CXXFLAGS) -c asktest1.cpp

buytest1.o:	buytest1.cpp
				$(CXX) $(CXXFLAGS) -c buytest1.cpp

buytest2.o:	buytest2.cpp
				$(CXX) $(CXXFLAGS) -c buytest2.cpp

buytest3.o:	buytest3.cpp
				$(CXX) $(CXXFLAGS) -c buytest3.cpp

selltest1.o:	selltest1.cpp
				$(CXX) $(CXXFLAGS) -c selltest1.cpp

selltest2.o:	selltest2.cpp
				$(CXX) $(CXXFLAGS) -c selltest2.cpp

selltest3.o:	selltest3.cpp
				$(CXX) $(CXXFLAGS) -c selltest3.cpp

selltest4.o:	selltest4.cpp
				$(CXX) $(CXXFLAGS) -c selltest4.cpp


Order_book.o:	Order_book.cpp
				$(CXX) $(CXXFLAGS) -c Order_book.cpp

Order.o:	Order.cpp
				$(CXX) $(CXXFLAGS) -c Order.cpp

Order_q.o:	Order_q.cpp
				$(CXX) $(CXXFLAGS) -c Order_q.cpp

init_test:	init_test.o Order_book.o Order.o Order_q.o
				$(CXX) $(CXXFLAGS) -o init_test init_test.o Order_book.o Order.o Order_q.o

stringtest:	stringtest.o Order_book.o Order.o Order_q.o
				$(CXX) $(CXXFLAGS) -o stringtest stringtest.o Order_book.o Order.o Order_q.o

qtest1:	qtest1.o Order_book.o Order.o Order_q.o
				$(CXX) $(CXXFLAGS) -o qtest1 qtest1.o Order_book.o Order.o Order_q.o

bidtest1:	bidtest1.o Order_book.o Order.o Order_q.o
				$(CXX) $(CXXFLAGS) -o bidtest1 bidtest1.o Order_book.o Order.o Order_q.o

asktest1:	asktest1.o Order_book.o Order.o Order_q.o
				$(CXX) $(CXXFLAGS) -o asktest1 asktest1.o Order_book.o Order.o Order_q.o


bidtest2:	bidtest2.o Order_book.o Order.o Order_q.o
				$(CXX) $(CXXFLAGS) -o bidtest2 bidtest2.o Order_book.o Order.o Order_q.o

buytest1:	buytest1.o Order_book.o Order.o Order_q.o
				$(CXX) $(CXXFLAGS) -o buytest1 buytest1.o Order_book.o Order.o Order_q.o

buytest2:	buytest2.o Order_book.o Order.o Order_q.o
				$(CXX) $(CXXFLAGS) -o buytest2 buytest2.o Order_book.o Order.o Order_q.o

buytest3:	buytest3.o Order_book.o Order.o Order_q.o
				$(CXX) $(CXXFLAGS) -o buytest3 buytest3.o Order_book.o Order.o Order_q.o

selltest1:	selltest1.o Order_book.o Order.o Order_q.o
				$(CXX) $(CXXFLAGS) -o selltest1 selltest1.o Order_book.o Order.o Order_q.o

selltest2:	selltest2.o Order_book.o Order.o Order_q.o
				$(CXX) $(CXXFLAGS) -o selltest2 selltest2.o Order_book.o Order.o Order_q.o

selltest3:	selltest3.o Order_book.o Order.o Order_q.o
				$(CXX) $(CXXFLAGS) -o selltest3 selltest3.o Order_book.o Order.o Order_q.o

selltest4:	selltest4.o Order_book.o Order.o Order_q.o
				$(CXX) $(CXXFLAGS) -o selltest4 selltest4.o Order_book.o Order.o Order_q.o

clean: 
				rm -f *.o  init_test qtest1 bidtest1 bidtest2 buytest1 buytest2 buytest3 selltest1 selltest2 selltest3 selltest4 stringtest asktest1
