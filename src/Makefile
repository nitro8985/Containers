CC=g++
OUT=test.out
STD=-std=c++17
OS=$(shell uname)
ifeq ($(OS), Linux)
	LIBS=-lgtest -lpthread
	OPEN=xdg-open
	LEAKS=CK_FORK=no valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --show-reachable=yes
else
    LIBS=-lgtest
	OPEN=open
	LEAKS=CK_FORK=no leaks --atExit --
endif

test: clean
	cd test/
	$(CC) $(STD) test/*.cpp -o $(OUT) $(LIBS)
	make run

gcov_report: clean
	$(CC) $(STD) -o $(OUT) --coverage test/*.cpp $(LIBS)
	make run
	lcov -t "container_test" -o test.info -c -d . --rc lcov_function_coverage=0
	lcov -q --remove test.info "/usr/include/*" -o test.info --rc lcov_function_coverage=0
	lcov -q --remove test.info "/usr/local/*" -o test.info --rc lcov_function_coverage=0
	genhtml -o report test.info --rc lcov_function_coverage=0

clean:
	rm -rf *.o *.a *.out *.gcda *.gcno *.info *.dSYM *.info report build

run:
	./$(OUT)

cppcheck: 
	cppcheck --enable=all --language=c++ --suppress=missingIncludeSystem test/*.cpp test/*.h lib/*.tcc lib/*.h

cpplint:
	cp ../materials/linters/CPPLINT.cfg ./CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extension=cpp,tcc test/*.cpp test/*.h lib/*

check: cpplint cppcheck

valgrind: clean test
	CK_FORK=no valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --show-reachable=yes ./test.out

leaks: test
	$(LEAKS)  ./$(OUT)
