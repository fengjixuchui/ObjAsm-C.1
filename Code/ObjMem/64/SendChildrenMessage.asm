; ==================================================================================================
; Title:      SendChildrenMessage.asm
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.1, January 2020
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Procedure:  SendChildMessage
; Purpose:    Callback procedure for EnumChildWindows that sends a message to a child window.
; Arguments:  Arg1: Child window HANDLE.
;             Arg2: -> CHILD_MSG structure.
; Return:     eax = always TRUE (continue the enumeration).

% include &ObjMemPath&Common\SendChildrenMessageX.inc

end
