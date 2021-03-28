; ==================================================================================================
; Title:      StrCCatA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMem.cop

.code

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Procedure:  StrCCatA
; Purpose:    Concatenate 2 ANSI strings with length limitation.
;             The destination string buffer should have at least enough room for the maximum number
;             of characters + 1.
; Arguments:  Arg1: -> Destination ANSI character buffer.
;             Arg2: -> Source ANSI string.
;             Arg3: Maximal number of charachters that the destination string can hold including the
;                   ZTC.
; Return:     Nothing.

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align ALIGN_CODE
StrCCatA proc pBuffer:POINTER, pSrcStringA:POINTER, dMaxChars:DWORD
  invoke StrEndA, [esp + 4]
  mov ecx, [esp + 4]                                    ;ecx -> Buffer
  add ecx, [esp + 12]
  sub ecx, eax
  jbe @F                                                ;Destination is too small!
  invoke StrCCopyA, eax, [esp + 12], ecx
@@:
  ret 12
StrCCatA endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

end
