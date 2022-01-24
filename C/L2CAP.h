#pragma once
#ifndef P_L2CAP_H_
#define P_L2CAP_H_
#include "Prt.h"

#ifdef __cplusplus
extern "C" {
#endif
    
    extern PRT_EVENTDECL P_EVENT_eGetDefaultValueResp;
    extern PRT_EVENTDECL P_EVENT_eSpecGetDefaultValueReq;
    extern PRT_EVENTDECL P_EVENT_eL2CmdReq;
    extern PRT_EVENTDECL P_EVENT_eConnReq;
    extern PRT_EVENTDECL P_EVENT_eConnResp;
    extern PRT_EVENTDECL P_EVENT_eConfReq;
    extern PRT_EVENTDECL P_EVENT_eConfResp;
    extern PRT_EVENTDECL P_EVENT_eChanGotoConnected;
    extern PRT_EVENTDECL P_EVENT_eChanGotoConfig;
    extern PRT_EVENTDECL P_EVENT_eChanDead;
    extern PRT_EVENTDECL P_EVENT_eChanStarted;
    extern PRT_EVENTDECL P_EVENT_eChanConnected;
    extern PRT_EVENTDECL P_EVENT_eStartTimer;
    extern PRT_EVENTDECL P_EVENT_eTimeOut;
    extern PRT_EVENTDECL P_EVENT_eParsetFix;
    extern PRT_EVENTDECL P_EVENT_eParsetVar;
    extern PRT_EVENTDECL P_EVENT_eParsetHdr;
    extern PRT_EVENTDECL P_EVENT_eParsetPara;
    extern PRT_EVENTDECL P_EVENT_eParsetPlist;
    extern PRT_EVENTDECL P_EVENT_eParsetMsg;
    extern PRT_EVENTDECL P_EVENT_eComposetFix;
    extern PRT_EVENTDECL P_EVENT_eComposetVar;
    extern PRT_EVENTDECL P_EVENT_eComposetHdr;
    extern PRT_EVENTDECL P_EVENT_eComposetPara;
    extern PRT_EVENTDECL P_EVENT_eComposetPlist;
    extern PRT_EVENTDECL P_EVENT_eComposetMsg;
    extern PRT_FUNDECL P_FUNCTION_readBuffer;
    extern PRT_FUNDECL P_FUNCTION_writeBuffer;
    extern PRT_FUNDECL P_FUNCTION_sleepFor;
    extern PRT_FUNDECL P_FUNCTION_SetupClientServerSystem;
    extern PRT_INTERFACEDECL P_I_VarInitMachine;
    extern PRT_INTERFACEDECL P_I_ConnMachine;
    extern PRT_INTERFACEDECL P_I_ClientMachine;
    extern PRT_INTERFACEDECL P_I_ChanMachine;
    extern PRT_INTERFACEDECL P_I_TimerMachine;
    extern PRT_INTERFACEDECL P_I_TestWithSingleClient;
    extern PRT_MACHINEDECL P_MACHINE_VarInitMachine;
    extern PRT_MACHINEDECL P_MACHINE_ConnMachine;
    extern PRT_MACHINEDECL P_MACHINE_ClientMachine;
    extern PRT_MACHINEDECL P_MACHINE_ChanMachine;
    extern PRT_MACHINEDECL P_MACHINE_TimerMachine;
    extern PRT_MACHINEDECL P_MACHINE_MessageFormatSpecMachine;
    extern PRT_MACHINEDECL P_MACHINE_LivenessSpecMachine;
    extern PRT_MACHINEDECL P_MACHINE_TestWithSingleClient;
    extern PRT_TYPE* P_TYPEDEF_tFix;
    extern PRT_TYPE* P_TYPEDEF_tVar;
    extern PRT_TYPE* P_TYPEDEF_tHdr;
    extern PRT_TYPE* P_TYPEDEF_tPara;
    extern PRT_TYPE* P_TYPEDEF_tPlist;
    extern PRT_TYPE* P_TYPEDEF_tHMsub;
    extern PRT_TYPE* P_TYPEDEF_tcMsub;
    extern PRT_TYPE* P_TYPEDEF_tHcMsub;
    extern PRT_TYPE* P_TYPEDEF_tMsg;
    extern PRT_TYPE* P_TYPEDEF_tChan;
    extern PRT_TYPE* P_TYPEDEF_tConn;
    // DECL(SafetyTest, singleClient) => P_SAFETY_TEST_singleClient
    // DECL(NamedModule, L2CAPServer) => P_MODULE_L2CAPServer
    // DECL(NamedModule, L2CAPClient) => P_MODULE_L2CAPClient
    
#ifdef __cplusplus
}
#endif

#endif // P_L2CAP_H_
