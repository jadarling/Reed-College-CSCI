        .text
        .align 2
        .globl main

main:
        li $v0, 5             #user input value set to syscall
        syscall               #ask user for input
        move $t0, $v0         #move value to empty register
        blt  $t0, $0, notPos  # go to notPos if a not positive  

        li $t1, 1             # set $t1 = 0 ('i')
        move $t2, $0          # set $t2 = 0 (sum)

loop:
        bgt $t1, $t0, print   #if i is greater than n, go to print
        add $t2, $t2, $t1     #add i to sum
        addi $t1, $t1, 1      #add 1 to i 
        b loop                #loop it

print:
        li   $v0, 1           # set up "print int" system call
        move $a0, $t2         # move $t2 (sum) to syscall variable 
        syscall               # execute system call
        jr $ra                #return to main
notPos:
        jr $ra                #return to main 