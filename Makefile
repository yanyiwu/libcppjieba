all:libcppjieba.a demo
libcppjieba.a:
	g++ -o cppjieba.o -c -O3 -Wall -g -I./include cppjieba.cpp && ar rc libcppjieba.a cppjieba.o && rm cppjieba.o
demo: libcppjieba.a
	g++ -o demo -O3 -Wall -g -I./include demo.cpp -L./ -lcppjieba
clean:
	rm -f *.o *.a demo
