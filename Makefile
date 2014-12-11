CC=g++
CPPFLAGS=-Iinclude/ -Wall -std=c++11 -g
LDFLAGS=

all: test_hybridtrie

clean:
	rm -f obj/*.o bin/*

check: test_hybridtrie
	./bin/test_hybridtrie

test_hybridtrie: obj/hybridtrie.o obj/test_hybridtrie.o obj/test.o
	$(CC) -o bin/$@ $^ $(LDFLAGS)

obj/%.o: src/%.cpp
	$(CC) -o $@ -c $< $(CPPFLAGS)
