type tFix = (nSize: int, nLow: int, nHigh: int, value: seq[int]);
type tVar = (nLow: int, nHigh: int, value: seq[int]);
type tHdr = (f: seq[tFix], fLen: tFix);
type tPara = (nKey: int, fKey: tFix, fVal: tFix);
type tPlist = (nSize: int, pP: seq[tPara]);
type tHMsub = (h: tHdr, msub: data);
type tcMsub = (nType: int, msub: data);
type tHcMsub = (h: tHdr, msub: seq[tcMsub]);
type tMsg = (chosen: int, v: tVar, p: tPara, fp: seq[tFix], l: tPlist, hmsub: tHMsub, hcmsub: tHcMsub);

type tChan = seq[tPara];
type tConn = seq[tChan];

event eGetDefaultValueResp: seq[data];
event eSpecGetDefaultValueReq: machine;

machine VarInitMachine{
    var vmtuType: tFix;
    var vmtuVal: tFix;
    var vmtuPara: tPara;
    var voptPlist: tPlist;

    // noted that the msgConfReq is not evaluated correctly, where they jump an abstract type.
    // we will need a new type here.
    var vmsgoptPlist: tMsg;

    var vsrcChanID: tFix;
    var vconfReqHdr: tHdr;

    var vl2Psm: tFix;
    var vl2PsmType: tFix;
    var vl2PsmPara: tPara;
    var vdstChanID: tFix;
    var vdstChanIDType: tFix;
    var vdstChanIDPara: tPara;

    var vcmdType: tFix;
    var vcmdHdr: tHdr;

    var vmsgConfReq: tMsg;
    var vmsgConfRsp: tMsg;

    var vmsgConnReq: tMsg;
    var vmsgConnRsp: tMsg;

    var vmsgL2Cmd: tMsg;

    var BT_CONFIG_timeout: int;
    var BT_CONNECTED_timeout: int;

    start state Init {
        entry
        {
            vmtuType = (nSize=1, nLow=10, nHigh=10, value=default(seq[int]));
            vmtuVal = (nSize=2, nLow=16, nHigh=1024, value=default(seq[int]));
            vmtuPara = (nKey=10, fKey=vmtuType, fVal=vmtuVal);
            voptPlist = (nSize=8, pP=default(seq[tPara]));
                voptPlist.pP += (0,vmtuPara);
                voptPlist.pP += (1,default(tPara));
                voptPlist.pP += (2,default(tPara));
                voptPlist.pP += (3,default(tPara));
                voptPlist.pP += (4,default(tPara));
                voptPlist.pP += (5,default(tPara));
                voptPlist.pP += (6,default(tPara));
                voptPlist.pP += (7,default(tPara));

            vmsgoptPlist = (chosen=3, v=default(tVar), p=default(tPara), fp=default(seq[tFix]),
                         l=voptPlist, hmsub=default(tHMsub), hcmsub=default(tHcMsub));
            vsrcChanID = (nSize=2, nLow=1, nHigh=65535, value = default(seq[int]));
            vconfReqHdr = (f=default(seq[tFix]), fLen=(nSize=1, nLow=0, nHigh=255, value=writeBuffer(1, 1)));
                            vconfReqHdr.f += (0, vsrcChanID);
            vl2Psm = (nSize=1, nLow=1, nHigh=23, value=default(seq[int]));
            vl2PsmType = (nSize=1, nLow=2, nHigh=2, value=default(seq[int]));
            vl2PsmPara = (nKey=2, fKey=vl2PsmType, fVal=vl2Psm);
            vdstChanID = (nSize=2, nLow=1, nHigh=65535, value=default(seq[int]));
            vdstChanIDType = (nSize=1, nLow=1, nHigh=1, value=default(seq[int]));
            vdstChanIDPara = (nKey=1, fKey=vdstChanIDType, fVal=vdstChanID);
            vcmdType = (nSize=1, nLow=1, nHigh=22, value=default(seq[int]));
            vcmdHdr = (f=default(seq[tFix]), fLen=(nSize=1, nLow=0, nHigh=255, value=writeBuffer(1, 1)));
            vcmdHdr.f += (0, vcmdType);
            vmsgConfReq = (chosen=4, v=default(tVar), p=default(tPara), fp=default(seq[tFix]),
                        l=default(tPlist), hmsub=(h=vconfReqHdr, msub=vmsgoptPlist), hcmsub=default(tHcMsub));
            vmsgConfRsp = (chosen=0, v=default(tVar), p=default(tPara), fp=default(seq[tFix]),
                        l=default(tPlist), hmsub=default(tHMsub), hcmsub=default(tHcMsub));
            vmsgConnReq = (chosen=2, v=default(tVar), p=default(tPara), fp=default(seq[tFix]),
                        l=default(tPlist), hmsub=default(tHMsub), hcmsub=default(tHcMsub));
                        vmsgConnReq.fp += (0, vl2Psm);
                        vmsgConnReq.fp += (1, vdstChanID);
            vmsgConnRsp = (chosen=0, v=default(tVar), p=default(tPara), fp=default(seq[tFix]),
                        l=default(tPlist), hmsub=default(tHMsub), hcmsub=default(tHcMsub));
            vmsgL2Cmd = (chosen=5, v=default(tVar), p=default(tPara), fp=default(seq[tFix]),
                        l=default(tPlist), hmsub=default(tHMsub),
                        hcmsub=(h=vcmdHdr, msub=default(seq[tcMsub])));
                        vmsgL2Cmd.hcmsub.msub += (0, (nType=2, msub=vmsgConnReq));
                        vmsgL2Cmd.hcmsub.msub += (1, (nType=4, msub=vmsgConfReq));
//            BT_CONFIG_timeout = 200;
            BT_CONFIG_timeout = 0;

//            BT_CONNECTED_timeout = 200;
            BT_CONNECTED_timeout = 0;

            goto WaitForMsgDefaultValueRequest;
        }
    }

    state WaitForMsgDefaultValueRequest{
        on eSpecGetDefaultValueReq do (wReq: machine){
            var ret: seq[data];
            ret += (0, vmtuType);
            ret += (1, vmtuVal);
            ret += (2, vmtuPara);
            ret += (3, voptPlist);
            ret += (4, vsrcChanID);
            ret += (5, vconfReqHdr);
            ret += (6, vl2Psm);
            ret += (7, vl2PsmType);
            ret += (8, vl2PsmPara);
            ret += (9, vdstChanID);
            ret += (10, vdstChanIDType);
            ret += (11, vdstChanIDPara);
            ret += (12, vcmdType);
            ret += (13, vcmdHdr);
            ret += (14, vmsgConfReq);
            ret += (15, vmsgConfRsp);
            ret += (16, vmsgConnReq);
            ret += (17, vmsgConnRsp);
            ret += (18, vmsgL2Cmd);
            ret += (19, BT_CONFIG_timeout);
            ret += (20, BT_CONNECTED_timeout);
            send wReq, eGetDefaultValueResp, ret;
        }
    }
}

fun readBuffer (buf : seq[int]) : int {
    var bufsize : int;
    var counter : int;
    var ret : int;

    bufsize = sizeof(buf);
    counter = 0;
    ret = 0;
    while (counter < bufsize){
        ret = ret * 256;
        ret = ret + buf[counter];
        counter = counter + 1;
    }
    return ret;
}

fun writeBuffer (bufsize : int, val : int) : seq[int] {
    var counter : int;
    var tmp : int;
    var ret_rev : seq[int];
    var ret : seq[int];
    var curval: int;

    curval = val;
    counter = 0;
    ret = default(seq[int]);
//    print format ("val={0}, bufsize={1}", val, bufsize);
    while (counter < bufsize){
        tmp = curval / 256;
        ret_rev += (counter, curval - 256 * tmp);
//        print format ("curval={0}, curval- 256 * tmp ={1}", curval, curval-256*tmp);
        curval = tmp;
        counter = counter + 1;
    }
    counter = 0;
    while (counter < sizeof(ret_rev)){
        ret += (counter, ret_rev[sizeof(ret_rev) - counter - 1]);
        counter = counter + 1;
    }
//    print "return from write buffer";
    return ret;
}

