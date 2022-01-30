event eL2CmdReq: (source: machine, req : tMsg);
event eConnReq: (source: machine, req : tMsg);
event eConnResp: bool;
event eConfReq: (source: machine, req: tMsg);
event eConfResp: bool;

machine ConnMachine
{
    var server : VarInitMachine;

    var Connection : tConn;
    var ChanMachineList : map[int, ChanMachine];

    start state Init {
        entry (input:(serv: VarInitMachine, conn : tConn)){
            server = input.serv;
            Connection = input.conn;
            goto WaitForReqs;
        }
    }

    state WaitForReqs {
        on eL2CmdReq do (wReq: (source: machine, req: tMsg)) {
            var MsgBody: tHcMsub;
            var MsgHdr: tHdr;
            var MsgCases: seq[tcMsub];
            var MsgType: int;
            var counter: int;
//            print "receive eL2CmdReq";
            announce eParsetMsg, wReq.req;
            MsgBody = wReq.req.hcmsub;
            MsgHdr = MsgBody.h;
            MsgCases = MsgBody.msub;
            MsgType = readBuffer(MsgHdr.f[0].value);
            counter = 0;
            while(counter < sizeof(MsgCases)){
                if(MsgType == MsgCases[counter].nType && MsgType == 2){
                    send this, eConnReq, (source = wReq.source, req = MsgCases[counter].msub as tMsg);
                }
                else if(MsgType == MsgCases[counter].nType && MsgType == 4){
                    send this, eConfReq, (source = wReq.source, req = MsgCases[counter].msub as tMsg);
                }
                counter = counter + 1;
            }
        }

        on eConnReq do (wReq: (source : machine, req : tMsg)) {
            var counter2 : int;
            var flag1 : bool;
            var flag2 : bool;
            var index : int;
            var counter3 : int;
            var tmp1 : tPara;
            var tmp2 : tPara;
            var tmp3 : tChan;
//            print "in eConnReq";

            announce eParsetMsg, wReq.req;
            counter2 = 0;
            flag1 = false;
            flag2 = false;
            // the findChanByPara function is hard-coded here.
            while(counter2 < sizeof(Connection)){
                counter3 = 0;
                while(counter3 < sizeof(Connection[counter2])){
                    if(Connection[counter2][counter3].nKey == 2 && readBuffer(Connection[counter2][counter3].fKey.value) == 2
                    && readBuffer(wReq.req.fp[0].value) == readBuffer(Connection[counter2][counter3].fVal.value)){
                        flag1 = true;
//                        print "flag1 = true";
                    }
                    if(Connection[counter2][counter3].nKey == 1 && readBuffer(Connection[counter2][counter3].fKey.value) == 1
                    && readBuffer(wReq.req.fp[1].value) == readBuffer(Connection[counter2][counter3].fVal.value)){
                        flag2 = true;
//                        print "flag2 = true";
                    }
                    counter3 = counter3 + 1;
                }
                counter2 = counter2 + 1;
            }
            // createChan is hard-coded here.
            // send response/set configs
            if (flag1 == true && flag2 == false){
                tmp1.nKey = 2;
                tmp1.fKey.value = writeBuffer(2, 1);
                tmp1.fVal = wReq.req.fp[0];
                tmp2.nKey = 1;
                tmp2.fKey.value = writeBuffer(1, 1);
                tmp2.fVal = wReq.req.fp[1];
                tmp3 += (0,tmp2);
                tmp3 += (1,tmp1);
                Connection += (sizeof(Connection) - 1, tmp3);
                ChanMachineList[sizeof(Connection)] = new ChanMachine(server);
                send ChanMachineList[sizeof(Connection)], eChanGotoConfig;
                send wReq.source, eConnResp, true;
                return;
            }
            send wReq.source, eConnResp, false;
        }
        on eConfReq do (wReq: (source : machine, req : tMsg)) {
            var hm : tHMsub;
            var msub: tMsg;
            var srcChanID : tFix;
            var optPlist : tPlist;
            var mtuPara : tPara;
            var counter2 : int;
            var flag1 : bool;
            var index : int;
            var counter3 : int;
            var targetChan: tChan;
            var targetChanM : ChanMachine;
//            print "in eConfReq";

            announce eParsetMsg, wReq.req;
            hm = wReq.req.hmsub;
            srcChanID = hm.h.f[0];
            msub = hm.msub as tMsg;
            optPlist = msub.l;
            mtuPara = optPlist.pP[0];

            counter2 = 0;
            flag1 = false;
            index = 0;
//            print "in eConfReq1";

            // the findChanByPara function is hard-coded here.
            while(counter2 < sizeof(Connection)){
                counter3 = 0;
//                print "in eConfReq2";
                while(counter3 < sizeof(Connection[counter2])){
                    if(Connection[counter2][counter3].nKey == 1 && readBuffer(Connection[counter2][counter3].fKey.value) == 1
                    && readBuffer(srcChanID.value) == readBuffer(Connection[counter2][counter3].fVal.value)){
                        flag1 = true;
                        index = counter2 + 1;
//                        print "in eConfReq3";
                    }
                    counter3 = counter3 + 1;
                }
//                print "in eConfReq4";
                counter2 = counter2 + 1;
            }
            if (flag1 == true){
//                print "in eConfReq5";
                targetChan = Connection[index - 1];
//                print "in eConfReq6";
                targetChan += (sizeof(targetChan) - 1, mtuPara);
//                print "in eConfReq7";
                targetChanM = ChanMachineList[sizeof(Connection)];
//                print "in eConfReq8";
                send targetChanM, eChanGotoConnected;
                send wReq.source, eConfResp, true;
                return;
            }
            send wReq.source, eConfResp, false;
        }
    }
}