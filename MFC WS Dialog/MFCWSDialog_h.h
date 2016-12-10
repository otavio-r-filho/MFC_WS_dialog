

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Fri Dec 09 20:30:02 2016
 */
/* Compiler settings for MFCWSDialog.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __MFCWSDialog_h_h__
#define __MFCWSDialog_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IMFCWSDialog_FWD_DEFINED__
#define __IMFCWSDialog_FWD_DEFINED__
typedef interface IMFCWSDialog IMFCWSDialog;

#endif 	/* __IMFCWSDialog_FWD_DEFINED__ */


#ifndef __MFCWSDialog_FWD_DEFINED__
#define __MFCWSDialog_FWD_DEFINED__

#ifdef __cplusplus
typedef class MFCWSDialog MFCWSDialog;
#else
typedef struct MFCWSDialog MFCWSDialog;
#endif /* __cplusplus */

#endif 	/* __MFCWSDialog_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __MFCWSDialog_LIBRARY_DEFINED__
#define __MFCWSDialog_LIBRARY_DEFINED__

/* library MFCWSDialog */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_MFCWSDialog;

#ifndef __IMFCWSDialog_DISPINTERFACE_DEFINED__
#define __IMFCWSDialog_DISPINTERFACE_DEFINED__

/* dispinterface IMFCWSDialog */
/* [uuid] */ 


EXTERN_C const IID DIID_IMFCWSDialog;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("984E0B16-4012-4254-8673-016C81AC60C0")
    IMFCWSDialog : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IMFCWSDialogVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMFCWSDialog * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMFCWSDialog * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMFCWSDialog * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMFCWSDialog * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMFCWSDialog * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMFCWSDialog * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMFCWSDialog * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } IMFCWSDialogVtbl;

    interface IMFCWSDialog
    {
        CONST_VTBL struct IMFCWSDialogVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMFCWSDialog_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMFCWSDialog_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMFCWSDialog_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMFCWSDialog_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMFCWSDialog_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMFCWSDialog_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMFCWSDialog_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IMFCWSDialog_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_MFCWSDialog;

#ifdef __cplusplus

class DECLSPEC_UUID("C0E76DFE-B827-45AA-8E7D-610E14DCD7F6")
MFCWSDialog;
#endif
#endif /* __MFCWSDialog_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


