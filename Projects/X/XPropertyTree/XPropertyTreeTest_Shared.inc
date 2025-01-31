; ==================================================================================================
; Title:      XPropertyTreeTest_Shared.inc
; Author:     G. Friedrich
; Version:    XPropertyTreeTest.asm
; Purpose:    ObjAsm XPropertyTree Test Application.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <XPropertyTree Demo>
ABOUT_TEXT                    textequ   <XPropertyTree>
COPYRIGHT                     textequ   <G. Friedrich   October 2017> 
VER_FILEVERSION               equ       1,0,0,0
VER_FILEVERSION_STR           textequ   <1.0>
VER_PRODUCTVERSION            equ       1,0,0,0
VER_PRODUCTVERSION_STR        textequ   <1.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       13
BUILD_DATE_STR                textequ   <2022-09-15>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       DBG

;Menu IDs
IDM_EXIT                      equ       1000
IDM_HELP                      equ       1001
IDM_ABOUT                     equ       1999
IDM_CONTEXT                   equ       3000

;Dialog About Control IDs
IDC_DAB_ICON                  equ       100
IDC_DAB_TEXT                  equ       101
IDC_DAB_MAIL                  equ       102
IDC_DAB_LINK                  equ       103
