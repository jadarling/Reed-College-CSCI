        
        .data
        .text
        .align 2
        .globl main
main:
        li $v0, 5
        syscall
        move $t0, $v1   

        li $v0, 5
        syscall 
        move $t1, $v0

        bge $t1, $t0, foo
        move $a0, $t0
        li $v0, 1
        syscall
        jr $ra
foo:
        move $a0, $t1
        li $v0, 1
        syscall
        jr $ra



    


