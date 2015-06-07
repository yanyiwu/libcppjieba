all: 
	g++ -o demo -O3 -DLOGGER_LEVEL=LL_WARN -Wall -g demo.cpp 
clean:
	rm -f *.o *.a demo
