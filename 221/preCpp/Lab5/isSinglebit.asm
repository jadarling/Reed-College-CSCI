        
        .data
        .text
        .align 2
        .globl main
takeinput:
    li $v0, 5
    syscall
    ble  $v0, $0, false
    beq $v0, 1, true
    jr $ra

main:
    addiu $sp, $sp, -4 #MAIN START AAAAAAAA
    sw $ra, 0($sp) 
    jal takeinput
    li $t0, 2 

    div $t0, $v0, $t0

    beq $t0, 0, isEven
    jal false
    jr $ra
isEven: 
    li $t1, 2 #AAaaaaaA iseven start
    bgt $t1, $v0, false
    beq $t1, $v0, true
    sll $t1, $t1, 1
    b isEven

false:
    lw    $ra, 0($sp) #FALSE FALSE FALSE
    addiu $sp, $sp, 4
    move $v0, $0
    jr $ra
true:
    lw    $ra, 0($sp) #TRUE TRUE TRUE
    addiu $sp, $sp, 4
    li $v0, 1
    jr $ra
