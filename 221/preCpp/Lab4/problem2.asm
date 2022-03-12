        .data
x:      .word 7         #global variable x has integer value 7
y:      .word 5         #global variable y has integer value 5

        .text           #Start code
        .align 2
        .globl main
main:
    la $t0, x           #assign register $t0 = x
    lw $t0, 0($t0)      #load word value to $t0
    la $t1, y           #assign register $t1 = y
    lw $t1, 0($t1)      #load word value to $t1
    sub $a0, $t0, $t1   #Compute substraction
    li $v0, 1           #'print' value set to syscall
    syscall             #print to console
    jr $ra              #return main 

