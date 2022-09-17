; ==================================================================================================
; Title:      StrLowerA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

.code
; ��������������������������������������������������������������������������������������������������
; Procedure:  StrLowerA
; Purpose:    Convert all ANSI string characters into lowercase.
; Arguments:  Arg1: -> Source ANSI string.
; Return:     rax -> String.

OPTION PROC:NONE
align ALIGN_CODE
StrLowerA proc pStringA:POINTER
  push rcx                                              ;rcx -> StringA
  dec rcx
@@:
  inc rcx
  mov al, [rcx]
  or al, al
  je @F                                                 ;End of string
  cmp al, 'A'
  jb @B
  cmp al, 'Z'
  ja @B
  add al, 20H
  mov [rcx], al
  jmp @B
@@:
  pop rax                                               ;Return string address
  ret
StrLowerA endp
OPTION PROC:DEFAULT

end
