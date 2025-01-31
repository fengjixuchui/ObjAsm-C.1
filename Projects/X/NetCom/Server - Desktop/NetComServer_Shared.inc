; ==================================================================================================
; Title:      NetComServer_Shared.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Version:    See NetComServer.asm
; Purpose:    NetCom Server application.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <NetCom Server>
ABOUT_TEXT                    textequ   <NetComServer>
COPYRIGHT                     textequ   <G. Friedrich   October 2017> 
VER_FILEVERSION               equ       1,0,0,0
VER_FILEVERSION_STR           textequ   <1.0>
VER_PRODUCTVERSION            equ       1,0,0,0
VER_PRODUCTVERSION_STR        textequ   <1.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       5
BUILD_DATE_STR                textequ   <2022-08-28>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       DBG

;Dialog About Control IDs
IDC_DAB_ICON                  equ       100
IDC_DAB_TEXT                  equ       101
IDC_DAB_MAIL                  equ       102
IDC_DAB_LINK                  equ       103

IDM_EXIT                      equ       1001
IDM_HELP                      equ       1100
IDM_ABOUT                     equ       1101
