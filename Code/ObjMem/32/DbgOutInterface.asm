; ==================================================================================================
; Title:      DbgOutInterface.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

.code
; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Procedure:  DbgOutInterface
; Purpose:    Identify a COM-Interface.
; Arguments:  Arg1: -> CSLID.
;             Arg2: Foreground color.
;             Arg2: -> Destination Window WIDE name.

align ALIGN_CODE
DbgOutInterface proc pIID:ptr GUID, dColor:DWORD, pDestWnd:POINTER
  invoke DbgOutTextA, $OfsCStrA("Interface: "), dColor, DBG_EFFECT_NORMAL, pDestWnd
  invoke DbgOutInterfaceName, pIID, dColor, pDestWnd
  ret
DbgOutInterface endp

end
