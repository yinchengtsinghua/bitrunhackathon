

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 11:14:07 2038
 */
/* Compiler settings for MFCprojector.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0622 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */


#ifndef __MFC_projector_h_h__
#define __MFC_projector_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IMFC_projector_FWD_DEFINED__
#define __IMFC_projector_FWD_DEFINED__
typedef interface IMFC_projector IMFC_projector;

#endif 	/* __IMFC_projector_FWD_DEFINED__ */


#ifndef __CMFCprojectorDoc_FWD_DEFINED__
#define __CMFCprojectorDoc_FWD_DEFINED__

#ifdef __cplusplus
typedef class CMFCprojectorDoc CMFCprojectorDoc;
#else
typedef struct CMFCprojectorDoc CMFCprojectorDoc;
#endif /* __cplusplus */

#endif 	/* __CMFCprojectorDoc_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __MFC_projector_LIBRARY_DEFINED__
#define __MFC_projector_LIBRARY_DEFINED__

/* library MFC_projector */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_MFC_projector;

#ifndef __IMFC_projector_DISPINTERFACE_DEFINED__
#define __IMFC_projector_DISPINTERFACE_DEFINED__

/* dispinterface IMFC_projector */
/* [uuid] */ 


EXTERN_C const IID DIID_IMFC_projector;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("84805df7-093b-451c-a3fa-7e5d8505f816")
    IMFC_projector : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IMFC_projectorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMFC_projector * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMFC_projector * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMFC_projector * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMFC_projector * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMFC_projector * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMFC_projector * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMFC_projector * This,
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
    } IMFC_projectorVtbl;

    interface IMFC_projector
    {
        CONST_VTBL struct IMFC_projectorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMFC_projector_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMFC_projector_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMFC_projector_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMFC_projector_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMFC_projector_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMFC_projector_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMFC_projector_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IMFC_projector_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_CMFCprojectorDoc;

#ifdef __cplusplus

class DECLSPEC_UUID("cdc71e47-0520-4940-8765-9f2f73ac9ae1")
CMFCprojectorDoc;
#endif
#endif /* __MFC_projector_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


