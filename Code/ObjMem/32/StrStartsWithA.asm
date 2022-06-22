; ==================================================================================================
; Title:      StrStartsWithA.asm
; Author:     HSE / G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.1, April 2020
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc

TARGET_STR_TYPE = STR_TYPE_ANSI
TARGET_STR_AFFIX textequ <A>
ProcName equ <StrStartsWithA>

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Procedure:  StrStartsWithA 
; Purpose:    Compares the beginning of a string.
; Arguments:  Arg1: -> Analized string.
;             Arg2: -> Prefix string.
; Return:     eax = TRUE of the beginning matches, otherwise FALSE.

% include &ObjMemPath&Common\StrStartsWithTXP.inc

end
