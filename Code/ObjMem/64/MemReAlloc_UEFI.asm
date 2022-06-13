; ==================================================================================================
; Title:      MemReAlloc_UEFI.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Procedure:  MemReAlloc_UEFI
; Purpose:    Shrink or expand a memory block.
; Arguments:  Arg1: -> Memory block
;             Arg2: Memory block size in BYTEs.
;             Arg3: New memory block size in BYTEs.
;             Arg4: Memory block attributes [0, MEM_INIT_ZERO].
; Return:     xax -> New memory block.

% include &ObjMemPath&X\MemReAlloc_UEFI.asm

end
