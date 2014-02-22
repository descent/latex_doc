CC=gcc
TARGET=cr_by_goto
cr_by_goto: cr_by_goto.o
	$(CC) -o $@ $<

cr_by_goto.o: cr_by_goto.c
	$(CC) -c $<

clean:
	rm -rf *.o $(TARGET)
