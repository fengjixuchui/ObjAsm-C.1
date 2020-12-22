; ==================================================================================================
; Title:      DisableCPUSerialNumber.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMem.cop

.code

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Procedure:  DisableCPUSerialNumber
; Purpose:    Disable the reading of the CPU serial number. 
; Arguments:  None.
; Return:     Nothing.

align ALIGN_CODE
DisableCPUSerialNumber proc
  mov ecx, 119h
  rdmsr
  and eax, 0FFDFFFFFh
  wrmsr
  ret
DisableCPUSerialNumber endp

end
