; ==================================================================================================
; Title:      StrECatA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

.code

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Procedure:  StrECatA
; Purpose:    Append an ANSI string to another and return the address of the ending zero character.
;             StrCatA does not perform any length checking. The destination buffer must have room
;             for at least StrLengthA(Destination) + StrLengthA(Source) + 1 characters.
; Arguments:  Arg1: -> Destination ANSI character buffer.
;             Arg2: -> Source ANSI string.
; Return:     eax -> Ending zero character.

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align ALIGN_CODE
StrECatA proc pBuffer:POINTER, pSrcStr:POINTER
  invoke StrEndA, [esp + 4]
  invoke StrECopyA, eax, [esp + 8]
  ret 8
StrECatA endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

end
