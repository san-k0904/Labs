	AREA RESET,DATA,READONLY
	EXPORT __Vectors
__Vectors
	DCD 0X10001000
	DCD Reset_Handler
	ALIGN
	AREA my_code,CODE,READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R0,=VAL1
	LDR R1,=VAL2
	LDR R8,=UNPACKED_RES
	LDR R2,[R0]
	LDR R3,[R1]
	MUL R4,R2,R3
COUNTER RN R5
CARRY RN R6
	MOV COUNTER,#4
L1	BL MASKING
	STRB R7,[R8],#1
	SUBS COUNTER,#1
	BNE L1
	LDR R8,=UNPACKED_RES
	LDR R9,=PACKED_RES
	MOV COUNTER,#2
L2	BL PACKED
	STRB R11,[R9],#1
	SUBS COUNTER,#1
	BNE L2
STOP B STOP

MASKING
	AND R7,R4,#0XF
	ADD R7,CARRY
	MOV CARRY,#0
	CMP R7,#0XA
	BLO MASK_L1
	MOV CARRY,#1
	SUB R7,#0XA
MASK_L1	LSR R4,#4
	BX LR
PACKED
	LDRB R10,[R8],#1
	LDRB R11,[R8],#1
	LSL R11,#4
	ADD R11,R10
	BX LR
VAL1 DCD 0X8
VAL2 DCD 0X9
	AREA my_data,DATA,READWRITE
UNPACKED_RES DCD 0
PACKED_RES DCD 0
	END