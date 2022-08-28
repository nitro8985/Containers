CC=g++
STD=-std=c++17
OUT=test.out
OS=$(shell uname)
ifeq ($(OS), Linux)
	LIBS=-lgtest
	OPEN=xdg-open
	LEAKS=CK_FORK=no valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --show-reachable=yes
else
    LIBS=-lgtest
	OPEN=open
	LEAKS=CK_FORK=no leaks --atExit --
endif

debug: clean
	$(CC) -g $(STD) *.cpp -o $(OUT) $(LIBS)
# make run

test: clean
#	cd test/
	$(CC) $(STD) *.cpp -o $(OUT) $(LIBS)
	make run

gcov_report: clean
	$(CC) $(STD) -o $(OUT) --coverage $(CORE) *.cpp $(LIBS)
	make run
	lcov -t "matrix_test" -o test.info -c -d .
	lcov -q --remove test.info "/usr/include/*" -o test.info
	genhtml -o report test.info

clean:
	rm -rf *.o *.a *.out *.gcda *.gcno *.info *.dSYM *.info report build

run:
	./$(OUT)

check: 
	cp ../../../materials/linters/CPPLINT.cfg ./CPPLINT.cfg
	python3 ../../../materials/linters/cpplint.py --extension=cpp,h test.cpp ../list.h
	cppcheck --enable=all --language=c++ --suppress=missingIncludeSystem --suppress=unusedFunction test/*.cpp test/*.h lib/*.cpp lib/*.h

leaks: debug
	$(LEAKS) ./$(OUT)
