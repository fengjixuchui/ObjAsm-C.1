; ==================================================================================================
; Title:      StrNewA_UEFI.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemUefi.cop

ProcName equ <StrNewA_UEFI>

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Procedure:  StrNewA_UEFI
; Purpose:    Allocate a new copy of the source string.
;             If the pointer to the source string is NULL, StrNew returns NULL and doesn't allocate
;             any memory space. Otherwise, StrNew makes a duplicate of the source string.
;             The allocated memory space is Length(String) + ZTC.
; Arguments:  Arg1: -> Source WIDE string.
; Return:     eax -> New string copy.

% include &ObjMemPath&Common\StrNewTXP.inc

end
