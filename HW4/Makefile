SOURCE_FILES := $(wildcard *.cpp)
OBJECT_FILES := $(patsubst %.cpp, %.o, $(SOURCE_FILES))

hw4: $(OBJECT_FILES)
	g++ -o hw4 $(OBJECT_FILES)

%.o: %.cpp
	g++ -c $<

clean:
	rm -f *.o hw4
