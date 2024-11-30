CFLAGS = -std=c99 -O2 -Wall -Wextra -Wpedantic -pipe -ggdb
DAY ?= day1

all: $(DAY)

run: $(DAY)
	./$(DAY)

$(DAY).o: $(DAY).c
	$(CC) -o $@ -c $< $(CFLAGS)

$(DAY): $(DAY).o
	$(CC) -o $@ $<

clean:
	rm -f $(DAY).o $(DAY)

.PHONY: all clean run
