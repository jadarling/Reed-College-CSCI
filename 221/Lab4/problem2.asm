        .data
x:      .word 7
y:      .word 5

        .text
        .align 2
        .globl main
main:
    la $t0, x
    lw $t0, 0($t0)
    la $t1, y
    lw $t1, 0($t1)
    sub $a0, $t0, $t1
    li $v0, 1
    syscall
    jr $ra

