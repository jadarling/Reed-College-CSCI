        .text
        .align 2
        .globl main

main:
        li $v0, 5           #user input value set to syscall
        syscall             #ask user for input
        move $t0, $v0       #move value to empty register (x)
        blt  $t0, $0, notPos# go to notPos if a not positive 
        
        move $t1, $0        # set $t1 = 0 ('i')
        move $t2, $0        #set $t2 = 0 
max:
        beq $t0, $t1, print #loop for 'x' inputs
        li $v0, 5           #user input value set to syscall
        syscall             #ask user for input
        addi $t1, 1         # add one to 'i'
        bge $t2, $v0, max   # if the max is still the last value, run it back
        move $t2, $v0       #else, put the new max in $t2
        b max               #run it back 

print:
        li   $v0, 1       # set up "print int" system call
        move $a0, $t2     # move $t2 (sum) to syscall variable 
        syscall           # execute system call
        jr $ra
notPos:
        jr $ra