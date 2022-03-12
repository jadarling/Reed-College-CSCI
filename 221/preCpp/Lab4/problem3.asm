        
        .data
        .text           #start code
        .align 2
        .globl main
main:
        li $v0, 5       #user input value set to syscall
        syscall         #ask user for input
        move $t0, $v1   #move value to empty register

        li $v0, 5       #user input value set to syscall
        syscall         #ask user for input
        move $t1, $v0   #move value to empty register

        bge $t1, $t0, foo       #branch initiate; if $t1 greater than, move to foo
        move $a0, $t0           #move the first value to syscall
        li $v0, 1               #print value set to syscall
        syscall                 #print syscall
        jr $ra                  #return
foo:
        move $a0, $t1           #move the second value to syscall
        li $v0, 1               #print value set to syscall
        syscall                 #print syscall
        jr $ra                  #return



    


