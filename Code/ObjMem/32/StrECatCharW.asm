; ==================================================================================================
; Title:      StrECatCharW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMem.cop

.code

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Procedure:  StrECatCharW
; Purpose:    Append a character to a WIDE string and return the address of the ending zero.
;             StrECatCharW does not perform any length checking. The destination buffer must have
;             enough room for at least StrLengthW(Destination) + 1 + 1 characters.
; Arguments:  Arg1: -> Destination WIDE string buffer.
;             Arg2: -> Wide character.
; Return:     eax -> Ending zero character.

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align ALIGN_CODE
StrECatCharW proc pBuffer:POINTER, cChar:CHRW
  invoke StrEndW, [esp + 4]                             ;pBuffer
  movzx ecx, WORD ptr [esp + 8]                         ;cChar
  mov DWORD ptr [eax], ecx                              ;Writes cChar and ZTC
  add eax, 2
  ret 8
StrECatCharW endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

end
