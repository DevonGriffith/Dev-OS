.386

.MODEL FLAT,STDCALL

OPTION CASEMAP:NONE

DEBUG EQU 0

;-------------------------------------------------------------------------
Include WINDOWS.INC
Include user32.inc
Include kernel32.inc
Include shell32.inc

Include gdi32.inc
Include ole32.inc
Include oleaut32.inc

;Needed For Debug Window Only
if DEBUG
	Include masm32.inc
	Include debug.inc
endif

;-------------------------------------------------------------------------
IncludeLib user32.lib
IncludeLib kernel32.lib
IncludeLib SHELL32.LIB

IncludeLib gdi32.lib
IncludeLib ole32.lib
IncludeLib oleaut32.lib

;Needed for debug
;----------------
if DEBUG
	IncludeLib masm32.lib
	IncludeLib debug.lib
endif
;-------------------------------------------------------------------------
