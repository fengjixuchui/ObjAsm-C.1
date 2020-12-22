; ==================================================================================================
; Title:      Image.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm compilation file for Image object.
; Notes:      Version C.1.0, November 2017
;             - First release.
; ==================================================================================================


% include Objects.cop

% include &COMPath&COM.inc
% include &IncPath&Windows\IImgCtx.inc

;Add here all files that build the inheritance path and referenced objects
LoadObjects Primer

;Add here the file that defines the object(s) to be included in the library
MakeObjects Image

end
