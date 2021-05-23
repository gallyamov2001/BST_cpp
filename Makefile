CC=g++
CFLAGS= -Wall -g -std=c++17 -fprofile-arcs -ftest-coverage

all: test
tests.o: test.cpp
	${CC} -c test.cpp -o test.o ${CFLAGS}
bst.o: bst.cpp
	${CC} -c bst.cpp -o bst.o ${CFLAGS}
test: test.o bst.o
	${CC} bst.o test.o -o test ${CFLAGS}
clean:
	@rm -rf *.o *.gcno *.gcda *.gcov test 2&>/dev/null
tar:
	tar czvf ../bst_cpp.tgz ../bst_cpp
