; ==================================================================================================
; Title:      DbgOutFPU_UEFI.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2022.
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemUefi.cop

ProcName textequ <DbgOutFPU_UEFI>

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Procedure:  DbgOutFPU_UEFI
; Purpose:    Display the content of the FPU.
; Arguments:  Arg1: -> Destination Window name.
;             Arg2: Text RGB color.
; Return:     Nothing.

% include &ObjMemPath&Common\\DbgOutFPUXP.inc

end
