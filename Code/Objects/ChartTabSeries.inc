; ==================================================================================================
; Title:      ChartTabSeries.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of ChartTabSeries objects.
; Notes:      Version C.1.0, August 2021
;               - First release.
; ==================================================================================================



; ==================================================================================================
;    ChartTabSeries implementation
; ==================================================================================================


; ��������������������������������������������������������������������������������������������������
; Method:     ChartTabSeries.Done
; Purpose:    Finalize the ChartTabSeries object.
; Arguments:  None.
; Return:     Nothing.

Method ChartTabSeries.Done, uses xsi
  SetObject xsi
  invoke StrDispose, [xsi].pLocalName
  invoke StrDispose, [xsi].pLocalDescription
  ACall xsi.Done
MethodEnd

; ��������������������������������������������������������������������������������������������������
; Method:     ChartTabSeries.Init
; Purpose:    Initialize the ChartTabSeries object.
; Arguments:  Arg1: -> Owner object.
; Return:     Nothing.

Method ChartTabSeries.Init, uses xbx xsi, pOwner:POINTER
  SetObject xsi
  ;Create local copies
  mov xbx, pOwner
  mov [xsi].pLocalName, $invoke(StrNew, [xbx].$Obj(ChartSeries).pName)
  mov [xsi].pLocalDescription, $invoke(StrNew, [xbx].$Obj(ChartSeries).pDescription)
MethodEnd

; ��������������������������������������������������������������������������������������������������
; Method:     ChartTabSeries.OnCtlColorDlg
; Purpose:    Event procedure for WM_CTLCOLORDLG message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Brush to paint the background.

Method ChartTabSeries.OnCtlColorDlg,, wParam:WPARAM, lParam:LPARAM
  invoke GetStockObject, WHITE_BRUSH
MethodEnd

; ��������������������������������������������������������������������������������������������������
; Method:     ChartTabSeries.Restore
; Purpose:    Restore original values.
; Arguments:  None.
; Return:     Nothing.

Method ChartTabSeries.Restore, uses xbx xsi
  SetObject xsi

  ;Restore from local copies
  mov xbx, [xsi].pOwner
  invoke StrDispose, [xbx].$Obj(ChartSeries).pName
  mov [xbx].$Obj(ChartSeries).pName, $invoke(StrNew, [xsi].pLocalName)
  invoke StrDispose, [xbx].$Obj(ChartSeries).pDescription
  mov [xbx].$Obj(ChartSeries).pDescription, $invoke(StrNew, [xsi].pLocalDescription)
MethodEnd