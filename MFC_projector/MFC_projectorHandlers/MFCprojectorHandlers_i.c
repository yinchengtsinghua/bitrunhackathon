

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 11:14:07 2038
 */
/* Compiler settings for MFCprojectorHandlers.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        EXTERN_C __declspec(selectany) const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif // !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IPreview,0x6103e95c,0xeac6,0x4168,0xbf,0x09,0x6c,0xe1,0xe3,0x64,0x28,0x13);


MIDL_DEFINE_GUID(IID, IID_IThumbnail,0x91a04f4b,0xf299,0x448d,0x8b,0xf5,0x34,0x7f,0xf2,0xb5,0x14,0x8c);


MIDL_DEFINE_GUID(IID, IID_ISearch,0x67a4af73,0x200a,0x47fd,0xb8,0x20,0x0f,0x2f,0x53,0xf4,0x24,0x13);


MIDL_DEFINE_GUID(IID, LIBID_MFCprojectorHandlersLib,0x9698425f,0x45d4,0x450f,0x8d,0x27,0x03,0x66,0x60,0xaf,0xb4,0xd7);


MIDL_DEFINE_GUID(CLSID, CLSID_Preview,0xb2c2f141,0x311a,0x4fd9,0x83,0xc6,0x64,0x02,0xfb,0x8e,0x87,0xda);


MIDL_DEFINE_GUID(CLSID, CLSID_Thumbnail,0xfe921c8d,0x053b,0x425b,0xa5,0xe8,0x5a,0x3d,0x47,0x1b,0xff,0xab);


MIDL_DEFINE_GUID(CLSID, CLSID_Search,0x8b15ce3a,0x29bc,0x4488,0x92,0x31,0x0c,0xe6,0xf5,0x66,0x3a,0xc7);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



