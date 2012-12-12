shellcodeasm:shellcodeasm.c
	gcc -static -m32 -o shellcodeasm -g -ggdb shellcodeasm.c
testsc: testsc.c
	gcc -m32 -z execstack -o $@ testsc.c
shellcode: shellcode.c
	gcc -static -m32 -g -o $@ $<
clean:
	rm shellcodeasm testsc shellcode
