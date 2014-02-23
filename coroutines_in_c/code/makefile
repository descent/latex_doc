CC=gcc
TARGET=cr_by_goto cr_by_duff_device cr_test
all: $(TARGET)

cr_test: cr_test.o
	$(CC) -o $@ $<
cr_test.o: cr_test.c
	$(CC) -c $<

cr_by_goto: cr_by_goto.o
	$(CC) -o $@ $<

cr_by_goto.o: cr_by_goto.c
	$(CC) -c $<

cr_by_duff_device: cr_by_duff_device.o
	$(CC) -o $@ $<
cr_by_duff_device.o: cr_by_duff_device.c
	$(CC) -c $<
clean:
	rm -rf *.o $(TARGET)
