CC=g++
TEST=test
LIBS=-lgtest -lpthread

all:

test: vector_test array_test

run:
	./$(TEST)

vector_test:
	$(CC) ./test_vector/test.cpp ./test_vector/test_main.cpp -o $(TEST) $(LIBS)
	make run

array_test:
	g++ ./test_array/test.cpp ./test_array/test_main.cpp -o $(TEST) $(LIBS)
	make run

vector_debug_test:
	$(CC) ./test_vector/test.cpp ./test_vector/test_main.cpp -o $(TEST) $(LIBS) -g

array_debug_test:
	$(CC) ./test_array/test.cpp ./test_array/test_main.cpp -o $(TEST) $(LIBS) -g

style:
	cp ../../materials/linters/CPPLINT.cfg ./
	python3 ../../materials/linters/cpplint.py --extensions=h --extensions=cpp *.h test_array/*.cpp test_vector/*.cpp 

check:
		cppcheck --quiet --enable=all --language=c++ --suppress=missingInclude --suppress=unusedFunction sequcontainer.h vector.h array.h test_array/*.cpp test_vector/*.cpp

clean:
	rm -rf $(TEST)
