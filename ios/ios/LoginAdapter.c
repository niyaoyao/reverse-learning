//
//  LoginAdapter.c
//  ios
//
//  Created by NiYao on 1/22/17.
//  Copyright © 2017 suneny. All rights reserved.
//

#include <stdio.h>
// LoginAdapter - (int)loginWithLoginOption:(int) isForce:(char) extraInfo:(id) completionHandler:(id) cancelationHandler:(id) request:(id)
int __cdecl -[LoginAdapter loginWithLoginOption:isForce:extraInfo:completionHandler:cancelationHandler:request:](struct LoginAdapter *self, SEL a2, int a3, char a4, id a5, id a6, id a7, id a8)
{
    // a3 option; a4 isForce; a5 extraInfo; a6 completionHandler; a7 cancelationHandler; a8 request
    struct LoginAdapter *v8; // r8@1
    char v9; // r5@1
    int v10; // r1@1
    int v11; // r6@1
    int v12; // r1@1
    int v13; // r11@1
    int v14; // r1@1
    void *v15; // r10@1
    void *v16; // r0@8
    int v17; // r5@8
    int v18; // r5@9
    int v19; // r4@9
    void *v20; // r0@12
    void *v21; // r6@12
    void *v22; // r0@12
    int v23; // r8@12
    void *v24; // r0@12
    int v25; // r0@12
    int v26; // r11@12
    void *v27; // r0@12
    int v28; // r5@12
    id v29; // r6@12
    int v30; // r5@12
    int v31; // r1@12
    int v32; // r1@12
    void *v33; // r0@19
    int v34; // r4@19
    int v36; // [sp+8h] [bp-64h]@10
    int v37; // [sp+Ch] [bp-60h]@1
    struct LoginAdapter *v38; // [sp+10h] [bp-5Ch]@8
    int v39; // [sp+14h] [bp-58h]@1
    int v40; // [sp+18h] [bp-54h]@2
    void *v41; // [sp+1Ch] [bp-50h]@12
    int v42; // [sp+20h] [bp-4Ch]@12
    int v43; // [sp+24h] [bp-48h]@12
    int (*v44)(); // [sp+28h] [bp-44h]@12
    void *v45; // [sp+2Ch] [bp-40h]@12
    int v46; // [sp+30h] [bp-3Ch]@12
    int v47; // [sp+34h] [bp-38h]@12
    void *v48; // [sp+38h] [bp-34h]@12
    int v49; // [sp+3Ch] [bp-30h]@12
    int v50; // [sp+40h] [bp-2Ch]@12
    int (*v51)(); // [sp+44h] [bp-28h]@12
    void *v52; // [sp+48h] [bp-24h]@12
    int v53; // [sp+4Ch] [bp-20h]@12
    int v54; // [sp+50h] [bp-1Ch]@12
    
    v8 = self;
    v9 = a4;
    v37 = a3;
    v39 = objc_retain(a5, a2);
    v11 = objc_retain(a6, v10);
    v13 = objc_retain(a7, v12);
    v15 = objc_retain(a8, v14);
    if ( !v8->_login_service )
    {
        v18 = 0;
        v19 = v39;
        goto LABEL_27;
    }
    v40 = v11;
    if ( v15 ) {
        objc_msgSend(v8, "accquirePendingLock");
    }
    
    if ( objc_msgSend(v8, "accquireLoginLock") & 0xFF )
    {
        if ( v9 || !(objc_msgSend(v8, "isValidLogin") & 0xFF) )
        {
            v36 = v13;
            if ( v15 )
                objc_msgSend(v8, "pendingLoginRequest:", v15);
            v20 = objc_msgSend(&OBJC_CLASS___LogAdapter, "getInstance");
            v21 = objc_retainAutoreleasedReturnValue(v20);
            v38 = v8;
            v22 = objc_msgSend(v15, "getApiName");
            v23 = objc_retainAutoreleasedReturnValue(v22);
            v24 = objc_msgSend(v15, "getApiVersion");
            v25 = objc_retainAutoreleasedReturnValue(v24);
            v26 = v25;
            v27 = objc_msgSend(
                               &OBJC_CLASS___NSString,
                               "stringWithFormat:",
                               CFSTR("[LoginAdapter] apiName: %@, apiVersion: %@ pull login module"),
                               v23,
                               v25);
            v28 = objc_retainAutoreleasedReturnValue(v27);
            objc_msgSend(v21, "warn:", v28);
            objc_release(v28);
            objc_release(v26);
            objc_release(v23);
            objc_release(v21);
            v29 = v38->_login_service;
            v48 = &_NSConcreteStackBlock;
            v49 = -1040187392;
            v50 = 0;
            v51 = sub_2AAF082;
            v52 = &unk_3164640;
            v30 = objc_retain(v38, sub_2AAF082);
            v53 = v30;
            v54 = objc_retain(v40, v31);
            v41 = &_NSConcreteStackBlock;
            v42 = -1040187392;
            v43 = 0;
            v44 = sub_2AAF1AC;
            v45 = &unk_3164660;
            v13 = v36;
            v46 = objc_retain(v30, &unk_3164660);
            v19 = v39;
            v47 = objc_retain(v36, v32);
            objc_msgSend(v29, "loginWithLoginOption:extraInfo:completionHandler:cancelationHandler:", v37, v39, &v48, &v41);
            objc_release(v47);
            objc_release(v46);
            objc_release(v54);
            objc_release(v53);
            v18 = 2;
            goto LABEL_24;
        }
        objc_msgSend(v8, "releaseLoginLock");
        if ( v11 )
        {
            v38 = v8;
            v16 = objc_msgSend(v8->_login_service, "currentSession");
            v17 = objc_retainAutoreleasedReturnValue(v16);
            (*(v11 + 12))(v11, 1, v17);
            objc_release(v17);
        }
        else
        {
            v38 = v8;
        }
        v18 = 3;
    }
    else
    {
        if ( v15 )
        {
            if ( objc_msgSend(v8->_loginPendingRequests, "count") > 0xFF )
            {
                v38 = v8;
                v18 = 0;
            }
            else
            {
                v38 = v8;
                objc_msgSend(v8, "pendingLoginRequest:", v15);
                v18 = 1;
            }
        }
        else
        {
            v38 = v8;
            v18 = 0;
        }
        if ( v11 )
        {
            v33 = objc_msgSend(&OBJC_CLASS___NSDictionary, "dictionary");
            v34 = objc_retainAutoreleasedReturnValue(v33);
            v40 = v11;
            (*(v11 + 12))(v11, 0, v34);
            objc_release(v34);
        }
        else
        {
            v40 = 0;
        }
    }
    v19 = v39;
LABEL_24:
    if ( v15 )
        objc_msgSend(v38, "releasePendingLock");
        v11 = v40;
        LABEL_27:
        objc_release(v15);
        objc_release(v13);
        objc_release(v11);
        objc_release(v19);
        return v18;

}

int __fastcall objc_retain(int a1, int a2)
{
    return _objc_retain(a1, a2);
}
