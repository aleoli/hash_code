OBJECTS = bin/main.o bin/hs.o bin/dependencies.o bin/veicolo.o bin/map.o bin/reader.o bin/direction.o bin/output.o

CPPFLAGS = 
LDLIBS = 

CC = g++

PROGRAM_NAME = hash_code

build: $(OBJECTS)
	$(CC) -Wall -std=c++11 $(CPPFLAGS) -o bin/$(PROGRAM_NAME) $(OBJECTS) $(LDLIBS)

bin/%.o: src/%.cpp
	$(CC) -Wall -std=c++11 $(CPPFLAGS) -c -o bin/$*.o src/$*.cpp $(LDLIBS)

run: build
	@bin/$(PROGRAM_NAME)

clear:
	@rm bin/*.o
	@rm bin/$(PROGRAM_NAME)
