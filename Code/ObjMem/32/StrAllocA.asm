; ==================================================================================================
; Title:      StrAllocA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMem.cop

.code

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Procedure:  StrAllocA
; Purpose:    Allocate space for an ANSI string with n characters.
; Arguments:  Arg1: Character count without the ZTC.
; Return:     eax -> New allocated ANSI string or NULL if failed.

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align ALIGN_CODE
StrAllocA proc dChars:DWORD
  mov ecx, [esp + 4]                                    ;ecx = dChars
  inc ecx                                               ;Make room for the ZTC
  invoke GlobalAlloc, 0, ecx                            ;GMEM_FIXED
  m2z BYTE ptr [eax]
  ret 4
StrAllocA endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

end
