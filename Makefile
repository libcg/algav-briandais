CC=g++
CPPFLAGS=-Iinclude/ -Wall -std=c++11 -g
LDFLAGS=

all: hybridtrie_test

clean:
	rm obj/*.o $(EXEC)

check: hybridtrie_test
	./bin/hybridtrie_test

hybridtrie_test: obj/hybridtrie.o obj/hybridtrie_test.o
	$(CC) -o bin/$@ $^ $(LDFLAGS)

obj/%.o: src/%.cpp
	$(CC) -o $@ -c $< $(CPPFLAGS)
