;*******************************************************************************
;
;        C Compiler for M16C/60
;       Copyright 1995-1998 MITSUBISHI ELECTRIC CORPORATION
;       AND MITSUBISHI ELECTRIC SEMICONDUCTOR SYSTEMS CORPORATION
;       All Rights Reserved.
;
;        Written by T.Aoyama
;
;       sect30.inc     : section definition
;       This program is applicable when using the basic I/O library
;
;       $Id: sect30.inc,v 1.7 97/11/05 11:27:23 ookura Exp $
;
;******************************************************************************
;---------------------------------------------------------------
;
;         Arrangement of section
;
;---------------------------------------------------------------
; Near RAM data area
;---------------------------------------------------------------
; SBDATA area
        .section        data_SE,DATA
        .org        400H
data_SE_top:

        .section        bss_SE,DATA,ALIGN
bss_SE_top:

        .section        data_SO,DATA
data_SO_top:

        .section        bss_SO,DATA
bss_SO_top:

; near RAM area
        .section        data_NE,DATA,ALIGN
data_NE_top:

        .section        bss_NE,DATA,ALIGN
bss_NE_top:

        .section        data_NO,DATA
data_NO_top:

        .section        bss_NO,DATA
bss_NO_top:

;---------------------------------------------------------------
; Stack area
;---------------------------------------------------------------
        .section        stack,DATA
        .blkb        STACKSIZE
stack_top:

        .blkb        ISTACKSIZE
istack_top:


;---------------------------------------------------------------
;        heap section
;---------------------------------------------------------------
        .section        heap,DATA
heap_top:
        .blkb        HEAPSIZE

;---------------------------------------------------------------
; Near ROM data area
;---------------------------------------------------------------
        .section        rom_NE,ROMDATA,ALIGN
rom_NE_top:

        .section        rom_NO,ROMDATA
rom_NO_top:

;---------------------------------------------------------------
; Far RAM data area
;---------------------------------------------------------------
        .section        data_FE,DATA
        .org                10000H
data_FE_top:

        .section        bss_FE,DATA,ALIGN
bss_FE_top:

        .section        data_FO,DATA
data_FO_top:

        .section        bss_FO,DATA
bss_FO_top:


;---------------------------------------------------------------
; Far ROM data area
;---------------------------------------------------------------
        .section        rom_FE,ROMDATA
        .org                0F0000H
rom_FE_top:

        .section        rom_FO,ROMDATA
rom_FO_top:

;---------------------------------------------------------------
; Initial data of 'data' section
;---------------------------------------------------------------
        .section        data_SEI,ROMDATA
data_SEI_top:

        .section        data_SOI,ROMDATA
data_SOI_top:

        .section        data_NEI,ROMDATA
data_NEI_top:

        .section        data_NOI,ROMDATA
data_NOI_top:

        .section        data_FEI,ROMDATA
data_FEI_top:

        .section        data_FOI,ROMDATA
data_FOI_top:

;---------------------------------------------------------------
; Switch Table Section
;---------------------------------------------------------------
        .section        switch_table,ROMDATA
switch_table_top:


;---------------------------------------------------------------
; code area
;---------------------------------------------------------------
        .section        interrupt

        .section        program

        .section        program_S

        .section        blal,ROMDATA
        .org            0FA000h

;---------------------------------------------------------------
; variable vector section
;---------------------------------------------------------------
        .section        vector                 ; variable vector table
        .org                VECTOR_ADR
        .lword                dummy_int                ; vector 0 (BRK)

        .org                (VECTOR_ADR +32)
        .lword               dummy_int

        .org                (VECTOR_ADR +36)
        .lword               dummy_int                            ; uart3 SPI


        .org                (VECTOR_ADR +44)
        .lword                dummy_int              ; DMA0 (for user)
        .lword                dummy_int              ; DMA1 2 (for user)
        .lword                dummy_int              ; input key (for user)
        .lword                dummy_int              ; AD Convert (for user)


        .org                (VECTOR_ADR +68)
        .lword                dummy_int              ; uart0 trance (for user)
        .lword                dummy_int              ; uart0 receive (for user)
        .lword                dummy_int              ; uart1 trance (for user)
        .lword                dummy_int              ; uart1 receive (for user)
        .glb            	  _TimerA0_InterruptHandler
        .lword                _TimerA0_InterruptHandler
        .lword                dummy_int              ; TIMER A1 (for user)
        .lword                dummy_int              ; TIMER A2 (for user)
        .lword                dummy_int              ; TIMER A3 (for user)
        .lword                dummy_int              ; TIMER A4 (for user) (vector 25)
        .lword                dummy_int              ; TIMER B0 (for user)  (vector 26)
        .lword                dummy_int              ; TIMER B1 (for user) (vector 27)
        .lword                dummy_int              ; TIMER B2 (for user) (vector 28)
        .lword                dummy_int              ; INT0 (for user) (vector 29)
        .lword                dummy_int              ; INT1 (for user) (vector 30)
        .lword                dummy_int              ; INT2 (for user) (vector 31)
        .lword                dummy_int              ; vector 32 (for user or MR30)
        .lword                dummy_int              ; vector 33 (for user or MR30)
        .lword                dummy_int              ; vector 34 (for user or MR30)
        .lword                dummy_int              ; vector 35 (for user or MR30)
        .lword                dummy_int              ; vector 36 (for user or MR30)
        .lword                dummy_int              ; vector 37 (for user or MR30)
        .lword                dummy_int              ; vector 38 (for user or MR30)
        .lword                dummy_int              ; vector 39 (for user or MR30)
        .lword                dummy_int              ; vector 40 (for user or MR30)
        .lword                dummy_int              ; vector 41 (for user or MR30)
        .lword                dummy_int              ; vector 42 (for user or MR30)
        .lword                dummy_int              ; vector 43 (for user or MR30)
        .lword                dummy_int              ; vector 44 (for user or MR30)
        .lword                dummy_int              ; vector 45 (for user or MR30)
        .lword                dummy_int              ; vector 46 (for user or MR30)
        .lword                dummy_int              ; vector 47 (for user or MR30)
        ; to vector 63 from vector 32 is used MR30

;===============================================================
; fixed vector section
;---------------------------------------------------------------
        .section        fvector                        ; fixed vector table
;===============================================================
; special page defination
;---------------------------------------------------------------
;        macro is defined in ncrt0.a30
;        Format: SPECIAL number
;
;---------------------------------------------------------------
;        SPECIAL 255
;        SPECIAL 254
;        SPECIAL 253
;           :
;           :
;        (omitted)
;           :
;           :
;        SPECIAL 24
;        SPECIAL 23
;        SPECIAL 22
;        SPECIAL 21
;        SPECIAL 20
;        SPECIAL 19
;        SPECIAL 18
;
;===============================================================
; fixed vector section
;---------------------------------------------------------------

        .org        0fffdch
UDI:
        .lword        dummy_int
OVER_FLOW:
        .lword        dummy_int
BRKI:
        .lword        dummy_int
ADDRESS_MATCH:
        .lword        dummy_int
SINGLE_STEP:
        .lword        dummy_int
WDT:
        .lword        dummy_int
DBC:
        .lword        dummy_int
NMI:
        .lword        dummy_int
RESET:
        .lword        start
;
;*******************************************************************************
;
;        C Compiler for M16C/60
;       Copyright 1995-1998 MITSUBISHI ELECTRIC CORPORATION
;       AND MITSUBISHI ELECTRIC SEMICONDUCTOR SYSTEMS CORPORATION
;       All Rights Reserved.
;
;*******************************************************************************