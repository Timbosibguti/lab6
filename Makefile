.PHONY: clean app test prepare

bin/main: prepare obj/main.o obj/app.o
	gcc -Wall -o bin/main obj/main.o obj/app.o -lm
	
bin/test: prepare obj/app.o obj/app_test.o obj/ctest.o
	gcc -Wall -o bin/test obj/app.o obj/app_test.o obj/ctest.o -lm
	
obj/main.o: prepare src/main.c
	gcc -Wall -c src/main.c -o obj/main.o
	
obj/app.o: prepare src/app.c
	gcc -Wall -c src/app.c -o obj/app.o

obj/app_test.o: prepare test/app_test.c
	gcc -Wall -c test/app_test.c -o obj/app_test.o -Ithirdparty -Isrc
	
obj/ctest.o: prepare test/ctest.c
	gcc -Wall -c test/ctest.c -o obj/ctest.o -Ithirdparty
	
clean:
	rm -f bin/* obj/*
	
app: bin/main
	bin/main
	
test: bin/test
	bin/test
	
prepare: bin obj

bin:
	mkdir bin
	
obj:
	mkdir obj