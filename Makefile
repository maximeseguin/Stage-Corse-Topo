CC = gcc
CFLAGS = -g -Wall -ansi -pedantic -lm
LDFLAGS = `xml2-config --cflags --libs`
EXEC = dom_ouvrir

pregama: pregama.c
	gcc $< $(CFLAGS) $(LDFLAGS) -o $@

dom_ouvrir: dom_ouvrir.c
	gcc $< $(CFLAGS) $(LDFLAGS) -o $@

clean:
	rm $(EXEC)
