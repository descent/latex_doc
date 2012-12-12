shellcodeasm:shellcodeasm.c
	gcc -static -m32 -o shellcodeasm -g -ggdb shellcodeasm.c
testsc: testsc.c
	gcc -m32 -z execstack -o $@ testsc.c
clean:
	rm shellcodeasm testsc
