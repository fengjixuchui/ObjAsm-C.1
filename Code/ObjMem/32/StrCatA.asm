; ==================================================================================================
; Title:      StrCatA.asm
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.0, October 2017
;               - First release.
;             Version C.1.1, July 2022
;               - Return value added.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

.code
; ��������������������������������������������������������������������������������������������������
; Procedure:  StrCatA
; Purpose:    Concatenate 2 ANSI strings.
; Arguments:  Arg1: Destrination ANSI buffer.
;             Arg2: Source ANSI string.
; Return:     eax = Number of added BYTEs.

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align ALIGN_CODE
StrCatA proc pDstStrA:POINTER, pSrcStrA:POINTER
  invoke StrEndA, [esp + 4]                             ;pDstStrA
  invoke StrCopyA, eax, [esp + 8]                       ;pSrcStrA
  sub eax, sizeof(CHRA)                                 ;Sizeof ZTC
  ret 8
StrCatA endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

end
