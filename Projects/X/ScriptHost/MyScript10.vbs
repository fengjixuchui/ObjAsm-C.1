Dim ObjShell
Set ObjShell = CreateObject("WScript.Shell")
ObjShell.RegWrite "HKEY_CURRENT_USER\Software\Wikipedia\", ""
ObjShell.RegWrite "HKEY_CURRENT_USER\Software\Wikipedia\URL", "https://de.wikipedia.org"
ObjShell.RegWrite "HKEY_CURRENT_USER\Software\Wikipedia\Artikel", "2000000", "REG_DWORD"

Dim URL, Artikel
URL = ObjShell.RegRead("HKEY_CURRENT_USER\Software\Wikipedia\URL")
Artikel = ObjShell.RegRead("HKEY_CURRENT_USER\Software\Wikipedia\Artikel")
ObjShell.Popup "Wikipedia, is accessible at " & URL & " and has more than " & Artikel & " articles", "5", ""

ObjShell.RegDelete "HKEY_CURRENT_USER\Software\Wikipedia\" 