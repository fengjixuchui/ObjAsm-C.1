; ==================================================================================================
; Title:      Demo08_Shared.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm CUDA demo application.
; Notes:      Version C.1.0, September 2021
;               - First release.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <Demo08>
ABOUT_TEXT                    textequ   <DlgApp Demo>
COPYRIGHT                     textequ   <G. Friedrich   September 2021> 
VER_FILEVERSION               equ       2,0,0,0
VER_FILEVERSION_STR           textequ   <2.0>
VER_PRODUCTVERSION            equ       2,0,0,0
VER_PRODUCTVERSION_STR        equ       <2.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       62
BUILD_DATE_STR                textequ   <2022-09-15>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       RLS

;Res\MainDlgDlg.rc
IDD_DLG_MAIN                  equ       1000
IDC_STC_MESSAGE               equ       1001

;Dialog About Control IDs
IDC_DAB_ICON                  equ       100
IDC_DAB_TEXT                  equ       101
IDC_DAB_MAIL                  equ       102
IDC_DAB_LINK                  equ       103
