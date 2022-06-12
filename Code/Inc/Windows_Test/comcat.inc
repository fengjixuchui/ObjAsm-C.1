;Include file created by h2incX, Version 1.2.0, 02/12/2021 16:49
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: 'C:\_MySoftware_\ObjAsm\Projects\Experimental\h2IncX\10.0.22000.0\cppwinrt\um\comcat.h', last modified: 11/09/2021 16:29

ifndef __REQUIRED_RPCNDR_H_VERSION__
  __REQUIRED_RPCNDR_H_VERSION__ equ 500
endif
ifndef __REQUIRED_RPCSAL_H_VERSION__
  __REQUIRED_RPCSAL_H_VERSION__ equ 100
endif
include rpc.inc
include rpcndr.inc
ifndef __RPCNDR_H_VERSION__
  .err <this stub requires an updated version of < rpcndr.h >>
endif
ifndef COM_NO_WINDOWS_H
  include windows.inc
  include ole2.inc
endif
ifndef __comcat_h__
  __comcat_h__ equ <>
  if Defined(_MSC_VER) and (_MSC_VER ge 1020)
  endif
  ifndef DECLSPEC_XFGVIRT
    if _CONTROL_FLOW_GUARD_XFG
      DECLSPEC_XFGVIRT macro base, func
        exitm <__declspec(xfg_virtual (base, func))>
      endm
    else
      DECLSPEC_XFGVIRT macro base, func
        exitm <>
      endm
    endif
  endif
  ifndef __IEnumGUID_FWD_DEFINED__
    __IEnumGUID_FWD_DEFINED__ equ <>
    ;IEnumGUID typedef IEnumGUID
    
  endif
  ifndef __IEnumCATEGORYINFO_FWD_DEFINED__
    __IEnumCATEGORYINFO_FWD_DEFINED__ equ <>
    ;IEnumCATEGORYINFO typedef IEnumCATEGORYINFO
    
  endif
  ifndef __ICatRegister_FWD_DEFINED__
    __ICatRegister_FWD_DEFINED__ equ <>
    ;ICatRegister typedef ICatRegister
    
  endif
  ifndef __ICatInformation_FWD_DEFINED__
    __ICatInformation_FWD_DEFINED__ equ <>
    ;ICatInformation typedef ICatInformation
    
  endif
  include unknwn.inc
  ifdef __cplusplus
    ;[...]
  endif
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    externdef CLSID_StdComponentCategoriesMgr:CLSID
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    CATID typedef GUID
    REFCATID typedef REFGUID
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    IID_IEnumCLSID equ <IID_IEnumGUID>
    IEnumCLSID equ <IEnumGUID>
    LPENUMCLSID equ <LPENUMGUID>
    CATID_NULL equ <GUID_NULL>
    IsEqualCATID macro rcatid1, rcatid2
      exitm <IsEqualGUID(rcatid1, rcatid2)>
    endm
    IID_IEnumCATID equ <IID_IEnumGUID>
    IEnumCATID equ <IEnumGUID>
    externdef CATID_Insertable:CATID
    externdef CATID_Control:CATID
    externdef CATID_Programmable:CATID
    externdef CATID_IsShortcut:CATID
    externdef CATID_NeverShowExt:CATID
    externdef CATID_DocObject:CATID
    externdef CATID_Printable:CATID
    externdef CATID_RequiresDataPathHost:CATID
    externdef CATID_PersistsToMoniker:CATID
    externdef CATID_PersistsToStorage:CATID
    externdef CATID_PersistsToStreamInit:CATID
    externdef CATID_PersistsToStream:CATID
    externdef CATID_PersistsToMemory:CATID
    externdef CATID_PersistsToFile:CATID
    externdef CATID_PersistsToPropertyBag:CATID
    externdef CATID_InternetAware:CATID
    externdef CATID_DesignTimeUIActivatableControl:CATID
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)
    ifndef _LPENUMGUID_DEFINED
      _LPENUMGUID_DEFINED equ <>
      externdef __MIDL_itf_comcat_0000_0000_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_comcat_0000_0000_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IEnumGUID_INTERFACE_DEFINED__
        __IEnumGUID_INTERFACE_DEFINED__ equ <>
        LPENUMGUID typedef ptr IEnumGUID
        externdef IID_IEnumGUID:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IEnumGUIDVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IEnumGUIDVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IEnumGUID, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IEnumGUID
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IEnumGUID
            DECLSPEC_XFGVIRT(IEnumGUID, Next)
            STD_METHOD Next, :ptr IEnumGUID, :ULONG, :ptr GUID, :ptr ULONG
            DECLSPEC_XFGVIRT(IEnumGUID, Skip)
            STD_METHOD Skip, :ptr IEnumGUID, :ULONG
            DECLSPEC_XFGVIRT(IEnumGUID, Reset)
            STD_METHOD Reset, :ptr IEnumGUID
            DECLSPEC_XFGVIRT(IEnumGUID, Clone)
            STD_METHOD Clone, :ptr IEnumGUID, :ptr ptr IEnumGUID
            ??Interface equ <>
            END_INTERFACE
          IEnumGUIDVtbl ends

          IEnumGUID struct
            lpVtbl POINTER ?
          IEnumGUID ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
        IEnumGUID_RemoteNext_Proxy proto WIN_STD_CALL_CONV :ptr IEnumGUID, :ULONG, :ptr GUID, :ptr ULONG
        IEnumGUID_RemoteNext_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      endif
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ifndef _LPENUMCATEGORYINFO_DEFINED
      _LPENUMCATEGORYINFO_DEFINED equ <>
      externdef __MIDL_itf_comcat_0000_0001_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_comcat_0000_0001_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IEnumCATEGORYINFO_INTERFACE_DEFINED__
        __IEnumCATEGORYINFO_INTERFACE_DEFINED__ equ <>
        LPENUMCATEGORYINFO typedef ptr IEnumCATEGORYINFO
        CATEGORYINFO struct
          catid CATID <>
          lcid LCID ?
          szDescription OLECHAR (128) dup(?)
        CATEGORYINFO ends

        tagCATEGORYINFO typedef CATEGORYINFO
        LPCATEGORYINFO typedef ptr tagCATEGORYINFO
        
        externdef IID_IEnumCATEGORYINFO:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IEnumCATEGORYINFOVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IEnumCATEGORYINFOVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IEnumCATEGORYINFO, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IEnumCATEGORYINFO
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IEnumCATEGORYINFO
            DECLSPEC_XFGVIRT(IEnumCATEGORYINFO, Next)
            STD_METHOD Next, :ptr IEnumCATEGORYINFO, :ULONG, :ptr CATEGORYINFO, :ptr ULONG
            DECLSPEC_XFGVIRT(IEnumCATEGORYINFO, Skip)
            STD_METHOD Skip, :ptr IEnumCATEGORYINFO, :ULONG
            DECLSPEC_XFGVIRT(IEnumCATEGORYINFO, Reset)
            STD_METHOD Reset, :ptr IEnumCATEGORYINFO
            DECLSPEC_XFGVIRT(IEnumCATEGORYINFO, Clone)
            STD_METHOD Clone, :ptr IEnumCATEGORYINFO, :ptr ptr IEnumCATEGORYINFO
            ??Interface equ <>
            END_INTERFACE
          IEnumCATEGORYINFOVtbl ends

          IEnumCATEGORYINFO struct
            lpVtbl POINTER ?
          IEnumCATEGORYINFO ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    ifndef _LPCATREGISTER_DEFINED
      _LPCATREGISTER_DEFINED equ <>
      externdef __MIDL_itf_comcat_0000_0002_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_comcat_0000_0002_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __ICatRegister_INTERFACE_DEFINED__
        __ICatRegister_INTERFACE_DEFINED__ equ <>
        LPCATREGISTER typedef ptr ICatRegister
        externdef IID_ICatRegister:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ICatRegisterVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ICatRegisterVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr ICatRegister, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ICatRegister
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ICatRegister
            DECLSPEC_XFGVIRT(ICatRegister, RegisterCategories)
            STD_METHOD RegisterCategories, :ptr ICatRegister, :ULONG, :ptr CATEGORYINFO
            DECLSPEC_XFGVIRT(ICatRegister, UnRegisterCategories)
            STD_METHOD UnRegisterCategories, :ptr ICatRegister, :ULONG, :ptr CATID
            DECLSPEC_XFGVIRT(ICatRegister, RegisterClassImplCategories)
            STD_METHOD RegisterClassImplCategories, :ptr ICatRegister, :REFCLSID, :ULONG, :ptr CATID
            DECLSPEC_XFGVIRT(ICatRegister, UnRegisterClassImplCategories)
            STD_METHOD UnRegisterClassImplCategories, :ptr ICatRegister, :REFCLSID, :ULONG, :ptr CATID
            DECLSPEC_XFGVIRT(ICatRegister, RegisterClassReqCategories)
            STD_METHOD RegisterClassReqCategories, :ptr ICatRegister, :REFCLSID, :ULONG, :ptr CATID
            DECLSPEC_XFGVIRT(ICatRegister, UnRegisterClassReqCategories)
            STD_METHOD UnRegisterClassReqCategories, :ptr ICatRegister, :REFCLSID, :ULONG, :ptr CATID
            ??Interface equ <>
            END_INTERFACE
          ICatRegisterVtbl ends

          ICatRegister struct
            lpVtbl POINTER ?
          ICatRegister ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    ifndef _LPCATINFORMATION_DEFINED
      _LPCATINFORMATION_DEFINED equ <>
      externdef __MIDL_itf_comcat_0000_0003_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_comcat_0000_0003_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __ICatInformation_INTERFACE_DEFINED__
        __ICatInformation_INTERFACE_DEFINED__ equ <>
        LPCATINFORMATION typedef ptr ICatInformation
        externdef IID_ICatInformation:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ICatInformationVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ICatInformationVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr ICatInformation, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ICatInformation
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ICatInformation
            DECLSPEC_XFGVIRT(ICatInformation, EnumCategories)
            STD_METHOD EnumCategories, :ptr ICatInformation, :LCID, :ptr ptr IEnumCATEGORYINFO
            DECLSPEC_XFGVIRT(ICatInformation, GetCategoryDesc)
            STD_METHOD GetCategoryDesc, :ptr ICatInformation, :REFCATID, :LCID, :ptr LPWSTR
            DECLSPEC_XFGVIRT(ICatInformation, EnumClassesOfCategories)
            STD_METHOD EnumClassesOfCategories, :ptr ICatInformation, :ULONG, :ptr CATID, :ULONG, :ptr CATID, :ptr ptr IEnumGUID
            DECLSPEC_XFGVIRT(ICatInformation, IsClassOfCategories)
            STD_METHOD IsClassOfCategories, :ptr ICatInformation, :REFCLSID, :ULONG, :ptr CATID, :ULONG, :ptr CATID
            DECLSPEC_XFGVIRT(ICatInformation, EnumImplCategoriesOfClass)
            STD_METHOD EnumImplCategoriesOfClass, :ptr ICatInformation, :REFCLSID, :ptr ptr IEnumGUID
            DECLSPEC_XFGVIRT(ICatInformation, EnumReqCategoriesOfClass)
            STD_METHOD EnumReqCategoriesOfClass, :ptr ICatInformation, :REFCLSID, :ptr ptr IEnumGUID
            ??Interface equ <>
            END_INTERFACE
          ICatInformationVtbl ends

          ICatInformation struct
            lpVtbl POINTER ?
          ICatInformation ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
        ICatInformation_RemoteEnumClassesOfCategories_Proxy proto WIN_STD_CALL_CONV :ptr ICatInformation, :ULONG, :ptr CATID, :ULONG, :ptr CATID, :ptr ptr IEnumGUID
        ICatInformation_RemoteEnumClassesOfCategories_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
        ICatInformation_RemoteIsClassOfCategories_Proxy proto WIN_STD_CALL_CONV :ptr ICatInformation, :REFCLSID, :ULONG, :ptr CATID, :ULONG, :ptr CATID
        ICatInformation_RemoteIsClassOfCategories_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      endif
    endif
  endif
  externdef __MIDL_itf_comcat_0000_0004_v0_0_c_ifspec:RPC_IF_HANDLE
  externdef __MIDL_itf_comcat_0000_0004_v0_0_s_ifspec:RPC_IF_HANDLE
  IEnumGUID_Next_Proxy proto WIN_STD_CALL_CONV :ptr IEnumGUID, :ULONG, :ptr GUID, :ptr ULONG
  IEnumGUID_Next_Stub proto WIN_STD_CALL_CONV :ptr IEnumGUID, :ULONG, :ptr GUID, :ptr ULONG
  ICatInformation_EnumClassesOfCategories_Proxy proto WIN_STD_CALL_CONV :ptr ICatInformation, :ULONG, :ptr CATID, :ULONG, :ptr CATID, :ptr ptr IEnumGUID
  ICatInformation_EnumClassesOfCategories_Stub proto WIN_STD_CALL_CONV :ptr ICatInformation, :ULONG, :ptr CATID, :ULONG, :ptr CATID, :ptr ptr IEnumGUID
  ICatInformation_IsClassOfCategories_Proxy proto WIN_STD_CALL_CONV :ptr ICatInformation, :REFCLSID, :ULONG, :ptr CATID, :ULONG, :ptr CATID
  ICatInformation_IsClassOfCategories_Stub proto WIN_STD_CALL_CONV :ptr ICatInformation, :REFCLSID, :ULONG, :ptr CATID, :ULONG, :ptr CATID
  ifdef __cplusplus
    ;[...]
  endif
endif
 