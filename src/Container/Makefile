CC=g++
TEST=test.out
LIBS=-lgtest -lpthread
CFLAGS=
OPEN=open

all:

test:
	$(CC) ./test_vector/test_vec.cpp ./test_vector/test.cpp ./test_vector/test_main.cpp -o $(TEST) $(LIBS)
	make run

run:
	./$(TEST)

debug_test:
	$(CC) ./test_vector/*.cpp -o $(TEST) $(LIBS) -g
	make run

gcov_report:
	$(CC) $(CFLAGS) -o $(TEST) --coverage ./test_vector/*.cpp $(LIBS)
	make run
	lcov -t "$(TEST)" -o test.info -c -d .
	lcov -q --remove test.info "/usr/include/*" -o test.info
	lcov -q --remove test.info "/usr/local/*" -o test.info
	genhtml -o report test.info
	$(OPEN) report/index.html

style:
	cp ../../materials/linters/CPPLINT.cfg ./
	python3 ../../materials/linters/cpplint.py --extensions=h --extensions=cpp *.h test_array/*.cpp test_vector/*.cpp 

check:
		cppcheck --quiet --enable=all --language=c++ --suppress=missingInclude --suppress=unusedFunction sequcontainer.h vector.h array.h test_array/*.cpp test_vector/*.cpp

clean:
	rm -rf *.o *.a *.out *.gcda *.gcno *.info *.dSYM *.info report *.exe $(TEST)
