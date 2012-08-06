.PHONY: run clean

SRCS = Message.m Program.m
OBJS = $(subst .m,.o,$(SRCS))
BIN = HelloWorld.bin

all: $(BIN)

$(BIN): $(OBJS)
	clang -o $(BIN) $(OBJS) -framework Foundation -fobjc-arc

$(OBJS): %.o: %.m
	clang -c $< -o $@

clean:
	rm $(BIN)
	rm $(OBJS)

run: $(BIN)
	@./$(BIN)