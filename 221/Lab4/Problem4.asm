# This program read in two positive integers, a and b, from the user and
# prints a * b
    .text
    .align 2
    .globl main
main:
    li   $v0, 5          # set up reading of first int
    syscall
    move $t0, $v0        # store first int, a, into $t0
    blt  $t0, $0, done   # go to done if a not positive

    li   $v0, 5          # set up reading of first int
    syscall
    move $t1, $v0        # store first int, b, into $t1
    blt  $t1, $0, done   # go to done if b not positive

    move $v0, $0
    move $t2, $0
loop:
    beq  $v0, $t1, print
    add  $t2, $t2, $t0
    addi  $v0, $v0, 1
    b loop

print:
    li   $v0, 1       # set up "print int" system call
    move $a0, $t0
    syscall           # execute system call

done:
    jr   $ra          # return from main method
