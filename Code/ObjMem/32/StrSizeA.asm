; ==================================================================================================
; Title:      StrSizeA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

.code

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Procedure:  StrSizeA
; Purpose:    Determine the size of an ANSI string including the zero terminating character (ZTC).
; Arguments:  Arg1: -> ANSI string.
; Return:     eax = Size of the string in bytes.

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align ALIGN_CODE
StrSizeA proc pStringA:POINTER
  mov eax, DWORD ptr [esp + 4]
  mov edx, eax
  and eax, 0FFFFFFFCh                                   ;Remove the last 2 bits to align the addr
  sub edx, eax                                          ;edx = 0..3
  mov ecx, DWORD ptr [eax]
  lea edx, [offset @@0 + 8*edx]                         ;Jump forward to skip non string bytes
  jmp edx

  align ALIGN_CODE
@@0:
  test ecx, 0000000FFh
  jz @0
@@1:
  test ecx, 00000FF00h
  jz @1
@@2:
  test ecx, 000FF0000h
  jz @2
@@3:
  test ecx, 0FF000000h
  jz @3
  add eax, 4
  mov ecx, DWORD ptr [eax]

  repeat 3
    test cl, cl
    jz @0
    test ch, ch
    jz @1
    test ecx, 000FF0000h
    jz @2
    test ecx, 0FF000000h
    jz @3
    add eax, 4
    mov ecx, DWORD ptr [eax]
  endm

  jmp @@0

@0:
  sub eax, [esp + 4]
  add eax, 1
  ret 4
@1:
  sub eax, [esp + 4]
  add eax, 2
  ret 4
@2:
  sub eax, [esp + 4]
  add eax, 3
  ret 4
@3:
  sub eax, [esp + 4]
  add eax, 4
  ret 4
StrSizeA endp

OPTION PROLOGUE:PROLOGUEDEF
 OPTION EPILOGUE:EPILOGUEDEF

end
