; ==================================================================================================
; Title:      RadixSortF32.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop
% include &ObjMemPath&32\RadixSort.inc                  ;Helper macros

.code

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Procedure:  RadixSortF32
; Purpose:    Ascending sort of an array of single precision floats (REAL4) using a modified 
;             "4 passes radix sort" algorithm.
; Arguments:  Arg1: -> Array of single precision floats.
;             Arg2: Number of single precision floats contained in the array.
;             Arg3: -> Memory used for the sorting process or NULL. The buffer size must be at least
;                   the size of the input array. If NULL, a memory chunk is allocated automatically.
; Return:     eax = TRUE if succeeded, otherwise FALSE.
; Notes:      - For short arrays, the shadow array can be placed onto the stack, saving the
;               expensive memory allocation/deallocation API calls. To achieve this, the proc
;               must be modified and stack probing must be included.
; Links:      - http://www.codercorner.com/RadixSortRevisited.htm
;             - http://en.wikipedia.org/wiki/Radix_sort

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align ALIGN_CODE
RadixSortF32 proc pArray:POINTER, dCount:DWORD, pWorkArea:POINTER
  push ebx
  mov ebx, [esp + 12]                                   ;dCount
  shl ebx, 2                                            ;ebx = Array size in bytes
  .if ZERO?
    mov eax, TRUE
  .else
    mov eax, [esp + 16]
    .if eax == NULL
      invoke VirtualAlloc, NULL, ebx, MEM_RESERVE or MEM_COMMIT, PAGE_READWRITE
    .endif
    .if eax != NULL
      push esi
      push edi
      mov esi, [esp + 16]                               ;esi -> Array
      mov edi, eax                                      ;edi -> Shadow array
      sub esp, 256*4                                    ;Make room for the counter array

      RadixPass32 0, edi, esi                           ;LSB
      RadixPass32 1, esi, edi
      RadixPass32 2, edi, esi

      ;Modified RadixPass32 3                           :MSB
      ResetRadixCounters
      CountRadixData32 3, edi
      GetRadixCountToIndexNegFirst TRUE
      SortRadixData32 3, esi, edi, TRUE                 ;Reverse order of negative floats

      add esp, 256*4                                    ;Release counter array
      .if POINTER ptr [esp + 24] == NULL
        invoke VirtualFree, edi, 0, MEM_RELEASE         ;Release shadow array, return value = TRUE
      .endif
      mov eax, TRUE
      pop edi
      pop esi
    .endif
  .endif
  pop ebx
  ret 8
RadixSortF32 endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

end
