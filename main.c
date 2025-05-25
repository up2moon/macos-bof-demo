#include <stdio.h>
#include <unistd.h>

void func()
{
    asm volatile(
        "sub x25, sp, #0x228\n"
        "ldr x30, [sp], #0x10\n"
        "ret\n"

        "mov x0, xzr\n"
        "ldr x30, [sp], #0x10\n"
        "ret\n"

        "mov x1, #0x400\n"
        "ldr x30, [sp], #0x10\n"
        "ret\n"

        "mov x2, #0x3\n"
        "ldr x30, [sp], #0x10\n"
        "ret\n"

        "mov x3, #0x1002\n"
        "ldr x30, [sp], #0x10\n"
        "ret\n"

        "mov x4, #-0x1\n"
        "ldr x30, [sp], #0x10\n"
        "ret\n"

        "mov x5, xzr\n"
        "ldr x30, [sp], #0x10\n"
        "ret\n"

        "bl _mmap\n"
        "ldr x30, [sp], #0x10\n"
        "ret\n"

        "mov x19, x0\n"
        "ldr x30, [sp], #0x10\n"
        "ret\n"

        "mov x1, x25\n"
        "ldr x30, [sp], #0x10\n"
        "ret\n"

        "mov x2, #0x400\n"
        "ldr x30, [sp], #0x10\n"
        "ret\n"

        "bl _memcpy\n"
        "ldr x30, [sp], #0x10\n"
        "ret\n"

        "mov x0, x19\n"
        "ldr x30, [sp], #0x10\n"
        "ret\n"

        "mov x2, #0x5\n"
        "ldr x30, [sp], #0x10\n"
        "ret\n"

        "bl _mprotect\n"
        "ldr x30, [sp], #0x10\n"
        "ret\n"

        "br x0\n"

    );
}

int main(int argc, char **argv)
{
    char buf[512];
    int size = 1024;

    read(0, buf, size);
    printf(buf);

    read(0, buf, size);
    printf(buf);

    return 0;
}
