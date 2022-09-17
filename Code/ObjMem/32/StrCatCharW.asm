; ==================================================================================================
; Title:      StrCatCharW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

.code
; ��������������������������������������������������������������������������������������������������
; Procedure:  StrCatCharW
; Purpose:    Append a character to the end of a WIDE string.
; Arguments:  Arg1: Destrination WIDE buffer.
;             Arg2: WIDE character.
; Return:     Nothing.

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align ALIGN_CODE
StrCatCharW proc pBuffer:POINTER, cChar:CHRW
  invoke StrEndW, [esp + 4]                             ;pBuffer
  movzx ecx, WORD ptr [esp + 8]                         ;cChar
  mov DWORD ptr [eax], ecx                              ;Writes cChar and ZTC
  ret 8
StrCatCharW endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

end
