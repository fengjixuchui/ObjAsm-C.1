; ==================================================================================================
; Title:      StrICompA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMem.cop

.code

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Procedure:  StrICompA
; Purpose:    Compare 2 ANSI strings without case sensitivity.
; Arguments:  Arg1: -> ANSI string 1.
;             Arg2: -> ANSI string 2.
; Return:     If string 1 < string 2, then eax < 0.
;            If string 1 = string 2, then eax = 0.
;            If string 1 > string 2, then eax > 0.

align ALIGN_CODE
StrICompA proc pStr1A:POINTER, pStr2A:POINTER
  xor r8, r8
  xor eax, eax
@@Char:
  mov al, [rcx + r8]                                    ;Load char to compare
  test al, al                                           ;Test if end of string
  jz @@Eq?                                              ;Compute result
  cmp al, [rdx + r8]                                    ;Compare with the char of the other string
  jnz @@ICmp                                            ;Chars are not equal, check if for capitals
  inc r8                                                ;Goto for next char
  jmp @@Char
@@ICmp:
  cmp al, 'z'                                           ;Check range 'A'..'Z' or 'a'..'z'
  ja @@Eq?
  cmp al, 'A'
  jb @@Eq?
  cmp al, 'a'
  jae @@1
  cmp al, 'Z'
  ja @@Eq?
@@1:
  xor al, 20h                                           ;Swap lowercase - uppercase
  cmp al, [rdx + r8]                                    ;Compare again
  jne @@2                                               ;If not equal, compute result
  inc r8                                                ;Goto for next char
  jmp @@Char
@@2:
  and al, not 20h                                       ;Make uppercase
@@Eq?:
  movzx ecx, BYTE ptr [rdx + r8]                        ;Get char
  cmp cl, 'a'                                           ;Check range 'a'..'z'
  jb @@Exit
  cmp cl, 'z'
  ja @@Exit
  and cl, not 20h                                       ;Make uppercase
@@Exit:
  sub eax, ecx                                          ;Subtract to see which is smaller
  ret
StrICompA endp

end
