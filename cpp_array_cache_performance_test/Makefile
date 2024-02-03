all: run_test_performance

run_test_performance: test_performance.o
	g++ -fopenmp -O2 -o run_test_performance test_performance.o

test_performance.o:	test_performance.cpp matrix.h
	g++ -fopenmp -O2 -c test_performance.cpp

clean:
	rm *.o run_test_performance
