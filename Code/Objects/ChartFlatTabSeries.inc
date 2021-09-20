; ==================================================================================================
; Title:      ChartFlatTabSeries.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of ChartFlatTabSeries objects.
; Notes:      Version C.1.0, August 2021
;               - First release.
; ==================================================================================================



; ==================================================================================================
;    ChartFlatTabSeries implementation
; ==================================================================================================


IDD_CHT_SER_TAB                 equ   5300
IDC_CHT_SER_NAME_STC            equ   5301
IDC_CHT_SER_NAME_EDT            equ   5302
IDC_CHT_SER_DESC_STC            equ   5303
IDC_CHT_SER_DESC_EDT            equ   5304

IDC_CHT_SER_LINE_GRP            equ   5310
IDC_CHT_SER_LINE_SHOW_CHK       equ   5311
IDC_CHT_SER_LINE_COLOR_BTN      equ   5312
IDC_CHT_SER_LINE_WIDTH_STC      equ   5314
IDC_CHT_SER_LINE_WIDTH_EDT      equ   5315
IDC_CHT_SER_LINE_WIDTH_UDN      equ   5316
IDC_CHT_SER_LINE_STYLE_STC      equ   5317
IDC_CHT_SER_LINE_STYLE_CBO      equ   5318

IDC_CHT_SER_MARKER_GRP          equ   5320
IDC_CHT_SER_MARKER_SHOW_CHK     equ   5321
IDC_CHT_SER_MARKER_COLOR_B_BTN  equ   5322
IDC_CHT_SER_MARKER_COLOR_F_BTN  equ   5323
IDC_CHT_SER_MARKER_SIZE_STC     equ   5324
IDC_CHT_SER_MARKER_SIZE_EDT     equ   5325
IDC_CHT_SER_MARKER_SIZE_UDN     equ   5326
IDC_CHT_SER_MARKER_TYPE_STC     equ   5327
IDC_CHT_SER_MARKER_TYPE_CBO     equ   5328
IDC_CHT_SER_MARKER_WIDTH_STC    equ   5329
IDC_CHT_SER_MARKER_WIDTH_EDT    equ   5330
IDC_CHT_SER_MARKER_WIDTH_UDN    equ   5331

LINE_WIDTH_MIN    equ   1
LINE_WIDTH_MAX    equ   10

MARKER_SIZE_MIN   equ   1
MARKER_SIZE_MAX   equ   50



; ��������������������������������������������������������������������������������������������������
; Method:     ChartFlatTabSeries.CtlsGet
; Purpose:    Read the setting of all controls.
; Arguments:  None.
; Return:     Nothing.

Method ChartFlatTabSeries.CtlsGet, uses xbx xdi xsi
  local cBuffer[1024]:CHR, dFailure:DWORD

  SetObject xsi
  lea xbx, cBuffer
  mov xdi, [xsi].pChartSeries
  assume xdi:$ObjPtr(ChartSeries)

  invoke StrDispose, [xdi].pName
  invoke GetDlgItemText, [xsi].hWnd, IDC_CHT_SER_NAME_EDT, xbx, lengthof cBuffer
  .if eax == 0
    xor eax, eax
  .else
    invoke StrNew, xbx
  .endif
  mov [xdi].pName, xax

  invoke StrDispose, [xdi].pDescription
  invoke GetDlgItemText, [xsi].hWnd, IDC_CHT_SER_DESC_EDT, xbx, lengthof cBuffer
  .if eax == 0
    xor eax, eax
  .else
    invoke StrNew, xbx
  .endif
  mov [xdi].pDescription, xax

  invoke IsDlgButtonChecked, [xsi].hWnd, IDC_CHT_SER_LINE_SHOW_CHK
  .if eax == BST_CHECKED
    BitSet [xdi].dFlags, CHT_SERIES_SHOW_LINE
  .else
    BitClr [xdi].dFlags, CHT_SERIES_SHOW_LINE
  .endif

  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_SER_LINE_COLOR_BTN
  mov [xdi].LineColor, $32($invoke(SendMessage, xax, BM_GETCOLOR, 0, 0))

  invoke GetDlgItemInt, [xsi].hWnd, IDC_CHT_SER_LINE_WIDTH_EDT, addr dFailure, FALSE
  .if dFailure != FALSE
    .if (eax >= LINE_WIDTH_MIN) && (eax <= LINE_WIDTH_MAX)
      mov [xdi].dLineWidth, eax
    .endif
  .endif

  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_SER_LINE_STYLE_CBO
  mov [xdi].dLineStyle, $32($invoke(SendMessage, xax, CB_GETCURSEL, 0, 0))

  invoke IsDlgButtonChecked, [xsi].hWnd, IDC_CHT_SER_MARKER_SHOW_CHK
  .if eax == BST_CHECKED
    BitSet [xdi].dFlags, CHT_SERIES_SHOW_MARKER
  .else
    BitClr [xdi].dFlags, CHT_SERIES_SHOW_MARKER
  .endif

  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_SER_MARKER_COLOR_B_BTN
  mov [xdi].MarkerBorderColor, $32($invoke(SendMessage, xax, BM_GETCOLOR, 0, 0))

  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_SER_MARKER_COLOR_F_BTN
  mov [xdi].MarkerFillColor, $32($invoke(SendMessage, xax, BM_GETCOLOR, 0, 0))

  invoke GetDlgItemInt, [xsi].hWnd, IDC_CHT_SER_MARKER_SIZE_EDT, addr dFailure, FALSE
  .if dFailure != FALSE
    .if (eax >= MARKER_SIZE_MIN) && (eax <= MARKER_SIZE_MAX)
      mov [xdi].dMarkerSize, eax
    .endif
  .endif

  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_SER_MARKER_TYPE_CBO
  mov [xdi].dMarkerShape, $32($invoke(SendMessage, xax, CB_GETCURSEL, 0, 0))

  invoke GetDlgItemInt, [xsi].hWnd, IDC_CHT_SER_MARKER_WIDTH_EDT, addr dFailure, FALSE
  .if dFailure != FALSE
    .if (eax >= LINE_WIDTH_MIN) && (eax <= LINE_WIDTH_MAX)
      mov [xdi].dMarkerBorderWidth, eax
    .endif
  .endif

  assume xdi:NOTHING
MethodEnd

; ��������������������������������������������������������������������������������������������������
; Method:     ChartFlatTabSeries.CtlsSet
; Purpose:    Set the controls of the setup dialog.
; Arguments:  None.
; Return:     Nothing.

Method ChartFlatTabSeries.CtlsSet, uses xbx xdi xsi
  SetObject xsi
  mov xdi, [xsi].pChartSeries
  assume xdi:$ObjPtr(ChartSeries)

  invoke SetDlgItemText, [xsi].hWnd, IDC_CHT_SER_NAME_EDT, [xdi].pName

  invoke SetDlgItemText, [xsi].hWnd, IDC_CHT_SER_DESC_EDT, [xdi].pDescription

  .ifBitSet [xdi].dFlags, CHT_SERIES_SHOW_LINE
    invoke CheckDlgButton, [xsi].hWnd, IDC_CHT_SER_LINE_SHOW_CHK, BST_CHECKED
  .else
    invoke CheckDlgButton, [xsi].hWnd, IDC_CHT_SER_LINE_SHOW_CHK, BST_UNCHECKED
  .endif

  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_SER_LINE_COLOR_BTN
  invoke SendMessage, xax, BM_SETCOLOR, 0, [xdi].LineColor

  invoke SetDlgItemInt, [xsi].hWnd, IDC_CHT_SER_LINE_WIDTH_EDT, [xdi].dLineWidth, FALSE

  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_SER_LINE_STYLE_CBO
  mov xbx, xax
  invoke SendMessage, xbx, CB_RESETCONTENT, 0, 0
  invoke SendMessage, xbx, CB_ADDSTRING, 0, $OfsCStr("Solid")
  invoke SendMessage, xbx, CB_ADDSTRING, 0, $OfsCStr("Dash")
  invoke SendMessage, xbx, CB_ADDSTRING, 0, $OfsCStr("Dot")
  invoke SendMessage, xbx, CB_ADDSTRING, 0, $OfsCStr("Dash-Dot")
  invoke SendMessage, xbx, CB_ADDSTRING, 0, $OfsCStr("Dash-Dot-Dot")
  invoke SendMessage, xbx, CB_SETCURSEL, [xdi].dLineStyle, 0

  .ifBitSet [xdi].dFlags, CHT_SERIES_SHOW_MARKER
    invoke CheckDlgButton, [xsi].hWnd, IDC_CHT_SER_MARKER_SHOW_CHK, BST_CHECKED
  .else
    invoke CheckDlgButton, [xsi].hWnd, IDC_CHT_SER_MARKER_SHOW_CHK, BST_UNCHECKED
  .endif

  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_SER_MARKER_COLOR_B_BTN
  invoke SendMessage, xax, BM_SETCOLOR, 0, [xdi].MarkerBorderColor

  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_SER_MARKER_COLOR_F_BTN
  invoke SendMessage, xax, BM_SETCOLOR, 0, [xdi].MarkerFillColor

  invoke SetDlgItemInt, [xsi].hWnd, IDC_CHT_SER_MARKER_SIZE_EDT, [xdi].dMarkerSize, FALSE

  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_SER_MARKER_TYPE_CBO
  mov xbx, xax
  invoke SendMessage, xbx, CB_RESETCONTENT, 0, 0
  invoke SendMessage, xbx, CB_ADDSTRING, 0, $OfsCStr("Square")
  invoke SendMessage, xbx, CB_ADDSTRING, 0, $OfsCStr("Rectangle Horizontal")
  invoke SendMessage, xbx, CB_ADDSTRING, 0, $OfsCStr("Rectangle Vertical")
  invoke SendMessage, xbx, CB_ADDSTRING, 0, $OfsCStr("Circle")
  invoke SendMessage, xbx, CB_ADDSTRING, 0, $OfsCStr("Ellipse Horizontal")
  invoke SendMessage, xbx, CB_ADDSTRING, 0, $OfsCStr("Ellipse Vertical")
  invoke SendMessage, xbx, CB_ADDSTRING, 0, $OfsCStr("Rhombus")
  invoke SendMessage, xbx, CB_ADDSTRING, 0, $OfsCStr("Rhombus Horizontal")
  invoke SendMessage, xbx, CB_ADDSTRING, 0, $OfsCStr("Rhombus Vertical")
  invoke SendMessage, xbx, CB_ADDSTRING, 0, $OfsCStr("Cross")
  invoke SendMessage, xbx, CB_ADDSTRING, 0, $OfsCStr("4 Point Star")
  invoke SendMessage, xbx, CB_ADDSTRING, 0, $OfsCStr("8 Point Star")
  invoke SendMessage, xbx, CB_SETCURSEL, [xdi].dMarkerShape, 0

  invoke SetDlgItemInt, [xsi].hWnd, IDC_CHT_SER_MARKER_WIDTH_EDT, [xdi].dMarkerBorderWidth, FALSE

  assume xdi:NOTHING
MethodEnd

; ��������������������������������������������������������������������������������������������������
; Method:     ChartFlatTabSeries.Done
; Purpose:    Finalize the ChartFlatTabSeries object.
; Arguments:  None.
; Return:     Nothing.

Method ChartFlatTabSeries.Done, uses xbx xsi
  SetObject xsi
  invoke StrDispose, [xsi].pLocalName
  invoke StrDispose, [xsi].pLocalDescription
  ACall xsi.Done
MethodEnd

; ��������������������������������������������������������������������������������������������������
; Method:     ChartFlatTabSeries.Init
; Purpose:    Initialize the ChartFlatTabSeries object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: -> ChartSeries.
; Return:     Nothing.

Method ChartFlatTabSeries.Init, uses xbx xsi, pOwner:POINTER, pChartSeries:$ObjPtr(ChartSeries)
  SetObject xsi
  mov xbx, pOwner
  ACall xsi.Init, xbx, [xbx].$Obj(TabCtrl).hWnd, IDD_CHT_SER_TAB, \
                  offset $ObjTmpl(Application).hActiveMlsDlg
  mrm [xsi].pChartSeries, pChartSeries, xbx

  ;Create local copies
  assume xbx:$ObjPtr(ChartSeries)
  mov [xsi].pLocalName, $invoke(StrNew, [xbx].pName)
  mov [xsi].pLocalDescription, $invoke(StrNew, [xbx].pDescription)
  m2m [xsi].LocalLineColor, [xbx].LineColor, eax
  m2m [xsi].dLocalLineWidth, [xbx].dLineWidth, ecx
  m2m [xsi].dLocalLineStyle, [xbx].dLineStyle, edx
;  m2m [xsi].LocalLineFillColor, [xbx].LineFillColor, eax
  m2m [xsi].LocalMarkerBorderColor, [xbx].MarkerBorderColor, ecx
  m2m [xsi].dLocalMarkerBorderWidth, [xbx].dMarkerBorderWidth, edx
  m2m [xsi].LocalMarkerFillColor, [xbx].MarkerFillColor, eax
  m2m [xsi].dLocalMarkerSize, [xbx].dMarkerSize, ecx
  m2m [xsi].dLocalMarkerShape, [xbx].dMarkerShape, edx
  assume xbx:NOTHING
MethodEnd

; ��������������������������������������������������������������������������������������������������
; Method:     ChartFlatTabSeries.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method ChartFlatTabSeries.OnCommand, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local ChooseClr:CHOOSECOLOR, ColorRef[16]:DWORD

  SetObject xsi
  .if (WORD ptr wParam == IDC_CHT_SER_LINE_COLOR_BTN) || \
      (WORD ptr wParam == IDC_CHT_SER_MARKER_COLOR_B_BTN) || \
      (WORD ptr wParam == IDC_CHT_SER_MARKER_COLOR_F_BTN)
    mov xbx, [xsi].pChartSeries

    ;Launch ChooseColor system dialog
    mov ChooseClr.lStructSize, sizeof ChooseClr
    m2m ChooseClr.hwndOwner, [xsi].hWnd, xdx
    m2m ChooseClr.hInstance, hInstance, xdx
    mov ChooseClr.Flags, CC_RGBINIT; or CC_FULLOPEN
    m2z ChooseClr.lCustData
    m2z ChooseClr.lpfnHook
    m2z ChooseClr.lpTemplateName

    ;Fill 1st part with the CHT_COLOR_CONFIG colors
    lea xdi, ColorRef
    mov ChooseClr.lpCustColors, xdi

    ;Fill other colors
    mov eax, $RGB(255,000,255)
    mov ColorRef[00*sizeof(COLORREF)], $RGB(000,000,000)
    mov ColorRef[01*sizeof(COLORREF)], $RGB(017,017,017)
    mov ColorRef[02*sizeof(COLORREF)], $RGB(034,034,034)
    mov ColorRef[03*sizeof(COLORREF)], $RGB(051,051,051)
    mov ColorRef[04*sizeof(COLORREF)], $RGB(068,068,068)
    mov ColorRef[05*sizeof(COLORREF)], $RGB(085,085,085)
    mov ColorRef[06*sizeof(COLORREF)], $RGB(102,102,102)
    mov ColorRef[07*sizeof(COLORREF)], $RGB(119,119,119)
    mov ColorRef[08*sizeof(COLORREF)], $RGB(136,136,136)
    mov ColorRef[09*sizeof(COLORREF)], $RGB(153,153,153)
    mov ColorRef[10*sizeof(COLORREF)], $RGB(170,170,170)
    mov ColorRef[11*sizeof(COLORREF)], $RGB(187,187,187)
    mov ColorRef[12*sizeof(COLORREF)], $RGB(204,204,204)
    mov ColorRef[13*sizeof(COLORREF)], $RGB(221,221,221)
    mov ColorRef[14*sizeof(COLORREF)], $RGB(239,239,239)
    mov ColorRef[15*sizeof(COLORREF)], $RGB(255,255,255)

    .if DWORD ptr wParam == IDC_CHT_SER_LINE_COLOR_BTN
      lea xbx, [xbx].$Obj(ChartSeries).LineColor
    .elseif DWORD ptr wParam ==  IDC_CHT_SER_MARKER_COLOR_B_BTN
      lea xbx, [xbx].$Obj(ChartSeries).MarkerBorderColor
    .else
      lea xbx, [xbx].$Obj(ChartSeries).MarkerFillColor
    .endif

    m2m ChooseClr.rgbResult, COLORREF ptr [xbx], edx
    invoke ChooseColor, addr ChooseClr
    .if eax != FALSE
      invoke GetDlgItem, [xsi].hWnd, DWORD ptr wParam
      mov xcx, xax
      mrm COLORREF ptr [xbx], ChooseClr.rgbResult, eax
      invoke SendMessage, xcx, BM_SETCOLOR, 0, eax
    .endif
  .endif
MethodEnd

; ��������������������������������������������������������������������������������������������������
; Method:     ChartFlatTabSeries.OnCtlColorDlg
; Purpose:    Event procedure for WM_CTLCOLORDLG message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Brush to paint the background.

Method ChartFlatTabSeries.OnCtlColorDlg,, wParam:WPARAM, lParam:LPARAM
  invoke GetStockObject, WHITE_BRUSH
MethodEnd

; ��������������������������������������������������������������������������������������������������
; Method:     ChartFlatTabSeries.OnInitDialog
; Purpose:    Event procedure for WM_INITDIALOG message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = FALSE.

Method ChartFlatTabSeries.OnInitDialog, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi

  ;Associate UDN-Controls
  mov xbx, $invoke(GetDlgItem, [xsi].hWnd, IDC_CHT_SER_LINE_WIDTH_UDN)
  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_SER_LINE_WIDTH_EDT
  invoke SendMessage, xbx, UDM_SETBUDDY, xax, 0
  invoke SendMessage, xbx, UDM_SETRANGE32, LINE_WIDTH_MIN, LINE_WIDTH_MAX

  mov xbx, $invoke(GetDlgItem, [xsi].hWnd, IDC_CHT_SER_MARKER_SIZE_UDN)
  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_SER_MARKER_SIZE_EDT
  invoke SendMessage, xbx, UDM_SETBUDDY, xax, 0
  invoke SendMessage, xbx, UDM_SETRANGE32, MARKER_SIZE_MIN, MARKER_SIZE_MAX

  mov xbx, $invoke(GetDlgItem, [xsi].hWnd, IDC_CHT_SER_MARKER_WIDTH_UDN)
  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_SER_MARKER_WIDTH_EDT
  invoke SendMessage, xbx, UDM_SETBUDDY, xax, 0
  invoke SendMessage, xbx, UDM_SETRANGE32, LINE_WIDTH_MIN, LINE_WIDTH_MAX

  ACall xsi.OnInitDialog, wParam, lParam
MethodEnd

; ��������������������������������������������������������������������������������������������������
; Method:     ChartFlatTabSeries.Restore
; Purpose:    Restore original values.
; Arguments:  None.
; Return:     Nothing.

Method ChartFlatTabSeries.Restore, uses xbx xsi
  SetObject xsi
  mov xbx, [xsi].pChartSeries
  assume xbx:$ObjPtr(ChartSeries)

  ;Restore from Create local copies
  invoke StrDispose, [xbx].pName
  mov [xbx].pName, $invoke(StrNew, [xsi].pLocalName)
  invoke StrDispose, [xbx].pDescription
  mov [xbx].pDescription, $invoke(StrNew, [xsi].pLocalDescription)
  m2m [xbx].LineColor, [xsi].LocalLineColor, eax
  m2m [xbx].dLineWidth, [xsi].dLocalLineWidth, ecx
  m2m [xbx].dLineStyle, [xsi].dLocalLineStyle, edx
;  m2m [xbx].LineFillColor, [xsi].LocalLineFillColor, eax
  m2m [xsi].LocalMarkerBorderColor, [xbx].MarkerBorderColor, ecx
  m2m [xbx].dMarkerBorderWidth, [xsi].dLocalMarkerBorderWidth, edx
  m2m [xbx].MarkerFillColor, [xsi].LocalMarkerFillColor, eax
  m2m [xbx].dMarkerSize, [xsi].dLocalMarkerSize, ecx
  m2m [xbx].dMarkerShape, [xsi].dLocalMarkerShape, edx
  assume xbx:NOTHING
MethodEnd