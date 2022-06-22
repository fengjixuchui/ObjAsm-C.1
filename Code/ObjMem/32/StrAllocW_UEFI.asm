; ==================================================================================================
; Title:      StrAllocW_UEFI.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemUefi.cop

ProcName equ <StrAllocW_UEFI>

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Procedure:  StrAllocW_UEFI 
; Purpose:    Allocate space for a string with n characters.
; Arguments:  Arg1: Character count without the ZTC.
; Return:     eax -> New allocated string or NULL if failed.

% include &ObjMemPath&Common\StrAllocTX_UEFI.inc

end
