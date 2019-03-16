# round two (here we go)

CPPFLAGS=-std=c++14 -Wall 
CC=g++
C2FLGS=--success --use-colour yes
TEST1=[basic]
TEST2=[notbasic]
TEST3=[notnotbasic]

all: src/main.cpp src/modules.hpp
	$(CC) $(CPPFLAGS) -o bin/crack.out src/main.cpp -lcrypto 
	

run:
	@if test -z "$$files"; then bin/crack.out; else cat $$files | bin/crack.out ; fi

tests:  bin/tests.out
	@bin/tests.out $(C2FLGS) 

test1:  bin/tests.out
	@bin/tests.out $(TEST1) $(C2FLGS) 

test2:  bin/tests.out
	@bin/tests.out $(TEST2) $(C2FLGS) 

test3: bin/tests.out
	@bin/tests.out $(TEST3) $(C2FLGS)

bin/tests.out: bin/tests.o
	@printf "\033[33mCompiling Tests...\n\033[0m"	
	$(CC) $(CPPFLAGS) -o bin/tests.out bin/tests.o tests/tests.cpp -lcrypto 

bin/tests.o: tests/tests.cpp tests/tests_main.cpp 
	@printf "\033[36mCompiling Test Driver...(be patient)...\n\033[0m"	
	$(CC) $(CPPFLAGS)  -c tests/tests_main.cpp -o bin/tests.o

clean:
	@printf "\033[31mRemoving objects (and temporary files)\033[0m\n"
	@rm -rf bin/*.o*

warn: src/main.cpp src/modules.hpp
	@printf "Number of warnings: "
	@$(CC) $(CPPFLAGS) -o bin/crack.out src/main.cpp -lcrypto 2>&1  | grep warning|wc -l

#.PHONY: notes
#notes:
#	...
