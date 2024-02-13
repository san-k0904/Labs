 	AREA RESET, DATA,READONLY
	EXPORT __Vectors
__Vectors
	DCD 0X10001000
	DCD Reset_Handler
	ALIGN
	AREA mycode,CODE,READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R0,=SRC
	LDR R1,=DST
	MOV R2,#10
SUM RN R4
	MOV SUM,#0
L1	LDR R3,[R0],#4
	ADCS SUM,R3
	SUBS R2,#1
	BNE L1
	STR SUM,[R1]
STOP B STOP
SRC DCD 0X1,0X2,0X3,0X4,0X5,0X6,0X7,0X8,0X9,0XA
	AREA my_data,DATA,READWRITE
DST DCD 0 
	END