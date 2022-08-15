TEST=test.exe

all:

build_tests:

run:
	./$(TEST)

vector_test:
	g++ ./test_vector/test.cpp ./test_vector/test_main.cpp -o $(TEST) -lgtest

array_test:
	g++ ./test_array/test.cpp ./test_array/test_main.cpp -o $(TEST) -lgtest
	make run

vector_debug_test:
	g++ ./test_vector/test.cpp ./test_vector/test_main.cpp -o $(TEST) -lgtest -g

array_debug_test:
	g++ ./test_array/test.cpp ./test_array/test_main.cpp -o $(TEST) -lgtest -g

clean:
	rm -rf $(TEST)