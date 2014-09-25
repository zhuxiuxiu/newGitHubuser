
all:
	gcc linktable.c menu.c test.c -o test
clean:
	rm -rf *.o test
			
