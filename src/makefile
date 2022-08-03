CC=g++
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

test: clean
	cd test/
	$(CC) test/*.cpp -o $(OUT) $(LIBS)
	make run

gcov_report: clean
	$(CC) -o $(OUT) --coverage $(CORE) test/*.cpp $(LIBS)
	make run
	lcov -t "matrix_test" -o test.info -c -d .
	lcov -q --remove test.info "/usr/include/*" -o test.info
	lcov -q --remove test.info "/usr/local/*" -o test.info
	genhtml -o report test.info

clean:
	rm -rf *.o *.a *.out *.gcda *.gcno *.info *.dSYM *.info report build

run:
	./$(OUT)

check: 
	cp ../materials/linters/CPPLINT.cfg ./CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extension=cpp test/*.cpp test/*.h lib/*.inl lib/*.h
	cppcheck --enable=all --language=c++ --suppress=missingIncludeSystem --suppress=unusedFunction test/*.cpp test/*.h lib/*.cpp lib/*.h

leaks: test
	$(LEAKS)  ./$(OUT)
