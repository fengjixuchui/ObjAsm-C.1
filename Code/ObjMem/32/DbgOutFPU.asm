; ==================================================================================================
; Title:      DbgOutFPU.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017.
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

ProcName textequ <DbgOutFPU>

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Purpose:    Display the content of the FPU.
; Arguments:  Arg1: -> Destination Window name.
;             Arg2: Text RGB color.
; Return:     Nothing.

% include &ObjMemPath&Common\\DbgOutFPUXP.inc

end
