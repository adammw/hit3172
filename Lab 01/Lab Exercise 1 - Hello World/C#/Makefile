.PHONY: run clean

CSC := gmcs
SRCS = Message.cs program.cs
BIN = HelloWorld.exe

all: $(BIN)

$(BIN): $(SRCS)
	$(CSC) $(CSC_FLAGS) -out:$(BIN) -target:exe $(SRCS)

clean:
	rm $(BIN)

run: $(BIN)
	@mono $(BIN)