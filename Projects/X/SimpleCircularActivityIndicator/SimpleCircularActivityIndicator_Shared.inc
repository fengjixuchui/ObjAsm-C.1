; ==================================================================================================
; Title:      CircularActivityIndicator_Shared.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm SimpleCircularActivityIndicator.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <Simple Circular Activity Indicator>
ABOUT_TEXT                    textequ   <Simple Circular Activity Indicator>
COPYRIGHT                     textequ   <G. Friedrich   August 2022> 
VER_FILEVERSION               equ       2,0,0,0
VER_FILEVERSION_STR           textequ   <2.0>
VER_PRODUCTVERSION            equ       2,0,0,0
VER_PRODUCTVERSION_STR        equ       <2.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       7
BUILD_DATE_STR                textequ   <2022-08-24>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       RLS

;Menu IDs
IDM_EXIT                      equ       1001
IDM_START_1                   equ       2001
IDM_START_2                   equ       2002
IDM_STOP_1                    equ       3001
IDM_STOP_2                    equ       3002
IDM_HELP                      equ       5001
IDM_ABOUT                     equ       5002

IDC_TEXT_ABOUT                equ       100