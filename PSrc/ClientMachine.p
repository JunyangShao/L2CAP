machine ClientMachine
{
    var InitServer : VarInitMachine;
    var ConnServer : ConnMachine;

    // Use actual value to denote the Types.
    var vmsgL2Cmd: tMsg;

    start state Init {
        entry (input:(_InitServer: VarInitMachine, _ConnServer : ConnMachine)){
            InitServer = input._InitServer;
            ConnServer = input._ConnServer;
            send InitServer, eSpecGetDefaultValueReq, this;
            receive {
                case eGetDefaultValueResp: (resp: seq[data]){
                     vmsgL2Cmd= resp[18] as tMsg;
                }
            }
            goto SendReqs, 1;
        }
    }

    state SendReqs {
        entry(IsConn: int) {
            var request: tMsg;
            var request_option0: tMsg;
            var request_option1: tMsg;
            var request_option1_msub: tMsg;
            var connreq: tMsg;
            var confreq: tHMsub;
            request = vmsgL2Cmd;
            request_option0 = request.hcmsub.msub[0].msub as tMsg;
            request_option1 = request.hcmsub.msub[1].msub as tMsg;
            request_option1_msub = request_option1.hmsub.msub as tMsg;
            connreq = request_option0;
            confreq = request_option1.hmsub;
            if(IsConn == 1){
                // ConnReq
                request.hcmsub.h.f[0].value = writeBuffer(request.hcmsub.h.f[0].nSize, request.hcmsub.msub[0].nType);
                request_option0.fp[0].value =
//                    writeBuffer(connreq.fp[0].nSize, choose(connreq.fp[0].nHigh - connreq.fp[0].nLow + 1) + 1);
                    writeBuffer(connreq.fp[0].nSize, 1 + 1);
                request_option0.fp[1].value =
//                    writeBuffer(connreq.fp[1].nSize, choose(connreq.fp[1].nHigh - connreq.fp[1].nLow + 1) + 1);
                    writeBuffer(connreq.fp[1].nSize, 1 + 1);
                request.hcmsub.msub[0].msub = request_option0 as data;
            }
            else{
                // ConfReq
                request.hcmsub.h.f[0].value = writeBuffer(request.hcmsub.h.f[0].nSize,request.hcmsub.msub[1].nType);
                request_option1.hmsub.h.f[0].value =
//                    writeBuffer(confreq.h.f[0].nSize, choose(confreq.h.f[0].nHigh- confreq.h.f[0].nLow + 1) + 1);
                    writeBuffer(confreq.h.f[0].nSize, 1 + 1);
                request_option1_msub.l.pP[0].fKey.value =
//                    writeBuffer(request_option1_msub.l.pP[0].fKey.nSize, choose(request_option1_msub.l.pP[0].fKey.nHigh
//                                                              - request_option1_msub.l.pP[0].fKey.nLow + 1) + 1);
                    writeBuffer(request_option1_msub.l.pP[0].fKey.nSize, 1 + 1);
                request_option1_msub.l.pP[0].fVal.value =
//                    writeBuffer(request_option1_msub.l.pP[0].fVal.nSize, choose(request_option1_msub.l.pP[0].fVal.nHigh
//                                                              - request_option1_msub.l.pP[0].fVal.nLow + 1) + 1);
                    writeBuffer(request_option1_msub.l.pP[0].fVal.nSize, 1 + 1);
                request_option1.hmsub.msub = request_option1_msub as data;
                request.hcmsub.msub[1].msub = request_option1 as data;
            }
            send ConnServer, eL2CmdReq, (source = this, req = request);
            goto WaitForReply;
        }
    }
    state WaitForReply{
        entry{
            receive{
                case eConnResp: (Success: bool){
                    if(Success){
                        goto SendReqs, 0;
                    }
                    else{
                        goto SendReqs, 1;
                    }
                }
                case eConfResp: (Success: bool){
                    if(Success){
                        goto DeadState;
                    }
                    else{
                        goto SendReqs, 1;
                    }
                }
            }
        }
    }
    state DeadState{
        ignore eConfResp, eConnResp, eGetDefaultValueResp;
    }
}