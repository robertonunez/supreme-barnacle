# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS = -g -Wall -std=c++11

# the build target executable and its dependencies:
TARGET = net
DEPENDS = train

all: $(DEPENDS) $(TARGET)

$(TARGET): $(TARGET).cpp ; $(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp ; ./train ; ./net

$(DEPENDS): $(DEPENDS).cpp ; $(CC) $(CFLAGS) -o $(DEPENDS) $(DEPENDS).cpp

clean: ; $(RM) $(TARGET) ; $(RM) $(DEPENDS) ; $(RM) ./trainingData.txt ; $(RM) ./*.stackdump
