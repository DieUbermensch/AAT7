	.global _FIR, _FXLMS;

;------------------------------------------------------
;	Int16 FIR(Int16 *x,	=> AR0
;			  Int16 *b, => AR1
;			  Int16 N, 	=> T0
;			  Int16 i)	=> T1

_FIR:	
	MOV #0, AC0					; Clear AC1
	MOV mmap(AR0),BSA01			; Set base Adress for buffer
	MOV mmap(T0), BK03			; Set buffer size to filter order
	MOV *(#T1),AR0				; Start from ith sample
	bset AR0LC					; Set pointer as circular
	SUB #1,T0					; Setup Repititions
	MOV T0,CSR					; Setup Repititions
	RPT CSR						; Repeat order times
	MAC *AR0-,*AR1+,AC0 		; Do filter convolution
	SFTL AC0, #-15				; Bit shift to fit Q15
	MOV AC0,T0					; Output sample
    RET
    
;-----------------------------------------------------    
;	void FXLMS(Int16 *x, => AR0
;			   Int16 *b, => AR1
;			   Int16  e, => T0
;			   Int16  i, => T1
;			   Int16  uN)=> AR2

    
_FXLMS:
	MOV *AR2+, T2 ; u => T2
	MOV *AR2,  T3 ; N => T3
	;Circular buffer setup
	MOV #0, AC0					; Clear AC1
	MOV mmap(AR0),BSA01			; Set base Adress for buffer
	MOV mmap(T3), BK03			; Set buffer size to filter order
	MOV *(#T1),AR0				; Start from ith sample
	bset AR0LC					; Set pointer as circular
	;2u*e
	MOV T0,AC0					; Move e to AC0			
	SFTL AC0, #16				; Shift to high
	MPY T2,AC0,AC0				; Multiply -2u*e
	SFTL AC0, #-15				; Bit shift to fit Q15
	MOV AC0, AR3				; Move to AR3
	;x(k-j)*(2u*e) - b(j)
	SUB #1,T3					; Setup Repititions
	MOV T3, BRC0				; Setup Repititions
	rptblocal loop-1			; Repeat loop N times
	MOV *AR1, AC1				; Move b(i) coef to AC1
	MAC *AR0-,*AR3,AC1			; Find new b(i) coef
	SFTL AC1, #-15				; Bit shift to fit Q15
	MOV AC1,*AR1+ 				; Place the new b(i) at old b(i) 
loop
	
	RET

	
;-----------------------------------------------------
	
	
