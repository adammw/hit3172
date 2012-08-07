.PHONY: run clean

JC := javac
SOURCES = Message.java Program.java
CLASSES = $(subst .java,.class,$(SOURCES))

all: $(CLASSES)

$(CLASSES): %.class: %.java
	$(JC) $(JFLAGS) $<

clean: 
	rm $(CLASSES)

run: 
	@java Program