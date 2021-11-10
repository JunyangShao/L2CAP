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
            var cvmsgConnReq: tMsg;
            var cvmsgConfReq: tMsg;
            var cvmsgoptPlist: tMsg;

//            print "in sendreqs";
            request = vmsgL2Cmd; // msgL2Cmd

            // we will need to cast these variables explicitly to assign values to them.
            // rule of the P Lang.
            cvmsgConnReq = request.hcmsub.msub[0].msub as tMsg; // msgConnReq, effective field is fp.
            cvmsgConfReq = request.hcmsub.msub[1].msub as tMsg; // msgConfReq, effective field is hmsub.
            cvmsgoptPlist = cvmsgConfReq.hmsub.msub as tMsg;  // msgoptPlist, effective field is l.

            cvmsgConnReq.fp[0].value =
                writeBuffer(cvmsgConnReq.fp[0].nSize, cvmsgConnReq.fp[0].nLow + 1);
            cvmsgConnReq.fp[1].value =
                writeBuffer(cvmsgConnReq.fp[1].nSize, cvmsgConnReq.fp[1].nLow);
            request.hcmsub.msub[0].msub = cvmsgConnReq as data;

            cvmsgConfReq.hmsub.h.f[0].value =
                writeBuffer(cvmsgConfReq.hmsub.h.f[0].nSize, cvmsgConfReq.hmsub.h.f[0].nLow);
            cvmsgoptPlist.l.pP[0].fKey.value =
                writeBuffer(cvmsgoptPlist.l.pP[0].fKey.nSize, cvmsgoptPlist.l.pP[0].fKey.nLow);
            cvmsgoptPlist.l.pP[0].fVal.value =
                writeBuffer(cvmsgoptPlist.l.pP[0].fVal.nSize, cvmsgoptPlist.l.pP[0].fVal.nLow);
            cvmsgConfReq.hmsub.msub = cvmsgoptPlist as data;
            cvmsgConfReq.hmsub.h.f[0].value =
                writeBuffer(cvmsgConfReq.hmsub.h.f[0].nSize, cvmsgConfReq.hmsub.h.f[0].nLow);
            request.hcmsub.msub[1].msub = cvmsgConfReq as data;

            if(IsConn == 1){
                // ConnReq
                request.hcmsub.h.f[0].value =
                    writeBuffer(request.hcmsub.h.f[0].nSize, request.hcmsub.msub[0].nType);
            }
            else{
                // ConfReq
                request.hcmsub.h.f[0].value =
                    writeBuffer(request.hcmsub.h.f[0].nSize,request.hcmsub.msub[1].nType);
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