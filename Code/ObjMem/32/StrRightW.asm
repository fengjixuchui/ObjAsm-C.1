; ==================================================================================================
; Title:      StrRightW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMem.cop

.code

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Procedure: StrRightW
; Purpose:   Copy the right n characters from the source string into the destination buffer.
; Arguments: Arg1: -> Destination WIDE character buffer.
;            Arg2: -> Source WIDE string.
;            Arg3: Character count.
; Return:    Nothing.

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align ALIGN_CODE
StrRightW proc pBuffer:POINTER, pSrcStringW:POINTER, dCharCount:DWORD
  invoke StrLengthW, [esp + 8]                          ;pSrcStringW
  mov ecx, eax
  cmp eax, [esp + 12]                                   ;dCharCount
  jbe @F                                                ;unsigned compare!
  mov eax, [esp + 12]                                   ;eax = dCharCount
@@:
  sub ecx, eax
  shl ecx, 1
  add ecx, [esp + 8]                                    ;pSrcStringW
  push eax
  shl eax, 1
  invoke MemShift, [esp + 16], ecx, eax                 ;pBuffer
  pop eax                                               ;Return number of copied chars
  lea edx, [2 * eax]
  add edx, [esp + 4]                                    ;pDstStringW
  m2z WORD ptr [edx]                                    ;Set ZTC
  ret 12
StrRightW endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

end
