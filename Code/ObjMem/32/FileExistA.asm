; ==================================================================================================
; Title:      FileExistA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

.code
; ��������������������������������������������������������������������������������������������������
; Procedure:  FileExistA
; Purpose:    Check the existence of a file.
; Arguments:  Arg1: -> ANSI file name.
; Return:     eax = TRUE if the file exists, otherwise FALSE.

align ALIGN_CODE
FileExistA proc pFileNameA:POINTER
  local wfd :WIN32_FIND_DATA

  invoke FindFirstFileA, pFileNameA, addr wfd
  .if eax == INVALID_HANDLE_VALUE
    xor eax, eax                                        ;FALSE = NOT exist
  .else
    invoke FindClose, eax
    mov eax, TRUE                                       ;TRUE = exist
  .endif
  ret
FileExistA endp

end
