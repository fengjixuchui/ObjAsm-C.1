; ==================================================================================================
; Title:      Real4ToHalf.asm
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.1, April 2020
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Procedure:  Real4ToHalf
; Purpose:    Convert a REAL4 to an HALF.
; Arguments:  Arg1: REAL4 value.
; Return:     ax = HALF.
; Note:       alternative code using VCVTPS2PH: 
;                movss xmm0, r4Value
;                VCVTPS2PH xmm1, xmm0, 0
;                movd eax, xmm1

% include &ObjMemPath&Common\Real4ToHalfXP.inc

end
