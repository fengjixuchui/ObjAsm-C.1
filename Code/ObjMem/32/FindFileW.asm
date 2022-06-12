; ==================================================================================================
; Title:      FindFileW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc

TARGET_STR_TYPE = STR_TYPE_WIDE
TARGET_STR_AFFIX textequ <W>

ProcName textequ <FindFileW>
??SearchInDir textequ <??SearchInDirW>
FIND_FILE_PARAMS textequ <FIND_FILE_PARAMSW>

% include &ObjMemPath&ObjMemWin.cop

FIND_FILE_PARAMSW struct
  pFileName   POINTER    ?
  pRetBuffer  POINTER    ?
  pFilter     POINTER    ?
  cPreStr     CHRW       MAX_PATH DUP(?)
FIND_FILE_PARAMSW ends

% include &ObjMemPath&X\FindFileT.asm

end
