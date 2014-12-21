CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))
CC_FLAGS := -MMD -Wall -g -std=c++11 -I include

-include obj/$(wildcard *.d)

all: lib/libflexium.a

lib/libflexium.a: $(OBJ_FILES)
	ar -rs $@ $^

obj/%.o: src/%.cpp
	g++ -c -o $@ $< $(CC_FLAGS)

clean:
	del obj\*.o
	del obj\*.d

demo: lib/libflexium.a demo/Demo.cpp
	g++ -Wall -g -c demo/Demo.cpp -I include -std=c++11 -o demo/Demo.o
	g++ -o demo/demo.exe demo/Demo.o -L ../Flexium/lib -lFlexium -lSFML-System -lSFML-Window -lSFML-Graphics -lSFML-Audio