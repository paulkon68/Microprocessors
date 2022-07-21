# Bubblesort Algorithm in MIPS Assembly Language
	
.data
msg1: .asciiz "\nEnter integer values (press enter after every input): \n"
msg2: .asciiz "|"
msg3: .asciiz "\nEnter the size of the array:\n"
msg6: .asciiz "\nThe sorted array:\n"

        .text 				
		.globl main
main:
	move $s0,$gp			# get the initial point to save array 
	addi $t0,1	            # initialization of variables		    
	add $t1,$zero,$zero		
	add $t2,$zero,$zero		
	add $t3,$zero,$zero		         
	add $t4,$zero,$zero 
	add $t6,$zero,$zero       
	add $t7,$zero,$zero	      

	la $a0, msg3 # prints "\nEnter the size of the array:\n"
	li $v0, 4
	syscall

	li $v0, 5
	syscall
	move $t6, $v0 # $t6 now contains the size of the array

	li $v0,4		# prints "\nEnter integer values (press enter after every input): \n"
	la $a0,msg1		
	syscall		
	add $s1,$s0,$zero	# copy the pointer to the block of memory (where array will be stored) in $s1

# the following block loops n-times, where n is the size of the array

input:
	li $v0,5		# get the size of the array
	syscall		
	add $t7, $t7 ,1
	sb $v0,0($s1)	# put the value at the position pointed by $s1
	addi $s1,1		# move the $s1 pointer by one
	add $t5,$s1,$zero # $t5 stores the end value
	bne $t6,$t7, input # end of string run to bubblesort
	
bubblesort:
	add $t4,$s0,$zero # $t4 now holds the start of the array
	sub $s1,$s1,$t0   
	beq $s1,$s0,ending  	# We have sorted everything, because $s1 and $s0 
	add $s2,$s0,$zero		# now point to the same address, meaning we finished 
							# the compare.
	

internal_loop:
	lb $t1,0($s2)		# first element
	lb $t2,1($s2)		# second element
	slt $t3,$t2,$t1		# 
	beq $t3,$zero,nenum	# if swap is needed,swap the values, else continue to the next position
	sb $t2,0($s2)		# 
	sb $t1,1($s2)		#		

nenum:
	addi $s2,1		# point to the next location of the array
	bne $s2,$s1,internal_loop # while its not the end of the array, loop   
j bubblesort	

ending:
	li $v0,4		# prints "\nThe sorted array:\n"
	la $a0,msg6		
	syscall		

sornum: # print the sorted numbers of the array

	li $v0,1
	lb $a0,0($t4)
	syscall

	li $v0,4 # prints the '|' character between the sorted numbers
	la $a0,msg2 
	syscall		

	addi $t4,1
	bne $t4,$t5,sornum

	jr $ra	 # return control to the caller (exit the program)
	