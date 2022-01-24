#include "L2CAP.h"
#include <stdio.h>
#include <stdlib.h>

// Type universe for program:
static PRT_TYPE P_GEND_TYPE_B = { PRT_KIND_ANY, { NULL } };
static PRT_SEQTYPE P_SEQTYPE = { &P_GEND_TYPE_B };
static PRT_TYPE P_GEND_TYPE_SB = { PRT_KIND_SEQ, { .seq = &P_SEQTYPE } };
static PRT_TYPE P_GEND_TYPE_m = { PRT_KIND_MACHINE, { NULL } };
static PRT_STRING P_NMDTUP_N[] = { "source", "req" };
static PRT_STRING P_NMDTUP_N_1[] = { "chosen", "v", "p", "fp", "l", "hmsub", "hcmsub" };
static PRT_TYPE P_GEND_TYPE_i = { PRT_KIND_INT, { NULL } };
static PRT_STRING P_NMDTUP_N_2[] = { "nLow", "nHigh", "value" };
static PRT_SEQTYPE P_SEQTYPE_1 = { &P_GEND_TYPE_i };
static PRT_TYPE P_GEND_TYPE_Si = { PRT_KIND_SEQ, { .seq = &P_SEQTYPE_1 } };
static PRT_TYPE* P_NMDTUP_T_2[] = { &P_GEND_TYPE_i, &P_GEND_TYPE_i, &P_GEND_TYPE_Si };
static PRT_NMDTUPTYPE P_NMDTUP_2 = { 3U, P_NMDTUP_N_2, P_NMDTUP_T_2 };
static PRT_TYPE P_GEND_TYPE_NT3iiSi = { PRT_KIND_NMDTUP, { .nmTuple = &P_NMDTUP_2 } };
static PRT_STRING P_NMDTUP_N_3[] = { "nKey", "fKey", "fVal" };
static PRT_STRING P_NMDTUP_N_4[] = { "nSize", "nLow", "nHigh", "value" };
static PRT_TYPE* P_NMDTUP_T_4[] = { &P_GEND_TYPE_i, &P_GEND_TYPE_i, &P_GEND_TYPE_i, &P_GEND_TYPE_Si };
static PRT_NMDTUPTYPE P_NMDTUP_4 = { 4U, P_NMDTUP_N_4, P_NMDTUP_T_4 };
static PRT_TYPE P_GEND_TYPE_NT4iiiSi = { PRT_KIND_NMDTUP, { .nmTuple = &P_NMDTUP_4 } };
static PRT_TYPE* P_NMDTUP_T_3[] = { &P_GEND_TYPE_i, &P_GEND_TYPE_NT4iiiSi, &P_GEND_TYPE_NT4iiiSi };
static PRT_NMDTUPTYPE P_NMDTUP_3 = { 3U, P_NMDTUP_N_3, P_NMDTUP_T_3 };
static PRT_TYPE P_GEND_TYPE_NT3iNT4iiiSiNT4iiiSi = { PRT_KIND_NMDTUP, { .nmTuple = &P_NMDTUP_3 } };
static PRT_SEQTYPE P_SEQTYPE_2 = { &P_GEND_TYPE_NT4iiiSi };
static PRT_TYPE P_GEND_TYPE_SNT4iiiSi = { PRT_KIND_SEQ, { .seq = &P_SEQTYPE_2 } };
static PRT_STRING P_NMDTUP_N_5[] = { "nSize", "pP" };
static PRT_SEQTYPE P_SEQTYPE_3 = { &P_GEND_TYPE_NT3iNT4iiiSiNT4iiiSi };
static PRT_TYPE P_GEND_TYPE_SNT3iNT4iiiSiNT4iiiSi = { PRT_KIND_SEQ, { .seq = &P_SEQTYPE_3 } };
static PRT_TYPE* P_NMDTUP_T_5[] = { &P_GEND_TYPE_i, &P_GEND_TYPE_SNT3iNT4iiiSiNT4iiiSi };
static PRT_NMDTUPTYPE P_NMDTUP_5 = { 2U, P_NMDTUP_N_5, P_NMDTUP_T_5 };
static PRT_TYPE P_GEND_TYPE_NT2iSNT3iNT4iiiSiNT4iiiSi = { PRT_KIND_NMDTUP, { .nmTuple = &P_NMDTUP_5 } };
static PRT_STRING P_NMDTUP_N_6[] = { "h", "msub" };
static PRT_STRING P_NMDTUP_N_7[] = { "f", "fLen" };
static PRT_TYPE* P_NMDTUP_T_7[] = { &P_GEND_TYPE_SNT4iiiSi, &P_GEND_TYPE_NT4iiiSi };
static PRT_NMDTUPTYPE P_NMDTUP_7 = { 2U, P_NMDTUP_N_7, P_NMDTUP_T_7 };
static PRT_TYPE P_GEND_TYPE_NT2SNT4iiiSiNT4iiiSi = { PRT_KIND_NMDTUP, { .nmTuple = &P_NMDTUP_7 } };
static PRT_TYPE* P_NMDTUP_T_6[] = { &P_GEND_TYPE_NT2SNT4iiiSiNT4iiiSi, &P_GEND_TYPE_B };
static PRT_NMDTUPTYPE P_NMDTUP_6 = { 2U, P_NMDTUP_N_6, P_NMDTUP_T_6 };
static PRT_TYPE P_GEND_TYPE_NT2NT2SNT4iiiSiNT4iiiSiB = { PRT_KIND_NMDTUP, { .nmTuple = &P_NMDTUP_6 } };
static PRT_STRING P_NMDTUP_N_8[] = { "h", "msub" };
static PRT_STRING P_NMDTUP_N_9[] = { "nType", "msub" };
static PRT_TYPE* P_NMDTUP_T_9[] = { &P_GEND_TYPE_i, &P_GEND_TYPE_B };
static PRT_NMDTUPTYPE P_NMDTUP_9 = { 2U, P_NMDTUP_N_9, P_NMDTUP_T_9 };
static PRT_TYPE P_GEND_TYPE_NT2iB = { PRT_KIND_NMDTUP, { .nmTuple = &P_NMDTUP_9 } };
static PRT_SEQTYPE P_SEQTYPE_4 = { &P_GEND_TYPE_NT2iB };
static PRT_TYPE P_GEND_TYPE_SNT2iB = { PRT_KIND_SEQ, { .seq = &P_SEQTYPE_4 } };
static PRT_TYPE* P_NMDTUP_T_8[] = { &P_GEND_TYPE_NT2SNT4iiiSiNT4iiiSi, &P_GEND_TYPE_SNT2iB };
static PRT_NMDTUPTYPE P_NMDTUP_8 = { 2U, P_NMDTUP_N_8, P_NMDTUP_T_8 };
static PRT_TYPE P_GEND_TYPE_NT2NT2SNT4iiiSiNT4iiiSiSNT2iB = { PRT_KIND_NMDTUP, { .nmTuple = &P_NMDTUP_8 } };
static PRT_TYPE* P_NMDTUP_T_1[] = { &P_GEND_TYPE_i, &P_GEND_TYPE_NT3iiSi, &P_GEND_TYPE_NT3iNT4iiiSiNT4iiiSi, &P_GEND_TYPE_SNT4iiiSi, &P_GEND_TYPE_NT2iSNT3iNT4iiiSiNT4iiiSi, &P_GEND_TYPE_NT2NT2SNT4iiiSiNT4iiiSiB, &P_GEND_TYPE_NT2NT2SNT4iiiSiNT4iiiSiSNT2iB };
static PRT_NMDTUPTYPE P_NMDTUP_1 = { 7U, P_NMDTUP_N_1, P_NMDTUP_T_1 };
static PRT_TYPE P_GEND_TYPE_NT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB = { PRT_KIND_NMDTUP, { .nmTuple = &P_NMDTUP_1 } };
static PRT_TYPE* P_NMDTUP_T[] = { &P_GEND_TYPE_m, &P_GEND_TYPE_NT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB };
static PRT_NMDTUPTYPE P_NMDTUP = { 2U, P_NMDTUP_N, P_NMDTUP_T };
static PRT_TYPE P_GEND_TYPE_NT2mNT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB = { PRT_KIND_NMDTUP, { .nmTuple = &P_NMDTUP } };
static PRT_TYPE P_GEND_TYPE_b = { PRT_KIND_BOOL, { NULL } };
static PRT_TYPE P_GEND_TYPE_n = { PRT_KIND_NULL, { NULL } };
static PRT_SEQTYPE P_SEQTYPE_5 = { &P_GEND_TYPE_SNT3iNT4iiiSiNT4iiiSi };
static PRT_TYPE P_GEND_TYPE_SSNT3iNT4iiiSiNT4iiiSi = { PRT_KIND_SEQ, { .seq = &P_SEQTYPE_5 } };
static PRT_STRING P_NMDTUP_N_10[] = { "serv", "conn" };
static PRT_TYPE P_GEND_TYPE_R_1 = { PRT_KIND_MACHINE, { NULL } };
static PRT_TYPE* P_NMDTUP_T_10[] = { &P_GEND_TYPE_R_1, &P_GEND_TYPE_SSNT3iNT4iiiSiNT4iiiSi };
static PRT_NMDTUPTYPE P_NMDTUP_10 = { 2U, P_NMDTUP_N_10, P_NMDTUP_T_10 };
static PRT_TYPE P_GEND_TYPE_NT2RSSNT3iNT4iiiSiNT4iiiSi = { PRT_KIND_NMDTUP, { .nmTuple = &P_NMDTUP_10 } };
static PRT_STRING P_NMDTUP_N_11[] = { "_InitServer", "_ConnServer" };
static PRT_TYPE P_GEND_TYPE_R = { PRT_KIND_MACHINE, { NULL } };
static PRT_TYPE* P_NMDTUP_T_11[] = { &P_GEND_TYPE_R_1, &P_GEND_TYPE_R };
static PRT_NMDTUPTYPE P_NMDTUP_11 = { 2U, P_NMDTUP_N_11, P_NMDTUP_T_11 };
static PRT_TYPE P_GEND_TYPE_NT2RR = { PRT_KIND_NMDTUP, { .nmTuple = &P_NMDTUP_11 } };
static PRT_STRING P_NMDTUP_N_12[] = { "_client", "_timeout" };
static PRT_TYPE* P_NMDTUP_T_12[] = { &P_GEND_TYPE_m, &P_GEND_TYPE_i };
static PRT_NMDTUPTYPE P_NMDTUP_12 = { 2U, P_NMDTUP_N_12, P_NMDTUP_T_12 };
static PRT_TYPE P_GEND_TYPE_NT2mi = { PRT_KIND_NMDTUP, { .nmTuple = &P_NMDTUP_12 } };
static PRT_STRING P_NMDTUP_N_13[] = { "h", "msub" };
static PRT_TYPE* P_NMDTUP_T_13[] = { &P_GEND_TYPE_NT2SNT4iiiSiNT4iiiSi, &P_GEND_TYPE_NT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB };
static PRT_NMDTUPTYPE P_NMDTUP_13 = { 2U, P_NMDTUP_N_13, P_NMDTUP_T_13 };
static PRT_TYPE P_GEND_TYPE_NT2NT2SNT4iiiSiNT4iiiSiNT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB = { PRT_KIND_NMDTUP, { .nmTuple = &P_NMDTUP_13 } };
static PRT_STRING P_NMDTUP_N_14[] = { "chosen", "v", "p", "fp", "l", "hmsub", "hcmsub" };
static PRT_TYPE* P_NMDTUP_T_14[] = { &P_GEND_TYPE_i, &P_GEND_TYPE_NT3iiSi, &P_GEND_TYPE_NT3iNT4iiiSiNT4iiiSi, &P_GEND_TYPE_SNT4iiiSi, &P_GEND_TYPE_NT2iSNT3iNT4iiiSiNT4iiiSi, &P_GEND_TYPE_NT2NT2SNT4iiiSiNT4iiiSiNT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB, &P_GEND_TYPE_NT2NT2SNT4iiiSiNT4iiiSiSNT2iB };
static PRT_NMDTUPTYPE P_NMDTUP_14 = { 7U, P_NMDTUP_N_14, P_NMDTUP_T_14 };
static PRT_TYPE P_GEND_TYPE_NT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiNT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB = { PRT_KIND_NMDTUP, { .nmTuple = &P_NMDTUP_14 } };
static PRT_STRING P_NMDTUP_N_15[] = { "nType", "msub" };
static PRT_TYPE* P_NMDTUP_T_15[] = { &P_GEND_TYPE_i, &P_GEND_TYPE_NT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB };
static PRT_NMDTUPTYPE P_NMDTUP_15 = { 2U, P_NMDTUP_N_15, P_NMDTUP_T_15 };
static PRT_TYPE P_GEND_TYPE_NT2iNT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB = { PRT_KIND_NMDTUP, { .nmTuple = &P_NMDTUP_15 } };
static PRT_TYPE P_GEND_TYPE_R_2 = { PRT_KIND_MACHINE, { NULL } };
static PRT_MAPTYPE P_MAPTYPE = { &P_GEND_TYPE_i, &P_GEND_TYPE_R_2 };
static PRT_TYPE P_GEND_TYPE_MKiVR = { PRT_KIND_MAP, { .map = &P_MAPTYPE } };
static PRT_STRING P_NMDTUP_N_16[] = { "source", "req" };
static PRT_TYPE P_GEND_TYPE_R_3 = { PRT_KIND_MACHINE, { NULL } };
static PRT_TYPE* P_NMDTUP_T_16[] = { &P_GEND_TYPE_R_3, &P_GEND_TYPE_NT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB };
static PRT_NMDTUPTYPE P_NMDTUP_16 = { 2U, P_NMDTUP_N_16, P_NMDTUP_T_16 };
static PRT_TYPE P_GEND_TYPE_NT2RNT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB = { PRT_KIND_NMDTUP, { .nmTuple = &P_NMDTUP_16 } };
static PRT_STRING P_NMDTUP_N_17[] = { "_client", "_timeout" };
static PRT_TYPE* P_NMDTUP_T_17[] = { &P_GEND_TYPE_R_2, &P_GEND_TYPE_i };
static PRT_NMDTUPTYPE P_NMDTUP_17 = { 2U, P_NMDTUP_N_17, P_NMDTUP_T_17 };
static PRT_TYPE P_GEND_TYPE_NT2Ri = { PRT_KIND_NMDTUP, { .nmTuple = &P_NMDTUP_17 } };

// Function implementation prototypes:
PRT_VALUE* P_readBuffer_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_readBuffer;

PRT_VALUE* P_writeBuffer_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_writeBuffer;

PRT_VALUE* P_sleepFor_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_sleepFor;

PRT_VALUE* P_SetupClientServerSystem_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_SetupClientServerSystem;

PRT_VALUE* P_Anon_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon;

PRT_VALUE* P_Anon_IMPL_1(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_1;

PRT_VALUE* P_Anon_IMPL_2(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_2;

PRT_VALUE* P_Anon_IMPL_3(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_3;

PRT_VALUE* P_Anon_IMPL_4(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_4;

PRT_VALUE* P_Anon_IMPL_5(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_5;

PRT_VALUE* P_Anon_IMPL_6(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_6;

PRT_VALUE* P_Anon_IMPL_7(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_7;

PRT_VALUE* P_Anon_IMPL_8(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_8;

PRT_VALUE* P_Anon_IMPL_9(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_9;

PRT_VALUE* P_Anon_IMPL_10(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_10;

PRT_VALUE* P_Anon_IMPL_11(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_11;

PRT_VALUE* P_Anon_IMPL_12(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_12;

PRT_VALUE* P_Anon_IMPL_13(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_13;

PRT_VALUE* P_Anon_IMPL_14(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_14;

PRT_VALUE* P_Anon_IMPL_15(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_15;

PRT_VALUE* P_Anon_IMPL_16(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_16;

PRT_VALUE* P_Anon_IMPL_17(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_17;

PRT_VALUE* P_Anon_IMPL_18(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_18;

PRT_VALUE* P_Anon_IMPL_19(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_19;

PRT_VALUE* P_Anon_IMPL_20(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_20;

PRT_VALUE* P_Anon_IMPL_21(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_21;

PRT_VALUE* P_Anon_IMPL_22(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_22;

PRT_VALUE* P_Anon_IMPL_23(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_23;

PRT_VALUE* P_Anon_IMPL_24(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_24;

PRT_VALUE* P_Anon_IMPL_25(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_25;

PRT_VALUE* P_Anon_IMPL_26(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_26;

PRT_VALUE* P_Anon_IMPL_27(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_27;

PRT_VALUE* P_Anon_IMPL_28(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_28;

PRT_VALUE* P_Anon_IMPL_29(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_29;

PRT_VALUE* P_Anon_IMPL_30(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_30;

PRT_VALUE* P_Anon_IMPL_31(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_31;

PRT_VALUE* P_Anon_IMPL_32(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_32;

PRT_VALUE* P_Anon_IMPL_33(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_33;

PRT_VALUE* P_checktFix_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_checktFix;

PRT_VALUE* P_checktVar_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_checktVar;

PRT_VALUE* P_checktHdr_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_checktHdr;

PRT_VALUE* P_checktPara_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_checktPara;

PRT_VALUE* P_checktPlist_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_checktPlist;

PRT_VALUE* P_checktMsg_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_checktMsg;

PRT_VALUE* P_readBuffer2_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_readBuffer2;

PRT_VALUE* P_Anon_IMPL_34(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_34;

PRT_VALUE* P_Anon_IMPL_35(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_35;

PRT_VALUE* P_Anon_IMPL_36(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_36;

PRT_VALUE* P_Anon_IMPL_37(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_37;


PRT_EVENTDECL P_EVENT_eGetDefaultValueResp = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "eGetDefaultValueResp",
    4294967295U,
    &P_GEND_TYPE_SB
};

PRT_EVENTDECL P_EVENT_eSpecGetDefaultValueReq = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "eSpecGetDefaultValueReq",
    4294967295U,
    &P_GEND_TYPE_m
};

PRT_EVENTDECL P_EVENT_eL2CmdReq = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "eL2CmdReq",
    4294967295U,
    &P_GEND_TYPE_NT2mNT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB
};

PRT_EVENTDECL P_EVENT_eConnReq = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "eConnReq",
    4294967295U,
    &P_GEND_TYPE_NT2mNT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB
};

PRT_EVENTDECL P_EVENT_eConnResp = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "eConnResp",
    4294967295U,
    &P_GEND_TYPE_b
};

PRT_EVENTDECL P_EVENT_eConfReq = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "eConfReq",
    4294967295U,
    &P_GEND_TYPE_NT2mNT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB
};

PRT_EVENTDECL P_EVENT_eConfResp = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "eConfResp",
    4294967295U,
    &P_GEND_TYPE_b
};

PRT_EVENTDECL P_EVENT_eChanGotoConnected = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "eChanGotoConnected",
    4294967295U,
    &P_GEND_TYPE_n
};

PRT_EVENTDECL P_EVENT_eChanGotoConfig = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "eChanGotoConfig",
    4294967295U,
    &P_GEND_TYPE_n
};

PRT_EVENTDECL P_EVENT_eChanDead = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "eChanDead",
    4294967295U,
    &P_GEND_TYPE_n
};

PRT_EVENTDECL P_EVENT_eChanStarted = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "eChanStarted",
    4294967295U,
    &P_GEND_TYPE_n
};

PRT_EVENTDECL P_EVENT_eChanConnected = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "eChanConnected",
    4294967295U,
    &P_GEND_TYPE_n
};

PRT_EVENTDECL P_EVENT_eStartTimer = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "eStartTimer",
    4294967295U,
    &P_GEND_TYPE_i
};

PRT_EVENTDECL P_EVENT_eTimeOut = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "eTimeOut",
    4294967295U,
    &P_GEND_TYPE_i
};

PRT_EVENTDECL P_EVENT_eParsetFix = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "eParsetFix",
    4294967295U,
    &P_GEND_TYPE_NT4iiiSi
};

PRT_EVENTDECL P_EVENT_eParsetVar = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "eParsetVar",
    4294967295U,
    &P_GEND_TYPE_NT3iiSi
};

PRT_EVENTDECL P_EVENT_eParsetHdr = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "eParsetHdr",
    4294967295U,
    &P_GEND_TYPE_NT2SNT4iiiSiNT4iiiSi
};

PRT_EVENTDECL P_EVENT_eParsetPara = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "eParsetPara",
    4294967295U,
    &P_GEND_TYPE_NT3iNT4iiiSiNT4iiiSi
};

PRT_EVENTDECL P_EVENT_eParsetPlist = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "eParsetPlist",
    4294967295U,
    &P_GEND_TYPE_NT2iSNT3iNT4iiiSiNT4iiiSi
};

PRT_EVENTDECL P_EVENT_eParsetMsg = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "eParsetMsg",
    4294967295U,
    &P_GEND_TYPE_NT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB
};

PRT_EVENTDECL P_EVENT_eComposetFix = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "eComposetFix",
    4294967295U,
    &P_GEND_TYPE_NT4iiiSi
};

PRT_EVENTDECL P_EVENT_eComposetVar = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "eComposetVar",
    4294967295U,
    &P_GEND_TYPE_NT3iiSi
};

PRT_EVENTDECL P_EVENT_eComposetHdr = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "eComposetHdr",
    4294967295U,
    &P_GEND_TYPE_NT2SNT4iiiSiNT4iiiSi
};

PRT_EVENTDECL P_EVENT_eComposetPara = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "eComposetPara",
    4294967295U,
    &P_GEND_TYPE_NT3iNT4iiiSiNT4iiiSi
};

PRT_EVENTDECL P_EVENT_eComposetPlist = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "eComposetPlist",
    4294967295U,
    &P_GEND_TYPE_NT2iSNT3iNT4iiiSiNT4iiiSi
};

PRT_EVENTDECL P_EVENT_eComposetMsg = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "eComposetMsg",
    4294967295U,
    &P_GEND_TYPE_NT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB
};

PRT_VALUE* P_readBuffer_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE** P_VAR_buf = argRefs[0];
    PRT_VALUE* P_VAR_bufsize = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* P_VAR_counter = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* P_VAR_ret = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* PTMP_tmp0 = NULL;
    PRT_VALUE* PTMP_tmp1 = NULL;
    PRT_VALUE* PTMP_tmp2 = NULL;
    PRT_VALUE* PTMP_tmp3 = NULL;
    PRT_VALUE* PTMP_tmp4 = NULL;
    PRT_VALUE* PTMP_tmp5 = NULL;
    PRT_VALUE* PTMP_tmp6 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE P_LIT_INT32_1 = { PRT_VALUE_KIND_INT, { .nt = 256 } };
    PRT_VALUE P_LIT_INT32_2 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE P_LIT_BOOLEAN = { PRT_VALUE_KIND_BOOL, { .bl = PRT_TRUE } };
    PRT_VALUE** P_LVALUE = &(PTMP_tmp0);
    PrtFreeValue(*P_LVALUE);
    *P_LVALUE = PrtMkIntValue(PrtSeqSizeOf(*P_VAR_buf));
    
    {
        PRT_VALUE** P_LVALUE_1 = &(P_VAR_bufsize);
        PrtFreeValue(*P_LVALUE_1);
        *P_LVALUE_1 = PTMP_tmp0;
        PTMP_tmp0 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_2 = &(P_VAR_counter);
    PrtFreeValue(*P_LVALUE_2);
    *P_LVALUE_2 = PrtCloneValue((&P_LIT_INT32));
    
    PRT_VALUE** P_LVALUE_3 = &(P_VAR_ret);
    PrtFreeValue(*P_LVALUE_3);
    *P_LVALUE_3 = PrtCloneValue((&P_LIT_INT32));
    
    while (PrtPrimGetBool((&P_LIT_BOOLEAN)))
    {
        PRT_VALUE** P_LVALUE_4 = &(PTMP_tmp1);
        PrtFreeValue(*P_LVALUE_4);
        *P_LVALUE_4 = PrtMkBoolValue(PrtPrimGetInt(P_VAR_counter) < PrtPrimGetInt(P_VAR_bufsize));
        
        PRT_VALUE** P_LVALUE_5 = &(PTMP_tmp2);
        PrtFreeValue(*P_LVALUE_5);
        *P_LVALUE_5 = PrtCloneValue(PTMP_tmp1);
        
        if (PrtPrimGetBool(PTMP_tmp2))
        {
        }
        
        else
        {
            break;
            
        }
        
        
        PRT_VALUE** P_LVALUE_6 = &(PTMP_tmp3);
        PrtFreeValue(*P_LVALUE_6);
        *P_LVALUE_6 = PrtMkIntValue(PrtPrimGetInt(P_VAR_ret) * PrtPrimGetInt((&P_LIT_INT32_1)));
        
        {
            PRT_VALUE** P_LVALUE_7 = &(P_VAR_ret);
            PrtFreeValue(*P_LVALUE_7);
            *P_LVALUE_7 = PTMP_tmp3;
            PTMP_tmp3 = NULL;
        }
        
        PRT_VALUE** P_LVALUE_8 = &(PTMP_tmp4);
        PrtFreeValue(*P_LVALUE_8);
        *P_LVALUE_8 = PrtSeqGet(*P_VAR_buf, P_VAR_counter);
        
        PRT_VALUE** P_LVALUE_9 = &(PTMP_tmp5);
        PrtFreeValue(*P_LVALUE_9);
        *P_LVALUE_9 = PrtMkIntValue(PrtPrimGetInt(P_VAR_ret) + PrtPrimGetInt(PTMP_tmp4));
        
        {
            PRT_VALUE** P_LVALUE_10 = &(P_VAR_ret);
            PrtFreeValue(*P_LVALUE_10);
            *P_LVALUE_10 = PTMP_tmp5;
            PTMP_tmp5 = NULL;
        }
        
        PRT_VALUE** P_LVALUE_11 = &(PTMP_tmp6);
        PrtFreeValue(*P_LVALUE_11);
        *P_LVALUE_11 = PrtMkIntValue(PrtPrimGetInt(P_VAR_counter) + PrtPrimGetInt((&P_LIT_INT32_2)));
        
        {
            PRT_VALUE** P_LVALUE_12 = &(P_VAR_counter);
            PrtFreeValue(*P_LVALUE_12);
            *P_LVALUE_12 = PTMP_tmp6;
            PTMP_tmp6 = NULL;
        }
        
    }
    
    
    PrtFreeValue(_P_GEN_retval);
    _P_GEN_retval = PrtCloneValue(P_VAR_ret);
    goto p_return;
    
p_return: ;
    PrtFreeValue(P_VAR_bufsize); P_VAR_bufsize = NULL;
    PrtFreeValue(P_VAR_counter); P_VAR_counter = NULL;
    PrtFreeValue(P_VAR_ret); P_VAR_ret = NULL;
    PrtFreeValue(PTMP_tmp0); PTMP_tmp0 = NULL;
    PrtFreeValue(PTMP_tmp1); PTMP_tmp1 = NULL;
    PrtFreeValue(PTMP_tmp2); PTMP_tmp2 = NULL;
    PrtFreeValue(PTMP_tmp3); PTMP_tmp3 = NULL;
    PrtFreeValue(PTMP_tmp4); PTMP_tmp4 = NULL;
    PrtFreeValue(PTMP_tmp5); PTMP_tmp5 = NULL;
    PrtFreeValue(PTMP_tmp6); PTMP_tmp6 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_readBuffer =
{
    "readBuffer",
    &P_readBuffer_IMPL,
    NULL
};


PRT_VALUE* P_writeBuffer_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = PrtMkDefaultValue(&P_GEND_TYPE_Si);
    PRT_VALUE** P_VAR_bufsize_1 = argRefs[0];
    PRT_VALUE** P_VAR_val = argRefs[1];
    PRT_VALUE* P_VAR_counter_1 = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* P_VAR_tmp = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* P_VAR_ret_rev = PrtMkDefaultValue(&P_GEND_TYPE_Si);
    PRT_VALUE* P_VAR_ret_1 = PrtMkDefaultValue(&P_GEND_TYPE_Si);
    PRT_VALUE* P_VAR_curval = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* PTMP_tmp0_1 = NULL;
    PRT_VALUE* PTMP_tmp1_1 = NULL;
    PRT_VALUE* PTMP_tmp2_1 = NULL;
    PRT_VALUE* PTMP_tmp3_1 = NULL;
    PRT_VALUE* PTMP_tmp4_1 = NULL;
    PRT_VALUE* PTMP_tmp5_1 = NULL;
    PRT_VALUE* PTMP_tmp6_1 = NULL;
    PRT_VALUE* PTMP_tmp7 = NULL;
    PRT_VALUE* PTMP_tmp8 = NULL;
    PRT_VALUE* PTMP_tmp9 = NULL;
    PRT_VALUE* PTMP_tmp10 = NULL;
    PRT_VALUE* PTMP_tmp11 = NULL;
    PRT_VALUE* PTMP_tmp12 = NULL;
    PRT_VALUE* PTMP_tmp13 = NULL;
    PRT_VALUE* PTMP_tmp14 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_3 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE P_LIT_INT32_4 = { PRT_VALUE_KIND_INT, { .nt = 256 } };
    PRT_VALUE P_LIT_INT32_5 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE P_LIT_BOOLEAN_1 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_TRUE } };
    PRT_VALUE** P_LVALUE_13 = &(P_VAR_curval);
    PrtFreeValue(*P_LVALUE_13);
    *P_LVALUE_13 = PrtCloneValue(*P_VAR_val);
    
    PRT_VALUE** P_LVALUE_14 = &(P_VAR_counter_1);
    PrtFreeValue(*P_LVALUE_14);
    *P_LVALUE_14 = PrtCloneValue((&P_LIT_INT32_3));
    
    PRT_VALUE** P_LVALUE_15 = &(PTMP_tmp0_1);
    PrtFreeValue(*P_LVALUE_15);
    *P_LVALUE_15 = PrtMkDefaultValue(&P_GEND_TYPE_Si);
    
    {
        PRT_VALUE** P_LVALUE_16 = &(P_VAR_ret_1);
        PrtFreeValue(*P_LVALUE_16);
        *P_LVALUE_16 = PTMP_tmp0_1;
        PTMP_tmp0_1 = NULL;
    }
    
    while (PrtPrimGetBool((&P_LIT_BOOLEAN_1)))
    {
        PRT_VALUE** P_LVALUE_17 = &(PTMP_tmp1_1);
        PrtFreeValue(*P_LVALUE_17);
        *P_LVALUE_17 = PrtMkBoolValue(PrtPrimGetInt(P_VAR_counter_1) < PrtPrimGetInt(*P_VAR_bufsize_1));
        
        PRT_VALUE** P_LVALUE_18 = &(PTMP_tmp2_1);
        PrtFreeValue(*P_LVALUE_18);
        *P_LVALUE_18 = PrtCloneValue(PTMP_tmp1_1);
        
        if (PrtPrimGetBool(PTMP_tmp2_1))
        {
        }
        
        else
        {
            break;
            
        }
        
        
        PRT_VALUE** P_LVALUE_19 = &(PTMP_tmp3_1);
        PrtFreeValue(*P_LVALUE_19);
        *P_LVALUE_19 = PrtMkIntValue(PrtPrimGetInt(P_VAR_curval) / PrtPrimGetInt((&P_LIT_INT32_4)));
        
        {
            PRT_VALUE** P_LVALUE_20 = &(P_VAR_tmp);
            PrtFreeValue(*P_LVALUE_20);
            *P_LVALUE_20 = PTMP_tmp3_1;
            PTMP_tmp3_1 = NULL;
        }
        
        PRT_VALUE** P_LVALUE_21 = &(PTMP_tmp4_1);
        PrtFreeValue(*P_LVALUE_21);
        *P_LVALUE_21 = PrtMkIntValue(PrtPrimGetInt((&P_LIT_INT32_4)) * PrtPrimGetInt(P_VAR_tmp));
        
        PRT_VALUE** P_LVALUE_22 = &(PTMP_tmp5_1);
        PrtFreeValue(*P_LVALUE_22);
        *P_LVALUE_22 = PrtMkIntValue(PrtPrimGetInt(P_VAR_curval) - PrtPrimGetInt(PTMP_tmp4_1));
        
        PrtSeqInsertEx(P_VAR_ret_rev, P_VAR_counter_1, PTMP_tmp5_1, PRT_FALSE);
        *(&(PTMP_tmp5_1)) = NULL;
        
        PRT_VALUE** P_LVALUE_23 = &(P_VAR_curval);
        PrtFreeValue(*P_LVALUE_23);
        *P_LVALUE_23 = PrtCloneValue(P_VAR_tmp);
        
        PRT_VALUE** P_LVALUE_24 = &(PTMP_tmp6_1);
        PrtFreeValue(*P_LVALUE_24);
        *P_LVALUE_24 = PrtMkIntValue(PrtPrimGetInt(P_VAR_counter_1) + PrtPrimGetInt((&P_LIT_INT32_5)));
        
        {
            PRT_VALUE** P_LVALUE_25 = &(P_VAR_counter_1);
            PrtFreeValue(*P_LVALUE_25);
            *P_LVALUE_25 = PTMP_tmp6_1;
            PTMP_tmp6_1 = NULL;
        }
        
    }
    
    
    PRT_VALUE** P_LVALUE_26 = &(P_VAR_counter_1);
    PrtFreeValue(*P_LVALUE_26);
    *P_LVALUE_26 = PrtCloneValue((&P_LIT_INT32_3));
    
    while (PrtPrimGetBool((&P_LIT_BOOLEAN_1)))
    {
        PRT_VALUE** P_LVALUE_27 = &(PTMP_tmp7);
        PrtFreeValue(*P_LVALUE_27);
        *P_LVALUE_27 = PrtMkIntValue(PrtSeqSizeOf(P_VAR_ret_rev));
        
        PRT_VALUE** P_LVALUE_28 = &(PTMP_tmp8);
        PrtFreeValue(*P_LVALUE_28);
        *P_LVALUE_28 = PrtMkBoolValue(PrtPrimGetInt(P_VAR_counter_1) < PrtPrimGetInt(PTMP_tmp7));
        
        PRT_VALUE** P_LVALUE_29 = &(PTMP_tmp9);
        PrtFreeValue(*P_LVALUE_29);
        *P_LVALUE_29 = PrtCloneValue(PTMP_tmp8);
        
        if (PrtPrimGetBool(PTMP_tmp9))
        {
        }
        
        else
        {
            break;
            
        }
        
        
        PRT_VALUE** P_LVALUE_30 = &(PTMP_tmp10);
        PrtFreeValue(*P_LVALUE_30);
        *P_LVALUE_30 = PrtMkIntValue(PrtSeqSizeOf(P_VAR_ret_rev));
        
        PRT_VALUE** P_LVALUE_31 = &(PTMP_tmp11);
        PrtFreeValue(*P_LVALUE_31);
        *P_LVALUE_31 = PrtMkIntValue(PrtPrimGetInt(PTMP_tmp10) - PrtPrimGetInt(P_VAR_counter_1));
        
        PRT_VALUE** P_LVALUE_32 = &(PTMP_tmp12);
        PrtFreeValue(*P_LVALUE_32);
        *P_LVALUE_32 = PrtMkIntValue(PrtPrimGetInt(PTMP_tmp11) - PrtPrimGetInt((&P_LIT_INT32_5)));
        
        PRT_VALUE** P_LVALUE_33 = &(PTMP_tmp13);
        PrtFreeValue(*P_LVALUE_33);
        *P_LVALUE_33 = PrtSeqGet(P_VAR_ret_rev, PTMP_tmp12);
        
        PrtSeqInsertEx(P_VAR_ret_1, P_VAR_counter_1, PTMP_tmp13, PRT_FALSE);
        *(&(PTMP_tmp13)) = NULL;
        
        PRT_VALUE** P_LVALUE_34 = &(PTMP_tmp14);
        PrtFreeValue(*P_LVALUE_34);
        *P_LVALUE_34 = PrtMkIntValue(PrtPrimGetInt(P_VAR_counter_1) + PrtPrimGetInt((&P_LIT_INT32_5)));
        
        {
            PRT_VALUE** P_LVALUE_35 = &(P_VAR_counter_1);
            PrtFreeValue(*P_LVALUE_35);
            *P_LVALUE_35 = PTMP_tmp14;
            PTMP_tmp14 = NULL;
        }
        
    }
    
    
    PrtFreeValue(_P_GEN_retval);
    _P_GEN_retval = PrtCloneValue(P_VAR_ret_1);
    goto p_return_1;
    
p_return_1: ;
    PrtFreeValue(P_VAR_counter_1); P_VAR_counter_1 = NULL;
    PrtFreeValue(P_VAR_tmp); P_VAR_tmp = NULL;
    PrtFreeValue(P_VAR_ret_rev); P_VAR_ret_rev = NULL;
    PrtFreeValue(P_VAR_ret_1); P_VAR_ret_1 = NULL;
    PrtFreeValue(P_VAR_curval); P_VAR_curval = NULL;
    PrtFreeValue(PTMP_tmp0_1); PTMP_tmp0_1 = NULL;
    PrtFreeValue(PTMP_tmp1_1); PTMP_tmp1_1 = NULL;
    PrtFreeValue(PTMP_tmp2_1); PTMP_tmp2_1 = NULL;
    PrtFreeValue(PTMP_tmp3_1); PTMP_tmp3_1 = NULL;
    PrtFreeValue(PTMP_tmp4_1); PTMP_tmp4_1 = NULL;
    PrtFreeValue(PTMP_tmp5_1); PTMP_tmp5_1 = NULL;
    PrtFreeValue(PTMP_tmp6_1); PTMP_tmp6_1 = NULL;
    PrtFreeValue(PTMP_tmp7); PTMP_tmp7 = NULL;
    PrtFreeValue(PTMP_tmp8); PTMP_tmp8 = NULL;
    PrtFreeValue(PTMP_tmp9); PTMP_tmp9 = NULL;
    PrtFreeValue(PTMP_tmp10); PTMP_tmp10 = NULL;
    PrtFreeValue(PTMP_tmp11); PTMP_tmp11 = NULL;
    PrtFreeValue(PTMP_tmp12); PTMP_tmp12 = NULL;
    PrtFreeValue(PTMP_tmp13); PTMP_tmp13 = NULL;
    PrtFreeValue(PTMP_tmp14); PTMP_tmp14 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_writeBuffer =
{
    "writeBuffer",
    &P_writeBuffer_IMPL,
    NULL
};


PRT_VALUE* P_sleepFor_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = PrtMkDefaultValue(&P_GEND_TYPE_b);
    PRT_VALUE** P_VAR_sleeptime = argRefs[0];
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_BOOLEAN_2 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_TRUE } };
    PrtFreeValue(_P_GEN_retval);
    _P_GEN_retval = PrtCloneValue((&P_LIT_BOOLEAN_2));
    goto p_return_2;
    
p_return_2: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_sleepFor =
{
    "sleepFor",
    &P_sleepFor_IMPL,
    NULL
};


PRT_VALUE* P_SetupClientServerSystem_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_numClients = argRefs[0];
    PRT_VALUE* P_VAR_ConnServer = PrtMkDefaultValue(&P_GEND_TYPE_R);
    PRT_VALUE* P_VAR_InitServer = PrtMkDefaultValue(&P_GEND_TYPE_R_1);
    PRT_VALUE* P_VAR_InitConnetcion = PrtMkDefaultValue(&P_GEND_TYPE_SSNT3iNT4iiiSiNT4iiiSi);
    PRT_VALUE* P_VAR_InitChannel = PrtMkDefaultValue(&P_GEND_TYPE_SNT3iNT4iiiSiNT4iiiSi);
    PRT_VALUE* P_VAR_tmpPara = PrtMkDefaultValue(&P_GEND_TYPE_NT3iNT4iiiSiNT4iiiSi);
    PRT_VALUE* P_VAR_counter_2 = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* PTMP_tmp0_2 = NULL;
    PRT_VALUE* PTMP_tmp1_2 = NULL;
    PRT_VALUE* PTMP_tmp2_2 = NULL;
    PRT_VALUE* PTMP_tmp3_2 = NULL;
    PRT_VALUE* PTMP_tmp4_2 = NULL;
    PRT_VALUE* PTMP_tmp5_2 = NULL;
    PRT_VALUE* PTMP_tmp6_2 = NULL;
    PRT_VALUE* PTMP_tmp7_1 = NULL;
    PRT_VALUE* PTMP_tmp8_1 = NULL;
    PRT_VALUE* PTMP_tmp9_1 = NULL;
    PRT_VALUE* PTMP_tmp10_1 = NULL;
    PRT_VALUE* PTMP_tmp11_1 = NULL;
    PRT_VALUE* PTMP_tmp12_1 = NULL;
    PRT_VALUE* PTMP_tmp13_1 = NULL;
    PRT_VALUE* PTMP_tmp14_1 = NULL;
    PRT_VALUE* PTMP_tmp15 = NULL;
    PRT_VALUE* PTMP_tmp16 = NULL;
    PRT_VALUE* PTMP_tmp17 = NULL;
    PRT_VALUE* PTMP_tmp18 = NULL;
    PRT_VALUE* PTMP_tmp19 = NULL;
    PRT_VALUE* PTMP_tmp20 = NULL;
    PRT_VALUE* PTMP_tmp21 = NULL;
    PRT_VALUE* PTMP_tmp22 = NULL;
    PRT_VALUE* PTMP_tmp23 = NULL;
    PRT_VALUE* PTMP_tmp24 = NULL;
    PRT_VALUE* PTMP_tmp25 = NULL;
    PRT_VALUE* PTMP_tmp26 = NULL;
    PRT_VALUE* PTMP_tmp27 = NULL;
    PRT_VALUE* PTMP_tmp28 = NULL;
    PRT_VALUE* PTMP_tmp29 = NULL;
    PRT_VALUE* PTMP_tmp30 = NULL;
    PRT_VALUE* PTMP_tmp31 = NULL;
    PRT_VALUE* PTMP_tmp32 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_6 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE P_LIT_INT32_7 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE P_LIT_INT32_8 = { PRT_VALUE_KIND_INT, { .nt = 255 } };
    PRT_VALUE P_LIT_INT32_9 = { PRT_VALUE_KIND_INT, { .nt = 2 } };
    PRT_VALUE P_LIT_INT32_10 = { PRT_VALUE_KIND_INT, { .nt = 65535 } };
    PRT_VALUE P_LIT_INT32_11 = { PRT_VALUE_KIND_INT, { .nt = 23 } };
    PRT_VALUE P_LIT_BOOLEAN_3 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_TRUE } };
    PRT_VALUE** P_LVALUE_36 = &(P_VAR_counter_2);
    PrtFreeValue(*P_LVALUE_36);
    *P_LVALUE_36 = PrtCloneValue((&P_LIT_INT32_6));
    
    PRT_VALUE** P_LVALUE_37 = &(PTMP_tmp0_2);
    PrtFreeValue(*P_LVALUE_37);
    *P_LVALUE_37 = PrtMkDefaultValue(&P_GEND_TYPE_SNT3iNT4iiiSiNT4iiiSi);
    
    {
        PRT_VALUE** P_LVALUE_38 = &(P_VAR_InitChannel);
        PrtFreeValue(*P_LVALUE_38);
        *P_LVALUE_38 = PTMP_tmp0_2;
        PTMP_tmp0_2 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_39 = &(PTMP_tmp1_2);
    PrtFreeValue(*P_LVALUE_39);
    *P_LVALUE_39 = PrtMkDefaultValue(&P_GEND_TYPE_NT3iNT4iiiSiNT4iiiSi);
    
    {
        PRT_VALUE** P_LVALUE_40 = &(P_VAR_tmpPara);
        PrtFreeValue(*P_LVALUE_40);
        *P_LVALUE_40 = PTMP_tmp1_2;
        PTMP_tmp1_2 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_41 = &(*(PrtTupleGetLValue(P_VAR_tmpPara, 0)));
    PrtFreeValue(*P_LVALUE_41);
    *P_LVALUE_41 = PrtCloneValue((&P_LIT_INT32_7));
    
    PRT_VALUE** P_LVALUE_42 = &(*(PrtTupleGetLValue(*(PrtTupleGetLValue(P_VAR_tmpPara, 1)), 0)));
    PrtFreeValue(*P_LVALUE_42);
    *P_LVALUE_42 = PrtCloneValue((&P_LIT_INT32_7));
    
    PRT_VALUE** P_LVALUE_43 = &(*(PrtTupleGetLValue(*(PrtTupleGetLValue(P_VAR_tmpPara, 1)), 1)));
    PrtFreeValue(*P_LVALUE_43);
    *P_LVALUE_43 = PrtCloneValue((&P_LIT_INT32_6));
    
    PRT_VALUE** P_LVALUE_44 = &(*(PrtTupleGetLValue(*(PrtTupleGetLValue(P_VAR_tmpPara, 1)), 2)));
    PrtFreeValue(*P_LVALUE_44);
    *P_LVALUE_44 = PrtCloneValue((&P_LIT_INT32_8));
    
    PRT_VALUE** P_LVALUE_45 = &(PTMP_tmp2_2);
    PrtFreeValue(*P_LVALUE_45);
    *P_LVALUE_45 = PrtCloneValue((&P_LIT_INT32_7));
    
    PRT_VALUE** P_LVALUE_46 = &(PTMP_tmp3_2);
    PrtFreeValue(*P_LVALUE_46);
    *P_LVALUE_46 = PrtCloneValue((&P_LIT_INT32_7));
    
    PRT_VALUE** P_LVALUE_47 = &(PTMP_tmp4_2);
    PrtFreeValue(*P_LVALUE_47);
    *P_LVALUE_47 = ((_P_GEN_funargs[0] = &(PTMP_tmp2_2)), (_P_GEN_funargs[1] = &(PTMP_tmp3_2)), (_P_GEN_funval = P_writeBuffer_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp2_2), PTMP_tmp2_2 = NULL), (PrtFreeValue(PTMP_tmp3_2), PTMP_tmp3_2 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_3;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_3;
    }
    
    {
        PRT_VALUE** P_LVALUE_48 = &(*(PrtTupleGetLValue(*(PrtTupleGetLValue(P_VAR_tmpPara, 1)), 3)));
        PrtFreeValue(*P_LVALUE_48);
        *P_LVALUE_48 = PTMP_tmp4_2;
        PTMP_tmp4_2 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_49 = &(*(PrtTupleGetLValue(*(PrtTupleGetLValue(P_VAR_tmpPara, 2)), 0)));
    PrtFreeValue(*P_LVALUE_49);
    *P_LVALUE_49 = PrtCloneValue((&P_LIT_INT32_9));
    
    PRT_VALUE** P_LVALUE_50 = &(*(PrtTupleGetLValue(*(PrtTupleGetLValue(P_VAR_tmpPara, 2)), 1)));
    PrtFreeValue(*P_LVALUE_50);
    *P_LVALUE_50 = PrtCloneValue((&P_LIT_INT32_7));
    
    PRT_VALUE** P_LVALUE_51 = &(*(PrtTupleGetLValue(*(PrtTupleGetLValue(P_VAR_tmpPara, 2)), 2)));
    PrtFreeValue(*P_LVALUE_51);
    *P_LVALUE_51 = PrtCloneValue((&P_LIT_INT32_10));
    
    PRT_VALUE** P_LVALUE_52 = &(PTMP_tmp5_2);
    PrtFreeValue(*P_LVALUE_52);
    *P_LVALUE_52 = PrtCloneValue((&P_LIT_INT32_9));
    
    PRT_VALUE** P_LVALUE_53 = &(PTMP_tmp6_2);
    PrtFreeValue(*P_LVALUE_53);
    *P_LVALUE_53 = PrtTupleGet(P_VAR_tmpPara, 2);
    
    PRT_VALUE** P_LVALUE_54 = &(PTMP_tmp7_1);
    PrtFreeValue(*P_LVALUE_54);
    *P_LVALUE_54 = PrtTupleGet(PTMP_tmp6_2, 1);
    
    PRT_VALUE** P_LVALUE_55 = &(PTMP_tmp8_1);
    PrtFreeValue(*P_LVALUE_55);
    *P_LVALUE_55 = PrtMkIntValue(PrtPrimGetInt(PTMP_tmp7_1) + PrtPrimGetInt((&P_LIT_INT32_7)));
    
    PRT_VALUE** P_LVALUE_56 = &(PTMP_tmp9_1);
    PrtFreeValue(*P_LVALUE_56);
    *P_LVALUE_56 = ((_P_GEN_funargs[0] = &(PTMP_tmp5_2)), (_P_GEN_funargs[1] = &(PTMP_tmp8_1)), (_P_GEN_funval = P_writeBuffer_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp5_2), PTMP_tmp5_2 = NULL), (PrtFreeValue(PTMP_tmp8_1), PTMP_tmp8_1 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_3;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_3;
    }
    
    {
        PRT_VALUE** P_LVALUE_57 = &(*(PrtTupleGetLValue(*(PrtTupleGetLValue(P_VAR_tmpPara, 2)), 3)));
        PrtFreeValue(*P_LVALUE_57);
        *P_LVALUE_57 = PTMP_tmp9_1;
        PTMP_tmp9_1 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_58 = &(PTMP_tmp10_1);
    PrtFreeValue(*P_LVALUE_58);
    *P_LVALUE_58 = PrtCloneValue(P_VAR_tmpPara);
    
    PrtSeqInsertEx(P_VAR_InitChannel, (&P_LIT_INT32_6), PTMP_tmp10_1, PRT_FALSE);
    *(&(PTMP_tmp10_1)) = NULL;
    
    PRT_VALUE** P_LVALUE_59 = &(*(PrtTupleGetLValue(P_VAR_tmpPara, 0)));
    PrtFreeValue(*P_LVALUE_59);
    *P_LVALUE_59 = PrtCloneValue((&P_LIT_INT32_9));
    
    PRT_VALUE** P_LVALUE_60 = &(*(PrtTupleGetLValue(*(PrtTupleGetLValue(P_VAR_tmpPara, 1)), 0)));
    PrtFreeValue(*P_LVALUE_60);
    *P_LVALUE_60 = PrtCloneValue((&P_LIT_INT32_7));
    
    PRT_VALUE** P_LVALUE_61 = &(*(PrtTupleGetLValue(*(PrtTupleGetLValue(P_VAR_tmpPara, 1)), 1)));
    PrtFreeValue(*P_LVALUE_61);
    *P_LVALUE_61 = PrtCloneValue((&P_LIT_INT32_6));
    
    PRT_VALUE** P_LVALUE_62 = &(*(PrtTupleGetLValue(*(PrtTupleGetLValue(P_VAR_tmpPara, 1)), 2)));
    PrtFreeValue(*P_LVALUE_62);
    *P_LVALUE_62 = PrtCloneValue((&P_LIT_INT32_8));
    
    PRT_VALUE** P_LVALUE_63 = &(PTMP_tmp11_1);
    PrtFreeValue(*P_LVALUE_63);
    *P_LVALUE_63 = PrtCloneValue((&P_LIT_INT32_7));
    
    PRT_VALUE** P_LVALUE_64 = &(PTMP_tmp12_1);
    PrtFreeValue(*P_LVALUE_64);
    *P_LVALUE_64 = PrtCloneValue((&P_LIT_INT32_9));
    
    PRT_VALUE** P_LVALUE_65 = &(PTMP_tmp13_1);
    PrtFreeValue(*P_LVALUE_65);
    *P_LVALUE_65 = ((_P_GEN_funargs[0] = &(PTMP_tmp11_1)), (_P_GEN_funargs[1] = &(PTMP_tmp12_1)), (_P_GEN_funval = P_writeBuffer_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp11_1), PTMP_tmp11_1 = NULL), (PrtFreeValue(PTMP_tmp12_1), PTMP_tmp12_1 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_3;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_3;
    }
    
    {
        PRT_VALUE** P_LVALUE_66 = &(*(PrtTupleGetLValue(*(PrtTupleGetLValue(P_VAR_tmpPara, 1)), 3)));
        PrtFreeValue(*P_LVALUE_66);
        *P_LVALUE_66 = PTMP_tmp13_1;
        PTMP_tmp13_1 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_67 = &(*(PrtTupleGetLValue(*(PrtTupleGetLValue(P_VAR_tmpPara, 2)), 0)));
    PrtFreeValue(*P_LVALUE_67);
    *P_LVALUE_67 = PrtCloneValue((&P_LIT_INT32_7));
    
    PRT_VALUE** P_LVALUE_68 = &(*(PrtTupleGetLValue(*(PrtTupleGetLValue(P_VAR_tmpPara, 2)), 1)));
    PrtFreeValue(*P_LVALUE_68);
    *P_LVALUE_68 = PrtCloneValue((&P_LIT_INT32_7));
    
    PRT_VALUE** P_LVALUE_69 = &(*(PrtTupleGetLValue(*(PrtTupleGetLValue(P_VAR_tmpPara, 2)), 2)));
    PrtFreeValue(*P_LVALUE_69);
    *P_LVALUE_69 = PrtCloneValue((&P_LIT_INT32_11));
    
    PRT_VALUE** P_LVALUE_70 = &(PTMP_tmp14_1);
    PrtFreeValue(*P_LVALUE_70);
    *P_LVALUE_70 = PrtCloneValue((&P_LIT_INT32_7));
    
    PRT_VALUE** P_LVALUE_71 = &(PTMP_tmp15);
    PrtFreeValue(*P_LVALUE_71);
    *P_LVALUE_71 = PrtTupleGet(P_VAR_tmpPara, 2);
    
    PRT_VALUE** P_LVALUE_72 = &(PTMP_tmp16);
    PrtFreeValue(*P_LVALUE_72);
    *P_LVALUE_72 = PrtTupleGet(PTMP_tmp15, 1);
    
    PRT_VALUE** P_LVALUE_73 = &(PTMP_tmp17);
    PrtFreeValue(*P_LVALUE_73);
    *P_LVALUE_73 = PrtMkIntValue(PrtPrimGetInt(PTMP_tmp16) + PrtPrimGetInt((&P_LIT_INT32_7)));
    
    PRT_VALUE** P_LVALUE_74 = &(PTMP_tmp18);
    PrtFreeValue(*P_LVALUE_74);
    *P_LVALUE_74 = ((_P_GEN_funargs[0] = &(PTMP_tmp14_1)), (_P_GEN_funargs[1] = &(PTMP_tmp17)), (_P_GEN_funval = P_writeBuffer_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp14_1), PTMP_tmp14_1 = NULL), (PrtFreeValue(PTMP_tmp17), PTMP_tmp17 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_3;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_3;
    }
    
    {
        PRT_VALUE** P_LVALUE_75 = &(*(PrtTupleGetLValue(*(PrtTupleGetLValue(P_VAR_tmpPara, 2)), 3)));
        PrtFreeValue(*P_LVALUE_75);
        *P_LVALUE_75 = PTMP_tmp18;
        PTMP_tmp18 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_76 = &(PTMP_tmp19);
    PrtFreeValue(*P_LVALUE_76);
    *P_LVALUE_76 = PrtCloneValue(P_VAR_tmpPara);
    
    PrtSeqInsertEx(P_VAR_InitChannel, (&P_LIT_INT32_7), PTMP_tmp19, PRT_FALSE);
    *(&(PTMP_tmp19)) = NULL;
    
    PRT_VALUE** P_LVALUE_77 = &(PTMP_tmp20);
    PrtFreeValue(*P_LVALUE_77);
    *P_LVALUE_77 = PrtCloneValue(PrtMkInterface(context, 0, 0)->id);
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_3;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_3;
    }
    
    {
        PRT_VALUE** P_LVALUE_78 = &(P_VAR_InitServer);
        PrtFreeValue(*P_LVALUE_78);
        *P_LVALUE_78 = PTMP_tmp20;
        PTMP_tmp20 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_79 = &(PTMP_tmp21);
    PrtFreeValue(*P_LVALUE_79);
    *P_LVALUE_79 = PrtMkDefaultValue(&P_GEND_TYPE_SSNT3iNT4iiiSiNT4iiiSi);
    
    {
        PRT_VALUE** P_LVALUE_80 = &(P_VAR_InitConnetcion);
        PrtFreeValue(*P_LVALUE_80);
        *P_LVALUE_80 = PTMP_tmp21;
        PTMP_tmp21 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_81 = &(PTMP_tmp22);
    PrtFreeValue(*P_LVALUE_81);
    *P_LVALUE_81 = PrtCloneValue(P_VAR_InitChannel);
    
    PrtSeqInsertEx(P_VAR_InitConnetcion, (&P_LIT_INT32_6), PTMP_tmp22, PRT_FALSE);
    *(&(PTMP_tmp22)) = NULL;
    
    PRT_VALUE** P_LVALUE_82 = &(PTMP_tmp23);
    PrtFreeValue(*P_LVALUE_82);
    *P_LVALUE_82 = PrtCloneValue(P_VAR_InitServer);
    
    PRT_VALUE** P_LVALUE_83 = &(PTMP_tmp24);
    PrtFreeValue(*P_LVALUE_83);
    *P_LVALUE_83 = PrtCloneValue(P_VAR_InitConnetcion);
    
    PRT_VALUE** P_LVALUE_84 = &(PTMP_tmp25);
    PrtFreeValue(*P_LVALUE_84);
    *P_LVALUE_84 = (PrtMkTuple(&P_GEND_TYPE_NT2RSSNT3iNT4iiiSiNT4iiiSi, &(PTMP_tmp23), &(PTMP_tmp24)));
    
    PRT_VALUE** P_LVALUE_85 = &(PTMP_tmp26);
    PrtFreeValue(*P_LVALUE_85);
    *P_LVALUE_85 = PrtCloneValue(PrtMkInterface(context, 1, 1, &(PTMP_tmp25))->id);
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_3;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_3;
    }
    
    {
        PRT_VALUE** P_LVALUE_86 = &(P_VAR_ConnServer);
        PrtFreeValue(*P_LVALUE_86);
        *P_LVALUE_86 = PTMP_tmp26;
        PTMP_tmp26 = NULL;
    }
    
    while (PrtPrimGetBool((&P_LIT_BOOLEAN_3)))
    {
        PRT_VALUE** P_LVALUE_87 = &(PTMP_tmp27);
        PrtFreeValue(*P_LVALUE_87);
        *P_LVALUE_87 = PrtMkBoolValue(PrtPrimGetInt(P_VAR_counter_2) < PrtPrimGetInt(*P_VAR_numClients));
        
        PRT_VALUE** P_LVALUE_88 = &(PTMP_tmp28);
        PrtFreeValue(*P_LVALUE_88);
        *P_LVALUE_88 = PrtCloneValue(PTMP_tmp27);
        
        if (PrtPrimGetBool(PTMP_tmp28))
        {
        }
        
        else
        {
            break;
            
        }
        
        
        PRT_VALUE** P_LVALUE_89 = &(PTMP_tmp29);
        PrtFreeValue(*P_LVALUE_89);
        *P_LVALUE_89 = PrtCloneValue(P_VAR_InitServer);
        
        PRT_VALUE** P_LVALUE_90 = &(PTMP_tmp30);
        PrtFreeValue(*P_LVALUE_90);
        *P_LVALUE_90 = PrtCloneValue(P_VAR_ConnServer);
        
        PRT_VALUE** P_LVALUE_91 = &(PTMP_tmp31);
        PrtFreeValue(*P_LVALUE_91);
        *P_LVALUE_91 = (PrtMkTuple(&P_GEND_TYPE_NT2RR, &(PTMP_tmp29), &(PTMP_tmp30)));
        
        PrtMkInterface(context, 2, 1, &(PTMP_tmp31));
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_3;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_3;
        }
        
        PRT_VALUE** P_LVALUE_92 = &(PTMP_tmp32);
        PrtFreeValue(*P_LVALUE_92);
        *P_LVALUE_92 = PrtMkIntValue(PrtPrimGetInt(P_VAR_counter_2) + PrtPrimGetInt((&P_LIT_INT32_7)));
        
        {
            PRT_VALUE** P_LVALUE_93 = &(P_VAR_counter_2);
            PrtFreeValue(*P_LVALUE_93);
            *P_LVALUE_93 = PTMP_tmp32;
            PTMP_tmp32 = NULL;
        }
        
    }
    
    
p_return_3: ;
    PrtFreeValue(P_VAR_ConnServer); P_VAR_ConnServer = NULL;
    PrtFreeValue(P_VAR_InitServer); P_VAR_InitServer = NULL;
    PrtFreeValue(P_VAR_InitConnetcion); P_VAR_InitConnetcion = NULL;
    PrtFreeValue(P_VAR_InitChannel); P_VAR_InitChannel = NULL;
    PrtFreeValue(P_VAR_tmpPara); P_VAR_tmpPara = NULL;
    PrtFreeValue(P_VAR_counter_2); P_VAR_counter_2 = NULL;
    PrtFreeValue(PTMP_tmp0_2); PTMP_tmp0_2 = NULL;
    PrtFreeValue(PTMP_tmp1_2); PTMP_tmp1_2 = NULL;
    PrtFreeValue(PTMP_tmp2_2); PTMP_tmp2_2 = NULL;
    PrtFreeValue(PTMP_tmp3_2); PTMP_tmp3_2 = NULL;
    PrtFreeValue(PTMP_tmp4_2); PTMP_tmp4_2 = NULL;
    PrtFreeValue(PTMP_tmp5_2); PTMP_tmp5_2 = NULL;
    PrtFreeValue(PTMP_tmp6_2); PTMP_tmp6_2 = NULL;
    PrtFreeValue(PTMP_tmp7_1); PTMP_tmp7_1 = NULL;
    PrtFreeValue(PTMP_tmp8_1); PTMP_tmp8_1 = NULL;
    PrtFreeValue(PTMP_tmp9_1); PTMP_tmp9_1 = NULL;
    PrtFreeValue(PTMP_tmp10_1); PTMP_tmp10_1 = NULL;
    PrtFreeValue(PTMP_tmp11_1); PTMP_tmp11_1 = NULL;
    PrtFreeValue(PTMP_tmp12_1); PTMP_tmp12_1 = NULL;
    PrtFreeValue(PTMP_tmp13_1); PTMP_tmp13_1 = NULL;
    PrtFreeValue(PTMP_tmp14_1); PTMP_tmp14_1 = NULL;
    PrtFreeValue(PTMP_tmp15); PTMP_tmp15 = NULL;
    PrtFreeValue(PTMP_tmp16); PTMP_tmp16 = NULL;
    PrtFreeValue(PTMP_tmp17); PTMP_tmp17 = NULL;
    PrtFreeValue(PTMP_tmp18); PTMP_tmp18 = NULL;
    PrtFreeValue(PTMP_tmp19); PTMP_tmp19 = NULL;
    PrtFreeValue(PTMP_tmp20); PTMP_tmp20 = NULL;
    PrtFreeValue(PTMP_tmp21); PTMP_tmp21 = NULL;
    PrtFreeValue(PTMP_tmp22); PTMP_tmp22 = NULL;
    PrtFreeValue(PTMP_tmp23); PTMP_tmp23 = NULL;
    PrtFreeValue(PTMP_tmp24); PTMP_tmp24 = NULL;
    PrtFreeValue(PTMP_tmp25); PTMP_tmp25 = NULL;
    PrtFreeValue(PTMP_tmp26); PTMP_tmp26 = NULL;
    PrtFreeValue(PTMP_tmp27); PTMP_tmp27 = NULL;
    PrtFreeValue(PTMP_tmp28); PTMP_tmp28 = NULL;
    PrtFreeValue(PTMP_tmp29); PTMP_tmp29 = NULL;
    PrtFreeValue(PTMP_tmp30); PTMP_tmp30 = NULL;
    PrtFreeValue(PTMP_tmp31); PTMP_tmp31 = NULL;
    PrtFreeValue(PTMP_tmp32); PTMP_tmp32 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_SetupClientServerSystem =
{
    "SetupClientServerSystem",
    &P_SetupClientServerSystem_IMPL,
    NULL
};


PRT_EVENTDECL* P_VarInitMachine_RECV_INNER[] = { &P_EVENT_eChanConnected, &P_EVENT_eChanDead, &P_EVENT_eChanGotoConfig, &P_EVENT_eChanGotoConnected, &P_EVENT_eChanStarted, &P_EVENT_eComposetFix, &P_EVENT_eComposetHdr, &P_EVENT_eComposetMsg, &P_EVENT_eComposetPara, &P_EVENT_eComposetPlist, &P_EVENT_eComposetVar, &P_EVENT_eConfReq, &P_EVENT_eConfResp, &P_EVENT_eConnReq, &P_EVENT_eConnResp, &P_EVENT_eGetDefaultValueResp, &P_EVENT_eL2CmdReq, &P_EVENT_eParsetFix, &P_EVENT_eParsetHdr, &P_EVENT_eParsetMsg, &P_EVENT_eParsetPara, &P_EVENT_eParsetPlist, &P_EVENT_eParsetVar, &P_EVENT_eSpecGetDefaultValueReq, &P_EVENT_eStartTimer, &P_EVENT_eTimeOut, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_VarInitMachine_RECV =
{
    27U,
    P_VarInitMachine_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_VarInitMachine =
{
    0U,
    "VarInitMachine",
    &P_GEND_TYPE_n,
    &P_EVENTSET_VarInitMachine_RECV
};

PRT_EVENTDECL* P_ConnMachine_RECV_INNER[] = { &P_EVENT_eChanConnected, &P_EVENT_eChanDead, &P_EVENT_eChanGotoConfig, &P_EVENT_eChanGotoConnected, &P_EVENT_eChanStarted, &P_EVENT_eComposetFix, &P_EVENT_eComposetHdr, &P_EVENT_eComposetMsg, &P_EVENT_eComposetPara, &P_EVENT_eComposetPlist, &P_EVENT_eComposetVar, &P_EVENT_eConfReq, &P_EVENT_eConfResp, &P_EVENT_eConnReq, &P_EVENT_eConnResp, &P_EVENT_eGetDefaultValueResp, &P_EVENT_eL2CmdReq, &P_EVENT_eParsetFix, &P_EVENT_eParsetHdr, &P_EVENT_eParsetMsg, &P_EVENT_eParsetPara, &P_EVENT_eParsetPlist, &P_EVENT_eParsetVar, &P_EVENT_eSpecGetDefaultValueReq, &P_EVENT_eStartTimer, &P_EVENT_eTimeOut, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_ConnMachine_RECV =
{
    27U,
    P_ConnMachine_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_ConnMachine =
{
    1U,
    "ConnMachine",
    &P_GEND_TYPE_NT2RSSNT3iNT4iiiSiNT4iiiSi,
    &P_EVENTSET_ConnMachine_RECV
};

PRT_EVENTDECL* P_ClientMachine_RECV_INNER[] = { &P_EVENT_eChanConnected, &P_EVENT_eChanDead, &P_EVENT_eChanGotoConfig, &P_EVENT_eChanGotoConnected, &P_EVENT_eChanStarted, &P_EVENT_eComposetFix, &P_EVENT_eComposetHdr, &P_EVENT_eComposetMsg, &P_EVENT_eComposetPara, &P_EVENT_eComposetPlist, &P_EVENT_eComposetVar, &P_EVENT_eConfReq, &P_EVENT_eConfResp, &P_EVENT_eConnReq, &P_EVENT_eConnResp, &P_EVENT_eGetDefaultValueResp, &P_EVENT_eL2CmdReq, &P_EVENT_eParsetFix, &P_EVENT_eParsetHdr, &P_EVENT_eParsetMsg, &P_EVENT_eParsetPara, &P_EVENT_eParsetPlist, &P_EVENT_eParsetVar, &P_EVENT_eSpecGetDefaultValueReq, &P_EVENT_eStartTimer, &P_EVENT_eTimeOut, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_ClientMachine_RECV =
{
    27U,
    P_ClientMachine_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_ClientMachine =
{
    2U,
    "ClientMachine",
    &P_GEND_TYPE_NT2RR,
    &P_EVENTSET_ClientMachine_RECV
};

PRT_EVENTDECL* P_ChanMachine_RECV_INNER[] = { &P_EVENT_eChanConnected, &P_EVENT_eChanDead, &P_EVENT_eChanGotoConfig, &P_EVENT_eChanGotoConnected, &P_EVENT_eChanStarted, &P_EVENT_eComposetFix, &P_EVENT_eComposetHdr, &P_EVENT_eComposetMsg, &P_EVENT_eComposetPara, &P_EVENT_eComposetPlist, &P_EVENT_eComposetVar, &P_EVENT_eConfReq, &P_EVENT_eConfResp, &P_EVENT_eConnReq, &P_EVENT_eConnResp, &P_EVENT_eGetDefaultValueResp, &P_EVENT_eL2CmdReq, &P_EVENT_eParsetFix, &P_EVENT_eParsetHdr, &P_EVENT_eParsetMsg, &P_EVENT_eParsetPara, &P_EVENT_eParsetPlist, &P_EVENT_eParsetVar, &P_EVENT_eSpecGetDefaultValueReq, &P_EVENT_eStartTimer, &P_EVENT_eTimeOut, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_ChanMachine_RECV =
{
    27U,
    P_ChanMachine_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_ChanMachine =
{
    3U,
    "ChanMachine",
    &P_GEND_TYPE_R_1,
    &P_EVENTSET_ChanMachine_RECV
};

PRT_EVENTDECL* P_TimerMachine_RECV_INNER[] = { &P_EVENT_eChanConnected, &P_EVENT_eChanDead, &P_EVENT_eChanGotoConfig, &P_EVENT_eChanGotoConnected, &P_EVENT_eChanStarted, &P_EVENT_eComposetFix, &P_EVENT_eComposetHdr, &P_EVENT_eComposetMsg, &P_EVENT_eComposetPara, &P_EVENT_eComposetPlist, &P_EVENT_eComposetVar, &P_EVENT_eConfReq, &P_EVENT_eConfResp, &P_EVENT_eConnReq, &P_EVENT_eConnResp, &P_EVENT_eGetDefaultValueResp, &P_EVENT_eL2CmdReq, &P_EVENT_eParsetFix, &P_EVENT_eParsetHdr, &P_EVENT_eParsetMsg, &P_EVENT_eParsetPara, &P_EVENT_eParsetPlist, &P_EVENT_eParsetVar, &P_EVENT_eSpecGetDefaultValueReq, &P_EVENT_eStartTimer, &P_EVENT_eTimeOut, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_TimerMachine_RECV =
{
    27U,
    P_TimerMachine_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_TimerMachine =
{
    4U,
    "TimerMachine",
    &P_GEND_TYPE_NT2mi,
    &P_EVENTSET_TimerMachine_RECV
};

PRT_EVENTDECL* P_TestWithSingleClient_RECV_INNER[] = { &P_EVENT_eChanConnected, &P_EVENT_eChanDead, &P_EVENT_eChanGotoConfig, &P_EVENT_eChanGotoConnected, &P_EVENT_eChanStarted, &P_EVENT_eComposetFix, &P_EVENT_eComposetHdr, &P_EVENT_eComposetMsg, &P_EVENT_eComposetPara, &P_EVENT_eComposetPlist, &P_EVENT_eComposetVar, &P_EVENT_eConfReq, &P_EVENT_eConfResp, &P_EVENT_eConnReq, &P_EVENT_eConnResp, &P_EVENT_eGetDefaultValueResp, &P_EVENT_eL2CmdReq, &P_EVENT_eParsetFix, &P_EVENT_eParsetHdr, &P_EVENT_eParsetMsg, &P_EVENT_eParsetPara, &P_EVENT_eParsetPlist, &P_EVENT_eParsetVar, &P_EVENT_eSpecGetDefaultValueReq, &P_EVENT_eStartTimer, &P_EVENT_eTimeOut, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_TestWithSingleClient_RECV =
{
    27U,
    P_TestWithSingleClient_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_TestWithSingleClient =
{
    5U,
    "TestWithSingleClient",
    &P_GEND_TYPE_n,
    &P_EVENTSET_TestWithSingleClient_RECV
};

PRT_VARDECL P_VarInitMachine_VARS[] = {
    { "vmtuType", &P_GEND_TYPE_NT4iiiSi },
    { "vmtuVal", &P_GEND_TYPE_NT4iiiSi },
    { "vmtuPara", &P_GEND_TYPE_NT3iNT4iiiSiNT4iiiSi },
    { "voptPlist", &P_GEND_TYPE_NT2iSNT3iNT4iiiSiNT4iiiSi },
    { "vmsgoptPlist", &P_GEND_TYPE_NT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB },
    { "vsrcChanID", &P_GEND_TYPE_NT4iiiSi },
    { "vconfReqHdr", &P_GEND_TYPE_NT2SNT4iiiSiNT4iiiSi },
    { "vl2Psm", &P_GEND_TYPE_NT4iiiSi },
    { "vl2PsmType", &P_GEND_TYPE_NT4iiiSi },
    { "vl2PsmPara", &P_GEND_TYPE_NT3iNT4iiiSiNT4iiiSi },
    { "vdstChanID", &P_GEND_TYPE_NT4iiiSi },
    { "vdstChanIDType", &P_GEND_TYPE_NT4iiiSi },
    { "vdstChanIDPara", &P_GEND_TYPE_NT3iNT4iiiSiNT4iiiSi },
    { "vcmdType", &P_GEND_TYPE_NT4iiiSi },
    { "vcmdHdr", &P_GEND_TYPE_NT2SNT4iiiSiNT4iiiSi },
    { "vmsgConfReq", &P_GEND_TYPE_NT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB },
    { "vmsgConfRsp", &P_GEND_TYPE_NT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB },
    { "vmsgConnReq", &P_GEND_TYPE_NT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB },
    { "vmsgConnRsp", &P_GEND_TYPE_NT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB },
    { "vmsgL2Cmd", &P_GEND_TYPE_NT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB },
    { "BT_CONFIG_timeout", &P_GEND_TYPE_i },
    { "BT_CONNECTED_timeout", &P_GEND_TYPE_i }
};

PRT_EVENTDECL* P_Init_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DEFERS =
{
    0U,
    P_Init_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_Init_TRANS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_TRANS =
{
    0U,
    P_Init_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_Init_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DOS =
{
    0U,
    P_Init_DOS_INNER,
    NULL
};

#define P_STATE_VarInitMachine_Init \
{ \
    "VarInitMachine.Init", \
    0U, \
    0U, \
    &P_EVENTSET_Init_DEFERS, \
    &P_EVENTSET_Init_TRANS, \
    &P_EVENTSET_Init_DOS, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_WaitForMsgDefaultValueRequest_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_WaitForMsgDefaultValueRequest_DEFERS =
{
    0U,
    P_WaitForMsgDefaultValueRequest_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_WaitForMsgDefaultValueRequest_TRANS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_WaitForMsgDefaultValueRequest_TRANS =
{
    0U,
    P_WaitForMsgDefaultValueRequest_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_WaitForMsgDefaultValueRequest_DOS_INNER[] = { &P_EVENT_eSpecGetDefaultValueReq };
PRT_EVENTSETDECL P_EVENTSET_WaitForMsgDefaultValueRequest_DOS =
{
    1U,
    P_WaitForMsgDefaultValueRequest_DOS_INNER,
    NULL
};

PRT_DODECL P_DOS[] =
{
    { 1, &P_EVENT_eSpecGetDefaultValueReq, &P_FUNCTION_Anon_1 }
};

#define P_STATE_VarInitMachine_WaitForMsgDefaultValueRequest \
{ \
    "VarInitMachine.WaitForMsgDefaultValueRequest", \
    0U, \
    1U, \
    &P_EVENTSET_WaitForMsgDefaultValueRequest_DEFERS, \
    &P_EVENTSET_WaitForMsgDefaultValueRequest_TRANS, \
    &P_EVENTSET_WaitForMsgDefaultValueRequest_DOS, \
    NULL, \
    P_DOS, \
    &_P_NO_OP, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_VarInitMachine_STATES[] = { P_STATE_VarInitMachine_Init, P_STATE_VarInitMachine_WaitForMsgDefaultValueRequest };

PRT_VALUE* P_Anon_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* PTMP_tmp0_3 = NULL;
    PRT_VALUE* PTMP_tmp1_3 = NULL;
    PRT_VALUE* PTMP_tmp2_3 = NULL;
    PRT_VALUE* PTMP_tmp3_3 = NULL;
    PRT_VALUE* PTMP_tmp4_3 = NULL;
    PRT_VALUE* PTMP_tmp5_3 = NULL;
    PRT_VALUE* PTMP_tmp6_3 = NULL;
    PRT_VALUE* PTMP_tmp7_2 = NULL;
    PRT_VALUE* PTMP_tmp8_2 = NULL;
    PRT_VALUE* PTMP_tmp9_2 = NULL;
    PRT_VALUE* PTMP_tmp10_2 = NULL;
    PRT_VALUE* PTMP_tmp11_2 = NULL;
    PRT_VALUE* PTMP_tmp12_2 = NULL;
    PRT_VALUE* PTMP_tmp13_2 = NULL;
    PRT_VALUE* PTMP_tmp14_2 = NULL;
    PRT_VALUE* PTMP_tmp15_1 = NULL;
    PRT_VALUE* PTMP_tmp16_1 = NULL;
    PRT_VALUE* PTMP_tmp17_1 = NULL;
    PRT_VALUE* PTMP_tmp18_1 = NULL;
    PRT_VALUE* PTMP_tmp19_1 = NULL;
    PRT_VALUE* PTMP_tmp20_1 = NULL;
    PRT_VALUE* PTMP_tmp21_1 = NULL;
    PRT_VALUE* PTMP_tmp22_1 = NULL;
    PRT_VALUE* PTMP_tmp23_1 = NULL;
    PRT_VALUE* PTMP_tmp24_1 = NULL;
    PRT_VALUE* PTMP_tmp25_1 = NULL;
    PRT_VALUE* PTMP_tmp26_1 = NULL;
    PRT_VALUE* PTMP_tmp27_1 = NULL;
    PRT_VALUE* PTMP_tmp28_1 = NULL;
    PRT_VALUE* PTMP_tmp29_1 = NULL;
    PRT_VALUE* PTMP_tmp30_1 = NULL;
    PRT_VALUE* PTMP_tmp31_1 = NULL;
    PRT_VALUE* PTMP_tmp32_1 = NULL;
    PRT_VALUE* PTMP_tmp33 = NULL;
    PRT_VALUE* PTMP_tmp34 = NULL;
    PRT_VALUE* PTMP_tmp35 = NULL;
    PRT_VALUE* PTMP_tmp36 = NULL;
    PRT_VALUE* PTMP_tmp37 = NULL;
    PRT_VALUE* PTMP_tmp38 = NULL;
    PRT_VALUE* PTMP_tmp39 = NULL;
    PRT_VALUE* PTMP_tmp40 = NULL;
    PRT_VALUE* PTMP_tmp41 = NULL;
    PRT_VALUE* PTMP_tmp42 = NULL;
    PRT_VALUE* PTMP_tmp43 = NULL;
    PRT_VALUE* PTMP_tmp44 = NULL;
    PRT_VALUE* PTMP_tmp45 = NULL;
    PRT_VALUE* PTMP_tmp46 = NULL;
    PRT_VALUE* PTMP_tmp47 = NULL;
    PRT_VALUE* PTMP_tmp48 = NULL;
    PRT_VALUE* PTMP_tmp49 = NULL;
    PRT_VALUE* PTMP_tmp50 = NULL;
    PRT_VALUE* PTMP_tmp51 = NULL;
    PRT_VALUE* PTMP_tmp52 = NULL;
    PRT_VALUE* PTMP_tmp53 = NULL;
    PRT_VALUE* PTMP_tmp54 = NULL;
    PRT_VALUE* PTMP_tmp55 = NULL;
    PRT_VALUE* PTMP_tmp56 = NULL;
    PRT_VALUE* PTMP_tmp57 = NULL;
    PRT_VALUE* PTMP_tmp58 = NULL;
    PRT_VALUE* PTMP_tmp59 = NULL;
    PRT_VALUE* PTMP_tmp60 = NULL;
    PRT_VALUE* PTMP_tmp61 = NULL;
    PRT_VALUE* PTMP_tmp62 = NULL;
    PRT_VALUE* PTMP_tmp63 = NULL;
    PRT_VALUE* PTMP_tmp64 = NULL;
    PRT_VALUE* PTMP_tmp65 = NULL;
    PRT_VALUE* PTMP_tmp66 = NULL;
    PRT_VALUE* PTMP_tmp67 = NULL;
    PRT_VALUE* PTMP_tmp68 = NULL;
    PRT_VALUE* PTMP_tmp69 = NULL;
    PRT_VALUE* PTMP_tmp70 = NULL;
    PRT_VALUE* PTMP_tmp71 = NULL;
    PRT_VALUE* PTMP_tmp72 = NULL;
    PRT_VALUE* PTMP_tmp73 = NULL;
    PRT_VALUE* PTMP_tmp74 = NULL;
    PRT_VALUE* PTMP_tmp75 = NULL;
    PRT_VALUE* PTMP_tmp76 = NULL;
    PRT_VALUE* PTMP_tmp77 = NULL;
    PRT_VALUE* PTMP_tmp78 = NULL;
    PRT_VALUE* PTMP_tmp79 = NULL;
    PRT_VALUE* PTMP_tmp80 = NULL;
    PRT_VALUE* PTMP_tmp81 = NULL;
    PRT_VALUE* PTMP_tmp82 = NULL;
    PRT_VALUE* PTMP_tmp83 = NULL;
    PRT_VALUE* PTMP_tmp84 = NULL;
    PRT_VALUE* PTMP_tmp85 = NULL;
    PRT_VALUE* PTMP_tmp86 = NULL;
    PRT_VALUE* PTMP_tmp87 = NULL;
    PRT_VALUE* PTMP_tmp88 = NULL;
    PRT_VALUE* PTMP_tmp89 = NULL;
    PRT_VALUE* PTMP_tmp90 = NULL;
    PRT_VALUE* PTMP_tmp91 = NULL;
    PRT_VALUE* PTMP_tmp92 = NULL;
    PRT_VALUE* PTMP_tmp93 = NULL;
    PRT_VALUE* PTMP_tmp94 = NULL;
    PRT_VALUE* PTMP_tmp95 = NULL;
    PRT_VALUE* PTMP_tmp96 = NULL;
    PRT_VALUE* PTMP_tmp97 = NULL;
    PRT_VALUE* PTMP_tmp98 = NULL;
    PRT_VALUE* PTMP_tmp99 = NULL;
    PRT_VALUE* PTMP_tmp100 = NULL;
    PRT_VALUE* PTMP_tmp101 = NULL;
    PRT_VALUE* PTMP_tmp102 = NULL;
    PRT_VALUE* PTMP_tmp103 = NULL;
    PRT_VALUE* PTMP_tmp104 = NULL;
    PRT_VALUE* PTMP_tmp105 = NULL;
    PRT_VALUE* PTMP_tmp106 = NULL;
    PRT_VALUE* PTMP_tmp107 = NULL;
    PRT_VALUE* PTMP_tmp108 = NULL;
    PRT_VALUE* PTMP_tmp109 = NULL;
    PRT_VALUE* PTMP_tmp110 = NULL;
    PRT_VALUE* PTMP_tmp111 = NULL;
    PRT_VALUE* PTMP_tmp112 = NULL;
    PRT_VALUE* PTMP_tmp113 = NULL;
    PRT_VALUE* PTMP_tmp114 = NULL;
    PRT_VALUE* PTMP_tmp115 = NULL;
    PRT_VALUE* PTMP_tmp116 = NULL;
    PRT_VALUE* PTMP_tmp117 = NULL;
    PRT_VALUE* PTMP_tmp118 = NULL;
    PRT_VALUE* PTMP_tmp119 = NULL;
    PRT_VALUE* PTMP_tmp120 = NULL;
    PRT_VALUE* PTMP_tmp121 = NULL;
    PRT_VALUE* PTMP_tmp122 = NULL;
    PRT_VALUE* PTMP_tmp123 = NULL;
    PRT_VALUE* PTMP_tmp124 = NULL;
    PRT_VALUE* PTMP_tmp125 = NULL;
    PRT_VALUE* PTMP_tmp126 = NULL;
    PRT_VALUE* PTMP_tmp127 = NULL;
    PRT_VALUE* PTMP_tmp128 = NULL;
    PRT_VALUE* PTMP_tmp129 = NULL;
    PRT_VALUE* PTMP_tmp130 = NULL;
    PRT_VALUE* PTMP_tmp131 = NULL;
    PRT_VALUE* PTMP_tmp132 = NULL;
    PRT_VALUE* PTMP_tmp133 = NULL;
    PRT_VALUE* PTMP_tmp134 = NULL;
    PRT_VALUE* PTMP_tmp135 = NULL;
    PRT_VALUE* PTMP_tmp136 = NULL;
    PRT_VALUE* PTMP_tmp137 = NULL;
    PRT_VALUE* PTMP_tmp138 = NULL;
    PRT_VALUE* PTMP_tmp139 = NULL;
    PRT_VALUE* PTMP_tmp140 = NULL;
    PRT_VALUE* PTMP_tmp141 = NULL;
    PRT_VALUE* PTMP_tmp142 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_12 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE P_LIT_INT32_13 = { PRT_VALUE_KIND_INT, { .nt = 10 } };
    PRT_VALUE P_LIT_INT32_14 = { PRT_VALUE_KIND_INT, { .nt = 2 } };
    PRT_VALUE P_LIT_INT32_15 = { PRT_VALUE_KIND_INT, { .nt = 16 } };
    PRT_VALUE P_LIT_INT32_16 = { PRT_VALUE_KIND_INT, { .nt = 1024 } };
    PRT_VALUE P_LIT_INT32_17 = { PRT_VALUE_KIND_INT, { .nt = 8 } };
    PRT_VALUE P_LIT_INT32_18 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE P_LIT_INT32_19 = { PRT_VALUE_KIND_INT, { .nt = 3 } };
    PRT_VALUE P_LIT_INT32_20 = { PRT_VALUE_KIND_INT, { .nt = 4 } };
    PRT_VALUE P_LIT_INT32_21 = { PRT_VALUE_KIND_INT, { .nt = 5 } };
    PRT_VALUE P_LIT_INT32_22 = { PRT_VALUE_KIND_INT, { .nt = 6 } };
    PRT_VALUE P_LIT_INT32_23 = { PRT_VALUE_KIND_INT, { .nt = 7 } };
    PRT_VALUE P_LIT_INT32_24 = { PRT_VALUE_KIND_INT, { .nt = 65535 } };
    PRT_VALUE P_LIT_INT32_25 = { PRT_VALUE_KIND_INT, { .nt = 255 } };
    PRT_VALUE P_LIT_INT32_26 = { PRT_VALUE_KIND_INT, { .nt = 23 } };
    PRT_VALUE P_LIT_INT32_27 = { PRT_VALUE_KIND_INT, { .nt = 22 } };
    PRT_VALUE P_LIT_INT32_28 = { PRT_VALUE_KIND_INT, { .nt = 200 } };
    PRT_VALUE** P_LVALUE_94 = &(PTMP_tmp0_3);
    PrtFreeValue(*P_LVALUE_94);
    *P_LVALUE_94 = PrtCloneValue((&P_LIT_INT32_12));
    
    PRT_VALUE** P_LVALUE_95 = &(PTMP_tmp1_3);
    PrtFreeValue(*P_LVALUE_95);
    *P_LVALUE_95 = PrtCloneValue((&P_LIT_INT32_13));
    
    PRT_VALUE** P_LVALUE_96 = &(PTMP_tmp2_3);
    PrtFreeValue(*P_LVALUE_96);
    *P_LVALUE_96 = PrtCloneValue((&P_LIT_INT32_13));
    
    PRT_VALUE** P_LVALUE_97 = &(PTMP_tmp3_3);
    PrtFreeValue(*P_LVALUE_97);
    *P_LVALUE_97 = PrtMkDefaultValue(&P_GEND_TYPE_Si);
    
    PRT_VALUE** P_LVALUE_98 = &(PTMP_tmp4_3);
    PrtFreeValue(*P_LVALUE_98);
    *P_LVALUE_98 = (PrtMkTuple(&P_GEND_TYPE_NT4iiiSi, &(PTMP_tmp0_3), &(PTMP_tmp1_3), &(PTMP_tmp2_3), &(PTMP_tmp3_3)));
    
    {
        PRT_VALUE** P_LVALUE_99 = &(p_this->varValues[0]);
        PrtFreeValue(*P_LVALUE_99);
        *P_LVALUE_99 = PTMP_tmp4_3;
        PTMP_tmp4_3 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_100 = &(PTMP_tmp5_3);
    PrtFreeValue(*P_LVALUE_100);
    *P_LVALUE_100 = PrtCloneValue((&P_LIT_INT32_14));
    
    PRT_VALUE** P_LVALUE_101 = &(PTMP_tmp6_3);
    PrtFreeValue(*P_LVALUE_101);
    *P_LVALUE_101 = PrtCloneValue((&P_LIT_INT32_15));
    
    PRT_VALUE** P_LVALUE_102 = &(PTMP_tmp7_2);
    PrtFreeValue(*P_LVALUE_102);
    *P_LVALUE_102 = PrtCloneValue((&P_LIT_INT32_16));
    
    PRT_VALUE** P_LVALUE_103 = &(PTMP_tmp8_2);
    PrtFreeValue(*P_LVALUE_103);
    *P_LVALUE_103 = PrtMkDefaultValue(&P_GEND_TYPE_Si);
    
    PRT_VALUE** P_LVALUE_104 = &(PTMP_tmp9_2);
    PrtFreeValue(*P_LVALUE_104);
    *P_LVALUE_104 = (PrtMkTuple(&P_GEND_TYPE_NT4iiiSi, &(PTMP_tmp5_3), &(PTMP_tmp6_3), &(PTMP_tmp7_2), &(PTMP_tmp8_2)));
    
    {
        PRT_VALUE** P_LVALUE_105 = &(p_this->varValues[1]);
        PrtFreeValue(*P_LVALUE_105);
        *P_LVALUE_105 = PTMP_tmp9_2;
        PTMP_tmp9_2 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_106 = &(PTMP_tmp10_2);
    PrtFreeValue(*P_LVALUE_106);
    *P_LVALUE_106 = PrtCloneValue((&P_LIT_INT32_13));
    
    PRT_VALUE** P_LVALUE_107 = &(PTMP_tmp11_2);
    PrtFreeValue(*P_LVALUE_107);
    *P_LVALUE_107 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_108 = &(PTMP_tmp12_2);
    PrtFreeValue(*P_LVALUE_108);
    *P_LVALUE_108 = PrtCloneValue(p_this->varValues[1]);
    
    PRT_VALUE** P_LVALUE_109 = &(PTMP_tmp13_2);
    PrtFreeValue(*P_LVALUE_109);
    *P_LVALUE_109 = (PrtMkTuple(&P_GEND_TYPE_NT3iNT4iiiSiNT4iiiSi, &(PTMP_tmp10_2), &(PTMP_tmp11_2), &(PTMP_tmp12_2)));
    
    {
        PRT_VALUE** P_LVALUE_110 = &(p_this->varValues[2]);
        PrtFreeValue(*P_LVALUE_110);
        *P_LVALUE_110 = PTMP_tmp13_2;
        PTMP_tmp13_2 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_111 = &(PTMP_tmp14_2);
    PrtFreeValue(*P_LVALUE_111);
    *P_LVALUE_111 = PrtCloneValue((&P_LIT_INT32_17));
    
    PRT_VALUE** P_LVALUE_112 = &(PTMP_tmp15_1);
    PrtFreeValue(*P_LVALUE_112);
    *P_LVALUE_112 = PrtMkDefaultValue(&P_GEND_TYPE_SNT3iNT4iiiSiNT4iiiSi);
    
    PRT_VALUE** P_LVALUE_113 = &(PTMP_tmp16_1);
    PrtFreeValue(*P_LVALUE_113);
    *P_LVALUE_113 = (PrtMkTuple(&P_GEND_TYPE_NT2iSNT3iNT4iiiSiNT4iiiSi, &(PTMP_tmp14_2), &(PTMP_tmp15_1)));
    
    {
        PRT_VALUE** P_LVALUE_114 = &(p_this->varValues[3]);
        PrtFreeValue(*P_LVALUE_114);
        *P_LVALUE_114 = PTMP_tmp16_1;
        PTMP_tmp16_1 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_115 = &(PTMP_tmp17_1);
    PrtFreeValue(*P_LVALUE_115);
    *P_LVALUE_115 = PrtCloneValue(p_this->varValues[2]);
    
    PrtSeqInsertEx(*(PrtTupleGetLValue(p_this->varValues[3], 1)), (&P_LIT_INT32_18), PTMP_tmp17_1, PRT_FALSE);
    *(&(PTMP_tmp17_1)) = NULL;
    
    PRT_VALUE** P_LVALUE_116 = &(PTMP_tmp18_1);
    PrtFreeValue(*P_LVALUE_116);
    *P_LVALUE_116 = PrtMkDefaultValue(&P_GEND_TYPE_NT3iNT4iiiSiNT4iiiSi);
    
    PrtSeqInsertEx(*(PrtTupleGetLValue(p_this->varValues[3], 1)), (&P_LIT_INT32_12), PTMP_tmp18_1, PRT_FALSE);
    *(&(PTMP_tmp18_1)) = NULL;
    
    PRT_VALUE** P_LVALUE_117 = &(PTMP_tmp19_1);
    PrtFreeValue(*P_LVALUE_117);
    *P_LVALUE_117 = PrtMkDefaultValue(&P_GEND_TYPE_NT3iNT4iiiSiNT4iiiSi);
    
    PrtSeqInsertEx(*(PrtTupleGetLValue(p_this->varValues[3], 1)), (&P_LIT_INT32_14), PTMP_tmp19_1, PRT_FALSE);
    *(&(PTMP_tmp19_1)) = NULL;
    
    PRT_VALUE** P_LVALUE_118 = &(PTMP_tmp20_1);
    PrtFreeValue(*P_LVALUE_118);
    *P_LVALUE_118 = PrtMkDefaultValue(&P_GEND_TYPE_NT3iNT4iiiSiNT4iiiSi);
    
    PrtSeqInsertEx(*(PrtTupleGetLValue(p_this->varValues[3], 1)), (&P_LIT_INT32_19), PTMP_tmp20_1, PRT_FALSE);
    *(&(PTMP_tmp20_1)) = NULL;
    
    PRT_VALUE** P_LVALUE_119 = &(PTMP_tmp21_1);
    PrtFreeValue(*P_LVALUE_119);
    *P_LVALUE_119 = PrtMkDefaultValue(&P_GEND_TYPE_NT3iNT4iiiSiNT4iiiSi);
    
    PrtSeqInsertEx(*(PrtTupleGetLValue(p_this->varValues[3], 1)), (&P_LIT_INT32_20), PTMP_tmp21_1, PRT_FALSE);
    *(&(PTMP_tmp21_1)) = NULL;
    
    PRT_VALUE** P_LVALUE_120 = &(PTMP_tmp22_1);
    PrtFreeValue(*P_LVALUE_120);
    *P_LVALUE_120 = PrtMkDefaultValue(&P_GEND_TYPE_NT3iNT4iiiSiNT4iiiSi);
    
    PrtSeqInsertEx(*(PrtTupleGetLValue(p_this->varValues[3], 1)), (&P_LIT_INT32_21), PTMP_tmp22_1, PRT_FALSE);
    *(&(PTMP_tmp22_1)) = NULL;
    
    PRT_VALUE** P_LVALUE_121 = &(PTMP_tmp23_1);
    PrtFreeValue(*P_LVALUE_121);
    *P_LVALUE_121 = PrtMkDefaultValue(&P_GEND_TYPE_NT3iNT4iiiSiNT4iiiSi);
    
    PrtSeqInsertEx(*(PrtTupleGetLValue(p_this->varValues[3], 1)), (&P_LIT_INT32_22), PTMP_tmp23_1, PRT_FALSE);
    *(&(PTMP_tmp23_1)) = NULL;
    
    PRT_VALUE** P_LVALUE_122 = &(PTMP_tmp24_1);
    PrtFreeValue(*P_LVALUE_122);
    *P_LVALUE_122 = PrtMkDefaultValue(&P_GEND_TYPE_NT3iNT4iiiSiNT4iiiSi);
    
    PrtSeqInsertEx(*(PrtTupleGetLValue(p_this->varValues[3], 1)), (&P_LIT_INT32_23), PTMP_tmp24_1, PRT_FALSE);
    *(&(PTMP_tmp24_1)) = NULL;
    
    PRT_VALUE** P_LVALUE_123 = &(PTMP_tmp25_1);
    PrtFreeValue(*P_LVALUE_123);
    *P_LVALUE_123 = PrtCloneValue((&P_LIT_INT32_19));
    
    PRT_VALUE** P_LVALUE_124 = &(PTMP_tmp26_1);
    PrtFreeValue(*P_LVALUE_124);
    *P_LVALUE_124 = PrtMkDefaultValue(&P_GEND_TYPE_NT3iiSi);
    
    PRT_VALUE** P_LVALUE_125 = &(PTMP_tmp27_1);
    PrtFreeValue(*P_LVALUE_125);
    *P_LVALUE_125 = PrtMkDefaultValue(&P_GEND_TYPE_NT3iNT4iiiSiNT4iiiSi);
    
    PRT_VALUE** P_LVALUE_126 = &(PTMP_tmp28_1);
    PrtFreeValue(*P_LVALUE_126);
    *P_LVALUE_126 = PrtMkDefaultValue(&P_GEND_TYPE_SNT4iiiSi);
    
    PRT_VALUE** P_LVALUE_127 = &(PTMP_tmp29_1);
    PrtFreeValue(*P_LVALUE_127);
    *P_LVALUE_127 = PrtCloneValue(p_this->varValues[3]);
    
    PRT_VALUE** P_LVALUE_128 = &(PTMP_tmp30_1);
    PrtFreeValue(*P_LVALUE_128);
    *P_LVALUE_128 = PrtMkDefaultValue(&P_GEND_TYPE_NT2NT2SNT4iiiSiNT4iiiSiB);
    
    PRT_VALUE** P_LVALUE_129 = &(PTMP_tmp31_1);
    PrtFreeValue(*P_LVALUE_129);
    *P_LVALUE_129 = PrtMkDefaultValue(&P_GEND_TYPE_NT2NT2SNT4iiiSiNT4iiiSiSNT2iB);
    
    PRT_VALUE** P_LVALUE_130 = &(PTMP_tmp32_1);
    PrtFreeValue(*P_LVALUE_130);
    *P_LVALUE_130 = (PrtMkTuple(&P_GEND_TYPE_NT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB, &(PTMP_tmp25_1), &(PTMP_tmp26_1), &(PTMP_tmp27_1), &(PTMP_tmp28_1), &(PTMP_tmp29_1), &(PTMP_tmp30_1), &(PTMP_tmp31_1)));
    
    {
        PRT_VALUE** P_LVALUE_131 = &(p_this->varValues[4]);
        PrtFreeValue(*P_LVALUE_131);
        *P_LVALUE_131 = PTMP_tmp32_1;
        PTMP_tmp32_1 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_132 = &(PTMP_tmp33);
    PrtFreeValue(*P_LVALUE_132);
    *P_LVALUE_132 = PrtCloneValue((&P_LIT_INT32_14));
    
    PRT_VALUE** P_LVALUE_133 = &(PTMP_tmp34);
    PrtFreeValue(*P_LVALUE_133);
    *P_LVALUE_133 = PrtCloneValue((&P_LIT_INT32_12));
    
    PRT_VALUE** P_LVALUE_134 = &(PTMP_tmp35);
    PrtFreeValue(*P_LVALUE_134);
    *P_LVALUE_134 = PrtCloneValue((&P_LIT_INT32_24));
    
    PRT_VALUE** P_LVALUE_135 = &(PTMP_tmp36);
    PrtFreeValue(*P_LVALUE_135);
    *P_LVALUE_135 = PrtMkDefaultValue(&P_GEND_TYPE_Si);
    
    PRT_VALUE** P_LVALUE_136 = &(PTMP_tmp37);
    PrtFreeValue(*P_LVALUE_136);
    *P_LVALUE_136 = (PrtMkTuple(&P_GEND_TYPE_NT4iiiSi, &(PTMP_tmp33), &(PTMP_tmp34), &(PTMP_tmp35), &(PTMP_tmp36)));
    
    {
        PRT_VALUE** P_LVALUE_137 = &(p_this->varValues[5]);
        PrtFreeValue(*P_LVALUE_137);
        *P_LVALUE_137 = PTMP_tmp37;
        PTMP_tmp37 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_138 = &(PTMP_tmp38);
    PrtFreeValue(*P_LVALUE_138);
    *P_LVALUE_138 = PrtMkDefaultValue(&P_GEND_TYPE_SNT4iiiSi);
    
    PRT_VALUE** P_LVALUE_139 = &(PTMP_tmp39);
    PrtFreeValue(*P_LVALUE_139);
    *P_LVALUE_139 = PrtCloneValue((&P_LIT_INT32_12));
    
    PRT_VALUE** P_LVALUE_140 = &(PTMP_tmp40);
    PrtFreeValue(*P_LVALUE_140);
    *P_LVALUE_140 = PrtCloneValue((&P_LIT_INT32_18));
    
    PRT_VALUE** P_LVALUE_141 = &(PTMP_tmp41);
    PrtFreeValue(*P_LVALUE_141);
    *P_LVALUE_141 = PrtCloneValue((&P_LIT_INT32_25));
    
    PRT_VALUE** P_LVALUE_142 = &(PTMP_tmp42);
    PrtFreeValue(*P_LVALUE_142);
    *P_LVALUE_142 = PrtCloneValue((&P_LIT_INT32_12));
    
    PRT_VALUE** P_LVALUE_143 = &(PTMP_tmp43);
    PrtFreeValue(*P_LVALUE_143);
    *P_LVALUE_143 = PrtCloneValue((&P_LIT_INT32_12));
    
    PRT_VALUE** P_LVALUE_144 = &(PTMP_tmp44);
    PrtFreeValue(*P_LVALUE_144);
    *P_LVALUE_144 = ((_P_GEN_funargs[0] = &(PTMP_tmp42)), (_P_GEN_funargs[1] = &(PTMP_tmp43)), (_P_GEN_funval = P_writeBuffer_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp42), PTMP_tmp42 = NULL), (PrtFreeValue(PTMP_tmp43), PTMP_tmp43 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_4;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_4;
    }
    
    PRT_VALUE** P_LVALUE_145 = &(PTMP_tmp45);
    PrtFreeValue(*P_LVALUE_145);
    *P_LVALUE_145 = (PrtMkTuple(&P_GEND_TYPE_NT4iiiSi, &(PTMP_tmp39), &(PTMP_tmp40), &(PTMP_tmp41), &(PTMP_tmp44)));
    
    PRT_VALUE** P_LVALUE_146 = &(PTMP_tmp46);
    PrtFreeValue(*P_LVALUE_146);
    *P_LVALUE_146 = (PrtMkTuple(&P_GEND_TYPE_NT2SNT4iiiSiNT4iiiSi, &(PTMP_tmp38), &(PTMP_tmp45)));
    
    {
        PRT_VALUE** P_LVALUE_147 = &(p_this->varValues[6]);
        PrtFreeValue(*P_LVALUE_147);
        *P_LVALUE_147 = PTMP_tmp46;
        PTMP_tmp46 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_148 = &(PTMP_tmp47);
    PrtFreeValue(*P_LVALUE_148);
    *P_LVALUE_148 = PrtCloneValue(p_this->varValues[5]);
    
    PrtSeqInsertEx(*(PrtTupleGetLValue(p_this->varValues[6], 0)), (&P_LIT_INT32_18), PTMP_tmp47, PRT_FALSE);
    *(&(PTMP_tmp47)) = NULL;
    
    PRT_VALUE** P_LVALUE_149 = &(PTMP_tmp48);
    PrtFreeValue(*P_LVALUE_149);
    *P_LVALUE_149 = PrtCloneValue((&P_LIT_INT32_12));
    
    PRT_VALUE** P_LVALUE_150 = &(PTMP_tmp49);
    PrtFreeValue(*P_LVALUE_150);
    *P_LVALUE_150 = PrtCloneValue((&P_LIT_INT32_12));
    
    PRT_VALUE** P_LVALUE_151 = &(PTMP_tmp50);
    PrtFreeValue(*P_LVALUE_151);
    *P_LVALUE_151 = PrtCloneValue((&P_LIT_INT32_26));
    
    PRT_VALUE** P_LVALUE_152 = &(PTMP_tmp51);
    PrtFreeValue(*P_LVALUE_152);
    *P_LVALUE_152 = PrtMkDefaultValue(&P_GEND_TYPE_Si);
    
    PRT_VALUE** P_LVALUE_153 = &(PTMP_tmp52);
    PrtFreeValue(*P_LVALUE_153);
    *P_LVALUE_153 = (PrtMkTuple(&P_GEND_TYPE_NT4iiiSi, &(PTMP_tmp48), &(PTMP_tmp49), &(PTMP_tmp50), &(PTMP_tmp51)));
    
    {
        PRT_VALUE** P_LVALUE_154 = &(p_this->varValues[7]);
        PrtFreeValue(*P_LVALUE_154);
        *P_LVALUE_154 = PTMP_tmp52;
        PTMP_tmp52 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_155 = &(PTMP_tmp53);
    PrtFreeValue(*P_LVALUE_155);
    *P_LVALUE_155 = PrtCloneValue((&P_LIT_INT32_12));
    
    PRT_VALUE** P_LVALUE_156 = &(PTMP_tmp54);
    PrtFreeValue(*P_LVALUE_156);
    *P_LVALUE_156 = PrtCloneValue((&P_LIT_INT32_14));
    
    PRT_VALUE** P_LVALUE_157 = &(PTMP_tmp55);
    PrtFreeValue(*P_LVALUE_157);
    *P_LVALUE_157 = PrtCloneValue((&P_LIT_INT32_14));
    
    PRT_VALUE** P_LVALUE_158 = &(PTMP_tmp56);
    PrtFreeValue(*P_LVALUE_158);
    *P_LVALUE_158 = PrtMkDefaultValue(&P_GEND_TYPE_Si);
    
    PRT_VALUE** P_LVALUE_159 = &(PTMP_tmp57);
    PrtFreeValue(*P_LVALUE_159);
    *P_LVALUE_159 = (PrtMkTuple(&P_GEND_TYPE_NT4iiiSi, &(PTMP_tmp53), &(PTMP_tmp54), &(PTMP_tmp55), &(PTMP_tmp56)));
    
    {
        PRT_VALUE** P_LVALUE_160 = &(p_this->varValues[8]);
        PrtFreeValue(*P_LVALUE_160);
        *P_LVALUE_160 = PTMP_tmp57;
        PTMP_tmp57 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_161 = &(PTMP_tmp58);
    PrtFreeValue(*P_LVALUE_161);
    *P_LVALUE_161 = PrtCloneValue((&P_LIT_INT32_14));
    
    PRT_VALUE** P_LVALUE_162 = &(PTMP_tmp59);
    PrtFreeValue(*P_LVALUE_162);
    *P_LVALUE_162 = PrtCloneValue(p_this->varValues[8]);
    
    PRT_VALUE** P_LVALUE_163 = &(PTMP_tmp60);
    PrtFreeValue(*P_LVALUE_163);
    *P_LVALUE_163 = PrtCloneValue(p_this->varValues[7]);
    
    PRT_VALUE** P_LVALUE_164 = &(PTMP_tmp61);
    PrtFreeValue(*P_LVALUE_164);
    *P_LVALUE_164 = (PrtMkTuple(&P_GEND_TYPE_NT3iNT4iiiSiNT4iiiSi, &(PTMP_tmp58), &(PTMP_tmp59), &(PTMP_tmp60)));
    
    {
        PRT_VALUE** P_LVALUE_165 = &(p_this->varValues[9]);
        PrtFreeValue(*P_LVALUE_165);
        *P_LVALUE_165 = PTMP_tmp61;
        PTMP_tmp61 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_166 = &(PTMP_tmp62);
    PrtFreeValue(*P_LVALUE_166);
    *P_LVALUE_166 = PrtCloneValue((&P_LIT_INT32_14));
    
    PRT_VALUE** P_LVALUE_167 = &(PTMP_tmp63);
    PrtFreeValue(*P_LVALUE_167);
    *P_LVALUE_167 = PrtCloneValue((&P_LIT_INT32_12));
    
    PRT_VALUE** P_LVALUE_168 = &(PTMP_tmp64);
    PrtFreeValue(*P_LVALUE_168);
    *P_LVALUE_168 = PrtCloneValue((&P_LIT_INT32_24));
    
    PRT_VALUE** P_LVALUE_169 = &(PTMP_tmp65);
    PrtFreeValue(*P_LVALUE_169);
    *P_LVALUE_169 = PrtMkDefaultValue(&P_GEND_TYPE_Si);
    
    PRT_VALUE** P_LVALUE_170 = &(PTMP_tmp66);
    PrtFreeValue(*P_LVALUE_170);
    *P_LVALUE_170 = (PrtMkTuple(&P_GEND_TYPE_NT4iiiSi, &(PTMP_tmp62), &(PTMP_tmp63), &(PTMP_tmp64), &(PTMP_tmp65)));
    
    {
        PRT_VALUE** P_LVALUE_171 = &(p_this->varValues[10]);
        PrtFreeValue(*P_LVALUE_171);
        *P_LVALUE_171 = PTMP_tmp66;
        PTMP_tmp66 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_172 = &(PTMP_tmp67);
    PrtFreeValue(*P_LVALUE_172);
    *P_LVALUE_172 = PrtCloneValue((&P_LIT_INT32_12));
    
    PRT_VALUE** P_LVALUE_173 = &(PTMP_tmp68);
    PrtFreeValue(*P_LVALUE_173);
    *P_LVALUE_173 = PrtCloneValue((&P_LIT_INT32_12));
    
    PRT_VALUE** P_LVALUE_174 = &(PTMP_tmp69);
    PrtFreeValue(*P_LVALUE_174);
    *P_LVALUE_174 = PrtCloneValue((&P_LIT_INT32_12));
    
    PRT_VALUE** P_LVALUE_175 = &(PTMP_tmp70);
    PrtFreeValue(*P_LVALUE_175);
    *P_LVALUE_175 = PrtMkDefaultValue(&P_GEND_TYPE_Si);
    
    PRT_VALUE** P_LVALUE_176 = &(PTMP_tmp71);
    PrtFreeValue(*P_LVALUE_176);
    *P_LVALUE_176 = (PrtMkTuple(&P_GEND_TYPE_NT4iiiSi, &(PTMP_tmp67), &(PTMP_tmp68), &(PTMP_tmp69), &(PTMP_tmp70)));
    
    {
        PRT_VALUE** P_LVALUE_177 = &(p_this->varValues[11]);
        PrtFreeValue(*P_LVALUE_177);
        *P_LVALUE_177 = PTMP_tmp71;
        PTMP_tmp71 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_178 = &(PTMP_tmp72);
    PrtFreeValue(*P_LVALUE_178);
    *P_LVALUE_178 = PrtCloneValue((&P_LIT_INT32_12));
    
    PRT_VALUE** P_LVALUE_179 = &(PTMP_tmp73);
    PrtFreeValue(*P_LVALUE_179);
    *P_LVALUE_179 = PrtCloneValue(p_this->varValues[11]);
    
    PRT_VALUE** P_LVALUE_180 = &(PTMP_tmp74);
    PrtFreeValue(*P_LVALUE_180);
    *P_LVALUE_180 = PrtCloneValue(p_this->varValues[10]);
    
    PRT_VALUE** P_LVALUE_181 = &(PTMP_tmp75);
    PrtFreeValue(*P_LVALUE_181);
    *P_LVALUE_181 = (PrtMkTuple(&P_GEND_TYPE_NT3iNT4iiiSiNT4iiiSi, &(PTMP_tmp72), &(PTMP_tmp73), &(PTMP_tmp74)));
    
    {
        PRT_VALUE** P_LVALUE_182 = &(p_this->varValues[12]);
        PrtFreeValue(*P_LVALUE_182);
        *P_LVALUE_182 = PTMP_tmp75;
        PTMP_tmp75 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_183 = &(PTMP_tmp76);
    PrtFreeValue(*P_LVALUE_183);
    *P_LVALUE_183 = PrtCloneValue((&P_LIT_INT32_12));
    
    PRT_VALUE** P_LVALUE_184 = &(PTMP_tmp77);
    PrtFreeValue(*P_LVALUE_184);
    *P_LVALUE_184 = PrtCloneValue((&P_LIT_INT32_12));
    
    PRT_VALUE** P_LVALUE_185 = &(PTMP_tmp78);
    PrtFreeValue(*P_LVALUE_185);
    *P_LVALUE_185 = PrtCloneValue((&P_LIT_INT32_27));
    
    PRT_VALUE** P_LVALUE_186 = &(PTMP_tmp79);
    PrtFreeValue(*P_LVALUE_186);
    *P_LVALUE_186 = PrtMkDefaultValue(&P_GEND_TYPE_Si);
    
    PRT_VALUE** P_LVALUE_187 = &(PTMP_tmp80);
    PrtFreeValue(*P_LVALUE_187);
    *P_LVALUE_187 = (PrtMkTuple(&P_GEND_TYPE_NT4iiiSi, &(PTMP_tmp76), &(PTMP_tmp77), &(PTMP_tmp78), &(PTMP_tmp79)));
    
    {
        PRT_VALUE** P_LVALUE_188 = &(p_this->varValues[13]);
        PrtFreeValue(*P_LVALUE_188);
        *P_LVALUE_188 = PTMP_tmp80;
        PTMP_tmp80 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_189 = &(PTMP_tmp81);
    PrtFreeValue(*P_LVALUE_189);
    *P_LVALUE_189 = PrtMkDefaultValue(&P_GEND_TYPE_SNT4iiiSi);
    
    PRT_VALUE** P_LVALUE_190 = &(PTMP_tmp82);
    PrtFreeValue(*P_LVALUE_190);
    *P_LVALUE_190 = PrtCloneValue((&P_LIT_INT32_12));
    
    PRT_VALUE** P_LVALUE_191 = &(PTMP_tmp83);
    PrtFreeValue(*P_LVALUE_191);
    *P_LVALUE_191 = PrtCloneValue((&P_LIT_INT32_18));
    
    PRT_VALUE** P_LVALUE_192 = &(PTMP_tmp84);
    PrtFreeValue(*P_LVALUE_192);
    *P_LVALUE_192 = PrtCloneValue((&P_LIT_INT32_25));
    
    PRT_VALUE** P_LVALUE_193 = &(PTMP_tmp85);
    PrtFreeValue(*P_LVALUE_193);
    *P_LVALUE_193 = PrtCloneValue((&P_LIT_INT32_12));
    
    PRT_VALUE** P_LVALUE_194 = &(PTMP_tmp86);
    PrtFreeValue(*P_LVALUE_194);
    *P_LVALUE_194 = PrtCloneValue((&P_LIT_INT32_12));
    
    PRT_VALUE** P_LVALUE_195 = &(PTMP_tmp87);
    PrtFreeValue(*P_LVALUE_195);
    *P_LVALUE_195 = ((_P_GEN_funargs[0] = &(PTMP_tmp85)), (_P_GEN_funargs[1] = &(PTMP_tmp86)), (_P_GEN_funval = P_writeBuffer_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp85), PTMP_tmp85 = NULL), (PrtFreeValue(PTMP_tmp86), PTMP_tmp86 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_4;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_4;
    }
    
    PRT_VALUE** P_LVALUE_196 = &(PTMP_tmp88);
    PrtFreeValue(*P_LVALUE_196);
    *P_LVALUE_196 = (PrtMkTuple(&P_GEND_TYPE_NT4iiiSi, &(PTMP_tmp82), &(PTMP_tmp83), &(PTMP_tmp84), &(PTMP_tmp87)));
    
    PRT_VALUE** P_LVALUE_197 = &(PTMP_tmp89);
    PrtFreeValue(*P_LVALUE_197);
    *P_LVALUE_197 = (PrtMkTuple(&P_GEND_TYPE_NT2SNT4iiiSiNT4iiiSi, &(PTMP_tmp81), &(PTMP_tmp88)));
    
    {
        PRT_VALUE** P_LVALUE_198 = &(p_this->varValues[14]);
        PrtFreeValue(*P_LVALUE_198);
        *P_LVALUE_198 = PTMP_tmp89;
        PTMP_tmp89 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_199 = &(PTMP_tmp90);
    PrtFreeValue(*P_LVALUE_199);
    *P_LVALUE_199 = PrtCloneValue(p_this->varValues[13]);
    
    PrtSeqInsertEx(*(PrtTupleGetLValue(p_this->varValues[14], 0)), (&P_LIT_INT32_18), PTMP_tmp90, PRT_FALSE);
    *(&(PTMP_tmp90)) = NULL;
    
    PRT_VALUE** P_LVALUE_200 = &(PTMP_tmp91);
    PrtFreeValue(*P_LVALUE_200);
    *P_LVALUE_200 = PrtCloneValue((&P_LIT_INT32_20));
    
    PRT_VALUE** P_LVALUE_201 = &(PTMP_tmp92);
    PrtFreeValue(*P_LVALUE_201);
    *P_LVALUE_201 = PrtMkDefaultValue(&P_GEND_TYPE_NT3iiSi);
    
    PRT_VALUE** P_LVALUE_202 = &(PTMP_tmp93);
    PrtFreeValue(*P_LVALUE_202);
    *P_LVALUE_202 = PrtMkDefaultValue(&P_GEND_TYPE_NT3iNT4iiiSiNT4iiiSi);
    
    PRT_VALUE** P_LVALUE_203 = &(PTMP_tmp94);
    PrtFreeValue(*P_LVALUE_203);
    *P_LVALUE_203 = PrtMkDefaultValue(&P_GEND_TYPE_SNT4iiiSi);
    
    PRT_VALUE** P_LVALUE_204 = &(PTMP_tmp95);
    PrtFreeValue(*P_LVALUE_204);
    *P_LVALUE_204 = PrtMkDefaultValue(&P_GEND_TYPE_NT2iSNT3iNT4iiiSiNT4iiiSi);
    
    PRT_VALUE** P_LVALUE_205 = &(PTMP_tmp96);
    PrtFreeValue(*P_LVALUE_205);
    *P_LVALUE_205 = PrtCloneValue(p_this->varValues[6]);
    
    PRT_VALUE** P_LVALUE_206 = &(PTMP_tmp97);
    PrtFreeValue(*P_LVALUE_206);
    *P_LVALUE_206 = PrtCloneValue(p_this->varValues[4]);
    
    PRT_VALUE** P_LVALUE_207 = &(PTMP_tmp98);
    PrtFreeValue(*P_LVALUE_207);
    *P_LVALUE_207 = (PrtMkTuple(&P_GEND_TYPE_NT2NT2SNT4iiiSiNT4iiiSiNT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB, &(PTMP_tmp96), &(PTMP_tmp97)));
    
    PRT_VALUE** P_LVALUE_208 = &(PTMP_tmp99);
    PrtFreeValue(*P_LVALUE_208);
    *P_LVALUE_208 = PrtMkDefaultValue(&P_GEND_TYPE_NT2NT2SNT4iiiSiNT4iiiSiSNT2iB);
    
    PRT_VALUE** P_LVALUE_209 = &(PTMP_tmp100);
    PrtFreeValue(*P_LVALUE_209);
    *P_LVALUE_209 = (PrtMkTuple(&P_GEND_TYPE_NT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiNT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB, &(PTMP_tmp91), &(PTMP_tmp92), &(PTMP_tmp93), &(PTMP_tmp94), &(PTMP_tmp95), &(PTMP_tmp98), &(PTMP_tmp99)));
    
    {
        PRT_VALUE** P_LVALUE_210 = &(p_this->varValues[15]);
        PrtFreeValue(*P_LVALUE_210);
        *P_LVALUE_210 = PTMP_tmp100;
        PTMP_tmp100 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_211 = &(PTMP_tmp101);
    PrtFreeValue(*P_LVALUE_211);
    *P_LVALUE_211 = PrtCloneValue((&P_LIT_INT32_18));
    
    PRT_VALUE** P_LVALUE_212 = &(PTMP_tmp102);
    PrtFreeValue(*P_LVALUE_212);
    *P_LVALUE_212 = PrtMkDefaultValue(&P_GEND_TYPE_NT3iiSi);
    
    PRT_VALUE** P_LVALUE_213 = &(PTMP_tmp103);
    PrtFreeValue(*P_LVALUE_213);
    *P_LVALUE_213 = PrtMkDefaultValue(&P_GEND_TYPE_NT3iNT4iiiSiNT4iiiSi);
    
    PRT_VALUE** P_LVALUE_214 = &(PTMP_tmp104);
    PrtFreeValue(*P_LVALUE_214);
    *P_LVALUE_214 = PrtMkDefaultValue(&P_GEND_TYPE_SNT4iiiSi);
    
    PRT_VALUE** P_LVALUE_215 = &(PTMP_tmp105);
    PrtFreeValue(*P_LVALUE_215);
    *P_LVALUE_215 = PrtMkDefaultValue(&P_GEND_TYPE_NT2iSNT3iNT4iiiSiNT4iiiSi);
    
    PRT_VALUE** P_LVALUE_216 = &(PTMP_tmp106);
    PrtFreeValue(*P_LVALUE_216);
    *P_LVALUE_216 = PrtMkDefaultValue(&P_GEND_TYPE_NT2NT2SNT4iiiSiNT4iiiSiB);
    
    PRT_VALUE** P_LVALUE_217 = &(PTMP_tmp107);
    PrtFreeValue(*P_LVALUE_217);
    *P_LVALUE_217 = PrtMkDefaultValue(&P_GEND_TYPE_NT2NT2SNT4iiiSiNT4iiiSiSNT2iB);
    
    PRT_VALUE** P_LVALUE_218 = &(PTMP_tmp108);
    PrtFreeValue(*P_LVALUE_218);
    *P_LVALUE_218 = (PrtMkTuple(&P_GEND_TYPE_NT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB, &(PTMP_tmp101), &(PTMP_tmp102), &(PTMP_tmp103), &(PTMP_tmp104), &(PTMP_tmp105), &(PTMP_tmp106), &(PTMP_tmp107)));
    
    {
        PRT_VALUE** P_LVALUE_219 = &(p_this->varValues[16]);
        PrtFreeValue(*P_LVALUE_219);
        *P_LVALUE_219 = PTMP_tmp108;
        PTMP_tmp108 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_220 = &(PTMP_tmp109);
    PrtFreeValue(*P_LVALUE_220);
    *P_LVALUE_220 = PrtCloneValue((&P_LIT_INT32_14));
    
    PRT_VALUE** P_LVALUE_221 = &(PTMP_tmp110);
    PrtFreeValue(*P_LVALUE_221);
    *P_LVALUE_221 = PrtMkDefaultValue(&P_GEND_TYPE_NT3iiSi);
    
    PRT_VALUE** P_LVALUE_222 = &(PTMP_tmp111);
    PrtFreeValue(*P_LVALUE_222);
    *P_LVALUE_222 = PrtMkDefaultValue(&P_GEND_TYPE_NT3iNT4iiiSiNT4iiiSi);
    
    PRT_VALUE** P_LVALUE_223 = &(PTMP_tmp112);
    PrtFreeValue(*P_LVALUE_223);
    *P_LVALUE_223 = PrtMkDefaultValue(&P_GEND_TYPE_SNT4iiiSi);
    
    PRT_VALUE** P_LVALUE_224 = &(PTMP_tmp113);
    PrtFreeValue(*P_LVALUE_224);
    *P_LVALUE_224 = PrtMkDefaultValue(&P_GEND_TYPE_NT2iSNT3iNT4iiiSiNT4iiiSi);
    
    PRT_VALUE** P_LVALUE_225 = &(PTMP_tmp114);
    PrtFreeValue(*P_LVALUE_225);
    *P_LVALUE_225 = PrtMkDefaultValue(&P_GEND_TYPE_NT2NT2SNT4iiiSiNT4iiiSiB);
    
    PRT_VALUE** P_LVALUE_226 = &(PTMP_tmp115);
    PrtFreeValue(*P_LVALUE_226);
    *P_LVALUE_226 = PrtMkDefaultValue(&P_GEND_TYPE_NT2NT2SNT4iiiSiNT4iiiSiSNT2iB);
    
    PRT_VALUE** P_LVALUE_227 = &(PTMP_tmp116);
    PrtFreeValue(*P_LVALUE_227);
    *P_LVALUE_227 = (PrtMkTuple(&P_GEND_TYPE_NT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB, &(PTMP_tmp109), &(PTMP_tmp110), &(PTMP_tmp111), &(PTMP_tmp112), &(PTMP_tmp113), &(PTMP_tmp114), &(PTMP_tmp115)));
    
    {
        PRT_VALUE** P_LVALUE_228 = &(p_this->varValues[17]);
        PrtFreeValue(*P_LVALUE_228);
        *P_LVALUE_228 = PTMP_tmp116;
        PTMP_tmp116 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_229 = &(PTMP_tmp117);
    PrtFreeValue(*P_LVALUE_229);
    *P_LVALUE_229 = PrtCloneValue(p_this->varValues[7]);
    
    PrtSeqInsertEx(*(PrtTupleGetLValue(p_this->varValues[17], 3)), (&P_LIT_INT32_18), PTMP_tmp117, PRT_FALSE);
    *(&(PTMP_tmp117)) = NULL;
    
    PRT_VALUE** P_LVALUE_230 = &(PTMP_tmp118);
    PrtFreeValue(*P_LVALUE_230);
    *P_LVALUE_230 = PrtCloneValue(p_this->varValues[10]);
    
    PrtSeqInsertEx(*(PrtTupleGetLValue(p_this->varValues[17], 3)), (&P_LIT_INT32_12), PTMP_tmp118, PRT_FALSE);
    *(&(PTMP_tmp118)) = NULL;
    
    PRT_VALUE** P_LVALUE_231 = &(PTMP_tmp119);
    PrtFreeValue(*P_LVALUE_231);
    *P_LVALUE_231 = PrtCloneValue((&P_LIT_INT32_18));
    
    PRT_VALUE** P_LVALUE_232 = &(PTMP_tmp120);
    PrtFreeValue(*P_LVALUE_232);
    *P_LVALUE_232 = PrtMkDefaultValue(&P_GEND_TYPE_NT3iiSi);
    
    PRT_VALUE** P_LVALUE_233 = &(PTMP_tmp121);
    PrtFreeValue(*P_LVALUE_233);
    *P_LVALUE_233 = PrtMkDefaultValue(&P_GEND_TYPE_NT3iNT4iiiSiNT4iiiSi);
    
    PRT_VALUE** P_LVALUE_234 = &(PTMP_tmp122);
    PrtFreeValue(*P_LVALUE_234);
    *P_LVALUE_234 = PrtMkDefaultValue(&P_GEND_TYPE_SNT4iiiSi);
    
    PRT_VALUE** P_LVALUE_235 = &(PTMP_tmp123);
    PrtFreeValue(*P_LVALUE_235);
    *P_LVALUE_235 = PrtMkDefaultValue(&P_GEND_TYPE_NT2iSNT3iNT4iiiSiNT4iiiSi);
    
    PRT_VALUE** P_LVALUE_236 = &(PTMP_tmp124);
    PrtFreeValue(*P_LVALUE_236);
    *P_LVALUE_236 = PrtMkDefaultValue(&P_GEND_TYPE_NT2NT2SNT4iiiSiNT4iiiSiB);
    
    PRT_VALUE** P_LVALUE_237 = &(PTMP_tmp125);
    PrtFreeValue(*P_LVALUE_237);
    *P_LVALUE_237 = PrtMkDefaultValue(&P_GEND_TYPE_NT2NT2SNT4iiiSiNT4iiiSiSNT2iB);
    
    PRT_VALUE** P_LVALUE_238 = &(PTMP_tmp126);
    PrtFreeValue(*P_LVALUE_238);
    *P_LVALUE_238 = (PrtMkTuple(&P_GEND_TYPE_NT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB, &(PTMP_tmp119), &(PTMP_tmp120), &(PTMP_tmp121), &(PTMP_tmp122), &(PTMP_tmp123), &(PTMP_tmp124), &(PTMP_tmp125)));
    
    {
        PRT_VALUE** P_LVALUE_239 = &(p_this->varValues[18]);
        PrtFreeValue(*P_LVALUE_239);
        *P_LVALUE_239 = PTMP_tmp126;
        PTMP_tmp126 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_240 = &(PTMP_tmp127);
    PrtFreeValue(*P_LVALUE_240);
    *P_LVALUE_240 = PrtCloneValue((&P_LIT_INT32_21));
    
    PRT_VALUE** P_LVALUE_241 = &(PTMP_tmp128);
    PrtFreeValue(*P_LVALUE_241);
    *P_LVALUE_241 = PrtMkDefaultValue(&P_GEND_TYPE_NT3iiSi);
    
    PRT_VALUE** P_LVALUE_242 = &(PTMP_tmp129);
    PrtFreeValue(*P_LVALUE_242);
    *P_LVALUE_242 = PrtMkDefaultValue(&P_GEND_TYPE_NT3iNT4iiiSiNT4iiiSi);
    
    PRT_VALUE** P_LVALUE_243 = &(PTMP_tmp130);
    PrtFreeValue(*P_LVALUE_243);
    *P_LVALUE_243 = PrtMkDefaultValue(&P_GEND_TYPE_SNT4iiiSi);
    
    PRT_VALUE** P_LVALUE_244 = &(PTMP_tmp131);
    PrtFreeValue(*P_LVALUE_244);
    *P_LVALUE_244 = PrtMkDefaultValue(&P_GEND_TYPE_NT2iSNT3iNT4iiiSiNT4iiiSi);
    
    PRT_VALUE** P_LVALUE_245 = &(PTMP_tmp132);
    PrtFreeValue(*P_LVALUE_245);
    *P_LVALUE_245 = PrtMkDefaultValue(&P_GEND_TYPE_NT2NT2SNT4iiiSiNT4iiiSiB);
    
    PRT_VALUE** P_LVALUE_246 = &(PTMP_tmp133);
    PrtFreeValue(*P_LVALUE_246);
    *P_LVALUE_246 = PrtCloneValue(p_this->varValues[14]);
    
    PRT_VALUE** P_LVALUE_247 = &(PTMP_tmp134);
    PrtFreeValue(*P_LVALUE_247);
    *P_LVALUE_247 = PrtMkDefaultValue(&P_GEND_TYPE_SNT2iB);
    
    PRT_VALUE** P_LVALUE_248 = &(PTMP_tmp135);
    PrtFreeValue(*P_LVALUE_248);
    *P_LVALUE_248 = (PrtMkTuple(&P_GEND_TYPE_NT2NT2SNT4iiiSiNT4iiiSiSNT2iB, &(PTMP_tmp133), &(PTMP_tmp134)));
    
    PRT_VALUE** P_LVALUE_249 = &(PTMP_tmp136);
    PrtFreeValue(*P_LVALUE_249);
    *P_LVALUE_249 = (PrtMkTuple(&P_GEND_TYPE_NT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB, &(PTMP_tmp127), &(PTMP_tmp128), &(PTMP_tmp129), &(PTMP_tmp130), &(PTMP_tmp131), &(PTMP_tmp132), &(PTMP_tmp135)));
    
    {
        PRT_VALUE** P_LVALUE_250 = &(p_this->varValues[19]);
        PrtFreeValue(*P_LVALUE_250);
        *P_LVALUE_250 = PTMP_tmp136;
        PTMP_tmp136 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_251 = &(PTMP_tmp137);
    PrtFreeValue(*P_LVALUE_251);
    *P_LVALUE_251 = PrtCloneValue((&P_LIT_INT32_14));
    
    PRT_VALUE** P_LVALUE_252 = &(PTMP_tmp138);
    PrtFreeValue(*P_LVALUE_252);
    *P_LVALUE_252 = PrtCloneValue(p_this->varValues[17]);
    
    PRT_VALUE** P_LVALUE_253 = &(PTMP_tmp139);
    PrtFreeValue(*P_LVALUE_253);
    *P_LVALUE_253 = (PrtMkTuple(&P_GEND_TYPE_NT2iNT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB, &(PTMP_tmp137), &(PTMP_tmp138)));
    
    PrtSeqInsertEx(*(PrtTupleGetLValue(*(PrtTupleGetLValue(p_this->varValues[19], 6)), 1)), (&P_LIT_INT32_18), PTMP_tmp139, PRT_FALSE);
    *(&(PTMP_tmp139)) = NULL;
    
    PRT_VALUE** P_LVALUE_254 = &(PTMP_tmp140);
    PrtFreeValue(*P_LVALUE_254);
    *P_LVALUE_254 = PrtCloneValue((&P_LIT_INT32_20));
    
    PRT_VALUE** P_LVALUE_255 = &(PTMP_tmp141);
    PrtFreeValue(*P_LVALUE_255);
    *P_LVALUE_255 = PrtCloneValue(p_this->varValues[15]);
    
    PRT_VALUE** P_LVALUE_256 = &(PTMP_tmp142);
    PrtFreeValue(*P_LVALUE_256);
    *P_LVALUE_256 = (PrtMkTuple(&P_GEND_TYPE_NT2iNT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB, &(PTMP_tmp140), &(PTMP_tmp141)));
    
    PrtSeqInsertEx(*(PrtTupleGetLValue(*(PrtTupleGetLValue(p_this->varValues[19], 6)), 1)), (&P_LIT_INT32_12), PTMP_tmp142, PRT_FALSE);
    *(&(PTMP_tmp142)) = NULL;
    
    PRT_VALUE** P_LVALUE_257 = &(p_this->varValues[20]);
    PrtFreeValue(*P_LVALUE_257);
    *P_LVALUE_257 = PrtCloneValue((&P_LIT_INT32_28));
    
    PRT_VALUE** P_LVALUE_258 = &(p_this->varValues[21]);
    PrtFreeValue(*P_LVALUE_258);
    *P_LVALUE_258 = PrtCloneValue((&P_LIT_INT32_28));
    
    PrtGoto(p_this, 1U, 0);
    
p_return_4: ;
    PrtFreeValue(PTMP_tmp0_3); PTMP_tmp0_3 = NULL;
    PrtFreeValue(PTMP_tmp1_3); PTMP_tmp1_3 = NULL;
    PrtFreeValue(PTMP_tmp2_3); PTMP_tmp2_3 = NULL;
    PrtFreeValue(PTMP_tmp3_3); PTMP_tmp3_3 = NULL;
    PrtFreeValue(PTMP_tmp4_3); PTMP_tmp4_3 = NULL;
    PrtFreeValue(PTMP_tmp5_3); PTMP_tmp5_3 = NULL;
    PrtFreeValue(PTMP_tmp6_3); PTMP_tmp6_3 = NULL;
    PrtFreeValue(PTMP_tmp7_2); PTMP_tmp7_2 = NULL;
    PrtFreeValue(PTMP_tmp8_2); PTMP_tmp8_2 = NULL;
    PrtFreeValue(PTMP_tmp9_2); PTMP_tmp9_2 = NULL;
    PrtFreeValue(PTMP_tmp10_2); PTMP_tmp10_2 = NULL;
    PrtFreeValue(PTMP_tmp11_2); PTMP_tmp11_2 = NULL;
    PrtFreeValue(PTMP_tmp12_2); PTMP_tmp12_2 = NULL;
    PrtFreeValue(PTMP_tmp13_2); PTMP_tmp13_2 = NULL;
    PrtFreeValue(PTMP_tmp14_2); PTMP_tmp14_2 = NULL;
    PrtFreeValue(PTMP_tmp15_1); PTMP_tmp15_1 = NULL;
    PrtFreeValue(PTMP_tmp16_1); PTMP_tmp16_1 = NULL;
    PrtFreeValue(PTMP_tmp17_1); PTMP_tmp17_1 = NULL;
    PrtFreeValue(PTMP_tmp18_1); PTMP_tmp18_1 = NULL;
    PrtFreeValue(PTMP_tmp19_1); PTMP_tmp19_1 = NULL;
    PrtFreeValue(PTMP_tmp20_1); PTMP_tmp20_1 = NULL;
    PrtFreeValue(PTMP_tmp21_1); PTMP_tmp21_1 = NULL;
    PrtFreeValue(PTMP_tmp22_1); PTMP_tmp22_1 = NULL;
    PrtFreeValue(PTMP_tmp23_1); PTMP_tmp23_1 = NULL;
    PrtFreeValue(PTMP_tmp24_1); PTMP_tmp24_1 = NULL;
    PrtFreeValue(PTMP_tmp25_1); PTMP_tmp25_1 = NULL;
    PrtFreeValue(PTMP_tmp26_1); PTMP_tmp26_1 = NULL;
    PrtFreeValue(PTMP_tmp27_1); PTMP_tmp27_1 = NULL;
    PrtFreeValue(PTMP_tmp28_1); PTMP_tmp28_1 = NULL;
    PrtFreeValue(PTMP_tmp29_1); PTMP_tmp29_1 = NULL;
    PrtFreeValue(PTMP_tmp30_1); PTMP_tmp30_1 = NULL;
    PrtFreeValue(PTMP_tmp31_1); PTMP_tmp31_1 = NULL;
    PrtFreeValue(PTMP_tmp32_1); PTMP_tmp32_1 = NULL;
    PrtFreeValue(PTMP_tmp33); PTMP_tmp33 = NULL;
    PrtFreeValue(PTMP_tmp34); PTMP_tmp34 = NULL;
    PrtFreeValue(PTMP_tmp35); PTMP_tmp35 = NULL;
    PrtFreeValue(PTMP_tmp36); PTMP_tmp36 = NULL;
    PrtFreeValue(PTMP_tmp37); PTMP_tmp37 = NULL;
    PrtFreeValue(PTMP_tmp38); PTMP_tmp38 = NULL;
    PrtFreeValue(PTMP_tmp39); PTMP_tmp39 = NULL;
    PrtFreeValue(PTMP_tmp40); PTMP_tmp40 = NULL;
    PrtFreeValue(PTMP_tmp41); PTMP_tmp41 = NULL;
    PrtFreeValue(PTMP_tmp42); PTMP_tmp42 = NULL;
    PrtFreeValue(PTMP_tmp43); PTMP_tmp43 = NULL;
    PrtFreeValue(PTMP_tmp44); PTMP_tmp44 = NULL;
    PrtFreeValue(PTMP_tmp45); PTMP_tmp45 = NULL;
    PrtFreeValue(PTMP_tmp46); PTMP_tmp46 = NULL;
    PrtFreeValue(PTMP_tmp47); PTMP_tmp47 = NULL;
    PrtFreeValue(PTMP_tmp48); PTMP_tmp48 = NULL;
    PrtFreeValue(PTMP_tmp49); PTMP_tmp49 = NULL;
    PrtFreeValue(PTMP_tmp50); PTMP_tmp50 = NULL;
    PrtFreeValue(PTMP_tmp51); PTMP_tmp51 = NULL;
    PrtFreeValue(PTMP_tmp52); PTMP_tmp52 = NULL;
    PrtFreeValue(PTMP_tmp53); PTMP_tmp53 = NULL;
    PrtFreeValue(PTMP_tmp54); PTMP_tmp54 = NULL;
    PrtFreeValue(PTMP_tmp55); PTMP_tmp55 = NULL;
    PrtFreeValue(PTMP_tmp56); PTMP_tmp56 = NULL;
    PrtFreeValue(PTMP_tmp57); PTMP_tmp57 = NULL;
    PrtFreeValue(PTMP_tmp58); PTMP_tmp58 = NULL;
    PrtFreeValue(PTMP_tmp59); PTMP_tmp59 = NULL;
    PrtFreeValue(PTMP_tmp60); PTMP_tmp60 = NULL;
    PrtFreeValue(PTMP_tmp61); PTMP_tmp61 = NULL;
    PrtFreeValue(PTMP_tmp62); PTMP_tmp62 = NULL;
    PrtFreeValue(PTMP_tmp63); PTMP_tmp63 = NULL;
    PrtFreeValue(PTMP_tmp64); PTMP_tmp64 = NULL;
    PrtFreeValue(PTMP_tmp65); PTMP_tmp65 = NULL;
    PrtFreeValue(PTMP_tmp66); PTMP_tmp66 = NULL;
    PrtFreeValue(PTMP_tmp67); PTMP_tmp67 = NULL;
    PrtFreeValue(PTMP_tmp68); PTMP_tmp68 = NULL;
    PrtFreeValue(PTMP_tmp69); PTMP_tmp69 = NULL;
    PrtFreeValue(PTMP_tmp70); PTMP_tmp70 = NULL;
    PrtFreeValue(PTMP_tmp71); PTMP_tmp71 = NULL;
    PrtFreeValue(PTMP_tmp72); PTMP_tmp72 = NULL;
    PrtFreeValue(PTMP_tmp73); PTMP_tmp73 = NULL;
    PrtFreeValue(PTMP_tmp74); PTMP_tmp74 = NULL;
    PrtFreeValue(PTMP_tmp75); PTMP_tmp75 = NULL;
    PrtFreeValue(PTMP_tmp76); PTMP_tmp76 = NULL;
    PrtFreeValue(PTMP_tmp77); PTMP_tmp77 = NULL;
    PrtFreeValue(PTMP_tmp78); PTMP_tmp78 = NULL;
    PrtFreeValue(PTMP_tmp79); PTMP_tmp79 = NULL;
    PrtFreeValue(PTMP_tmp80); PTMP_tmp80 = NULL;
    PrtFreeValue(PTMP_tmp81); PTMP_tmp81 = NULL;
    PrtFreeValue(PTMP_tmp82); PTMP_tmp82 = NULL;
    PrtFreeValue(PTMP_tmp83); PTMP_tmp83 = NULL;
    PrtFreeValue(PTMP_tmp84); PTMP_tmp84 = NULL;
    PrtFreeValue(PTMP_tmp85); PTMP_tmp85 = NULL;
    PrtFreeValue(PTMP_tmp86); PTMP_tmp86 = NULL;
    PrtFreeValue(PTMP_tmp87); PTMP_tmp87 = NULL;
    PrtFreeValue(PTMP_tmp88); PTMP_tmp88 = NULL;
    PrtFreeValue(PTMP_tmp89); PTMP_tmp89 = NULL;
    PrtFreeValue(PTMP_tmp90); PTMP_tmp90 = NULL;
    PrtFreeValue(PTMP_tmp91); PTMP_tmp91 = NULL;
    PrtFreeValue(PTMP_tmp92); PTMP_tmp92 = NULL;
    PrtFreeValue(PTMP_tmp93); PTMP_tmp93 = NULL;
    PrtFreeValue(PTMP_tmp94); PTMP_tmp94 = NULL;
    PrtFreeValue(PTMP_tmp95); PTMP_tmp95 = NULL;
    PrtFreeValue(PTMP_tmp96); PTMP_tmp96 = NULL;
    PrtFreeValue(PTMP_tmp97); PTMP_tmp97 = NULL;
    PrtFreeValue(PTMP_tmp98); PTMP_tmp98 = NULL;
    PrtFreeValue(PTMP_tmp99); PTMP_tmp99 = NULL;
    PrtFreeValue(PTMP_tmp100); PTMP_tmp100 = NULL;
    PrtFreeValue(PTMP_tmp101); PTMP_tmp101 = NULL;
    PrtFreeValue(PTMP_tmp102); PTMP_tmp102 = NULL;
    PrtFreeValue(PTMP_tmp103); PTMP_tmp103 = NULL;
    PrtFreeValue(PTMP_tmp104); PTMP_tmp104 = NULL;
    PrtFreeValue(PTMP_tmp105); PTMP_tmp105 = NULL;
    PrtFreeValue(PTMP_tmp106); PTMP_tmp106 = NULL;
    PrtFreeValue(PTMP_tmp107); PTMP_tmp107 = NULL;
    PrtFreeValue(PTMP_tmp108); PTMP_tmp108 = NULL;
    PrtFreeValue(PTMP_tmp109); PTMP_tmp109 = NULL;
    PrtFreeValue(PTMP_tmp110); PTMP_tmp110 = NULL;
    PrtFreeValue(PTMP_tmp111); PTMP_tmp111 = NULL;
    PrtFreeValue(PTMP_tmp112); PTMP_tmp112 = NULL;
    PrtFreeValue(PTMP_tmp113); PTMP_tmp113 = NULL;
    PrtFreeValue(PTMP_tmp114); PTMP_tmp114 = NULL;
    PrtFreeValue(PTMP_tmp115); PTMP_tmp115 = NULL;
    PrtFreeValue(PTMP_tmp116); PTMP_tmp116 = NULL;
    PrtFreeValue(PTMP_tmp117); PTMP_tmp117 = NULL;
    PrtFreeValue(PTMP_tmp118); PTMP_tmp118 = NULL;
    PrtFreeValue(PTMP_tmp119); PTMP_tmp119 = NULL;
    PrtFreeValue(PTMP_tmp120); PTMP_tmp120 = NULL;
    PrtFreeValue(PTMP_tmp121); PTMP_tmp121 = NULL;
    PrtFreeValue(PTMP_tmp122); PTMP_tmp122 = NULL;
    PrtFreeValue(PTMP_tmp123); PTMP_tmp123 = NULL;
    PrtFreeValue(PTMP_tmp124); PTMP_tmp124 = NULL;
    PrtFreeValue(PTMP_tmp125); PTMP_tmp125 = NULL;
    PrtFreeValue(PTMP_tmp126); PTMP_tmp126 = NULL;
    PrtFreeValue(PTMP_tmp127); PTMP_tmp127 = NULL;
    PrtFreeValue(PTMP_tmp128); PTMP_tmp128 = NULL;
    PrtFreeValue(PTMP_tmp129); PTMP_tmp129 = NULL;
    PrtFreeValue(PTMP_tmp130); PTMP_tmp130 = NULL;
    PrtFreeValue(PTMP_tmp131); PTMP_tmp131 = NULL;
    PrtFreeValue(PTMP_tmp132); PTMP_tmp132 = NULL;
    PrtFreeValue(PTMP_tmp133); PTMP_tmp133 = NULL;
    PrtFreeValue(PTMP_tmp134); PTMP_tmp134 = NULL;
    PrtFreeValue(PTMP_tmp135); PTMP_tmp135 = NULL;
    PrtFreeValue(PTMP_tmp136); PTMP_tmp136 = NULL;
    PrtFreeValue(PTMP_tmp137); PTMP_tmp137 = NULL;
    PrtFreeValue(PTMP_tmp138); PTMP_tmp138 = NULL;
    PrtFreeValue(PTMP_tmp139); PTMP_tmp139 = NULL;
    PrtFreeValue(PTMP_tmp140); PTMP_tmp140 = NULL;
    PrtFreeValue(PTMP_tmp141); PTMP_tmp141 = NULL;
    PrtFreeValue(PTMP_tmp142); PTMP_tmp142 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon =
{
    NULL,
    &P_Anon_IMPL,
    NULL
};


PRT_VALUE* P_Anon_IMPL_1(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_wReq = argRefs[0];
    PRT_VALUE* P_VAR_ret_2 = PrtMkDefaultValue(&P_GEND_TYPE_SB);
    PRT_VALUE* PTMP_tmp0_4 = NULL;
    PRT_VALUE* PTMP_tmp1_4 = NULL;
    PRT_VALUE* PTMP_tmp2_4 = NULL;
    PRT_VALUE* PTMP_tmp3_4 = NULL;
    PRT_VALUE* PTMP_tmp4_4 = NULL;
    PRT_VALUE* PTMP_tmp5_4 = NULL;
    PRT_VALUE* PTMP_tmp6_4 = NULL;
    PRT_VALUE* PTMP_tmp7_3 = NULL;
    PRT_VALUE* PTMP_tmp8_3 = NULL;
    PRT_VALUE* PTMP_tmp9_3 = NULL;
    PRT_VALUE* PTMP_tmp10_3 = NULL;
    PRT_VALUE* PTMP_tmp11_3 = NULL;
    PRT_VALUE* PTMP_tmp12_3 = NULL;
    PRT_VALUE* PTMP_tmp13_3 = NULL;
    PRT_VALUE* PTMP_tmp14_3 = NULL;
    PRT_VALUE* PTMP_tmp15_2 = NULL;
    PRT_VALUE* PTMP_tmp16_2 = NULL;
    PRT_VALUE* PTMP_tmp17_2 = NULL;
    PRT_VALUE* PTMP_tmp18_2 = NULL;
    PRT_VALUE* PTMP_tmp19_2 = NULL;
    PRT_VALUE* PTMP_tmp20_2 = NULL;
    PRT_VALUE* PTMP_tmp21_2 = NULL;
    PRT_VALUE* PTMP_tmp22_2 = NULL;
    PRT_VALUE* PTMP_tmp23_2 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_29 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE P_LIT_INT32_30 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE P_LIT_INT32_31 = { PRT_VALUE_KIND_INT, { .nt = 2 } };
    PRT_VALUE P_LIT_INT32_32 = { PRT_VALUE_KIND_INT, { .nt = 3 } };
    PRT_VALUE P_LIT_INT32_33 = { PRT_VALUE_KIND_INT, { .nt = 4 } };
    PRT_VALUE P_LIT_INT32_34 = { PRT_VALUE_KIND_INT, { .nt = 5 } };
    PRT_VALUE P_LIT_INT32_35 = { PRT_VALUE_KIND_INT, { .nt = 6 } };
    PRT_VALUE P_LIT_INT32_36 = { PRT_VALUE_KIND_INT, { .nt = 7 } };
    PRT_VALUE P_LIT_INT32_37 = { PRT_VALUE_KIND_INT, { .nt = 8 } };
    PRT_VALUE P_LIT_INT32_38 = { PRT_VALUE_KIND_INT, { .nt = 9 } };
    PRT_VALUE P_LIT_INT32_39 = { PRT_VALUE_KIND_INT, { .nt = 10 } };
    PRT_VALUE P_LIT_INT32_40 = { PRT_VALUE_KIND_INT, { .nt = 11 } };
    PRT_VALUE P_LIT_INT32_41 = { PRT_VALUE_KIND_INT, { .nt = 12 } };
    PRT_VALUE P_LIT_INT32_42 = { PRT_VALUE_KIND_INT, { .nt = 13 } };
    PRT_VALUE P_LIT_INT32_43 = { PRT_VALUE_KIND_INT, { .nt = 14 } };
    PRT_VALUE P_LIT_INT32_44 = { PRT_VALUE_KIND_INT, { .nt = 15 } };
    PRT_VALUE P_LIT_INT32_45 = { PRT_VALUE_KIND_INT, { .nt = 16 } };
    PRT_VALUE P_LIT_INT32_46 = { PRT_VALUE_KIND_INT, { .nt = 17 } };
    PRT_VALUE P_LIT_INT32_47 = { PRT_VALUE_KIND_INT, { .nt = 18 } };
    PRT_VALUE P_LIT_INT32_48 = { PRT_VALUE_KIND_INT, { .nt = 19 } };
    PRT_VALUE P_LIT_INT32_49 = { PRT_VALUE_KIND_INT, { .nt = 20 } };
    PRT_VALUE** P_LVALUE_259 = &(PTMP_tmp0_4);
    PrtFreeValue(*P_LVALUE_259);
    *P_LVALUE_259 = PrtCloneValue(p_this->varValues[0]);
    
    PrtSeqInsertEx(P_VAR_ret_2, (&P_LIT_INT32_29), PTMP_tmp0_4, PRT_FALSE);
    *(&(PTMP_tmp0_4)) = NULL;
    
    PRT_VALUE** P_LVALUE_260 = &(PTMP_tmp1_4);
    PrtFreeValue(*P_LVALUE_260);
    *P_LVALUE_260 = PrtCloneValue(p_this->varValues[1]);
    
    PrtSeqInsertEx(P_VAR_ret_2, (&P_LIT_INT32_30), PTMP_tmp1_4, PRT_FALSE);
    *(&(PTMP_tmp1_4)) = NULL;
    
    PRT_VALUE** P_LVALUE_261 = &(PTMP_tmp2_4);
    PrtFreeValue(*P_LVALUE_261);
    *P_LVALUE_261 = PrtCloneValue(p_this->varValues[2]);
    
    PrtSeqInsertEx(P_VAR_ret_2, (&P_LIT_INT32_31), PTMP_tmp2_4, PRT_FALSE);
    *(&(PTMP_tmp2_4)) = NULL;
    
    PRT_VALUE** P_LVALUE_262 = &(PTMP_tmp3_4);
    PrtFreeValue(*P_LVALUE_262);
    *P_LVALUE_262 = PrtCloneValue(p_this->varValues[3]);
    
    PrtSeqInsertEx(P_VAR_ret_2, (&P_LIT_INT32_32), PTMP_tmp3_4, PRT_FALSE);
    *(&(PTMP_tmp3_4)) = NULL;
    
    PRT_VALUE** P_LVALUE_263 = &(PTMP_tmp4_4);
    PrtFreeValue(*P_LVALUE_263);
    *P_LVALUE_263 = PrtCloneValue(p_this->varValues[5]);
    
    PrtSeqInsertEx(P_VAR_ret_2, (&P_LIT_INT32_33), PTMP_tmp4_4, PRT_FALSE);
    *(&(PTMP_tmp4_4)) = NULL;
    
    PRT_VALUE** P_LVALUE_264 = &(PTMP_tmp5_4);
    PrtFreeValue(*P_LVALUE_264);
    *P_LVALUE_264 = PrtCloneValue(p_this->varValues[6]);
    
    PrtSeqInsertEx(P_VAR_ret_2, (&P_LIT_INT32_34), PTMP_tmp5_4, PRT_FALSE);
    *(&(PTMP_tmp5_4)) = NULL;
    
    PRT_VALUE** P_LVALUE_265 = &(PTMP_tmp6_4);
    PrtFreeValue(*P_LVALUE_265);
    *P_LVALUE_265 = PrtCloneValue(p_this->varValues[7]);
    
    PrtSeqInsertEx(P_VAR_ret_2, (&P_LIT_INT32_35), PTMP_tmp6_4, PRT_FALSE);
    *(&(PTMP_tmp6_4)) = NULL;
    
    PRT_VALUE** P_LVALUE_266 = &(PTMP_tmp7_3);
    PrtFreeValue(*P_LVALUE_266);
    *P_LVALUE_266 = PrtCloneValue(p_this->varValues[8]);
    
    PrtSeqInsertEx(P_VAR_ret_2, (&P_LIT_INT32_36), PTMP_tmp7_3, PRT_FALSE);
    *(&(PTMP_tmp7_3)) = NULL;
    
    PRT_VALUE** P_LVALUE_267 = &(PTMP_tmp8_3);
    PrtFreeValue(*P_LVALUE_267);
    *P_LVALUE_267 = PrtCloneValue(p_this->varValues[9]);
    
    PrtSeqInsertEx(P_VAR_ret_2, (&P_LIT_INT32_37), PTMP_tmp8_3, PRT_FALSE);
    *(&(PTMP_tmp8_3)) = NULL;
    
    PRT_VALUE** P_LVALUE_268 = &(PTMP_tmp9_3);
    PrtFreeValue(*P_LVALUE_268);
    *P_LVALUE_268 = PrtCloneValue(p_this->varValues[10]);
    
    PrtSeqInsertEx(P_VAR_ret_2, (&P_LIT_INT32_38), PTMP_tmp9_3, PRT_FALSE);
    *(&(PTMP_tmp9_3)) = NULL;
    
    PRT_VALUE** P_LVALUE_269 = &(PTMP_tmp10_3);
    PrtFreeValue(*P_LVALUE_269);
    *P_LVALUE_269 = PrtCloneValue(p_this->varValues[11]);
    
    PrtSeqInsertEx(P_VAR_ret_2, (&P_LIT_INT32_39), PTMP_tmp10_3, PRT_FALSE);
    *(&(PTMP_tmp10_3)) = NULL;
    
    PRT_VALUE** P_LVALUE_270 = &(PTMP_tmp11_3);
    PrtFreeValue(*P_LVALUE_270);
    *P_LVALUE_270 = PrtCloneValue(p_this->varValues[12]);
    
    PrtSeqInsertEx(P_VAR_ret_2, (&P_LIT_INT32_40), PTMP_tmp11_3, PRT_FALSE);
    *(&(PTMP_tmp11_3)) = NULL;
    
    PRT_VALUE** P_LVALUE_271 = &(PTMP_tmp12_3);
    PrtFreeValue(*P_LVALUE_271);
    *P_LVALUE_271 = PrtCloneValue(p_this->varValues[13]);
    
    PrtSeqInsertEx(P_VAR_ret_2, (&P_LIT_INT32_41), PTMP_tmp12_3, PRT_FALSE);
    *(&(PTMP_tmp12_3)) = NULL;
    
    PRT_VALUE** P_LVALUE_272 = &(PTMP_tmp13_3);
    PrtFreeValue(*P_LVALUE_272);
    *P_LVALUE_272 = PrtCloneValue(p_this->varValues[14]);
    
    PrtSeqInsertEx(P_VAR_ret_2, (&P_LIT_INT32_42), PTMP_tmp13_3, PRT_FALSE);
    *(&(PTMP_tmp13_3)) = NULL;
    
    PRT_VALUE** P_LVALUE_273 = &(PTMP_tmp14_3);
    PrtFreeValue(*P_LVALUE_273);
    *P_LVALUE_273 = PrtCloneValue(p_this->varValues[15]);
    
    PrtSeqInsertEx(P_VAR_ret_2, (&P_LIT_INT32_43), PTMP_tmp14_3, PRT_FALSE);
    *(&(PTMP_tmp14_3)) = NULL;
    
    PRT_VALUE** P_LVALUE_274 = &(PTMP_tmp15_2);
    PrtFreeValue(*P_LVALUE_274);
    *P_LVALUE_274 = PrtCloneValue(p_this->varValues[16]);
    
    PrtSeqInsertEx(P_VAR_ret_2, (&P_LIT_INT32_44), PTMP_tmp15_2, PRT_FALSE);
    *(&(PTMP_tmp15_2)) = NULL;
    
    PRT_VALUE** P_LVALUE_275 = &(PTMP_tmp16_2);
    PrtFreeValue(*P_LVALUE_275);
    *P_LVALUE_275 = PrtCloneValue(p_this->varValues[17]);
    
    PrtSeqInsertEx(P_VAR_ret_2, (&P_LIT_INT32_45), PTMP_tmp16_2, PRT_FALSE);
    *(&(PTMP_tmp16_2)) = NULL;
    
    PRT_VALUE** P_LVALUE_276 = &(PTMP_tmp17_2);
    PrtFreeValue(*P_LVALUE_276);
    *P_LVALUE_276 = PrtCloneValue(p_this->varValues[18]);
    
    PrtSeqInsertEx(P_VAR_ret_2, (&P_LIT_INT32_46), PTMP_tmp17_2, PRT_FALSE);
    *(&(PTMP_tmp17_2)) = NULL;
    
    PRT_VALUE** P_LVALUE_277 = &(PTMP_tmp18_2);
    PrtFreeValue(*P_LVALUE_277);
    *P_LVALUE_277 = PrtCloneValue(p_this->varValues[19]);
    
    PrtSeqInsertEx(P_VAR_ret_2, (&P_LIT_INT32_47), PTMP_tmp18_2, PRT_FALSE);
    *(&(PTMP_tmp18_2)) = NULL;
    
    PRT_VALUE** P_LVALUE_278 = &(PTMP_tmp19_2);
    PrtFreeValue(*P_LVALUE_278);
    *P_LVALUE_278 = PrtCloneValue(p_this->varValues[20]);
    
    PrtSeqInsertEx(P_VAR_ret_2, (&P_LIT_INT32_48), PTMP_tmp19_2, PRT_FALSE);
    *(&(PTMP_tmp19_2)) = NULL;
    
    PRT_VALUE** P_LVALUE_279 = &(PTMP_tmp20_2);
    PrtFreeValue(*P_LVALUE_279);
    *P_LVALUE_279 = PrtCloneValue(p_this->varValues[21]);
    
    PrtSeqInsertEx(P_VAR_ret_2, (&P_LIT_INT32_49), PTMP_tmp20_2, PRT_FALSE);
    *(&(PTMP_tmp20_2)) = NULL;
    
    PRT_VALUE** P_LVALUE_280 = &(PTMP_tmp21_2);
    PrtFreeValue(*P_LVALUE_280);
    *P_LVALUE_280 = PrtCloneValue(*P_VAR_wReq);
    
    PRT_VALUE** P_LVALUE_281 = &(PTMP_tmp22_2);
    PrtFreeValue(*P_LVALUE_281);
    *P_LVALUE_281 = PrtCloneValue((&P_EVENT_eGetDefaultValueResp.value));
    
    PRT_VALUE** P_LVALUE_282 = &(PTMP_tmp23_2);
    PrtFreeValue(*P_LVALUE_282);
    *P_LVALUE_282 = PrtCloneValue(P_VAR_ret_2);
    
    PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp21_2), PTMP_tmp22_2, 1, &(PTMP_tmp23_2));
    *(&(PTMP_tmp22_2)) = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_5;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_5;
    }
    
p_return_5: ;
    PrtFreeValue(P_VAR_ret_2); P_VAR_ret_2 = NULL;
    PrtFreeValue(PTMP_tmp0_4); PTMP_tmp0_4 = NULL;
    PrtFreeValue(PTMP_tmp1_4); PTMP_tmp1_4 = NULL;
    PrtFreeValue(PTMP_tmp2_4); PTMP_tmp2_4 = NULL;
    PrtFreeValue(PTMP_tmp3_4); PTMP_tmp3_4 = NULL;
    PrtFreeValue(PTMP_tmp4_4); PTMP_tmp4_4 = NULL;
    PrtFreeValue(PTMP_tmp5_4); PTMP_tmp5_4 = NULL;
    PrtFreeValue(PTMP_tmp6_4); PTMP_tmp6_4 = NULL;
    PrtFreeValue(PTMP_tmp7_3); PTMP_tmp7_3 = NULL;
    PrtFreeValue(PTMP_tmp8_3); PTMP_tmp8_3 = NULL;
    PrtFreeValue(PTMP_tmp9_3); PTMP_tmp9_3 = NULL;
    PrtFreeValue(PTMP_tmp10_3); PTMP_tmp10_3 = NULL;
    PrtFreeValue(PTMP_tmp11_3); PTMP_tmp11_3 = NULL;
    PrtFreeValue(PTMP_tmp12_3); PTMP_tmp12_3 = NULL;
    PrtFreeValue(PTMP_tmp13_3); PTMP_tmp13_3 = NULL;
    PrtFreeValue(PTMP_tmp14_3); PTMP_tmp14_3 = NULL;
    PrtFreeValue(PTMP_tmp15_2); PTMP_tmp15_2 = NULL;
    PrtFreeValue(PTMP_tmp16_2); PTMP_tmp16_2 = NULL;
    PrtFreeValue(PTMP_tmp17_2); PTMP_tmp17_2 = NULL;
    PrtFreeValue(PTMP_tmp18_2); PTMP_tmp18_2 = NULL;
    PrtFreeValue(PTMP_tmp19_2); PTMP_tmp19_2 = NULL;
    PrtFreeValue(PTMP_tmp20_2); PTMP_tmp20_2 = NULL;
    PrtFreeValue(PTMP_tmp21_2); PTMP_tmp21_2 = NULL;
    PrtFreeValue(PTMP_tmp22_2); PTMP_tmp22_2 = NULL;
    PrtFreeValue(PTMP_tmp23_2); PTMP_tmp23_2 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_1 =
{
    NULL,
    &P_Anon_IMPL_1,
    &P_GEND_TYPE_m
};


PRT_FUNDECL* P_VarInitMachine_METHODS[] = { &P_FUNCTION_Anon, &P_FUNCTION_Anon_1 };

PRT_EVENTDECL* P_VarInitMachine_RECV_INNER_1[] = { &P_EVENT_eChanConnected, &P_EVENT_eChanDead, &P_EVENT_eChanGotoConfig, &P_EVENT_eChanGotoConnected, &P_EVENT_eChanStarted, &P_EVENT_eComposetFix, &P_EVENT_eComposetHdr, &P_EVENT_eComposetMsg, &P_EVENT_eComposetPara, &P_EVENT_eComposetPlist, &P_EVENT_eComposetVar, &P_EVENT_eConfReq, &P_EVENT_eConfResp, &P_EVENT_eConnReq, &P_EVENT_eConnResp, &P_EVENT_eGetDefaultValueResp, &P_EVENT_eL2CmdReq, &P_EVENT_eParsetFix, &P_EVENT_eParsetHdr, &P_EVENT_eParsetMsg, &P_EVENT_eParsetPara, &P_EVENT_eParsetPlist, &P_EVENT_eParsetVar, &P_EVENT_eSpecGetDefaultValueReq, &P_EVENT_eStartTimer, &P_EVENT_eTimeOut, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_VarInitMachine_RECV_1 =
{
    27U,
    P_VarInitMachine_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_VarInitMachine_SEND_INNER[] = { &P_EVENT_eChanConnected, &P_EVENT_eChanDead, &P_EVENT_eChanGotoConfig, &P_EVENT_eChanGotoConnected, &P_EVENT_eChanStarted, &P_EVENT_eComposetFix, &P_EVENT_eComposetHdr, &P_EVENT_eComposetMsg, &P_EVENT_eComposetPara, &P_EVENT_eComposetPlist, &P_EVENT_eComposetVar, &P_EVENT_eConfReq, &P_EVENT_eConfResp, &P_EVENT_eConnReq, &P_EVENT_eConnResp, &P_EVENT_eGetDefaultValueResp, &P_EVENT_eL2CmdReq, &P_EVENT_eParsetFix, &P_EVENT_eParsetHdr, &P_EVENT_eParsetMsg, &P_EVENT_eParsetPara, &P_EVENT_eParsetPlist, &P_EVENT_eParsetVar, &P_EVENT_eSpecGetDefaultValueReq, &P_EVENT_eStartTimer, &P_EVENT_eTimeOut, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_VarInitMachine_SEND =
{
    27U,
    P_VarInitMachine_SEND_INNER,
    NULL
};

PRT_MACHINEDECL P_MACHINE_VarInitMachine = 
{
    0U,
    "VarInitMachine",
    &P_EVENTSET_VarInitMachine_RECV_1,
    &P_EVENTSET_VarInitMachine_SEND,
    NULL,
    22U,
    2U,
    2U,
    4294967295U,
    0U,
    P_VarInitMachine_VARS,
    P_VarInitMachine_STATES,
    P_VarInitMachine_METHODS
};

PRT_VARDECL P_ConnMachine_VARS[] = {
    { "server", &P_GEND_TYPE_R_1 },
    { "Connection", &P_GEND_TYPE_SSNT3iNT4iiiSiNT4iiiSi },
    { "ChanMachineList", &P_GEND_TYPE_MKiVR }
};

PRT_EVENTDECL* P_Init_DEFERS_INNER_1[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DEFERS_1 =
{
    0U,
    P_Init_DEFERS_INNER_1,
    NULL
};

PRT_EVENTDECL* P_Init_TRANS_INNER_1[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_TRANS_1 =
{
    0U,
    P_Init_TRANS_INNER_1,
    NULL
};

PRT_EVENTDECL* P_Init_DOS_INNER_1[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DOS_1 =
{
    0U,
    P_Init_DOS_INNER_1,
    NULL
};

#define P_STATE_ConnMachine_Init \
{ \
    "ConnMachine.Init", \
    0U, \
    0U, \
    &P_EVENTSET_Init_DEFERS_1, \
    &P_EVENTSET_Init_TRANS_1, \
    &P_EVENTSET_Init_DOS_1, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon_2, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_WaitForReqs_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_WaitForReqs_DEFERS =
{
    0U,
    P_WaitForReqs_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_WaitForReqs_TRANS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_WaitForReqs_TRANS =
{
    0U,
    P_WaitForReqs_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_WaitForReqs_DOS_INNER[] = { &P_EVENT_eConfReq, &P_EVENT_eConnReq, &P_EVENT_eL2CmdReq };
PRT_EVENTSETDECL P_EVENTSET_WaitForReqs_DOS =
{
    3U,
    P_WaitForReqs_DOS_INNER,
    NULL
};

PRT_DODECL P_DOS_1[] =
{
    { 1, &P_EVENT_eL2CmdReq, &P_FUNCTION_Anon_3 },
    { 1, &P_EVENT_eConnReq, &P_FUNCTION_Anon_4 },
    { 1, &P_EVENT_eConfReq, &P_FUNCTION_Anon_5 }
};

#define P_STATE_ConnMachine_WaitForReqs \
{ \
    "ConnMachine.WaitForReqs", \
    0U, \
    3U, \
    &P_EVENTSET_WaitForReqs_DEFERS, \
    &P_EVENTSET_WaitForReqs_TRANS, \
    &P_EVENTSET_WaitForReqs_DOS, \
    NULL, \
    P_DOS_1, \
    &_P_NO_OP, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_ConnMachine_STATES[] = { P_STATE_ConnMachine_Init, P_STATE_ConnMachine_WaitForReqs };

PRT_VALUE* P_Anon_IMPL_2(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_input = argRefs[0];
    PRT_VALUE* PTMP_tmp0_5 = NULL;
    PRT_VALUE* PTMP_tmp1_5 = NULL;
    PRT_VALUE* PTMP_tmp2_5 = NULL;
    PRT_VALUE* PTMP_tmp3_5 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_283 = &(PTMP_tmp0_5);
    PrtFreeValue(*P_LVALUE_283);
    *P_LVALUE_283 = PrtTupleGet(*P_VAR_input, 0);
    
    PRT_VALUE** P_LVALUE_284 = &(PTMP_tmp1_5);
    PrtFreeValue(*P_LVALUE_284);
    *P_LVALUE_284 = PrtCloneValue(PTMP_tmp0_5);
    
    {
        PRT_VALUE** P_LVALUE_285 = &(p_this->varValues[0]);
        PrtFreeValue(*P_LVALUE_285);
        *P_LVALUE_285 = PTMP_tmp1_5;
        PTMP_tmp1_5 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_286 = &(PTMP_tmp2_5);
    PrtFreeValue(*P_LVALUE_286);
    *P_LVALUE_286 = PrtTupleGet(*P_VAR_input, 1);
    
    PRT_VALUE** P_LVALUE_287 = &(PTMP_tmp3_5);
    PrtFreeValue(*P_LVALUE_287);
    *P_LVALUE_287 = PrtCloneValue(PTMP_tmp2_5);
    
    {
        PRT_VALUE** P_LVALUE_288 = &(p_this->varValues[1]);
        PrtFreeValue(*P_LVALUE_288);
        *P_LVALUE_288 = PTMP_tmp3_5;
        PTMP_tmp3_5 = NULL;
    }
    
    PrtGoto(p_this, 1U, 0);
    
p_return_6: ;
    PrtFreeValue(PTMP_tmp0_5); PTMP_tmp0_5 = NULL;
    PrtFreeValue(PTMP_tmp1_5); PTMP_tmp1_5 = NULL;
    PrtFreeValue(PTMP_tmp2_5); PTMP_tmp2_5 = NULL;
    PrtFreeValue(PTMP_tmp3_5); PTMP_tmp3_5 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_2 =
{
    NULL,
    &P_Anon_IMPL_2,
    &P_GEND_TYPE_NT2RSSNT3iNT4iiiSiNT4iiiSi
};


PRT_VALUE* P_Anon_IMPL_3(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_wReq_1 = argRefs[0];
    PRT_VALUE* P_VAR_MsgBody = PrtMkDefaultValue(&P_GEND_TYPE_NT2NT2SNT4iiiSiNT4iiiSiSNT2iB);
    PRT_VALUE* P_VAR_MsgHdr = PrtMkDefaultValue(&P_GEND_TYPE_NT2SNT4iiiSiNT4iiiSi);
    PRT_VALUE* P_VAR_MsgCases = PrtMkDefaultValue(&P_GEND_TYPE_SNT2iB);
    PRT_VALUE* P_VAR_MsgType = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* P_VAR_counter_3 = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* PTMP_tmp0_6 = NULL;
    PRT_VALUE* PTMP_tmp1_6 = NULL;
    PRT_VALUE* PTMP_tmp2_6 = NULL;
    PRT_VALUE* PTMP_tmp3_6 = NULL;
    PRT_VALUE* PTMP_tmp4_5 = NULL;
    PRT_VALUE* PTMP_tmp5_5 = NULL;
    PRT_VALUE* PTMP_tmp6_5 = NULL;
    PRT_VALUE* PTMP_tmp7_4 = NULL;
    PRT_VALUE* PTMP_tmp8_4 = NULL;
    PRT_VALUE* PTMP_tmp9_4 = NULL;
    PRT_VALUE* PTMP_tmp10_4 = NULL;
    PRT_VALUE* PTMP_tmp11_4 = NULL;
    PRT_VALUE* PTMP_tmp12_4 = NULL;
    PRT_VALUE* PTMP_tmp13_4 = NULL;
    PRT_VALUE* PTMP_tmp14_4 = NULL;
    PRT_VALUE* PTMP_tmp15_3 = NULL;
    PRT_VALUE* PTMP_tmp16_3 = NULL;
    PRT_VALUE* PTMP_tmp17_3 = NULL;
    PRT_VALUE* PTMP_tmp18_3 = NULL;
    PRT_VALUE* PTMP_tmp19_3 = NULL;
    PRT_VALUE* PTMP_tmp20_3 = NULL;
    PRT_VALUE* PTMP_tmp21_3 = NULL;
    PRT_VALUE* PTMP_tmp22_3 = NULL;
    PRT_VALUE* PTMP_tmp23_3 = NULL;
    PRT_VALUE* PTMP_tmp24_2 = NULL;
    PRT_VALUE* PTMP_tmp25_2 = NULL;
    PRT_VALUE* PTMP_tmp26_2 = NULL;
    PRT_VALUE* PTMP_tmp27_2 = NULL;
    PRT_VALUE* PTMP_tmp28_2 = NULL;
    PRT_VALUE* PTMP_tmp29_2 = NULL;
    PRT_VALUE* PTMP_tmp30_2 = NULL;
    PRT_VALUE* PTMP_tmp31_2 = NULL;
    PRT_VALUE* PTMP_tmp32_2 = NULL;
    PRT_VALUE* PTMP_tmp33_1 = NULL;
    PRT_VALUE* PTMP_tmp34_1 = NULL;
    PRT_VALUE* PTMP_tmp35_1 = NULL;
    PRT_VALUE* PTMP_tmp36_1 = NULL;
    PRT_VALUE* PTMP_tmp37_1 = NULL;
    PRT_VALUE* PTMP_tmp38_1 = NULL;
    PRT_VALUE* PTMP_tmp39_1 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_50 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE P_LIT_INT32_51 = { PRT_VALUE_KIND_INT, { .nt = 2 } };
    PRT_VALUE P_LIT_INT32_52 = { PRT_VALUE_KIND_INT, { .nt = 4 } };
    PRT_VALUE P_LIT_INT32_53 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE P_LIT_BOOLEAN_4 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_TRUE } };
    PRT_VALUE** P_LVALUE_289 = &(PTMP_tmp0_6);
    PrtFreeValue(*P_LVALUE_289);
    *P_LVALUE_289 = PrtTupleGet(*P_VAR_wReq_1, 1);
    
    
    PRT_VALUE** P_LVALUE_290 = &(PTMP_tmp1_6);
    PrtFreeValue(*P_LVALUE_290);
    *P_LVALUE_290 = PrtTupleGet(*P_VAR_wReq_1, 1);
    
    PRT_VALUE** P_LVALUE_291 = &(PTMP_tmp2_6);
    PrtFreeValue(*P_LVALUE_291);
    *P_LVALUE_291 = PrtTupleGet(PTMP_tmp1_6, 6);
    
    PRT_VALUE** P_LVALUE_292 = &(PTMP_tmp3_6);
    PrtFreeValue(*P_LVALUE_292);
    *P_LVALUE_292 = PrtCloneValue(PTMP_tmp2_6);
    
    {
        PRT_VALUE** P_LVALUE_293 = &(P_VAR_MsgBody);
        PrtFreeValue(*P_LVALUE_293);
        *P_LVALUE_293 = PTMP_tmp3_6;
        PTMP_tmp3_6 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_294 = &(PTMP_tmp4_5);
    PrtFreeValue(*P_LVALUE_294);
    *P_LVALUE_294 = PrtTupleGet(P_VAR_MsgBody, 0);
    
    PRT_VALUE** P_LVALUE_295 = &(PTMP_tmp5_5);
    PrtFreeValue(*P_LVALUE_295);
    *P_LVALUE_295 = PrtCloneValue(PTMP_tmp4_5);
    
    {
        PRT_VALUE** P_LVALUE_296 = &(P_VAR_MsgHdr);
        PrtFreeValue(*P_LVALUE_296);
        *P_LVALUE_296 = PTMP_tmp5_5;
        PTMP_tmp5_5 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_297 = &(PTMP_tmp6_5);
    PrtFreeValue(*P_LVALUE_297);
    *P_LVALUE_297 = PrtTupleGet(P_VAR_MsgBody, 1);
    
    PRT_VALUE** P_LVALUE_298 = &(PTMP_tmp7_4);
    PrtFreeValue(*P_LVALUE_298);
    *P_LVALUE_298 = PrtCloneValue(PTMP_tmp6_5);
    
    {
        PRT_VALUE** P_LVALUE_299 = &(P_VAR_MsgCases);
        PrtFreeValue(*P_LVALUE_299);
        *P_LVALUE_299 = PTMP_tmp7_4;
        PTMP_tmp7_4 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_300 = &(PTMP_tmp8_4);
    PrtFreeValue(*P_LVALUE_300);
    *P_LVALUE_300 = PrtTupleGet(P_VAR_MsgHdr, 0);
    
    PRT_VALUE** P_LVALUE_301 = &(PTMP_tmp9_4);
    PrtFreeValue(*P_LVALUE_301);
    *P_LVALUE_301 = PrtSeqGet(PTMP_tmp8_4, (&P_LIT_INT32_50));
    
    PRT_VALUE** P_LVALUE_302 = &(PTMP_tmp10_4);
    PrtFreeValue(*P_LVALUE_302);
    *P_LVALUE_302 = PrtTupleGet(PTMP_tmp9_4, 3);
    
    PRT_VALUE** P_LVALUE_303 = &(PTMP_tmp11_4);
    PrtFreeValue(*P_LVALUE_303);
    *P_LVALUE_303 = ((_P_GEN_funargs[0] = &(PTMP_tmp10_4)), (_P_GEN_funval = P_readBuffer_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp10_4), PTMP_tmp10_4 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_7;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_7;
    }
    
    {
        PRT_VALUE** P_LVALUE_304 = &(P_VAR_MsgType);
        PrtFreeValue(*P_LVALUE_304);
        *P_LVALUE_304 = PTMP_tmp11_4;
        PTMP_tmp11_4 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_305 = &(P_VAR_counter_3);
    PrtFreeValue(*P_LVALUE_305);
    *P_LVALUE_305 = PrtCloneValue((&P_LIT_INT32_50));
    
    while (PrtPrimGetBool((&P_LIT_BOOLEAN_4)))
    {
        PRT_VALUE** P_LVALUE_306 = &(PTMP_tmp12_4);
        PrtFreeValue(*P_LVALUE_306);
        *P_LVALUE_306 = PrtMkIntValue(PrtSeqSizeOf(P_VAR_MsgCases));
        
        PRT_VALUE** P_LVALUE_307 = &(PTMP_tmp13_4);
        PrtFreeValue(*P_LVALUE_307);
        *P_LVALUE_307 = PrtMkBoolValue(PrtPrimGetInt(P_VAR_counter_3) < PrtPrimGetInt(PTMP_tmp12_4));
        
        PRT_VALUE** P_LVALUE_308 = &(PTMP_tmp14_4);
        PrtFreeValue(*P_LVALUE_308);
        *P_LVALUE_308 = PrtCloneValue(PTMP_tmp13_4);
        
        if (PrtPrimGetBool(PTMP_tmp14_4))
        {
        }
        
        else
        {
            break;
            
        }
        
        
        PRT_VALUE** P_LVALUE_309 = &(PTMP_tmp15_3);
        PrtFreeValue(*P_LVALUE_309);
        *P_LVALUE_309 = PrtSeqGet(P_VAR_MsgCases, P_VAR_counter_3);
        
        PRT_VALUE** P_LVALUE_310 = &(PTMP_tmp16_3);
        PrtFreeValue(*P_LVALUE_310);
        *P_LVALUE_310 = PrtTupleGet(PTMP_tmp15_3, 0);
        
        PRT_VALUE** P_LVALUE_311 = &(PTMP_tmp17_3);
        PrtFreeValue(*P_LVALUE_311);
        *P_LVALUE_311 = PrtMkBoolValue(PrtIsEqualValue(P_VAR_MsgType, PTMP_tmp16_3));
        
        PRT_VALUE** P_LVALUE_312 = &(PTMP_tmp19_3);
        PrtFreeValue(*P_LVALUE_312);
        *P_LVALUE_312 = PrtCloneValue(PTMP_tmp17_3);
        
        if (PrtPrimGetBool(PTMP_tmp19_3))
        {
            PRT_VALUE** P_LVALUE_313 = &(PTMP_tmp18_3);
            PrtFreeValue(*P_LVALUE_313);
            *P_LVALUE_313 = PrtMkBoolValue(PrtIsEqualValue(P_VAR_MsgType, (&P_LIT_INT32_51)));
            
            PRT_VALUE** P_LVALUE_314 = &(PTMP_tmp19_3);
            PrtFreeValue(*P_LVALUE_314);
            *P_LVALUE_314 = PrtCloneValue(PTMP_tmp18_3);
            
        }
        
        
        if (PrtPrimGetBool(PTMP_tmp19_3))
        {
            PRT_VALUE** P_LVALUE_315 = &(PTMP_tmp20_3);
            PrtFreeValue(*P_LVALUE_315);
            *P_LVALUE_315 = PrtCloneValue((p_this->id));
            
            PRT_VALUE** P_LVALUE_316 = &(PTMP_tmp21_3);
            PrtFreeValue(*P_LVALUE_316);
            *P_LVALUE_316 = PrtCloneValue((&P_EVENT_eConnReq.value));
            
            PRT_VALUE** P_LVALUE_317 = &(PTMP_tmp22_3);
            PrtFreeValue(*P_LVALUE_317);
            *P_LVALUE_317 = PrtTupleGet(*P_VAR_wReq_1, 0);
            
            PRT_VALUE** P_LVALUE_318 = &(PTMP_tmp23_3);
            PrtFreeValue(*P_LVALUE_318);
            *P_LVALUE_318 = PrtSeqGet(P_VAR_MsgCases, P_VAR_counter_3);
            
            PRT_VALUE** P_LVALUE_319 = &(PTMP_tmp24_2);
            PrtFreeValue(*P_LVALUE_319);
            *P_LVALUE_319 = PrtTupleGet(PTMP_tmp23_3, 1);
            
            PRT_VALUE** P_LVALUE_320 = &(PTMP_tmp25_2);
            PrtFreeValue(*P_LVALUE_320);
            *P_LVALUE_320 = PrtCloneValue(PrtCastValue(PrtCloneValue(PTMP_tmp24_2), &P_GEND_TYPE_NT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB));
            
            PRT_VALUE** P_LVALUE_321 = &(PTMP_tmp26_2);
            PrtFreeValue(*P_LVALUE_321);
            *P_LVALUE_321 = (PrtMkTuple(&P_GEND_TYPE_NT2mNT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB, &(PTMP_tmp22_3), &(PTMP_tmp25_2)));
            
            PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp20_3), PTMP_tmp21_3, 1, &(PTMP_tmp26_2));
            *(&(PTMP_tmp21_3)) = NULL;
            if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                goto p_return_7;
            }
            if (p_this->isHalted == PRT_TRUE) {
                PrtFreeValue(_P_GEN_retval);
                _P_GEN_retval = NULL;
                goto p_return_7;
            }
            
        }
        
        else
        {
            PRT_VALUE** P_LVALUE_322 = &(PTMP_tmp27_2);
            PrtFreeValue(*P_LVALUE_322);
            *P_LVALUE_322 = PrtSeqGet(P_VAR_MsgCases, P_VAR_counter_3);
            
            PRT_VALUE** P_LVALUE_323 = &(PTMP_tmp28_2);
            PrtFreeValue(*P_LVALUE_323);
            *P_LVALUE_323 = PrtTupleGet(PTMP_tmp27_2, 0);
            
            PRT_VALUE** P_LVALUE_324 = &(PTMP_tmp29_2);
            PrtFreeValue(*P_LVALUE_324);
            *P_LVALUE_324 = PrtMkBoolValue(PrtIsEqualValue(P_VAR_MsgType, PTMP_tmp28_2));
            
            PRT_VALUE** P_LVALUE_325 = &(PTMP_tmp31_2);
            PrtFreeValue(*P_LVALUE_325);
            *P_LVALUE_325 = PrtCloneValue(PTMP_tmp29_2);
            
            if (PrtPrimGetBool(PTMP_tmp31_2))
            {
                PRT_VALUE** P_LVALUE_326 = &(PTMP_tmp30_2);
                PrtFreeValue(*P_LVALUE_326);
                *P_LVALUE_326 = PrtMkBoolValue(PrtIsEqualValue(P_VAR_MsgType, (&P_LIT_INT32_52)));
                
                PRT_VALUE** P_LVALUE_327 = &(PTMP_tmp31_2);
                PrtFreeValue(*P_LVALUE_327);
                *P_LVALUE_327 = PrtCloneValue(PTMP_tmp30_2);
                
            }
            
            
            if (PrtPrimGetBool(PTMP_tmp31_2))
            {
                PRT_VALUE** P_LVALUE_328 = &(PTMP_tmp32_2);
                PrtFreeValue(*P_LVALUE_328);
                *P_LVALUE_328 = PrtCloneValue((p_this->id));
                
                PRT_VALUE** P_LVALUE_329 = &(PTMP_tmp33_1);
                PrtFreeValue(*P_LVALUE_329);
                *P_LVALUE_329 = PrtCloneValue((&P_EVENT_eConfReq.value));
                
                PRT_VALUE** P_LVALUE_330 = &(PTMP_tmp34_1);
                PrtFreeValue(*P_LVALUE_330);
                *P_LVALUE_330 = PrtTupleGet(*P_VAR_wReq_1, 0);
                
                PRT_VALUE** P_LVALUE_331 = &(PTMP_tmp35_1);
                PrtFreeValue(*P_LVALUE_331);
                *P_LVALUE_331 = PrtSeqGet(P_VAR_MsgCases, P_VAR_counter_3);
                
                PRT_VALUE** P_LVALUE_332 = &(PTMP_tmp36_1);
                PrtFreeValue(*P_LVALUE_332);
                *P_LVALUE_332 = PrtTupleGet(PTMP_tmp35_1, 1);
                
                PRT_VALUE** P_LVALUE_333 = &(PTMP_tmp37_1);
                PrtFreeValue(*P_LVALUE_333);
                *P_LVALUE_333 = PrtCloneValue(PrtCastValue(PrtCloneValue(PTMP_tmp36_1), &P_GEND_TYPE_NT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB));
                
                PRT_VALUE** P_LVALUE_334 = &(PTMP_tmp38_1);
                PrtFreeValue(*P_LVALUE_334);
                *P_LVALUE_334 = (PrtMkTuple(&P_GEND_TYPE_NT2mNT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB, &(PTMP_tmp34_1), &(PTMP_tmp37_1)));
                
                PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp32_2), PTMP_tmp33_1, 1, &(PTMP_tmp38_1));
                *(&(PTMP_tmp33_1)) = NULL;
                if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                    goto p_return_7;
                }
                if (p_this->isHalted == PRT_TRUE) {
                    PrtFreeValue(_P_GEN_retval);
                    _P_GEN_retval = NULL;
                    goto p_return_7;
                }
                
            }
            
            else
            {
            }
            
            
        }
        
        
        PRT_VALUE** P_LVALUE_335 = &(PTMP_tmp39_1);
        PrtFreeValue(*P_LVALUE_335);
        *P_LVALUE_335 = PrtMkIntValue(PrtPrimGetInt(P_VAR_counter_3) + PrtPrimGetInt((&P_LIT_INT32_53)));
        
        {
            PRT_VALUE** P_LVALUE_336 = &(P_VAR_counter_3);
            PrtFreeValue(*P_LVALUE_336);
            *P_LVALUE_336 = PTMP_tmp39_1;
            PTMP_tmp39_1 = NULL;
        }
        
    }
    
    
p_return_7: ;
    PrtFreeValue(P_VAR_MsgBody); P_VAR_MsgBody = NULL;
    PrtFreeValue(P_VAR_MsgHdr); P_VAR_MsgHdr = NULL;
    PrtFreeValue(P_VAR_MsgCases); P_VAR_MsgCases = NULL;
    PrtFreeValue(P_VAR_MsgType); P_VAR_MsgType = NULL;
    PrtFreeValue(P_VAR_counter_3); P_VAR_counter_3 = NULL;
    PrtFreeValue(PTMP_tmp0_6); PTMP_tmp0_6 = NULL;
    PrtFreeValue(PTMP_tmp1_6); PTMP_tmp1_6 = NULL;
    PrtFreeValue(PTMP_tmp2_6); PTMP_tmp2_6 = NULL;
    PrtFreeValue(PTMP_tmp3_6); PTMP_tmp3_6 = NULL;
    PrtFreeValue(PTMP_tmp4_5); PTMP_tmp4_5 = NULL;
    PrtFreeValue(PTMP_tmp5_5); PTMP_tmp5_5 = NULL;
    PrtFreeValue(PTMP_tmp6_5); PTMP_tmp6_5 = NULL;
    PrtFreeValue(PTMP_tmp7_4); PTMP_tmp7_4 = NULL;
    PrtFreeValue(PTMP_tmp8_4); PTMP_tmp8_4 = NULL;
    PrtFreeValue(PTMP_tmp9_4); PTMP_tmp9_4 = NULL;
    PrtFreeValue(PTMP_tmp10_4); PTMP_tmp10_4 = NULL;
    PrtFreeValue(PTMP_tmp11_4); PTMP_tmp11_4 = NULL;
    PrtFreeValue(PTMP_tmp12_4); PTMP_tmp12_4 = NULL;
    PrtFreeValue(PTMP_tmp13_4); PTMP_tmp13_4 = NULL;
    PrtFreeValue(PTMP_tmp14_4); PTMP_tmp14_4 = NULL;
    PrtFreeValue(PTMP_tmp15_3); PTMP_tmp15_3 = NULL;
    PrtFreeValue(PTMP_tmp16_3); PTMP_tmp16_3 = NULL;
    PrtFreeValue(PTMP_tmp17_3); PTMP_tmp17_3 = NULL;
    PrtFreeValue(PTMP_tmp18_3); PTMP_tmp18_3 = NULL;
    PrtFreeValue(PTMP_tmp19_3); PTMP_tmp19_3 = NULL;
    PrtFreeValue(PTMP_tmp20_3); PTMP_tmp20_3 = NULL;
    PrtFreeValue(PTMP_tmp21_3); PTMP_tmp21_3 = NULL;
    PrtFreeValue(PTMP_tmp22_3); PTMP_tmp22_3 = NULL;
    PrtFreeValue(PTMP_tmp23_3); PTMP_tmp23_3 = NULL;
    PrtFreeValue(PTMP_tmp24_2); PTMP_tmp24_2 = NULL;
    PrtFreeValue(PTMP_tmp25_2); PTMP_tmp25_2 = NULL;
    PrtFreeValue(PTMP_tmp26_2); PTMP_tmp26_2 = NULL;
    PrtFreeValue(PTMP_tmp27_2); PTMP_tmp27_2 = NULL;
    PrtFreeValue(PTMP_tmp28_2); PTMP_tmp28_2 = NULL;
    PrtFreeValue(PTMP_tmp29_2); PTMP_tmp29_2 = NULL;
    PrtFreeValue(PTMP_tmp30_2); PTMP_tmp30_2 = NULL;
    PrtFreeValue(PTMP_tmp31_2); PTMP_tmp31_2 = NULL;
    PrtFreeValue(PTMP_tmp32_2); PTMP_tmp32_2 = NULL;
    PrtFreeValue(PTMP_tmp33_1); PTMP_tmp33_1 = NULL;
    PrtFreeValue(PTMP_tmp34_1); PTMP_tmp34_1 = NULL;
    PrtFreeValue(PTMP_tmp35_1); PTMP_tmp35_1 = NULL;
    PrtFreeValue(PTMP_tmp36_1); PTMP_tmp36_1 = NULL;
    PrtFreeValue(PTMP_tmp37_1); PTMP_tmp37_1 = NULL;
    PrtFreeValue(PTMP_tmp38_1); PTMP_tmp38_1 = NULL;
    PrtFreeValue(PTMP_tmp39_1); PTMP_tmp39_1 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_3 =
{
    NULL,
    &P_Anon_IMPL_3,
    &P_GEND_TYPE_NT2mNT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB
};


PRT_VALUE* P_Anon_IMPL_4(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_wReq_2 = argRefs[0];
    PRT_VALUE* P_VAR_counter2 = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* P_VAR_flag1 = PrtMkDefaultValue(&P_GEND_TYPE_b);
    PRT_VALUE* P_VAR_flag2 = PrtMkDefaultValue(&P_GEND_TYPE_b);
    PRT_VALUE* P_VAR_index = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* P_VAR_counter3 = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* P_VAR_tmp1 = PrtMkDefaultValue(&P_GEND_TYPE_NT3iNT4iiiSiNT4iiiSi);
    PRT_VALUE* P_VAR_tmp2 = PrtMkDefaultValue(&P_GEND_TYPE_NT3iNT4iiiSiNT4iiiSi);
    PRT_VALUE* P_VAR_tmp3 = PrtMkDefaultValue(&P_GEND_TYPE_SNT3iNT4iiiSiNT4iiiSi);
    PRT_VALUE* PTMP_tmp0_7 = NULL;
    PRT_VALUE* PTMP_tmp1_7 = NULL;
    PRT_VALUE* PTMP_tmp2_7 = NULL;
    PRT_VALUE* PTMP_tmp3_7 = NULL;
    PRT_VALUE* PTMP_tmp4_6 = NULL;
    PRT_VALUE* PTMP_tmp5_6 = NULL;
    PRT_VALUE* PTMP_tmp6_6 = NULL;
    PRT_VALUE* PTMP_tmp7_5 = NULL;
    PRT_VALUE* PTMP_tmp8_5 = NULL;
    PRT_VALUE* PTMP_tmp9_5 = NULL;
    PRT_VALUE* PTMP_tmp10_5 = NULL;
    PRT_VALUE* PTMP_tmp11_5 = NULL;
    PRT_VALUE* PTMP_tmp12_5 = NULL;
    PRT_VALUE* PTMP_tmp13_5 = NULL;
    PRT_VALUE* PTMP_tmp14_5 = NULL;
    PRT_VALUE* PTMP_tmp15_4 = NULL;
    PRT_VALUE* PTMP_tmp16_4 = NULL;
    PRT_VALUE* PTMP_tmp17_4 = NULL;
    PRT_VALUE* PTMP_tmp18_4 = NULL;
    PRT_VALUE* PTMP_tmp19_4 = NULL;
    PRT_VALUE* PTMP_tmp20_4 = NULL;
    PRT_VALUE* PTMP_tmp21_4 = NULL;
    PRT_VALUE* PTMP_tmp22_4 = NULL;
    PRT_VALUE* PTMP_tmp23_4 = NULL;
    PRT_VALUE* PTMP_tmp24_3 = NULL;
    PRT_VALUE* PTMP_tmp25_3 = NULL;
    PRT_VALUE* PTMP_tmp26_3 = NULL;
    PRT_VALUE* PTMP_tmp27_3 = NULL;
    PRT_VALUE* PTMP_tmp28_3 = NULL;
    PRT_VALUE* PTMP_tmp29_3 = NULL;
    PRT_VALUE* PTMP_tmp30_3 = NULL;
    PRT_VALUE* PTMP_tmp31_3 = NULL;
    PRT_VALUE* PTMP_tmp32_3 = NULL;
    PRT_VALUE* PTMP_tmp33_2 = NULL;
    PRT_VALUE* PTMP_tmp34_2 = NULL;
    PRT_VALUE* PTMP_tmp35_2 = NULL;
    PRT_VALUE* PTMP_tmp36_2 = NULL;
    PRT_VALUE* PTMP_tmp37_2 = NULL;
    PRT_VALUE* PTMP_tmp38_2 = NULL;
    PRT_VALUE* PTMP_tmp39_2 = NULL;
    PRT_VALUE* PTMP_tmp40_1 = NULL;
    PRT_VALUE* PTMP_tmp41_1 = NULL;
    PRT_VALUE* PTMP_tmp42_1 = NULL;
    PRT_VALUE* PTMP_tmp43_1 = NULL;
    PRT_VALUE* PTMP_tmp44_1 = NULL;
    PRT_VALUE* PTMP_tmp45_1 = NULL;
    PRT_VALUE* PTMP_tmp46_1 = NULL;
    PRT_VALUE* PTMP_tmp47_1 = NULL;
    PRT_VALUE* PTMP_tmp48_1 = NULL;
    PRT_VALUE* PTMP_tmp49_1 = NULL;
    PRT_VALUE* PTMP_tmp50_1 = NULL;
    PRT_VALUE* PTMP_tmp51_1 = NULL;
    PRT_VALUE* PTMP_tmp52_1 = NULL;
    PRT_VALUE* PTMP_tmp53_1 = NULL;
    PRT_VALUE* PTMP_tmp54_1 = NULL;
    PRT_VALUE* PTMP_tmp55_1 = NULL;
    PRT_VALUE* PTMP_tmp56_1 = NULL;
    PRT_VALUE* PTMP_tmp57_1 = NULL;
    PRT_VALUE* PTMP_tmp58_1 = NULL;
    PRT_VALUE* PTMP_tmp59_1 = NULL;
    PRT_VALUE* PTMP_tmp60_1 = NULL;
    PRT_VALUE* PTMP_tmp61_1 = NULL;
    PRT_VALUE* PTMP_tmp62_1 = NULL;
    PRT_VALUE* PTMP_tmp63_1 = NULL;
    PRT_VALUE* PTMP_tmp64_1 = NULL;
    PRT_VALUE* PTMP_tmp65_1 = NULL;
    PRT_VALUE* PTMP_tmp66_1 = NULL;
    PRT_VALUE* PTMP_tmp67_1 = NULL;
    PRT_VALUE* PTMP_tmp68_1 = NULL;
    PRT_VALUE* PTMP_tmp69_1 = NULL;
    PRT_VALUE* PTMP_tmp70_1 = NULL;
    PRT_VALUE* PTMP_tmp71_1 = NULL;
    PRT_VALUE* PTMP_tmp72_1 = NULL;
    PRT_VALUE* PTMP_tmp73_1 = NULL;
    PRT_VALUE* PTMP_tmp74_1 = NULL;
    PRT_VALUE* PTMP_tmp75_1 = NULL;
    PRT_VALUE* PTMP_tmp76_1 = NULL;
    PRT_VALUE* PTMP_tmp77_1 = NULL;
    PRT_VALUE* PTMP_tmp78_1 = NULL;
    PRT_VALUE* PTMP_tmp79_1 = NULL;
    PRT_VALUE* PTMP_tmp80_1 = NULL;
    PRT_VALUE* PTMP_tmp81_1 = NULL;
    PRT_VALUE* PTMP_tmp82_1 = NULL;
    PRT_VALUE* PTMP_tmp83_1 = NULL;
    PRT_VALUE* PTMP_tmp84_1 = NULL;
    PRT_VALUE* PTMP_tmp85_1 = NULL;
    PRT_VALUE* PTMP_tmp86_1 = NULL;
    PRT_VALUE* PTMP_tmp87_1 = NULL;
    PRT_VALUE* PTMP_tmp88_1 = NULL;
    PRT_VALUE* PTMP_tmp89_1 = NULL;
    PRT_VALUE* PTMP_tmp90_1 = NULL;
    PRT_VALUE* PTMP_tmp91_1 = NULL;
    PRT_VALUE* PTMP_tmp92_1 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_54 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE P_LIT_INT32_55 = { PRT_VALUE_KIND_INT, { .nt = 2 } };
    PRT_VALUE P_LIT_INT32_56 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE P_LIT_BOOLEAN_5 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_FALSE } };
    PRT_VALUE P_LIT_BOOLEAN_6 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_TRUE } };
    PRT_VALUE** P_LVALUE_337 = &(PTMP_tmp0_7);
    PrtFreeValue(*P_LVALUE_337);
    *P_LVALUE_337 = PrtTupleGet(*P_VAR_wReq_2, 1);
    
    
    PRT_VALUE** P_LVALUE_338 = &(P_VAR_counter2);
    PrtFreeValue(*P_LVALUE_338);
    *P_LVALUE_338 = PrtCloneValue((&P_LIT_INT32_54));
    
    PRT_VALUE** P_LVALUE_339 = &(P_VAR_flag1);
    PrtFreeValue(*P_LVALUE_339);
    *P_LVALUE_339 = PrtCloneValue((&P_LIT_BOOLEAN_5));
    
    PRT_VALUE** P_LVALUE_340 = &(P_VAR_flag2);
    PrtFreeValue(*P_LVALUE_340);
    *P_LVALUE_340 = PrtCloneValue((&P_LIT_BOOLEAN_5));
    
    while (PrtPrimGetBool((&P_LIT_BOOLEAN_6)))
    {
        PRT_VALUE** P_LVALUE_341 = &(PTMP_tmp1_7);
        PrtFreeValue(*P_LVALUE_341);
        *P_LVALUE_341 = PrtMkIntValue(PrtSeqSizeOf(p_this->varValues[1]));
        
        PRT_VALUE** P_LVALUE_342 = &(PTMP_tmp2_7);
        PrtFreeValue(*P_LVALUE_342);
        *P_LVALUE_342 = PrtMkBoolValue(PrtPrimGetInt(P_VAR_counter2) < PrtPrimGetInt(PTMP_tmp1_7));
        
        PRT_VALUE** P_LVALUE_343 = &(PTMP_tmp3_7);
        PrtFreeValue(*P_LVALUE_343);
        *P_LVALUE_343 = PrtCloneValue(PTMP_tmp2_7);
        
        if (PrtPrimGetBool(PTMP_tmp3_7))
        {
        }
        
        else
        {
            break;
            
        }
        
        
        PRT_VALUE** P_LVALUE_344 = &(P_VAR_counter3);
        PrtFreeValue(*P_LVALUE_344);
        *P_LVALUE_344 = PrtCloneValue((&P_LIT_INT32_54));
        
        while (PrtPrimGetBool((&P_LIT_BOOLEAN_6)))
        {
            PRT_VALUE** P_LVALUE_345 = &(PTMP_tmp4_6);
            PrtFreeValue(*P_LVALUE_345);
            *P_LVALUE_345 = PrtSeqGet(p_this->varValues[1], P_VAR_counter2);
            
            PRT_VALUE** P_LVALUE_346 = &(PTMP_tmp5_6);
            PrtFreeValue(*P_LVALUE_346);
            *P_LVALUE_346 = PrtMkIntValue(PrtSeqSizeOf(PTMP_tmp4_6));
            
            PRT_VALUE** P_LVALUE_347 = &(PTMP_tmp6_6);
            PrtFreeValue(*P_LVALUE_347);
            *P_LVALUE_347 = PrtMkBoolValue(PrtPrimGetInt(P_VAR_counter3) < PrtPrimGetInt(PTMP_tmp5_6));
            
            PRT_VALUE** P_LVALUE_348 = &(PTMP_tmp7_5);
            PrtFreeValue(*P_LVALUE_348);
            *P_LVALUE_348 = PrtCloneValue(PTMP_tmp6_6);
            
            if (PrtPrimGetBool(PTMP_tmp7_5))
            {
            }
            
            else
            {
                break;
                
            }
            
            
            PRT_VALUE** P_LVALUE_349 = &(PTMP_tmp8_5);
            PrtFreeValue(*P_LVALUE_349);
            *P_LVALUE_349 = PrtSeqGet(p_this->varValues[1], P_VAR_counter2);
            
            PRT_VALUE** P_LVALUE_350 = &(PTMP_tmp9_5);
            PrtFreeValue(*P_LVALUE_350);
            *P_LVALUE_350 = PrtSeqGet(PTMP_tmp8_5, P_VAR_counter3);
            
            PRT_VALUE** P_LVALUE_351 = &(PTMP_tmp10_5);
            PrtFreeValue(*P_LVALUE_351);
            *P_LVALUE_351 = PrtTupleGet(PTMP_tmp9_5, 0);
            
            PRT_VALUE** P_LVALUE_352 = &(PTMP_tmp11_5);
            PrtFreeValue(*P_LVALUE_352);
            *P_LVALUE_352 = PrtMkBoolValue(PrtIsEqualValue(PTMP_tmp10_5, (&P_LIT_INT32_55)));
            
            PRT_VALUE** P_LVALUE_353 = &(PTMP_tmp18_4);
            PrtFreeValue(*P_LVALUE_353);
            *P_LVALUE_353 = PrtCloneValue(PTMP_tmp11_5);
            
            if (PrtPrimGetBool(PTMP_tmp18_4))
            {
                PRT_VALUE** P_LVALUE_354 = &(PTMP_tmp12_5);
                PrtFreeValue(*P_LVALUE_354);
                *P_LVALUE_354 = PrtSeqGet(p_this->varValues[1], P_VAR_counter2);
                
                PRT_VALUE** P_LVALUE_355 = &(PTMP_tmp13_5);
                PrtFreeValue(*P_LVALUE_355);
                *P_LVALUE_355 = PrtSeqGet(PTMP_tmp12_5, P_VAR_counter3);
                
                PRT_VALUE** P_LVALUE_356 = &(PTMP_tmp14_5);
                PrtFreeValue(*P_LVALUE_356);
                *P_LVALUE_356 = PrtTupleGet(PTMP_tmp13_5, 1);
                
                PRT_VALUE** P_LVALUE_357 = &(PTMP_tmp15_4);
                PrtFreeValue(*P_LVALUE_357);
                *P_LVALUE_357 = PrtTupleGet(PTMP_tmp14_5, 3);
                
                PRT_VALUE** P_LVALUE_358 = &(PTMP_tmp16_4);
                PrtFreeValue(*P_LVALUE_358);
                *P_LVALUE_358 = ((_P_GEN_funargs[0] = &(PTMP_tmp15_4)), (_P_GEN_funval = P_readBuffer_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp15_4), PTMP_tmp15_4 = NULL), (_P_GEN_funval));
                if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                    goto p_return_8;
                }
                if (p_this->isHalted == PRT_TRUE) {
                    PrtFreeValue(_P_GEN_retval);
                    _P_GEN_retval = NULL;
                    goto p_return_8;
                }
                
                PRT_VALUE** P_LVALUE_359 = &(PTMP_tmp17_4);
                PrtFreeValue(*P_LVALUE_359);
                *P_LVALUE_359 = PrtMkBoolValue(PrtIsEqualValue(PTMP_tmp16_4, (&P_LIT_INT32_55)));
                
                PRT_VALUE** P_LVALUE_360 = &(PTMP_tmp18_4);
                PrtFreeValue(*P_LVALUE_360);
                *P_LVALUE_360 = PrtCloneValue(PTMP_tmp17_4);
                
            }
            
            
            PRT_VALUE** P_LVALUE_361 = &(PTMP_tmp30_3);
            PrtFreeValue(*P_LVALUE_361);
            *P_LVALUE_361 = PrtCloneValue(PTMP_tmp18_4);
            
            if (PrtPrimGetBool(PTMP_tmp30_3))
            {
                PRT_VALUE** P_LVALUE_362 = &(PTMP_tmp19_4);
                PrtFreeValue(*P_LVALUE_362);
                *P_LVALUE_362 = PrtTupleGet(*P_VAR_wReq_2, 1);
                
                PRT_VALUE** P_LVALUE_363 = &(PTMP_tmp20_4);
                PrtFreeValue(*P_LVALUE_363);
                *P_LVALUE_363 = PrtTupleGet(PTMP_tmp19_4, 3);
                
                PRT_VALUE** P_LVALUE_364 = &(PTMP_tmp21_4);
                PrtFreeValue(*P_LVALUE_364);
                *P_LVALUE_364 = PrtSeqGet(PTMP_tmp20_4, (&P_LIT_INT32_54));
                
                PRT_VALUE** P_LVALUE_365 = &(PTMP_tmp22_4);
                PrtFreeValue(*P_LVALUE_365);
                *P_LVALUE_365 = PrtTupleGet(PTMP_tmp21_4, 3);
                
                PRT_VALUE** P_LVALUE_366 = &(PTMP_tmp23_4);
                PrtFreeValue(*P_LVALUE_366);
                *P_LVALUE_366 = ((_P_GEN_funargs[0] = &(PTMP_tmp22_4)), (_P_GEN_funval = P_readBuffer_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp22_4), PTMP_tmp22_4 = NULL), (_P_GEN_funval));
                if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                    goto p_return_8;
                }
                if (p_this->isHalted == PRT_TRUE) {
                    PrtFreeValue(_P_GEN_retval);
                    _P_GEN_retval = NULL;
                    goto p_return_8;
                }
                
                PRT_VALUE** P_LVALUE_367 = &(PTMP_tmp24_3);
                PrtFreeValue(*P_LVALUE_367);
                *P_LVALUE_367 = PrtSeqGet(p_this->varValues[1], P_VAR_counter2);
                
                PRT_VALUE** P_LVALUE_368 = &(PTMP_tmp25_3);
                PrtFreeValue(*P_LVALUE_368);
                *P_LVALUE_368 = PrtSeqGet(PTMP_tmp24_3, P_VAR_counter3);
                
                PRT_VALUE** P_LVALUE_369 = &(PTMP_tmp26_3);
                PrtFreeValue(*P_LVALUE_369);
                *P_LVALUE_369 = PrtTupleGet(PTMP_tmp25_3, 2);
                
                PRT_VALUE** P_LVALUE_370 = &(PTMP_tmp27_3);
                PrtFreeValue(*P_LVALUE_370);
                *P_LVALUE_370 = PrtTupleGet(PTMP_tmp26_3, 3);
                
                PRT_VALUE** P_LVALUE_371 = &(PTMP_tmp28_3);
                PrtFreeValue(*P_LVALUE_371);
                *P_LVALUE_371 = ((_P_GEN_funargs[0] = &(PTMP_tmp27_3)), (_P_GEN_funval = P_readBuffer_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp27_3), PTMP_tmp27_3 = NULL), (_P_GEN_funval));
                if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                    goto p_return_8;
                }
                if (p_this->isHalted == PRT_TRUE) {
                    PrtFreeValue(_P_GEN_retval);
                    _P_GEN_retval = NULL;
                    goto p_return_8;
                }
                
                PRT_VALUE** P_LVALUE_372 = &(PTMP_tmp29_3);
                PrtFreeValue(*P_LVALUE_372);
                *P_LVALUE_372 = PrtMkBoolValue(PrtIsEqualValue(PTMP_tmp23_4, PTMP_tmp28_3));
                
                PRT_VALUE** P_LVALUE_373 = &(PTMP_tmp30_3);
                PrtFreeValue(*P_LVALUE_373);
                *P_LVALUE_373 = PrtCloneValue(PTMP_tmp29_3);
                
            }
            
            
            if (PrtPrimGetBool(PTMP_tmp30_3))
            {
                PRT_VALUE** P_LVALUE_374 = &(P_VAR_flag1);
                PrtFreeValue(*P_LVALUE_374);
                *P_LVALUE_374 = PrtCloneValue((&P_LIT_BOOLEAN_6));
                
            }
            
            else
            {
            }
            
            
            PRT_VALUE** P_LVALUE_375 = &(PTMP_tmp31_3);
            PrtFreeValue(*P_LVALUE_375);
            *P_LVALUE_375 = PrtSeqGet(p_this->varValues[1], P_VAR_counter2);
            
            PRT_VALUE** P_LVALUE_376 = &(PTMP_tmp32_3);
            PrtFreeValue(*P_LVALUE_376);
            *P_LVALUE_376 = PrtSeqGet(PTMP_tmp31_3, P_VAR_counter3);
            
            PRT_VALUE** P_LVALUE_377 = &(PTMP_tmp33_2);
            PrtFreeValue(*P_LVALUE_377);
            *P_LVALUE_377 = PrtTupleGet(PTMP_tmp32_3, 0);
            
            PRT_VALUE** P_LVALUE_378 = &(PTMP_tmp34_2);
            PrtFreeValue(*P_LVALUE_378);
            *P_LVALUE_378 = PrtMkBoolValue(PrtIsEqualValue(PTMP_tmp33_2, (&P_LIT_INT32_56)));
            
            PRT_VALUE** P_LVALUE_379 = &(PTMP_tmp41_1);
            PrtFreeValue(*P_LVALUE_379);
            *P_LVALUE_379 = PrtCloneValue(PTMP_tmp34_2);
            
            if (PrtPrimGetBool(PTMP_tmp41_1))
            {
                PRT_VALUE** P_LVALUE_380 = &(PTMP_tmp35_2);
                PrtFreeValue(*P_LVALUE_380);
                *P_LVALUE_380 = PrtSeqGet(p_this->varValues[1], P_VAR_counter2);
                
                PRT_VALUE** P_LVALUE_381 = &(PTMP_tmp36_2);
                PrtFreeValue(*P_LVALUE_381);
                *P_LVALUE_381 = PrtSeqGet(PTMP_tmp35_2, P_VAR_counter3);
                
                PRT_VALUE** P_LVALUE_382 = &(PTMP_tmp37_2);
                PrtFreeValue(*P_LVALUE_382);
                *P_LVALUE_382 = PrtTupleGet(PTMP_tmp36_2, 1);
                
                PRT_VALUE** P_LVALUE_383 = &(PTMP_tmp38_2);
                PrtFreeValue(*P_LVALUE_383);
                *P_LVALUE_383 = PrtTupleGet(PTMP_tmp37_2, 3);
                
                PRT_VALUE** P_LVALUE_384 = &(PTMP_tmp39_2);
                PrtFreeValue(*P_LVALUE_384);
                *P_LVALUE_384 = ((_P_GEN_funargs[0] = &(PTMP_tmp38_2)), (_P_GEN_funval = P_readBuffer_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp38_2), PTMP_tmp38_2 = NULL), (_P_GEN_funval));
                if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                    goto p_return_8;
                }
                if (p_this->isHalted == PRT_TRUE) {
                    PrtFreeValue(_P_GEN_retval);
                    _P_GEN_retval = NULL;
                    goto p_return_8;
                }
                
                PRT_VALUE** P_LVALUE_385 = &(PTMP_tmp40_1);
                PrtFreeValue(*P_LVALUE_385);
                *P_LVALUE_385 = PrtMkBoolValue(PrtIsEqualValue(PTMP_tmp39_2, (&P_LIT_INT32_56)));
                
                PRT_VALUE** P_LVALUE_386 = &(PTMP_tmp41_1);
                PrtFreeValue(*P_LVALUE_386);
                *P_LVALUE_386 = PrtCloneValue(PTMP_tmp40_1);
                
            }
            
            
            PRT_VALUE** P_LVALUE_387 = &(PTMP_tmp53_1);
            PrtFreeValue(*P_LVALUE_387);
            *P_LVALUE_387 = PrtCloneValue(PTMP_tmp41_1);
            
            if (PrtPrimGetBool(PTMP_tmp53_1))
            {
                PRT_VALUE** P_LVALUE_388 = &(PTMP_tmp42_1);
                PrtFreeValue(*P_LVALUE_388);
                *P_LVALUE_388 = PrtTupleGet(*P_VAR_wReq_2, 1);
                
                PRT_VALUE** P_LVALUE_389 = &(PTMP_tmp43_1);
                PrtFreeValue(*P_LVALUE_389);
                *P_LVALUE_389 = PrtTupleGet(PTMP_tmp42_1, 3);
                
                PRT_VALUE** P_LVALUE_390 = &(PTMP_tmp44_1);
                PrtFreeValue(*P_LVALUE_390);
                *P_LVALUE_390 = PrtSeqGet(PTMP_tmp43_1, (&P_LIT_INT32_56));
                
                PRT_VALUE** P_LVALUE_391 = &(PTMP_tmp45_1);
                PrtFreeValue(*P_LVALUE_391);
                *P_LVALUE_391 = PrtTupleGet(PTMP_tmp44_1, 3);
                
                PRT_VALUE** P_LVALUE_392 = &(PTMP_tmp46_1);
                PrtFreeValue(*P_LVALUE_392);
                *P_LVALUE_392 = ((_P_GEN_funargs[0] = &(PTMP_tmp45_1)), (_P_GEN_funval = P_readBuffer_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp45_1), PTMP_tmp45_1 = NULL), (_P_GEN_funval));
                if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                    goto p_return_8;
                }
                if (p_this->isHalted == PRT_TRUE) {
                    PrtFreeValue(_P_GEN_retval);
                    _P_GEN_retval = NULL;
                    goto p_return_8;
                }
                
                PRT_VALUE** P_LVALUE_393 = &(PTMP_tmp47_1);
                PrtFreeValue(*P_LVALUE_393);
                *P_LVALUE_393 = PrtSeqGet(p_this->varValues[1], P_VAR_counter2);
                
                PRT_VALUE** P_LVALUE_394 = &(PTMP_tmp48_1);
                PrtFreeValue(*P_LVALUE_394);
                *P_LVALUE_394 = PrtSeqGet(PTMP_tmp47_1, P_VAR_counter3);
                
                PRT_VALUE** P_LVALUE_395 = &(PTMP_tmp49_1);
                PrtFreeValue(*P_LVALUE_395);
                *P_LVALUE_395 = PrtTupleGet(PTMP_tmp48_1, 2);
                
                PRT_VALUE** P_LVALUE_396 = &(PTMP_tmp50_1);
                PrtFreeValue(*P_LVALUE_396);
                *P_LVALUE_396 = PrtTupleGet(PTMP_tmp49_1, 3);
                
                PRT_VALUE** P_LVALUE_397 = &(PTMP_tmp51_1);
                PrtFreeValue(*P_LVALUE_397);
                *P_LVALUE_397 = ((_P_GEN_funargs[0] = &(PTMP_tmp50_1)), (_P_GEN_funval = P_readBuffer_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp50_1), PTMP_tmp50_1 = NULL), (_P_GEN_funval));
                if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                    goto p_return_8;
                }
                if (p_this->isHalted == PRT_TRUE) {
                    PrtFreeValue(_P_GEN_retval);
                    _P_GEN_retval = NULL;
                    goto p_return_8;
                }
                
                PRT_VALUE** P_LVALUE_398 = &(PTMP_tmp52_1);
                PrtFreeValue(*P_LVALUE_398);
                *P_LVALUE_398 = PrtMkBoolValue(PrtIsEqualValue(PTMP_tmp46_1, PTMP_tmp51_1));
                
                PRT_VALUE** P_LVALUE_399 = &(PTMP_tmp53_1);
                PrtFreeValue(*P_LVALUE_399);
                *P_LVALUE_399 = PrtCloneValue(PTMP_tmp52_1);
                
            }
            
            
            if (PrtPrimGetBool(PTMP_tmp53_1))
            {
                PRT_VALUE** P_LVALUE_400 = &(P_VAR_flag2);
                PrtFreeValue(*P_LVALUE_400);
                *P_LVALUE_400 = PrtCloneValue((&P_LIT_BOOLEAN_6));
                
            }
            
            else
            {
            }
            
            
            PRT_VALUE** P_LVALUE_401 = &(PTMP_tmp54_1);
            PrtFreeValue(*P_LVALUE_401);
            *P_LVALUE_401 = PrtMkIntValue(PrtPrimGetInt(P_VAR_counter3) + PrtPrimGetInt((&P_LIT_INT32_56)));
            
            {
                PRT_VALUE** P_LVALUE_402 = &(P_VAR_counter3);
                PrtFreeValue(*P_LVALUE_402);
                *P_LVALUE_402 = PTMP_tmp54_1;
                PTMP_tmp54_1 = NULL;
            }
            
        }
        
        
        PRT_VALUE** P_LVALUE_403 = &(PTMP_tmp55_1);
        PrtFreeValue(*P_LVALUE_403);
        *P_LVALUE_403 = PrtMkIntValue(PrtPrimGetInt(P_VAR_counter2) + PrtPrimGetInt((&P_LIT_INT32_56)));
        
        {
            PRT_VALUE** P_LVALUE_404 = &(P_VAR_counter2);
            PrtFreeValue(*P_LVALUE_404);
            *P_LVALUE_404 = PTMP_tmp55_1;
            PTMP_tmp55_1 = NULL;
        }
        
    }
    
    
    PRT_VALUE** P_LVALUE_405 = &(PTMP_tmp56_1);
    PrtFreeValue(*P_LVALUE_405);
    *P_LVALUE_405 = PrtMkBoolValue(PrtIsEqualValue(P_VAR_flag1, (&P_LIT_BOOLEAN_6)));
    
    PRT_VALUE** P_LVALUE_406 = &(PTMP_tmp58_1);
    PrtFreeValue(*P_LVALUE_406);
    *P_LVALUE_406 = PrtCloneValue(PTMP_tmp56_1);
    
    if (PrtPrimGetBool(PTMP_tmp58_1))
    {
        PRT_VALUE** P_LVALUE_407 = &(PTMP_tmp57_1);
        PrtFreeValue(*P_LVALUE_407);
        *P_LVALUE_407 = PrtMkBoolValue(PrtIsEqualValue(P_VAR_flag2, (&P_LIT_BOOLEAN_5)));
        
        PRT_VALUE** P_LVALUE_408 = &(PTMP_tmp58_1);
        PrtFreeValue(*P_LVALUE_408);
        *P_LVALUE_408 = PrtCloneValue(PTMP_tmp57_1);
        
    }
    
    
    if (PrtPrimGetBool(PTMP_tmp58_1))
    {
        PRT_VALUE** P_LVALUE_409 = &(*(PrtTupleGetLValue(P_VAR_tmp1, 0)));
        PrtFreeValue(*P_LVALUE_409);
        *P_LVALUE_409 = PrtCloneValue((&P_LIT_INT32_55));
        
        PRT_VALUE** P_LVALUE_410 = &(PTMP_tmp59_1);
        PrtFreeValue(*P_LVALUE_410);
        *P_LVALUE_410 = PrtCloneValue((&P_LIT_INT32_55));
        
        PRT_VALUE** P_LVALUE_411 = &(PTMP_tmp60_1);
        PrtFreeValue(*P_LVALUE_411);
        *P_LVALUE_411 = PrtCloneValue((&P_LIT_INT32_56));
        
        PRT_VALUE** P_LVALUE_412 = &(PTMP_tmp61_1);
        PrtFreeValue(*P_LVALUE_412);
        *P_LVALUE_412 = ((_P_GEN_funargs[0] = &(PTMP_tmp59_1)), (_P_GEN_funargs[1] = &(PTMP_tmp60_1)), (_P_GEN_funval = P_writeBuffer_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp59_1), PTMP_tmp59_1 = NULL), (PrtFreeValue(PTMP_tmp60_1), PTMP_tmp60_1 = NULL), (_P_GEN_funval));
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_8;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_8;
        }
        
        {
            PRT_VALUE** P_LVALUE_413 = &(*(PrtTupleGetLValue(*(PrtTupleGetLValue(P_VAR_tmp1, 1)), 3)));
            PrtFreeValue(*P_LVALUE_413);
            *P_LVALUE_413 = PTMP_tmp61_1;
            PTMP_tmp61_1 = NULL;
        }
        
        PRT_VALUE** P_LVALUE_414 = &(PTMP_tmp62_1);
        PrtFreeValue(*P_LVALUE_414);
        *P_LVALUE_414 = PrtTupleGet(*P_VAR_wReq_2, 1);
        
        PRT_VALUE** P_LVALUE_415 = &(PTMP_tmp63_1);
        PrtFreeValue(*P_LVALUE_415);
        *P_LVALUE_415 = PrtTupleGet(PTMP_tmp62_1, 3);
        
        PRT_VALUE** P_LVALUE_416 = &(PTMP_tmp64_1);
        PrtFreeValue(*P_LVALUE_416);
        *P_LVALUE_416 = PrtSeqGet(PTMP_tmp63_1, (&P_LIT_INT32_54));
        
        PRT_VALUE** P_LVALUE_417 = &(PTMP_tmp65_1);
        PrtFreeValue(*P_LVALUE_417);
        *P_LVALUE_417 = PrtCloneValue(PTMP_tmp64_1);
        
        {
            PRT_VALUE** P_LVALUE_418 = &(*(PrtTupleGetLValue(P_VAR_tmp1, 2)));
            PrtFreeValue(*P_LVALUE_418);
            *P_LVALUE_418 = PTMP_tmp65_1;
            PTMP_tmp65_1 = NULL;
        }
        
        PRT_VALUE** P_LVALUE_419 = &(*(PrtTupleGetLValue(P_VAR_tmp2, 0)));
        PrtFreeValue(*P_LVALUE_419);
        *P_LVALUE_419 = PrtCloneValue((&P_LIT_INT32_56));
        
        PRT_VALUE** P_LVALUE_420 = &(PTMP_tmp66_1);
        PrtFreeValue(*P_LVALUE_420);
        *P_LVALUE_420 = PrtCloneValue((&P_LIT_INT32_56));
        
        PRT_VALUE** P_LVALUE_421 = &(PTMP_tmp67_1);
        PrtFreeValue(*P_LVALUE_421);
        *P_LVALUE_421 = PrtCloneValue((&P_LIT_INT32_56));
        
        PRT_VALUE** P_LVALUE_422 = &(PTMP_tmp68_1);
        PrtFreeValue(*P_LVALUE_422);
        *P_LVALUE_422 = ((_P_GEN_funargs[0] = &(PTMP_tmp66_1)), (_P_GEN_funargs[1] = &(PTMP_tmp67_1)), (_P_GEN_funval = P_writeBuffer_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp66_1), PTMP_tmp66_1 = NULL), (PrtFreeValue(PTMP_tmp67_1), PTMP_tmp67_1 = NULL), (_P_GEN_funval));
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_8;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_8;
        }
        
        {
            PRT_VALUE** P_LVALUE_423 = &(*(PrtTupleGetLValue(*(PrtTupleGetLValue(P_VAR_tmp2, 1)), 3)));
            PrtFreeValue(*P_LVALUE_423);
            *P_LVALUE_423 = PTMP_tmp68_1;
            PTMP_tmp68_1 = NULL;
        }
        
        PRT_VALUE** P_LVALUE_424 = &(PTMP_tmp69_1);
        PrtFreeValue(*P_LVALUE_424);
        *P_LVALUE_424 = PrtTupleGet(*P_VAR_wReq_2, 1);
        
        PRT_VALUE** P_LVALUE_425 = &(PTMP_tmp70_1);
        PrtFreeValue(*P_LVALUE_425);
        *P_LVALUE_425 = PrtTupleGet(PTMP_tmp69_1, 3);
        
        PRT_VALUE** P_LVALUE_426 = &(PTMP_tmp71_1);
        PrtFreeValue(*P_LVALUE_426);
        *P_LVALUE_426 = PrtSeqGet(PTMP_tmp70_1, (&P_LIT_INT32_56));
        
        PRT_VALUE** P_LVALUE_427 = &(PTMP_tmp72_1);
        PrtFreeValue(*P_LVALUE_427);
        *P_LVALUE_427 = PrtCloneValue(PTMP_tmp71_1);
        
        {
            PRT_VALUE** P_LVALUE_428 = &(*(PrtTupleGetLValue(P_VAR_tmp2, 2)));
            PrtFreeValue(*P_LVALUE_428);
            *P_LVALUE_428 = PTMP_tmp72_1;
            PTMP_tmp72_1 = NULL;
        }
        
        PRT_VALUE** P_LVALUE_429 = &(PTMP_tmp73_1);
        PrtFreeValue(*P_LVALUE_429);
        *P_LVALUE_429 = PrtCloneValue(P_VAR_tmp2);
        
        PrtSeqInsertEx(P_VAR_tmp3, (&P_LIT_INT32_54), PTMP_tmp73_1, PRT_FALSE);
        *(&(PTMP_tmp73_1)) = NULL;
        
        PRT_VALUE** P_LVALUE_430 = &(PTMP_tmp74_1);
        PrtFreeValue(*P_LVALUE_430);
        *P_LVALUE_430 = PrtCloneValue(P_VAR_tmp1);
        
        PrtSeqInsertEx(P_VAR_tmp3, (&P_LIT_INT32_56), PTMP_tmp74_1, PRT_FALSE);
        *(&(PTMP_tmp74_1)) = NULL;
        
        PRT_VALUE** P_LVALUE_431 = &(PTMP_tmp75_1);
        PrtFreeValue(*P_LVALUE_431);
        *P_LVALUE_431 = PrtMkIntValue(PrtSeqSizeOf(p_this->varValues[1]));
        
        PRT_VALUE** P_LVALUE_432 = &(PTMP_tmp76_1);
        PrtFreeValue(*P_LVALUE_432);
        *P_LVALUE_432 = PrtMkIntValue(PrtPrimGetInt(PTMP_tmp75_1) - PrtPrimGetInt((&P_LIT_INT32_56)));
        
        PRT_VALUE** P_LVALUE_433 = &(PTMP_tmp77_1);
        PrtFreeValue(*P_LVALUE_433);
        *P_LVALUE_433 = PrtCloneValue(P_VAR_tmp3);
        
        PrtSeqInsertEx(p_this->varValues[1], PTMP_tmp76_1, PTMP_tmp77_1, PRT_FALSE);
        *(&(PTMP_tmp77_1)) = NULL;
        
        PRT_VALUE** P_LVALUE_434 = &(PTMP_tmp78_1);
        PrtFreeValue(*P_LVALUE_434);
        *P_LVALUE_434 = PrtMkIntValue(PrtSeqSizeOf(p_this->varValues[1]));
        
        PRT_VALUE** P_LVALUE_435 = &(PTMP_tmp79_1);
        PrtFreeValue(*P_LVALUE_435);
        *P_LVALUE_435 = PrtCloneValue(p_this->varValues[0]);
        
        PRT_VALUE** P_LVALUE_436 = &(PTMP_tmp80_1);
        PrtFreeValue(*P_LVALUE_436);
        *P_LVALUE_436 = PrtCloneValue(PrtMkInterface(context, 3, 1, &(PTMP_tmp79_1))->id);
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_8;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_8;
        }
        
        {
            PRT_VALUE** P_LVALUE_437 = &(*(PrtMapGetLValue(p_this->varValues[2], PTMP_tmp78_1, PRT_TRUE, &P_GEND_TYPE_MKiVR)));
            PrtFreeValue(*P_LVALUE_437);
            *P_LVALUE_437 = PTMP_tmp80_1;
            PTMP_tmp80_1 = NULL;
        }
        
        PRT_VALUE** P_LVALUE_438 = &(PTMP_tmp81_1);
        PrtFreeValue(*P_LVALUE_438);
        *P_LVALUE_438 = PrtMkIntValue(PrtSeqSizeOf(p_this->varValues[1]));
        
        PRT_VALUE** P_LVALUE_439 = &(PTMP_tmp82_1);
        PrtFreeValue(*P_LVALUE_439);
        *P_LVALUE_439 = PrtMapGet(p_this->varValues[2], PTMP_tmp81_1);
        
        PRT_VALUE** P_LVALUE_440 = &(PTMP_tmp83_1);
        PrtFreeValue(*P_LVALUE_440);
        *P_LVALUE_440 = PrtCloneValue(PTMP_tmp82_1);
        
        PRT_VALUE** P_LVALUE_441 = &(PTMP_tmp84_1);
        PrtFreeValue(*P_LVALUE_441);
        *P_LVALUE_441 = PrtCloneValue((&P_EVENT_eChanGotoConfig.value));
        
        PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp83_1), PTMP_tmp84_1, 0);
        *(&(PTMP_tmp84_1)) = NULL;
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_8;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_8;
        }
        
        PRT_VALUE** P_LVALUE_442 = &(PTMP_tmp85_1);
        PrtFreeValue(*P_LVALUE_442);
        *P_LVALUE_442 = PrtTupleGet(*P_VAR_wReq_2, 0);
        
        PRT_VALUE** P_LVALUE_443 = &(PTMP_tmp86_1);
        PrtFreeValue(*P_LVALUE_443);
        *P_LVALUE_443 = PrtCloneValue(PTMP_tmp85_1);
        
        PRT_VALUE** P_LVALUE_444 = &(PTMP_tmp87_1);
        PrtFreeValue(*P_LVALUE_444);
        *P_LVALUE_444 = PrtCloneValue((&P_EVENT_eConnResp.value));
        
        PRT_VALUE** P_LVALUE_445 = &(PTMP_tmp88_1);
        PrtFreeValue(*P_LVALUE_445);
        *P_LVALUE_445 = PrtCloneValue((&P_LIT_BOOLEAN_6));
        
        PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp86_1), PTMP_tmp87_1, 1, &(PTMP_tmp88_1));
        *(&(PTMP_tmp87_1)) = NULL;
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_8;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_8;
        }
        
        goto p_return_8;
        
    }
    
    else
    {
    }
    
    
    PRT_VALUE** P_LVALUE_446 = &(PTMP_tmp89_1);
    PrtFreeValue(*P_LVALUE_446);
    *P_LVALUE_446 = PrtTupleGet(*P_VAR_wReq_2, 0);
    
    PRT_VALUE** P_LVALUE_447 = &(PTMP_tmp90_1);
    PrtFreeValue(*P_LVALUE_447);
    *P_LVALUE_447 = PrtCloneValue(PTMP_tmp89_1);
    
    PRT_VALUE** P_LVALUE_448 = &(PTMP_tmp91_1);
    PrtFreeValue(*P_LVALUE_448);
    *P_LVALUE_448 = PrtCloneValue((&P_EVENT_eConnResp.value));
    
    PRT_VALUE** P_LVALUE_449 = &(PTMP_tmp92_1);
    PrtFreeValue(*P_LVALUE_449);
    *P_LVALUE_449 = PrtCloneValue((&P_LIT_BOOLEAN_5));
    
    PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp90_1), PTMP_tmp91_1, 1, &(PTMP_tmp92_1));
    *(&(PTMP_tmp91_1)) = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_8;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_8;
    }
    
p_return_8: ;
    PrtFreeValue(P_VAR_counter2); P_VAR_counter2 = NULL;
    PrtFreeValue(P_VAR_flag1); P_VAR_flag1 = NULL;
    PrtFreeValue(P_VAR_flag2); P_VAR_flag2 = NULL;
    PrtFreeValue(P_VAR_index); P_VAR_index = NULL;
    PrtFreeValue(P_VAR_counter3); P_VAR_counter3 = NULL;
    PrtFreeValue(P_VAR_tmp1); P_VAR_tmp1 = NULL;
    PrtFreeValue(P_VAR_tmp2); P_VAR_tmp2 = NULL;
    PrtFreeValue(P_VAR_tmp3); P_VAR_tmp3 = NULL;
    PrtFreeValue(PTMP_tmp0_7); PTMP_tmp0_7 = NULL;
    PrtFreeValue(PTMP_tmp1_7); PTMP_tmp1_7 = NULL;
    PrtFreeValue(PTMP_tmp2_7); PTMP_tmp2_7 = NULL;
    PrtFreeValue(PTMP_tmp3_7); PTMP_tmp3_7 = NULL;
    PrtFreeValue(PTMP_tmp4_6); PTMP_tmp4_6 = NULL;
    PrtFreeValue(PTMP_tmp5_6); PTMP_tmp5_6 = NULL;
    PrtFreeValue(PTMP_tmp6_6); PTMP_tmp6_6 = NULL;
    PrtFreeValue(PTMP_tmp7_5); PTMP_tmp7_5 = NULL;
    PrtFreeValue(PTMP_tmp8_5); PTMP_tmp8_5 = NULL;
    PrtFreeValue(PTMP_tmp9_5); PTMP_tmp9_5 = NULL;
    PrtFreeValue(PTMP_tmp10_5); PTMP_tmp10_5 = NULL;
    PrtFreeValue(PTMP_tmp11_5); PTMP_tmp11_5 = NULL;
    PrtFreeValue(PTMP_tmp12_5); PTMP_tmp12_5 = NULL;
    PrtFreeValue(PTMP_tmp13_5); PTMP_tmp13_5 = NULL;
    PrtFreeValue(PTMP_tmp14_5); PTMP_tmp14_5 = NULL;
    PrtFreeValue(PTMP_tmp15_4); PTMP_tmp15_4 = NULL;
    PrtFreeValue(PTMP_tmp16_4); PTMP_tmp16_4 = NULL;
    PrtFreeValue(PTMP_tmp17_4); PTMP_tmp17_4 = NULL;
    PrtFreeValue(PTMP_tmp18_4); PTMP_tmp18_4 = NULL;
    PrtFreeValue(PTMP_tmp19_4); PTMP_tmp19_4 = NULL;
    PrtFreeValue(PTMP_tmp20_4); PTMP_tmp20_4 = NULL;
    PrtFreeValue(PTMP_tmp21_4); PTMP_tmp21_4 = NULL;
    PrtFreeValue(PTMP_tmp22_4); PTMP_tmp22_4 = NULL;
    PrtFreeValue(PTMP_tmp23_4); PTMP_tmp23_4 = NULL;
    PrtFreeValue(PTMP_tmp24_3); PTMP_tmp24_3 = NULL;
    PrtFreeValue(PTMP_tmp25_3); PTMP_tmp25_3 = NULL;
    PrtFreeValue(PTMP_tmp26_3); PTMP_tmp26_3 = NULL;
    PrtFreeValue(PTMP_tmp27_3); PTMP_tmp27_3 = NULL;
    PrtFreeValue(PTMP_tmp28_3); PTMP_tmp28_3 = NULL;
    PrtFreeValue(PTMP_tmp29_3); PTMP_tmp29_3 = NULL;
    PrtFreeValue(PTMP_tmp30_3); PTMP_tmp30_3 = NULL;
    PrtFreeValue(PTMP_tmp31_3); PTMP_tmp31_3 = NULL;
    PrtFreeValue(PTMP_tmp32_3); PTMP_tmp32_3 = NULL;
    PrtFreeValue(PTMP_tmp33_2); PTMP_tmp33_2 = NULL;
    PrtFreeValue(PTMP_tmp34_2); PTMP_tmp34_2 = NULL;
    PrtFreeValue(PTMP_tmp35_2); PTMP_tmp35_2 = NULL;
    PrtFreeValue(PTMP_tmp36_2); PTMP_tmp36_2 = NULL;
    PrtFreeValue(PTMP_tmp37_2); PTMP_tmp37_2 = NULL;
    PrtFreeValue(PTMP_tmp38_2); PTMP_tmp38_2 = NULL;
    PrtFreeValue(PTMP_tmp39_2); PTMP_tmp39_2 = NULL;
    PrtFreeValue(PTMP_tmp40_1); PTMP_tmp40_1 = NULL;
    PrtFreeValue(PTMP_tmp41_1); PTMP_tmp41_1 = NULL;
    PrtFreeValue(PTMP_tmp42_1); PTMP_tmp42_1 = NULL;
    PrtFreeValue(PTMP_tmp43_1); PTMP_tmp43_1 = NULL;
    PrtFreeValue(PTMP_tmp44_1); PTMP_tmp44_1 = NULL;
    PrtFreeValue(PTMP_tmp45_1); PTMP_tmp45_1 = NULL;
    PrtFreeValue(PTMP_tmp46_1); PTMP_tmp46_1 = NULL;
    PrtFreeValue(PTMP_tmp47_1); PTMP_tmp47_1 = NULL;
    PrtFreeValue(PTMP_tmp48_1); PTMP_tmp48_1 = NULL;
    PrtFreeValue(PTMP_tmp49_1); PTMP_tmp49_1 = NULL;
    PrtFreeValue(PTMP_tmp50_1); PTMP_tmp50_1 = NULL;
    PrtFreeValue(PTMP_tmp51_1); PTMP_tmp51_1 = NULL;
    PrtFreeValue(PTMP_tmp52_1); PTMP_tmp52_1 = NULL;
    PrtFreeValue(PTMP_tmp53_1); PTMP_tmp53_1 = NULL;
    PrtFreeValue(PTMP_tmp54_1); PTMP_tmp54_1 = NULL;
    PrtFreeValue(PTMP_tmp55_1); PTMP_tmp55_1 = NULL;
    PrtFreeValue(PTMP_tmp56_1); PTMP_tmp56_1 = NULL;
    PrtFreeValue(PTMP_tmp57_1); PTMP_tmp57_1 = NULL;
    PrtFreeValue(PTMP_tmp58_1); PTMP_tmp58_1 = NULL;
    PrtFreeValue(PTMP_tmp59_1); PTMP_tmp59_1 = NULL;
    PrtFreeValue(PTMP_tmp60_1); PTMP_tmp60_1 = NULL;
    PrtFreeValue(PTMP_tmp61_1); PTMP_tmp61_1 = NULL;
    PrtFreeValue(PTMP_tmp62_1); PTMP_tmp62_1 = NULL;
    PrtFreeValue(PTMP_tmp63_1); PTMP_tmp63_1 = NULL;
    PrtFreeValue(PTMP_tmp64_1); PTMP_tmp64_1 = NULL;
    PrtFreeValue(PTMP_tmp65_1); PTMP_tmp65_1 = NULL;
    PrtFreeValue(PTMP_tmp66_1); PTMP_tmp66_1 = NULL;
    PrtFreeValue(PTMP_tmp67_1); PTMP_tmp67_1 = NULL;
    PrtFreeValue(PTMP_tmp68_1); PTMP_tmp68_1 = NULL;
    PrtFreeValue(PTMP_tmp69_1); PTMP_tmp69_1 = NULL;
    PrtFreeValue(PTMP_tmp70_1); PTMP_tmp70_1 = NULL;
    PrtFreeValue(PTMP_tmp71_1); PTMP_tmp71_1 = NULL;
    PrtFreeValue(PTMP_tmp72_1); PTMP_tmp72_1 = NULL;
    PrtFreeValue(PTMP_tmp73_1); PTMP_tmp73_1 = NULL;
    PrtFreeValue(PTMP_tmp74_1); PTMP_tmp74_1 = NULL;
    PrtFreeValue(PTMP_tmp75_1); PTMP_tmp75_1 = NULL;
    PrtFreeValue(PTMP_tmp76_1); PTMP_tmp76_1 = NULL;
    PrtFreeValue(PTMP_tmp77_1); PTMP_tmp77_1 = NULL;
    PrtFreeValue(PTMP_tmp78_1); PTMP_tmp78_1 = NULL;
    PrtFreeValue(PTMP_tmp79_1); PTMP_tmp79_1 = NULL;
    PrtFreeValue(PTMP_tmp80_1); PTMP_tmp80_1 = NULL;
    PrtFreeValue(PTMP_tmp81_1); PTMP_tmp81_1 = NULL;
    PrtFreeValue(PTMP_tmp82_1); PTMP_tmp82_1 = NULL;
    PrtFreeValue(PTMP_tmp83_1); PTMP_tmp83_1 = NULL;
    PrtFreeValue(PTMP_tmp84_1); PTMP_tmp84_1 = NULL;
    PrtFreeValue(PTMP_tmp85_1); PTMP_tmp85_1 = NULL;
    PrtFreeValue(PTMP_tmp86_1); PTMP_tmp86_1 = NULL;
    PrtFreeValue(PTMP_tmp87_1); PTMP_tmp87_1 = NULL;
    PrtFreeValue(PTMP_tmp88_1); PTMP_tmp88_1 = NULL;
    PrtFreeValue(PTMP_tmp89_1); PTMP_tmp89_1 = NULL;
    PrtFreeValue(PTMP_tmp90_1); PTMP_tmp90_1 = NULL;
    PrtFreeValue(PTMP_tmp91_1); PTMP_tmp91_1 = NULL;
    PrtFreeValue(PTMP_tmp92_1); PTMP_tmp92_1 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_4 =
{
    NULL,
    &P_Anon_IMPL_4,
    &P_GEND_TYPE_NT2mNT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB
};


PRT_VALUE* P_Anon_IMPL_5(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_wReq_3 = argRefs[0];
    PRT_VALUE* P_VAR_hm = PrtMkDefaultValue(&P_GEND_TYPE_NT2NT2SNT4iiiSiNT4iiiSiB);
    PRT_VALUE* P_VAR_msub = PrtMkDefaultValue(&P_GEND_TYPE_NT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB);
    PRT_VALUE* P_VAR_srcChanID = PrtMkDefaultValue(&P_GEND_TYPE_NT4iiiSi);
    PRT_VALUE* P_VAR_optPlist = PrtMkDefaultValue(&P_GEND_TYPE_NT2iSNT3iNT4iiiSiNT4iiiSi);
    PRT_VALUE* P_VAR_mtuPara = PrtMkDefaultValue(&P_GEND_TYPE_NT3iNT4iiiSiNT4iiiSi);
    PRT_VALUE* P_VAR_counter2_1 = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* P_VAR_flag1_1 = PrtMkDefaultValue(&P_GEND_TYPE_b);
    PRT_VALUE* P_VAR_index_1 = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* P_VAR_counter3_1 = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* P_VAR_targetChan = PrtMkDefaultValue(&P_GEND_TYPE_SNT3iNT4iiiSiNT4iiiSi);
    PRT_VALUE* P_VAR_targetChanM = PrtMkDefaultValue(&P_GEND_TYPE_R_2);
    PRT_VALUE* PTMP_tmp0_8 = NULL;
    PRT_VALUE* PTMP_tmp1_8 = NULL;
    PRT_VALUE* PTMP_tmp2_8 = NULL;
    PRT_VALUE* PTMP_tmp3_8 = NULL;
    PRT_VALUE* PTMP_tmp4_7 = NULL;
    PRT_VALUE* PTMP_tmp5_7 = NULL;
    PRT_VALUE* PTMP_tmp6_7 = NULL;
    PRT_VALUE* PTMP_tmp7_6 = NULL;
    PRT_VALUE* PTMP_tmp8_6 = NULL;
    PRT_VALUE* PTMP_tmp9_6 = NULL;
    PRT_VALUE* PTMP_tmp10_6 = NULL;
    PRT_VALUE* PTMP_tmp11_6 = NULL;
    PRT_VALUE* PTMP_tmp12_6 = NULL;
    PRT_VALUE* PTMP_tmp13_6 = NULL;
    PRT_VALUE* PTMP_tmp14_6 = NULL;
    PRT_VALUE* PTMP_tmp15_5 = NULL;
    PRT_VALUE* PTMP_tmp16_5 = NULL;
    PRT_VALUE* PTMP_tmp17_5 = NULL;
    PRT_VALUE* PTMP_tmp18_5 = NULL;
    PRT_VALUE* PTMP_tmp19_5 = NULL;
    PRT_VALUE* PTMP_tmp20_5 = NULL;
    PRT_VALUE* PTMP_tmp21_5 = NULL;
    PRT_VALUE* PTMP_tmp22_5 = NULL;
    PRT_VALUE* PTMP_tmp23_5 = NULL;
    PRT_VALUE* PTMP_tmp24_4 = NULL;
    PRT_VALUE* PTMP_tmp25_4 = NULL;
    PRT_VALUE* PTMP_tmp26_4 = NULL;
    PRT_VALUE* PTMP_tmp27_4 = NULL;
    PRT_VALUE* PTMP_tmp28_4 = NULL;
    PRT_VALUE* PTMP_tmp29_4 = NULL;
    PRT_VALUE* PTMP_tmp30_4 = NULL;
    PRT_VALUE* PTMP_tmp31_4 = NULL;
    PRT_VALUE* PTMP_tmp32_4 = NULL;
    PRT_VALUE* PTMP_tmp33_3 = NULL;
    PRT_VALUE* PTMP_tmp34_3 = NULL;
    PRT_VALUE* PTMP_tmp35_3 = NULL;
    PRT_VALUE* PTMP_tmp36_3 = NULL;
    PRT_VALUE* PTMP_tmp37_3 = NULL;
    PRT_VALUE* PTMP_tmp38_3 = NULL;
    PRT_VALUE* PTMP_tmp39_3 = NULL;
    PRT_VALUE* PTMP_tmp40_2 = NULL;
    PRT_VALUE* PTMP_tmp41_2 = NULL;
    PRT_VALUE* PTMP_tmp42_2 = NULL;
    PRT_VALUE* PTMP_tmp43_2 = NULL;
    PRT_VALUE* PTMP_tmp44_2 = NULL;
    PRT_VALUE* PTMP_tmp45_2 = NULL;
    PRT_VALUE* PTMP_tmp46_2 = NULL;
    PRT_VALUE* PTMP_tmp47_2 = NULL;
    PRT_VALUE* PTMP_tmp48_2 = NULL;
    PRT_VALUE* PTMP_tmp49_2 = NULL;
    PRT_VALUE* PTMP_tmp50_2 = NULL;
    PRT_VALUE* PTMP_tmp51_2 = NULL;
    PRT_VALUE* PTMP_tmp52_2 = NULL;
    PRT_VALUE* PTMP_tmp53_2 = NULL;
    PRT_VALUE* PTMP_tmp54_2 = NULL;
    PRT_VALUE* PTMP_tmp55_2 = NULL;
    PRT_VALUE* PTMP_tmp56_2 = NULL;
    PRT_VALUE* PTMP_tmp57_2 = NULL;
    PRT_VALUE* PTMP_tmp58_2 = NULL;
    PRT_VALUE* PTMP_tmp59_2 = NULL;
    PRT_VALUE* PTMP_tmp60_2 = NULL;
    PRT_VALUE* PTMP_tmp61_2 = NULL;
    PRT_VALUE* PTMP_tmp62_2 = NULL;
    PRT_VALUE* PTMP_tmp63_2 = NULL;
    PRT_VALUE* PTMP_tmp64_2 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_57 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE P_LIT_INT32_58 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE P_LIT_BOOLEAN_7 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_FALSE } };
    PRT_VALUE P_LIT_BOOLEAN_8 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_TRUE } };
    PRT_VALUE** P_LVALUE_450 = &(PTMP_tmp0_8);
    PrtFreeValue(*P_LVALUE_450);
    *P_LVALUE_450 = PrtTupleGet(*P_VAR_wReq_3, 1);
    
    
    PRT_VALUE** P_LVALUE_451 = &(PTMP_tmp1_8);
    PrtFreeValue(*P_LVALUE_451);
    *P_LVALUE_451 = PrtTupleGet(*P_VAR_wReq_3, 1);
    
    PRT_VALUE** P_LVALUE_452 = &(PTMP_tmp2_8);
    PrtFreeValue(*P_LVALUE_452);
    *P_LVALUE_452 = PrtTupleGet(PTMP_tmp1_8, 5);
    
    PRT_VALUE** P_LVALUE_453 = &(PTMP_tmp3_8);
    PrtFreeValue(*P_LVALUE_453);
    *P_LVALUE_453 = PrtCloneValue(PTMP_tmp2_8);
    
    {
        PRT_VALUE** P_LVALUE_454 = &(P_VAR_hm);
        PrtFreeValue(*P_LVALUE_454);
        *P_LVALUE_454 = PTMP_tmp3_8;
        PTMP_tmp3_8 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_455 = &(PTMP_tmp4_7);
    PrtFreeValue(*P_LVALUE_455);
    *P_LVALUE_455 = PrtTupleGet(P_VAR_hm, 0);
    
    PRT_VALUE** P_LVALUE_456 = &(PTMP_tmp5_7);
    PrtFreeValue(*P_LVALUE_456);
    *P_LVALUE_456 = PrtTupleGet(PTMP_tmp4_7, 0);
    
    PRT_VALUE** P_LVALUE_457 = &(PTMP_tmp6_7);
    PrtFreeValue(*P_LVALUE_457);
    *P_LVALUE_457 = PrtSeqGet(PTMP_tmp5_7, (&P_LIT_INT32_57));
    
    PRT_VALUE** P_LVALUE_458 = &(PTMP_tmp7_6);
    PrtFreeValue(*P_LVALUE_458);
    *P_LVALUE_458 = PrtCloneValue(PTMP_tmp6_7);
    
    {
        PRT_VALUE** P_LVALUE_459 = &(P_VAR_srcChanID);
        PrtFreeValue(*P_LVALUE_459);
        *P_LVALUE_459 = PTMP_tmp7_6;
        PTMP_tmp7_6 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_460 = &(PTMP_tmp8_6);
    PrtFreeValue(*P_LVALUE_460);
    *P_LVALUE_460 = PrtTupleGet(P_VAR_hm, 1);
    
    PRT_VALUE** P_LVALUE_461 = &(PTMP_tmp9_6);
    PrtFreeValue(*P_LVALUE_461);
    *P_LVALUE_461 = PrtCloneValue(PrtCastValue(PrtCloneValue(PTMP_tmp8_6), &P_GEND_TYPE_NT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB));
    
    {
        PRT_VALUE** P_LVALUE_462 = &(P_VAR_msub);
        PrtFreeValue(*P_LVALUE_462);
        *P_LVALUE_462 = PTMP_tmp9_6;
        PTMP_tmp9_6 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_463 = &(PTMP_tmp10_6);
    PrtFreeValue(*P_LVALUE_463);
    *P_LVALUE_463 = PrtTupleGet(P_VAR_msub, 4);
    
    PRT_VALUE** P_LVALUE_464 = &(PTMP_tmp11_6);
    PrtFreeValue(*P_LVALUE_464);
    *P_LVALUE_464 = PrtCloneValue(PTMP_tmp10_6);
    
    {
        PRT_VALUE** P_LVALUE_465 = &(P_VAR_optPlist);
        PrtFreeValue(*P_LVALUE_465);
        *P_LVALUE_465 = PTMP_tmp11_6;
        PTMP_tmp11_6 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_466 = &(PTMP_tmp12_6);
    PrtFreeValue(*P_LVALUE_466);
    *P_LVALUE_466 = PrtTupleGet(P_VAR_optPlist, 1);
    
    PRT_VALUE** P_LVALUE_467 = &(PTMP_tmp13_6);
    PrtFreeValue(*P_LVALUE_467);
    *P_LVALUE_467 = PrtSeqGet(PTMP_tmp12_6, (&P_LIT_INT32_57));
    
    PRT_VALUE** P_LVALUE_468 = &(PTMP_tmp14_6);
    PrtFreeValue(*P_LVALUE_468);
    *P_LVALUE_468 = PrtCloneValue(PTMP_tmp13_6);
    
    {
        PRT_VALUE** P_LVALUE_469 = &(P_VAR_mtuPara);
        PrtFreeValue(*P_LVALUE_469);
        *P_LVALUE_469 = PTMP_tmp14_6;
        PTMP_tmp14_6 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_470 = &(P_VAR_counter2_1);
    PrtFreeValue(*P_LVALUE_470);
    *P_LVALUE_470 = PrtCloneValue((&P_LIT_INT32_57));
    
    PRT_VALUE** P_LVALUE_471 = &(P_VAR_flag1_1);
    PrtFreeValue(*P_LVALUE_471);
    *P_LVALUE_471 = PrtCloneValue((&P_LIT_BOOLEAN_7));
    
    PRT_VALUE** P_LVALUE_472 = &(P_VAR_index_1);
    PrtFreeValue(*P_LVALUE_472);
    *P_LVALUE_472 = PrtCloneValue((&P_LIT_INT32_57));
    
    while (PrtPrimGetBool((&P_LIT_BOOLEAN_8)))
    {
        PRT_VALUE** P_LVALUE_473 = &(PTMP_tmp15_5);
        PrtFreeValue(*P_LVALUE_473);
        *P_LVALUE_473 = PrtMkIntValue(PrtSeqSizeOf(p_this->varValues[1]));
        
        PRT_VALUE** P_LVALUE_474 = &(PTMP_tmp16_5);
        PrtFreeValue(*P_LVALUE_474);
        *P_LVALUE_474 = PrtMkBoolValue(PrtPrimGetInt(P_VAR_counter2_1) < PrtPrimGetInt(PTMP_tmp15_5));
        
        PRT_VALUE** P_LVALUE_475 = &(PTMP_tmp17_5);
        PrtFreeValue(*P_LVALUE_475);
        *P_LVALUE_475 = PrtCloneValue(PTMP_tmp16_5);
        
        if (PrtPrimGetBool(PTMP_tmp17_5))
        {
        }
        
        else
        {
            break;
            
        }
        
        
        PRT_VALUE** P_LVALUE_476 = &(P_VAR_counter3_1);
        PrtFreeValue(*P_LVALUE_476);
        *P_LVALUE_476 = PrtCloneValue((&P_LIT_INT32_57));
        
        while (PrtPrimGetBool((&P_LIT_BOOLEAN_8)))
        {
            PRT_VALUE** P_LVALUE_477 = &(PTMP_tmp18_5);
            PrtFreeValue(*P_LVALUE_477);
            *P_LVALUE_477 = PrtSeqGet(p_this->varValues[1], P_VAR_counter2_1);
            
            PRT_VALUE** P_LVALUE_478 = &(PTMP_tmp19_5);
            PrtFreeValue(*P_LVALUE_478);
            *P_LVALUE_478 = PrtMkIntValue(PrtSeqSizeOf(PTMP_tmp18_5));
            
            PRT_VALUE** P_LVALUE_479 = &(PTMP_tmp20_5);
            PrtFreeValue(*P_LVALUE_479);
            *P_LVALUE_479 = PrtMkBoolValue(PrtPrimGetInt(P_VAR_counter3_1) < PrtPrimGetInt(PTMP_tmp19_5));
            
            PRT_VALUE** P_LVALUE_480 = &(PTMP_tmp21_5);
            PrtFreeValue(*P_LVALUE_480);
            *P_LVALUE_480 = PrtCloneValue(PTMP_tmp20_5);
            
            if (PrtPrimGetBool(PTMP_tmp21_5))
            {
            }
            
            else
            {
                break;
                
            }
            
            
            PRT_VALUE** P_LVALUE_481 = &(PTMP_tmp22_5);
            PrtFreeValue(*P_LVALUE_481);
            *P_LVALUE_481 = PrtSeqGet(p_this->varValues[1], P_VAR_counter2_1);
            
            PRT_VALUE** P_LVALUE_482 = &(PTMP_tmp23_5);
            PrtFreeValue(*P_LVALUE_482);
            *P_LVALUE_482 = PrtSeqGet(PTMP_tmp22_5, P_VAR_counter3_1);
            
            PRT_VALUE** P_LVALUE_483 = &(PTMP_tmp24_4);
            PrtFreeValue(*P_LVALUE_483);
            *P_LVALUE_483 = PrtTupleGet(PTMP_tmp23_5, 0);
            
            PRT_VALUE** P_LVALUE_484 = &(PTMP_tmp25_4);
            PrtFreeValue(*P_LVALUE_484);
            *P_LVALUE_484 = PrtMkBoolValue(PrtIsEqualValue(PTMP_tmp24_4, (&P_LIT_INT32_58)));
            
            PRT_VALUE** P_LVALUE_485 = &(PTMP_tmp32_4);
            PrtFreeValue(*P_LVALUE_485);
            *P_LVALUE_485 = PrtCloneValue(PTMP_tmp25_4);
            
            if (PrtPrimGetBool(PTMP_tmp32_4))
            {
                PRT_VALUE** P_LVALUE_486 = &(PTMP_tmp26_4);
                PrtFreeValue(*P_LVALUE_486);
                *P_LVALUE_486 = PrtSeqGet(p_this->varValues[1], P_VAR_counter2_1);
                
                PRT_VALUE** P_LVALUE_487 = &(PTMP_tmp27_4);
                PrtFreeValue(*P_LVALUE_487);
                *P_LVALUE_487 = PrtSeqGet(PTMP_tmp26_4, P_VAR_counter3_1);
                
                PRT_VALUE** P_LVALUE_488 = &(PTMP_tmp28_4);
                PrtFreeValue(*P_LVALUE_488);
                *P_LVALUE_488 = PrtTupleGet(PTMP_tmp27_4, 1);
                
                PRT_VALUE** P_LVALUE_489 = &(PTMP_tmp29_4);
                PrtFreeValue(*P_LVALUE_489);
                *P_LVALUE_489 = PrtTupleGet(PTMP_tmp28_4, 3);
                
                PRT_VALUE** P_LVALUE_490 = &(PTMP_tmp30_4);
                PrtFreeValue(*P_LVALUE_490);
                *P_LVALUE_490 = ((_P_GEN_funargs[0] = &(PTMP_tmp29_4)), (_P_GEN_funval = P_readBuffer_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp29_4), PTMP_tmp29_4 = NULL), (_P_GEN_funval));
                if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                    goto p_return_9;
                }
                if (p_this->isHalted == PRT_TRUE) {
                    PrtFreeValue(_P_GEN_retval);
                    _P_GEN_retval = NULL;
                    goto p_return_9;
                }
                
                PRT_VALUE** P_LVALUE_491 = &(PTMP_tmp31_4);
                PrtFreeValue(*P_LVALUE_491);
                *P_LVALUE_491 = PrtMkBoolValue(PrtIsEqualValue(PTMP_tmp30_4, (&P_LIT_INT32_58)));
                
                PRT_VALUE** P_LVALUE_492 = &(PTMP_tmp32_4);
                PrtFreeValue(*P_LVALUE_492);
                *P_LVALUE_492 = PrtCloneValue(PTMP_tmp31_4);
                
            }
            
            
            PRT_VALUE** P_LVALUE_493 = &(PTMP_tmp41_2);
            PrtFreeValue(*P_LVALUE_493);
            *P_LVALUE_493 = PrtCloneValue(PTMP_tmp32_4);
            
            if (PrtPrimGetBool(PTMP_tmp41_2))
            {
                PRT_VALUE** P_LVALUE_494 = &(PTMP_tmp33_3);
                PrtFreeValue(*P_LVALUE_494);
                *P_LVALUE_494 = PrtTupleGet(P_VAR_srcChanID, 3);
                
                PRT_VALUE** P_LVALUE_495 = &(PTMP_tmp34_3);
                PrtFreeValue(*P_LVALUE_495);
                *P_LVALUE_495 = ((_P_GEN_funargs[0] = &(PTMP_tmp33_3)), (_P_GEN_funval = P_readBuffer_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp33_3), PTMP_tmp33_3 = NULL), (_P_GEN_funval));
                if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                    goto p_return_9;
                }
                if (p_this->isHalted == PRT_TRUE) {
                    PrtFreeValue(_P_GEN_retval);
                    _P_GEN_retval = NULL;
                    goto p_return_9;
                }
                
                PRT_VALUE** P_LVALUE_496 = &(PTMP_tmp35_3);
                PrtFreeValue(*P_LVALUE_496);
                *P_LVALUE_496 = PrtSeqGet(p_this->varValues[1], P_VAR_counter2_1);
                
                PRT_VALUE** P_LVALUE_497 = &(PTMP_tmp36_3);
                PrtFreeValue(*P_LVALUE_497);
                *P_LVALUE_497 = PrtSeqGet(PTMP_tmp35_3, P_VAR_counter3_1);
                
                PRT_VALUE** P_LVALUE_498 = &(PTMP_tmp37_3);
                PrtFreeValue(*P_LVALUE_498);
                *P_LVALUE_498 = PrtTupleGet(PTMP_tmp36_3, 2);
                
                PRT_VALUE** P_LVALUE_499 = &(PTMP_tmp38_3);
                PrtFreeValue(*P_LVALUE_499);
                *P_LVALUE_499 = PrtTupleGet(PTMP_tmp37_3, 3);
                
                PRT_VALUE** P_LVALUE_500 = &(PTMP_tmp39_3);
                PrtFreeValue(*P_LVALUE_500);
                *P_LVALUE_500 = ((_P_GEN_funargs[0] = &(PTMP_tmp38_3)), (_P_GEN_funval = P_readBuffer_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp38_3), PTMP_tmp38_3 = NULL), (_P_GEN_funval));
                if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                    goto p_return_9;
                }
                if (p_this->isHalted == PRT_TRUE) {
                    PrtFreeValue(_P_GEN_retval);
                    _P_GEN_retval = NULL;
                    goto p_return_9;
                }
                
                PRT_VALUE** P_LVALUE_501 = &(PTMP_tmp40_2);
                PrtFreeValue(*P_LVALUE_501);
                *P_LVALUE_501 = PrtMkBoolValue(PrtIsEqualValue(PTMP_tmp34_3, PTMP_tmp39_3));
                
                PRT_VALUE** P_LVALUE_502 = &(PTMP_tmp41_2);
                PrtFreeValue(*P_LVALUE_502);
                *P_LVALUE_502 = PrtCloneValue(PTMP_tmp40_2);
                
            }
            
            
            if (PrtPrimGetBool(PTMP_tmp41_2))
            {
                PRT_VALUE** P_LVALUE_503 = &(P_VAR_flag1_1);
                PrtFreeValue(*P_LVALUE_503);
                *P_LVALUE_503 = PrtCloneValue((&P_LIT_BOOLEAN_8));
                
                PRT_VALUE** P_LVALUE_504 = &(PTMP_tmp42_2);
                PrtFreeValue(*P_LVALUE_504);
                *P_LVALUE_504 = PrtMkIntValue(PrtPrimGetInt(P_VAR_counter2_1) + PrtPrimGetInt((&P_LIT_INT32_58)));
                
                {
                    PRT_VALUE** P_LVALUE_505 = &(P_VAR_index_1);
                    PrtFreeValue(*P_LVALUE_505);
                    *P_LVALUE_505 = PTMP_tmp42_2;
                    PTMP_tmp42_2 = NULL;
                }
                
            }
            
            else
            {
            }
            
            
            PRT_VALUE** P_LVALUE_506 = &(PTMP_tmp43_2);
            PrtFreeValue(*P_LVALUE_506);
            *P_LVALUE_506 = PrtMkIntValue(PrtPrimGetInt(P_VAR_counter3_1) + PrtPrimGetInt((&P_LIT_INT32_58)));
            
            {
                PRT_VALUE** P_LVALUE_507 = &(P_VAR_counter3_1);
                PrtFreeValue(*P_LVALUE_507);
                *P_LVALUE_507 = PTMP_tmp43_2;
                PTMP_tmp43_2 = NULL;
            }
            
        }
        
        
        PRT_VALUE** P_LVALUE_508 = &(PTMP_tmp44_2);
        PrtFreeValue(*P_LVALUE_508);
        *P_LVALUE_508 = PrtMkIntValue(PrtPrimGetInt(P_VAR_counter2_1) + PrtPrimGetInt((&P_LIT_INT32_58)));
        
        {
            PRT_VALUE** P_LVALUE_509 = &(P_VAR_counter2_1);
            PrtFreeValue(*P_LVALUE_509);
            *P_LVALUE_509 = PTMP_tmp44_2;
            PTMP_tmp44_2 = NULL;
        }
        
    }
    
    
    PRT_VALUE** P_LVALUE_510 = &(PTMP_tmp45_2);
    PrtFreeValue(*P_LVALUE_510);
    *P_LVALUE_510 = PrtMkBoolValue(PrtIsEqualValue(P_VAR_flag1_1, (&P_LIT_BOOLEAN_8)));
    
    if (PrtPrimGetBool(PTMP_tmp45_2))
    {
        PRT_VALUE** P_LVALUE_511 = &(PTMP_tmp46_2);
        PrtFreeValue(*P_LVALUE_511);
        *P_LVALUE_511 = PrtMkIntValue(PrtPrimGetInt(P_VAR_index_1) - PrtPrimGetInt((&P_LIT_INT32_58)));
        
        PRT_VALUE** P_LVALUE_512 = &(PTMP_tmp47_2);
        PrtFreeValue(*P_LVALUE_512);
        *P_LVALUE_512 = PrtSeqGet(p_this->varValues[1], PTMP_tmp46_2);
        
        PRT_VALUE** P_LVALUE_513 = &(PTMP_tmp48_2);
        PrtFreeValue(*P_LVALUE_513);
        *P_LVALUE_513 = PrtCloneValue(PTMP_tmp47_2);
        
        {
            PRT_VALUE** P_LVALUE_514 = &(P_VAR_targetChan);
            PrtFreeValue(*P_LVALUE_514);
            *P_LVALUE_514 = PTMP_tmp48_2;
            PTMP_tmp48_2 = NULL;
        }
        
        PRT_VALUE** P_LVALUE_515 = &(PTMP_tmp49_2);
        PrtFreeValue(*P_LVALUE_515);
        *P_LVALUE_515 = PrtMkIntValue(PrtSeqSizeOf(P_VAR_targetChan));
        
        PRT_VALUE** P_LVALUE_516 = &(PTMP_tmp50_2);
        PrtFreeValue(*P_LVALUE_516);
        *P_LVALUE_516 = PrtMkIntValue(PrtPrimGetInt(PTMP_tmp49_2) - PrtPrimGetInt((&P_LIT_INT32_58)));
        
        PRT_VALUE** P_LVALUE_517 = &(PTMP_tmp51_2);
        PrtFreeValue(*P_LVALUE_517);
        *P_LVALUE_517 = PrtCloneValue(P_VAR_mtuPara);
        
        PrtSeqInsertEx(P_VAR_targetChan, PTMP_tmp50_2, PTMP_tmp51_2, PRT_FALSE);
        *(&(PTMP_tmp51_2)) = NULL;
        
        PRT_VALUE** P_LVALUE_518 = &(PTMP_tmp52_2);
        PrtFreeValue(*P_LVALUE_518);
        *P_LVALUE_518 = PrtMkIntValue(PrtSeqSizeOf(p_this->varValues[1]));
        
        PRT_VALUE** P_LVALUE_519 = &(PTMP_tmp53_2);
        PrtFreeValue(*P_LVALUE_519);
        *P_LVALUE_519 = PrtMapGet(p_this->varValues[2], PTMP_tmp52_2);
        
        PRT_VALUE** P_LVALUE_520 = &(PTMP_tmp54_2);
        PrtFreeValue(*P_LVALUE_520);
        *P_LVALUE_520 = PrtCloneValue(PTMP_tmp53_2);
        
        {
            PRT_VALUE** P_LVALUE_521 = &(P_VAR_targetChanM);
            PrtFreeValue(*P_LVALUE_521);
            *P_LVALUE_521 = PTMP_tmp54_2;
            PTMP_tmp54_2 = NULL;
        }
        
        PRT_VALUE** P_LVALUE_522 = &(PTMP_tmp55_2);
        PrtFreeValue(*P_LVALUE_522);
        *P_LVALUE_522 = PrtCloneValue(P_VAR_targetChanM);
        
        PRT_VALUE** P_LVALUE_523 = &(PTMP_tmp56_2);
        PrtFreeValue(*P_LVALUE_523);
        *P_LVALUE_523 = PrtCloneValue((&P_EVENT_eChanGotoConnected.value));
        
        PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp55_2), PTMP_tmp56_2, 0);
        *(&(PTMP_tmp56_2)) = NULL;
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_9;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_9;
        }
        
        PRT_VALUE** P_LVALUE_524 = &(PTMP_tmp57_2);
        PrtFreeValue(*P_LVALUE_524);
        *P_LVALUE_524 = PrtTupleGet(*P_VAR_wReq_3, 0);
        
        PRT_VALUE** P_LVALUE_525 = &(PTMP_tmp58_2);
        PrtFreeValue(*P_LVALUE_525);
        *P_LVALUE_525 = PrtCloneValue(PTMP_tmp57_2);
        
        PRT_VALUE** P_LVALUE_526 = &(PTMP_tmp59_2);
        PrtFreeValue(*P_LVALUE_526);
        *P_LVALUE_526 = PrtCloneValue((&P_EVENT_eConfResp.value));
        
        PRT_VALUE** P_LVALUE_527 = &(PTMP_tmp60_2);
        PrtFreeValue(*P_LVALUE_527);
        *P_LVALUE_527 = PrtCloneValue((&P_LIT_BOOLEAN_8));
        
        PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp58_2), PTMP_tmp59_2, 1, &(PTMP_tmp60_2));
        *(&(PTMP_tmp59_2)) = NULL;
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_9;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_9;
        }
        
        goto p_return_9;
        
    }
    
    else
    {
    }
    
    
    PRT_VALUE** P_LVALUE_528 = &(PTMP_tmp61_2);
    PrtFreeValue(*P_LVALUE_528);
    *P_LVALUE_528 = PrtTupleGet(*P_VAR_wReq_3, 0);
    
    PRT_VALUE** P_LVALUE_529 = &(PTMP_tmp62_2);
    PrtFreeValue(*P_LVALUE_529);
    *P_LVALUE_529 = PrtCloneValue(PTMP_tmp61_2);
    
    PRT_VALUE** P_LVALUE_530 = &(PTMP_tmp63_2);
    PrtFreeValue(*P_LVALUE_530);
    *P_LVALUE_530 = PrtCloneValue((&P_EVENT_eConfResp.value));
    
    PRT_VALUE** P_LVALUE_531 = &(PTMP_tmp64_2);
    PrtFreeValue(*P_LVALUE_531);
    *P_LVALUE_531 = PrtCloneValue((&P_LIT_BOOLEAN_7));
    
    PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp62_2), PTMP_tmp63_2, 1, &(PTMP_tmp64_2));
    *(&(PTMP_tmp63_2)) = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_9;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_9;
    }
    
p_return_9: ;
    PrtFreeValue(P_VAR_hm); P_VAR_hm = NULL;
    PrtFreeValue(P_VAR_msub); P_VAR_msub = NULL;
    PrtFreeValue(P_VAR_srcChanID); P_VAR_srcChanID = NULL;
    PrtFreeValue(P_VAR_optPlist); P_VAR_optPlist = NULL;
    PrtFreeValue(P_VAR_mtuPara); P_VAR_mtuPara = NULL;
    PrtFreeValue(P_VAR_counter2_1); P_VAR_counter2_1 = NULL;
    PrtFreeValue(P_VAR_flag1_1); P_VAR_flag1_1 = NULL;
    PrtFreeValue(P_VAR_index_1); P_VAR_index_1 = NULL;
    PrtFreeValue(P_VAR_counter3_1); P_VAR_counter3_1 = NULL;
    PrtFreeValue(P_VAR_targetChan); P_VAR_targetChan = NULL;
    PrtFreeValue(P_VAR_targetChanM); P_VAR_targetChanM = NULL;
    PrtFreeValue(PTMP_tmp0_8); PTMP_tmp0_8 = NULL;
    PrtFreeValue(PTMP_tmp1_8); PTMP_tmp1_8 = NULL;
    PrtFreeValue(PTMP_tmp2_8); PTMP_tmp2_8 = NULL;
    PrtFreeValue(PTMP_tmp3_8); PTMP_tmp3_8 = NULL;
    PrtFreeValue(PTMP_tmp4_7); PTMP_tmp4_7 = NULL;
    PrtFreeValue(PTMP_tmp5_7); PTMP_tmp5_7 = NULL;
    PrtFreeValue(PTMP_tmp6_7); PTMP_tmp6_7 = NULL;
    PrtFreeValue(PTMP_tmp7_6); PTMP_tmp7_6 = NULL;
    PrtFreeValue(PTMP_tmp8_6); PTMP_tmp8_6 = NULL;
    PrtFreeValue(PTMP_tmp9_6); PTMP_tmp9_6 = NULL;
    PrtFreeValue(PTMP_tmp10_6); PTMP_tmp10_6 = NULL;
    PrtFreeValue(PTMP_tmp11_6); PTMP_tmp11_6 = NULL;
    PrtFreeValue(PTMP_tmp12_6); PTMP_tmp12_6 = NULL;
    PrtFreeValue(PTMP_tmp13_6); PTMP_tmp13_6 = NULL;
    PrtFreeValue(PTMP_tmp14_6); PTMP_tmp14_6 = NULL;
    PrtFreeValue(PTMP_tmp15_5); PTMP_tmp15_5 = NULL;
    PrtFreeValue(PTMP_tmp16_5); PTMP_tmp16_5 = NULL;
    PrtFreeValue(PTMP_tmp17_5); PTMP_tmp17_5 = NULL;
    PrtFreeValue(PTMP_tmp18_5); PTMP_tmp18_5 = NULL;
    PrtFreeValue(PTMP_tmp19_5); PTMP_tmp19_5 = NULL;
    PrtFreeValue(PTMP_tmp20_5); PTMP_tmp20_5 = NULL;
    PrtFreeValue(PTMP_tmp21_5); PTMP_tmp21_5 = NULL;
    PrtFreeValue(PTMP_tmp22_5); PTMP_tmp22_5 = NULL;
    PrtFreeValue(PTMP_tmp23_5); PTMP_tmp23_5 = NULL;
    PrtFreeValue(PTMP_tmp24_4); PTMP_tmp24_4 = NULL;
    PrtFreeValue(PTMP_tmp25_4); PTMP_tmp25_4 = NULL;
    PrtFreeValue(PTMP_tmp26_4); PTMP_tmp26_4 = NULL;
    PrtFreeValue(PTMP_tmp27_4); PTMP_tmp27_4 = NULL;
    PrtFreeValue(PTMP_tmp28_4); PTMP_tmp28_4 = NULL;
    PrtFreeValue(PTMP_tmp29_4); PTMP_tmp29_4 = NULL;
    PrtFreeValue(PTMP_tmp30_4); PTMP_tmp30_4 = NULL;
    PrtFreeValue(PTMP_tmp31_4); PTMP_tmp31_4 = NULL;
    PrtFreeValue(PTMP_tmp32_4); PTMP_tmp32_4 = NULL;
    PrtFreeValue(PTMP_tmp33_3); PTMP_tmp33_3 = NULL;
    PrtFreeValue(PTMP_tmp34_3); PTMP_tmp34_3 = NULL;
    PrtFreeValue(PTMP_tmp35_3); PTMP_tmp35_3 = NULL;
    PrtFreeValue(PTMP_tmp36_3); PTMP_tmp36_3 = NULL;
    PrtFreeValue(PTMP_tmp37_3); PTMP_tmp37_3 = NULL;
    PrtFreeValue(PTMP_tmp38_3); PTMP_tmp38_3 = NULL;
    PrtFreeValue(PTMP_tmp39_3); PTMP_tmp39_3 = NULL;
    PrtFreeValue(PTMP_tmp40_2); PTMP_tmp40_2 = NULL;
    PrtFreeValue(PTMP_tmp41_2); PTMP_tmp41_2 = NULL;
    PrtFreeValue(PTMP_tmp42_2); PTMP_tmp42_2 = NULL;
    PrtFreeValue(PTMP_tmp43_2); PTMP_tmp43_2 = NULL;
    PrtFreeValue(PTMP_tmp44_2); PTMP_tmp44_2 = NULL;
    PrtFreeValue(PTMP_tmp45_2); PTMP_tmp45_2 = NULL;
    PrtFreeValue(PTMP_tmp46_2); PTMP_tmp46_2 = NULL;
    PrtFreeValue(PTMP_tmp47_2); PTMP_tmp47_2 = NULL;
    PrtFreeValue(PTMP_tmp48_2); PTMP_tmp48_2 = NULL;
    PrtFreeValue(PTMP_tmp49_2); PTMP_tmp49_2 = NULL;
    PrtFreeValue(PTMP_tmp50_2); PTMP_tmp50_2 = NULL;
    PrtFreeValue(PTMP_tmp51_2); PTMP_tmp51_2 = NULL;
    PrtFreeValue(PTMP_tmp52_2); PTMP_tmp52_2 = NULL;
    PrtFreeValue(PTMP_tmp53_2); PTMP_tmp53_2 = NULL;
    PrtFreeValue(PTMP_tmp54_2); PTMP_tmp54_2 = NULL;
    PrtFreeValue(PTMP_tmp55_2); PTMP_tmp55_2 = NULL;
    PrtFreeValue(PTMP_tmp56_2); PTMP_tmp56_2 = NULL;
    PrtFreeValue(PTMP_tmp57_2); PTMP_tmp57_2 = NULL;
    PrtFreeValue(PTMP_tmp58_2); PTMP_tmp58_2 = NULL;
    PrtFreeValue(PTMP_tmp59_2); PTMP_tmp59_2 = NULL;
    PrtFreeValue(PTMP_tmp60_2); PTMP_tmp60_2 = NULL;
    PrtFreeValue(PTMP_tmp61_2); PTMP_tmp61_2 = NULL;
    PrtFreeValue(PTMP_tmp62_2); PTMP_tmp62_2 = NULL;
    PrtFreeValue(PTMP_tmp63_2); PTMP_tmp63_2 = NULL;
    PrtFreeValue(PTMP_tmp64_2); PTMP_tmp64_2 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_5 =
{
    NULL,
    &P_Anon_IMPL_5,
    &P_GEND_TYPE_NT2mNT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB
};


PRT_FUNDECL* P_ConnMachine_METHODS[] = { &P_FUNCTION_Anon_2, &P_FUNCTION_Anon_3, &P_FUNCTION_Anon_4, &P_FUNCTION_Anon_5 };

PRT_EVENTDECL* P_ConnMachine_RECV_INNER_1[] = { &P_EVENT_eChanConnected, &P_EVENT_eChanDead, &P_EVENT_eChanGotoConfig, &P_EVENT_eChanGotoConnected, &P_EVENT_eChanStarted, &P_EVENT_eComposetFix, &P_EVENT_eComposetHdr, &P_EVENT_eComposetMsg, &P_EVENT_eComposetPara, &P_EVENT_eComposetPlist, &P_EVENT_eComposetVar, &P_EVENT_eConfReq, &P_EVENT_eConfResp, &P_EVENT_eConnReq, &P_EVENT_eConnResp, &P_EVENT_eGetDefaultValueResp, &P_EVENT_eL2CmdReq, &P_EVENT_eParsetFix, &P_EVENT_eParsetHdr, &P_EVENT_eParsetMsg, &P_EVENT_eParsetPara, &P_EVENT_eParsetPlist, &P_EVENT_eParsetVar, &P_EVENT_eSpecGetDefaultValueReq, &P_EVENT_eStartTimer, &P_EVENT_eTimeOut, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_ConnMachine_RECV_1 =
{
    27U,
    P_ConnMachine_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_ConnMachine_SEND_INNER[] = { &P_EVENT_eChanConnected, &P_EVENT_eChanDead, &P_EVENT_eChanGotoConfig, &P_EVENT_eChanGotoConnected, &P_EVENT_eChanStarted, &P_EVENT_eComposetFix, &P_EVENT_eComposetHdr, &P_EVENT_eComposetMsg, &P_EVENT_eComposetPara, &P_EVENT_eComposetPlist, &P_EVENT_eComposetVar, &P_EVENT_eConfReq, &P_EVENT_eConfResp, &P_EVENT_eConnReq, &P_EVENT_eConnResp, &P_EVENT_eGetDefaultValueResp, &P_EVENT_eL2CmdReq, &P_EVENT_eParsetFix, &P_EVENT_eParsetHdr, &P_EVENT_eParsetMsg, &P_EVENT_eParsetPara, &P_EVENT_eParsetPlist, &P_EVENT_eParsetVar, &P_EVENT_eSpecGetDefaultValueReq, &P_EVENT_eStartTimer, &P_EVENT_eTimeOut, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_ConnMachine_SEND =
{
    27U,
    P_ConnMachine_SEND_INNER,
    NULL
};

PRT_UINT32 P_ConnMachine_CREATES_ARR[] = { 3 };
PRT_INTERFACESETDECL P_ConnMachine_CREATES = { 1, P_ConnMachine_CREATES_ARR };
PRT_MACHINEDECL P_MACHINE_ConnMachine = 
{
    1U,
    "ConnMachine",
    &P_EVENTSET_ConnMachine_RECV_1,
    &P_EVENTSET_ConnMachine_SEND,
    &P_ConnMachine_CREATES,
    3U,
    2U,
    4U,
    4294967295U,
    0U,
    P_ConnMachine_VARS,
    P_ConnMachine_STATES,
    P_ConnMachine_METHODS
};

PRT_VARDECL P_ClientMachine_VARS[] = {
    { "InitServer", &P_GEND_TYPE_R_1 },
    { "ConnServer", &P_GEND_TYPE_R },
    { "vmsgL2Cmd", &P_GEND_TYPE_NT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB }
};

PRT_EVENTDECL* P_Init_DEFERS_INNER_2[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DEFERS_2 =
{
    0U,
    P_Init_DEFERS_INNER_2,
    NULL
};

PRT_EVENTDECL* P_Init_TRANS_INNER_2[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_TRANS_2 =
{
    0U,
    P_Init_TRANS_INNER_2,
    NULL
};

PRT_EVENTDECL* P_Init_DOS_INNER_2[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DOS_2 =
{
    0U,
    P_Init_DOS_INNER_2,
    NULL
};

#define P_STATE_ClientMachine_Init \
{ \
    "ClientMachine.Init", \
    0U, \
    0U, \
    &P_EVENTSET_Init_DEFERS_2, \
    &P_EVENTSET_Init_TRANS_2, \
    &P_EVENTSET_Init_DOS_2, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon_6, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_SendReqs_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_SendReqs_DEFERS =
{
    0U,
    P_SendReqs_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_SendReqs_TRANS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_SendReqs_TRANS =
{
    0U,
    P_SendReqs_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_SendReqs_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_SendReqs_DOS =
{
    0U,
    P_SendReqs_DOS_INNER,
    NULL
};

#define P_STATE_ClientMachine_SendReqs \
{ \
    "ClientMachine.SendReqs", \
    0U, \
    0U, \
    &P_EVENTSET_SendReqs_DEFERS, \
    &P_EVENTSET_SendReqs_TRANS, \
    &P_EVENTSET_SendReqs_DOS, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon_7, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_WaitForReply_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_WaitForReply_DEFERS =
{
    0U,
    P_WaitForReply_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_WaitForReply_TRANS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_WaitForReply_TRANS =
{
    0U,
    P_WaitForReply_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_WaitForReply_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_WaitForReply_DOS =
{
    0U,
    P_WaitForReply_DOS_INNER,
    NULL
};

#define P_STATE_ClientMachine_WaitForReply \
{ \
    "ClientMachine.WaitForReply", \
    0U, \
    0U, \
    &P_EVENTSET_WaitForReply_DEFERS, \
    &P_EVENTSET_WaitForReply_TRANS, \
    &P_EVENTSET_WaitForReply_DOS, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon_8, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_DeadState_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_DeadState_DEFERS =
{
    0U,
    P_DeadState_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_DeadState_TRANS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_DeadState_TRANS =
{
    0U,
    P_DeadState_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_DeadState_DOS_INNER[] = { &P_EVENT_eConfResp, &P_EVENT_eConnResp, &P_EVENT_eGetDefaultValueResp };
PRT_EVENTSETDECL P_EVENTSET_DeadState_DOS =
{
    3U,
    P_DeadState_DOS_INNER,
    NULL
};

PRT_DODECL P_DOS_2[] =
{
    { 3, &P_EVENT_eConfResp, NULL },
    { 3, &P_EVENT_eConnResp, NULL },
    { 3, &P_EVENT_eGetDefaultValueResp, NULL }
};

#define P_STATE_ClientMachine_DeadState \
{ \
    "ClientMachine.DeadState", \
    0U, \
    3U, \
    &P_EVENTSET_DeadState_DEFERS, \
    &P_EVENTSET_DeadState_TRANS, \
    &P_EVENTSET_DeadState_DOS, \
    NULL, \
    P_DOS_2, \
    &_P_NO_OP, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_ClientMachine_STATES[] = { P_STATE_ClientMachine_Init, P_STATE_ClientMachine_SendReqs, P_STATE_ClientMachine_WaitForReply, P_STATE_ClientMachine_DeadState };

PRT_VALUE* P_Anon_IMPL_6(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_input_1 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_9 = NULL;
    PRT_VALUE* PTMP_tmp1_9 = NULL;
    PRT_VALUE* PTMP_tmp2_9 = NULL;
    PRT_VALUE* PTMP_tmp3_9 = NULL;
    PRT_VALUE* PTMP_tmp4_8 = NULL;
    PRT_VALUE* PTMP_tmp5_8 = NULL;
    PRT_VALUE* PTMP_tmp6_8 = NULL;
    PRT_VALUE* PTMP_tmp7_7 = NULL;
    PRT_VALUE* PTMP_tmp8_7 = NULL;
    PRT_VALUE* PTMP_tmp9_7 = NULL;
    PRT_VALUE* P_VAR_P_payload = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_60 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE** P_LVALUE_532 = &(PTMP_tmp0_9);
    PrtFreeValue(*P_LVALUE_532);
    *P_LVALUE_532 = PrtTupleGet(*P_VAR_input_1, 0);
    
    PRT_VALUE** P_LVALUE_533 = &(PTMP_tmp1_9);
    PrtFreeValue(*P_LVALUE_533);
    *P_LVALUE_533 = PrtCloneValue(PTMP_tmp0_9);
    
    {
        PRT_VALUE** P_LVALUE_534 = &(p_this->varValues[0]);
        PrtFreeValue(*P_LVALUE_534);
        *P_LVALUE_534 = PTMP_tmp1_9;
        PTMP_tmp1_9 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_535 = &(PTMP_tmp2_9);
    PrtFreeValue(*P_LVALUE_535);
    *P_LVALUE_535 = PrtTupleGet(*P_VAR_input_1, 1);
    
    PRT_VALUE** P_LVALUE_536 = &(PTMP_tmp3_9);
    PrtFreeValue(*P_LVALUE_536);
    *P_LVALUE_536 = PrtCloneValue(PTMP_tmp2_9);
    
    {
        PRT_VALUE** P_LVALUE_537 = &(p_this->varValues[1]);
        PrtFreeValue(*P_LVALUE_537);
        *P_LVALUE_537 = PTMP_tmp3_9;
        PTMP_tmp3_9 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_538 = &(PTMP_tmp4_8);
    PrtFreeValue(*P_LVALUE_538);
    *P_LVALUE_538 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_539 = &(PTMP_tmp5_8);
    PrtFreeValue(*P_LVALUE_539);
    *P_LVALUE_539 = PrtCloneValue((&P_EVENT_eSpecGetDefaultValueReq.value));
    
    PRT_VALUE** P_LVALUE_540 = &(PTMP_tmp6_8);
    PrtFreeValue(*P_LVALUE_540);
    *P_LVALUE_540 = PrtCloneValue((p_this->id));
    
    PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp4_8), PTMP_tmp5_8, 1, &(PTMP_tmp6_8));
    *(&(PTMP_tmp5_8)) = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_10;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_10;
    }
    
    PRT_UINT32 P_allowedEventIds[] = { 2 };
    PrtFreeValue(P_VAR_P_payload); P_VAR_P_payload = NULL;
    PRT_UINT32 P_eventId = PrtReceiveAsync(1U, P_allowedEventIds, &P_VAR_P_payload);
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_10;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_10;
    }
    switch (P_eventId) {
        case 2: {
            PRT_VALUE** P_VAR_resp = &P_VAR_P_payload;
            PRT_VALUE P_LIT_INT32_59 = { PRT_VALUE_KIND_INT, { .nt = 18 } };
                        PRT_VALUE** P_LVALUE_541 = &(PTMP_tmp7_7);
            PrtFreeValue(*P_LVALUE_541);
            *P_LVALUE_541 = PrtSeqGet(*P_VAR_resp, (&P_LIT_INT32_59));
            
            PRT_VALUE** P_LVALUE_542 = &(PTMP_tmp8_7);
            PrtFreeValue(*P_LVALUE_542);
            *P_LVALUE_542 = PrtCloneValue(PrtCastValue(PrtCloneValue(PTMP_tmp7_7), &P_GEND_TYPE_NT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB));
            
            {
                PRT_VALUE** P_LVALUE_543 = &(p_this->varValues[2]);
                PrtFreeValue(*P_LVALUE_543);
                *P_LVALUE_543 = PTMP_tmp8_7;
                PTMP_tmp8_7 = NULL;
            }
            
            p_return_11: ;
} break;
        default: {
            PrtAssert(PRT_FALSE, "receive returned unhandled event");
        } break;
    }
    PrtFreeValue(P_VAR_P_payload); P_VAR_P_payload = NULL;
    
    PRT_VALUE** P_LVALUE_544 = &(PTMP_tmp9_7);
    PrtFreeValue(*P_LVALUE_544);
    *P_LVALUE_544 = PrtCloneValue((&P_LIT_INT32_60));
    
    PrtGoto(p_this, 1U, 1, &(PTMP_tmp9_7));
    
p_return_10: ;
    PrtFreeValue(PTMP_tmp0_9); PTMP_tmp0_9 = NULL;
    PrtFreeValue(PTMP_tmp1_9); PTMP_tmp1_9 = NULL;
    PrtFreeValue(PTMP_tmp2_9); PTMP_tmp2_9 = NULL;
    PrtFreeValue(PTMP_tmp3_9); PTMP_tmp3_9 = NULL;
    PrtFreeValue(PTMP_tmp4_8); PTMP_tmp4_8 = NULL;
    PrtFreeValue(PTMP_tmp5_8); PTMP_tmp5_8 = NULL;
    PrtFreeValue(PTMP_tmp6_8); PTMP_tmp6_8 = NULL;
    PrtFreeValue(PTMP_tmp7_7); PTMP_tmp7_7 = NULL;
    PrtFreeValue(PTMP_tmp8_7); PTMP_tmp8_7 = NULL;
    PrtFreeValue(PTMP_tmp9_7); PTMP_tmp9_7 = NULL;
    PrtFreeValue(P_VAR_P_payload); P_VAR_P_payload = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_6 =
{
    NULL,
    &P_Anon_IMPL_6,
    &P_GEND_TYPE_NT2RR
};


PRT_VALUE* P_Anon_IMPL_7(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_IsConn = argRefs[0];
    PRT_VALUE* P_VAR_request = PrtMkDefaultValue(&P_GEND_TYPE_NT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB);
    PRT_VALUE* P_VAR_cvmsgConnReq = PrtMkDefaultValue(&P_GEND_TYPE_NT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB);
    PRT_VALUE* P_VAR_cvmsgConfReq = PrtMkDefaultValue(&P_GEND_TYPE_NT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB);
    PRT_VALUE* P_VAR_cvmsgoptPlist = PrtMkDefaultValue(&P_GEND_TYPE_NT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB);
    PRT_VALUE* PTMP_tmp0_10 = NULL;
    PRT_VALUE* PTMP_tmp1_10 = NULL;
    PRT_VALUE* PTMP_tmp2_10 = NULL;
    PRT_VALUE* PTMP_tmp3_10 = NULL;
    PRT_VALUE* PTMP_tmp4_9 = NULL;
    PRT_VALUE* PTMP_tmp5_9 = NULL;
    PRT_VALUE* PTMP_tmp6_9 = NULL;
    PRT_VALUE* PTMP_tmp7_8 = NULL;
    PRT_VALUE* PTMP_tmp8_8 = NULL;
    PRT_VALUE* PTMP_tmp9_8 = NULL;
    PRT_VALUE* PTMP_tmp10_7 = NULL;
    PRT_VALUE* PTMP_tmp11_7 = NULL;
    PRT_VALUE* PTMP_tmp12_7 = NULL;
    PRT_VALUE* PTMP_tmp13_7 = NULL;
    PRT_VALUE* PTMP_tmp14_7 = NULL;
    PRT_VALUE* PTMP_tmp15_6 = NULL;
    PRT_VALUE* PTMP_tmp16_6 = NULL;
    PRT_VALUE* PTMP_tmp17_6 = NULL;
    PRT_VALUE* PTMP_tmp18_6 = NULL;
    PRT_VALUE* PTMP_tmp19_6 = NULL;
    PRT_VALUE* PTMP_tmp20_6 = NULL;
    PRT_VALUE* PTMP_tmp21_6 = NULL;
    PRT_VALUE* PTMP_tmp22_6 = NULL;
    PRT_VALUE* PTMP_tmp23_6 = NULL;
    PRT_VALUE* PTMP_tmp24_5 = NULL;
    PRT_VALUE* PTMP_tmp25_5 = NULL;
    PRT_VALUE* PTMP_tmp26_5 = NULL;
    PRT_VALUE* PTMP_tmp27_5 = NULL;
    PRT_VALUE* PTMP_tmp28_5 = NULL;
    PRT_VALUE* PTMP_tmp29_5 = NULL;
    PRT_VALUE* PTMP_tmp30_5 = NULL;
    PRT_VALUE* PTMP_tmp31_5 = NULL;
    PRT_VALUE* PTMP_tmp32_5 = NULL;
    PRT_VALUE* PTMP_tmp33_4 = NULL;
    PRT_VALUE* PTMP_tmp34_4 = NULL;
    PRT_VALUE* PTMP_tmp35_4 = NULL;
    PRT_VALUE* PTMP_tmp36_4 = NULL;
    PRT_VALUE* PTMP_tmp37_4 = NULL;
    PRT_VALUE* PTMP_tmp38_4 = NULL;
    PRT_VALUE* PTMP_tmp39_4 = NULL;
    PRT_VALUE* PTMP_tmp40_3 = NULL;
    PRT_VALUE* PTMP_tmp41_3 = NULL;
    PRT_VALUE* PTMP_tmp42_3 = NULL;
    PRT_VALUE* PTMP_tmp43_3 = NULL;
    PRT_VALUE* PTMP_tmp44_3 = NULL;
    PRT_VALUE* PTMP_tmp45_3 = NULL;
    PRT_VALUE* PTMP_tmp46_3 = NULL;
    PRT_VALUE* PTMP_tmp47_3 = NULL;
    PRT_VALUE* PTMP_tmp48_3 = NULL;
    PRT_VALUE* PTMP_tmp49_3 = NULL;
    PRT_VALUE* PTMP_tmp50_3 = NULL;
    PRT_VALUE* PTMP_tmp51_3 = NULL;
    PRT_VALUE* PTMP_tmp52_3 = NULL;
    PRT_VALUE* PTMP_tmp53_3 = NULL;
    PRT_VALUE* PTMP_tmp54_3 = NULL;
    PRT_VALUE* PTMP_tmp55_3 = NULL;
    PRT_VALUE* PTMP_tmp56_3 = NULL;
    PRT_VALUE* PTMP_tmp57_3 = NULL;
    PRT_VALUE* PTMP_tmp58_3 = NULL;
    PRT_VALUE* PTMP_tmp59_3 = NULL;
    PRT_VALUE* PTMP_tmp60_3 = NULL;
    PRT_VALUE* PTMP_tmp61_3 = NULL;
    PRT_VALUE* PTMP_tmp62_3 = NULL;
    PRT_VALUE* PTMP_tmp63_3 = NULL;
    PRT_VALUE* PTMP_tmp64_3 = NULL;
    PRT_VALUE* PTMP_tmp65_2 = NULL;
    PRT_VALUE* PTMP_tmp66_2 = NULL;
    PRT_VALUE* PTMP_tmp67_2 = NULL;
    PRT_VALUE* PTMP_tmp68_2 = NULL;
    PRT_VALUE* PTMP_tmp69_2 = NULL;
    PRT_VALUE* PTMP_tmp70_2 = NULL;
    PRT_VALUE* PTMP_tmp71_2 = NULL;
    PRT_VALUE* PTMP_tmp72_2 = NULL;
    PRT_VALUE* PTMP_tmp73_2 = NULL;
    PRT_VALUE* PTMP_tmp74_2 = NULL;
    PRT_VALUE* PTMP_tmp75_2 = NULL;
    PRT_VALUE* PTMP_tmp76_2 = NULL;
    PRT_VALUE* PTMP_tmp77_2 = NULL;
    PRT_VALUE* PTMP_tmp78_2 = NULL;
    PRT_VALUE* PTMP_tmp79_2 = NULL;
    PRT_VALUE* PTMP_tmp80_2 = NULL;
    PRT_VALUE* PTMP_tmp81_2 = NULL;
    PRT_VALUE* PTMP_tmp82_2 = NULL;
    PRT_VALUE* PTMP_tmp83_2 = NULL;
    PRT_VALUE* PTMP_tmp84_2 = NULL;
    PRT_VALUE* PTMP_tmp85_2 = NULL;
    PRT_VALUE* PTMP_tmp86_2 = NULL;
    PRT_VALUE* PTMP_tmp87_2 = NULL;
    PRT_VALUE* PTMP_tmp88_2 = NULL;
    PRT_VALUE* PTMP_tmp89_2 = NULL;
    PRT_VALUE* PTMP_tmp90_2 = NULL;
    PRT_VALUE* PTMP_tmp91_2 = NULL;
    PRT_VALUE* PTMP_tmp92_2 = NULL;
    PRT_VALUE* PTMP_tmp93_1 = NULL;
    PRT_VALUE* PTMP_tmp94_1 = NULL;
    PRT_VALUE* PTMP_tmp95_1 = NULL;
    PRT_VALUE* PTMP_tmp96_1 = NULL;
    PRT_VALUE* PTMP_tmp97_1 = NULL;
    PRT_VALUE* PTMP_tmp98_1 = NULL;
    PRT_VALUE* PTMP_tmp99_1 = NULL;
    PRT_VALUE* PTMP_tmp100_1 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_61 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE P_LIT_INT32_62 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE** P_LVALUE_545 = &(P_VAR_request);
    PrtFreeValue(*P_LVALUE_545);
    *P_LVALUE_545 = PrtCloneValue(p_this->varValues[2]);
    
    PRT_VALUE** P_LVALUE_546 = &(PTMP_tmp0_10);
    PrtFreeValue(*P_LVALUE_546);
    *P_LVALUE_546 = PrtTupleGet(P_VAR_request, 6);
    
    PRT_VALUE** P_LVALUE_547 = &(PTMP_tmp1_10);
    PrtFreeValue(*P_LVALUE_547);
    *P_LVALUE_547 = PrtTupleGet(PTMP_tmp0_10, 1);
    
    PRT_VALUE** P_LVALUE_548 = &(PTMP_tmp2_10);
    PrtFreeValue(*P_LVALUE_548);
    *P_LVALUE_548 = PrtSeqGet(PTMP_tmp1_10, (&P_LIT_INT32_61));
    
    PRT_VALUE** P_LVALUE_549 = &(PTMP_tmp3_10);
    PrtFreeValue(*P_LVALUE_549);
    *P_LVALUE_549 = PrtTupleGet(PTMP_tmp2_10, 1);
    
    PRT_VALUE** P_LVALUE_550 = &(PTMP_tmp4_9);
    PrtFreeValue(*P_LVALUE_550);
    *P_LVALUE_550 = PrtCloneValue(PrtCastValue(PrtCloneValue(PTMP_tmp3_10), &P_GEND_TYPE_NT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB));
    
    {
        PRT_VALUE** P_LVALUE_551 = &(P_VAR_cvmsgConnReq);
        PrtFreeValue(*P_LVALUE_551);
        *P_LVALUE_551 = PTMP_tmp4_9;
        PTMP_tmp4_9 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_552 = &(PTMP_tmp5_9);
    PrtFreeValue(*P_LVALUE_552);
    *P_LVALUE_552 = PrtTupleGet(P_VAR_request, 6);
    
    PRT_VALUE** P_LVALUE_553 = &(PTMP_tmp6_9);
    PrtFreeValue(*P_LVALUE_553);
    *P_LVALUE_553 = PrtTupleGet(PTMP_tmp5_9, 1);
    
    PRT_VALUE** P_LVALUE_554 = &(PTMP_tmp7_8);
    PrtFreeValue(*P_LVALUE_554);
    *P_LVALUE_554 = PrtSeqGet(PTMP_tmp6_9, (&P_LIT_INT32_62));
    
    PRT_VALUE** P_LVALUE_555 = &(PTMP_tmp8_8);
    PrtFreeValue(*P_LVALUE_555);
    *P_LVALUE_555 = PrtTupleGet(PTMP_tmp7_8, 1);
    
    PRT_VALUE** P_LVALUE_556 = &(PTMP_tmp9_8);
    PrtFreeValue(*P_LVALUE_556);
    *P_LVALUE_556 = PrtCloneValue(PrtCastValue(PrtCloneValue(PTMP_tmp8_8), &P_GEND_TYPE_NT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB));
    
    {
        PRT_VALUE** P_LVALUE_557 = &(P_VAR_cvmsgConfReq);
        PrtFreeValue(*P_LVALUE_557);
        *P_LVALUE_557 = PTMP_tmp9_8;
        PTMP_tmp9_8 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_558 = &(PTMP_tmp10_7);
    PrtFreeValue(*P_LVALUE_558);
    *P_LVALUE_558 = PrtTupleGet(P_VAR_cvmsgConfReq, 5);
    
    PRT_VALUE** P_LVALUE_559 = &(PTMP_tmp11_7);
    PrtFreeValue(*P_LVALUE_559);
    *P_LVALUE_559 = PrtTupleGet(PTMP_tmp10_7, 1);
    
    PRT_VALUE** P_LVALUE_560 = &(PTMP_tmp12_7);
    PrtFreeValue(*P_LVALUE_560);
    *P_LVALUE_560 = PrtCloneValue(PrtCastValue(PrtCloneValue(PTMP_tmp11_7), &P_GEND_TYPE_NT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB));
    
    {
        PRT_VALUE** P_LVALUE_561 = &(P_VAR_cvmsgoptPlist);
        PrtFreeValue(*P_LVALUE_561);
        *P_LVALUE_561 = PTMP_tmp12_7;
        PTMP_tmp12_7 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_562 = &(PTMP_tmp13_7);
    PrtFreeValue(*P_LVALUE_562);
    *P_LVALUE_562 = PrtTupleGet(P_VAR_cvmsgConnReq, 3);
    
    PRT_VALUE** P_LVALUE_563 = &(PTMP_tmp14_7);
    PrtFreeValue(*P_LVALUE_563);
    *P_LVALUE_563 = PrtSeqGet(PTMP_tmp13_7, (&P_LIT_INT32_61));
    
    PRT_VALUE** P_LVALUE_564 = &(PTMP_tmp15_6);
    PrtFreeValue(*P_LVALUE_564);
    *P_LVALUE_564 = PrtTupleGet(PTMP_tmp14_7, 0);
    
    PRT_VALUE** P_LVALUE_565 = &(PTMP_tmp16_6);
    PrtFreeValue(*P_LVALUE_565);
    *P_LVALUE_565 = PrtTupleGet(P_VAR_cvmsgConnReq, 3);
    
    PRT_VALUE** P_LVALUE_566 = &(PTMP_tmp17_6);
    PrtFreeValue(*P_LVALUE_566);
    *P_LVALUE_566 = PrtSeqGet(PTMP_tmp16_6, (&P_LIT_INT32_61));
    
    PRT_VALUE** P_LVALUE_567 = &(PTMP_tmp18_6);
    PrtFreeValue(*P_LVALUE_567);
    *P_LVALUE_567 = PrtTupleGet(PTMP_tmp17_6, 1);
    
    PRT_VALUE** P_LVALUE_568 = &(PTMP_tmp19_6);
    PrtFreeValue(*P_LVALUE_568);
    *P_LVALUE_568 = PrtMkIntValue(PrtPrimGetInt(PTMP_tmp18_6) + PrtPrimGetInt((&P_LIT_INT32_62)));
    
    PRT_VALUE** P_LVALUE_569 = &(PTMP_tmp20_6);
    PrtFreeValue(*P_LVALUE_569);
    *P_LVALUE_569 = ((_P_GEN_funargs[0] = &(PTMP_tmp15_6)), (_P_GEN_funargs[1] = &(PTMP_tmp19_6)), (_P_GEN_funval = P_writeBuffer_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp15_6), PTMP_tmp15_6 = NULL), (PrtFreeValue(PTMP_tmp19_6), PTMP_tmp19_6 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_12;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_12;
    }
    
    {
        PRT_VALUE** P_LVALUE_570 = &(*(PrtTupleGetLValue(*(PrtSeqGetLValue(*(PrtTupleGetLValue(P_VAR_cvmsgConnReq, 3)), (&P_LIT_INT32_61))), 3)));
        PrtFreeValue(*P_LVALUE_570);
        *P_LVALUE_570 = PTMP_tmp20_6;
        PTMP_tmp20_6 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_571 = &(PTMP_tmp21_6);
    PrtFreeValue(*P_LVALUE_571);
    *P_LVALUE_571 = PrtTupleGet(P_VAR_cvmsgConnReq, 3);
    
    PRT_VALUE** P_LVALUE_572 = &(PTMP_tmp22_6);
    PrtFreeValue(*P_LVALUE_572);
    *P_LVALUE_572 = PrtSeqGet(PTMP_tmp21_6, (&P_LIT_INT32_62));
    
    PRT_VALUE** P_LVALUE_573 = &(PTMP_tmp23_6);
    PrtFreeValue(*P_LVALUE_573);
    *P_LVALUE_573 = PrtTupleGet(PTMP_tmp22_6, 0);
    
    PRT_VALUE** P_LVALUE_574 = &(PTMP_tmp24_5);
    PrtFreeValue(*P_LVALUE_574);
    *P_LVALUE_574 = PrtTupleGet(P_VAR_cvmsgConnReq, 3);
    
    PRT_VALUE** P_LVALUE_575 = &(PTMP_tmp25_5);
    PrtFreeValue(*P_LVALUE_575);
    *P_LVALUE_575 = PrtSeqGet(PTMP_tmp24_5, (&P_LIT_INT32_62));
    
    PRT_VALUE** P_LVALUE_576 = &(PTMP_tmp26_5);
    PrtFreeValue(*P_LVALUE_576);
    *P_LVALUE_576 = PrtTupleGet(PTMP_tmp25_5, 1);
    
    PRT_VALUE** P_LVALUE_577 = &(PTMP_tmp27_5);
    PrtFreeValue(*P_LVALUE_577);
    *P_LVALUE_577 = ((_P_GEN_funargs[0] = &(PTMP_tmp23_6)), (_P_GEN_funargs[1] = &(PTMP_tmp26_5)), (_P_GEN_funval = P_writeBuffer_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp23_6), PTMP_tmp23_6 = NULL), (PrtFreeValue(PTMP_tmp26_5), PTMP_tmp26_5 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_12;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_12;
    }
    
    {
        PRT_VALUE** P_LVALUE_578 = &(*(PrtTupleGetLValue(*(PrtSeqGetLValue(*(PrtTupleGetLValue(P_VAR_cvmsgConnReq, 3)), (&P_LIT_INT32_62))), 3)));
        PrtFreeValue(*P_LVALUE_578);
        *P_LVALUE_578 = PTMP_tmp27_5;
        PTMP_tmp27_5 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_579 = &(PTMP_tmp28_5);
    PrtFreeValue(*P_LVALUE_579);
    *P_LVALUE_579 = PrtCloneValue(PrtCastValue(PrtCloneValue(P_VAR_cvmsgConnReq), &P_GEND_TYPE_B));
    
    {
        PRT_VALUE** P_LVALUE_580 = &(*(PrtTupleGetLValue(*(PrtSeqGetLValue(*(PrtTupleGetLValue(*(PrtTupleGetLValue(P_VAR_request, 6)), 1)), (&P_LIT_INT32_61))), 1)));
        PrtFreeValue(*P_LVALUE_580);
        *P_LVALUE_580 = PTMP_tmp28_5;
        PTMP_tmp28_5 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_581 = &(PTMP_tmp29_5);
    PrtFreeValue(*P_LVALUE_581);
    *P_LVALUE_581 = PrtTupleGet(P_VAR_cvmsgConfReq, 5);
    
    PRT_VALUE** P_LVALUE_582 = &(PTMP_tmp30_5);
    PrtFreeValue(*P_LVALUE_582);
    *P_LVALUE_582 = PrtTupleGet(PTMP_tmp29_5, 0);
    
    PRT_VALUE** P_LVALUE_583 = &(PTMP_tmp31_5);
    PrtFreeValue(*P_LVALUE_583);
    *P_LVALUE_583 = PrtTupleGet(PTMP_tmp30_5, 0);
    
    PRT_VALUE** P_LVALUE_584 = &(PTMP_tmp32_5);
    PrtFreeValue(*P_LVALUE_584);
    *P_LVALUE_584 = PrtSeqGet(PTMP_tmp31_5, (&P_LIT_INT32_61));
    
    PRT_VALUE** P_LVALUE_585 = &(PTMP_tmp33_4);
    PrtFreeValue(*P_LVALUE_585);
    *P_LVALUE_585 = PrtTupleGet(PTMP_tmp32_5, 0);
    
    PRT_VALUE** P_LVALUE_586 = &(PTMP_tmp34_4);
    PrtFreeValue(*P_LVALUE_586);
    *P_LVALUE_586 = PrtTupleGet(P_VAR_cvmsgConfReq, 5);
    
    PRT_VALUE** P_LVALUE_587 = &(PTMP_tmp35_4);
    PrtFreeValue(*P_LVALUE_587);
    *P_LVALUE_587 = PrtTupleGet(PTMP_tmp34_4, 0);
    
    PRT_VALUE** P_LVALUE_588 = &(PTMP_tmp36_4);
    PrtFreeValue(*P_LVALUE_588);
    *P_LVALUE_588 = PrtTupleGet(PTMP_tmp35_4, 0);
    
    PRT_VALUE** P_LVALUE_589 = &(PTMP_tmp37_4);
    PrtFreeValue(*P_LVALUE_589);
    *P_LVALUE_589 = PrtSeqGet(PTMP_tmp36_4, (&P_LIT_INT32_61));
    
    PRT_VALUE** P_LVALUE_590 = &(PTMP_tmp38_4);
    PrtFreeValue(*P_LVALUE_590);
    *P_LVALUE_590 = PrtTupleGet(PTMP_tmp37_4, 1);
    
    PRT_VALUE** P_LVALUE_591 = &(PTMP_tmp39_4);
    PrtFreeValue(*P_LVALUE_591);
    *P_LVALUE_591 = ((_P_GEN_funargs[0] = &(PTMP_tmp33_4)), (_P_GEN_funargs[1] = &(PTMP_tmp38_4)), (_P_GEN_funval = P_writeBuffer_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp33_4), PTMP_tmp33_4 = NULL), (PrtFreeValue(PTMP_tmp38_4), PTMP_tmp38_4 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_12;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_12;
    }
    
    {
        PRT_VALUE** P_LVALUE_592 = &(*(PrtTupleGetLValue(*(PrtSeqGetLValue(*(PrtTupleGetLValue(*(PrtTupleGetLValue(*(PrtTupleGetLValue(P_VAR_cvmsgConfReq, 5)), 0)), 0)), (&P_LIT_INT32_61))), 3)));
        PrtFreeValue(*P_LVALUE_592);
        *P_LVALUE_592 = PTMP_tmp39_4;
        PTMP_tmp39_4 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_593 = &(PTMP_tmp40_3);
    PrtFreeValue(*P_LVALUE_593);
    *P_LVALUE_593 = PrtTupleGet(P_VAR_cvmsgoptPlist, 4);
    
    PRT_VALUE** P_LVALUE_594 = &(PTMP_tmp41_3);
    PrtFreeValue(*P_LVALUE_594);
    *P_LVALUE_594 = PrtTupleGet(PTMP_tmp40_3, 1);
    
    PRT_VALUE** P_LVALUE_595 = &(PTMP_tmp42_3);
    PrtFreeValue(*P_LVALUE_595);
    *P_LVALUE_595 = PrtSeqGet(PTMP_tmp41_3, (&P_LIT_INT32_61));
    
    PRT_VALUE** P_LVALUE_596 = &(PTMP_tmp43_3);
    PrtFreeValue(*P_LVALUE_596);
    *P_LVALUE_596 = PrtTupleGet(PTMP_tmp42_3, 1);
    
    PRT_VALUE** P_LVALUE_597 = &(PTMP_tmp44_3);
    PrtFreeValue(*P_LVALUE_597);
    *P_LVALUE_597 = PrtTupleGet(PTMP_tmp43_3, 0);
    
    PRT_VALUE** P_LVALUE_598 = &(PTMP_tmp45_3);
    PrtFreeValue(*P_LVALUE_598);
    *P_LVALUE_598 = PrtTupleGet(P_VAR_cvmsgoptPlist, 4);
    
    PRT_VALUE** P_LVALUE_599 = &(PTMP_tmp46_3);
    PrtFreeValue(*P_LVALUE_599);
    *P_LVALUE_599 = PrtTupleGet(PTMP_tmp45_3, 1);
    
    PRT_VALUE** P_LVALUE_600 = &(PTMP_tmp47_3);
    PrtFreeValue(*P_LVALUE_600);
    *P_LVALUE_600 = PrtSeqGet(PTMP_tmp46_3, (&P_LIT_INT32_61));
    
    PRT_VALUE** P_LVALUE_601 = &(PTMP_tmp48_3);
    PrtFreeValue(*P_LVALUE_601);
    *P_LVALUE_601 = PrtTupleGet(PTMP_tmp47_3, 1);
    
    PRT_VALUE** P_LVALUE_602 = &(PTMP_tmp49_3);
    PrtFreeValue(*P_LVALUE_602);
    *P_LVALUE_602 = PrtTupleGet(PTMP_tmp48_3, 1);
    
    PRT_VALUE** P_LVALUE_603 = &(PTMP_tmp50_3);
    PrtFreeValue(*P_LVALUE_603);
    *P_LVALUE_603 = ((_P_GEN_funargs[0] = &(PTMP_tmp44_3)), (_P_GEN_funargs[1] = &(PTMP_tmp49_3)), (_P_GEN_funval = P_writeBuffer_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp44_3), PTMP_tmp44_3 = NULL), (PrtFreeValue(PTMP_tmp49_3), PTMP_tmp49_3 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_12;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_12;
    }
    
    {
        PRT_VALUE** P_LVALUE_604 = &(*(PrtTupleGetLValue(*(PrtTupleGetLValue(*(PrtSeqGetLValue(*(PrtTupleGetLValue(*(PrtTupleGetLValue(P_VAR_cvmsgoptPlist, 4)), 1)), (&P_LIT_INT32_61))), 1)), 3)));
        PrtFreeValue(*P_LVALUE_604);
        *P_LVALUE_604 = PTMP_tmp50_3;
        PTMP_tmp50_3 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_605 = &(PTMP_tmp51_3);
    PrtFreeValue(*P_LVALUE_605);
    *P_LVALUE_605 = PrtTupleGet(P_VAR_cvmsgoptPlist, 4);
    
    PRT_VALUE** P_LVALUE_606 = &(PTMP_tmp52_3);
    PrtFreeValue(*P_LVALUE_606);
    *P_LVALUE_606 = PrtTupleGet(PTMP_tmp51_3, 1);
    
    PRT_VALUE** P_LVALUE_607 = &(PTMP_tmp53_3);
    PrtFreeValue(*P_LVALUE_607);
    *P_LVALUE_607 = PrtSeqGet(PTMP_tmp52_3, (&P_LIT_INT32_61));
    
    PRT_VALUE** P_LVALUE_608 = &(PTMP_tmp54_3);
    PrtFreeValue(*P_LVALUE_608);
    *P_LVALUE_608 = PrtTupleGet(PTMP_tmp53_3, 2);
    
    PRT_VALUE** P_LVALUE_609 = &(PTMP_tmp55_3);
    PrtFreeValue(*P_LVALUE_609);
    *P_LVALUE_609 = PrtTupleGet(PTMP_tmp54_3, 0);
    
    PRT_VALUE** P_LVALUE_610 = &(PTMP_tmp56_3);
    PrtFreeValue(*P_LVALUE_610);
    *P_LVALUE_610 = PrtTupleGet(P_VAR_cvmsgoptPlist, 4);
    
    PRT_VALUE** P_LVALUE_611 = &(PTMP_tmp57_3);
    PrtFreeValue(*P_LVALUE_611);
    *P_LVALUE_611 = PrtTupleGet(PTMP_tmp56_3, 1);
    
    PRT_VALUE** P_LVALUE_612 = &(PTMP_tmp58_3);
    PrtFreeValue(*P_LVALUE_612);
    *P_LVALUE_612 = PrtSeqGet(PTMP_tmp57_3, (&P_LIT_INT32_61));
    
    PRT_VALUE** P_LVALUE_613 = &(PTMP_tmp59_3);
    PrtFreeValue(*P_LVALUE_613);
    *P_LVALUE_613 = PrtTupleGet(PTMP_tmp58_3, 2);
    
    PRT_VALUE** P_LVALUE_614 = &(PTMP_tmp60_3);
    PrtFreeValue(*P_LVALUE_614);
    *P_LVALUE_614 = PrtTupleGet(PTMP_tmp59_3, 1);
    
    PRT_VALUE** P_LVALUE_615 = &(PTMP_tmp61_3);
    PrtFreeValue(*P_LVALUE_615);
    *P_LVALUE_615 = ((_P_GEN_funargs[0] = &(PTMP_tmp55_3)), (_P_GEN_funargs[1] = &(PTMP_tmp60_3)), (_P_GEN_funval = P_writeBuffer_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp55_3), PTMP_tmp55_3 = NULL), (PrtFreeValue(PTMP_tmp60_3), PTMP_tmp60_3 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_12;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_12;
    }
    
    {
        PRT_VALUE** P_LVALUE_616 = &(*(PrtTupleGetLValue(*(PrtTupleGetLValue(*(PrtSeqGetLValue(*(PrtTupleGetLValue(*(PrtTupleGetLValue(P_VAR_cvmsgoptPlist, 4)), 1)), (&P_LIT_INT32_61))), 2)), 3)));
        PrtFreeValue(*P_LVALUE_616);
        *P_LVALUE_616 = PTMP_tmp61_3;
        PTMP_tmp61_3 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_617 = &(PTMP_tmp62_3);
    PrtFreeValue(*P_LVALUE_617);
    *P_LVALUE_617 = PrtCloneValue(PrtCastValue(PrtCloneValue(P_VAR_cvmsgoptPlist), &P_GEND_TYPE_B));
    
    {
        PRT_VALUE** P_LVALUE_618 = &(*(PrtTupleGetLValue(*(PrtTupleGetLValue(P_VAR_cvmsgConfReq, 5)), 1)));
        PrtFreeValue(*P_LVALUE_618);
        *P_LVALUE_618 = PTMP_tmp62_3;
        PTMP_tmp62_3 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_619 = &(PTMP_tmp63_3);
    PrtFreeValue(*P_LVALUE_619);
    *P_LVALUE_619 = PrtTupleGet(P_VAR_cvmsgConfReq, 5);
    
    PRT_VALUE** P_LVALUE_620 = &(PTMP_tmp64_3);
    PrtFreeValue(*P_LVALUE_620);
    *P_LVALUE_620 = PrtTupleGet(PTMP_tmp63_3, 0);
    
    PRT_VALUE** P_LVALUE_621 = &(PTMP_tmp65_2);
    PrtFreeValue(*P_LVALUE_621);
    *P_LVALUE_621 = PrtTupleGet(PTMP_tmp64_3, 0);
    
    PRT_VALUE** P_LVALUE_622 = &(PTMP_tmp66_2);
    PrtFreeValue(*P_LVALUE_622);
    *P_LVALUE_622 = PrtSeqGet(PTMP_tmp65_2, (&P_LIT_INT32_61));
    
    PRT_VALUE** P_LVALUE_623 = &(PTMP_tmp67_2);
    PrtFreeValue(*P_LVALUE_623);
    *P_LVALUE_623 = PrtTupleGet(PTMP_tmp66_2, 0);
    
    PRT_VALUE** P_LVALUE_624 = &(PTMP_tmp68_2);
    PrtFreeValue(*P_LVALUE_624);
    *P_LVALUE_624 = PrtTupleGet(P_VAR_cvmsgConfReq, 5);
    
    PRT_VALUE** P_LVALUE_625 = &(PTMP_tmp69_2);
    PrtFreeValue(*P_LVALUE_625);
    *P_LVALUE_625 = PrtTupleGet(PTMP_tmp68_2, 0);
    
    PRT_VALUE** P_LVALUE_626 = &(PTMP_tmp70_2);
    PrtFreeValue(*P_LVALUE_626);
    *P_LVALUE_626 = PrtTupleGet(PTMP_tmp69_2, 0);
    
    PRT_VALUE** P_LVALUE_627 = &(PTMP_tmp71_2);
    PrtFreeValue(*P_LVALUE_627);
    *P_LVALUE_627 = PrtSeqGet(PTMP_tmp70_2, (&P_LIT_INT32_61));
    
    PRT_VALUE** P_LVALUE_628 = &(PTMP_tmp72_2);
    PrtFreeValue(*P_LVALUE_628);
    *P_LVALUE_628 = PrtTupleGet(PTMP_tmp71_2, 1);
    
    PRT_VALUE** P_LVALUE_629 = &(PTMP_tmp73_2);
    PrtFreeValue(*P_LVALUE_629);
    *P_LVALUE_629 = ((_P_GEN_funargs[0] = &(PTMP_tmp67_2)), (_P_GEN_funargs[1] = &(PTMP_tmp72_2)), (_P_GEN_funval = P_writeBuffer_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp67_2), PTMP_tmp67_2 = NULL), (PrtFreeValue(PTMP_tmp72_2), PTMP_tmp72_2 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_12;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_12;
    }
    
    {
        PRT_VALUE** P_LVALUE_630 = &(*(PrtTupleGetLValue(*(PrtSeqGetLValue(*(PrtTupleGetLValue(*(PrtTupleGetLValue(*(PrtTupleGetLValue(P_VAR_cvmsgConfReq, 5)), 0)), 0)), (&P_LIT_INT32_61))), 3)));
        PrtFreeValue(*P_LVALUE_630);
        *P_LVALUE_630 = PTMP_tmp73_2;
        PTMP_tmp73_2 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_631 = &(PTMP_tmp74_2);
    PrtFreeValue(*P_LVALUE_631);
    *P_LVALUE_631 = PrtCloneValue(PrtCastValue(PrtCloneValue(P_VAR_cvmsgConfReq), &P_GEND_TYPE_B));
    
    {
        PRT_VALUE** P_LVALUE_632 = &(*(PrtTupleGetLValue(*(PrtSeqGetLValue(*(PrtTupleGetLValue(*(PrtTupleGetLValue(P_VAR_request, 6)), 1)), (&P_LIT_INT32_62))), 1)));
        PrtFreeValue(*P_LVALUE_632);
        *P_LVALUE_632 = PTMP_tmp74_2;
        PTMP_tmp74_2 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_633 = &(PTMP_tmp75_2);
    PrtFreeValue(*P_LVALUE_633);
    *P_LVALUE_633 = PrtMkBoolValue(PrtIsEqualValue(*P_VAR_IsConn, (&P_LIT_INT32_62)));
    
    if (PrtPrimGetBool(PTMP_tmp75_2))
    {
        PRT_VALUE** P_LVALUE_634 = &(PTMP_tmp76_2);
        PrtFreeValue(*P_LVALUE_634);
        *P_LVALUE_634 = PrtTupleGet(P_VAR_request, 6);
        
        PRT_VALUE** P_LVALUE_635 = &(PTMP_tmp77_2);
        PrtFreeValue(*P_LVALUE_635);
        *P_LVALUE_635 = PrtTupleGet(PTMP_tmp76_2, 0);
        
        PRT_VALUE** P_LVALUE_636 = &(PTMP_tmp78_2);
        PrtFreeValue(*P_LVALUE_636);
        *P_LVALUE_636 = PrtTupleGet(PTMP_tmp77_2, 0);
        
        PRT_VALUE** P_LVALUE_637 = &(PTMP_tmp79_2);
        PrtFreeValue(*P_LVALUE_637);
        *P_LVALUE_637 = PrtSeqGet(PTMP_tmp78_2, (&P_LIT_INT32_61));
        
        PRT_VALUE** P_LVALUE_638 = &(PTMP_tmp80_2);
        PrtFreeValue(*P_LVALUE_638);
        *P_LVALUE_638 = PrtTupleGet(PTMP_tmp79_2, 0);
        
        PRT_VALUE** P_LVALUE_639 = &(PTMP_tmp81_2);
        PrtFreeValue(*P_LVALUE_639);
        *P_LVALUE_639 = PrtTupleGet(P_VAR_request, 6);
        
        PRT_VALUE** P_LVALUE_640 = &(PTMP_tmp82_2);
        PrtFreeValue(*P_LVALUE_640);
        *P_LVALUE_640 = PrtTupleGet(PTMP_tmp81_2, 1);
        
        PRT_VALUE** P_LVALUE_641 = &(PTMP_tmp83_2);
        PrtFreeValue(*P_LVALUE_641);
        *P_LVALUE_641 = PrtSeqGet(PTMP_tmp82_2, (&P_LIT_INT32_61));
        
        PRT_VALUE** P_LVALUE_642 = &(PTMP_tmp84_2);
        PrtFreeValue(*P_LVALUE_642);
        *P_LVALUE_642 = PrtTupleGet(PTMP_tmp83_2, 0);
        
        PRT_VALUE** P_LVALUE_643 = &(PTMP_tmp85_2);
        PrtFreeValue(*P_LVALUE_643);
        *P_LVALUE_643 = ((_P_GEN_funargs[0] = &(PTMP_tmp80_2)), (_P_GEN_funargs[1] = &(PTMP_tmp84_2)), (_P_GEN_funval = P_writeBuffer_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp80_2), PTMP_tmp80_2 = NULL), (PrtFreeValue(PTMP_tmp84_2), PTMP_tmp84_2 = NULL), (_P_GEN_funval));
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_12;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_12;
        }
        
        {
            PRT_VALUE** P_LVALUE_644 = &(*(PrtTupleGetLValue(*(PrtSeqGetLValue(*(PrtTupleGetLValue(*(PrtTupleGetLValue(*(PrtTupleGetLValue(P_VAR_request, 6)), 0)), 0)), (&P_LIT_INT32_61))), 3)));
            PrtFreeValue(*P_LVALUE_644);
            *P_LVALUE_644 = PTMP_tmp85_2;
            PTMP_tmp85_2 = NULL;
        }
        
    }
    
    else
    {
        PRT_VALUE** P_LVALUE_645 = &(PTMP_tmp86_2);
        PrtFreeValue(*P_LVALUE_645);
        *P_LVALUE_645 = PrtTupleGet(P_VAR_request, 6);
        
        PRT_VALUE** P_LVALUE_646 = &(PTMP_tmp87_2);
        PrtFreeValue(*P_LVALUE_646);
        *P_LVALUE_646 = PrtTupleGet(PTMP_tmp86_2, 0);
        
        PRT_VALUE** P_LVALUE_647 = &(PTMP_tmp88_2);
        PrtFreeValue(*P_LVALUE_647);
        *P_LVALUE_647 = PrtTupleGet(PTMP_tmp87_2, 0);
        
        PRT_VALUE** P_LVALUE_648 = &(PTMP_tmp89_2);
        PrtFreeValue(*P_LVALUE_648);
        *P_LVALUE_648 = PrtSeqGet(PTMP_tmp88_2, (&P_LIT_INT32_61));
        
        PRT_VALUE** P_LVALUE_649 = &(PTMP_tmp90_2);
        PrtFreeValue(*P_LVALUE_649);
        *P_LVALUE_649 = PrtTupleGet(PTMP_tmp89_2, 0);
        
        PRT_VALUE** P_LVALUE_650 = &(PTMP_tmp91_2);
        PrtFreeValue(*P_LVALUE_650);
        *P_LVALUE_650 = PrtTupleGet(P_VAR_request, 6);
        
        PRT_VALUE** P_LVALUE_651 = &(PTMP_tmp92_2);
        PrtFreeValue(*P_LVALUE_651);
        *P_LVALUE_651 = PrtTupleGet(PTMP_tmp91_2, 1);
        
        PRT_VALUE** P_LVALUE_652 = &(PTMP_tmp93_1);
        PrtFreeValue(*P_LVALUE_652);
        *P_LVALUE_652 = PrtSeqGet(PTMP_tmp92_2, (&P_LIT_INT32_62));
        
        PRT_VALUE** P_LVALUE_653 = &(PTMP_tmp94_1);
        PrtFreeValue(*P_LVALUE_653);
        *P_LVALUE_653 = PrtTupleGet(PTMP_tmp93_1, 0);
        
        PRT_VALUE** P_LVALUE_654 = &(PTMP_tmp95_1);
        PrtFreeValue(*P_LVALUE_654);
        *P_LVALUE_654 = ((_P_GEN_funargs[0] = &(PTMP_tmp90_2)), (_P_GEN_funargs[1] = &(PTMP_tmp94_1)), (_P_GEN_funval = P_writeBuffer_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp90_2), PTMP_tmp90_2 = NULL), (PrtFreeValue(PTMP_tmp94_1), PTMP_tmp94_1 = NULL), (_P_GEN_funval));
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_12;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_12;
        }
        
        {
            PRT_VALUE** P_LVALUE_655 = &(*(PrtTupleGetLValue(*(PrtSeqGetLValue(*(PrtTupleGetLValue(*(PrtTupleGetLValue(*(PrtTupleGetLValue(P_VAR_request, 6)), 0)), 0)), (&P_LIT_INT32_61))), 3)));
            PrtFreeValue(*P_LVALUE_655);
            *P_LVALUE_655 = PTMP_tmp95_1;
            PTMP_tmp95_1 = NULL;
        }
        
    }
    
    
    PRT_VALUE** P_LVALUE_656 = &(PTMP_tmp96_1);
    PrtFreeValue(*P_LVALUE_656);
    *P_LVALUE_656 = PrtCloneValue(p_this->varValues[1]);
    
    PRT_VALUE** P_LVALUE_657 = &(PTMP_tmp97_1);
    PrtFreeValue(*P_LVALUE_657);
    *P_LVALUE_657 = PrtCloneValue((&P_EVENT_eL2CmdReq.value));
    
    PRT_VALUE** P_LVALUE_658 = &(PTMP_tmp98_1);
    PrtFreeValue(*P_LVALUE_658);
    *P_LVALUE_658 = PrtCloneValue((p_this->id));
    
    PRT_VALUE** P_LVALUE_659 = &(PTMP_tmp99_1);
    PrtFreeValue(*P_LVALUE_659);
    *P_LVALUE_659 = PrtCloneValue(P_VAR_request);
    
    PRT_VALUE** P_LVALUE_660 = &(PTMP_tmp100_1);
    PrtFreeValue(*P_LVALUE_660);
    *P_LVALUE_660 = (PrtMkTuple(&P_GEND_TYPE_NT2RNT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB, &(PTMP_tmp98_1), &(PTMP_tmp99_1)));
    
    PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp96_1), PTMP_tmp97_1, 1, &(PTMP_tmp100_1));
    *(&(PTMP_tmp97_1)) = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_12;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_12;
    }
    
    PrtGoto(p_this, 2U, 0);
    
p_return_12: ;
    PrtFreeValue(P_VAR_request); P_VAR_request = NULL;
    PrtFreeValue(P_VAR_cvmsgConnReq); P_VAR_cvmsgConnReq = NULL;
    PrtFreeValue(P_VAR_cvmsgConfReq); P_VAR_cvmsgConfReq = NULL;
    PrtFreeValue(P_VAR_cvmsgoptPlist); P_VAR_cvmsgoptPlist = NULL;
    PrtFreeValue(PTMP_tmp0_10); PTMP_tmp0_10 = NULL;
    PrtFreeValue(PTMP_tmp1_10); PTMP_tmp1_10 = NULL;
    PrtFreeValue(PTMP_tmp2_10); PTMP_tmp2_10 = NULL;
    PrtFreeValue(PTMP_tmp3_10); PTMP_tmp3_10 = NULL;
    PrtFreeValue(PTMP_tmp4_9); PTMP_tmp4_9 = NULL;
    PrtFreeValue(PTMP_tmp5_9); PTMP_tmp5_9 = NULL;
    PrtFreeValue(PTMP_tmp6_9); PTMP_tmp6_9 = NULL;
    PrtFreeValue(PTMP_tmp7_8); PTMP_tmp7_8 = NULL;
    PrtFreeValue(PTMP_tmp8_8); PTMP_tmp8_8 = NULL;
    PrtFreeValue(PTMP_tmp9_8); PTMP_tmp9_8 = NULL;
    PrtFreeValue(PTMP_tmp10_7); PTMP_tmp10_7 = NULL;
    PrtFreeValue(PTMP_tmp11_7); PTMP_tmp11_7 = NULL;
    PrtFreeValue(PTMP_tmp12_7); PTMP_tmp12_7 = NULL;
    PrtFreeValue(PTMP_tmp13_7); PTMP_tmp13_7 = NULL;
    PrtFreeValue(PTMP_tmp14_7); PTMP_tmp14_7 = NULL;
    PrtFreeValue(PTMP_tmp15_6); PTMP_tmp15_6 = NULL;
    PrtFreeValue(PTMP_tmp16_6); PTMP_tmp16_6 = NULL;
    PrtFreeValue(PTMP_tmp17_6); PTMP_tmp17_6 = NULL;
    PrtFreeValue(PTMP_tmp18_6); PTMP_tmp18_6 = NULL;
    PrtFreeValue(PTMP_tmp19_6); PTMP_tmp19_6 = NULL;
    PrtFreeValue(PTMP_tmp20_6); PTMP_tmp20_6 = NULL;
    PrtFreeValue(PTMP_tmp21_6); PTMP_tmp21_6 = NULL;
    PrtFreeValue(PTMP_tmp22_6); PTMP_tmp22_6 = NULL;
    PrtFreeValue(PTMP_tmp23_6); PTMP_tmp23_6 = NULL;
    PrtFreeValue(PTMP_tmp24_5); PTMP_tmp24_5 = NULL;
    PrtFreeValue(PTMP_tmp25_5); PTMP_tmp25_5 = NULL;
    PrtFreeValue(PTMP_tmp26_5); PTMP_tmp26_5 = NULL;
    PrtFreeValue(PTMP_tmp27_5); PTMP_tmp27_5 = NULL;
    PrtFreeValue(PTMP_tmp28_5); PTMP_tmp28_5 = NULL;
    PrtFreeValue(PTMP_tmp29_5); PTMP_tmp29_5 = NULL;
    PrtFreeValue(PTMP_tmp30_5); PTMP_tmp30_5 = NULL;
    PrtFreeValue(PTMP_tmp31_5); PTMP_tmp31_5 = NULL;
    PrtFreeValue(PTMP_tmp32_5); PTMP_tmp32_5 = NULL;
    PrtFreeValue(PTMP_tmp33_4); PTMP_tmp33_4 = NULL;
    PrtFreeValue(PTMP_tmp34_4); PTMP_tmp34_4 = NULL;
    PrtFreeValue(PTMP_tmp35_4); PTMP_tmp35_4 = NULL;
    PrtFreeValue(PTMP_tmp36_4); PTMP_tmp36_4 = NULL;
    PrtFreeValue(PTMP_tmp37_4); PTMP_tmp37_4 = NULL;
    PrtFreeValue(PTMP_tmp38_4); PTMP_tmp38_4 = NULL;
    PrtFreeValue(PTMP_tmp39_4); PTMP_tmp39_4 = NULL;
    PrtFreeValue(PTMP_tmp40_3); PTMP_tmp40_3 = NULL;
    PrtFreeValue(PTMP_tmp41_3); PTMP_tmp41_3 = NULL;
    PrtFreeValue(PTMP_tmp42_3); PTMP_tmp42_3 = NULL;
    PrtFreeValue(PTMP_tmp43_3); PTMP_tmp43_3 = NULL;
    PrtFreeValue(PTMP_tmp44_3); PTMP_tmp44_3 = NULL;
    PrtFreeValue(PTMP_tmp45_3); PTMP_tmp45_3 = NULL;
    PrtFreeValue(PTMP_tmp46_3); PTMP_tmp46_3 = NULL;
    PrtFreeValue(PTMP_tmp47_3); PTMP_tmp47_3 = NULL;
    PrtFreeValue(PTMP_tmp48_3); PTMP_tmp48_3 = NULL;
    PrtFreeValue(PTMP_tmp49_3); PTMP_tmp49_3 = NULL;
    PrtFreeValue(PTMP_tmp50_3); PTMP_tmp50_3 = NULL;
    PrtFreeValue(PTMP_tmp51_3); PTMP_tmp51_3 = NULL;
    PrtFreeValue(PTMP_tmp52_3); PTMP_tmp52_3 = NULL;
    PrtFreeValue(PTMP_tmp53_3); PTMP_tmp53_3 = NULL;
    PrtFreeValue(PTMP_tmp54_3); PTMP_tmp54_3 = NULL;
    PrtFreeValue(PTMP_tmp55_3); PTMP_tmp55_3 = NULL;
    PrtFreeValue(PTMP_tmp56_3); PTMP_tmp56_3 = NULL;
    PrtFreeValue(PTMP_tmp57_3); PTMP_tmp57_3 = NULL;
    PrtFreeValue(PTMP_tmp58_3); PTMP_tmp58_3 = NULL;
    PrtFreeValue(PTMP_tmp59_3); PTMP_tmp59_3 = NULL;
    PrtFreeValue(PTMP_tmp60_3); PTMP_tmp60_3 = NULL;
    PrtFreeValue(PTMP_tmp61_3); PTMP_tmp61_3 = NULL;
    PrtFreeValue(PTMP_tmp62_3); PTMP_tmp62_3 = NULL;
    PrtFreeValue(PTMP_tmp63_3); PTMP_tmp63_3 = NULL;
    PrtFreeValue(PTMP_tmp64_3); PTMP_tmp64_3 = NULL;
    PrtFreeValue(PTMP_tmp65_2); PTMP_tmp65_2 = NULL;
    PrtFreeValue(PTMP_tmp66_2); PTMP_tmp66_2 = NULL;
    PrtFreeValue(PTMP_tmp67_2); PTMP_tmp67_2 = NULL;
    PrtFreeValue(PTMP_tmp68_2); PTMP_tmp68_2 = NULL;
    PrtFreeValue(PTMP_tmp69_2); PTMP_tmp69_2 = NULL;
    PrtFreeValue(PTMP_tmp70_2); PTMP_tmp70_2 = NULL;
    PrtFreeValue(PTMP_tmp71_2); PTMP_tmp71_2 = NULL;
    PrtFreeValue(PTMP_tmp72_2); PTMP_tmp72_2 = NULL;
    PrtFreeValue(PTMP_tmp73_2); PTMP_tmp73_2 = NULL;
    PrtFreeValue(PTMP_tmp74_2); PTMP_tmp74_2 = NULL;
    PrtFreeValue(PTMP_tmp75_2); PTMP_tmp75_2 = NULL;
    PrtFreeValue(PTMP_tmp76_2); PTMP_tmp76_2 = NULL;
    PrtFreeValue(PTMP_tmp77_2); PTMP_tmp77_2 = NULL;
    PrtFreeValue(PTMP_tmp78_2); PTMP_tmp78_2 = NULL;
    PrtFreeValue(PTMP_tmp79_2); PTMP_tmp79_2 = NULL;
    PrtFreeValue(PTMP_tmp80_2); PTMP_tmp80_2 = NULL;
    PrtFreeValue(PTMP_tmp81_2); PTMP_tmp81_2 = NULL;
    PrtFreeValue(PTMP_tmp82_2); PTMP_tmp82_2 = NULL;
    PrtFreeValue(PTMP_tmp83_2); PTMP_tmp83_2 = NULL;
    PrtFreeValue(PTMP_tmp84_2); PTMP_tmp84_2 = NULL;
    PrtFreeValue(PTMP_tmp85_2); PTMP_tmp85_2 = NULL;
    PrtFreeValue(PTMP_tmp86_2); PTMP_tmp86_2 = NULL;
    PrtFreeValue(PTMP_tmp87_2); PTMP_tmp87_2 = NULL;
    PrtFreeValue(PTMP_tmp88_2); PTMP_tmp88_2 = NULL;
    PrtFreeValue(PTMP_tmp89_2); PTMP_tmp89_2 = NULL;
    PrtFreeValue(PTMP_tmp90_2); PTMP_tmp90_2 = NULL;
    PrtFreeValue(PTMP_tmp91_2); PTMP_tmp91_2 = NULL;
    PrtFreeValue(PTMP_tmp92_2); PTMP_tmp92_2 = NULL;
    PrtFreeValue(PTMP_tmp93_1); PTMP_tmp93_1 = NULL;
    PrtFreeValue(PTMP_tmp94_1); PTMP_tmp94_1 = NULL;
    PrtFreeValue(PTMP_tmp95_1); PTMP_tmp95_1 = NULL;
    PrtFreeValue(PTMP_tmp96_1); PTMP_tmp96_1 = NULL;
    PrtFreeValue(PTMP_tmp97_1); PTMP_tmp97_1 = NULL;
    PrtFreeValue(PTMP_tmp98_1); PTMP_tmp98_1 = NULL;
    PrtFreeValue(PTMP_tmp99_1); PTMP_tmp99_1 = NULL;
    PrtFreeValue(PTMP_tmp100_1); PTMP_tmp100_1 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_7 =
{
    NULL,
    &P_Anon_IMPL_7,
    &P_GEND_TYPE_i
};


PRT_VALUE* P_Anon_IMPL_8(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* PTMP_tmp0_11 = NULL;
    PRT_VALUE* PTMP_tmp1_11 = NULL;
    PRT_VALUE* PTMP_tmp2_11 = NULL;
    PRT_VALUE* P_VAR_P_payload_1 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_UINT32 P_allowedEventIds_1[] = { 3, 4 };
    PrtFreeValue(P_VAR_P_payload_1); P_VAR_P_payload_1 = NULL;
    PRT_UINT32 P_eventId_1 = PrtReceiveAsync(2U, P_allowedEventIds_1, &P_VAR_P_payload_1);
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_13;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_13;
    }
    switch (P_eventId_1) {
        case 3: {
            PRT_VALUE** P_VAR_Success = &P_VAR_P_payload_1;
            PRT_VALUE P_LIT_INT32_63 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
            PRT_VALUE P_LIT_INT32_64 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
                        if (PrtPrimGetBool(*P_VAR_Success))
            {
                PRT_VALUE** P_LVALUE_661 = &(PTMP_tmp0_11);
                PrtFreeValue(*P_LVALUE_661);
                *P_LVALUE_661 = PrtCloneValue((&P_LIT_INT32_63));
                
                PrtGoto(p_this, 1U, 1, &(PTMP_tmp0_11));
                
            }
            
            else
            {
                PRT_VALUE** P_LVALUE_662 = &(PTMP_tmp1_11);
                PrtFreeValue(*P_LVALUE_662);
                *P_LVALUE_662 = PrtCloneValue((&P_LIT_INT32_64));
                
                PrtGoto(p_this, 1U, 1, &(PTMP_tmp1_11));
                
            }
            
            
            p_return_14: ;
} break;
        case 4: {
            PRT_VALUE** P_VAR_Success_1 = &P_VAR_P_payload_1;
            PRT_VALUE P_LIT_INT32_65 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
                        if (PrtPrimGetBool(*P_VAR_Success_1))
            {
                PrtGoto(p_this, 3U, 0);
                
            }
            
            else
            {
                PRT_VALUE** P_LVALUE_663 = &(PTMP_tmp2_11);
                PrtFreeValue(*P_LVALUE_663);
                *P_LVALUE_663 = PrtCloneValue((&P_LIT_INT32_65));
                
                PrtGoto(p_this, 1U, 1, &(PTMP_tmp2_11));
                
            }
            
            
            p_return_15: ;
} break;
        default: {
            PrtAssert(PRT_FALSE, "receive returned unhandled event");
        } break;
    }
    PrtFreeValue(P_VAR_P_payload_1); P_VAR_P_payload_1 = NULL;
    
p_return_13: ;
    PrtFreeValue(PTMP_tmp0_11); PTMP_tmp0_11 = NULL;
    PrtFreeValue(PTMP_tmp1_11); PTMP_tmp1_11 = NULL;
    PrtFreeValue(PTMP_tmp2_11); PTMP_tmp2_11 = NULL;
    PrtFreeValue(P_VAR_P_payload_1); P_VAR_P_payload_1 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_8 =
{
    NULL,
    &P_Anon_IMPL_8,
    NULL
};


PRT_FUNDECL* P_ClientMachine_METHODS[] = { &P_FUNCTION_Anon_6, &P_FUNCTION_Anon_7, &P_FUNCTION_Anon_8 };

PRT_EVENTDECL* P_ClientMachine_RECV_INNER_1[] = { &P_EVENT_eChanConnected, &P_EVENT_eChanDead, &P_EVENT_eChanGotoConfig, &P_EVENT_eChanGotoConnected, &P_EVENT_eChanStarted, &P_EVENT_eComposetFix, &P_EVENT_eComposetHdr, &P_EVENT_eComposetMsg, &P_EVENT_eComposetPara, &P_EVENT_eComposetPlist, &P_EVENT_eComposetVar, &P_EVENT_eConfReq, &P_EVENT_eConfResp, &P_EVENT_eConnReq, &P_EVENT_eConnResp, &P_EVENT_eGetDefaultValueResp, &P_EVENT_eL2CmdReq, &P_EVENT_eParsetFix, &P_EVENT_eParsetHdr, &P_EVENT_eParsetMsg, &P_EVENT_eParsetPara, &P_EVENT_eParsetPlist, &P_EVENT_eParsetVar, &P_EVENT_eSpecGetDefaultValueReq, &P_EVENT_eStartTimer, &P_EVENT_eTimeOut, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_ClientMachine_RECV_1 =
{
    27U,
    P_ClientMachine_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_ClientMachine_SEND_INNER[] = { &P_EVENT_eChanConnected, &P_EVENT_eChanDead, &P_EVENT_eChanGotoConfig, &P_EVENT_eChanGotoConnected, &P_EVENT_eChanStarted, &P_EVENT_eComposetFix, &P_EVENT_eComposetHdr, &P_EVENT_eComposetMsg, &P_EVENT_eComposetPara, &P_EVENT_eComposetPlist, &P_EVENT_eComposetVar, &P_EVENT_eConfReq, &P_EVENT_eConfResp, &P_EVENT_eConnReq, &P_EVENT_eConnResp, &P_EVENT_eGetDefaultValueResp, &P_EVENT_eL2CmdReq, &P_EVENT_eParsetFix, &P_EVENT_eParsetHdr, &P_EVENT_eParsetMsg, &P_EVENT_eParsetPara, &P_EVENT_eParsetPlist, &P_EVENT_eParsetVar, &P_EVENT_eSpecGetDefaultValueReq, &P_EVENT_eStartTimer, &P_EVENT_eTimeOut, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_ClientMachine_SEND =
{
    27U,
    P_ClientMachine_SEND_INNER,
    NULL
};

PRT_MACHINEDECL P_MACHINE_ClientMachine = 
{
    2U,
    "ClientMachine",
    &P_EVENTSET_ClientMachine_RECV_1,
    &P_EVENTSET_ClientMachine_SEND,
    NULL,
    3U,
    4U,
    3U,
    4294967295U,
    0U,
    P_ClientMachine_VARS,
    P_ClientMachine_STATES,
    P_ClientMachine_METHODS
};

PRT_VARDECL P_ChanMachine_VARS[] = {
    { "ConfigReqID", &P_GEND_TYPE_i },
    { "ConnectedReqID", &P_GEND_TYPE_i },
    { "ConfigTimer", &P_GEND_TYPE_m },
    { "ConnectedTimer", &P_GEND_TYPE_m },
    { "InitServer", &P_GEND_TYPE_R_1 },
    { "BT_CONFIG_timeout", &P_GEND_TYPE_i },
    { "BT_CONNECTED_timeout", &P_GEND_TYPE_i }
};

PRT_EVENTDECL* P_Init_DEFERS_INNER_3[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DEFERS_3 =
{
    0U,
    P_Init_DEFERS_INNER_3,
    NULL
};

PRT_EVENTDECL* P_Init_TRANS_INNER_3[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_TRANS_3 =
{
    0U,
    P_Init_TRANS_INNER_3,
    NULL
};

PRT_EVENTDECL* P_Init_DOS_INNER_3[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DOS_3 =
{
    0U,
    P_Init_DOS_INNER_3,
    NULL
};

#define P_STATE_ChanMachine_Init \
{ \
    "ChanMachine.Init", \
    0U, \
    0U, \
    &P_EVENTSET_Init_DEFERS_3, \
    &P_EVENTSET_Init_TRANS_3, \
    &P_EVENTSET_Init_DOS_3, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon_9, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_BT_START_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_BT_START_DEFERS =
{
    0U,
    P_BT_START_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_BT_START_TRANS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_BT_START_TRANS =
{
    0U,
    P_BT_START_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_BT_START_DOS_INNER[] = { &P_EVENT_eChanGotoConfig, &P_EVENT_eChanGotoConnected, &P_EVENT_eTimeOut };
PRT_EVENTSETDECL P_EVENTSET_BT_START_DOS =
{
    3U,
    P_BT_START_DOS_INNER,
    NULL
};

PRT_DODECL P_DOS_3[] =
{
    { 1, &P_EVENT_eChanGotoConfig, &P_FUNCTION_Anon_11 },
    { 1, &P_EVENT_eChanGotoConnected, NULL },
    { 1, &P_EVENT_eTimeOut, NULL }
};

#define P_STATE_ChanMachine_BT_START \
{ \
    "ChanMachine.BT_START", \
    0U, \
    3U, \
    &P_EVENTSET_BT_START_DEFERS, \
    &P_EVENTSET_BT_START_TRANS, \
    &P_EVENTSET_BT_START_DOS, \
    NULL, \
    P_DOS_3, \
    &P_FUNCTION_Anon_10, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_BT_CONFIG_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_BT_CONFIG_DEFERS =
{
    0U,
    P_BT_CONFIG_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_BT_CONFIG_TRANS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_BT_CONFIG_TRANS =
{
    0U,
    P_BT_CONFIG_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_BT_CONFIG_DOS_INNER[] = { &P_EVENT_eChanGotoConfig, &P_EVENT_eChanGotoConnected, &P_EVENT_eTimeOut };
PRT_EVENTSETDECL P_EVENTSET_BT_CONFIG_DOS =
{
    3U,
    P_BT_CONFIG_DOS_INNER,
    NULL
};

PRT_DODECL P_DOS_4[] =
{
    { 2, &P_EVENT_eChanGotoConnected, &P_FUNCTION_Anon_13 },
    { 2, &P_EVENT_eTimeOut, &P_FUNCTION_Anon_14 },
    { 2, &P_EVENT_eChanGotoConfig, NULL }
};

#define P_STATE_ChanMachine_BT_CONFIG \
{ \
    "ChanMachine.BT_CONFIG", \
    0U, \
    3U, \
    &P_EVENTSET_BT_CONFIG_DEFERS, \
    &P_EVENTSET_BT_CONFIG_TRANS, \
    &P_EVENTSET_BT_CONFIG_DOS, \
    NULL, \
    P_DOS_4, \
    &P_FUNCTION_Anon_12, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_BT_CONNECTED_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_BT_CONNECTED_DEFERS =
{
    0U,
    P_BT_CONNECTED_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_BT_CONNECTED_TRANS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_BT_CONNECTED_TRANS =
{
    0U,
    P_BT_CONNECTED_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_BT_CONNECTED_DOS_INNER[] = { &P_EVENT_eChanGotoConnected, &P_EVENT_eTimeOut };
PRT_EVENTSETDECL P_EVENTSET_BT_CONNECTED_DOS =
{
    2U,
    P_BT_CONNECTED_DOS_INNER,
    NULL
};

PRT_DODECL P_DOS_5[] =
{
    { 3, &P_EVENT_eTimeOut, &P_FUNCTION_Anon_16 },
    { 3, &P_EVENT_eChanGotoConnected, NULL }
};

#define P_STATE_ChanMachine_BT_CONNECTED \
{ \
    "ChanMachine.BT_CONNECTED", \
    0U, \
    2U, \
    &P_EVENTSET_BT_CONNECTED_DEFERS, \
    &P_EVENTSET_BT_CONNECTED_TRANS, \
    &P_EVENTSET_BT_CONNECTED_DOS, \
    NULL, \
    P_DOS_5, \
    &P_FUNCTION_Anon_15, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_BT_DEAD_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_BT_DEAD_DEFERS =
{
    0U,
    P_BT_DEAD_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_BT_DEAD_TRANS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_BT_DEAD_TRANS =
{
    0U,
    P_BT_DEAD_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_BT_DEAD_DOS_INNER[] = { &P_EVENT_eChanGotoConnected, &P_EVENT_eTimeOut };
PRT_EVENTSETDECL P_EVENTSET_BT_DEAD_DOS =
{
    2U,
    P_BT_DEAD_DOS_INNER,
    NULL
};

PRT_DODECL P_DOS_6[] =
{
    { 4, &P_EVENT_eChanGotoConnected, NULL },
    { 4, &P_EVENT_eTimeOut, NULL }
};

#define P_STATE_ChanMachine_BT_DEAD \
{ \
    "ChanMachine.BT_DEAD", \
    0U, \
    2U, \
    &P_EVENTSET_BT_DEAD_DEFERS, \
    &P_EVENTSET_BT_DEAD_TRANS, \
    &P_EVENTSET_BT_DEAD_DOS, \
    NULL, \
    P_DOS_6, \
    &P_FUNCTION_Anon_17, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_ChanMachine_STATES[] = { P_STATE_ChanMachine_Init, P_STATE_ChanMachine_BT_START, P_STATE_ChanMachine_BT_CONFIG, P_STATE_ChanMachine_BT_CONNECTED, P_STATE_ChanMachine_BT_DEAD };

PRT_VALUE* P_Anon_IMPL_9(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR__InitServer = argRefs[0];
    PRT_VALUE* PTMP_tmp0_12 = NULL;
    PRT_VALUE* PTMP_tmp1_12 = NULL;
    PRT_VALUE* PTMP_tmp2_12 = NULL;
    PRT_VALUE* PTMP_tmp3_11 = NULL;
    PRT_VALUE* PTMP_tmp4_10 = NULL;
    PRT_VALUE* PTMP_tmp5_10 = NULL;
    PRT_VALUE* PTMP_tmp6_10 = NULL;
    PRT_VALUE* PTMP_tmp7_9 = NULL;
    PRT_VALUE* PTMP_tmp8_9 = NULL;
    PRT_VALUE* PTMP_tmp9_9 = NULL;
    PRT_VALUE* PTMP_tmp10_8 = NULL;
    PRT_VALUE* PTMP_tmp11_8 = NULL;
    PRT_VALUE* PTMP_tmp12_8 = NULL;
    PRT_VALUE* PTMP_tmp13_8 = NULL;
    PRT_VALUE* PTMP_tmp14_8 = NULL;
    PRT_VALUE* P_VAR_P_payload_2 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_66 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE** P_LVALUE_664 = &(p_this->varValues[4]);
    PrtFreeValue(*P_LVALUE_664);
    *P_LVALUE_664 = PrtCloneValue(*P_VAR__InitServer);
    
    PRT_VALUE** P_LVALUE_665 = &(p_this->varValues[0]);
    PrtFreeValue(*P_LVALUE_665);
    *P_LVALUE_665 = PrtCloneValue((&P_LIT_INT32_66));
    
    PRT_VALUE** P_LVALUE_666 = &(p_this->varValues[0]);
    PrtFreeValue(*P_LVALUE_666);
    *P_LVALUE_666 = PrtCloneValue((&P_LIT_INT32_66));
    
    PRT_VALUE** P_LVALUE_667 = &(PTMP_tmp0_12);
    PrtFreeValue(*P_LVALUE_667);
    *P_LVALUE_667 = PrtCloneValue(p_this->varValues[4]);
    
    PRT_VALUE** P_LVALUE_668 = &(PTMP_tmp1_12);
    PrtFreeValue(*P_LVALUE_668);
    *P_LVALUE_668 = PrtCloneValue((&P_EVENT_eSpecGetDefaultValueReq.value));
    
    PRT_VALUE** P_LVALUE_669 = &(PTMP_tmp2_12);
    PrtFreeValue(*P_LVALUE_669);
    *P_LVALUE_669 = PrtCloneValue((p_this->id));
    
    PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp0_12), PTMP_tmp1_12, 1, &(PTMP_tmp2_12));
    *(&(PTMP_tmp1_12)) = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_16;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_16;
    }
    
    PRT_UINT32 P_allowedEventIds_2[] = { 2 };
    PrtFreeValue(P_VAR_P_payload_2); P_VAR_P_payload_2 = NULL;
    PRT_UINT32 P_eventId_2 = PrtReceiveAsync(1U, P_allowedEventIds_2, &P_VAR_P_payload_2);
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_16;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_16;
    }
    switch (P_eventId_2) {
        case 2: {
            PRT_VALUE** P_VAR_resp_1 = &P_VAR_P_payload_2;
            PRT_VALUE P_LIT_INT32_67 = { PRT_VALUE_KIND_INT, { .nt = 19 } };
            PRT_VALUE P_LIT_INT32_68 = { PRT_VALUE_KIND_INT, { .nt = 20 } };
                        PRT_VALUE** P_LVALUE_670 = &(PTMP_tmp3_11);
            PrtFreeValue(*P_LVALUE_670);
            *P_LVALUE_670 = PrtSeqGet(*P_VAR_resp_1, (&P_LIT_INT32_67));
            
            PRT_VALUE** P_LVALUE_671 = &(PTMP_tmp4_10);
            PrtFreeValue(*P_LVALUE_671);
            *P_LVALUE_671 = PrtCloneValue(PrtCastValue(PrtCloneValue(PTMP_tmp3_11), &P_GEND_TYPE_i));
            
            {
                PRT_VALUE** P_LVALUE_672 = &(p_this->varValues[5]);
                PrtFreeValue(*P_LVALUE_672);
                *P_LVALUE_672 = PTMP_tmp4_10;
                PTMP_tmp4_10 = NULL;
            }
            
            PRT_VALUE** P_LVALUE_673 = &(PTMP_tmp5_10);
            PrtFreeValue(*P_LVALUE_673);
            *P_LVALUE_673 = PrtSeqGet(*P_VAR_resp_1, (&P_LIT_INT32_68));
            
            PRT_VALUE** P_LVALUE_674 = &(PTMP_tmp6_10);
            PrtFreeValue(*P_LVALUE_674);
            *P_LVALUE_674 = PrtCloneValue(PrtCastValue(PrtCloneValue(PTMP_tmp5_10), &P_GEND_TYPE_i));
            
            {
                PRT_VALUE** P_LVALUE_675 = &(p_this->varValues[6]);
                PrtFreeValue(*P_LVALUE_675);
                *P_LVALUE_675 = PTMP_tmp6_10;
                PTMP_tmp6_10 = NULL;
            }
            
            p_return_17: ;
} break;
        default: {
            PrtAssert(PRT_FALSE, "receive returned unhandled event");
        } break;
    }
    PrtFreeValue(P_VAR_P_payload_2); P_VAR_P_payload_2 = NULL;
    
    PRT_VALUE** P_LVALUE_676 = &(PTMP_tmp7_9);
    PrtFreeValue(*P_LVALUE_676);
    *P_LVALUE_676 = PrtCloneValue((p_this->id));
    
    PRT_VALUE** P_LVALUE_677 = &(PTMP_tmp8_9);
    PrtFreeValue(*P_LVALUE_677);
    *P_LVALUE_677 = PrtCloneValue(p_this->varValues[5]);
    
    PRT_VALUE** P_LVALUE_678 = &(PTMP_tmp9_9);
    PrtFreeValue(*P_LVALUE_678);
    *P_LVALUE_678 = (PrtMkTuple(&P_GEND_TYPE_NT2Ri, &(PTMP_tmp7_9), &(PTMP_tmp8_9)));
    
    PRT_VALUE** P_LVALUE_679 = &(PTMP_tmp10_8);
    PrtFreeValue(*P_LVALUE_679);
    *P_LVALUE_679 = PrtCloneValue(PrtMkInterface(context, 4, 1, &(PTMP_tmp9_9))->id);
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_16;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_16;
    }
    
    {
        PRT_VALUE** P_LVALUE_680 = &(p_this->varValues[2]);
        PrtFreeValue(*P_LVALUE_680);
        *P_LVALUE_680 = PTMP_tmp10_8;
        PTMP_tmp10_8 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_681 = &(PTMP_tmp11_8);
    PrtFreeValue(*P_LVALUE_681);
    *P_LVALUE_681 = PrtCloneValue((p_this->id));
    
    PRT_VALUE** P_LVALUE_682 = &(PTMP_tmp12_8);
    PrtFreeValue(*P_LVALUE_682);
    *P_LVALUE_682 = PrtCloneValue(p_this->varValues[6]);
    
    PRT_VALUE** P_LVALUE_683 = &(PTMP_tmp13_8);
    PrtFreeValue(*P_LVALUE_683);
    *P_LVALUE_683 = (PrtMkTuple(&P_GEND_TYPE_NT2Ri, &(PTMP_tmp11_8), &(PTMP_tmp12_8)));
    
    PRT_VALUE** P_LVALUE_684 = &(PTMP_tmp14_8);
    PrtFreeValue(*P_LVALUE_684);
    *P_LVALUE_684 = PrtCloneValue(PrtMkInterface(context, 4, 1, &(PTMP_tmp13_8))->id);
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_16;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_16;
    }
    
    {
        PRT_VALUE** P_LVALUE_685 = &(p_this->varValues[3]);
        PrtFreeValue(*P_LVALUE_685);
        *P_LVALUE_685 = PTMP_tmp14_8;
        PTMP_tmp14_8 = NULL;
    }
    
    PrtGoto(p_this, 1U, 0);
    
p_return_16: ;
    PrtFreeValue(PTMP_tmp0_12); PTMP_tmp0_12 = NULL;
    PrtFreeValue(PTMP_tmp1_12); PTMP_tmp1_12 = NULL;
    PrtFreeValue(PTMP_tmp2_12); PTMP_tmp2_12 = NULL;
    PrtFreeValue(PTMP_tmp3_11); PTMP_tmp3_11 = NULL;
    PrtFreeValue(PTMP_tmp4_10); PTMP_tmp4_10 = NULL;
    PrtFreeValue(PTMP_tmp5_10); PTMP_tmp5_10 = NULL;
    PrtFreeValue(PTMP_tmp6_10); PTMP_tmp6_10 = NULL;
    PrtFreeValue(PTMP_tmp7_9); PTMP_tmp7_9 = NULL;
    PrtFreeValue(PTMP_tmp8_9); PTMP_tmp8_9 = NULL;
    PrtFreeValue(PTMP_tmp9_9); PTMP_tmp9_9 = NULL;
    PrtFreeValue(PTMP_tmp10_8); PTMP_tmp10_8 = NULL;
    PrtFreeValue(PTMP_tmp11_8); PTMP_tmp11_8 = NULL;
    PrtFreeValue(PTMP_tmp12_8); PTMP_tmp12_8 = NULL;
    PrtFreeValue(PTMP_tmp13_8); PTMP_tmp13_8 = NULL;
    PrtFreeValue(PTMP_tmp14_8); PTMP_tmp14_8 = NULL;
    PrtFreeValue(P_VAR_P_payload_2); P_VAR_P_payload_2 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_9 =
{
    NULL,
    &P_Anon_IMPL_9,
    &P_GEND_TYPE_R_1
};


PRT_VALUE* P_Anon_IMPL_10(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
p_return_18: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_10 =
{
    NULL,
    &P_Anon_IMPL_10,
    NULL
};


PRT_VALUE* P_Anon_IMPL_11(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* PTMP_tmp0_13 = NULL;
    PRT_VALUE* PTMP_tmp1_13 = NULL;
    PRT_VALUE* PTMP_tmp2_13 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_69 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE** P_LVALUE_686 = &(PTMP_tmp0_13);
    PrtFreeValue(*P_LVALUE_686);
    *P_LVALUE_686 = PrtCloneValue(p_this->varValues[2]);
    
    PRT_VALUE** P_LVALUE_687 = &(PTMP_tmp1_13);
    PrtFreeValue(*P_LVALUE_687);
    *P_LVALUE_687 = PrtCloneValue((&P_EVENT_eStartTimer.value));
    
    PRT_VALUE** P_LVALUE_688 = &(PTMP_tmp2_13);
    PrtFreeValue(*P_LVALUE_688);
    *P_LVALUE_688 = PrtCloneValue((&P_LIT_INT32_69));
    
    PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp0_13), PTMP_tmp1_13, 1, &(PTMP_tmp2_13));
    *(&(PTMP_tmp1_13)) = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_19;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_19;
    }
    
    PrtGoto(p_this, 2U, 0);
    
p_return_19: ;
    PrtFreeValue(PTMP_tmp0_13); PTMP_tmp0_13 = NULL;
    PrtFreeValue(PTMP_tmp1_13); PTMP_tmp1_13 = NULL;
    PrtFreeValue(PTMP_tmp2_13); PTMP_tmp2_13 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_11 =
{
    NULL,
    &P_Anon_IMPL_11,
    NULL
};


PRT_VALUE* P_Anon_IMPL_12(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    
p_return_20: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_12 =
{
    NULL,
    &P_Anon_IMPL_12,
    NULL
};


PRT_VALUE* P_Anon_IMPL_13(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* PTMP_tmp0_14 = NULL;
    PRT_VALUE* PTMP_tmp1_14 = NULL;
    PRT_VALUE* PTMP_tmp2_14 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_70 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE** P_LVALUE_689 = &(PTMP_tmp0_14);
    PrtFreeValue(*P_LVALUE_689);
    *P_LVALUE_689 = PrtCloneValue(p_this->varValues[3]);
    
    PRT_VALUE** P_LVALUE_690 = &(PTMP_tmp1_14);
    PrtFreeValue(*P_LVALUE_690);
    *P_LVALUE_690 = PrtCloneValue((&P_EVENT_eStartTimer.value));
    
    PRT_VALUE** P_LVALUE_691 = &(PTMP_tmp2_14);
    PrtFreeValue(*P_LVALUE_691);
    *P_LVALUE_691 = PrtCloneValue((&P_LIT_INT32_70));
    
    PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp0_14), PTMP_tmp1_14, 1, &(PTMP_tmp2_14));
    *(&(PTMP_tmp1_14)) = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_21;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_21;
    }
    
    PrtGoto(p_this, 3U, 0);
    
p_return_21: ;
    PrtFreeValue(PTMP_tmp0_14); PTMP_tmp0_14 = NULL;
    PrtFreeValue(PTMP_tmp1_14); PTMP_tmp1_14 = NULL;
    PrtFreeValue(PTMP_tmp2_14); PTMP_tmp2_14 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_13 =
{
    NULL,
    &P_Anon_IMPL_13,
    NULL
};


PRT_VALUE* P_Anon_IMPL_14(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_stateid = argRefs[0];
    PRT_VALUE* PTMP_tmp0_15 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_71 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE** P_LVALUE_692 = &(PTMP_tmp0_15);
    PrtFreeValue(*P_LVALUE_692);
    *P_LVALUE_692 = PrtMkBoolValue(PrtIsEqualValue(*P_VAR_stateid, (&P_LIT_INT32_71)));
    
    if (PrtPrimGetBool(PTMP_tmp0_15))
    {
        PrtGoto(p_this, 4U, 0);
        
    }
    
    else
    {
    }
    
    
p_return_22: ;
    PrtFreeValue(PTMP_tmp0_15); PTMP_tmp0_15 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_14 =
{
    NULL,
    &P_Anon_IMPL_14,
    &P_GEND_TYPE_i
};


PRT_VALUE* P_Anon_IMPL_15(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    
p_return_23: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_15 =
{
    NULL,
    &P_Anon_IMPL_15,
    NULL
};


PRT_VALUE* P_Anon_IMPL_16(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_stateid_1 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_16 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_72 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE** P_LVALUE_693 = &(PTMP_tmp0_16);
    PrtFreeValue(*P_LVALUE_693);
    *P_LVALUE_693 = PrtMkBoolValue(PrtIsEqualValue(*P_VAR_stateid_1, (&P_LIT_INT32_72)));
    
    if (PrtPrimGetBool(PTMP_tmp0_16))
    {
        PrtGoto(p_this, 4U, 0);
        
    }
    
    else
    {
    }
    
    
p_return_24: ;
    PrtFreeValue(PTMP_tmp0_16); PTMP_tmp0_16 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_16 =
{
    NULL,
    &P_Anon_IMPL_16,
    &P_GEND_TYPE_i
};


PRT_VALUE* P_Anon_IMPL_17(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    
p_return_25: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_17 =
{
    NULL,
    &P_Anon_IMPL_17,
    NULL
};


PRT_FUNDECL* P_ChanMachine_METHODS[] = { &P_FUNCTION_Anon_9, &P_FUNCTION_Anon_10, &P_FUNCTION_Anon_11, &P_FUNCTION_Anon_12, &P_FUNCTION_Anon_13, &P_FUNCTION_Anon_14, &P_FUNCTION_Anon_15, &P_FUNCTION_Anon_16, &P_FUNCTION_Anon_17 };

PRT_EVENTDECL* P_ChanMachine_RECV_INNER_1[] = { &P_EVENT_eChanConnected, &P_EVENT_eChanDead, &P_EVENT_eChanGotoConfig, &P_EVENT_eChanGotoConnected, &P_EVENT_eChanStarted, &P_EVENT_eComposetFix, &P_EVENT_eComposetHdr, &P_EVENT_eComposetMsg, &P_EVENT_eComposetPara, &P_EVENT_eComposetPlist, &P_EVENT_eComposetVar, &P_EVENT_eConfReq, &P_EVENT_eConfResp, &P_EVENT_eConnReq, &P_EVENT_eConnResp, &P_EVENT_eGetDefaultValueResp, &P_EVENT_eL2CmdReq, &P_EVENT_eParsetFix, &P_EVENT_eParsetHdr, &P_EVENT_eParsetMsg, &P_EVENT_eParsetPara, &P_EVENT_eParsetPlist, &P_EVENT_eParsetVar, &P_EVENT_eSpecGetDefaultValueReq, &P_EVENT_eStartTimer, &P_EVENT_eTimeOut, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_ChanMachine_RECV_1 =
{
    27U,
    P_ChanMachine_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_ChanMachine_SEND_INNER[] = { &P_EVENT_eChanConnected, &P_EVENT_eChanDead, &P_EVENT_eChanGotoConfig, &P_EVENT_eChanGotoConnected, &P_EVENT_eChanStarted, &P_EVENT_eComposetFix, &P_EVENT_eComposetHdr, &P_EVENT_eComposetMsg, &P_EVENT_eComposetPara, &P_EVENT_eComposetPlist, &P_EVENT_eComposetVar, &P_EVENT_eConfReq, &P_EVENT_eConfResp, &P_EVENT_eConnReq, &P_EVENT_eConnResp, &P_EVENT_eGetDefaultValueResp, &P_EVENT_eL2CmdReq, &P_EVENT_eParsetFix, &P_EVENT_eParsetHdr, &P_EVENT_eParsetMsg, &P_EVENT_eParsetPara, &P_EVENT_eParsetPlist, &P_EVENT_eParsetVar, &P_EVENT_eSpecGetDefaultValueReq, &P_EVENT_eStartTimer, &P_EVENT_eTimeOut, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_ChanMachine_SEND =
{
    27U,
    P_ChanMachine_SEND_INNER,
    NULL
};

PRT_UINT32 P_ChanMachine_CREATES_ARR[] = { 4 };
PRT_INTERFACESETDECL P_ChanMachine_CREATES = { 1, P_ChanMachine_CREATES_ARR };
PRT_MACHINEDECL P_MACHINE_ChanMachine = 
{
    3U,
    "ChanMachine",
    &P_EVENTSET_ChanMachine_RECV_1,
    &P_EVENTSET_ChanMachine_SEND,
    &P_ChanMachine_CREATES,
    7U,
    5U,
    9U,
    4294967295U,
    0U,
    P_ChanMachine_VARS,
    P_ChanMachine_STATES,
    P_ChanMachine_METHODS
};

PRT_VARDECL P_TimerMachine_VARS[] = {
    { "client", &P_GEND_TYPE_m },
    { "timeout", &P_GEND_TYPE_i }
};

PRT_EVENTDECL* P_Init_DEFERS_INNER_4[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DEFERS_4 =
{
    0U,
    P_Init_DEFERS_INNER_4,
    NULL
};

PRT_EVENTDECL* P_Init_TRANS_INNER_4[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_TRANS_4 =
{
    0U,
    P_Init_TRANS_INNER_4,
    NULL
};

PRT_EVENTDECL* P_Init_DOS_INNER_4[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DOS_4 =
{
    0U,
    P_Init_DOS_INNER_4,
    NULL
};

#define P_STATE_TimerMachine_Init \
{ \
    "TimerMachine.Init", \
    0U, \
    0U, \
    &P_EVENTSET_Init_DEFERS_4, \
    &P_EVENTSET_Init_TRANS_4, \
    &P_EVENTSET_Init_DOS_4, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon_18, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_WaitForTimerRequests_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_WaitForTimerRequests_DEFERS =
{
    0U,
    P_WaitForTimerRequests_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_WaitForTimerRequests_TRANS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_WaitForTimerRequests_TRANS =
{
    0U,
    P_WaitForTimerRequests_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_WaitForTimerRequests_DOS_INNER[] = { &P_EVENT_eStartTimer };
PRT_EVENTSETDECL P_EVENTSET_WaitForTimerRequests_DOS =
{
    1U,
    P_WaitForTimerRequests_DOS_INNER,
    NULL
};

PRT_DODECL P_DOS_7[] =
{
    { 1, &P_EVENT_eStartTimer, &P_FUNCTION_Anon_19 }
};

#define P_STATE_TimerMachine_WaitForTimerRequests \
{ \
    "TimerMachine.WaitForTimerRequests", \
    0U, \
    1U, \
    &P_EVENTSET_WaitForTimerRequests_DEFERS, \
    &P_EVENTSET_WaitForTimerRequests_TRANS, \
    &P_EVENTSET_WaitForTimerRequests_DOS, \
    NULL, \
    P_DOS_7, \
    &_P_NO_OP, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_TimerStarted_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_TimerStarted_DEFERS =
{
    0U,
    P_TimerStarted_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_TimerStarted_TRANS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_TimerStarted_TRANS =
{
    0U,
    P_TimerStarted_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_TimerStarted_DOS_INNER[] = { &P_EVENT_eStartTimer };
PRT_EVENTSETDECL P_EVENTSET_TimerStarted_DOS =
{
    1U,
    P_TimerStarted_DOS_INNER,
    NULL
};

PRT_DODECL P_DOS_8[] =
{
    { 2, &P_EVENT_eStartTimer, NULL }
};

#define P_STATE_TimerMachine_TimerStarted \
{ \
    "TimerMachine.TimerStarted", \
    0U, \
    1U, \
    &P_EVENTSET_TimerStarted_DEFERS, \
    &P_EVENTSET_TimerStarted_TRANS, \
    &P_EVENTSET_TimerStarted_DOS, \
    NULL, \
    P_DOS_8, \
    &P_FUNCTION_Anon_20, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_TimerMachine_STATES[] = { P_STATE_TimerMachine_Init, P_STATE_TimerMachine_WaitForTimerRequests, P_STATE_TimerMachine_TimerStarted };

PRT_VALUE* P_Anon_IMPL_18(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_input_2 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_17 = NULL;
    PRT_VALUE* PTMP_tmp1_15 = NULL;
    PRT_VALUE* PTMP_tmp2_15 = NULL;
    PRT_VALUE* PTMP_tmp3_12 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_694 = &(PTMP_tmp0_17);
    PrtFreeValue(*P_LVALUE_694);
    *P_LVALUE_694 = PrtTupleGet(*P_VAR_input_2, 0);
    
    PRT_VALUE** P_LVALUE_695 = &(PTMP_tmp1_15);
    PrtFreeValue(*P_LVALUE_695);
    *P_LVALUE_695 = PrtCloneValue(PTMP_tmp0_17);
    
    {
        PRT_VALUE** P_LVALUE_696 = &(p_this->varValues[0]);
        PrtFreeValue(*P_LVALUE_696);
        *P_LVALUE_696 = PTMP_tmp1_15;
        PTMP_tmp1_15 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_697 = &(PTMP_tmp2_15);
    PrtFreeValue(*P_LVALUE_697);
    *P_LVALUE_697 = PrtTupleGet(*P_VAR_input_2, 1);
    
    PRT_VALUE** P_LVALUE_698 = &(PTMP_tmp3_12);
    PrtFreeValue(*P_LVALUE_698);
    *P_LVALUE_698 = PrtCloneValue(PTMP_tmp2_15);
    
    {
        PRT_VALUE** P_LVALUE_699 = &(p_this->varValues[1]);
        PrtFreeValue(*P_LVALUE_699);
        *P_LVALUE_699 = PTMP_tmp3_12;
        PTMP_tmp3_12 = NULL;
    }
    
    PrtGoto(p_this, 1U, 0);
    
p_return_26: ;
    PrtFreeValue(PTMP_tmp0_17); PTMP_tmp0_17 = NULL;
    PrtFreeValue(PTMP_tmp1_15); PTMP_tmp1_15 = NULL;
    PrtFreeValue(PTMP_tmp2_15); PTMP_tmp2_15 = NULL;
    PrtFreeValue(PTMP_tmp3_12); PTMP_tmp3_12 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_18 =
{
    NULL,
    &P_Anon_IMPL_18,
    &P_GEND_TYPE_NT2mi
};


PRT_VALUE* P_Anon_IMPL_19(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_stateid_2 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_18 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_700 = &(PTMP_tmp0_18);
    PrtFreeValue(*P_LVALUE_700);
    *P_LVALUE_700 = PrtCloneValue(*P_VAR_stateid_2);
    
    PrtGoto(p_this, 2U, 1, &(PTMP_tmp0_18));
    
p_return_27: ;
    PrtFreeValue(PTMP_tmp0_18); PTMP_tmp0_18 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_19 =
{
    NULL,
    &P_Anon_IMPL_19,
    &P_GEND_TYPE_i
};


PRT_VALUE* P_Anon_IMPL_20(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_stateid_3 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_19 = NULL;
    PRT_VALUE* PTMP_tmp1_16 = NULL;
    PRT_VALUE* PTMP_tmp2_16 = NULL;
    PRT_VALUE* PTMP_tmp3_13 = NULL;
    PRT_VALUE* PTMP_tmp4_11 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_73 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE** P_LVALUE_701 = &(PTMP_tmp0_19);
    PrtFreeValue(*P_LVALUE_701);
    *P_LVALUE_701 = PrtMkBoolValue(!PrtIsEqualValue(p_this->varValues[1], (&P_LIT_INT32_73)));
    
    if (PrtPrimGetBool(PTMP_tmp0_19))
    {
        PRT_VALUE** P_LVALUE_702 = &(PTMP_tmp1_16);
        PrtFreeValue(*P_LVALUE_702);
        *P_LVALUE_702 = PrtCloneValue(p_this->varValues[1]);
        
        _P_GEN_funargs[0] = &(PTMP_tmp1_16);
        PrtFreeValue(P_sleepFor_IMPL(context, _P_GEN_funargs));
        PrtFreeValue(PTMP_tmp1_16);
        PTMP_tmp1_16 = NULL;
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_28;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_28;
        }
        
        PRT_VALUE** P_LVALUE_703 = &(PTMP_tmp2_16);
        PrtFreeValue(*P_LVALUE_703);
        *P_LVALUE_703 = PrtCloneValue(p_this->varValues[0]);
        
        PRT_VALUE** P_LVALUE_704 = &(PTMP_tmp3_13);
        PrtFreeValue(*P_LVALUE_704);
        *P_LVALUE_704 = PrtCloneValue((&P_EVENT_eTimeOut.value));
        
        PRT_VALUE** P_LVALUE_705 = &(PTMP_tmp4_11);
        PrtFreeValue(*P_LVALUE_705);
        *P_LVALUE_705 = PrtCloneValue(*P_VAR_stateid_3);
        
        PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp2_16), PTMP_tmp3_13, 1, &(PTMP_tmp4_11));
        *(&(PTMP_tmp3_13)) = NULL;
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_28;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_28;
        }
        
        PrtGoto(p_this, 1U, 0);
        
    }
    
    else
    {
    }
    
    
p_return_28: ;
    PrtFreeValue(PTMP_tmp0_19); PTMP_tmp0_19 = NULL;
    PrtFreeValue(PTMP_tmp1_16); PTMP_tmp1_16 = NULL;
    PrtFreeValue(PTMP_tmp2_16); PTMP_tmp2_16 = NULL;
    PrtFreeValue(PTMP_tmp3_13); PTMP_tmp3_13 = NULL;
    PrtFreeValue(PTMP_tmp4_11); PTMP_tmp4_11 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_20 =
{
    NULL,
    &P_Anon_IMPL_20,
    &P_GEND_TYPE_i
};


PRT_FUNDECL* P_TimerMachine_METHODS[] = { &P_FUNCTION_Anon_18, &P_FUNCTION_Anon_19, &P_FUNCTION_Anon_20 };

PRT_EVENTDECL* P_TimerMachine_RECV_INNER_1[] = { &P_EVENT_eChanConnected, &P_EVENT_eChanDead, &P_EVENT_eChanGotoConfig, &P_EVENT_eChanGotoConnected, &P_EVENT_eChanStarted, &P_EVENT_eComposetFix, &P_EVENT_eComposetHdr, &P_EVENT_eComposetMsg, &P_EVENT_eComposetPara, &P_EVENT_eComposetPlist, &P_EVENT_eComposetVar, &P_EVENT_eConfReq, &P_EVENT_eConfResp, &P_EVENT_eConnReq, &P_EVENT_eConnResp, &P_EVENT_eGetDefaultValueResp, &P_EVENT_eL2CmdReq, &P_EVENT_eParsetFix, &P_EVENT_eParsetHdr, &P_EVENT_eParsetMsg, &P_EVENT_eParsetPara, &P_EVENT_eParsetPlist, &P_EVENT_eParsetVar, &P_EVENT_eSpecGetDefaultValueReq, &P_EVENT_eStartTimer, &P_EVENT_eTimeOut, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_TimerMachine_RECV_1 =
{
    27U,
    P_TimerMachine_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_TimerMachine_SEND_INNER[] = { &P_EVENT_eChanConnected, &P_EVENT_eChanDead, &P_EVENT_eChanGotoConfig, &P_EVENT_eChanGotoConnected, &P_EVENT_eChanStarted, &P_EVENT_eComposetFix, &P_EVENT_eComposetHdr, &P_EVENT_eComposetMsg, &P_EVENT_eComposetPara, &P_EVENT_eComposetPlist, &P_EVENT_eComposetVar, &P_EVENT_eConfReq, &P_EVENT_eConfResp, &P_EVENT_eConnReq, &P_EVENT_eConnResp, &P_EVENT_eGetDefaultValueResp, &P_EVENT_eL2CmdReq, &P_EVENT_eParsetFix, &P_EVENT_eParsetHdr, &P_EVENT_eParsetMsg, &P_EVENT_eParsetPara, &P_EVENT_eParsetPlist, &P_EVENT_eParsetVar, &P_EVENT_eSpecGetDefaultValueReq, &P_EVENT_eStartTimer, &P_EVENT_eTimeOut, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_TimerMachine_SEND =
{
    27U,
    P_TimerMachine_SEND_INNER,
    NULL
};

PRT_MACHINEDECL P_MACHINE_TimerMachine = 
{
    4U,
    "TimerMachine",
    &P_EVENTSET_TimerMachine_RECV_1,
    &P_EVENTSET_TimerMachine_SEND,
    NULL,
    2U,
    3U,
    3U,
    4294967295U,
    0U,
    P_TimerMachine_VARS,
    P_TimerMachine_STATES,
    P_TimerMachine_METHODS
};

PRT_EVENTDECL* P_Init_DEFERS_INNER_5[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DEFERS_5 =
{
    0U,
    P_Init_DEFERS_INNER_5,
    NULL
};

PRT_EVENTDECL* P_Init_TRANS_INNER_5[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_TRANS_5 =
{
    0U,
    P_Init_TRANS_INNER_5,
    NULL
};

PRT_EVENTDECL* P_Init_DOS_INNER_5[] = { &P_EVENT_eComposetFix, &P_EVENT_eComposetHdr, &P_EVENT_eComposetMsg, &P_EVENT_eComposetPara, &P_EVENT_eComposetPlist, &P_EVENT_eComposetVar, &P_EVENT_eParsetFix, &P_EVENT_eParsetHdr, &P_EVENT_eParsetMsg, &P_EVENT_eParsetPara, &P_EVENT_eParsetPlist, &P_EVENT_eParsetVar };
PRT_EVENTSETDECL P_EVENTSET_Init_DOS_5 =
{
    12U,
    P_Init_DOS_INNER_5,
    NULL
};

PRT_DODECL P_DOS_9[] =
{
    { 0, &P_EVENT_eParsetFix, NULL },
    { 0, &P_EVENT_eParsetVar, NULL },
    { 0, &P_EVENT_eParsetHdr, NULL },
    { 0, &P_EVENT_eParsetPara, NULL },
    { 0, &P_EVENT_eParsetPlist, NULL },
    { 0, &P_EVENT_eParsetMsg, NULL },
    { 0, &P_EVENT_eComposetFix, NULL },
    { 0, &P_EVENT_eComposetVar, NULL },
    { 0, &P_EVENT_eComposetHdr, NULL },
    { 0, &P_EVENT_eComposetPara, NULL },
    { 0, &P_EVENT_eComposetPlist, NULL },
    { 0, &P_EVENT_eComposetMsg, NULL }
};

#define P_STATE_MessageFormatSpecMachine_Init \
{ \
    "MessageFormatSpecMachine.Init", \
    0U, \
    12U, \
    &P_EVENTSET_Init_DEFERS_5, \
    &P_EVENTSET_Init_TRANS_5, \
    &P_EVENTSET_Init_DOS_5, \
    NULL, \
    P_DOS_9, \
    &P_FUNCTION_Anon_21, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_Observe_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Observe_DEFERS =
{
    0U,
    P_Observe_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_Observe_TRANS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Observe_TRANS =
{
    0U,
    P_Observe_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_Observe_DOS_INNER[] = { &P_EVENT_eComposetFix, &P_EVENT_eComposetHdr, &P_EVENT_eComposetMsg, &P_EVENT_eComposetPara, &P_EVENT_eComposetPlist, &P_EVENT_eComposetVar, &P_EVENT_eParsetFix, &P_EVENT_eParsetHdr, &P_EVENT_eParsetMsg, &P_EVENT_eParsetPara, &P_EVENT_eParsetPlist, &P_EVENT_eParsetVar };
PRT_EVENTSETDECL P_EVENTSET_Observe_DOS =
{
    12U,
    P_Observe_DOS_INNER,
    NULL
};

PRT_DODECL P_DOS_10[] =
{
    { 1, &P_EVENT_eParsetFix, &P_FUNCTION_Anon_22 },
    { 1, &P_EVENT_eParsetVar, &P_FUNCTION_Anon_23 },
    { 1, &P_EVENT_eParsetHdr, &P_FUNCTION_Anon_24 },
    { 1, &P_EVENT_eParsetPara, &P_FUNCTION_Anon_25 },
    { 1, &P_EVENT_eParsetPlist, &P_FUNCTION_Anon_26 },
    { 1, &P_EVENT_eParsetMsg, &P_FUNCTION_Anon_27 },
    { 1, &P_EVENT_eComposetFix, &P_FUNCTION_Anon_28 },
    { 1, &P_EVENT_eComposetVar, &P_FUNCTION_Anon_29 },
    { 1, &P_EVENT_eComposetHdr, &P_FUNCTION_Anon_30 },
    { 1, &P_EVENT_eComposetPara, &P_FUNCTION_Anon_31 },
    { 1, &P_EVENT_eComposetPlist, &P_FUNCTION_Anon_32 },
    { 1, &P_EVENT_eComposetMsg, &P_FUNCTION_Anon_33 }
};

#define P_STATE_MessageFormatSpecMachine_Observe \
{ \
    "MessageFormatSpecMachine.Observe", \
    0U, \
    12U, \
    &P_EVENTSET_Observe_DEFERS, \
    &P_EVENTSET_Observe_TRANS, \
    &P_EVENTSET_Observe_DOS, \
    NULL, \
    P_DOS_10, \
    &_P_NO_OP, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_MessageFormatSpecMachine_STATES[] = { P_STATE_MessageFormatSpecMachine_Init, P_STATE_MessageFormatSpecMachine_Observe };

PRT_VALUE* P_Anon_IMPL_21(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PrtGoto(p_this, 1U, 0);
    
p_return_29: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_21 =
{
    NULL,
    &P_Anon_IMPL_21,
    NULL
};


PRT_VALUE* P_Anon_IMPL_22(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_value = argRefs[0];
    PRT_VALUE* PTMP_tmp0_20 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_706 = &(PTMP_tmp0_20);
    PrtFreeValue(*P_LVALUE_706);
    *P_LVALUE_706 = PrtCloneValue(*P_VAR_value);
    
    _P_GEN_funargs[0] = &(PTMP_tmp0_20);
    PrtFreeValue(P_checktFix_IMPL(context, _P_GEN_funargs));
    PrtFreeValue(PTMP_tmp0_20);
    PTMP_tmp0_20 = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_30;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_30;
    }
    
p_return_30: ;
    PrtFreeValue(PTMP_tmp0_20); PTMP_tmp0_20 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_22 =
{
    NULL,
    &P_Anon_IMPL_22,
    &P_GEND_TYPE_NT4iiiSi
};


PRT_VALUE* P_Anon_IMPL_23(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_value_1 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_21 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_707 = &(PTMP_tmp0_21);
    PrtFreeValue(*P_LVALUE_707);
    *P_LVALUE_707 = PrtCloneValue(*P_VAR_value_1);
    
    _P_GEN_funargs[0] = &(PTMP_tmp0_21);
    PrtFreeValue(P_checktVar_IMPL(context, _P_GEN_funargs));
    PrtFreeValue(PTMP_tmp0_21);
    PTMP_tmp0_21 = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_31;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_31;
    }
    
p_return_31: ;
    PrtFreeValue(PTMP_tmp0_21); PTMP_tmp0_21 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_23 =
{
    NULL,
    &P_Anon_IMPL_23,
    &P_GEND_TYPE_NT3iiSi
};


PRT_VALUE* P_Anon_IMPL_24(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_value_2 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_22 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_708 = &(PTMP_tmp0_22);
    PrtFreeValue(*P_LVALUE_708);
    *P_LVALUE_708 = PrtCloneValue(*P_VAR_value_2);
    
    _P_GEN_funargs[0] = &(PTMP_tmp0_22);
    PrtFreeValue(P_checktHdr_IMPL(context, _P_GEN_funargs));
    PrtFreeValue(PTMP_tmp0_22);
    PTMP_tmp0_22 = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_32;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_32;
    }
    
p_return_32: ;
    PrtFreeValue(PTMP_tmp0_22); PTMP_tmp0_22 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_24 =
{
    NULL,
    &P_Anon_IMPL_24,
    &P_GEND_TYPE_NT2SNT4iiiSiNT4iiiSi
};


PRT_VALUE* P_Anon_IMPL_25(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_value_3 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_23 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_709 = &(PTMP_tmp0_23);
    PrtFreeValue(*P_LVALUE_709);
    *P_LVALUE_709 = PrtCloneValue(*P_VAR_value_3);
    
    _P_GEN_funargs[0] = &(PTMP_tmp0_23);
    PrtFreeValue(P_checktPara_IMPL(context, _P_GEN_funargs));
    PrtFreeValue(PTMP_tmp0_23);
    PTMP_tmp0_23 = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_33;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_33;
    }
    
p_return_33: ;
    PrtFreeValue(PTMP_tmp0_23); PTMP_tmp0_23 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_25 =
{
    NULL,
    &P_Anon_IMPL_25,
    &P_GEND_TYPE_NT3iNT4iiiSiNT4iiiSi
};


PRT_VALUE* P_Anon_IMPL_26(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_value_4 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_24 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_710 = &(PTMP_tmp0_24);
    PrtFreeValue(*P_LVALUE_710);
    *P_LVALUE_710 = PrtCloneValue(*P_VAR_value_4);
    
    _P_GEN_funargs[0] = &(PTMP_tmp0_24);
    PrtFreeValue(P_checktPlist_IMPL(context, _P_GEN_funargs));
    PrtFreeValue(PTMP_tmp0_24);
    PTMP_tmp0_24 = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_34;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_34;
    }
    
p_return_34: ;
    PrtFreeValue(PTMP_tmp0_24); PTMP_tmp0_24 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_26 =
{
    NULL,
    &P_Anon_IMPL_26,
    &P_GEND_TYPE_NT2iSNT3iNT4iiiSiNT4iiiSi
};


PRT_VALUE* P_Anon_IMPL_27(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_value_5 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_25 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_711 = &(PTMP_tmp0_25);
    PrtFreeValue(*P_LVALUE_711);
    *P_LVALUE_711 = PrtCloneValue(*P_VAR_value_5);
    
    _P_GEN_funargs[0] = &(PTMP_tmp0_25);
    PrtFreeValue(P_checktMsg_IMPL(context, _P_GEN_funargs));
    PrtFreeValue(PTMP_tmp0_25);
    PTMP_tmp0_25 = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_35;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_35;
    }
    
p_return_35: ;
    PrtFreeValue(PTMP_tmp0_25); PTMP_tmp0_25 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_27 =
{
    NULL,
    &P_Anon_IMPL_27,
    &P_GEND_TYPE_NT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB
};


PRT_VALUE* P_Anon_IMPL_28(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_value_6 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_26 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_712 = &(PTMP_tmp0_26);
    PrtFreeValue(*P_LVALUE_712);
    *P_LVALUE_712 = PrtCloneValue(*P_VAR_value_6);
    
    _P_GEN_funargs[0] = &(PTMP_tmp0_26);
    PrtFreeValue(P_checktFix_IMPL(context, _P_GEN_funargs));
    PrtFreeValue(PTMP_tmp0_26);
    PTMP_tmp0_26 = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_36;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_36;
    }
    
p_return_36: ;
    PrtFreeValue(PTMP_tmp0_26); PTMP_tmp0_26 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_28 =
{
    NULL,
    &P_Anon_IMPL_28,
    &P_GEND_TYPE_NT4iiiSi
};


PRT_VALUE* P_Anon_IMPL_29(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_value_7 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_27 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_713 = &(PTMP_tmp0_27);
    PrtFreeValue(*P_LVALUE_713);
    *P_LVALUE_713 = PrtCloneValue(*P_VAR_value_7);
    
    _P_GEN_funargs[0] = &(PTMP_tmp0_27);
    PrtFreeValue(P_checktVar_IMPL(context, _P_GEN_funargs));
    PrtFreeValue(PTMP_tmp0_27);
    PTMP_tmp0_27 = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_37;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_37;
    }
    
p_return_37: ;
    PrtFreeValue(PTMP_tmp0_27); PTMP_tmp0_27 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_29 =
{
    NULL,
    &P_Anon_IMPL_29,
    &P_GEND_TYPE_NT3iiSi
};


PRT_VALUE* P_Anon_IMPL_30(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_value_8 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_28 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_714 = &(PTMP_tmp0_28);
    PrtFreeValue(*P_LVALUE_714);
    *P_LVALUE_714 = PrtCloneValue(*P_VAR_value_8);
    
    _P_GEN_funargs[0] = &(PTMP_tmp0_28);
    PrtFreeValue(P_checktHdr_IMPL(context, _P_GEN_funargs));
    PrtFreeValue(PTMP_tmp0_28);
    PTMP_tmp0_28 = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_38;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_38;
    }
    
p_return_38: ;
    PrtFreeValue(PTMP_tmp0_28); PTMP_tmp0_28 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_30 =
{
    NULL,
    &P_Anon_IMPL_30,
    &P_GEND_TYPE_NT2SNT4iiiSiNT4iiiSi
};


PRT_VALUE* P_Anon_IMPL_31(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_value_9 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_29 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_715 = &(PTMP_tmp0_29);
    PrtFreeValue(*P_LVALUE_715);
    *P_LVALUE_715 = PrtCloneValue(*P_VAR_value_9);
    
    _P_GEN_funargs[0] = &(PTMP_tmp0_29);
    PrtFreeValue(P_checktPara_IMPL(context, _P_GEN_funargs));
    PrtFreeValue(PTMP_tmp0_29);
    PTMP_tmp0_29 = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_39;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_39;
    }
    
p_return_39: ;
    PrtFreeValue(PTMP_tmp0_29); PTMP_tmp0_29 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_31 =
{
    NULL,
    &P_Anon_IMPL_31,
    &P_GEND_TYPE_NT3iNT4iiiSiNT4iiiSi
};


PRT_VALUE* P_Anon_IMPL_32(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_value_10 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_30 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_716 = &(PTMP_tmp0_30);
    PrtFreeValue(*P_LVALUE_716);
    *P_LVALUE_716 = PrtCloneValue(*P_VAR_value_10);
    
    _P_GEN_funargs[0] = &(PTMP_tmp0_30);
    PrtFreeValue(P_checktPlist_IMPL(context, _P_GEN_funargs));
    PrtFreeValue(PTMP_tmp0_30);
    PTMP_tmp0_30 = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_40;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_40;
    }
    
p_return_40: ;
    PrtFreeValue(PTMP_tmp0_30); PTMP_tmp0_30 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_32 =
{
    NULL,
    &P_Anon_IMPL_32,
    &P_GEND_TYPE_NT2iSNT3iNT4iiiSiNT4iiiSi
};


PRT_VALUE* P_Anon_IMPL_33(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_value_11 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_31 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_717 = &(PTMP_tmp0_31);
    PrtFreeValue(*P_LVALUE_717);
    *P_LVALUE_717 = PrtCloneValue(*P_VAR_value_11);
    
    _P_GEN_funargs[0] = &(PTMP_tmp0_31);
    PrtFreeValue(P_checktMsg_IMPL(context, _P_GEN_funargs));
    PrtFreeValue(PTMP_tmp0_31);
    PTMP_tmp0_31 = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_41;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_41;
    }
    
p_return_41: ;
    PrtFreeValue(PTMP_tmp0_31); PTMP_tmp0_31 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_33 =
{
    NULL,
    &P_Anon_IMPL_33,
    &P_GEND_TYPE_NT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB
};


PRT_VALUE* P_checktFix_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_value_12 = argRefs[0];
    PRT_VALUE* P_VAR_val_1 = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* PTMP_tmp0_32 = NULL;
    PRT_VALUE* PTMP_tmp1_17 = NULL;
    PRT_VALUE* PTMP_tmp2_17 = NULL;
    PRT_VALUE* PTMP_tmp3_14 = NULL;
    PRT_VALUE* PTMP_tmp4_12 = NULL;
    PRT_VALUE* PTMP_tmp5_11 = NULL;
    PRT_VALUE* PTMP_tmp6_11 = NULL;
    PRT_VALUE* PTMP_tmp7_10 = NULL;
    PRT_VALUE* PTMP_tmp8_10 = NULL;
    PRT_VALUE* PTMP_tmp9_10 = NULL;
    PRT_VALUE* PTMP_tmp10_9 = NULL;
    PRT_VALUE* PTMP_tmp11_9 = NULL;
    PRT_VALUE* PTMP_tmp12_9 = NULL;
    PRT_VALUE* PTMP_tmp13_9 = NULL;
    PRT_VALUE* PTMP_tmp14_9 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_74 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE** P_LVALUE_718 = &(PTMP_tmp0_32);
    PrtFreeValue(*P_LVALUE_718);
    *P_LVALUE_718 = PrtTupleGet(*P_VAR_value_12, 3);
    
    PRT_VALUE** P_LVALUE_719 = &(PTMP_tmp1_17);
    PrtFreeValue(*P_LVALUE_719);
    *P_LVALUE_719 = ((_P_GEN_funargs[0] = &(PTMP_tmp0_32)), (_P_GEN_funval = P_readBuffer2_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp0_32), PTMP_tmp0_32 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_42;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_42;
    }
    
    {
        PRT_VALUE** P_LVALUE_720 = &(P_VAR_val_1);
        PrtFreeValue(*P_LVALUE_720);
        *P_LVALUE_720 = PTMP_tmp1_17;
        PTMP_tmp1_17 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_721 = &(PTMP_tmp2_17);
    PrtFreeValue(*P_LVALUE_721);
    *P_LVALUE_721 = PrtTupleGet(*P_VAR_value_12, 3);
    
    PRT_VALUE** P_LVALUE_722 = &(PTMP_tmp3_14);
    PrtFreeValue(*P_LVALUE_722);
    *P_LVALUE_722 = PrtMkIntValue(PrtSeqSizeOf(PTMP_tmp2_17));
    
    PRT_VALUE** P_LVALUE_723 = &(PTMP_tmp4_12);
    PrtFreeValue(*P_LVALUE_723);
    *P_LVALUE_723 = PrtTupleGet(*P_VAR_value_12, 0);
    
    PRT_VALUE** P_LVALUE_724 = &(PTMP_tmp5_11);
    PrtFreeValue(*P_LVALUE_724);
    *P_LVALUE_724 = PrtMkBoolValue(PrtIsEqualValue(PTMP_tmp3_14, PTMP_tmp4_12));
    
    PRT_VALUE** P_LVALUE_725 = &(PTMP_tmp6_11);
    PrtFreeValue(*P_LVALUE_725);
    *P_LVALUE_725 = PrtMkStringValue(PrtFormatString("", 0, 0));
    ;
    
    PrtAssert(PrtPrimGetBool(PTMP_tmp5_11), "Plang.Compiler.TypeChecker.AST.Expressions.VariableAccessExpr");
    
    PRT_VALUE** P_LVALUE_726 = &(PTMP_tmp7_10);
    PrtFreeValue(*P_LVALUE_726);
    *P_LVALUE_726 = PrtTupleGet(*P_VAR_value_12, 0);
    
    PRT_VALUE** P_LVALUE_727 = &(PTMP_tmp8_10);
    PrtFreeValue(*P_LVALUE_727);
    *P_LVALUE_727 = PrtMkBoolValue(!PrtIsEqualValue(PTMP_tmp7_10, (&P_LIT_INT32_74)));
    
    if (PrtPrimGetBool(PTMP_tmp8_10))
    {
        PRT_VALUE** P_LVALUE_728 = &(PTMP_tmp9_10);
        PrtFreeValue(*P_LVALUE_728);
        *P_LVALUE_728 = PrtTupleGet(*P_VAR_value_12, 2);
        
        PRT_VALUE** P_LVALUE_729 = &(PTMP_tmp10_9);
        PrtFreeValue(*P_LVALUE_729);
        *P_LVALUE_729 = PrtMkBoolValue(PrtPrimGetInt(P_VAR_val_1) <= PrtPrimGetInt(PTMP_tmp9_10));
        
        PRT_VALUE** P_LVALUE_730 = &(PTMP_tmp13_9);
        PrtFreeValue(*P_LVALUE_730);
        *P_LVALUE_730 = PrtCloneValue(PTMP_tmp10_9);
        
        if (PrtPrimGetBool(PTMP_tmp13_9))
        {
            PRT_VALUE** P_LVALUE_731 = &(PTMP_tmp11_9);
            PrtFreeValue(*P_LVALUE_731);
            *P_LVALUE_731 = PrtTupleGet(*P_VAR_value_12, 1);
            
            PRT_VALUE** P_LVALUE_732 = &(PTMP_tmp12_9);
            PrtFreeValue(*P_LVALUE_732);
            *P_LVALUE_732 = PrtMkBoolValue(PrtPrimGetInt(P_VAR_val_1) >= PrtPrimGetInt(PTMP_tmp11_9));
            
            PRT_VALUE** P_LVALUE_733 = &(PTMP_tmp13_9);
            PrtFreeValue(*P_LVALUE_733);
            *P_LVALUE_733 = PrtCloneValue(PTMP_tmp12_9);
            
        }
        
        
        PRT_VALUE** P_LVALUE_734 = &(PTMP_tmp14_9);
        PrtFreeValue(*P_LVALUE_734);
        *P_LVALUE_734 = PrtMkStringValue(PrtFormatString("", 0, 0));
        ;
        
        PrtAssert(PrtPrimGetBool(PTMP_tmp13_9), "Plang.Compiler.TypeChecker.AST.Expressions.VariableAccessExpr");
        
    }
    
    else
    {
    }
    
    
    goto p_return_42;
    
p_return_42: ;
    PrtFreeValue(P_VAR_val_1); P_VAR_val_1 = NULL;
    PrtFreeValue(PTMP_tmp0_32); PTMP_tmp0_32 = NULL;
    PrtFreeValue(PTMP_tmp1_17); PTMP_tmp1_17 = NULL;
    PrtFreeValue(PTMP_tmp2_17); PTMP_tmp2_17 = NULL;
    PrtFreeValue(PTMP_tmp3_14); PTMP_tmp3_14 = NULL;
    PrtFreeValue(PTMP_tmp4_12); PTMP_tmp4_12 = NULL;
    PrtFreeValue(PTMP_tmp5_11); PTMP_tmp5_11 = NULL;
    PrtFreeValue(PTMP_tmp6_11); PTMP_tmp6_11 = NULL;
    PrtFreeValue(PTMP_tmp7_10); PTMP_tmp7_10 = NULL;
    PrtFreeValue(PTMP_tmp8_10); PTMP_tmp8_10 = NULL;
    PrtFreeValue(PTMP_tmp9_10); PTMP_tmp9_10 = NULL;
    PrtFreeValue(PTMP_tmp10_9); PTMP_tmp10_9 = NULL;
    PrtFreeValue(PTMP_tmp11_9); PTMP_tmp11_9 = NULL;
    PrtFreeValue(PTMP_tmp12_9); PTMP_tmp12_9 = NULL;
    PrtFreeValue(PTMP_tmp13_9); PTMP_tmp13_9 = NULL;
    PrtFreeValue(PTMP_tmp14_9); PTMP_tmp14_9 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_checktFix =
{
    "checktFix",
    &P_checktFix_IMPL,
    NULL
};


PRT_VALUE* P_checktVar_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_value_13 = argRefs[0];
    PRT_VALUE* P_VAR_val_2 = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* PTMP_tmp0_33 = NULL;
    PRT_VALUE* PTMP_tmp1_18 = NULL;
    PRT_VALUE* PTMP_tmp2_18 = NULL;
    PRT_VALUE* PTMP_tmp3_15 = NULL;
    PRT_VALUE* PTMP_tmp4_13 = NULL;
    PRT_VALUE* PTMP_tmp5_12 = NULL;
    PRT_VALUE* PTMP_tmp6_12 = NULL;
    PRT_VALUE* PTMP_tmp7_11 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_735 = &(PTMP_tmp0_33);
    PrtFreeValue(*P_LVALUE_735);
    *P_LVALUE_735 = PrtTupleGet(*P_VAR_value_13, 2);
    
    PRT_VALUE** P_LVALUE_736 = &(PTMP_tmp1_18);
    PrtFreeValue(*P_LVALUE_736);
    *P_LVALUE_736 = PrtMkIntValue(PrtSeqSizeOf(PTMP_tmp0_33));
    
    {
        PRT_VALUE** P_LVALUE_737 = &(P_VAR_val_2);
        PrtFreeValue(*P_LVALUE_737);
        *P_LVALUE_737 = PTMP_tmp1_18;
        PTMP_tmp1_18 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_738 = &(PTMP_tmp2_18);
    PrtFreeValue(*P_LVALUE_738);
    *P_LVALUE_738 = PrtTupleGet(*P_VAR_value_13, 1);
    
    PRT_VALUE** P_LVALUE_739 = &(PTMP_tmp3_15);
    PrtFreeValue(*P_LVALUE_739);
    *P_LVALUE_739 = PrtMkBoolValue(PrtPrimGetInt(P_VAR_val_2) <= PrtPrimGetInt(PTMP_tmp2_18));
    
    PRT_VALUE** P_LVALUE_740 = &(PTMP_tmp6_12);
    PrtFreeValue(*P_LVALUE_740);
    *P_LVALUE_740 = PrtCloneValue(PTMP_tmp3_15);
    
    if (PrtPrimGetBool(PTMP_tmp6_12))
    {
        PRT_VALUE** P_LVALUE_741 = &(PTMP_tmp4_13);
        PrtFreeValue(*P_LVALUE_741);
        *P_LVALUE_741 = PrtTupleGet(*P_VAR_value_13, 0);
        
        PRT_VALUE** P_LVALUE_742 = &(PTMP_tmp5_12);
        PrtFreeValue(*P_LVALUE_742);
        *P_LVALUE_742 = PrtMkBoolValue(PrtPrimGetInt(P_VAR_val_2) >= PrtPrimGetInt(PTMP_tmp4_13));
        
        PRT_VALUE** P_LVALUE_743 = &(PTMP_tmp6_12);
        PrtFreeValue(*P_LVALUE_743);
        *P_LVALUE_743 = PrtCloneValue(PTMP_tmp5_12);
        
    }
    
    
    PRT_VALUE** P_LVALUE_744 = &(PTMP_tmp7_11);
    PrtFreeValue(*P_LVALUE_744);
    *P_LVALUE_744 = PrtMkStringValue(PrtFormatString("", 0, 0));
    ;
    
    PrtAssert(PrtPrimGetBool(PTMP_tmp6_12), "Plang.Compiler.TypeChecker.AST.Expressions.VariableAccessExpr");
    
    goto p_return_43;
    
p_return_43: ;
    PrtFreeValue(P_VAR_val_2); P_VAR_val_2 = NULL;
    PrtFreeValue(PTMP_tmp0_33); PTMP_tmp0_33 = NULL;
    PrtFreeValue(PTMP_tmp1_18); PTMP_tmp1_18 = NULL;
    PrtFreeValue(PTMP_tmp2_18); PTMP_tmp2_18 = NULL;
    PrtFreeValue(PTMP_tmp3_15); PTMP_tmp3_15 = NULL;
    PrtFreeValue(PTMP_tmp4_13); PTMP_tmp4_13 = NULL;
    PrtFreeValue(PTMP_tmp5_12); PTMP_tmp5_12 = NULL;
    PrtFreeValue(PTMP_tmp6_12); PTMP_tmp6_12 = NULL;
    PrtFreeValue(PTMP_tmp7_11); PTMP_tmp7_11 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_checktVar =
{
    "checktVar",
    &P_checktVar_IMPL,
    NULL
};


PRT_VALUE* P_checktHdr_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_value_14 = argRefs[0];
    PRT_VALUE* P_VAR_count = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* PTMP_tmp0_34 = NULL;
    PRT_VALUE* PTMP_tmp1_19 = NULL;
    PRT_VALUE* PTMP_tmp2_19 = NULL;
    PRT_VALUE* PTMP_tmp3_16 = NULL;
    PRT_VALUE* PTMP_tmp4_14 = NULL;
    PRT_VALUE* PTMP_tmp5_13 = NULL;
    PRT_VALUE* PTMP_tmp6_13 = NULL;
    PRT_VALUE* PTMP_tmp7_12 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_75 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE P_LIT_INT32_76 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE P_LIT_BOOLEAN_9 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_TRUE } };
    PRT_VALUE** P_LVALUE_745 = &(P_VAR_count);
    PrtFreeValue(*P_LVALUE_745);
    *P_LVALUE_745 = PrtCloneValue((&P_LIT_INT32_75));
    
    PRT_VALUE** P_LVALUE_746 = &(PTMP_tmp0_34);
    PrtFreeValue(*P_LVALUE_746);
    *P_LVALUE_746 = PrtTupleGet(*P_VAR_value_14, 1);
    
    _P_GEN_funargs[0] = &(PTMP_tmp0_34);
    PrtFreeValue(P_checktFix_IMPL(context, _P_GEN_funargs));
    PrtFreeValue(PTMP_tmp0_34);
    PTMP_tmp0_34 = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_44;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_44;
    }
    
    while (PrtPrimGetBool((&P_LIT_BOOLEAN_9)))
    {
        PRT_VALUE** P_LVALUE_747 = &(PTMP_tmp1_19);
        PrtFreeValue(*P_LVALUE_747);
        *P_LVALUE_747 = PrtTupleGet(*P_VAR_value_14, 0);
        
        PRT_VALUE** P_LVALUE_748 = &(PTMP_tmp2_19);
        PrtFreeValue(*P_LVALUE_748);
        *P_LVALUE_748 = PrtMkIntValue(PrtSeqSizeOf(PTMP_tmp1_19));
        
        PRT_VALUE** P_LVALUE_749 = &(PTMP_tmp3_16);
        PrtFreeValue(*P_LVALUE_749);
        *P_LVALUE_749 = PrtMkBoolValue(PrtPrimGetInt(P_VAR_count) < PrtPrimGetInt(PTMP_tmp2_19));
        
        PRT_VALUE** P_LVALUE_750 = &(PTMP_tmp4_14);
        PrtFreeValue(*P_LVALUE_750);
        *P_LVALUE_750 = PrtCloneValue(PTMP_tmp3_16);
        
        if (PrtPrimGetBool(PTMP_tmp4_14))
        {
        }
        
        else
        {
            break;
            
        }
        
        
        PRT_VALUE** P_LVALUE_751 = &(PTMP_tmp5_13);
        PrtFreeValue(*P_LVALUE_751);
        *P_LVALUE_751 = PrtTupleGet(*P_VAR_value_14, 0);
        
        PRT_VALUE** P_LVALUE_752 = &(PTMP_tmp6_13);
        PrtFreeValue(*P_LVALUE_752);
        *P_LVALUE_752 = PrtSeqGet(PTMP_tmp5_13, P_VAR_count);
        
        _P_GEN_funargs[0] = &(PTMP_tmp6_13);
        PrtFreeValue(P_checktFix_IMPL(context, _P_GEN_funargs));
        PrtFreeValue(PTMP_tmp6_13);
        PTMP_tmp6_13 = NULL;
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_44;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_44;
        }
        
        PRT_VALUE** P_LVALUE_753 = &(PTMP_tmp7_12);
        PrtFreeValue(*P_LVALUE_753);
        *P_LVALUE_753 = PrtMkIntValue(PrtPrimGetInt(P_VAR_count) + PrtPrimGetInt((&P_LIT_INT32_76)));
        
        {
            PRT_VALUE** P_LVALUE_754 = &(P_VAR_count);
            PrtFreeValue(*P_LVALUE_754);
            *P_LVALUE_754 = PTMP_tmp7_12;
            PTMP_tmp7_12 = NULL;
        }
        
    }
    
    
    goto p_return_44;
    
p_return_44: ;
    PrtFreeValue(P_VAR_count); P_VAR_count = NULL;
    PrtFreeValue(PTMP_tmp0_34); PTMP_tmp0_34 = NULL;
    PrtFreeValue(PTMP_tmp1_19); PTMP_tmp1_19 = NULL;
    PrtFreeValue(PTMP_tmp2_19); PTMP_tmp2_19 = NULL;
    PrtFreeValue(PTMP_tmp3_16); PTMP_tmp3_16 = NULL;
    PrtFreeValue(PTMP_tmp4_14); PTMP_tmp4_14 = NULL;
    PrtFreeValue(PTMP_tmp5_13); PTMP_tmp5_13 = NULL;
    PrtFreeValue(PTMP_tmp6_13); PTMP_tmp6_13 = NULL;
    PrtFreeValue(PTMP_tmp7_12); PTMP_tmp7_12 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_checktHdr =
{
    "checktHdr",
    &P_checktHdr_IMPL,
    NULL
};


PRT_VALUE* P_checktPara_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_value_15 = argRefs[0];
    PRT_VALUE* P_VAR_fval = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* PTMP_tmp0_35 = NULL;
    PRT_VALUE* PTMP_tmp1_20 = NULL;
    PRT_VALUE* PTMP_tmp2_20 = NULL;
    PRT_VALUE* PTMP_tmp3_17 = NULL;
    PRT_VALUE* PTMP_tmp4_15 = NULL;
    PRT_VALUE* PTMP_tmp5_14 = NULL;
    PRT_VALUE* PTMP_tmp6_14 = NULL;
    PRT_VALUE* PTMP_tmp7_13 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_755 = &(PTMP_tmp0_35);
    PrtFreeValue(*P_LVALUE_755);
    *P_LVALUE_755 = PrtTupleGet(*P_VAR_value_15, 1);
    
    _P_GEN_funargs[0] = &(PTMP_tmp0_35);
    PrtFreeValue(P_checktFix_IMPL(context, _P_GEN_funargs));
    PrtFreeValue(PTMP_tmp0_35);
    PTMP_tmp0_35 = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_45;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_45;
    }
    
    PRT_VALUE** P_LVALUE_756 = &(PTMP_tmp1_20);
    PrtFreeValue(*P_LVALUE_756);
    *P_LVALUE_756 = PrtTupleGet(*P_VAR_value_15, 1);
    
    PRT_VALUE** P_LVALUE_757 = &(PTMP_tmp2_20);
    PrtFreeValue(*P_LVALUE_757);
    *P_LVALUE_757 = PrtTupleGet(PTMP_tmp1_20, 3);
    
    PRT_VALUE** P_LVALUE_758 = &(PTMP_tmp3_17);
    PrtFreeValue(*P_LVALUE_758);
    *P_LVALUE_758 = ((_P_GEN_funargs[0] = &(PTMP_tmp2_20)), (_P_GEN_funval = P_readBuffer2_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp2_20), PTMP_tmp2_20 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_45;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_45;
    }
    
    {
        PRT_VALUE** P_LVALUE_759 = &(P_VAR_fval);
        PrtFreeValue(*P_LVALUE_759);
        *P_LVALUE_759 = PTMP_tmp3_17;
        PTMP_tmp3_17 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_760 = &(PTMP_tmp4_15);
    PrtFreeValue(*P_LVALUE_760);
    *P_LVALUE_760 = PrtTupleGet(*P_VAR_value_15, 0);
    
    PRT_VALUE** P_LVALUE_761 = &(PTMP_tmp5_14);
    PrtFreeValue(*P_LVALUE_761);
    *P_LVALUE_761 = PrtMkBoolValue(PrtIsEqualValue(PTMP_tmp4_15, P_VAR_fval));
    
    PRT_VALUE** P_LVALUE_762 = &(PTMP_tmp6_14);
    PrtFreeValue(*P_LVALUE_762);
    *P_LVALUE_762 = PrtMkStringValue(PrtFormatString("", 0, 0));
    ;
    
    PrtAssert(PrtPrimGetBool(PTMP_tmp5_14), "Plang.Compiler.TypeChecker.AST.Expressions.VariableAccessExpr");
    
    PRT_VALUE** P_LVALUE_763 = &(PTMP_tmp7_13);
    PrtFreeValue(*P_LVALUE_763);
    *P_LVALUE_763 = PrtTupleGet(*P_VAR_value_15, 2);
    
    _P_GEN_funargs[0] = &(PTMP_tmp7_13);
    PrtFreeValue(P_checktFix_IMPL(context, _P_GEN_funargs));
    PrtFreeValue(PTMP_tmp7_13);
    PTMP_tmp7_13 = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_45;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_45;
    }
    
    goto p_return_45;
    
p_return_45: ;
    PrtFreeValue(P_VAR_fval); P_VAR_fval = NULL;
    PrtFreeValue(PTMP_tmp0_35); PTMP_tmp0_35 = NULL;
    PrtFreeValue(PTMP_tmp1_20); PTMP_tmp1_20 = NULL;
    PrtFreeValue(PTMP_tmp2_20); PTMP_tmp2_20 = NULL;
    PrtFreeValue(PTMP_tmp3_17); PTMP_tmp3_17 = NULL;
    PrtFreeValue(PTMP_tmp4_15); PTMP_tmp4_15 = NULL;
    PrtFreeValue(PTMP_tmp5_14); PTMP_tmp5_14 = NULL;
    PrtFreeValue(PTMP_tmp6_14); PTMP_tmp6_14 = NULL;
    PrtFreeValue(PTMP_tmp7_13); PTMP_tmp7_13 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_checktPara =
{
    "checktPara",
    &P_checktPara_IMPL,
    NULL
};


PRT_VALUE* P_checktPlist_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_value_16 = argRefs[0];
    PRT_VALUE* P_VAR_count_1 = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* PTMP_tmp0_36 = NULL;
    PRT_VALUE* PTMP_tmp1_21 = NULL;
    PRT_VALUE* PTMP_tmp2_21 = NULL;
    PRT_VALUE* PTMP_tmp3_18 = NULL;
    PRT_VALUE* PTMP_tmp4_16 = NULL;
    PRT_VALUE* PTMP_tmp5_15 = NULL;
    PRT_VALUE* PTMP_tmp6_15 = NULL;
    PRT_VALUE* PTMP_tmp7_14 = NULL;
    PRT_VALUE* PTMP_tmp8_11 = NULL;
    PRT_VALUE* PTMP_tmp9_11 = NULL;
    PRT_VALUE* PTMP_tmp10_10 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_77 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE P_LIT_INT32_78 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE P_LIT_BOOLEAN_10 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_TRUE } };
    PRT_VALUE** P_LVALUE_764 = &(P_VAR_count_1);
    PrtFreeValue(*P_LVALUE_764);
    *P_LVALUE_764 = PrtCloneValue((&P_LIT_INT32_77));
    
    PRT_VALUE** P_LVALUE_765 = &(PTMP_tmp0_36);
    PrtFreeValue(*P_LVALUE_765);
    *P_LVALUE_765 = PrtTupleGet(*P_VAR_value_16, 1);
    
    PRT_VALUE** P_LVALUE_766 = &(PTMP_tmp1_21);
    PrtFreeValue(*P_LVALUE_766);
    *P_LVALUE_766 = PrtMkIntValue(PrtSeqSizeOf(PTMP_tmp0_36));
    
    PRT_VALUE** P_LVALUE_767 = &(PTMP_tmp2_21);
    PrtFreeValue(*P_LVALUE_767);
    *P_LVALUE_767 = PrtTupleGet(*P_VAR_value_16, 0);
    
    PRT_VALUE** P_LVALUE_768 = &(PTMP_tmp3_18);
    PrtFreeValue(*P_LVALUE_768);
    *P_LVALUE_768 = PrtMkBoolValue(PrtIsEqualValue(PTMP_tmp1_21, PTMP_tmp2_21));
    
    PRT_VALUE** P_LVALUE_769 = &(PTMP_tmp4_16);
    PrtFreeValue(*P_LVALUE_769);
    *P_LVALUE_769 = PrtMkStringValue(PrtFormatString("", 0, 0));
    ;
    
    PrtAssert(PrtPrimGetBool(PTMP_tmp3_18), "Plang.Compiler.TypeChecker.AST.Expressions.VariableAccessExpr");
    
    while (PrtPrimGetBool((&P_LIT_BOOLEAN_10)))
    {
        PRT_VALUE** P_LVALUE_770 = &(PTMP_tmp5_15);
        PrtFreeValue(*P_LVALUE_770);
        *P_LVALUE_770 = PrtTupleGet(*P_VAR_value_16, 0);
        
        PRT_VALUE** P_LVALUE_771 = &(PTMP_tmp6_15);
        PrtFreeValue(*P_LVALUE_771);
        *P_LVALUE_771 = PrtMkBoolValue(PrtPrimGetInt(P_VAR_count_1) < PrtPrimGetInt(PTMP_tmp5_15));
        
        PRT_VALUE** P_LVALUE_772 = &(PTMP_tmp7_14);
        PrtFreeValue(*P_LVALUE_772);
        *P_LVALUE_772 = PrtCloneValue(PTMP_tmp6_15);
        
        if (PrtPrimGetBool(PTMP_tmp7_14))
        {
        }
        
        else
        {
            break;
            
        }
        
        
        PRT_VALUE** P_LVALUE_773 = &(PTMP_tmp8_11);
        PrtFreeValue(*P_LVALUE_773);
        *P_LVALUE_773 = PrtTupleGet(*P_VAR_value_16, 1);
        
        PRT_VALUE** P_LVALUE_774 = &(PTMP_tmp9_11);
        PrtFreeValue(*P_LVALUE_774);
        *P_LVALUE_774 = PrtSeqGet(PTMP_tmp8_11, P_VAR_count_1);
        
        _P_GEN_funargs[0] = &(PTMP_tmp9_11);
        PrtFreeValue(P_checktPara_IMPL(context, _P_GEN_funargs));
        PrtFreeValue(PTMP_tmp9_11);
        PTMP_tmp9_11 = NULL;
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_46;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_46;
        }
        
        PRT_VALUE** P_LVALUE_775 = &(PTMP_tmp10_10);
        PrtFreeValue(*P_LVALUE_775);
        *P_LVALUE_775 = PrtMkIntValue(PrtPrimGetInt(P_VAR_count_1) + PrtPrimGetInt((&P_LIT_INT32_78)));
        
        {
            PRT_VALUE** P_LVALUE_776 = &(P_VAR_count_1);
            PrtFreeValue(*P_LVALUE_776);
            *P_LVALUE_776 = PTMP_tmp10_10;
            PTMP_tmp10_10 = NULL;
        }
        
    }
    
    
    goto p_return_46;
    
p_return_46: ;
    PrtFreeValue(P_VAR_count_1); P_VAR_count_1 = NULL;
    PrtFreeValue(PTMP_tmp0_36); PTMP_tmp0_36 = NULL;
    PrtFreeValue(PTMP_tmp1_21); PTMP_tmp1_21 = NULL;
    PrtFreeValue(PTMP_tmp2_21); PTMP_tmp2_21 = NULL;
    PrtFreeValue(PTMP_tmp3_18); PTMP_tmp3_18 = NULL;
    PrtFreeValue(PTMP_tmp4_16); PTMP_tmp4_16 = NULL;
    PrtFreeValue(PTMP_tmp5_15); PTMP_tmp5_15 = NULL;
    PrtFreeValue(PTMP_tmp6_15); PTMP_tmp6_15 = NULL;
    PrtFreeValue(PTMP_tmp7_14); PTMP_tmp7_14 = NULL;
    PrtFreeValue(PTMP_tmp8_11); PTMP_tmp8_11 = NULL;
    PrtFreeValue(PTMP_tmp9_11); PTMP_tmp9_11 = NULL;
    PrtFreeValue(PTMP_tmp10_10); PTMP_tmp10_10 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_checktPlist =
{
    "checktPlist",
    &P_checktPlist_IMPL,
    NULL
};


PRT_VALUE* P_checktMsg_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_value_17 = argRefs[0];
    PRT_VALUE* P_VAR_count_2 = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* P_VAR_tmpmsg = PrtMkDefaultValue(&P_GEND_TYPE_NT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB);
    PRT_VALUE* P_VAR_flag = PrtMkDefaultValue(&P_GEND_TYPE_b);
    PRT_VALUE* P_VAR_tmpvar = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* P_VAR_tmpcMsub = PrtMkDefaultValue(&P_GEND_TYPE_NT2iB);
    PRT_VALUE* PTMP_tmp0_37 = NULL;
    PRT_VALUE* PTMP_tmp1_22 = NULL;
    PRT_VALUE* PTMP_tmp2_22 = NULL;
    PRT_VALUE* PTMP_tmp3_19 = NULL;
    PRT_VALUE* PTMP_tmp4_17 = NULL;
    PRT_VALUE* PTMP_tmp5_16 = NULL;
    PRT_VALUE* PTMP_tmp6_16 = NULL;
    PRT_VALUE* PTMP_tmp7_15 = NULL;
    PRT_VALUE* PTMP_tmp8_12 = NULL;
    PRT_VALUE* PTMP_tmp9_12 = NULL;
    PRT_VALUE* PTMP_tmp10_11 = NULL;
    PRT_VALUE* PTMP_tmp11_10 = NULL;
    PRT_VALUE* PTMP_tmp12_10 = NULL;
    PRT_VALUE* PTMP_tmp13_10 = NULL;
    PRT_VALUE* PTMP_tmp14_10 = NULL;
    PRT_VALUE* PTMP_tmp15_7 = NULL;
    PRT_VALUE* PTMP_tmp16_7 = NULL;
    PRT_VALUE* PTMP_tmp17_7 = NULL;
    PRT_VALUE* PTMP_tmp18_7 = NULL;
    PRT_VALUE* PTMP_tmp19_7 = NULL;
    PRT_VALUE* PTMP_tmp20_7 = NULL;
    PRT_VALUE* PTMP_tmp21_7 = NULL;
    PRT_VALUE* PTMP_tmp22_7 = NULL;
    PRT_VALUE* PTMP_tmp23_7 = NULL;
    PRT_VALUE* PTMP_tmp24_6 = NULL;
    PRT_VALUE* PTMP_tmp25_6 = NULL;
    PRT_VALUE* PTMP_tmp26_6 = NULL;
    PRT_VALUE* PTMP_tmp27_6 = NULL;
    PRT_VALUE* PTMP_tmp28_6 = NULL;
    PRT_VALUE* PTMP_tmp29_6 = NULL;
    PRT_VALUE* PTMP_tmp30_6 = NULL;
    PRT_VALUE* PTMP_tmp31_6 = NULL;
    PRT_VALUE* PTMP_tmp32_6 = NULL;
    PRT_VALUE* PTMP_tmp33_5 = NULL;
    PRT_VALUE* PTMP_tmp34_5 = NULL;
    PRT_VALUE* PTMP_tmp35_5 = NULL;
    PRT_VALUE* PTMP_tmp36_5 = NULL;
    PRT_VALUE* PTMP_tmp37_5 = NULL;
    PRT_VALUE* PTMP_tmp38_5 = NULL;
    PRT_VALUE* PTMP_tmp39_5 = NULL;
    PRT_VALUE* PTMP_tmp40_4 = NULL;
    PRT_VALUE* PTMP_tmp41_4 = NULL;
    PRT_VALUE* PTMP_tmp42_4 = NULL;
    PRT_VALUE* PTMP_tmp43_4 = NULL;
    PRT_VALUE* PTMP_tmp44_4 = NULL;
    PRT_VALUE* PTMP_tmp45_4 = NULL;
    PRT_VALUE* PTMP_tmp46_4 = NULL;
    PRT_VALUE* PTMP_tmp47_4 = NULL;
    PRT_VALUE* PTMP_tmp48_4 = NULL;
    PRT_VALUE* PTMP_tmp49_4 = NULL;
    PRT_VALUE* PTMP_tmp50_4 = NULL;
    PRT_VALUE* PTMP_tmp51_4 = NULL;
    PRT_VALUE* PTMP_tmp52_4 = NULL;
    PRT_VALUE* PTMP_tmp53_4 = NULL;
    PRT_VALUE* PTMP_tmp54_4 = NULL;
    PRT_VALUE* PTMP_tmp55_4 = NULL;
    PRT_VALUE* PTMP_tmp56_4 = NULL;
    PRT_VALUE* PTMP_tmp57_4 = NULL;
    PRT_VALUE* PTMP_tmp58_4 = NULL;
    PRT_VALUE* PTMP_tmp59_4 = NULL;
    PRT_VALUE* PTMP_tmp60_4 = NULL;
    PRT_VALUE* PTMP_tmp61_4 = NULL;
    PRT_VALUE* PTMP_tmp62_4 = NULL;
    PRT_VALUE* PTMP_tmp63_4 = NULL;
    PRT_VALUE* PTMP_tmp64_4 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_79 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE P_LIT_INT32_80 = { PRT_VALUE_KIND_INT, { .nt = 5 } };
    PRT_VALUE P_LIT_INT32_81 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE P_LIT_INT32_82 = { PRT_VALUE_KIND_INT, { .nt = 2 } };
    PRT_VALUE P_LIT_INT32_83 = { PRT_VALUE_KIND_INT, { .nt = 3 } };
    PRT_VALUE P_LIT_INT32_84 = { PRT_VALUE_KIND_INT, { .nt = 4 } };
    PRT_VALUE P_LIT_BOOLEAN_11 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_TRUE } };
    PRT_VALUE** P_LVALUE_777 = &(P_VAR_count_2);
    PrtFreeValue(*P_LVALUE_777);
    *P_LVALUE_777 = PrtCloneValue((&P_LIT_INT32_79));
    
    PRT_VALUE** P_LVALUE_778 = &(PTMP_tmp0_37);
    PrtFreeValue(*P_LVALUE_778);
    *P_LVALUE_778 = PrtTupleGet(*P_VAR_value_17, 0);
    
    PRT_VALUE** P_LVALUE_779 = &(PTMP_tmp1_22);
    PrtFreeValue(*P_LVALUE_779);
    *P_LVALUE_779 = PrtMkBoolValue(PrtPrimGetInt(PTMP_tmp0_37) >= PrtPrimGetInt((&P_LIT_INT32_79)));
    
    PRT_VALUE** P_LVALUE_780 = &(PTMP_tmp4_17);
    PrtFreeValue(*P_LVALUE_780);
    *P_LVALUE_780 = PrtCloneValue(PTMP_tmp1_22);
    
    if (PrtPrimGetBool(PTMP_tmp4_17))
    {
        PRT_VALUE** P_LVALUE_781 = &(PTMP_tmp2_22);
        PrtFreeValue(*P_LVALUE_781);
        *P_LVALUE_781 = PrtTupleGet(*P_VAR_value_17, 0);
        
        PRT_VALUE** P_LVALUE_782 = &(PTMP_tmp3_19);
        PrtFreeValue(*P_LVALUE_782);
        *P_LVALUE_782 = PrtMkBoolValue(PrtPrimGetInt(PTMP_tmp2_22) <= PrtPrimGetInt((&P_LIT_INT32_80)));
        
        PRT_VALUE** P_LVALUE_783 = &(PTMP_tmp4_17);
        PrtFreeValue(*P_LVALUE_783);
        *P_LVALUE_783 = PrtCloneValue(PTMP_tmp3_19);
        
    }
    
    
    PRT_VALUE** P_LVALUE_784 = &(PTMP_tmp5_16);
    PrtFreeValue(*P_LVALUE_784);
    *P_LVALUE_784 = PrtMkStringValue(PrtFormatString("", 0, 0));
    ;
    
    PrtAssert(PrtPrimGetBool(PTMP_tmp4_17), "Plang.Compiler.TypeChecker.AST.Expressions.VariableAccessExpr");
    
    PRT_VALUE** P_LVALUE_785 = &(PTMP_tmp6_16);
    PrtFreeValue(*P_LVALUE_785);
    *P_LVALUE_785 = PrtTupleGet(*P_VAR_value_17, 0);
    
    PRT_VALUE** P_LVALUE_786 = &(PTMP_tmp7_15);
    PrtFreeValue(*P_LVALUE_786);
    *P_LVALUE_786 = PrtMkBoolValue(PrtIsEqualValue(PTMP_tmp6_16, (&P_LIT_INT32_79)));
    
    if (PrtPrimGetBool(PTMP_tmp7_15))
    {
        PRT_VALUE** P_LVALUE_787 = &(PTMP_tmp8_12);
        PrtFreeValue(*P_LVALUE_787);
        *P_LVALUE_787 = PrtTupleGet(*P_VAR_value_17, 1);
        
        _P_GEN_funargs[0] = &(PTMP_tmp8_12);
        PrtFreeValue(P_checktVar_IMPL(context, _P_GEN_funargs));
        PrtFreeValue(PTMP_tmp8_12);
        PTMP_tmp8_12 = NULL;
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_47;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_47;
        }
        
    }
    
    else
    {
        PRT_VALUE** P_LVALUE_788 = &(PTMP_tmp9_12);
        PrtFreeValue(*P_LVALUE_788);
        *P_LVALUE_788 = PrtTupleGet(*P_VAR_value_17, 0);
        
        PRT_VALUE** P_LVALUE_789 = &(PTMP_tmp10_11);
        PrtFreeValue(*P_LVALUE_789);
        *P_LVALUE_789 = PrtMkBoolValue(PrtIsEqualValue(PTMP_tmp9_12, (&P_LIT_INT32_81)));
        
        if (PrtPrimGetBool(PTMP_tmp10_11))
        {
            PRT_VALUE** P_LVALUE_790 = &(PTMP_tmp11_10);
            PrtFreeValue(*P_LVALUE_790);
            *P_LVALUE_790 = PrtTupleGet(*P_VAR_value_17, 2);
            
            _P_GEN_funargs[0] = &(PTMP_tmp11_10);
            PrtFreeValue(P_checktPara_IMPL(context, _P_GEN_funargs));
            PrtFreeValue(PTMP_tmp11_10);
            PTMP_tmp11_10 = NULL;
            if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                goto p_return_47;
            }
            if (p_this->isHalted == PRT_TRUE) {
                PrtFreeValue(_P_GEN_retval);
                _P_GEN_retval = NULL;
                goto p_return_47;
            }
            
        }
        
        else
        {
            PRT_VALUE** P_LVALUE_791 = &(PTMP_tmp12_10);
            PrtFreeValue(*P_LVALUE_791);
            *P_LVALUE_791 = PrtTupleGet(*P_VAR_value_17, 0);
            
            PRT_VALUE** P_LVALUE_792 = &(PTMP_tmp13_10);
            PrtFreeValue(*P_LVALUE_792);
            *P_LVALUE_792 = PrtMkBoolValue(PrtIsEqualValue(PTMP_tmp12_10, (&P_LIT_INT32_82)));
            
            if (PrtPrimGetBool(PTMP_tmp13_10))
            {
                PRT_VALUE** P_LVALUE_793 = &(P_VAR_count_2);
                PrtFreeValue(*P_LVALUE_793);
                *P_LVALUE_793 = PrtCloneValue((&P_LIT_INT32_79));
                
                while (PrtPrimGetBool((&P_LIT_BOOLEAN_11)))
                {
                    PRT_VALUE** P_LVALUE_794 = &(PTMP_tmp14_10);
                    PrtFreeValue(*P_LVALUE_794);
                    *P_LVALUE_794 = PrtTupleGet(*P_VAR_value_17, 3);
                    
                    PRT_VALUE** P_LVALUE_795 = &(PTMP_tmp15_7);
                    PrtFreeValue(*P_LVALUE_795);
                    *P_LVALUE_795 = PrtMkIntValue(PrtSeqSizeOf(PTMP_tmp14_10));
                    
                    PRT_VALUE** P_LVALUE_796 = &(PTMP_tmp16_7);
                    PrtFreeValue(*P_LVALUE_796);
                    *P_LVALUE_796 = PrtMkBoolValue(PrtPrimGetInt(P_VAR_count_2) < PrtPrimGetInt(PTMP_tmp15_7));
                    
                    PRT_VALUE** P_LVALUE_797 = &(PTMP_tmp17_7);
                    PrtFreeValue(*P_LVALUE_797);
                    *P_LVALUE_797 = PrtCloneValue(PTMP_tmp16_7);
                    
                    if (PrtPrimGetBool(PTMP_tmp17_7))
                    {
                    }
                    
                    else
                    {
                        break;
                        
                    }
                    
                    
                    PRT_VALUE** P_LVALUE_798 = &(PTMP_tmp18_7);
                    PrtFreeValue(*P_LVALUE_798);
                    *P_LVALUE_798 = PrtTupleGet(*P_VAR_value_17, 3);
                    
                    PRT_VALUE** P_LVALUE_799 = &(PTMP_tmp19_7);
                    PrtFreeValue(*P_LVALUE_799);
                    *P_LVALUE_799 = PrtSeqGet(PTMP_tmp18_7, P_VAR_count_2);
                    
                    _P_GEN_funargs[0] = &(PTMP_tmp19_7);
                    PrtFreeValue(P_checktFix_IMPL(context, _P_GEN_funargs));
                    PrtFreeValue(PTMP_tmp19_7);
                    PTMP_tmp19_7 = NULL;
                    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                        goto p_return_47;
                    }
                    if (p_this->isHalted == PRT_TRUE) {
                        PrtFreeValue(_P_GEN_retval);
                        _P_GEN_retval = NULL;
                        goto p_return_47;
                    }
                    
                    PRT_VALUE** P_LVALUE_800 = &(PTMP_tmp20_7);
                    PrtFreeValue(*P_LVALUE_800);
                    *P_LVALUE_800 = PrtMkIntValue(PrtPrimGetInt(P_VAR_count_2) + PrtPrimGetInt((&P_LIT_INT32_81)));
                    
                    {
                        PRT_VALUE** P_LVALUE_801 = &(P_VAR_count_2);
                        PrtFreeValue(*P_LVALUE_801);
                        *P_LVALUE_801 = PTMP_tmp20_7;
                        PTMP_tmp20_7 = NULL;
                    }
                    
                }
                
                
            }
            
            else
            {
                PRT_VALUE** P_LVALUE_802 = &(PTMP_tmp21_7);
                PrtFreeValue(*P_LVALUE_802);
                *P_LVALUE_802 = PrtTupleGet(*P_VAR_value_17, 0);
                
                PRT_VALUE** P_LVALUE_803 = &(PTMP_tmp22_7);
                PrtFreeValue(*P_LVALUE_803);
                *P_LVALUE_803 = PrtMkBoolValue(PrtIsEqualValue(PTMP_tmp21_7, (&P_LIT_INT32_83)));
                
                if (PrtPrimGetBool(PTMP_tmp22_7))
                {
                    PRT_VALUE** P_LVALUE_804 = &(PTMP_tmp23_7);
                    PrtFreeValue(*P_LVALUE_804);
                    *P_LVALUE_804 = PrtTupleGet(*P_VAR_value_17, 4);
                    
                    _P_GEN_funargs[0] = &(PTMP_tmp23_7);
                    PrtFreeValue(P_checktPlist_IMPL(context, _P_GEN_funargs));
                    PrtFreeValue(PTMP_tmp23_7);
                    PTMP_tmp23_7 = NULL;
                    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                        goto p_return_47;
                    }
                    if (p_this->isHalted == PRT_TRUE) {
                        PrtFreeValue(_P_GEN_retval);
                        _P_GEN_retval = NULL;
                        goto p_return_47;
                    }
                    
                }
                
                else
                {
                    PRT_VALUE** P_LVALUE_805 = &(PTMP_tmp24_6);
                    PrtFreeValue(*P_LVALUE_805);
                    *P_LVALUE_805 = PrtTupleGet(*P_VAR_value_17, 0);
                    
                    PRT_VALUE** P_LVALUE_806 = &(PTMP_tmp25_6);
                    PrtFreeValue(*P_LVALUE_806);
                    *P_LVALUE_806 = PrtMkBoolValue(PrtIsEqualValue(PTMP_tmp24_6, (&P_LIT_INT32_84)));
                    
                    if (PrtPrimGetBool(PTMP_tmp25_6))
                    {
                        PRT_VALUE** P_LVALUE_807 = &(PTMP_tmp26_6);
                        PrtFreeValue(*P_LVALUE_807);
                        *P_LVALUE_807 = PrtTupleGet(*P_VAR_value_17, 5);
                        
                        PRT_VALUE** P_LVALUE_808 = &(PTMP_tmp27_6);
                        PrtFreeValue(*P_LVALUE_808);
                        *P_LVALUE_808 = PrtTupleGet(PTMP_tmp26_6, 0);
                        
                        _P_GEN_funargs[0] = &(PTMP_tmp27_6);
                        PrtFreeValue(P_checktHdr_IMPL(context, _P_GEN_funargs));
                        PrtFreeValue(PTMP_tmp27_6);
                        PTMP_tmp27_6 = NULL;
                        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                            goto p_return_47;
                        }
                        if (p_this->isHalted == PRT_TRUE) {
                            PrtFreeValue(_P_GEN_retval);
                            _P_GEN_retval = NULL;
                            goto p_return_47;
                        }
                        
                        PRT_VALUE** P_LVALUE_809 = &(PTMP_tmp28_6);
                        PrtFreeValue(*P_LVALUE_809);
                        *P_LVALUE_809 = PrtTupleGet(*P_VAR_value_17, 5);
                        
                        PRT_VALUE** P_LVALUE_810 = &(PTMP_tmp29_6);
                        PrtFreeValue(*P_LVALUE_810);
                        *P_LVALUE_810 = PrtTupleGet(PTMP_tmp28_6, 1);
                        
                        PRT_VALUE** P_LVALUE_811 = &(PTMP_tmp30_6);
                        PrtFreeValue(*P_LVALUE_811);
                        *P_LVALUE_811 = PrtCloneValue(PrtCastValue(PrtCloneValue(PTMP_tmp29_6), &P_GEND_TYPE_NT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB));
                        
                        {
                            PRT_VALUE** P_LVALUE_812 = &(P_VAR_tmpmsg);
                            PrtFreeValue(*P_LVALUE_812);
                            *P_LVALUE_812 = PTMP_tmp30_6;
                            PTMP_tmp30_6 = NULL;
                        }
                        
                        PRT_VALUE** P_LVALUE_813 = &(PTMP_tmp31_6);
                        PrtFreeValue(*P_LVALUE_813);
                        *P_LVALUE_813 = PrtCloneValue(P_VAR_tmpmsg);
                        
                        _P_GEN_funargs[0] = &(PTMP_tmp31_6);
                        PrtFreeValue(P_checktMsg_IMPL(context, _P_GEN_funargs));
                        PrtFreeValue(PTMP_tmp31_6);
                        PTMP_tmp31_6 = NULL;
                        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                            goto p_return_47;
                        }
                        if (p_this->isHalted == PRT_TRUE) {
                            PrtFreeValue(_P_GEN_retval);
                            _P_GEN_retval = NULL;
                            goto p_return_47;
                        }
                        
                    }
                    
                    else
                    {
                        PRT_VALUE** P_LVALUE_814 = &(PTMP_tmp32_6);
                        PrtFreeValue(*P_LVALUE_814);
                        *P_LVALUE_814 = PrtTupleGet(*P_VAR_value_17, 0);
                        
                        PRT_VALUE** P_LVALUE_815 = &(PTMP_tmp33_5);
                        PrtFreeValue(*P_LVALUE_815);
                        *P_LVALUE_815 = PrtMkBoolValue(PrtIsEqualValue(PTMP_tmp32_6, (&P_LIT_INT32_80)));
                        
                        if (PrtPrimGetBool(PTMP_tmp33_5))
                        {
                            PRT_VALUE** P_LVALUE_816 = &(PTMP_tmp34_5);
                            PrtFreeValue(*P_LVALUE_816);
                            *P_LVALUE_816 = PrtTupleGet(*P_VAR_value_17, 6);
                            
                            PRT_VALUE** P_LVALUE_817 = &(PTMP_tmp35_5);
                            PrtFreeValue(*P_LVALUE_817);
                            *P_LVALUE_817 = PrtTupleGet(PTMP_tmp34_5, 0);
                            
                            _P_GEN_funargs[0] = &(PTMP_tmp35_5);
                            PrtFreeValue(P_checktHdr_IMPL(context, _P_GEN_funargs));
                            PrtFreeValue(PTMP_tmp35_5);
                            PTMP_tmp35_5 = NULL;
                            if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                                goto p_return_47;
                            }
                            if (p_this->isHalted == PRT_TRUE) {
                                PrtFreeValue(_P_GEN_retval);
                                _P_GEN_retval = NULL;
                                goto p_return_47;
                            }
                            
                            PRT_VALUE** P_LVALUE_818 = &(PTMP_tmp36_5);
                            PrtFreeValue(*P_LVALUE_818);
                            *P_LVALUE_818 = PrtTupleGet(*P_VAR_value_17, 6);
                            
                            PRT_VALUE** P_LVALUE_819 = &(PTMP_tmp37_5);
                            PrtFreeValue(*P_LVALUE_819);
                            *P_LVALUE_819 = PrtTupleGet(PTMP_tmp36_5, 0);
                            
                            PRT_VALUE** P_LVALUE_820 = &(PTMP_tmp38_5);
                            PrtFreeValue(*P_LVALUE_820);
                            *P_LVALUE_820 = PrtTupleGet(PTMP_tmp37_5, 0);
                            
                            PRT_VALUE** P_LVALUE_821 = &(PTMP_tmp39_5);
                            PrtFreeValue(*P_LVALUE_821);
                            *P_LVALUE_821 = PrtMkIntValue(PrtSeqSizeOf(PTMP_tmp38_5));
                            
                            PRT_VALUE** P_LVALUE_822 = &(PTMP_tmp40_4);
                            PrtFreeValue(*P_LVALUE_822);
                            *P_LVALUE_822 = PrtMkBoolValue(PrtPrimGetInt(PTMP_tmp39_5) >= PrtPrimGetInt((&P_LIT_INT32_81)));
                            
                            PRT_VALUE** P_LVALUE_823 = &(PTMP_tmp41_4);
                            PrtFreeValue(*P_LVALUE_823);
                            *P_LVALUE_823 = PrtMkStringValue(PrtFormatString("", 0, 0));
                            ;
                            
                            PrtAssert(PrtPrimGetBool(PTMP_tmp40_4), "Plang.Compiler.TypeChecker.AST.Expressions.VariableAccessExpr");
                            
                            PRT_VALUE** P_LVALUE_824 = &(PTMP_tmp42_4);
                            PrtFreeValue(*P_LVALUE_824);
                            *P_LVALUE_824 = PrtTupleGet(*P_VAR_value_17, 6);
                            
                            PRT_VALUE** P_LVALUE_825 = &(PTMP_tmp43_4);
                            PrtFreeValue(*P_LVALUE_825);
                            *P_LVALUE_825 = PrtTupleGet(PTMP_tmp42_4, 0);
                            
                            PRT_VALUE** P_LVALUE_826 = &(PTMP_tmp44_4);
                            PrtFreeValue(*P_LVALUE_826);
                            *P_LVALUE_826 = PrtTupleGet(PTMP_tmp43_4, 0);
                            
                            PRT_VALUE** P_LVALUE_827 = &(PTMP_tmp45_4);
                            PrtFreeValue(*P_LVALUE_827);
                            *P_LVALUE_827 = PrtSeqGet(PTMP_tmp44_4, (&P_LIT_INT32_79));
                            
                            PRT_VALUE** P_LVALUE_828 = &(PTMP_tmp46_4);
                            PrtFreeValue(*P_LVALUE_828);
                            *P_LVALUE_828 = PrtTupleGet(PTMP_tmp45_4, 3);
                            
                            PRT_VALUE** P_LVALUE_829 = &(PTMP_tmp47_4);
                            PrtFreeValue(*P_LVALUE_829);
                            *P_LVALUE_829 = ((_P_GEN_funargs[0] = &(PTMP_tmp46_4)), (_P_GEN_funval = P_readBuffer2_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp46_4), PTMP_tmp46_4 = NULL), (_P_GEN_funval));
                            if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                                goto p_return_47;
                            }
                            if (p_this->isHalted == PRT_TRUE) {
                                PrtFreeValue(_P_GEN_retval);
                                _P_GEN_retval = NULL;
                                goto p_return_47;
                            }
                            
                            {
                                PRT_VALUE** P_LVALUE_830 = &(P_VAR_tmpvar);
                                PrtFreeValue(*P_LVALUE_830);
                                *P_LVALUE_830 = PTMP_tmp47_4;
                                PTMP_tmp47_4 = NULL;
                            }
                            
                            PRT_VALUE** P_LVALUE_831 = &(P_VAR_count_2);
                            PrtFreeValue(*P_LVALUE_831);
                            *P_LVALUE_831 = PrtCloneValue((&P_LIT_INT32_79));
                            
                            while (PrtPrimGetBool((&P_LIT_BOOLEAN_11)))
                            {
                                PRT_VALUE** P_LVALUE_832 = &(PTMP_tmp48_4);
                                PrtFreeValue(*P_LVALUE_832);
                                *P_LVALUE_832 = PrtTupleGet(*P_VAR_value_17, 6);
                                
                                PRT_VALUE** P_LVALUE_833 = &(PTMP_tmp49_4);
                                PrtFreeValue(*P_LVALUE_833);
                                *P_LVALUE_833 = PrtTupleGet(PTMP_tmp48_4, 1);
                                
                                PRT_VALUE** P_LVALUE_834 = &(PTMP_tmp50_4);
                                PrtFreeValue(*P_LVALUE_834);
                                *P_LVALUE_834 = PrtMkIntValue(PrtSeqSizeOf(PTMP_tmp49_4));
                                
                                PRT_VALUE** P_LVALUE_835 = &(PTMP_tmp51_4);
                                PrtFreeValue(*P_LVALUE_835);
                                *P_LVALUE_835 = PrtMkBoolValue(PrtPrimGetInt(P_VAR_count_2) < PrtPrimGetInt(PTMP_tmp50_4));
                                
                                PRT_VALUE** P_LVALUE_836 = &(PTMP_tmp52_4);
                                PrtFreeValue(*P_LVALUE_836);
                                *P_LVALUE_836 = PrtCloneValue(PTMP_tmp51_4);
                                
                                if (PrtPrimGetBool(PTMP_tmp52_4))
                                {
                                }
                                
                                else
                                {
                                    break;
                                    
                                }
                                
                                
                                PRT_VALUE** P_LVALUE_837 = &(PTMP_tmp53_4);
                                PrtFreeValue(*P_LVALUE_837);
                                *P_LVALUE_837 = PrtTupleGet(*P_VAR_value_17, 6);
                                
                                PRT_VALUE** P_LVALUE_838 = &(PTMP_tmp54_4);
                                PrtFreeValue(*P_LVALUE_838);
                                *P_LVALUE_838 = PrtTupleGet(PTMP_tmp53_4, 1);
                                
                                PRT_VALUE** P_LVALUE_839 = &(PTMP_tmp55_4);
                                PrtFreeValue(*P_LVALUE_839);
                                *P_LVALUE_839 = PrtSeqGet(PTMP_tmp54_4, P_VAR_count_2);
                                
                                PRT_VALUE** P_LVALUE_840 = &(PTMP_tmp56_4);
                                PrtFreeValue(*P_LVALUE_840);
                                *P_LVALUE_840 = PrtCloneValue(PTMP_tmp55_4);
                                
                                {
                                    PRT_VALUE** P_LVALUE_841 = &(P_VAR_tmpcMsub);
                                    PrtFreeValue(*P_LVALUE_841);
                                    *P_LVALUE_841 = PTMP_tmp56_4;
                                    PTMP_tmp56_4 = NULL;
                                }
                                
                                PRT_VALUE** P_LVALUE_842 = &(PTMP_tmp57_4);
                                PrtFreeValue(*P_LVALUE_842);
                                *P_LVALUE_842 = PrtTupleGet(P_VAR_tmpcMsub, 1);
                                
                                PRT_VALUE** P_LVALUE_843 = &(PTMP_tmp58_4);
                                PrtFreeValue(*P_LVALUE_843);
                                *P_LVALUE_843 = PrtCloneValue(PrtCastValue(PrtCloneValue(PTMP_tmp57_4), &P_GEND_TYPE_NT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB));
                                
                                {
                                    PRT_VALUE** P_LVALUE_844 = &(P_VAR_tmpmsg);
                                    PrtFreeValue(*P_LVALUE_844);
                                    *P_LVALUE_844 = PTMP_tmp58_4;
                                    PTMP_tmp58_4 = NULL;
                                }
                                
                                PRT_VALUE** P_LVALUE_845 = &(PTMP_tmp59_4);
                                PrtFreeValue(*P_LVALUE_845);
                                *P_LVALUE_845 = PrtCloneValue(P_VAR_tmpmsg);
                                
                                _P_GEN_funargs[0] = &(PTMP_tmp59_4);
                                PrtFreeValue(P_checktMsg_IMPL(context, _P_GEN_funargs));
                                PrtFreeValue(PTMP_tmp59_4);
                                PTMP_tmp59_4 = NULL;
                                if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                                    goto p_return_47;
                                }
                                if (p_this->isHalted == PRT_TRUE) {
                                    PrtFreeValue(_P_GEN_retval);
                                    _P_GEN_retval = NULL;
                                    goto p_return_47;
                                }
                                
                                PRT_VALUE** P_LVALUE_846 = &(PTMP_tmp60_4);
                                PrtFreeValue(*P_LVALUE_846);
                                *P_LVALUE_846 = PrtTupleGet(P_VAR_tmpcMsub, 0);
                                
                                PRT_VALUE** P_LVALUE_847 = &(PTMP_tmp61_4);
                                PrtFreeValue(*P_LVALUE_847);
                                *P_LVALUE_847 = PrtMkBoolValue(PrtIsEqualValue(PTMP_tmp60_4, P_VAR_tmpvar));
                                
                                if (PrtPrimGetBool(PTMP_tmp61_4))
                                {
                                    PRT_VALUE** P_LVALUE_848 = &(P_VAR_flag);
                                    PrtFreeValue(*P_LVALUE_848);
                                    *P_LVALUE_848 = PrtCloneValue((&P_LIT_BOOLEAN_11));
                                    
                                }
                                
                                else
                                {
                                }
                                
                                
                                PRT_VALUE** P_LVALUE_849 = &(PTMP_tmp62_4);
                                PrtFreeValue(*P_LVALUE_849);
                                *P_LVALUE_849 = PrtMkIntValue(PrtPrimGetInt(P_VAR_count_2) + PrtPrimGetInt((&P_LIT_INT32_81)));
                                
                                {
                                    PRT_VALUE** P_LVALUE_850 = &(P_VAR_count_2);
                                    PrtFreeValue(*P_LVALUE_850);
                                    *P_LVALUE_850 = PTMP_tmp62_4;
                                    PTMP_tmp62_4 = NULL;
                                }
                                
                            }
                            
                            
                            PRT_VALUE** P_LVALUE_851 = &(PTMP_tmp63_4);
                            PrtFreeValue(*P_LVALUE_851);
                            *P_LVALUE_851 = PrtMkBoolValue(PrtIsEqualValue(P_VAR_flag, (&P_LIT_BOOLEAN_11)));
                            
                            PRT_VALUE** P_LVALUE_852 = &(PTMP_tmp64_4);
                            PrtFreeValue(*P_LVALUE_852);
                            *P_LVALUE_852 = PrtMkStringValue(PrtFormatString("", 0, 0));
                            ;
                            
                            PrtAssert(PrtPrimGetBool(PTMP_tmp63_4), "Plang.Compiler.TypeChecker.AST.Expressions.VariableAccessExpr");
                            
                        }
                        
                        else
                        {
                        }
                        
                        
                    }
                    
                    
                }
                
                
            }
            
            
        }
        
        
    }
    
    
    goto p_return_47;
    
p_return_47: ;
    PrtFreeValue(P_VAR_count_2); P_VAR_count_2 = NULL;
    PrtFreeValue(P_VAR_tmpmsg); P_VAR_tmpmsg = NULL;
    PrtFreeValue(P_VAR_flag); P_VAR_flag = NULL;
    PrtFreeValue(P_VAR_tmpvar); P_VAR_tmpvar = NULL;
    PrtFreeValue(P_VAR_tmpcMsub); P_VAR_tmpcMsub = NULL;
    PrtFreeValue(PTMP_tmp0_37); PTMP_tmp0_37 = NULL;
    PrtFreeValue(PTMP_tmp1_22); PTMP_tmp1_22 = NULL;
    PrtFreeValue(PTMP_tmp2_22); PTMP_tmp2_22 = NULL;
    PrtFreeValue(PTMP_tmp3_19); PTMP_tmp3_19 = NULL;
    PrtFreeValue(PTMP_tmp4_17); PTMP_tmp4_17 = NULL;
    PrtFreeValue(PTMP_tmp5_16); PTMP_tmp5_16 = NULL;
    PrtFreeValue(PTMP_tmp6_16); PTMP_tmp6_16 = NULL;
    PrtFreeValue(PTMP_tmp7_15); PTMP_tmp7_15 = NULL;
    PrtFreeValue(PTMP_tmp8_12); PTMP_tmp8_12 = NULL;
    PrtFreeValue(PTMP_tmp9_12); PTMP_tmp9_12 = NULL;
    PrtFreeValue(PTMP_tmp10_11); PTMP_tmp10_11 = NULL;
    PrtFreeValue(PTMP_tmp11_10); PTMP_tmp11_10 = NULL;
    PrtFreeValue(PTMP_tmp12_10); PTMP_tmp12_10 = NULL;
    PrtFreeValue(PTMP_tmp13_10); PTMP_tmp13_10 = NULL;
    PrtFreeValue(PTMP_tmp14_10); PTMP_tmp14_10 = NULL;
    PrtFreeValue(PTMP_tmp15_7); PTMP_tmp15_7 = NULL;
    PrtFreeValue(PTMP_tmp16_7); PTMP_tmp16_7 = NULL;
    PrtFreeValue(PTMP_tmp17_7); PTMP_tmp17_7 = NULL;
    PrtFreeValue(PTMP_tmp18_7); PTMP_tmp18_7 = NULL;
    PrtFreeValue(PTMP_tmp19_7); PTMP_tmp19_7 = NULL;
    PrtFreeValue(PTMP_tmp20_7); PTMP_tmp20_7 = NULL;
    PrtFreeValue(PTMP_tmp21_7); PTMP_tmp21_7 = NULL;
    PrtFreeValue(PTMP_tmp22_7); PTMP_tmp22_7 = NULL;
    PrtFreeValue(PTMP_tmp23_7); PTMP_tmp23_7 = NULL;
    PrtFreeValue(PTMP_tmp24_6); PTMP_tmp24_6 = NULL;
    PrtFreeValue(PTMP_tmp25_6); PTMP_tmp25_6 = NULL;
    PrtFreeValue(PTMP_tmp26_6); PTMP_tmp26_6 = NULL;
    PrtFreeValue(PTMP_tmp27_6); PTMP_tmp27_6 = NULL;
    PrtFreeValue(PTMP_tmp28_6); PTMP_tmp28_6 = NULL;
    PrtFreeValue(PTMP_tmp29_6); PTMP_tmp29_6 = NULL;
    PrtFreeValue(PTMP_tmp30_6); PTMP_tmp30_6 = NULL;
    PrtFreeValue(PTMP_tmp31_6); PTMP_tmp31_6 = NULL;
    PrtFreeValue(PTMP_tmp32_6); PTMP_tmp32_6 = NULL;
    PrtFreeValue(PTMP_tmp33_5); PTMP_tmp33_5 = NULL;
    PrtFreeValue(PTMP_tmp34_5); PTMP_tmp34_5 = NULL;
    PrtFreeValue(PTMP_tmp35_5); PTMP_tmp35_5 = NULL;
    PrtFreeValue(PTMP_tmp36_5); PTMP_tmp36_5 = NULL;
    PrtFreeValue(PTMP_tmp37_5); PTMP_tmp37_5 = NULL;
    PrtFreeValue(PTMP_tmp38_5); PTMP_tmp38_5 = NULL;
    PrtFreeValue(PTMP_tmp39_5); PTMP_tmp39_5 = NULL;
    PrtFreeValue(PTMP_tmp40_4); PTMP_tmp40_4 = NULL;
    PrtFreeValue(PTMP_tmp41_4); PTMP_tmp41_4 = NULL;
    PrtFreeValue(PTMP_tmp42_4); PTMP_tmp42_4 = NULL;
    PrtFreeValue(PTMP_tmp43_4); PTMP_tmp43_4 = NULL;
    PrtFreeValue(PTMP_tmp44_4); PTMP_tmp44_4 = NULL;
    PrtFreeValue(PTMP_tmp45_4); PTMP_tmp45_4 = NULL;
    PrtFreeValue(PTMP_tmp46_4); PTMP_tmp46_4 = NULL;
    PrtFreeValue(PTMP_tmp47_4); PTMP_tmp47_4 = NULL;
    PrtFreeValue(PTMP_tmp48_4); PTMP_tmp48_4 = NULL;
    PrtFreeValue(PTMP_tmp49_4); PTMP_tmp49_4 = NULL;
    PrtFreeValue(PTMP_tmp50_4); PTMP_tmp50_4 = NULL;
    PrtFreeValue(PTMP_tmp51_4); PTMP_tmp51_4 = NULL;
    PrtFreeValue(PTMP_tmp52_4); PTMP_tmp52_4 = NULL;
    PrtFreeValue(PTMP_tmp53_4); PTMP_tmp53_4 = NULL;
    PrtFreeValue(PTMP_tmp54_4); PTMP_tmp54_4 = NULL;
    PrtFreeValue(PTMP_tmp55_4); PTMP_tmp55_4 = NULL;
    PrtFreeValue(PTMP_tmp56_4); PTMP_tmp56_4 = NULL;
    PrtFreeValue(PTMP_tmp57_4); PTMP_tmp57_4 = NULL;
    PrtFreeValue(PTMP_tmp58_4); PTMP_tmp58_4 = NULL;
    PrtFreeValue(PTMP_tmp59_4); PTMP_tmp59_4 = NULL;
    PrtFreeValue(PTMP_tmp60_4); PTMP_tmp60_4 = NULL;
    PrtFreeValue(PTMP_tmp61_4); PTMP_tmp61_4 = NULL;
    PrtFreeValue(PTMP_tmp62_4); PTMP_tmp62_4 = NULL;
    PrtFreeValue(PTMP_tmp63_4); PTMP_tmp63_4 = NULL;
    PrtFreeValue(PTMP_tmp64_4); PTMP_tmp64_4 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_checktMsg =
{
    "checktMsg",
    &P_checktMsg_IMPL,
    NULL
};


PRT_VALUE* P_readBuffer2_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE** P_VAR_buf_1 = argRefs[0];
    PRT_VALUE* P_VAR_bufsize_2 = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* P_VAR_counter_4 = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* P_VAR_ret_3 = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* PTMP_tmp0_38 = NULL;
    PRT_VALUE* PTMP_tmp1_23 = NULL;
    PRT_VALUE* PTMP_tmp2_23 = NULL;
    PRT_VALUE* PTMP_tmp3_20 = NULL;
    PRT_VALUE* PTMP_tmp4_18 = NULL;
    PRT_VALUE* PTMP_tmp5_17 = NULL;
    PRT_VALUE* PTMP_tmp6_17 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_85 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE P_LIT_INT32_86 = { PRT_VALUE_KIND_INT, { .nt = 256 } };
    PRT_VALUE P_LIT_INT32_87 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE P_LIT_BOOLEAN_12 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_TRUE } };
    PRT_VALUE** P_LVALUE_853 = &(PTMP_tmp0_38);
    PrtFreeValue(*P_LVALUE_853);
    *P_LVALUE_853 = PrtMkIntValue(PrtSeqSizeOf(*P_VAR_buf_1));
    
    {
        PRT_VALUE** P_LVALUE_854 = &(P_VAR_bufsize_2);
        PrtFreeValue(*P_LVALUE_854);
        *P_LVALUE_854 = PTMP_tmp0_38;
        PTMP_tmp0_38 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_855 = &(P_VAR_counter_4);
    PrtFreeValue(*P_LVALUE_855);
    *P_LVALUE_855 = PrtCloneValue((&P_LIT_INT32_85));
    
    PRT_VALUE** P_LVALUE_856 = &(P_VAR_ret_3);
    PrtFreeValue(*P_LVALUE_856);
    *P_LVALUE_856 = PrtCloneValue((&P_LIT_INT32_85));
    
    while (PrtPrimGetBool((&P_LIT_BOOLEAN_12)))
    {
        PRT_VALUE** P_LVALUE_857 = &(PTMP_tmp1_23);
        PrtFreeValue(*P_LVALUE_857);
        *P_LVALUE_857 = PrtMkBoolValue(PrtPrimGetInt(P_VAR_counter_4) < PrtPrimGetInt(P_VAR_bufsize_2));
        
        PRT_VALUE** P_LVALUE_858 = &(PTMP_tmp2_23);
        PrtFreeValue(*P_LVALUE_858);
        *P_LVALUE_858 = PrtCloneValue(PTMP_tmp1_23);
        
        if (PrtPrimGetBool(PTMP_tmp2_23))
        {
        }
        
        else
        {
            break;
            
        }
        
        
        PRT_VALUE** P_LVALUE_859 = &(PTMP_tmp3_20);
        PrtFreeValue(*P_LVALUE_859);
        *P_LVALUE_859 = PrtMkIntValue(PrtPrimGetInt(P_VAR_ret_3) * PrtPrimGetInt((&P_LIT_INT32_86)));
        
        {
            PRT_VALUE** P_LVALUE_860 = &(P_VAR_ret_3);
            PrtFreeValue(*P_LVALUE_860);
            *P_LVALUE_860 = PTMP_tmp3_20;
            PTMP_tmp3_20 = NULL;
        }
        
        PRT_VALUE** P_LVALUE_861 = &(PTMP_tmp4_18);
        PrtFreeValue(*P_LVALUE_861);
        *P_LVALUE_861 = PrtSeqGet(*P_VAR_buf_1, P_VAR_counter_4);
        
        PRT_VALUE** P_LVALUE_862 = &(PTMP_tmp5_17);
        PrtFreeValue(*P_LVALUE_862);
        *P_LVALUE_862 = PrtMkIntValue(PrtPrimGetInt(P_VAR_ret_3) + PrtPrimGetInt(PTMP_tmp4_18));
        
        {
            PRT_VALUE** P_LVALUE_863 = &(P_VAR_ret_3);
            PrtFreeValue(*P_LVALUE_863);
            *P_LVALUE_863 = PTMP_tmp5_17;
            PTMP_tmp5_17 = NULL;
        }
        
        PRT_VALUE** P_LVALUE_864 = &(PTMP_tmp6_17);
        PrtFreeValue(*P_LVALUE_864);
        *P_LVALUE_864 = PrtMkIntValue(PrtPrimGetInt(P_VAR_counter_4) + PrtPrimGetInt((&P_LIT_INT32_87)));
        
        {
            PRT_VALUE** P_LVALUE_865 = &(P_VAR_counter_4);
            PrtFreeValue(*P_LVALUE_865);
            *P_LVALUE_865 = PTMP_tmp6_17;
            PTMP_tmp6_17 = NULL;
        }
        
    }
    
    
    PrtFreeValue(_P_GEN_retval);
    _P_GEN_retval = PrtCloneValue(P_VAR_ret_3);
    goto p_return_48;
    
p_return_48: ;
    PrtFreeValue(P_VAR_bufsize_2); P_VAR_bufsize_2 = NULL;
    PrtFreeValue(P_VAR_counter_4); P_VAR_counter_4 = NULL;
    PrtFreeValue(P_VAR_ret_3); P_VAR_ret_3 = NULL;
    PrtFreeValue(PTMP_tmp0_38); PTMP_tmp0_38 = NULL;
    PrtFreeValue(PTMP_tmp1_23); PTMP_tmp1_23 = NULL;
    PrtFreeValue(PTMP_tmp2_23); PTMP_tmp2_23 = NULL;
    PrtFreeValue(PTMP_tmp3_20); PTMP_tmp3_20 = NULL;
    PrtFreeValue(PTMP_tmp4_18); PTMP_tmp4_18 = NULL;
    PrtFreeValue(PTMP_tmp5_17); PTMP_tmp5_17 = NULL;
    PrtFreeValue(PTMP_tmp6_17); PTMP_tmp6_17 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_readBuffer2 =
{
    "readBuffer2",
    &P_readBuffer2_IMPL,
    NULL
};


PRT_FUNDECL* P_MessageFormatSpecMachine_METHODS[] = { &P_FUNCTION_Anon_21, &P_FUNCTION_Anon_22, &P_FUNCTION_Anon_23, &P_FUNCTION_Anon_24, &P_FUNCTION_Anon_25, &P_FUNCTION_Anon_26, &P_FUNCTION_Anon_27, &P_FUNCTION_Anon_28, &P_FUNCTION_Anon_29, &P_FUNCTION_Anon_30, &P_FUNCTION_Anon_31, &P_FUNCTION_Anon_32, &P_FUNCTION_Anon_33, &P_FUNCTION_checktFix, &P_FUNCTION_checktVar, &P_FUNCTION_checktHdr, &P_FUNCTION_checktPara, &P_FUNCTION_checktPlist, &P_FUNCTION_checktMsg, &P_FUNCTION_readBuffer2 };

PRT_EVENTDECL* P_MessageFormatSpecMachine_RECV_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_MessageFormatSpecMachine_RECV =
{
    0U,
    P_MessageFormatSpecMachine_RECV_INNER,
    NULL
};

PRT_EVENTDECL* P_MessageFormatSpecMachine_SEND_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_MessageFormatSpecMachine_SEND =
{
    0U,
    P_MessageFormatSpecMachine_SEND_INNER,
    NULL
};

PRT_MACHINEDECL P_MACHINE_MessageFormatSpecMachine = 
{
    5U,
    "MessageFormatSpecMachine",
    &P_EVENTSET_MessageFormatSpecMachine_RECV,
    &P_EVENTSET_MessageFormatSpecMachine_SEND,
    NULL,
    0U,
    2U,
    20U,
    4294967295U,
    0U,
    NULL,
    P_MessageFormatSpecMachine_STATES,
    P_MessageFormatSpecMachine_METHODS
};

PRT_EVENTDECL* P_Init_DEFERS_INNER_6[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DEFERS_6 =
{
    0U,
    P_Init_DEFERS_INNER_6,
    NULL
};

PRT_EVENTDECL* P_Init_TRANS_INNER_6[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_TRANS_6 =
{
    0U,
    P_Init_TRANS_INNER_6,
    NULL
};

PRT_EVENTDECL* P_Init_DOS_INNER_6[] = { &P_EVENT_eChanConnected };
PRT_EVENTSETDECL P_EVENTSET_Init_DOS_6 =
{
    1U,
    P_Init_DOS_INNER_6,
    NULL
};

PRT_DODECL P_DOS_11[] =
{
    { 0, &P_EVENT_eChanConnected, &P_FUNCTION_Anon_35 }
};

#define P_STATE_LivenessSpecMachine_Init \
{ \
    "LivenessSpecMachine.Init", \
    0U, \
    1U, \
    &P_EVENTSET_Init_DEFERS_6, \
    &P_EVENTSET_Init_TRANS_6, \
    &P_EVENTSET_Init_DOS_6, \
    NULL, \
    P_DOS_11, \
    &P_FUNCTION_Anon_34, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_Wait_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Wait_DEFERS =
{
    0U,
    P_Wait_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_Wait_TRANS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Wait_TRANS =
{
    0U,
    P_Wait_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_Wait_DOS_INNER[] = { &P_EVENT_eChanConnected };
PRT_EVENTSETDECL P_EVENTSET_Wait_DOS =
{
    1U,
    P_Wait_DOS_INNER,
    NULL
};

PRT_DODECL P_DOS_12[] =
{
    { 1, &P_EVENT_eChanConnected, &P_FUNCTION_Anon_36 }
};

#define P_STATE_LivenessSpecMachine_Wait \
{ \
    "LivenessSpecMachine.Wait", \
    0U, \
    1U, \
    &P_EVENTSET_Wait_DEFERS, \
    &P_EVENTSET_Wait_TRANS, \
    &P_EVENTSET_Wait_DOS, \
    NULL, \
    P_DOS_12, \
    &_P_NO_OP, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_Done_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Done_DEFERS =
{
    0U,
    P_Done_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_Done_TRANS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Done_TRANS =
{
    0U,
    P_Done_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_Done_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Done_DOS =
{
    0U,
    P_Done_DOS_INNER,
    NULL
};

#define P_STATE_LivenessSpecMachine_Done \
{ \
    "LivenessSpecMachine.Done", \
    0U, \
    0U, \
    &P_EVENTSET_Done_DEFERS, \
    &P_EVENTSET_Done_TRANS, \
    &P_EVENTSET_Done_DOS, \
    NULL, \
    NULL, \
    &_P_NO_OP, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_LivenessSpecMachine_STATES[] = { P_STATE_LivenessSpecMachine_Init, P_STATE_LivenessSpecMachine_Wait, P_STATE_LivenessSpecMachine_Done };

PRT_VALUE* P_Anon_IMPL_34(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PrtGoto(p_this, 1U, 0);
    
p_return_49: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_34 =
{
    NULL,
    &P_Anon_IMPL_34,
    NULL
};


PRT_VALUE* P_Anon_IMPL_35(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PrtGoto(p_this, 2U, 0);
    
p_return_50: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_35 =
{
    NULL,
    &P_Anon_IMPL_35,
    NULL
};


PRT_VALUE* P_Anon_IMPL_36(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PrtGoto(p_this, 2U, 0);
    
p_return_51: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_36 =
{
    NULL,
    &P_Anon_IMPL_36,
    NULL
};


PRT_FUNDECL* P_LivenessSpecMachine_METHODS[] = { &P_FUNCTION_Anon_34, &P_FUNCTION_Anon_35, &P_FUNCTION_Anon_36 };

PRT_EVENTDECL* P_LivenessSpecMachine_RECV_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_LivenessSpecMachine_RECV =
{
    0U,
    P_LivenessSpecMachine_RECV_INNER,
    NULL
};

PRT_EVENTDECL* P_LivenessSpecMachine_SEND_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_LivenessSpecMachine_SEND =
{
    0U,
    P_LivenessSpecMachine_SEND_INNER,
    NULL
};

PRT_MACHINEDECL P_MACHINE_LivenessSpecMachine = 
{
    6U,
    "LivenessSpecMachine",
    &P_EVENTSET_LivenessSpecMachine_RECV,
    &P_EVENTSET_LivenessSpecMachine_SEND,
    NULL,
    0U,
    3U,
    3U,
    4294967295U,
    0U,
    NULL,
    P_LivenessSpecMachine_STATES,
    P_LivenessSpecMachine_METHODS
};

PRT_EVENTDECL* P_Init_DEFERS_INNER_7[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DEFERS_7 =
{
    0U,
    P_Init_DEFERS_INNER_7,
    NULL
};

PRT_EVENTDECL* P_Init_TRANS_INNER_7[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_TRANS_7 =
{
    0U,
    P_Init_TRANS_INNER_7,
    NULL
};

PRT_EVENTDECL* P_Init_DOS_INNER_7[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DOS_7 =
{
    0U,
    P_Init_DOS_INNER_7,
    NULL
};

#define P_STATE_TestWithSingleClient_Init \
{ \
    "TestWithSingleClient.Init", \
    0U, \
    0U, \
    &P_EVENTSET_Init_DEFERS_7, \
    &P_EVENTSET_Init_TRANS_7, \
    &P_EVENTSET_Init_DOS_7, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon_37, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_TestWithSingleClient_STATES[] = { P_STATE_TestWithSingleClient_Init };

PRT_VALUE* P_Anon_IMPL_37(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* PTMP_tmp0_39 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_88 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE** P_LVALUE_866 = &(PTMP_tmp0_39);
    PrtFreeValue(*P_LVALUE_866);
    *P_LVALUE_866 = PrtCloneValue((&P_LIT_INT32_88));
    
    _P_GEN_funargs[0] = &(PTMP_tmp0_39);
    PrtFreeValue(P_SetupClientServerSystem_IMPL(context, _P_GEN_funargs));
    PrtFreeValue(PTMP_tmp0_39);
    PTMP_tmp0_39 = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_52;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_52;
    }
    
p_return_52: ;
    PrtFreeValue(PTMP_tmp0_39); PTMP_tmp0_39 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_37 =
{
    NULL,
    &P_Anon_IMPL_37,
    NULL
};


PRT_FUNDECL* P_TestWithSingleClient_METHODS[] = { &P_FUNCTION_Anon_37 };

PRT_EVENTDECL* P_TestWithSingleClient_RECV_INNER_1[] = { &P_EVENT_eChanConnected, &P_EVENT_eChanDead, &P_EVENT_eChanGotoConfig, &P_EVENT_eChanGotoConnected, &P_EVENT_eChanStarted, &P_EVENT_eComposetFix, &P_EVENT_eComposetHdr, &P_EVENT_eComposetMsg, &P_EVENT_eComposetPara, &P_EVENT_eComposetPlist, &P_EVENT_eComposetVar, &P_EVENT_eConfReq, &P_EVENT_eConfResp, &P_EVENT_eConnReq, &P_EVENT_eConnResp, &P_EVENT_eGetDefaultValueResp, &P_EVENT_eL2CmdReq, &P_EVENT_eParsetFix, &P_EVENT_eParsetHdr, &P_EVENT_eParsetMsg, &P_EVENT_eParsetPara, &P_EVENT_eParsetPlist, &P_EVENT_eParsetVar, &P_EVENT_eSpecGetDefaultValueReq, &P_EVENT_eStartTimer, &P_EVENT_eTimeOut, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_TestWithSingleClient_RECV_1 =
{
    27U,
    P_TestWithSingleClient_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_TestWithSingleClient_SEND_INNER[] = { &P_EVENT_eChanConnected, &P_EVENT_eChanDead, &P_EVENT_eChanGotoConfig, &P_EVENT_eChanGotoConnected, &P_EVENT_eChanStarted, &P_EVENT_eComposetFix, &P_EVENT_eComposetHdr, &P_EVENT_eComposetMsg, &P_EVENT_eComposetPara, &P_EVENT_eComposetPlist, &P_EVENT_eComposetVar, &P_EVENT_eConfReq, &P_EVENT_eConfResp, &P_EVENT_eConnReq, &P_EVENT_eConnResp, &P_EVENT_eGetDefaultValueResp, &P_EVENT_eL2CmdReq, &P_EVENT_eParsetFix, &P_EVENT_eParsetHdr, &P_EVENT_eParsetMsg, &P_EVENT_eParsetPara, &P_EVENT_eParsetPlist, &P_EVENT_eParsetVar, &P_EVENT_eSpecGetDefaultValueReq, &P_EVENT_eStartTimer, &P_EVENT_eTimeOut, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_TestWithSingleClient_SEND =
{
    27U,
    P_TestWithSingleClient_SEND_INNER,
    NULL
};

PRT_UINT32 P_TestWithSingleClient_CREATES_ARR[] = { 2, 1, 0 };
PRT_INTERFACESETDECL P_TestWithSingleClient_CREATES = { 3, P_TestWithSingleClient_CREATES_ARR };
PRT_MACHINEDECL P_MACHINE_TestWithSingleClient = 
{
    7U,
    "TestWithSingleClient",
    &P_EVENTSET_TestWithSingleClient_RECV_1,
    &P_EVENTSET_TestWithSingleClient_SEND,
    &P_TestWithSingleClient_CREATES,
    0U,
    1U,
    1U,
    4294967295U,
    0U,
    NULL,
    P_TestWithSingleClient_STATES,
    P_TestWithSingleClient_METHODS
};

PRT_TYPE* P_TYPEDEF_tFix = &P_GEND_TYPE_NT4iiiSi;
PRT_TYPE* P_TYPEDEF_tVar = &P_GEND_TYPE_NT3iiSi;
PRT_TYPE* P_TYPEDEF_tHdr = &P_GEND_TYPE_NT2SNT4iiiSiNT4iiiSi;
PRT_TYPE* P_TYPEDEF_tPara = &P_GEND_TYPE_NT3iNT4iiiSiNT4iiiSi;
PRT_TYPE* P_TYPEDEF_tPlist = &P_GEND_TYPE_NT2iSNT3iNT4iiiSiNT4iiiSi;
PRT_TYPE* P_TYPEDEF_tHMsub = &P_GEND_TYPE_NT2NT2SNT4iiiSiNT4iiiSiB;
PRT_TYPE* P_TYPEDEF_tcMsub = &P_GEND_TYPE_NT2iB;
PRT_TYPE* P_TYPEDEF_tHcMsub = &P_GEND_TYPE_NT2NT2SNT4iiiSiNT4iiiSiSNT2iB;
PRT_TYPE* P_TYPEDEF_tMsg = &P_GEND_TYPE_NT7iNT3iiSiNT3iNT4iiiSiNT4iiiSiSNT4iiiSiNT2iSNT3iNT4iiiSiNT4iiiSiNT2NT2SNT4iiiSiNT4iiiSiBNT2NT2SNT4iiiSiNT4iiiSiSNT2iB;
PRT_TYPE* P_TYPEDEF_tChan = &P_GEND_TYPE_SNT3iNT4iiiSiNT4iiiSi;
PRT_TYPE* P_TYPEDEF_tConn = &P_GEND_TYPE_SSNT3iNT4iiiSiNT4iiiSi;
PRT_EVENTDECL* P_ALL_EVENTS[] = { &_P_EVENT_NULL_STRUCT, &_P_EVENT_HALT_STRUCT, &P_EVENT_eGetDefaultValueResp, &P_EVENT_eConnResp, &P_EVENT_eConfResp, &P_EVENT_eSpecGetDefaultValueReq, &P_EVENT_eL2CmdReq, &P_EVENT_eConnReq, &P_EVENT_eConfReq, &P_EVENT_eChanGotoConnected, &P_EVENT_eChanGotoConfig, &P_EVENT_eChanDead, &P_EVENT_eChanStarted, &P_EVENT_eChanConnected, &P_EVENT_eStartTimer, &P_EVENT_eTimeOut, &P_EVENT_eParsetFix, &P_EVENT_eParsetVar, &P_EVENT_eParsetHdr, &P_EVENT_eParsetPara, &P_EVENT_eParsetPlist, &P_EVENT_eParsetMsg, &P_EVENT_eComposetFix, &P_EVENT_eComposetVar, &P_EVENT_eComposetHdr, &P_EVENT_eComposetPara, &P_EVENT_eComposetPlist, &P_EVENT_eComposetMsg };
PRT_MACHINEDECL* P_ALL_MACHINES[] = { &P_MACHINE_VarInitMachine, &P_MACHINE_ConnMachine, &P_MACHINE_ClientMachine, &P_MACHINE_ChanMachine, &P_MACHINE_TimerMachine, &P_MACHINE_MessageFormatSpecMachine, &P_MACHINE_LivenessSpecMachine, &P_MACHINE_TestWithSingleClient };
PRT_INTERFACEDECL* P_ALL_INTERFACES[] = { &P_I_VarInitMachine, &P_I_ConnMachine, &P_I_ClientMachine, &P_I_ChanMachine, &P_I_TimerMachine, &P_I_TestWithSingleClient };
PRT_FUNDECL* P_ALL_FUNCTIONS[] = { &P_FUNCTION_readBuffer, &P_FUNCTION_writeBuffer, &P_FUNCTION_sleepFor, &P_FUNCTION_SetupClientServerSystem };
PRT_FOREIGNTYPEDECL* P_ALL_FOREIGN_TYPES[] = { NULL };

int main(){
    FILE* fp = fopen("/dev/kmsg", "r");
    size_t len = 0;
    ssize_t read;
    char* line = NULL;
    char* subs_start = 0;
    if(fp == NULL) return 0;
    while ((read = getline(&line, &len, fp)) != -1) {
        if(subs_start = strstr(line, "P Server ID = 668")){
            printf("%s", subs_start);
        }
    }

    fclose(fp);
    if (line)
        free(line);
    return 0;
}