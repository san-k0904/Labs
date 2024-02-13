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
	LDRB R1,[R0]
	LDR R2,=DST
	MOV R4,#2
L1	AND R3,R1,#0XF
	LSR R1,#4;
	SUBS R4,#1 
	CMP R3,#0X9
	BLS L2
	ADD R3,#0X7
L2	ADD R3,#0X30
	STRB R3,[R2],#1
	BNE L1
STOP B STOP
SRC DCB 0X23
	AREA my_data,DATA,READWRITE
DST DCW 0
	END
	