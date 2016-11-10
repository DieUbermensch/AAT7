	.global _FIR, _FXLMS;

;------------------------------------------------------
;		void FIR(Int16 *x,	=> AR0
;			   	   Int16 *b, 	=> AR1
;				   Int16 N, 	=> T0
;				   Int16 i)		=> T1



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
    
_FXLMS:
	NOP
	RET


	
	
