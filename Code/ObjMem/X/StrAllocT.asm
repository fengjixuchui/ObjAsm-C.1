; ==================================================================================================
; Title:      StrAllocT.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
;               - Character and bitness neutral code.
; ==================================================================================================


% include &ObjMemPath&ObjMemWin.cop

.code

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Procedure:  StrAllocA / StrAllocW
; Purpose:    Allocate space for a string with n characters.
; Arguments:  Arg1: Character count without the ZTC.
; Return:     rax -> New allocated string or NULL if failed.

align ALIGN_CODE
ProcName proc dChars:DWORD
  ?mov ecx, dChars
  lea edx, [sizeof(CHR)*ecx + sizeof(CHR)]              ;Make room for the ZTC
  invoke GlobalAlloc, 0, edx                            ;GMEM_FIXED
  m2z CHR ptr [xax]                                     ;Set the ZTC
  ret
ProcName endp

end
