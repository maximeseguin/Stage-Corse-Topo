CC = gcc
CFLAGS = -g -Wall -ansi -pedantic
LDFLAGS = `xml2-config --cflags --libs`
EXEC = pregama

pregama: pregama.c
	gcc $< $(CFLAGS) $(LDFLAGS) -o $@

clean:
	rm $(EXEC)
