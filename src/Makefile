FLAGS= -Wall -Wextra -Werror -std=c++17
TEST_FLAGS += -pthread -lgtest_main -lgtest
FILES= $(wildcard *.cc)
OBJ=$(patsubst %.cc,%.o,${FILES})
UNAME := $(shell uname)
GCO= --coverage

all: s21_matrix_oop.a test gcov_report Leaks

s21_matrix_oop.a: clean
	g++ -c $(FLAGS) $(FILES)
	ar crv s21_matrix_oop.a $(OBJ)
	rm -rf *.o

main: clean
	g++ -g $(STDFLAGS) -o main -std=c++17 *.cc
	./main

test: s21_matrix_oop.a
	g++ -g $(TEST_FLAGS) -o test $(FILES) tests/*.cc
	./test

gcov_report: clean
	g++ $(TEST_FLAGS) $(GCO) -o report *.cc tests/*.cc
	./report
	lcov -c -d . -o coverage.info --ignore-errors mismatch
	genhtml coverage.info --output-directory=res 
	open ./res/index.html
	rm -rf *.gcda *.gcno

install_brew:
	cd ~
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh

lcov_install:
	brew install lcov

clean:
	rm -rf *.o *.a matrix s21_matrix_oop test *.dSYM *.gcda *.gcno *.info report res

leaks:
	CK_FORK=no leaks --atExit -- ./test

style:
	clang-format -style=Google -n *.h *.cc 
	cd matrix_test && clang-format -style=Google -n *.h *.cc

style_setup:
	clang-format -style=Google -i *.h *.cc 
	cd tests && clang-format -style=Google -i *.h *.cc 

git:
	@echo "Enter commit message: "
	@read COMMENT;
	cd ..
	git add .
	git commit -m "$$COMMENT Commit on `date +'%Y-%m-%d %H:%M:%S'`"
	git push origin develop