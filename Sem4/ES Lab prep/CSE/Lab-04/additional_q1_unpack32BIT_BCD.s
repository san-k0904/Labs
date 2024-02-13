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
	LDR R0,=SRC
	LDR R1,=DST
	MOV R5,#4
L1	LDRB R2,[R0],#1
	AND R3,R2,#0XF
	AND R4,R2,#0XF0
	LSR R4,#4
	STRB R3,[R1],#1
	STRB R4,[R1],#1
	SUBS R5,#1
	BNE L1
STOP B STOP
SRC DCD 0X12345678
	AREA my_data,DATA,READWRITE
DST DCD 0
	END