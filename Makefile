CC=g++
CPPFLAGS=-Iinclude/ -Wall -std=c++11 -g
LDFLAGS=

all: dir test_hybridtrie test_briandaistrie

dir:
	mkdir -p bin/ obj/

clean:
	rm -f obj/*.o bin/*

check: all
	./bin/test_hybridtrie
	./bin/test_briandaistrie

test_hybridtrie: obj/hybridtrie.o obj/briandaistrie.o obj/test_hybridtrie.o obj/test.o
	$(CC) -o bin/$@ $^ $(LDFLAGS)

test_briandaistrie: obj/hybridtrie.o obj/briandaistrie.o obj/test_briandaistrie.o obj/test.o
	$(CC) -o bin/$@ $^ $(LDFLAGS)

obj/%.o: src/%.cpp
	$(CC) -o $@ -c $< $(CPPFLAGS)
