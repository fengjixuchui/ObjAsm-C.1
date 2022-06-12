; ==================================================================================================
; Title:      StrIFilterA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

.code

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Procedure:  StrIFilterA
; Purpose:    Perform a case insensitive string match test using wildcards (* and ?).
; Arguments:  Arg1: -> Source ANSI string.
;             Arg2: -> Filter ANSI string.
; Return:     eax = TRUE if strings match, otherwise FALSE.

OPTION PROC:NONE
align ALIGN_CODE
StrIFilterA proc pStringA:POINTER, pFilterA:POINTER
  ;rcx -> StringA, rdx -> pFilterA
  .while TRUE
    mov ah, [rdx]
    .break .if ah == "*"
    mov al, [rcx]
    .break .if al == 0
    .if ah != "?"
      .if ah != al
        .if (ah >= "A" && ah <= "Z") || (ah >= "a" && ah <= "z")
          xor ah, " "
          .if ah != al
            xor eax, eax
            ret
          .endif
        .endif
      .endif
    .endif
    inc rcx
    inc rdx
  .endw

  .while TRUE
    mov al, [rcx]
    .break .if al == 0
    mov ah, [rdx]
    .if ah == "*"
      inc rdx
      mov ah, [rdx]
      .if ah == 0
        xor eax, eax
        inc eax
        ret
      .endif
      mov r8, rcx
      mov r9, rdx
      inc r8
    .elseif ah == "?"
      inc rcx
      inc rdx
    .else
      .if ah != al
        .if (ah >= "A" && ah <= "Z") || (ah >= "a" && ah <= "z")
          xor ah, 20h
          .if ah != al
            mov rcx, r8
            mov rdx, r9
            inc r8
            .continue
          .endif
        .endif
      .endif
      inc rcx
      inc rdx
    .endif
  .endw

  .while CHRA ptr [rdx] == "*"
    inc rdx
  .endw

  xor eax, eax
  .if CHRA ptr [rdx] == 0
    inc eax
  .endif

  ret
StrIFilterA endp
OPTION PROC:DEFAULT

end
