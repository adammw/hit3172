.PHONY: run clean

CXX := g++
SRCS = message.cpp program.cpp
OBJS = $(subst .cpp,.o,$(SRCS))
BIN = HelloWorld.bin

all: $(BIN)

$(BIN): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(BIN) $(OBJS) $(LDFLAGS) $(LIBS)

$(OBJS): %.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@ $(LDFLAGS) $(LIBS)

clean:
	rm $(BIN)
	rm $(OBJS)

run: $(BIN)
	@./$(BIN)