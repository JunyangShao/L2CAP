event eParsetFix : tFix;
event eParsetVar : tVar;
event eParsetHdr : tHdr;
event eParsetPara : tPara;
event eParsetPlist : tPlist;
event eParsetMsg : tMsg;

event eComposetFix : tFix;
event eComposetVar : tVar;
event eComposetHdr : tHdr;
event eComposetPara : tPara;
event eComposetPlist : tPlist;
event eComposetMsg : tMsg;

spec L2CAPFormatIsCorrect observes
eParsetFix, eParsetVar, eParsetHdr, eParsetPara, eParsetPlist, eParsetMsg,
eComposetFix, eComposetVar, eComposetHdr, eComposetPara, eComposetPlist, eComposetMsg {

    start state Init {
        entry{
            goto Observe;
        }
        ignore eParsetFix, eParsetVar, eParsetHdr, eParsetPara, eParsetPlist, eParsetMsg,
                eComposetFix, eComposetVar, eComposetHdr, eComposetPara, eComposetPlist, eComposetMsg;
    }
    state Observe{
        on eParsetFix do (value: tFix){
            return;
        }
        on eParsetVar do (value: tVar){
            return;
        }
        on eParsetHdr do (value: tHdr){
            return;
        }
        on eParsetPara do (value: tPara){
            return;
        }
        on eParsetPlist do (value: tPlist){
            return;
        }
        on eParsetMsg do (value: tMsg){
            return;
        }


        on eComposetFix do (value: tFix){
            return;
        }
        on eComposetVar do (value: tVar){
            return;
        }
        on eComposetHdr do (value: tHdr){
            return;
        }
        on eComposetPara do (value: tPara){
            return;
        }
        on eComposetPlist do (value: tPlist){
            return;
        }
        on eComposetMsg do (value: tMsg){
            return;
        }
    }
}
