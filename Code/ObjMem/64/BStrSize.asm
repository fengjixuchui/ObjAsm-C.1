; ==================================================================================================
; Title:      BStrSize.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMem.cop

.code

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Procedure:  BStrSize
; Purpose:    Determine the size of a BStr including the ZTC + leading DWORD.
; Arguments:  Arg1: -> Source BStr.
; Return:     rax = String size including the length field and ZTC in bytes.

align ALIGN_CODE
BStrSize proc pBStr:POINTER
  mov eax, DWORD ptr [rcx - 4]                          ;Get the byte length DWORD
  add rax, sizeof(DWORD) + sizeof(CHRW)                 ;Add leading DWORD and ZTC
  ret
BStrSize endp

end
