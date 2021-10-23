; ------------------------------------------------------------------------
;|AniGIF is a copyright of Antonis Kyprianou.                             |
;|                                                                        |
;|You can use AniGIF for NON commercial purposes provided you             |
;|have the following information on your application's about box:         |
;|AniGIF control is copyright of Antonis Kyprianou (http://www.winasm.net)|
;|                                                                        |
;|You need my WRITTEN permission to use AniGIF in commercial applications |
; ------------------------------------------------------------------------

IPicture STRUCT
    ;IUnknown methods
    QueryInterface          DWORD   ?
    AddRef                  DWORD   ?
    Release                 DWORD   ?
    ;IPicture methods
    get_Handle              DWORD   ?
    get_hPal                DWORD   ?
    get_Type                DWORD   ?
    get_Width               DWORD   ?
    get_Height              DWORD   ?
    Render                  DWORD   ?	
    set_hPal                DWORD   ?
    get_CurDC               DWORD   ?
    SelectPicture           DWORD   ?
    get_KeepOriginalFormat  DWORD   ?
    put_KeepOriginalFormat  DWORD   ?
    PictureChanged          DWORD   ?
    SaveAsFile              DWORD   ?
    get_Attributes          DWORD   ?
IPicture ENDS

HIMETRIC_INCH					EQU 2540

BIT8							EQU 128
BIT7							EQU 64
BIT6							EQU 32
BIT5							EQU 16
BIT4							EQU 8
BIT3							EQU 4
BIT2							EQU 2
BIT1							EQU 1

GIFSIGNATURELENGTH				EQU 6 ;bytes
SCREENWIDTHLENGTH				EQU 2 ;bytes
SCREENHEIGHTLENGTH				EQU 2 ;bytes

IMAGESEPARATOR					EQU 2CH	; ','
EXTENSIONINTRODUCER				EQU 21H	
APPLICATIONEXTENSION			EQU 0FFH
COMMENTEXTENSION				EQU 0FEH
GRAPHICCONTROLEXTENSION			EQU 0F9H
PLAINTEXTEXTENSION				EQU 1H

GRAPHICCONTROLEXTENSIONLENGTH	EQU 7
TRAILER							EQU 3BH
IMAGEDESCRIPTORLENGTH			EQU 10

FRAME STRUCT
	ImageLeft				DWORD	?
	ImageTop				DWORD	?
	ImageWidth				DWORD	?
	ImageHeight				DWORD	?
	LSortFlag				BOOLEAN	?
	LocalColorTableFlag		BOOLEAN	?
	InterLaceFlag			BOOLEAN	?
	LZWMinimumCodeSize		BYTE	?
	DelayTime				WORD	?
	TransparentColorIndex	BYTE	?
	TransparentColor		DWORD	?	;Transparent Color resulting from TransparentColorIndex

	DisposalMethod			BYTE	?
	UserInputFlag			BOOLEAN	?
	TransparentColorFlag	BOOLEAN	?
	GifStart				DWORD	?
	GifEnd					DWORD	?
	hBitMap					DWORD	?
	ColorTable				DB		768+1 DUP (?)	;Max 256 Colors of 8bitx3 RGB triplets values
FRAME ENDS


GIFDATA STRUCT
	hDCBuffer					DWORD	?
	hOriginalBitMap				DWORD	?
	BkColor						DWORD	?					;color specified by the user

	szHyperlink					DB		MAX_PATH+1 DUP (?)	;<-------Is it enough?

	ViewRect					RECT	<>
	ZoomFactor					DWORD	?					;0,1=+10%, 2=+20%, 3=+30%,...
	
	Screen						RECT	<>
	BackgroundColorIndex		BYTE	?					;Background=Color index of screen background (color is defined from the Global color map or default map if none specified)
	SizeOfGlobalTableInBytes	DWORD ?
	GSortFlag					BOOLEAN	?
	ColorResolution				BYTE	?					;Color Resolution bits
	GlobalColorTableFlag	 	BOOLEAN	?
	GlobalColorTable			DWORD	768+1 DUP (?)		;Max 256 Colors of 8bitx3 RGB triplets values
	NumberOfFrames				DWORD	?
	lpFrames					DWORD	?
	dwCurrentFrame				DWORD	?
GIFDATA ENDS


.DATA
szControlName					DB "AniGIF",0
szZero							DB "0",0
szDummyControlBlock				DB "21F9",0;DB "F921",0
szTrailerBlock					DB "3B",0

szErrorLoadingFile				DB "Error loading file.",0
;szErrorLoadingResource			DB "Error loading resource.",0
szErrorNotAValidSignature		DB "This file has not a valid Gif signature.",0
szFatalError					DB "Fatal error.",0

sIID_IPicture					TEXTEQU <{07BF80980H, 0BF32H, 0101AH, {08BH, 0BBH, 000H, 0AAH, 000H, 030H, 00CH, 0ABH}}>
                             
IID_IPicture					GUID sIID_IPicture

szOpen							DB "open",0

.DATA?
hHeap							DWORD ?
hInstance						HINSTANCE ?