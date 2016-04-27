.PHONY: clean app test

bin/main: obj/main.o obj/app.o
	gcc -Wall -o bin/main obj/main.o obj/app.o -lm
	
bin/test: obj/app.o obj/app_test.o obj/ctest.o
	gcc -Wall -o bin/test obj/app.o obj/app_test.o obj/ctest.o -lm
	
obj/main.o: src/main.c
	gcc -Wall -c src/main.c -o obj/main.o
	
obj/app.o: src/app.c
	gcc -Wall -c src/app.c -o obj/app.o

obj/app_test.o: test/app_test.c
	gcc -Wall -c test/app_test.c -o obj/app_test.o -Ithirdparty -Isrc
	
obj/ctest.o: test/ctest.c
	gcc -Wall -c test/ctest.c -o obj/ctest.o -Ithirdparty
	
clean:
	rm -f bin/* obj/*
	
app: bin/main
	bin/main
	
test: bin/test
	bin/test