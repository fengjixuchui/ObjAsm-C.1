; ==================================================================================================
; Title:      ChartFlatSetup.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm compilation file for ChartFlatSetup object.
; Notes:      Version C.1.0, August 2021
;             - First release.
; ==================================================================================================


% include Objects.cop

% include &MacPath&fMath.inc

;Add here all files that build the inheritance path and referenced objects
LoadObjects Primer
LoadObjects Stream
LoadObjects WinPrimer
LoadObjects Window
LoadObjects Dialog
LoadObjects DialogModal
LoadObjects Array
LoadObjects Collection
LoadObjects ChartFlat

;Add here the file that defines the object(s) to be included in the library
MakeObjects ChartFlatSetup

end
