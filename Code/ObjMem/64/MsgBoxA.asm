; ==================================================================================================
; Title:      MsgBoxA.asm
; Author:     G. Friedrich
; Version:    C.1.2
; Notes:      Version C.1.2, May 2020
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\Objects\\Lib\\64A\\Objects.cop
TARGET_STR_TYPE = STR_TYPE_ANSI
% include &ObjMemPath&ObjMemWin.cop

ProcName equ <MsgBoxA>

.code
; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Procedure:  MsgBoxA
; Purpose:    Show a customized MessageBox.
; Arguments:  Arg1: Parent HANDLE.
;             Arg2: -> Markup text.
;             Arg3: -> Caption text.
;             Arg4: Flags.
; Return:     eax = Zero if failed, otherwise pressed button ID.
; Note:       Caption, text etc. are transferred via a caption string which contains a header and
;             the address of a MsgBoxInfo structure in text form.

% include &ObjMemPath&Common\MsgBox_TX.inc

end
