; ==================================================================================================
; Title:      StrUpperW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMem.cop

.code

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Procedure:  StrUpperW
; Purpose:    Convert all WIDE string characters into uppercase.
; Arguments:  Arg1: -> Source WIDE string.
; Return:     rax -> String.

align ALIGN_CODE
StrUpperW proc pStringW:POINTER
  push rax                                              ;rcx -> StringW
  sub rcx, sizeof(CHRW)
@@:
  add rcx, sizeof(CHRW)
  mov ax, [rcx]
  or ax, ax
  je @F                                                 ;End of string
  cmp ax, 'a'
  jb @B
  cmp ax, 'z'
  ja @B
  sub ax, 20H
  mov [rcx], ax
  jmp @B
@@:
  pop rax                                               ;Return string address
  ret
StrUpperW endp

end
