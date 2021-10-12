using Microsoft.Coyote;
using Microsoft.Coyote.Actors;
using Microsoft.Coyote.Runtime;
using Microsoft.Coyote.Specifications;
using System;
using System.Runtime;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using Plang.CSharpRuntime;
using Plang.CSharpRuntime.Values;
using Plang.CSharpRuntime.Exceptions;
using System.Threading;
using System.Threading.Tasks;

#pragma warning disable 162, 219, 414, 1998
namespace PImplementation
{
}
namespace PImplementation
{
    internal partial class eChanGotoConnected : PEvent
    {
        public eChanGotoConnected() : base() {}
        public eChanGotoConnected (IPrtValue payload): base(payload){ }
        public override IPrtValue Clone() { return new eChanGotoConnected();}
    }
}
namespace PImplementation
{
    internal partial class eChanGotoConfig : PEvent
    {
        public eChanGotoConfig() : base() {}
        public eChanGotoConfig (IPrtValue payload): base(payload){ }
        public override IPrtValue Clone() { return new eChanGotoConfig();}
    }
}
namespace PImplementation
{
    internal partial class eStartTimer : PEvent
    {
        public eStartTimer() : base() {}
        public eStartTimer (PrtInt payload): base(payload){ }
        public override IPrtValue Clone() { return new eStartTimer();}
    }
}
namespace PImplementation
{
    internal partial class eTimeOut : PEvent
    {
        public eTimeOut() : base() {}
        public eTimeOut (PrtInt payload): base(payload){ }
        public override IPrtValue Clone() { return new eTimeOut();}
    }
}
namespace PImplementation
{
    internal partial class eL2CmdReq : PEvent
    {
        public eL2CmdReq() : base() {}
        public eL2CmdReq (PrtNamedTuple payload): base(payload){ }
        public override IPrtValue Clone() { return new eL2CmdReq();}
    }
}
namespace PImplementation
{
    internal partial class eConnReq : PEvent
    {
        public eConnReq() : base() {}
        public eConnReq (PrtNamedTuple payload): base(payload){ }
        public override IPrtValue Clone() { return new eConnReq();}
    }
}
namespace PImplementation
{
    internal partial class eConnResp : PEvent
    {
        public eConnResp() : base() {}
        public eConnResp (PrtBool payload): base(payload){ }
        public override IPrtValue Clone() { return new eConnResp();}
    }
}
namespace PImplementation
{
    internal partial class eConfReq : PEvent
    {
        public eConfReq() : base() {}
        public eConfReq (PrtNamedTuple payload): base(payload){ }
        public override IPrtValue Clone() { return new eConfReq();}
    }
}
namespace PImplementation
{
    internal partial class eConfResp : PEvent
    {
        public eConfResp() : base() {}
        public eConfResp (PrtBool payload): base(payload){ }
        public override IPrtValue Clone() { return new eConfResp();}
    }
}
namespace PImplementation
{
    internal partial class eGetDefaultValueResp : PEvent
    {
        public eGetDefaultValueResp() : base() {}
        public eGetDefaultValueResp (PrtSeq payload): base(payload){ }
        public override IPrtValue Clone() { return new eGetDefaultValueResp();}
    }
}
namespace PImplementation
{
    internal partial class eSpecGetDefaultValueReq : PEvent
    {
        public eSpecGetDefaultValueReq() : base() {}
        public eSpecGetDefaultValueReq (PMachineValue payload): base(payload){ }
        public override IPrtValue Clone() { return new eSpecGetDefaultValueReq();}
    }
}
namespace PImplementation
{
    internal partial class eParsetFix : PEvent
    {
        public eParsetFix() : base() {}
        public eParsetFix (PrtNamedTuple payload): base(payload){ }
        public override IPrtValue Clone() { return new eParsetFix();}
    }
}
namespace PImplementation
{
    internal partial class eParsetVar : PEvent
    {
        public eParsetVar() : base() {}
        public eParsetVar (PrtNamedTuple payload): base(payload){ }
        public override IPrtValue Clone() { return new eParsetVar();}
    }
}
namespace PImplementation
{
    internal partial class eParsetHdr : PEvent
    {
        public eParsetHdr() : base() {}
        public eParsetHdr (PrtNamedTuple payload): base(payload){ }
        public override IPrtValue Clone() { return new eParsetHdr();}
    }
}
namespace PImplementation
{
    internal partial class eParsetPara : PEvent
    {
        public eParsetPara() : base() {}
        public eParsetPara (PrtNamedTuple payload): base(payload){ }
        public override IPrtValue Clone() { return new eParsetPara();}
    }
}
namespace PImplementation
{
    internal partial class eParsetPlist : PEvent
    {
        public eParsetPlist() : base() {}
        public eParsetPlist (PrtNamedTuple payload): base(payload){ }
        public override IPrtValue Clone() { return new eParsetPlist();}
    }
}
namespace PImplementation
{
    internal partial class eParsetMsg : PEvent
    {
        public eParsetMsg() : base() {}
        public eParsetMsg (PrtNamedTuple payload): base(payload){ }
        public override IPrtValue Clone() { return new eParsetMsg();}
    }
}
namespace PImplementation
{
    internal partial class eComposetFix : PEvent
    {
        public eComposetFix() : base() {}
        public eComposetFix (PrtNamedTuple payload): base(payload){ }
        public override IPrtValue Clone() { return new eComposetFix();}
    }
}
namespace PImplementation
{
    internal partial class eComposetVar : PEvent
    {
        public eComposetVar() : base() {}
        public eComposetVar (PrtNamedTuple payload): base(payload){ }
        public override IPrtValue Clone() { return new eComposetVar();}
    }
}
namespace PImplementation
{
    internal partial class eComposetHdr : PEvent
    {
        public eComposetHdr() : base() {}
        public eComposetHdr (PrtNamedTuple payload): base(payload){ }
        public override IPrtValue Clone() { return new eComposetHdr();}
    }
}
namespace PImplementation
{
    internal partial class eComposetPara : PEvent
    {
        public eComposetPara() : base() {}
        public eComposetPara (PrtNamedTuple payload): base(payload){ }
        public override IPrtValue Clone() { return new eComposetPara();}
    }
}
namespace PImplementation
{
    internal partial class eComposetPlist : PEvent
    {
        public eComposetPlist() : base() {}
        public eComposetPlist (PrtNamedTuple payload): base(payload){ }
        public override IPrtValue Clone() { return new eComposetPlist();}
    }
}
namespace PImplementation
{
    internal partial class eComposetMsg : PEvent
    {
        public eComposetMsg() : base() {}
        public eComposetMsg (PrtNamedTuple payload): base(payload){ }
        public override IPrtValue Clone() { return new eComposetMsg();}
    }
}
namespace PImplementation
{
    public static partial class GlobalFunctions
    {
        public static PrtInt readBuffer(PrtSeq buf, PMachine currentMachine)
        {
            PrtInt bufsize = ((PrtInt)0);
            PrtInt counter = ((PrtInt)0);
            PrtInt ret = ((PrtInt)0);
            PrtInt TMP_tmp0 = ((PrtInt)0);
            PrtBool TMP_tmp1 = ((PrtBool)false);
            PrtBool TMP_tmp2 = ((PrtBool)false);
            PrtInt TMP_tmp3 = ((PrtInt)0);
            PrtInt TMP_tmp4 = ((PrtInt)0);
            PrtInt TMP_tmp5 = ((PrtInt)0);
            PrtInt TMP_tmp6 = ((PrtInt)0);
            TMP_tmp0 = (PrtInt)(((PrtInt)(buf).Count));
            bufsize = TMP_tmp0;
            counter = (PrtInt)(((PrtInt)0));
            ret = (PrtInt)(((PrtInt)0));
            while (((PrtBool)true))
            {
                TMP_tmp1 = (PrtBool)((counter) < (bufsize));
                TMP_tmp2 = (PrtBool)(((PrtBool)((IPrtValue)TMP_tmp1)?.Clone()));
                if (TMP_tmp2)
                {
                }
                else
                {
                    break;
                }
                TMP_tmp3 = (PrtInt)((ret) * (((PrtInt)256)));
                ret = TMP_tmp3;
                TMP_tmp4 = (PrtInt)(((PrtSeq)buf)[counter]);
                TMP_tmp5 = (PrtInt)((ret) + (TMP_tmp4));
                ret = TMP_tmp5;
                TMP_tmp6 = (PrtInt)((counter) + (((PrtInt)1)));
                counter = TMP_tmp6;
            }
            return ((PrtInt)((IPrtValue)ret)?.Clone());
        }
    }
}
namespace PImplementation
{
    public static partial class GlobalFunctions
    {
        public static PrtSeq writeBuffer(PrtInt val, PrtInt bufsize_1, PMachine currentMachine)
        {
            PrtInt counter_1 = ((PrtInt)0);
            PrtInt curval = ((PrtInt)0);
            PrtInt tmp1 = ((PrtInt)0);
            PrtInt tmp2 = ((PrtInt)0);
            PrtSeq ret_1 = new PrtSeq();
            PrtInt counter2 = ((PrtInt)0);
            PrtSeq TMP_tmp0_1 = new PrtSeq();
            PrtBool TMP_tmp1_1 = ((PrtBool)false);
            PrtBool TMP_tmp2_1 = ((PrtBool)false);
            PrtInt TMP_tmp3_1 = ((PrtInt)0);
            PrtBool TMP_tmp4_1 = ((PrtBool)false);
            PrtBool TMP_tmp5_1 = ((PrtBool)false);
            PrtInt TMP_tmp6_1 = ((PrtInt)0);
            PrtInt TMP_tmp7 = ((PrtInt)0);
            PrtInt TMP_tmp8 = ((PrtInt)0);
            PrtInt TMP_tmp9 = ((PrtInt)0);
            PrtInt TMP_tmp10 = ((PrtInt)0);
            PrtInt TMP_tmp11 = ((PrtInt)0);
            PrtInt TMP_tmp12 = ((PrtInt)0);
            PrtInt TMP_tmp13 = ((PrtInt)0);
            PrtInt TMP_tmp14 = ((PrtInt)0);
            counter_1 = (PrtInt)(((PrtInt)0));
            curval = (PrtInt)(((PrtInt)((IPrtValue)val)?.Clone()));
            tmp1 = (PrtInt)(((PrtInt)1));
            TMP_tmp0_1 = (PrtSeq)(new PrtSeq());
            ret_1 = TMP_tmp0_1;
            while (((PrtBool)true))
            {
                TMP_tmp1_1 = (PrtBool)((counter_1) < (bufsize_1));
                TMP_tmp2_1 = (PrtBool)(((PrtBool)((IPrtValue)TMP_tmp1_1)?.Clone()));
                if (TMP_tmp2_1)
                {
                }
                else
                {
                    break;
                }
                while (((PrtBool)true))
                {
                    TMP_tmp3_1 = (PrtInt)((bufsize_1) - (counter_1));
                    TMP_tmp4_1 = (PrtBool)((counter2) < (TMP_tmp3_1));
                    TMP_tmp5_1 = (PrtBool)(((PrtBool)((IPrtValue)TMP_tmp4_1)?.Clone()));
                    if (TMP_tmp5_1)
                    {
                    }
                    else
                    {
                        break;
                    }
                    TMP_tmp6_1 = (PrtInt)((((PrtInt)256)) * (tmp1));
                    tmp1 = TMP_tmp6_1;
                    TMP_tmp7 = (PrtInt)((counter2) + (((PrtInt)1)));
                    counter2 = TMP_tmp7;
                }
                TMP_tmp8 = (PrtInt)((curval) / (tmp1));
                tmp2 = TMP_tmp8;
                TMP_tmp9 = (PrtInt)(((PrtInt)(ret_1).Count));
                TMP_tmp10 = (PrtInt)((TMP_tmp9) - (((PrtInt)1)));
                TMP_tmp11 = (PrtInt)(((PrtInt)((IPrtValue)tmp2)?.Clone()));
                ((PrtSeq)ret_1).Insert(TMP_tmp10, TMP_tmp11);
                TMP_tmp12 = (PrtInt)((tmp1) * (tmp2));
                TMP_tmp13 = (PrtInt)((curval) - (TMP_tmp12));
                curval = TMP_tmp13;
                TMP_tmp14 = (PrtInt)((counter_1) + (((PrtInt)1)));
                counter_1 = TMP_tmp14;
            }
            return ((PrtSeq)((IPrtValue)ret_1)?.Clone());
        }
    }
}
namespace PImplementation
{
    public static partial class GlobalFunctions
    {
        public static void SetupClientServerSystem(PrtInt numClients, PMachine currentMachine)
        {
            PMachineValue ConnServer = null;
            PMachineValue InitServer = null;
            PrtSeq InitConnetcion = new PrtSeq();
            PrtSeq InitChannel = new PrtSeq();
            PrtNamedTuple tmpPara = (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PrtInt counter_2 = ((PrtInt)0);
            PMachineValue TMP_tmp0_2 = null;
            PrtSeq TMP_tmp1_2 = new PrtSeq();
            PrtSeq TMP_tmp2_2 = new PrtSeq();
            PrtNamedTuple TMP_tmp3_2 = (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PrtInt TMP_tmp4_2 = ((PrtInt)0);
            PrtInt TMP_tmp5_2 = ((PrtInt)0);
            PrtSeq TMP_tmp6_2 = new PrtSeq();
            PrtInt TMP_tmp7_1 = ((PrtInt)0);
            PrtInt TMP_tmp8_1 = ((PrtInt)0);
            PrtInt TMP_tmp9_1 = ((PrtInt)0);
            PrtSeq TMP_tmp10_1 = new PrtSeq();
            PrtNamedTuple TMP_tmp11_1 = (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PrtInt TMP_tmp12_1 = ((PrtInt)0);
            PrtInt TMP_tmp13_1 = ((PrtInt)0);
            PrtSeq TMP_tmp14_1 = new PrtSeq();
            PrtInt TMP_tmp15 = ((PrtInt)0);
            PrtInt TMP_tmp16 = ((PrtInt)0);
            PrtInt TMP_tmp17 = ((PrtInt)0);
            PrtSeq TMP_tmp18 = new PrtSeq();
            PrtNamedTuple TMP_tmp19 = (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PrtSeq TMP_tmp20 = new PrtSeq();
            PMachineValue TMP_tmp21 = null;
            PrtSeq TMP_tmp22 = new PrtSeq();
            PrtNamedTuple TMP_tmp23 = (new PrtNamedTuple(new string[]{"serv","conn"},null, new PrtSeq()));
            PMachineValue TMP_tmp24 = null;
            PrtBool TMP_tmp25 = ((PrtBool)false);
            PrtBool TMP_tmp26 = ((PrtBool)false);
            PMachineValue TMP_tmp27 = null;
            PMachineValue TMP_tmp28 = null;
            PrtNamedTuple TMP_tmp29 = (new PrtNamedTuple(new string[]{"_InitServer","_ConnServer"},null, null));
            TMP_tmp0_2 = (PMachineValue)(currentMachine.CreateInterface<I_VarInitMachine>( currentMachine));
            InitServer = TMP_tmp0_2;
            TMP_tmp1_2 = (PrtSeq)(new PrtSeq());
            InitConnetcion = TMP_tmp1_2;
            TMP_tmp2_2 = (PrtSeq)(new PrtSeq());
            InitChannel = TMP_tmp2_2;
            TMP_tmp3_2 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))));
            tmpPara = TMP_tmp3_2;
            ((PrtNamedTuple)tmpPara)["nKey"] = (PrtInt)(((PrtInt)1));
            ((PrtNamedTuple)((PrtNamedTuple)tmpPara)["fKey"])["nSize"] = (PrtInt)(((PrtInt)1));
            ((PrtNamedTuple)((PrtNamedTuple)tmpPara)["fKey"])["nLow"] = (PrtInt)(((PrtInt)1));
            ((PrtNamedTuple)((PrtNamedTuple)tmpPara)["fKey"])["nHigh"] = (PrtInt)(((PrtInt)1));
            TMP_tmp4_2 = (PrtInt)(((PrtInt)1));
            TMP_tmp5_2 = (PrtInt)(((PrtInt)1));
            TMP_tmp6_2 = (PrtSeq)(GlobalFunctions.writeBuffer(TMP_tmp4_2, TMP_tmp5_2, currentMachine));
            ((PrtNamedTuple)((PrtNamedTuple)tmpPara)["fKey"])["value"] = TMP_tmp6_2;
            ((PrtNamedTuple)((PrtNamedTuple)tmpPara)["fVal"])["nSize"] = (PrtInt)(((PrtInt)2));
            ((PrtNamedTuple)((PrtNamedTuple)tmpPara)["fVal"])["nLow"] = (PrtInt)(((PrtInt)1));
            ((PrtNamedTuple)((PrtNamedTuple)tmpPara)["fVal"])["nHigh"] = (PrtInt)(((PrtInt)65535));
            TMP_tmp7_1 = (PrtInt)(((PrtInt)2));
            TMP_tmp8_1 = (PrtInt)(((PrtInt)currentMachine.TryRandom(((PrtInt)65535))));
            TMP_tmp9_1 = (PrtInt)((TMP_tmp8_1) + (((PrtInt)1)));
            TMP_tmp10_1 = (PrtSeq)(GlobalFunctions.writeBuffer(TMP_tmp7_1, TMP_tmp9_1, currentMachine));
            ((PrtNamedTuple)((PrtNamedTuple)tmpPara)["fVal"])["value"] = TMP_tmp10_1;
            TMP_tmp11_1 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)tmpPara)?.Clone()));
            ((PrtSeq)InitChannel).Insert(((PrtInt)0), TMP_tmp11_1);
            ((PrtNamedTuple)tmpPara)["nKey"] = (PrtInt)(((PrtInt)2));
            ((PrtNamedTuple)((PrtNamedTuple)tmpPara)["fKey"])["nSize"] = (PrtInt)(((PrtInt)1));
            ((PrtNamedTuple)((PrtNamedTuple)tmpPara)["fKey"])["nLow"] = (PrtInt)(((PrtInt)2));
            ((PrtNamedTuple)((PrtNamedTuple)tmpPara)["fKey"])["nHigh"] = (PrtInt)(((PrtInt)2));
            TMP_tmp12_1 = (PrtInt)(((PrtInt)1));
            TMP_tmp13_1 = (PrtInt)(((PrtInt)2));
            TMP_tmp14_1 = (PrtSeq)(GlobalFunctions.writeBuffer(TMP_tmp12_1, TMP_tmp13_1, currentMachine));
            ((PrtNamedTuple)((PrtNamedTuple)tmpPara)["fKey"])["value"] = TMP_tmp14_1;
            ((PrtNamedTuple)((PrtNamedTuple)tmpPara)["fVal"])["nSize"] = (PrtInt)(((PrtInt)1));
            ((PrtNamedTuple)((PrtNamedTuple)tmpPara)["fVal"])["nLow"] = (PrtInt)(((PrtInt)1));
            ((PrtNamedTuple)((PrtNamedTuple)tmpPara)["fVal"])["nHigh"] = (PrtInt)(((PrtInt)23));
            TMP_tmp15 = (PrtInt)(((PrtInt)1));
            TMP_tmp16 = (PrtInt)(((PrtInt)currentMachine.TryRandom(((PrtInt)23))));
            TMP_tmp17 = (PrtInt)((TMP_tmp16) + (((PrtInt)1)));
            TMP_tmp18 = (PrtSeq)(GlobalFunctions.writeBuffer(TMP_tmp15, TMP_tmp17, currentMachine));
            ((PrtNamedTuple)((PrtNamedTuple)tmpPara)["fVal"])["value"] = TMP_tmp18;
            TMP_tmp19 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)tmpPara)?.Clone()));
            ((PrtSeq)InitChannel).Insert(((PrtInt)1), TMP_tmp19);
            TMP_tmp20 = (PrtSeq)(((PrtSeq)((IPrtValue)InitChannel)?.Clone()));
            ((PrtSeq)InitConnetcion).Insert(((PrtInt)0), TMP_tmp20);
            TMP_tmp21 = (PMachineValue)(((PMachineValue)((IPrtValue)InitServer)?.Clone()));
            TMP_tmp22 = (PrtSeq)(((PrtSeq)((IPrtValue)InitConnetcion)?.Clone()));
            TMP_tmp23 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"serv","conn"}, TMP_tmp21, TMP_tmp22)));
            TMP_tmp24 = (PMachineValue)(currentMachine.CreateInterface<I_ConnMachine>( currentMachine, TMP_tmp23));
            ConnServer = TMP_tmp24;
            while (((PrtBool)true))
            {
                TMP_tmp25 = (PrtBool)((counter_2) < (numClients));
                TMP_tmp26 = (PrtBool)(((PrtBool)((IPrtValue)TMP_tmp25)?.Clone()));
                if (TMP_tmp26)
                {
                }
                else
                {
                    break;
                }
                TMP_tmp27 = (PMachineValue)(((PMachineValue)((IPrtValue)InitServer)?.Clone()));
                TMP_tmp28 = (PMachineValue)(((PMachineValue)((IPrtValue)ConnServer)?.Clone()));
                TMP_tmp29 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"_InitServer","_ConnServer"}, TMP_tmp27, TMP_tmp28)));
                currentMachine.CreateInterface<I_ClientMachine>(currentMachine, TMP_tmp29);
            }
        }
    }
}
namespace PImplementation
{
    internal partial class ClientMachine : PMachine
    {
        private PMachineValue InitServer_1 = null;
        private PMachineValue ConnServer_1 = null;
        private PrtNamedTuple vmsgL2Cmd = (new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null)), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()))));
        public class ConstructorEvent : PEvent{public ConstructorEvent(PrtNamedTuple val) : base(val) { }}
        
        protected override Event GetConstructorEvent(IPrtValue value) { return new ConstructorEvent((PrtNamedTuple)value); }
        public ClientMachine() {
            this.sends.Add(nameof(eChanGotoConfig));
            this.sends.Add(nameof(eChanGotoConnected));
            this.sends.Add(nameof(eComposetFix));
            this.sends.Add(nameof(eComposetHdr));
            this.sends.Add(nameof(eComposetMsg));
            this.sends.Add(nameof(eComposetPara));
            this.sends.Add(nameof(eComposetPlist));
            this.sends.Add(nameof(eComposetVar));
            this.sends.Add(nameof(eConfReq));
            this.sends.Add(nameof(eConfResp));
            this.sends.Add(nameof(eConnReq));
            this.sends.Add(nameof(eConnResp));
            this.sends.Add(nameof(eGetDefaultValueResp));
            this.sends.Add(nameof(eL2CmdReq));
            this.sends.Add(nameof(eParsetFix));
            this.sends.Add(nameof(eParsetHdr));
            this.sends.Add(nameof(eParsetMsg));
            this.sends.Add(nameof(eParsetPara));
            this.sends.Add(nameof(eParsetPlist));
            this.sends.Add(nameof(eParsetVar));
            this.sends.Add(nameof(eSpecGetDefaultValueReq));
            this.sends.Add(nameof(eStartTimer));
            this.sends.Add(nameof(eTimeOut));
            this.sends.Add(nameof(PHalt));
            this.receives.Add(nameof(eChanGotoConfig));
            this.receives.Add(nameof(eChanGotoConnected));
            this.receives.Add(nameof(eComposetFix));
            this.receives.Add(nameof(eComposetHdr));
            this.receives.Add(nameof(eComposetMsg));
            this.receives.Add(nameof(eComposetPara));
            this.receives.Add(nameof(eComposetPlist));
            this.receives.Add(nameof(eComposetVar));
            this.receives.Add(nameof(eConfReq));
            this.receives.Add(nameof(eConfResp));
            this.receives.Add(nameof(eConnReq));
            this.receives.Add(nameof(eConnResp));
            this.receives.Add(nameof(eGetDefaultValueResp));
            this.receives.Add(nameof(eL2CmdReq));
            this.receives.Add(nameof(eParsetFix));
            this.receives.Add(nameof(eParsetHdr));
            this.receives.Add(nameof(eParsetMsg));
            this.receives.Add(nameof(eParsetPara));
            this.receives.Add(nameof(eParsetPlist));
            this.receives.Add(nameof(eParsetVar));
            this.receives.Add(nameof(eSpecGetDefaultValueReq));
            this.receives.Add(nameof(eStartTimer));
            this.receives.Add(nameof(eTimeOut));
            this.receives.Add(nameof(PHalt));
        }
        
        public async Task Anon(Event currentMachine_dequeuedEvent)
        {
            ClientMachine currentMachine = this;
            PrtNamedTuple input = (PrtNamedTuple)(gotoPayload ?? ((PEvent)currentMachine_dequeuedEvent).Payload);
            this.gotoPayload = null;
            PMachineValue TMP_tmp0_3 = null;
            PMachineValue TMP_tmp1_3 = null;
            PMachineValue TMP_tmp2_3 = null;
            PMachineValue TMP_tmp3_3 = null;
            PMachineValue TMP_tmp4_3 = null;
            PEvent TMP_tmp5_3 = null;
            PMachineValue TMP_tmp6_3 = null;
            IPrtValue TMP_tmp7_2 = null;
            PrtNamedTuple TMP_tmp8_2 = (new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null)), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()))));
            PrtInt TMP_tmp9_2 = ((PrtInt)0);
            TMP_tmp0_3 = (PMachineValue)(((PrtNamedTuple)input)["_InitServer"]);
            TMP_tmp1_3 = (PMachineValue)(((PMachineValue)((IPrtValue)TMP_tmp0_3)?.Clone()));
            InitServer_1 = TMP_tmp1_3;
            TMP_tmp2_3 = (PMachineValue)(((PrtNamedTuple)input)["_ConnServer"]);
            TMP_tmp3_3 = (PMachineValue)(((PMachineValue)((IPrtValue)TMP_tmp2_3)?.Clone()));
            ConnServer_1 = TMP_tmp3_3;
            TMP_tmp4_3 = (PMachineValue)(((PMachineValue)((IPrtValue)InitServer_1)?.Clone()));
            TMP_tmp5_3 = (PEvent)(new eSpecGetDefaultValueReq(null));
            TMP_tmp6_3 = (PMachineValue)(currentMachine.self);
            currentMachine.TrySendEvent(TMP_tmp4_3, (Event)TMP_tmp5_3, TMP_tmp6_3);
            var PGEN_recvEvent = await currentMachine.TryReceiveEvent(typeof(eGetDefaultValueResp));
            switch (PGEN_recvEvent) {
                case eGetDefaultValueResp PGEN_evt: {
                    PrtSeq resp = (PrtSeq)(PGEN_evt.Payload);
                    TMP_tmp7_2 = (IPrtValue)(((PrtSeq)resp)[((PrtInt)18)]);
                    TMP_tmp8_2 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)((IPrtValue)TMP_tmp7_2)?.Clone())));
                    vmsgL2Cmd = TMP_tmp8_2;
                } break;
            }
            TMP_tmp9_2 = (PrtInt)(((PrtInt)1));
            currentMachine.TryGotoState<SendReqs>(TMP_tmp9_2);
            return;
        }
        public void Anon_1(Event currentMachine_dequeuedEvent)
        {
            ClientMachine currentMachine = this;
            PrtInt IsConn = (PrtInt)(gotoPayload ?? ((PEvent)currentMachine_dequeuedEvent).Payload);
            this.gotoPayload = null;
            PrtNamedTuple request = (new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null)), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()))));
            PrtNamedTuple request_option0 = (new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null)), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()))));
            PrtNamedTuple request_option1 = (new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null)), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()))));
            PrtNamedTuple request_option1_msub = (new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null)), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()))));
            PrtNamedTuple connreq = (new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null)), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()))));
            PrtNamedTuple confreq = (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null));
            PrtNamedTuple TMP_tmp0_4 = (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()));
            PrtSeq TMP_tmp1_4 = new PrtSeq();
            PrtNamedTuple TMP_tmp2_4 = (new PrtNamedTuple(new string[]{"nType","msub"},((PrtInt)0), null));
            IPrtValue TMP_tmp3_4 = null;
            PrtNamedTuple TMP_tmp4_4 = (new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null)), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()))));
            PrtNamedTuple TMP_tmp5_4 = (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()));
            PrtSeq TMP_tmp6_4 = new PrtSeq();
            PrtNamedTuple TMP_tmp7_3 = (new PrtNamedTuple(new string[]{"nType","msub"},((PrtInt)0), null));
            IPrtValue TMP_tmp8_3 = null;
            PrtNamedTuple TMP_tmp9_3 = (new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null)), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()))));
            PrtNamedTuple TMP_tmp10_2 = (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null));
            IPrtValue TMP_tmp11_2 = null;
            PrtNamedTuple TMP_tmp12_2 = (new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null)), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()))));
            PrtNamedTuple TMP_tmp13_2 = (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null));
            PrtNamedTuple TMP_tmp14_2 = (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null));
            PrtBool TMP_tmp15_1 = ((PrtBool)false);
            PrtNamedTuple TMP_tmp16_1 = (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()));
            PrtNamedTuple TMP_tmp17_1 = (new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PrtSeq TMP_tmp18_1 = new PrtSeq();
            PrtNamedTuple TMP_tmp19_1 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtInt TMP_tmp20_1 = ((PrtInt)0);
            PrtNamedTuple TMP_tmp21_1 = (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()));
            PrtSeq TMP_tmp22_1 = new PrtSeq();
            PrtNamedTuple TMP_tmp23_1 = (new PrtNamedTuple(new string[]{"nType","msub"},((PrtInt)0), null));
            PrtInt TMP_tmp24_1 = ((PrtInt)0);
            PrtSeq TMP_tmp25_1 = new PrtSeq();
            PrtSeq TMP_tmp26_1 = new PrtSeq();
            PrtNamedTuple TMP_tmp27_1 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtInt TMP_tmp28_1 = ((PrtInt)0);
            PrtSeq TMP_tmp29_1 = new PrtSeq();
            PrtNamedTuple TMP_tmp30 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtInt TMP_tmp31 = ((PrtInt)0);
            PrtSeq TMP_tmp32 = new PrtSeq();
            PrtNamedTuple TMP_tmp33 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtInt TMP_tmp34 = ((PrtInt)0);
            PrtInt TMP_tmp35 = ((PrtInt)0);
            PrtInt TMP_tmp36 = ((PrtInt)0);
            PrtInt TMP_tmp37 = ((PrtInt)0);
            PrtInt TMP_tmp38 = ((PrtInt)0);
            PrtSeq TMP_tmp39 = new PrtSeq();
            PrtSeq TMP_tmp40 = new PrtSeq();
            PrtNamedTuple TMP_tmp41 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtInt TMP_tmp42 = ((PrtInt)0);
            PrtSeq TMP_tmp43 = new PrtSeq();
            PrtNamedTuple TMP_tmp44 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtInt TMP_tmp45 = ((PrtInt)0);
            PrtSeq TMP_tmp46 = new PrtSeq();
            PrtNamedTuple TMP_tmp47 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtInt TMP_tmp48 = ((PrtInt)0);
            PrtInt TMP_tmp49 = ((PrtInt)0);
            PrtInt TMP_tmp50 = ((PrtInt)0);
            PrtInt TMP_tmp51 = ((PrtInt)0);
            PrtInt TMP_tmp52 = ((PrtInt)0);
            PrtSeq TMP_tmp53 = new PrtSeq();
            PrtNamedTuple TMP_tmp54 = (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()));
            PrtNamedTuple TMP_tmp55 = (new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PrtSeq TMP_tmp56 = new PrtSeq();
            PrtNamedTuple TMP_tmp57 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtInt TMP_tmp58 = ((PrtInt)0);
            PrtNamedTuple TMP_tmp59 = (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()));
            PrtSeq TMP_tmp60 = new PrtSeq();
            PrtNamedTuple TMP_tmp61 = (new PrtNamedTuple(new string[]{"nType","msub"},((PrtInt)0), null));
            PrtInt TMP_tmp62 = ((PrtInt)0);
            PrtSeq TMP_tmp63 = new PrtSeq();
            PrtNamedTuple TMP_tmp64 = (new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PrtSeq TMP_tmp65 = new PrtSeq();
            PrtNamedTuple TMP_tmp66 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtInt TMP_tmp67 = ((PrtInt)0);
            PrtNamedTuple TMP_tmp68 = (new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PrtSeq TMP_tmp69 = new PrtSeq();
            PrtNamedTuple TMP_tmp70 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtInt TMP_tmp71 = ((PrtInt)0);
            PrtNamedTuple TMP_tmp72 = (new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PrtSeq TMP_tmp73 = new PrtSeq();
            PrtNamedTuple TMP_tmp74 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtInt TMP_tmp75 = ((PrtInt)0);
            PrtInt TMP_tmp76 = ((PrtInt)0);
            PrtInt TMP_tmp77 = ((PrtInt)0);
            PrtInt TMP_tmp78 = ((PrtInt)0);
            PrtInt TMP_tmp79 = ((PrtInt)0);
            PrtSeq TMP_tmp80 = new PrtSeq();
            PrtNamedTuple TMP_tmp81 = (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq()));
            PrtSeq TMP_tmp82 = new PrtSeq();
            PrtNamedTuple TMP_tmp83 = (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PrtNamedTuple TMP_tmp84 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtInt TMP_tmp85 = ((PrtInt)0);
            PrtNamedTuple TMP_tmp86 = (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq()));
            PrtSeq TMP_tmp87 = new PrtSeq();
            PrtNamedTuple TMP_tmp88 = (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PrtNamedTuple TMP_tmp89 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtInt TMP_tmp90 = ((PrtInt)0);
            PrtNamedTuple TMP_tmp91 = (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq()));
            PrtSeq TMP_tmp92 = new PrtSeq();
            PrtNamedTuple TMP_tmp93 = (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PrtNamedTuple TMP_tmp94 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtInt TMP_tmp95 = ((PrtInt)0);
            PrtInt TMP_tmp96 = ((PrtInt)0);
            PrtInt TMP_tmp97 = ((PrtInt)0);
            PrtInt TMP_tmp98 = ((PrtInt)0);
            PrtInt TMP_tmp99 = ((PrtInt)0);
            PrtSeq TMP_tmp100 = new PrtSeq();
            PrtNamedTuple TMP_tmp101 = (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq()));
            PrtSeq TMP_tmp102 = new PrtSeq();
            PrtNamedTuple TMP_tmp103 = (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PrtNamedTuple TMP_tmp104 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtInt TMP_tmp105 = ((PrtInt)0);
            PrtNamedTuple TMP_tmp106 = (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq()));
            PrtSeq TMP_tmp107 = new PrtSeq();
            PrtNamedTuple TMP_tmp108 = (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PrtNamedTuple TMP_tmp109 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtInt TMP_tmp110 = ((PrtInt)0);
            PrtNamedTuple TMP_tmp111 = (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq()));
            PrtSeq TMP_tmp112 = new PrtSeq();
            PrtNamedTuple TMP_tmp113 = (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PrtNamedTuple TMP_tmp114 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtInt TMP_tmp115 = ((PrtInt)0);
            PrtInt TMP_tmp116 = ((PrtInt)0);
            PrtInt TMP_tmp117 = ((PrtInt)0);
            PrtInt TMP_tmp118 = ((PrtInt)0);
            PrtInt TMP_tmp119 = ((PrtInt)0);
            PrtSeq TMP_tmp120 = new PrtSeq();
            PMachineValue TMP_tmp121 = null;
            PEvent TMP_tmp122 = null;
            PMachineValue TMP_tmp123 = null;
            PrtNamedTuple TMP_tmp124 = (new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null)), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()))));
            PrtNamedTuple TMP_tmp125 = (new PrtNamedTuple(new string[]{"source","req"},null, (new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null)), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()))))));
            request = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)vmsgL2Cmd)?.Clone()));
            TMP_tmp0_4 = (PrtNamedTuple)(((PrtNamedTuple)request)["hcmsub"]);
            TMP_tmp1_4 = (PrtSeq)(((PrtNamedTuple)TMP_tmp0_4)["msub"]);
            TMP_tmp2_4 = (PrtNamedTuple)(((PrtSeq)TMP_tmp1_4)[((PrtInt)0)]);
            TMP_tmp3_4 = (IPrtValue)(((PrtNamedTuple)TMP_tmp2_4)["msub"]);
            TMP_tmp4_4 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)((IPrtValue)TMP_tmp3_4)?.Clone())));
            request_option0 = TMP_tmp4_4;
            TMP_tmp5_4 = (PrtNamedTuple)(((PrtNamedTuple)request)["hcmsub"]);
            TMP_tmp6_4 = (PrtSeq)(((PrtNamedTuple)TMP_tmp5_4)["msub"]);
            TMP_tmp7_3 = (PrtNamedTuple)(((PrtSeq)TMP_tmp6_4)[((PrtInt)1)]);
            TMP_tmp8_3 = (IPrtValue)(((PrtNamedTuple)TMP_tmp7_3)["msub"]);
            TMP_tmp9_3 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)((IPrtValue)TMP_tmp8_3)?.Clone())));
            request_option1 = TMP_tmp9_3;
            TMP_tmp10_2 = (PrtNamedTuple)(((PrtNamedTuple)request_option1)["hmsub"]);
            TMP_tmp11_2 = (IPrtValue)(((PrtNamedTuple)TMP_tmp10_2)["msub"]);
            TMP_tmp12_2 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)((IPrtValue)TMP_tmp11_2)?.Clone())));
            request_option1_msub = TMP_tmp12_2;
            connreq = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)request_option0)?.Clone()));
            TMP_tmp13_2 = (PrtNamedTuple)(((PrtNamedTuple)request_option1)["hmsub"]);
            TMP_tmp14_2 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)TMP_tmp13_2)?.Clone()));
            confreq = TMP_tmp14_2;
            TMP_tmp15_1 = (PrtBool)((PrtValues.SafeEquals(IsConn,((PrtInt)1))));
            if (TMP_tmp15_1)
            {
                TMP_tmp16_1 = (PrtNamedTuple)(((PrtNamedTuple)request)["hcmsub"]);
                TMP_tmp17_1 = (PrtNamedTuple)(((PrtNamedTuple)TMP_tmp16_1)["h"]);
                TMP_tmp18_1 = (PrtSeq)(((PrtNamedTuple)TMP_tmp17_1)["f"]);
                TMP_tmp19_1 = (PrtNamedTuple)(((PrtSeq)TMP_tmp18_1)[((PrtInt)0)]);
                TMP_tmp20_1 = (PrtInt)(((PrtNamedTuple)TMP_tmp19_1)["nSize"]);
                TMP_tmp21_1 = (PrtNamedTuple)(((PrtNamedTuple)request)["hcmsub"]);
                TMP_tmp22_1 = (PrtSeq)(((PrtNamedTuple)TMP_tmp21_1)["msub"]);
                TMP_tmp23_1 = (PrtNamedTuple)(((PrtSeq)TMP_tmp22_1)[((PrtInt)0)]);
                TMP_tmp24_1 = (PrtInt)(((PrtNamedTuple)TMP_tmp23_1)["nType"]);
                TMP_tmp25_1 = (PrtSeq)(GlobalFunctions.writeBuffer(TMP_tmp20_1, TMP_tmp24_1, currentMachine));
                ((PrtNamedTuple)((PrtSeq)((PrtNamedTuple)((PrtNamedTuple)((PrtNamedTuple)request)["hcmsub"])["h"])["f"])[((PrtInt)0)])["value"] = TMP_tmp25_1;
                TMP_tmp26_1 = (PrtSeq)(((PrtNamedTuple)connreq)["fp"]);
                TMP_tmp27_1 = (PrtNamedTuple)(((PrtSeq)TMP_tmp26_1)[((PrtInt)0)]);
                TMP_tmp28_1 = (PrtInt)(((PrtNamedTuple)TMP_tmp27_1)["nSize"]);
                TMP_tmp29_1 = (PrtSeq)(((PrtNamedTuple)connreq)["fp"]);
                TMP_tmp30 = (PrtNamedTuple)(((PrtSeq)TMP_tmp29_1)[((PrtInt)0)]);
                TMP_tmp31 = (PrtInt)(((PrtNamedTuple)TMP_tmp30)["nHigh"]);
                TMP_tmp32 = (PrtSeq)(((PrtNamedTuple)connreq)["fp"]);
                TMP_tmp33 = (PrtNamedTuple)(((PrtSeq)TMP_tmp32)[((PrtInt)0)]);
                TMP_tmp34 = (PrtInt)(((PrtNamedTuple)TMP_tmp33)["nLow"]);
                TMP_tmp35 = (PrtInt)((TMP_tmp31) - (TMP_tmp34));
                TMP_tmp36 = (PrtInt)((TMP_tmp35) + (((PrtInt)1)));
                TMP_tmp37 = (PrtInt)(((PrtInt)currentMachine.TryRandom(TMP_tmp36)));
                TMP_tmp38 = (PrtInt)((TMP_tmp37) + (((PrtInt)1)));
                TMP_tmp39 = (PrtSeq)(GlobalFunctions.writeBuffer(TMP_tmp28_1, TMP_tmp38, currentMachine));
                ((PrtNamedTuple)((PrtSeq)((PrtNamedTuple)request_option0)["fp"])[((PrtInt)0)])["value"] = TMP_tmp39;
                TMP_tmp40 = (PrtSeq)(((PrtNamedTuple)connreq)["fp"]);
                TMP_tmp41 = (PrtNamedTuple)(((PrtSeq)TMP_tmp40)[((PrtInt)1)]);
                TMP_tmp42 = (PrtInt)(((PrtNamedTuple)TMP_tmp41)["nSize"]);
                TMP_tmp43 = (PrtSeq)(((PrtNamedTuple)connreq)["fp"]);
                TMP_tmp44 = (PrtNamedTuple)(((PrtSeq)TMP_tmp43)[((PrtInt)1)]);
                TMP_tmp45 = (PrtInt)(((PrtNamedTuple)TMP_tmp44)["nHigh"]);
                TMP_tmp46 = (PrtSeq)(((PrtNamedTuple)connreq)["fp"]);
                TMP_tmp47 = (PrtNamedTuple)(((PrtSeq)TMP_tmp46)[((PrtInt)1)]);
                TMP_tmp48 = (PrtInt)(((PrtNamedTuple)TMP_tmp47)["nLow"]);
                TMP_tmp49 = (PrtInt)((TMP_tmp45) - (TMP_tmp48));
                TMP_tmp50 = (PrtInt)((TMP_tmp49) + (((PrtInt)1)));
                TMP_tmp51 = (PrtInt)(((PrtInt)currentMachine.TryRandom(TMP_tmp50)));
                TMP_tmp52 = (PrtInt)((TMP_tmp51) + (((PrtInt)1)));
                TMP_tmp53 = (PrtSeq)(GlobalFunctions.writeBuffer(TMP_tmp42, TMP_tmp52, currentMachine));
                ((PrtNamedTuple)((PrtSeq)((PrtNamedTuple)request_option0)["fp"])[((PrtInt)1)])["value"] = TMP_tmp53;
                ((PrtNamedTuple)((PrtSeq)((PrtNamedTuple)((PrtNamedTuple)request)["hcmsub"])["msub"])[((PrtInt)0)])["msub"] = (IPrtValue)(new IPrtValue(((PrtNamedTuple)((IPrtValue)request_option0)?.Clone())));
            }
            else
            {
                TMP_tmp54 = (PrtNamedTuple)(((PrtNamedTuple)request)["hcmsub"]);
                TMP_tmp55 = (PrtNamedTuple)(((PrtNamedTuple)TMP_tmp54)["h"]);
                TMP_tmp56 = (PrtSeq)(((PrtNamedTuple)TMP_tmp55)["f"]);
                TMP_tmp57 = (PrtNamedTuple)(((PrtSeq)TMP_tmp56)[((PrtInt)0)]);
                TMP_tmp58 = (PrtInt)(((PrtNamedTuple)TMP_tmp57)["nSize"]);
                TMP_tmp59 = (PrtNamedTuple)(((PrtNamedTuple)request)["hcmsub"]);
                TMP_tmp60 = (PrtSeq)(((PrtNamedTuple)TMP_tmp59)["msub"]);
                TMP_tmp61 = (PrtNamedTuple)(((PrtSeq)TMP_tmp60)[((PrtInt)1)]);
                TMP_tmp62 = (PrtInt)(((PrtNamedTuple)TMP_tmp61)["nType"]);
                TMP_tmp63 = (PrtSeq)(GlobalFunctions.writeBuffer(TMP_tmp58, TMP_tmp62, currentMachine));
                ((PrtNamedTuple)((PrtSeq)((PrtNamedTuple)((PrtNamedTuple)((PrtNamedTuple)request)["hcmsub"])["h"])["f"])[((PrtInt)0)])["value"] = TMP_tmp63;
                TMP_tmp64 = (PrtNamedTuple)(((PrtNamedTuple)confreq)["h"]);
                TMP_tmp65 = (PrtSeq)(((PrtNamedTuple)TMP_tmp64)["f"]);
                TMP_tmp66 = (PrtNamedTuple)(((PrtSeq)TMP_tmp65)[((PrtInt)0)]);
                TMP_tmp67 = (PrtInt)(((PrtNamedTuple)TMP_tmp66)["nSize"]);
                TMP_tmp68 = (PrtNamedTuple)(((PrtNamedTuple)confreq)["h"]);
                TMP_tmp69 = (PrtSeq)(((PrtNamedTuple)TMP_tmp68)["f"]);
                TMP_tmp70 = (PrtNamedTuple)(((PrtSeq)TMP_tmp69)[((PrtInt)0)]);
                TMP_tmp71 = (PrtInt)(((PrtNamedTuple)TMP_tmp70)["nHigh"]);
                TMP_tmp72 = (PrtNamedTuple)(((PrtNamedTuple)confreq)["h"]);
                TMP_tmp73 = (PrtSeq)(((PrtNamedTuple)TMP_tmp72)["f"]);
                TMP_tmp74 = (PrtNamedTuple)(((PrtSeq)TMP_tmp73)[((PrtInt)0)]);
                TMP_tmp75 = (PrtInt)(((PrtNamedTuple)TMP_tmp74)["nLow"]);
                TMP_tmp76 = (PrtInt)((TMP_tmp71) - (TMP_tmp75));
                TMP_tmp77 = (PrtInt)((TMP_tmp76) + (((PrtInt)1)));
                TMP_tmp78 = (PrtInt)(((PrtInt)currentMachine.TryRandom(TMP_tmp77)));
                TMP_tmp79 = (PrtInt)((TMP_tmp78) + (((PrtInt)1)));
                TMP_tmp80 = (PrtSeq)(GlobalFunctions.writeBuffer(TMP_tmp67, TMP_tmp79, currentMachine));
                ((PrtNamedTuple)((PrtSeq)((PrtNamedTuple)((PrtNamedTuple)((PrtNamedTuple)request_option1)["hmsub"])["h"])["f"])[((PrtInt)0)])["value"] = TMP_tmp80;
                TMP_tmp81 = (PrtNamedTuple)(((PrtNamedTuple)request_option1_msub)["l"]);
                TMP_tmp82 = (PrtSeq)(((PrtNamedTuple)TMP_tmp81)["pP"]);
                TMP_tmp83 = (PrtNamedTuple)(((PrtSeq)TMP_tmp82)[((PrtInt)0)]);
                TMP_tmp84 = (PrtNamedTuple)(((PrtNamedTuple)TMP_tmp83)["fKey"]);
                TMP_tmp85 = (PrtInt)(((PrtNamedTuple)TMP_tmp84)["nSize"]);
                TMP_tmp86 = (PrtNamedTuple)(((PrtNamedTuple)request_option1_msub)["l"]);
                TMP_tmp87 = (PrtSeq)(((PrtNamedTuple)TMP_tmp86)["pP"]);
                TMP_tmp88 = (PrtNamedTuple)(((PrtSeq)TMP_tmp87)[((PrtInt)0)]);
                TMP_tmp89 = (PrtNamedTuple)(((PrtNamedTuple)TMP_tmp88)["fKey"]);
                TMP_tmp90 = (PrtInt)(((PrtNamedTuple)TMP_tmp89)["nHigh"]);
                TMP_tmp91 = (PrtNamedTuple)(((PrtNamedTuple)request_option1_msub)["l"]);
                TMP_tmp92 = (PrtSeq)(((PrtNamedTuple)TMP_tmp91)["pP"]);
                TMP_tmp93 = (PrtNamedTuple)(((PrtSeq)TMP_tmp92)[((PrtInt)0)]);
                TMP_tmp94 = (PrtNamedTuple)(((PrtNamedTuple)TMP_tmp93)["fKey"]);
                TMP_tmp95 = (PrtInt)(((PrtNamedTuple)TMP_tmp94)["nLow"]);
                TMP_tmp96 = (PrtInt)((TMP_tmp90) - (TMP_tmp95));
                TMP_tmp97 = (PrtInt)((TMP_tmp96) + (((PrtInt)1)));
                TMP_tmp98 = (PrtInt)(((PrtInt)currentMachine.TryRandom(TMP_tmp97)));
                TMP_tmp99 = (PrtInt)((TMP_tmp98) + (((PrtInt)1)));
                TMP_tmp100 = (PrtSeq)(GlobalFunctions.writeBuffer(TMP_tmp85, TMP_tmp99, currentMachine));
                ((PrtNamedTuple)((PrtNamedTuple)((PrtSeq)((PrtNamedTuple)((PrtNamedTuple)request_option1_msub)["l"])["pP"])[((PrtInt)0)])["fKey"])["value"] = TMP_tmp100;
                TMP_tmp101 = (PrtNamedTuple)(((PrtNamedTuple)request_option1_msub)["l"]);
                TMP_tmp102 = (PrtSeq)(((PrtNamedTuple)TMP_tmp101)["pP"]);
                TMP_tmp103 = (PrtNamedTuple)(((PrtSeq)TMP_tmp102)[((PrtInt)0)]);
                TMP_tmp104 = (PrtNamedTuple)(((PrtNamedTuple)TMP_tmp103)["fVal"]);
                TMP_tmp105 = (PrtInt)(((PrtNamedTuple)TMP_tmp104)["nSize"]);
                TMP_tmp106 = (PrtNamedTuple)(((PrtNamedTuple)request_option1_msub)["l"]);
                TMP_tmp107 = (PrtSeq)(((PrtNamedTuple)TMP_tmp106)["pP"]);
                TMP_tmp108 = (PrtNamedTuple)(((PrtSeq)TMP_tmp107)[((PrtInt)0)]);
                TMP_tmp109 = (PrtNamedTuple)(((PrtNamedTuple)TMP_tmp108)["fVal"]);
                TMP_tmp110 = (PrtInt)(((PrtNamedTuple)TMP_tmp109)["nHigh"]);
                TMP_tmp111 = (PrtNamedTuple)(((PrtNamedTuple)request_option1_msub)["l"]);
                TMP_tmp112 = (PrtSeq)(((PrtNamedTuple)TMP_tmp111)["pP"]);
                TMP_tmp113 = (PrtNamedTuple)(((PrtSeq)TMP_tmp112)[((PrtInt)0)]);
                TMP_tmp114 = (PrtNamedTuple)(((PrtNamedTuple)TMP_tmp113)["fVal"]);
                TMP_tmp115 = (PrtInt)(((PrtNamedTuple)TMP_tmp114)["nLow"]);
                TMP_tmp116 = (PrtInt)((TMP_tmp110) - (TMP_tmp115));
                TMP_tmp117 = (PrtInt)((TMP_tmp116) + (((PrtInt)1)));
                TMP_tmp118 = (PrtInt)(((PrtInt)currentMachine.TryRandom(TMP_tmp117)));
                TMP_tmp119 = (PrtInt)((TMP_tmp118) + (((PrtInt)1)));
                TMP_tmp120 = (PrtSeq)(GlobalFunctions.writeBuffer(TMP_tmp105, TMP_tmp119, currentMachine));
                ((PrtNamedTuple)((PrtNamedTuple)((PrtSeq)((PrtNamedTuple)((PrtNamedTuple)request_option1_msub)["l"])["pP"])[((PrtInt)0)])["fVal"])["value"] = TMP_tmp120;
                ((PrtNamedTuple)((PrtNamedTuple)request_option1)["hmsub"])["msub"] = (IPrtValue)(new IPrtValue(((PrtNamedTuple)((IPrtValue)request_option1_msub)?.Clone())));
                ((PrtNamedTuple)((PrtSeq)((PrtNamedTuple)((PrtNamedTuple)request)["hcmsub"])["msub"])[((PrtInt)1)])["msub"] = (IPrtValue)(new IPrtValue(((PrtNamedTuple)((IPrtValue)request_option1)?.Clone())));
            }
            TMP_tmp121 = (PMachineValue)(((PMachineValue)((IPrtValue)ConnServer_1)?.Clone()));
            TMP_tmp122 = (PEvent)(new eL2CmdReq((new PrtNamedTuple(new string[]{"source","req"},null, (new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null)), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()))))))));
            TMP_tmp123 = (PMachineValue)(currentMachine.self);
            TMP_tmp124 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)request)?.Clone()));
            TMP_tmp125 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"source","req"}, TMP_tmp123, TMP_tmp124)));
            currentMachine.TrySendEvent(TMP_tmp121, (Event)TMP_tmp122, TMP_tmp125);
            currentMachine.TryGotoState<WaitForReply>();
            return;
        }
        public async Task Anon_2(Event currentMachine_dequeuedEvent)
        {
            ClientMachine currentMachine = this;
            PrtInt TMP_tmp0_5 = ((PrtInt)0);
            PrtInt TMP_tmp1_5 = ((PrtInt)0);
            PrtInt TMP_tmp2_5 = ((PrtInt)0);
            var PGEN_recvEvent_1 = await currentMachine.TryReceiveEvent(typeof(eConnResp), typeof(eConfResp));
            switch (PGEN_recvEvent_1) {
                case eConnResp PGEN_evt_1: {
                    PrtBool Success = (PrtBool)(PGEN_evt_1.Payload);
                    if (Success)
                    {
                        TMP_tmp0_5 = (PrtInt)(((PrtInt)0));
                        currentMachine.TryGotoState<SendReqs>(TMP_tmp0_5);
                        return;
                    }
                    else
                    {
                        TMP_tmp1_5 = (PrtInt)(((PrtInt)1));
                        currentMachine.TryGotoState<SendReqs>(TMP_tmp1_5);
                        return;
                    }
                } break;
                case eConfResp PGEN_evt_2: {
                    PrtBool Success_1 = (PrtBool)(PGEN_evt_2.Payload);
                    if (Success_1)
                    {
                        currentMachine.TryGotoState<DeadState>();
                        return;
                    }
                    else
                    {
                        TMP_tmp2_5 = (PrtInt)(((PrtInt)1));
                        currentMachine.TryGotoState<SendReqs>(TMP_tmp2_5);
                        return;
                    }
                } break;
            }
        }
        [Start]
        [OnEntry(nameof(InitializeParametersFunction))]
        [OnEventGotoState(typeof(ConstructorEvent), typeof(Init))]
        class __InitState__ : State { }
        
        [OnEntry(nameof(Anon))]
        class Init : State
        {
        }
        [OnEntry(nameof(Anon_1))]
        class SendReqs : State
        {
        }
        [OnEntry(nameof(Anon_2))]
        class WaitForReply : State
        {
        }
        [IgnoreEvents(typeof(eConfResp), typeof(eConnResp), typeof(eGetDefaultValueResp))]
        class DeadState : State
        {
        }
    }
}
namespace PImplementation
{
    internal partial class ChanMachine : PMachine
    {
        private PrtInt ConfigReqID = ((PrtInt)0);
        private PrtInt ConnectedReqID = ((PrtInt)0);
        private PMachineValue ConfigTimer = null;
        private PMachineValue ConnectedTimer = null;
        private PMachineValue InitServer_2 = null;
        private PrtInt BT_CONFIG_timeout = ((PrtInt)0);
        private PrtInt BT_CONNECTED_timeout = ((PrtInt)0);
        public class ConstructorEvent : PEvent{public ConstructorEvent(PMachineValue val) : base(val) { }}
        
        protected override Event GetConstructorEvent(IPrtValue value) { return new ConstructorEvent((PMachineValue)value); }
        public ChanMachine() {
            this.sends.Add(nameof(eChanGotoConfig));
            this.sends.Add(nameof(eChanGotoConnected));
            this.sends.Add(nameof(eComposetFix));
            this.sends.Add(nameof(eComposetHdr));
            this.sends.Add(nameof(eComposetMsg));
            this.sends.Add(nameof(eComposetPara));
            this.sends.Add(nameof(eComposetPlist));
            this.sends.Add(nameof(eComposetVar));
            this.sends.Add(nameof(eConfReq));
            this.sends.Add(nameof(eConfResp));
            this.sends.Add(nameof(eConnReq));
            this.sends.Add(nameof(eConnResp));
            this.sends.Add(nameof(eGetDefaultValueResp));
            this.sends.Add(nameof(eL2CmdReq));
            this.sends.Add(nameof(eParsetFix));
            this.sends.Add(nameof(eParsetHdr));
            this.sends.Add(nameof(eParsetMsg));
            this.sends.Add(nameof(eParsetPara));
            this.sends.Add(nameof(eParsetPlist));
            this.sends.Add(nameof(eParsetVar));
            this.sends.Add(nameof(eSpecGetDefaultValueReq));
            this.sends.Add(nameof(eStartTimer));
            this.sends.Add(nameof(eTimeOut));
            this.sends.Add(nameof(PHalt));
            this.receives.Add(nameof(eChanGotoConfig));
            this.receives.Add(nameof(eChanGotoConnected));
            this.receives.Add(nameof(eComposetFix));
            this.receives.Add(nameof(eComposetHdr));
            this.receives.Add(nameof(eComposetMsg));
            this.receives.Add(nameof(eComposetPara));
            this.receives.Add(nameof(eComposetPlist));
            this.receives.Add(nameof(eComposetVar));
            this.receives.Add(nameof(eConfReq));
            this.receives.Add(nameof(eConfResp));
            this.receives.Add(nameof(eConnReq));
            this.receives.Add(nameof(eConnResp));
            this.receives.Add(nameof(eGetDefaultValueResp));
            this.receives.Add(nameof(eL2CmdReq));
            this.receives.Add(nameof(eParsetFix));
            this.receives.Add(nameof(eParsetHdr));
            this.receives.Add(nameof(eParsetMsg));
            this.receives.Add(nameof(eParsetPara));
            this.receives.Add(nameof(eParsetPlist));
            this.receives.Add(nameof(eParsetVar));
            this.receives.Add(nameof(eSpecGetDefaultValueReq));
            this.receives.Add(nameof(eStartTimer));
            this.receives.Add(nameof(eTimeOut));
            this.receives.Add(nameof(PHalt));
            this.creates.Add(nameof(I_TimerMachine));
        }
        
        public async Task Anon_3(Event currentMachine_dequeuedEvent)
        {
            ChanMachine currentMachine = this;
            PMachineValue _InitServer = (PMachineValue)(gotoPayload ?? ((PEvent)currentMachine_dequeuedEvent).Payload);
            this.gotoPayload = null;
            PMachineValue TMP_tmp0_6 = null;
            PEvent TMP_tmp1_6 = null;
            PMachineValue TMP_tmp2_6 = null;
            IPrtValue TMP_tmp3_5 = null;
            PrtInt TMP_tmp4_5 = ((PrtInt)0);
            IPrtValue TMP_tmp5_5 = null;
            PrtInt TMP_tmp6_5 = ((PrtInt)0);
            PMachineValue TMP_tmp7_4 = null;
            PrtInt TMP_tmp8_4 = ((PrtInt)0);
            PrtNamedTuple TMP_tmp9_4 = (new PrtNamedTuple(new string[]{"_client","_timeout"},null, ((PrtInt)0)));
            PMachineValue TMP_tmp10_3 = null;
            PMachineValue TMP_tmp11_3 = null;
            PrtInt TMP_tmp12_3 = ((PrtInt)0);
            PrtNamedTuple TMP_tmp13_3 = (new PrtNamedTuple(new string[]{"_client","_timeout"},null, ((PrtInt)0)));
            PMachineValue TMP_tmp14_3 = null;
            InitServer_2 = (PMachineValue)(((PMachineValue)((IPrtValue)_InitServer)?.Clone()));
            ConfigReqID = (PrtInt)(((PrtInt)0));
            ConfigReqID = (PrtInt)(((PrtInt)0));
            TMP_tmp0_6 = (PMachineValue)(((PMachineValue)((IPrtValue)InitServer_2)?.Clone()));
            TMP_tmp1_6 = (PEvent)(new eSpecGetDefaultValueReq(null));
            TMP_tmp2_6 = (PMachineValue)(currentMachine.self);
            currentMachine.TrySendEvent(TMP_tmp0_6, (Event)TMP_tmp1_6, TMP_tmp2_6);
            var PGEN_recvEvent_2 = await currentMachine.TryReceiveEvent(typeof(eGetDefaultValueResp));
            switch (PGEN_recvEvent_2) {
                case eGetDefaultValueResp PGEN_evt_3: {
                    PrtSeq resp_1 = (PrtSeq)(PGEN_evt_3.Payload);
                    TMP_tmp3_5 = (IPrtValue)(((PrtSeq)resp_1)[((PrtInt)19)]);
                    TMP_tmp4_5 = (PrtInt)(((PrtInt)((IPrtValue)((IPrtValue)TMP_tmp3_5)?.Clone())));
                    BT_CONFIG_timeout = TMP_tmp4_5;
                    TMP_tmp5_5 = (IPrtValue)(((PrtSeq)resp_1)[((PrtInt)20)]);
                    TMP_tmp6_5 = (PrtInt)(((PrtInt)((IPrtValue)((IPrtValue)TMP_tmp5_5)?.Clone())));
                    BT_CONNECTED_timeout = TMP_tmp6_5;
                } break;
            }
            TMP_tmp7_4 = (PMachineValue)(currentMachine.self);
            TMP_tmp8_4 = (PrtInt)(((PrtInt)((IPrtValue)BT_CONFIG_timeout)?.Clone()));
            TMP_tmp9_4 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"_client","_timeout"}, TMP_tmp7_4, TMP_tmp8_4)));
            TMP_tmp10_3 = (PMachineValue)(currentMachine.CreateInterface<I_TimerMachine>( currentMachine, TMP_tmp9_4));
            ConfigTimer = (PMachineValue)TMP_tmp10_3;
            TMP_tmp11_3 = (PMachineValue)(currentMachine.self);
            TMP_tmp12_3 = (PrtInt)(((PrtInt)((IPrtValue)BT_CONNECTED_timeout)?.Clone()));
            TMP_tmp13_3 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"_client","_timeout"}, TMP_tmp11_3, TMP_tmp12_3)));
            TMP_tmp14_3 = (PMachineValue)(currentMachine.CreateInterface<I_TimerMachine>( currentMachine, TMP_tmp13_3));
            ConnectedTimer = (PMachineValue)TMP_tmp14_3;
            currentMachine.TryGotoState<BT_START>();
            return;
        }
        public void Anon_4(Event currentMachine_dequeuedEvent)
        {
            ChanMachine currentMachine = this;
            PMachineValue TMP_tmp0_7 = null;
            PEvent TMP_tmp1_7 = null;
            PrtInt TMP_tmp2_7 = ((PrtInt)0);
            TMP_tmp0_7 = (PMachineValue)(((PMachineValue)((IPrtValue)ConfigTimer)?.Clone()));
            TMP_tmp1_7 = (PEvent)(new eStartTimer(((PrtInt)0)));
            TMP_tmp2_7 = (PrtInt)(((PrtInt)0));
            currentMachine.TrySendEvent(TMP_tmp0_7, (Event)TMP_tmp1_7, TMP_tmp2_7);
            currentMachine.TryGotoState<BT_CONFIG>();
            return;
        }
        public void Anon_5(Event currentMachine_dequeuedEvent)
        {
            ChanMachine currentMachine = this;
            PMachineValue TMP_tmp0_8 = null;
            PEvent TMP_tmp1_8 = null;
            PrtInt TMP_tmp2_8 = ((PrtInt)0);
            TMP_tmp0_8 = (PMachineValue)(((PMachineValue)((IPrtValue)ConnectedTimer)?.Clone()));
            TMP_tmp1_8 = (PEvent)(new eStartTimer(((PrtInt)0)));
            TMP_tmp2_8 = (PrtInt)(((PrtInt)1));
            currentMachine.TrySendEvent(TMP_tmp0_8, (Event)TMP_tmp1_8, TMP_tmp2_8);
            currentMachine.TryGotoState<BT_CONNECTED>();
            return;
        }
        public void Anon_6(Event currentMachine_dequeuedEvent)
        {
            ChanMachine currentMachine = this;
            PrtInt stateid = (PrtInt)(gotoPayload ?? ((PEvent)currentMachine_dequeuedEvent).Payload);
            this.gotoPayload = null;
            PrtBool TMP_tmp0_9 = ((PrtBool)false);
            TMP_tmp0_9 = (PrtBool)((PrtValues.SafeEquals(stateid,((PrtInt)0))));
            if (TMP_tmp0_9)
            {
                currentMachine.TryGotoState<BT_DEAD>();
                return;
            }
        }
        public void Anon_7(Event currentMachine_dequeuedEvent)
        {
            ChanMachine currentMachine = this;
            PrtInt stateid_1 = (PrtInt)(gotoPayload ?? ((PEvent)currentMachine_dequeuedEvent).Payload);
            this.gotoPayload = null;
            PrtBool TMP_tmp0_10 = ((PrtBool)false);
            TMP_tmp0_10 = (PrtBool)((PrtValues.SafeEquals(stateid_1,((PrtInt)1))));
            if (TMP_tmp0_10)
            {
                currentMachine.TryGotoState<BT_DEAD>();
                return;
            }
        }
        [Start]
        [OnEntry(nameof(InitializeParametersFunction))]
        [OnEventGotoState(typeof(ConstructorEvent), typeof(Init_1))]
        class __InitState__ : State { }
        
        [OnEntry(nameof(Anon_3))]
        class Init_1 : State
        {
        }
        [OnEventDoAction(typeof(eChanGotoConfig), nameof(Anon_4))]
        [IgnoreEvents(typeof(eChanGotoConnected), typeof(eTimeOut))]
        class BT_START : State
        {
        }
        [OnEventDoAction(typeof(eChanGotoConnected), nameof(Anon_5))]
        [OnEventDoAction(typeof(eTimeOut), nameof(Anon_6))]
        [IgnoreEvents(typeof(eChanGotoConfig))]
        class BT_CONFIG : State
        {
        }
        [OnEventDoAction(typeof(eTimeOut), nameof(Anon_7))]
        [IgnoreEvents(typeof(eChanGotoConnected))]
        class BT_CONNECTED : State
        {
        }
        [IgnoreEvents(typeof(eChanGotoConnected), typeof(eTimeOut))]
        class BT_DEAD : State
        {
        }
    }
}
namespace PImplementation
{
    internal partial class TimerMachine : PMachine
    {
        private PMachineValue client = null;
        private PrtInt timeout = ((PrtInt)0);
        public class ConstructorEvent : PEvent{public ConstructorEvent(PrtNamedTuple val) : base(val) { }}
        
        protected override Event GetConstructorEvent(IPrtValue value) { return new ConstructorEvent((PrtNamedTuple)value); }
        public TimerMachine() {
            this.sends.Add(nameof(eChanGotoConfig));
            this.sends.Add(nameof(eChanGotoConnected));
            this.sends.Add(nameof(eComposetFix));
            this.sends.Add(nameof(eComposetHdr));
            this.sends.Add(nameof(eComposetMsg));
            this.sends.Add(nameof(eComposetPara));
            this.sends.Add(nameof(eComposetPlist));
            this.sends.Add(nameof(eComposetVar));
            this.sends.Add(nameof(eConfReq));
            this.sends.Add(nameof(eConfResp));
            this.sends.Add(nameof(eConnReq));
            this.sends.Add(nameof(eConnResp));
            this.sends.Add(nameof(eGetDefaultValueResp));
            this.sends.Add(nameof(eL2CmdReq));
            this.sends.Add(nameof(eParsetFix));
            this.sends.Add(nameof(eParsetHdr));
            this.sends.Add(nameof(eParsetMsg));
            this.sends.Add(nameof(eParsetPara));
            this.sends.Add(nameof(eParsetPlist));
            this.sends.Add(nameof(eParsetVar));
            this.sends.Add(nameof(eSpecGetDefaultValueReq));
            this.sends.Add(nameof(eStartTimer));
            this.sends.Add(nameof(eTimeOut));
            this.sends.Add(nameof(PHalt));
            this.receives.Add(nameof(eChanGotoConfig));
            this.receives.Add(nameof(eChanGotoConnected));
            this.receives.Add(nameof(eComposetFix));
            this.receives.Add(nameof(eComposetHdr));
            this.receives.Add(nameof(eComposetMsg));
            this.receives.Add(nameof(eComposetPara));
            this.receives.Add(nameof(eComposetPlist));
            this.receives.Add(nameof(eComposetVar));
            this.receives.Add(nameof(eConfReq));
            this.receives.Add(nameof(eConfResp));
            this.receives.Add(nameof(eConnReq));
            this.receives.Add(nameof(eConnResp));
            this.receives.Add(nameof(eGetDefaultValueResp));
            this.receives.Add(nameof(eL2CmdReq));
            this.receives.Add(nameof(eParsetFix));
            this.receives.Add(nameof(eParsetHdr));
            this.receives.Add(nameof(eParsetMsg));
            this.receives.Add(nameof(eParsetPara));
            this.receives.Add(nameof(eParsetPlist));
            this.receives.Add(nameof(eParsetVar));
            this.receives.Add(nameof(eSpecGetDefaultValueReq));
            this.receives.Add(nameof(eStartTimer));
            this.receives.Add(nameof(eTimeOut));
            this.receives.Add(nameof(PHalt));
        }
        
        public void Anon_8(Event currentMachine_dequeuedEvent)
        {
            TimerMachine currentMachine = this;
            PrtNamedTuple input_1 = (PrtNamedTuple)(gotoPayload ?? ((PEvent)currentMachine_dequeuedEvent).Payload);
            this.gotoPayload = null;
            PMachineValue TMP_tmp0_11 = null;
            PMachineValue TMP_tmp1_9 = null;
            PrtInt TMP_tmp2_9 = ((PrtInt)0);
            PrtInt TMP_tmp3_6 = ((PrtInt)0);
            TMP_tmp0_11 = (PMachineValue)(((PrtNamedTuple)input_1)["_client"]);
            TMP_tmp1_9 = (PMachineValue)(((PMachineValue)((IPrtValue)TMP_tmp0_11)?.Clone()));
            client = TMP_tmp1_9;
            TMP_tmp2_9 = (PrtInt)(((PrtNamedTuple)input_1)["_timeout"]);
            TMP_tmp3_6 = (PrtInt)(((PrtInt)((IPrtValue)TMP_tmp2_9)?.Clone()));
            timeout = TMP_tmp3_6;
            currentMachine.TryGotoState<WaitForTimerRequests>();
            return;
        }
        public void Anon_9(Event currentMachine_dequeuedEvent)
        {
            TimerMachine currentMachine = this;
            PrtInt stateid_2 = (PrtInt)(gotoPayload ?? ((PEvent)currentMachine_dequeuedEvent).Payload);
            this.gotoPayload = null;
            PrtInt TMP_tmp0_12 = ((PrtInt)0);
            TMP_tmp0_12 = (PrtInt)(((PrtInt)((IPrtValue)stateid_2)?.Clone()));
            currentMachine.TryGotoState<TimerStarted>(TMP_tmp0_12);
            return;
        }
        public void Anon_10(Event currentMachine_dequeuedEvent)
        {
            TimerMachine currentMachine = this;
            PrtInt stateid_3 = (PrtInt)(gotoPayload ?? ((PEvent)currentMachine_dequeuedEvent).Payload);
            this.gotoPayload = null;
            PrtInt TMP_tmp0_13 = ((PrtInt)0);
            PMachineValue TMP_tmp1_10 = null;
            PEvent TMP_tmp2_10 = null;
            PrtInt TMP_tmp3_7 = ((PrtInt)0);
            TMP_tmp0_13 = (PrtInt)(((PrtInt)((IPrtValue)timeout)?.Clone()));
            GlobalFunctions.sleepFor(TMP_tmp0_13, currentMachine);
            TMP_tmp1_10 = (PMachineValue)(((PMachineValue)((IPrtValue)client)?.Clone()));
            TMP_tmp2_10 = (PEvent)(new eTimeOut(((PrtInt)0)));
            TMP_tmp3_7 = (PrtInt)(((PrtInt)((IPrtValue)stateid_3)?.Clone()));
            currentMachine.TrySendEvent(TMP_tmp1_10, (Event)TMP_tmp2_10, TMP_tmp3_7);
            currentMachine.TryGotoState<WaitForTimerRequests>();
            return;
        }
        [Start]
        [OnEntry(nameof(InitializeParametersFunction))]
        [OnEventGotoState(typeof(ConstructorEvent), typeof(Init_2))]
        class __InitState__ : State { }
        
        [OnEntry(nameof(Anon_8))]
        class Init_2 : State
        {
        }
        [OnEventDoAction(typeof(eStartTimer), nameof(Anon_9))]
        class WaitForTimerRequests : State
        {
        }
        [OnEntry(nameof(Anon_10))]
        [IgnoreEvents(typeof(eStartTimer))]
        class TimerStarted : State
        {
        }
    }
}
namespace PImplementation
{
    internal partial class ConnMachine : PMachine
    {
        private PMachineValue server = null;
        private PrtSeq Connection = new PrtSeq();
        private PrtMap ChanMachineList = new PrtMap();
        public class ConstructorEvent : PEvent{public ConstructorEvent(PrtNamedTuple val) : base(val) { }}
        
        protected override Event GetConstructorEvent(IPrtValue value) { return new ConstructorEvent((PrtNamedTuple)value); }
        public ConnMachine() {
            this.sends.Add(nameof(eChanGotoConfig));
            this.sends.Add(nameof(eChanGotoConnected));
            this.sends.Add(nameof(eComposetFix));
            this.sends.Add(nameof(eComposetHdr));
            this.sends.Add(nameof(eComposetMsg));
            this.sends.Add(nameof(eComposetPara));
            this.sends.Add(nameof(eComposetPlist));
            this.sends.Add(nameof(eComposetVar));
            this.sends.Add(nameof(eConfReq));
            this.sends.Add(nameof(eConfResp));
            this.sends.Add(nameof(eConnReq));
            this.sends.Add(nameof(eConnResp));
            this.sends.Add(nameof(eGetDefaultValueResp));
            this.sends.Add(nameof(eL2CmdReq));
            this.sends.Add(nameof(eParsetFix));
            this.sends.Add(nameof(eParsetHdr));
            this.sends.Add(nameof(eParsetMsg));
            this.sends.Add(nameof(eParsetPara));
            this.sends.Add(nameof(eParsetPlist));
            this.sends.Add(nameof(eParsetVar));
            this.sends.Add(nameof(eSpecGetDefaultValueReq));
            this.sends.Add(nameof(eStartTimer));
            this.sends.Add(nameof(eTimeOut));
            this.sends.Add(nameof(PHalt));
            this.receives.Add(nameof(eChanGotoConfig));
            this.receives.Add(nameof(eChanGotoConnected));
            this.receives.Add(nameof(eComposetFix));
            this.receives.Add(nameof(eComposetHdr));
            this.receives.Add(nameof(eComposetMsg));
            this.receives.Add(nameof(eComposetPara));
            this.receives.Add(nameof(eComposetPlist));
            this.receives.Add(nameof(eComposetVar));
            this.receives.Add(nameof(eConfReq));
            this.receives.Add(nameof(eConfResp));
            this.receives.Add(nameof(eConnReq));
            this.receives.Add(nameof(eConnResp));
            this.receives.Add(nameof(eGetDefaultValueResp));
            this.receives.Add(nameof(eL2CmdReq));
            this.receives.Add(nameof(eParsetFix));
            this.receives.Add(nameof(eParsetHdr));
            this.receives.Add(nameof(eParsetMsg));
            this.receives.Add(nameof(eParsetPara));
            this.receives.Add(nameof(eParsetPlist));
            this.receives.Add(nameof(eParsetVar));
            this.receives.Add(nameof(eSpecGetDefaultValueReq));
            this.receives.Add(nameof(eStartTimer));
            this.receives.Add(nameof(eTimeOut));
            this.receives.Add(nameof(PHalt));
            this.creates.Add(nameof(I_ChanMachine));
        }
        
        public void Anon_11(Event currentMachine_dequeuedEvent)
        {
            ConnMachine currentMachine = this;
            PrtNamedTuple input_2 = (PrtNamedTuple)(gotoPayload ?? ((PEvent)currentMachine_dequeuedEvent).Payload);
            this.gotoPayload = null;
            PMachineValue TMP_tmp0_14 = null;
            PMachineValue TMP_tmp1_11 = null;
            PrtSeq TMP_tmp2_11 = new PrtSeq();
            PrtSeq TMP_tmp3_8 = new PrtSeq();
            TMP_tmp0_14 = (PMachineValue)(((PrtNamedTuple)input_2)["serv"]);
            TMP_tmp1_11 = (PMachineValue)(((PMachineValue)((IPrtValue)TMP_tmp0_14)?.Clone()));
            server = TMP_tmp1_11;
            TMP_tmp2_11 = (PrtSeq)(((PrtNamedTuple)input_2)["conn"]);
            TMP_tmp3_8 = (PrtSeq)(((PrtSeq)((IPrtValue)TMP_tmp2_11)?.Clone()));
            Connection = TMP_tmp3_8;
            currentMachine.TryGotoState<WaitForReqs>();
            return;
        }
        public void Anon_12(Event currentMachine_dequeuedEvent)
        {
            ConnMachine currentMachine = this;
            PrtNamedTuple wReq = (PrtNamedTuple)(gotoPayload ?? ((PEvent)currentMachine_dequeuedEvent).Payload);
            this.gotoPayload = null;
            PrtNamedTuple MsgBody = (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()));
            PrtNamedTuple MsgHdr = (new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PrtSeq MsgCases = new PrtSeq();
            PrtInt MsgType = ((PrtInt)0);
            PrtInt counter_3 = ((PrtInt)0);
            PrtNamedTuple TMP_tmp0_15 = (new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null)), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()))));
            PrtNamedTuple TMP_tmp1_12 = (new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null)), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()))));
            PrtNamedTuple TMP_tmp2_12 = (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()));
            PrtNamedTuple TMP_tmp3_9 = (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()));
            PrtNamedTuple TMP_tmp4_6 = (new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PrtNamedTuple TMP_tmp5_6 = (new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PrtSeq TMP_tmp6_6 = new PrtSeq();
            PrtSeq TMP_tmp7_5 = new PrtSeq();
            PrtSeq TMP_tmp8_5 = new PrtSeq();
            PrtNamedTuple TMP_tmp9_5 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtSeq TMP_tmp10_4 = new PrtSeq();
            PrtInt TMP_tmp11_4 = ((PrtInt)0);
            PrtInt TMP_tmp12_4 = ((PrtInt)0);
            PrtBool TMP_tmp13_4 = ((PrtBool)false);
            PrtBool TMP_tmp14_4 = ((PrtBool)false);
            PrtNamedTuple TMP_tmp15_2 = (new PrtNamedTuple(new string[]{"nType","msub"},((PrtInt)0), null));
            PrtInt TMP_tmp16_2 = ((PrtInt)0);
            PrtBool TMP_tmp17_2 = ((PrtBool)false);
            PMachineValue TMP_tmp18_2 = null;
            PEvent TMP_tmp19_2 = null;
            PMachineValue TMP_tmp20_2 = null;
            PrtNamedTuple TMP_tmp21_2 = (new PrtNamedTuple(new string[]{"nType","msub"},((PrtInt)0), null));
            IPrtValue TMP_tmp22_2 = null;
            PrtNamedTuple TMP_tmp23_2 = (new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null)), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()))));
            PrtNamedTuple TMP_tmp24_2 = (new PrtNamedTuple(new string[]{"source","req"},null, (new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null)), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()))))));
            TMP_tmp0_15 = (PrtNamedTuple)(((PrtNamedTuple)wReq)["req"]);
            currentMachine.Announce((Event)new eParsetMsg((new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null)), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()))))), TMP_tmp0_15);
            TMP_tmp1_12 = (PrtNamedTuple)(((PrtNamedTuple)wReq)["req"]);
            TMP_tmp2_12 = (PrtNamedTuple)(((PrtNamedTuple)TMP_tmp1_12)["hcmsub"]);
            TMP_tmp3_9 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)TMP_tmp2_12)?.Clone()));
            MsgBody = TMP_tmp3_9;
            TMP_tmp4_6 = (PrtNamedTuple)(((PrtNamedTuple)MsgBody)["h"]);
            TMP_tmp5_6 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)TMP_tmp4_6)?.Clone()));
            MsgHdr = TMP_tmp5_6;
            TMP_tmp6_6 = (PrtSeq)(((PrtNamedTuple)MsgBody)["msub"]);
            TMP_tmp7_5 = (PrtSeq)(((PrtSeq)((IPrtValue)TMP_tmp6_6)?.Clone()));
            MsgCases = TMP_tmp7_5;
            TMP_tmp8_5 = (PrtSeq)(((PrtNamedTuple)MsgHdr)["f"]);
            TMP_tmp9_5 = (PrtNamedTuple)(((PrtSeq)TMP_tmp8_5)[((PrtInt)0)]);
            TMP_tmp10_4 = (PrtSeq)(((PrtNamedTuple)TMP_tmp9_5)["value"]);
            TMP_tmp11_4 = (PrtInt)(GlobalFunctions.readBuffer(TMP_tmp10_4, currentMachine));
            MsgType = TMP_tmp11_4;
            counter_3 = (PrtInt)(((PrtInt)0));
            while (((PrtBool)true))
            {
                TMP_tmp12_4 = (PrtInt)(((PrtInt)(MsgCases).Count));
                TMP_tmp13_4 = (PrtBool)((counter_3) < (TMP_tmp12_4));
                TMP_tmp14_4 = (PrtBool)(((PrtBool)((IPrtValue)TMP_tmp13_4)?.Clone()));
                if (TMP_tmp14_4)
                {
                }
                else
                {
                    break;
                }
                TMP_tmp15_2 = (PrtNamedTuple)(((PrtSeq)MsgCases)[counter_3]);
                TMP_tmp16_2 = (PrtInt)(((PrtNamedTuple)TMP_tmp15_2)["nType"]);
                TMP_tmp17_2 = (PrtBool)((PrtValues.SafeEquals(MsgType,TMP_tmp16_2)));
                if (TMP_tmp17_2)
                {
                    TMP_tmp18_2 = (PMachineValue)(currentMachine.self);
                    TMP_tmp19_2 = (PEvent)(new eConnReq((new PrtNamedTuple(new string[]{"source","req"},null, (new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null)), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()))))))));
                    TMP_tmp20_2 = (PMachineValue)(((PrtNamedTuple)wReq)["source"]);
                    TMP_tmp21_2 = (PrtNamedTuple)(((PrtSeq)MsgCases)[counter_3]);
                    TMP_tmp22_2 = (IPrtValue)(((PrtNamedTuple)TMP_tmp21_2)["msub"]);
                    TMP_tmp23_2 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)((IPrtValue)TMP_tmp22_2)?.Clone())));
                    TMP_tmp24_2 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"source","req"}, TMP_tmp20_2, TMP_tmp23_2)));
                    currentMachine.TrySendEvent(TMP_tmp18_2, (Event)TMP_tmp19_2, TMP_tmp24_2);
                }
            }
        }
        public void Anon_13(Event currentMachine_dequeuedEvent)
        {
            ConnMachine currentMachine = this;
            PrtNamedTuple wReq_1 = (PrtNamedTuple)(gotoPayload ?? ((PEvent)currentMachine_dequeuedEvent).Payload);
            this.gotoPayload = null;
            PrtInt counter2_1 = ((PrtInt)0);
            PrtBool flag1 = ((PrtBool)false);
            PrtBool flag2 = ((PrtBool)false);
            PrtInt index = ((PrtInt)0);
            PrtInt counter3 = ((PrtInt)0);
            PrtNamedTuple tmp1_1 = (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PrtNamedTuple tmp2_1 = (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PrtSeq tmp3 = new PrtSeq();
            PrtNamedTuple TMP_tmp0_16 = (new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null)), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()))));
            PrtInt TMP_tmp1_13 = ((PrtInt)0);
            PrtBool TMP_tmp2_13 = ((PrtBool)false);
            PrtBool TMP_tmp3_10 = ((PrtBool)false);
            PrtSeq TMP_tmp4_7 = new PrtSeq();
            PrtInt TMP_tmp5_7 = ((PrtInt)0);
            PrtBool TMP_tmp6_7 = ((PrtBool)false);
            PrtBool TMP_tmp7_6 = ((PrtBool)false);
            PrtSeq TMP_tmp8_6 = new PrtSeq();
            PrtNamedTuple TMP_tmp9_6 = (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PrtInt TMP_tmp10_5 = ((PrtInt)0);
            PrtBool TMP_tmp11_5 = ((PrtBool)false);
            PrtSeq TMP_tmp12_5 = new PrtSeq();
            PrtNamedTuple TMP_tmp13_5 = (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PrtNamedTuple TMP_tmp14_5 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtSeq TMP_tmp15_3 = new PrtSeq();
            PrtInt TMP_tmp16_3 = ((PrtInt)0);
            PrtBool TMP_tmp17_3 = ((PrtBool)false);
            PrtBool TMP_tmp18_3 = ((PrtBool)false);
            PrtNamedTuple TMP_tmp19_3 = (new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null)), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()))));
            PrtSeq TMP_tmp20_3 = new PrtSeq();
            PrtNamedTuple TMP_tmp21_3 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtSeq TMP_tmp22_3 = new PrtSeq();
            PrtInt TMP_tmp23_3 = ((PrtInt)0);
            PrtSeq TMP_tmp24_3 = new PrtSeq();
            PrtNamedTuple TMP_tmp25_2 = (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PrtNamedTuple TMP_tmp26_2 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtSeq TMP_tmp27_2 = new PrtSeq();
            PrtInt TMP_tmp28_2 = ((PrtInt)0);
            PrtBool TMP_tmp29_2 = ((PrtBool)false);
            PrtBool TMP_tmp30_1 = ((PrtBool)false);
            PrtSeq TMP_tmp31_1 = new PrtSeq();
            PrtNamedTuple TMP_tmp32_1 = (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PrtInt TMP_tmp33_1 = ((PrtInt)0);
            PrtBool TMP_tmp34_1 = ((PrtBool)false);
            PrtSeq TMP_tmp35_1 = new PrtSeq();
            PrtNamedTuple TMP_tmp36_1 = (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PrtNamedTuple TMP_tmp37_1 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtSeq TMP_tmp38_1 = new PrtSeq();
            PrtInt TMP_tmp39_1 = ((PrtInt)0);
            PrtBool TMP_tmp40_1 = ((PrtBool)false);
            PrtBool TMP_tmp41_1 = ((PrtBool)false);
            PrtNamedTuple TMP_tmp42_1 = (new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null)), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()))));
            PrtSeq TMP_tmp43_1 = new PrtSeq();
            PrtNamedTuple TMP_tmp44_1 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtSeq TMP_tmp45_1 = new PrtSeq();
            PrtInt TMP_tmp46_1 = ((PrtInt)0);
            PrtSeq TMP_tmp47_1 = new PrtSeq();
            PrtNamedTuple TMP_tmp48_1 = (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PrtNamedTuple TMP_tmp49_1 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtSeq TMP_tmp50_1 = new PrtSeq();
            PrtInt TMP_tmp51_1 = ((PrtInt)0);
            PrtBool TMP_tmp52_1 = ((PrtBool)false);
            PrtBool TMP_tmp53_1 = ((PrtBool)false);
            PrtInt TMP_tmp54_1 = ((PrtInt)0);
            PrtInt TMP_tmp55_1 = ((PrtInt)0);
            PrtBool TMP_tmp56_1 = ((PrtBool)false);
            PrtBool TMP_tmp57_1 = ((PrtBool)false);
            PrtBool TMP_tmp58_1 = ((PrtBool)false);
            PrtInt TMP_tmp59_1 = ((PrtInt)0);
            PrtInt TMP_tmp60_1 = ((PrtInt)0);
            PrtSeq TMP_tmp61_1 = new PrtSeq();
            PrtNamedTuple TMP_tmp62_1 = (new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null)), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()))));
            PrtSeq TMP_tmp63_1 = new PrtSeq();
            PrtNamedTuple TMP_tmp64_1 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtNamedTuple TMP_tmp65_1 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtInt TMP_tmp66_1 = ((PrtInt)0);
            PrtInt TMP_tmp67_1 = ((PrtInt)0);
            PrtSeq TMP_tmp68_1 = new PrtSeq();
            PrtNamedTuple TMP_tmp69_1 = (new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null)), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()))));
            PrtSeq TMP_tmp70_1 = new PrtSeq();
            PrtNamedTuple TMP_tmp71_1 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtNamedTuple TMP_tmp72_1 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtNamedTuple TMP_tmp73_1 = (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PrtNamedTuple TMP_tmp74_1 = (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PrtInt TMP_tmp75_1 = ((PrtInt)0);
            PrtInt TMP_tmp76_1 = ((PrtInt)0);
            PrtSeq TMP_tmp77_1 = new PrtSeq();
            PrtInt TMP_tmp78_1 = ((PrtInt)0);
            PMachineValue TMP_tmp79_1 = null;
            PMachineValue TMP_tmp80_1 = null;
            PrtInt TMP_tmp81_1 = ((PrtInt)0);
            PMachineValue TMP_tmp82_1 = null;
            PMachineValue TMP_tmp83_1 = null;
            PEvent TMP_tmp84_1 = null;
            PMachineValue TMP_tmp85_1 = null;
            PMachineValue TMP_tmp86_1 = null;
            PEvent TMP_tmp87_1 = null;
            PrtBool TMP_tmp88_1 = ((PrtBool)false);
            PMachineValue TMP_tmp89_1 = null;
            PMachineValue TMP_tmp90_1 = null;
            PEvent TMP_tmp91_1 = null;
            PrtBool TMP_tmp92_1 = ((PrtBool)false);
            TMP_tmp0_16 = (PrtNamedTuple)(((PrtNamedTuple)wReq_1)["req"]);
            currentMachine.Announce((Event)new eParsetMsg((new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null)), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()))))), TMP_tmp0_16);
            counter2_1 = (PrtInt)(((PrtInt)0));
            flag1 = (PrtBool)(((PrtBool)false));
            flag2 = (PrtBool)(((PrtBool)false));
            while (((PrtBool)true))
            {
                TMP_tmp1_13 = (PrtInt)(((PrtInt)(Connection).Count));
                TMP_tmp2_13 = (PrtBool)((!PrtValues.SafeEquals(counter2_1,TMP_tmp1_13)));
                TMP_tmp3_10 = (PrtBool)(((PrtBool)((IPrtValue)TMP_tmp2_13)?.Clone()));
                if (TMP_tmp3_10)
                {
                }
                else
                {
                    break;
                }
                counter3 = (PrtInt)(((PrtInt)0));
                while (((PrtBool)true))
                {
                    TMP_tmp4_7 = (PrtSeq)(((PrtSeq)Connection)[counter2_1]);
                    TMP_tmp5_7 = (PrtInt)(((PrtInt)(TMP_tmp4_7).Count));
                    TMP_tmp6_7 = (PrtBool)((!PrtValues.SafeEquals(counter3,TMP_tmp5_7)));
                    TMP_tmp7_6 = (PrtBool)(((PrtBool)((IPrtValue)TMP_tmp6_7)?.Clone()));
                    if (TMP_tmp7_6)
                    {
                    }
                    else
                    {
                        break;
                    }
                    TMP_tmp8_6 = (PrtSeq)(((PrtSeq)Connection)[counter2_1]);
                    TMP_tmp9_6 = (PrtNamedTuple)(((PrtSeq)TMP_tmp8_6)[counter3]);
                    TMP_tmp10_5 = (PrtInt)(((PrtNamedTuple)TMP_tmp9_6)["nKey"]);
                    TMP_tmp11_5 = (PrtBool)((PrtValues.SafeEquals(TMP_tmp10_5,((PrtInt)2))));
                    TMP_tmp18_3 = (PrtBool)(((PrtBool)((IPrtValue)TMP_tmp11_5)?.Clone()));
                    if (TMP_tmp18_3)
                    {
                        TMP_tmp12_5 = (PrtSeq)(((PrtSeq)Connection)[counter2_1]);
                        TMP_tmp13_5 = (PrtNamedTuple)(((PrtSeq)TMP_tmp12_5)[counter3]);
                        TMP_tmp14_5 = (PrtNamedTuple)(((PrtNamedTuple)TMP_tmp13_5)["fKey"]);
                        TMP_tmp15_3 = (PrtSeq)(((PrtNamedTuple)TMP_tmp14_5)["value"]);
                        TMP_tmp16_3 = (PrtInt)(GlobalFunctions.readBuffer(TMP_tmp15_3, currentMachine));
                        TMP_tmp17_3 = (PrtBool)((PrtValues.SafeEquals(TMP_tmp16_3,((PrtInt)2))));
                        TMP_tmp18_3 = (PrtBool)(((PrtBool)((IPrtValue)TMP_tmp17_3)?.Clone()));
                    }
                    TMP_tmp30_1 = (PrtBool)(((PrtBool)((IPrtValue)TMP_tmp18_3)?.Clone()));
                    if (TMP_tmp30_1)
                    {
                        TMP_tmp19_3 = (PrtNamedTuple)(((PrtNamedTuple)wReq_1)["req"]);
                        TMP_tmp20_3 = (PrtSeq)(((PrtNamedTuple)TMP_tmp19_3)["fp"]);
                        TMP_tmp21_3 = (PrtNamedTuple)(((PrtSeq)TMP_tmp20_3)[((PrtInt)0)]);
                        TMP_tmp22_3 = (PrtSeq)(((PrtNamedTuple)TMP_tmp21_3)["value"]);
                        TMP_tmp23_3 = (PrtInt)(GlobalFunctions.readBuffer(TMP_tmp22_3, currentMachine));
                        TMP_tmp24_3 = (PrtSeq)(((PrtSeq)Connection)[counter2_1]);
                        TMP_tmp25_2 = (PrtNamedTuple)(((PrtSeq)TMP_tmp24_3)[counter3]);
                        TMP_tmp26_2 = (PrtNamedTuple)(((PrtNamedTuple)TMP_tmp25_2)["fVal"]);
                        TMP_tmp27_2 = (PrtSeq)(((PrtNamedTuple)TMP_tmp26_2)["value"]);
                        TMP_tmp28_2 = (PrtInt)(GlobalFunctions.readBuffer(TMP_tmp27_2, currentMachine));
                        TMP_tmp29_2 = (PrtBool)((PrtValues.SafeEquals(TMP_tmp23_3,TMP_tmp28_2)));
                        TMP_tmp30_1 = (PrtBool)(((PrtBool)((IPrtValue)TMP_tmp29_2)?.Clone()));
                    }
                    if (TMP_tmp30_1)
                    {
                        flag1 = (PrtBool)(((PrtBool)true));
                    }
                    TMP_tmp31_1 = (PrtSeq)(((PrtSeq)Connection)[counter2_1]);
                    TMP_tmp32_1 = (PrtNamedTuple)(((PrtSeq)TMP_tmp31_1)[counter3]);
                    TMP_tmp33_1 = (PrtInt)(((PrtNamedTuple)TMP_tmp32_1)["nKey"]);
                    TMP_tmp34_1 = (PrtBool)((PrtValues.SafeEquals(TMP_tmp33_1,((PrtInt)1))));
                    TMP_tmp41_1 = (PrtBool)(((PrtBool)((IPrtValue)TMP_tmp34_1)?.Clone()));
                    if (TMP_tmp41_1)
                    {
                        TMP_tmp35_1 = (PrtSeq)(((PrtSeq)Connection)[counter2_1]);
                        TMP_tmp36_1 = (PrtNamedTuple)(((PrtSeq)TMP_tmp35_1)[counter3]);
                        TMP_tmp37_1 = (PrtNamedTuple)(((PrtNamedTuple)TMP_tmp36_1)["fKey"]);
                        TMP_tmp38_1 = (PrtSeq)(((PrtNamedTuple)TMP_tmp37_1)["value"]);
                        TMP_tmp39_1 = (PrtInt)(GlobalFunctions.readBuffer(TMP_tmp38_1, currentMachine));
                        TMP_tmp40_1 = (PrtBool)((PrtValues.SafeEquals(TMP_tmp39_1,((PrtInt)1))));
                        TMP_tmp41_1 = (PrtBool)(((PrtBool)((IPrtValue)TMP_tmp40_1)?.Clone()));
                    }
                    TMP_tmp53_1 = (PrtBool)(((PrtBool)((IPrtValue)TMP_tmp41_1)?.Clone()));
                    if (TMP_tmp53_1)
                    {
                        TMP_tmp42_1 = (PrtNamedTuple)(((PrtNamedTuple)wReq_1)["req"]);
                        TMP_tmp43_1 = (PrtSeq)(((PrtNamedTuple)TMP_tmp42_1)["fp"]);
                        TMP_tmp44_1 = (PrtNamedTuple)(((PrtSeq)TMP_tmp43_1)[((PrtInt)1)]);
                        TMP_tmp45_1 = (PrtSeq)(((PrtNamedTuple)TMP_tmp44_1)["value"]);
                        TMP_tmp46_1 = (PrtInt)(GlobalFunctions.readBuffer(TMP_tmp45_1, currentMachine));
                        TMP_tmp47_1 = (PrtSeq)(((PrtSeq)Connection)[counter2_1]);
                        TMP_tmp48_1 = (PrtNamedTuple)(((PrtSeq)TMP_tmp47_1)[counter3]);
                        TMP_tmp49_1 = (PrtNamedTuple)(((PrtNamedTuple)TMP_tmp48_1)["fVal"]);
                        TMP_tmp50_1 = (PrtSeq)(((PrtNamedTuple)TMP_tmp49_1)["value"]);
                        TMP_tmp51_1 = (PrtInt)(GlobalFunctions.readBuffer(TMP_tmp50_1, currentMachine));
                        TMP_tmp52_1 = (PrtBool)((PrtValues.SafeEquals(TMP_tmp46_1,TMP_tmp51_1)));
                        TMP_tmp53_1 = (PrtBool)(((PrtBool)((IPrtValue)TMP_tmp52_1)?.Clone()));
                    }
                    if (TMP_tmp53_1)
                    {
                        flag2 = (PrtBool)(((PrtBool)true));
                    }
                    TMP_tmp54_1 = (PrtInt)((counter3) + (((PrtInt)1)));
                    counter3 = TMP_tmp54_1;
                }
                TMP_tmp55_1 = (PrtInt)((counter2_1) + (((PrtInt)1)));
                counter2_1 = TMP_tmp55_1;
            }
            TMP_tmp56_1 = (PrtBool)((PrtValues.SafeEquals(flag1,((PrtBool)true))));
            TMP_tmp58_1 = (PrtBool)(((PrtBool)((IPrtValue)TMP_tmp56_1)?.Clone()));
            if (TMP_tmp58_1)
            {
                TMP_tmp57_1 = (PrtBool)((PrtValues.SafeEquals(flag2,((PrtBool)false))));
                TMP_tmp58_1 = (PrtBool)(((PrtBool)((IPrtValue)TMP_tmp57_1)?.Clone()));
            }
            if (TMP_tmp58_1)
            {
                ((PrtNamedTuple)tmp1_1)["nKey"] = (PrtInt)(((PrtInt)2));
                TMP_tmp59_1 = (PrtInt)(((PrtInt)2));
                TMP_tmp60_1 = (PrtInt)(((PrtInt)1));
                TMP_tmp61_1 = (PrtSeq)(GlobalFunctions.writeBuffer(TMP_tmp59_1, TMP_tmp60_1, currentMachine));
                ((PrtNamedTuple)((PrtNamedTuple)tmp1_1)["fKey"])["value"] = TMP_tmp61_1;
                TMP_tmp62_1 = (PrtNamedTuple)(((PrtNamedTuple)wReq_1)["req"]);
                TMP_tmp63_1 = (PrtSeq)(((PrtNamedTuple)TMP_tmp62_1)["fp"]);
                TMP_tmp64_1 = (PrtNamedTuple)(((PrtSeq)TMP_tmp63_1)[((PrtInt)0)]);
                TMP_tmp65_1 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)TMP_tmp64_1)?.Clone()));
                ((PrtNamedTuple)tmp1_1)["fVal"] = TMP_tmp65_1;
                ((PrtNamedTuple)tmp2_1)["nKey"] = (PrtInt)(((PrtInt)1));
                TMP_tmp66_1 = (PrtInt)(((PrtInt)1));
                TMP_tmp67_1 = (PrtInt)(((PrtInt)1));
                TMP_tmp68_1 = (PrtSeq)(GlobalFunctions.writeBuffer(TMP_tmp66_1, TMP_tmp67_1, currentMachine));
                ((PrtNamedTuple)((PrtNamedTuple)tmp2_1)["fKey"])["value"] = TMP_tmp68_1;
                TMP_tmp69_1 = (PrtNamedTuple)(((PrtNamedTuple)wReq_1)["req"]);
                TMP_tmp70_1 = (PrtSeq)(((PrtNamedTuple)TMP_tmp69_1)["fp"]);
                TMP_tmp71_1 = (PrtNamedTuple)(((PrtSeq)TMP_tmp70_1)[((PrtInt)1)]);
                TMP_tmp72_1 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)TMP_tmp71_1)?.Clone()));
                ((PrtNamedTuple)tmp2_1)["fVal"] = TMP_tmp72_1;
                TMP_tmp73_1 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)tmp2_1)?.Clone()));
                ((PrtSeq)tmp3).Insert(((PrtInt)0), TMP_tmp73_1);
                TMP_tmp74_1 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)tmp1_1)?.Clone()));
                ((PrtSeq)tmp3).Insert(((PrtInt)1), TMP_tmp74_1);
                TMP_tmp75_1 = (PrtInt)(((PrtInt)(Connection).Count));
                TMP_tmp76_1 = (PrtInt)((TMP_tmp75_1) - (((PrtInt)1)));
                TMP_tmp77_1 = (PrtSeq)(((PrtSeq)((IPrtValue)tmp3)?.Clone()));
                ((PrtSeq)Connection).Insert(TMP_tmp76_1, TMP_tmp77_1);
                TMP_tmp78_1 = (PrtInt)(((PrtInt)(Connection).Count));
                TMP_tmp79_1 = (PMachineValue)(((PMachineValue)((IPrtValue)server)?.Clone()));
                TMP_tmp80_1 = (PMachineValue)(currentMachine.CreateInterface<I_ChanMachine>( currentMachine, TMP_tmp79_1));
                ((PrtMap)ChanMachineList)[TMP_tmp78_1] = TMP_tmp80_1;
                TMP_tmp81_1 = (PrtInt)(((PrtInt)(Connection).Count));
                TMP_tmp82_1 = (PMachineValue)(((PrtMap)ChanMachineList)[TMP_tmp81_1]);
                TMP_tmp83_1 = (PMachineValue)(((PMachineValue)((IPrtValue)TMP_tmp82_1)?.Clone()));
                TMP_tmp84_1 = (PEvent)(new eChanGotoConnected(null));
                currentMachine.TrySendEvent(TMP_tmp83_1, (Event)TMP_tmp84_1);
                TMP_tmp85_1 = (PMachineValue)(((PrtNamedTuple)wReq_1)["source"]);
                TMP_tmp86_1 = (PMachineValue)(((PMachineValue)((IPrtValue)TMP_tmp85_1)?.Clone()));
                TMP_tmp87_1 = (PEvent)(new eConnResp(((PrtBool)false)));
                TMP_tmp88_1 = (PrtBool)(((PrtBool)true));
                currentMachine.TrySendEvent(TMP_tmp86_1, (Event)TMP_tmp87_1, TMP_tmp88_1);
                return ;
            }
            TMP_tmp89_1 = (PMachineValue)(((PrtNamedTuple)wReq_1)["source"]);
            TMP_tmp90_1 = (PMachineValue)(((PMachineValue)((IPrtValue)TMP_tmp89_1)?.Clone()));
            TMP_tmp91_1 = (PEvent)(new eConnResp(((PrtBool)false)));
            TMP_tmp92_1 = (PrtBool)(((PrtBool)false));
            currentMachine.TrySendEvent(TMP_tmp90_1, (Event)TMP_tmp91_1, TMP_tmp92_1);
        }
        public void Anon_14(Event currentMachine_dequeuedEvent)
        {
            ConnMachine currentMachine = this;
            PrtNamedTuple wReq_2 = (PrtNamedTuple)(gotoPayload ?? ((PEvent)currentMachine_dequeuedEvent).Payload);
            this.gotoPayload = null;
            PrtNamedTuple hm = (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null));
            PrtNamedTuple msub = (new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null)), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()))));
            PrtNamedTuple srcChanID = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtNamedTuple optPlist = (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq()));
            PrtNamedTuple mtuPara = (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PrtInt counter2_2 = ((PrtInt)0);
            PrtBool flag1_1 = ((PrtBool)false);
            PrtInt index_1 = ((PrtInt)0);
            PrtInt counter3_1 = ((PrtInt)0);
            PrtSeq targetChan = new PrtSeq();
            PMachineValue targetChanM = null;
            PrtNamedTuple TMP_tmp0_17 = (new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null)), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()))));
            PrtNamedTuple TMP_tmp1_14 = (new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null)), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()))));
            PrtNamedTuple TMP_tmp2_14 = (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null));
            PrtNamedTuple TMP_tmp3_11 = (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null));
            PrtNamedTuple TMP_tmp4_8 = (new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PrtSeq TMP_tmp5_8 = new PrtSeq();
            PrtNamedTuple TMP_tmp6_8 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtNamedTuple TMP_tmp7_7 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            IPrtValue TMP_tmp8_7 = null;
            PrtNamedTuple TMP_tmp9_7 = (new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null)), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()))));
            PrtNamedTuple TMP_tmp10_6 = (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq()));
            PrtNamedTuple TMP_tmp11_6 = (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq()));
            PrtSeq TMP_tmp12_6 = new PrtSeq();
            PrtNamedTuple TMP_tmp13_6 = (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PrtNamedTuple TMP_tmp14_6 = (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PrtInt TMP_tmp15_4 = ((PrtInt)0);
            PrtBool TMP_tmp16_4 = ((PrtBool)false);
            PrtBool TMP_tmp17_4 = ((PrtBool)false);
            PrtSeq TMP_tmp18_4 = new PrtSeq();
            PrtInt TMP_tmp19_4 = ((PrtInt)0);
            PrtBool TMP_tmp20_4 = ((PrtBool)false);
            PrtBool TMP_tmp21_4 = ((PrtBool)false);
            PrtSeq TMP_tmp22_4 = new PrtSeq();
            PrtNamedTuple TMP_tmp23_4 = (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PrtInt TMP_tmp24_4 = ((PrtInt)0);
            PrtBool TMP_tmp25_3 = ((PrtBool)false);
            PrtSeq TMP_tmp26_3 = new PrtSeq();
            PrtNamedTuple TMP_tmp27_3 = (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PrtNamedTuple TMP_tmp28_3 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtSeq TMP_tmp29_3 = new PrtSeq();
            PrtInt TMP_tmp30_2 = ((PrtInt)0);
            PrtBool TMP_tmp31_2 = ((PrtBool)false);
            PrtBool TMP_tmp32_2 = ((PrtBool)false);
            PrtSeq TMP_tmp33_2 = new PrtSeq();
            PrtInt TMP_tmp34_2 = ((PrtInt)0);
            PrtSeq TMP_tmp35_2 = new PrtSeq();
            PrtNamedTuple TMP_tmp36_2 = (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PrtNamedTuple TMP_tmp37_2 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtSeq TMP_tmp38_2 = new PrtSeq();
            PrtInt TMP_tmp39_2 = ((PrtInt)0);
            PrtBool TMP_tmp40_2 = ((PrtBool)false);
            PrtBool TMP_tmp41_2 = ((PrtBool)false);
            PrtInt TMP_tmp42_2 = ((PrtInt)0);
            PrtInt TMP_tmp43_2 = ((PrtInt)0);
            PrtInt TMP_tmp44_2 = ((PrtInt)0);
            PrtBool TMP_tmp45_2 = ((PrtBool)false);
            PrtInt TMP_tmp46_2 = ((PrtInt)0);
            PrtSeq TMP_tmp47_2 = new PrtSeq();
            PrtSeq TMP_tmp48_2 = new PrtSeq();
            PrtInt TMP_tmp49_2 = ((PrtInt)0);
            PrtInt TMP_tmp50_2 = ((PrtInt)0);
            PrtNamedTuple TMP_tmp51_2 = (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PMachineValue TMP_tmp52_2 = null;
            PMachineValue TMP_tmp53_2 = null;
            PMachineValue TMP_tmp54_2 = null;
            PEvent TMP_tmp55_2 = null;
            PMachineValue TMP_tmp56_2 = null;
            PMachineValue TMP_tmp57_2 = null;
            PEvent TMP_tmp58_2 = null;
            PrtBool TMP_tmp59_2 = ((PrtBool)false);
            PMachineValue TMP_tmp60_2 = null;
            PMachineValue TMP_tmp61_2 = null;
            PEvent TMP_tmp62_2 = null;
            PrtBool TMP_tmp63_2 = ((PrtBool)false);
            TMP_tmp0_17 = (PrtNamedTuple)(((PrtNamedTuple)wReq_2)["req"]);
            currentMachine.Announce((Event)new eParsetMsg((new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null)), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()))))), TMP_tmp0_17);
            TMP_tmp1_14 = (PrtNamedTuple)(((PrtNamedTuple)wReq_2)["req"]);
            TMP_tmp2_14 = (PrtNamedTuple)(((PrtNamedTuple)TMP_tmp1_14)["hmsub"]);
            TMP_tmp3_11 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)TMP_tmp2_14)?.Clone()));
            hm = TMP_tmp3_11;
            TMP_tmp4_8 = (PrtNamedTuple)(((PrtNamedTuple)hm)["h"]);
            TMP_tmp5_8 = (PrtSeq)(((PrtNamedTuple)TMP_tmp4_8)["f"]);
            TMP_tmp6_8 = (PrtNamedTuple)(((PrtSeq)TMP_tmp5_8)[((PrtInt)0)]);
            TMP_tmp7_7 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)TMP_tmp6_8)?.Clone()));
            srcChanID = TMP_tmp7_7;
            TMP_tmp8_7 = (IPrtValue)(((PrtNamedTuple)hm)["msub"]);
            TMP_tmp9_7 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)((IPrtValue)TMP_tmp8_7)?.Clone())));
            msub = TMP_tmp9_7;
            TMP_tmp10_6 = (PrtNamedTuple)(((PrtNamedTuple)msub)["l"]);
            TMP_tmp11_6 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)TMP_tmp10_6)?.Clone()));
            optPlist = TMP_tmp11_6;
            TMP_tmp12_6 = (PrtSeq)(((PrtNamedTuple)optPlist)["pP"]);
            TMP_tmp13_6 = (PrtNamedTuple)(((PrtSeq)TMP_tmp12_6)[((PrtInt)0)]);
            TMP_tmp14_6 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)TMP_tmp13_6)?.Clone()));
            mtuPara = TMP_tmp14_6;
            counter2_2 = (PrtInt)(((PrtInt)0));
            flag1_1 = (PrtBool)(((PrtBool)false));
            index_1 = (PrtInt)(((PrtInt)0));
            while (((PrtBool)true))
            {
                TMP_tmp15_4 = (PrtInt)(((PrtInt)(Connection).Count));
                TMP_tmp16_4 = (PrtBool)((!PrtValues.SafeEquals(counter2_2,TMP_tmp15_4)));
                TMP_tmp17_4 = (PrtBool)(((PrtBool)((IPrtValue)TMP_tmp16_4)?.Clone()));
                if (TMP_tmp17_4)
                {
                }
                else
                {
                    break;
                }
                counter3_1 = (PrtInt)(((PrtInt)0));
                while (((PrtBool)true))
                {
                    TMP_tmp18_4 = (PrtSeq)(((PrtSeq)Connection)[counter2_2]);
                    TMP_tmp19_4 = (PrtInt)(((PrtInt)(TMP_tmp18_4).Count));
                    TMP_tmp20_4 = (PrtBool)((!PrtValues.SafeEquals(counter3_1,TMP_tmp19_4)));
                    TMP_tmp21_4 = (PrtBool)(((PrtBool)((IPrtValue)TMP_tmp20_4)?.Clone()));
                    if (TMP_tmp21_4)
                    {
                    }
                    else
                    {
                        break;
                    }
                    TMP_tmp22_4 = (PrtSeq)(((PrtSeq)Connection)[counter2_2]);
                    TMP_tmp23_4 = (PrtNamedTuple)(((PrtSeq)TMP_tmp22_4)[counter3_1]);
                    TMP_tmp24_4 = (PrtInt)(((PrtNamedTuple)TMP_tmp23_4)["nKey"]);
                    TMP_tmp25_3 = (PrtBool)((PrtValues.SafeEquals(TMP_tmp24_4,((PrtInt)1))));
                    TMP_tmp32_2 = (PrtBool)(((PrtBool)((IPrtValue)TMP_tmp25_3)?.Clone()));
                    if (TMP_tmp32_2)
                    {
                        TMP_tmp26_3 = (PrtSeq)(((PrtSeq)Connection)[counter2_2]);
                        TMP_tmp27_3 = (PrtNamedTuple)(((PrtSeq)TMP_tmp26_3)[counter3_1]);
                        TMP_tmp28_3 = (PrtNamedTuple)(((PrtNamedTuple)TMP_tmp27_3)["fKey"]);
                        TMP_tmp29_3 = (PrtSeq)(((PrtNamedTuple)TMP_tmp28_3)["value"]);
                        TMP_tmp30_2 = (PrtInt)(GlobalFunctions.readBuffer(TMP_tmp29_3, currentMachine));
                        TMP_tmp31_2 = (PrtBool)((PrtValues.SafeEquals(TMP_tmp30_2,((PrtInt)1))));
                        TMP_tmp32_2 = (PrtBool)(((PrtBool)((IPrtValue)TMP_tmp31_2)?.Clone()));
                    }
                    TMP_tmp41_2 = (PrtBool)(((PrtBool)((IPrtValue)TMP_tmp32_2)?.Clone()));
                    if (TMP_tmp41_2)
                    {
                        TMP_tmp33_2 = (PrtSeq)(((PrtNamedTuple)srcChanID)["value"]);
                        TMP_tmp34_2 = (PrtInt)(GlobalFunctions.readBuffer(TMP_tmp33_2, currentMachine));
                        TMP_tmp35_2 = (PrtSeq)(((PrtSeq)Connection)[counter2_2]);
                        TMP_tmp36_2 = (PrtNamedTuple)(((PrtSeq)TMP_tmp35_2)[counter3_1]);
                        TMP_tmp37_2 = (PrtNamedTuple)(((PrtNamedTuple)TMP_tmp36_2)["fVal"]);
                        TMP_tmp38_2 = (PrtSeq)(((PrtNamedTuple)TMP_tmp37_2)["value"]);
                        TMP_tmp39_2 = (PrtInt)(GlobalFunctions.readBuffer(TMP_tmp38_2, currentMachine));
                        TMP_tmp40_2 = (PrtBool)((PrtValues.SafeEquals(TMP_tmp34_2,TMP_tmp39_2)));
                        TMP_tmp41_2 = (PrtBool)(((PrtBool)((IPrtValue)TMP_tmp40_2)?.Clone()));
                    }
                    if (TMP_tmp41_2)
                    {
                        flag1_1 = (PrtBool)(((PrtBool)true));
                        TMP_tmp42_2 = (PrtInt)((counter2_2) + (((PrtInt)1)));
                        index_1 = TMP_tmp42_2;
                    }
                    TMP_tmp43_2 = (PrtInt)((counter3_1) + (((PrtInt)1)));
                    counter3_1 = TMP_tmp43_2;
                }
                TMP_tmp44_2 = (PrtInt)((counter2_2) + (((PrtInt)1)));
                counter2_2 = TMP_tmp44_2;
            }
            TMP_tmp45_2 = (PrtBool)((PrtValues.SafeEquals(flag1_1,((PrtBool)true))));
            if (TMP_tmp45_2)
            {
                TMP_tmp46_2 = (PrtInt)((index_1) - (((PrtInt)1)));
                TMP_tmp47_2 = (PrtSeq)(((PrtSeq)Connection)[TMP_tmp46_2]);
                TMP_tmp48_2 = (PrtSeq)(((PrtSeq)((IPrtValue)TMP_tmp47_2)?.Clone()));
                targetChan = TMP_tmp48_2;
                TMP_tmp49_2 = (PrtInt)(((PrtInt)(targetChan).Count));
                TMP_tmp50_2 = (PrtInt)((TMP_tmp49_2) - (((PrtInt)1)));
                TMP_tmp51_2 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)mtuPara)?.Clone()));
                ((PrtSeq)targetChan).Insert(TMP_tmp50_2, TMP_tmp51_2);
                TMP_tmp52_2 = (PMachineValue)(((PrtMap)ChanMachineList)[index_1]);
                TMP_tmp53_2 = (PMachineValue)(((PMachineValue)((IPrtValue)TMP_tmp52_2)?.Clone()));
                targetChanM = TMP_tmp53_2;
                TMP_tmp54_2 = (PMachineValue)(((PMachineValue)((IPrtValue)targetChanM)?.Clone()));
                TMP_tmp55_2 = (PEvent)(new eChanGotoConfig(null));
                currentMachine.TrySendEvent(TMP_tmp54_2, (Event)TMP_tmp55_2);
                TMP_tmp56_2 = (PMachineValue)(((PrtNamedTuple)wReq_2)["source"]);
                TMP_tmp57_2 = (PMachineValue)(((PMachineValue)((IPrtValue)TMP_tmp56_2)?.Clone()));
                TMP_tmp58_2 = (PEvent)(new eConfResp(((PrtBool)false)));
                TMP_tmp59_2 = (PrtBool)(((PrtBool)true));
                currentMachine.TrySendEvent(TMP_tmp57_2, (Event)TMP_tmp58_2, TMP_tmp59_2);
                return ;
            }
            TMP_tmp60_2 = (PMachineValue)(((PrtNamedTuple)wReq_2)["source"]);
            TMP_tmp61_2 = (PMachineValue)(((PMachineValue)((IPrtValue)TMP_tmp60_2)?.Clone()));
            TMP_tmp62_2 = (PEvent)(new eConfResp(((PrtBool)false)));
            TMP_tmp63_2 = (PrtBool)(((PrtBool)false));
            currentMachine.TrySendEvent(TMP_tmp61_2, (Event)TMP_tmp62_2, TMP_tmp63_2);
        }
        [Start]
        [OnEntry(nameof(InitializeParametersFunction))]
        [OnEventGotoState(typeof(ConstructorEvent), typeof(Init_3))]
        class __InitState__ : State { }
        
        [OnEntry(nameof(Anon_11))]
        class Init_3 : State
        {
        }
        [OnEventDoAction(typeof(eL2CmdReq), nameof(Anon_12))]
        [OnEventDoAction(typeof(eConnReq), nameof(Anon_13))]
        [OnEventDoAction(typeof(eConfReq), nameof(Anon_14))]
        class WaitForReqs : State
        {
        }
    }
}
namespace PImplementation
{
    internal partial class VarInitMachine : PMachine
    {
        private PrtNamedTuple vmtuType = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
        private PrtNamedTuple vmtuVal = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
        private PrtNamedTuple vmtuPara = (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
        private PrtNamedTuple voptPlist = (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq()));
        private PrtNamedTuple vsrcChanID = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
        private PrtNamedTuple vconfReqHdr = (new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
        private PrtNamedTuple vl2Psm = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
        private PrtNamedTuple vl2PsmType = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
        private PrtNamedTuple vl2PsmPara = (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
        private PrtNamedTuple vdstChanID = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
        private PrtNamedTuple vdstChanIDType = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
        private PrtNamedTuple vdstChanIDPara = (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
        private PrtNamedTuple vcmdType = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
        private PrtNamedTuple vcmdHdr = (new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
        private PrtNamedTuple vmsgConfReq = (new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null)), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()))));
        private PrtNamedTuple vmsgConfRsp = (new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null)), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()))));
        private PrtNamedTuple vmsgConnReq = (new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null)), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()))));
        private PrtNamedTuple vmsgConnRsp = (new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null)), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()))));
        private PrtNamedTuple vmsgL2Cmd_1 = (new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null)), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()))));
        private PrtInt BT_CONFIG_timeout_1 = ((PrtInt)0);
        private PrtInt BT_CONNECTED_timeout_1 = ((PrtInt)0);
        public class ConstructorEvent : PEvent{public ConstructorEvent(IPrtValue val) : base(val) { }}
        
        protected override Event GetConstructorEvent(IPrtValue value) { return new ConstructorEvent((IPrtValue)value); }
        public VarInitMachine() {
            this.sends.Add(nameof(eChanGotoConfig));
            this.sends.Add(nameof(eChanGotoConnected));
            this.sends.Add(nameof(eComposetFix));
            this.sends.Add(nameof(eComposetHdr));
            this.sends.Add(nameof(eComposetMsg));
            this.sends.Add(nameof(eComposetPara));
            this.sends.Add(nameof(eComposetPlist));
            this.sends.Add(nameof(eComposetVar));
            this.sends.Add(nameof(eConfReq));
            this.sends.Add(nameof(eConfResp));
            this.sends.Add(nameof(eConnReq));
            this.sends.Add(nameof(eConnResp));
            this.sends.Add(nameof(eGetDefaultValueResp));
            this.sends.Add(nameof(eL2CmdReq));
            this.sends.Add(nameof(eParsetFix));
            this.sends.Add(nameof(eParsetHdr));
            this.sends.Add(nameof(eParsetMsg));
            this.sends.Add(nameof(eParsetPara));
            this.sends.Add(nameof(eParsetPlist));
            this.sends.Add(nameof(eParsetVar));
            this.sends.Add(nameof(eSpecGetDefaultValueReq));
            this.sends.Add(nameof(eStartTimer));
            this.sends.Add(nameof(eTimeOut));
            this.sends.Add(nameof(PHalt));
            this.receives.Add(nameof(eChanGotoConfig));
            this.receives.Add(nameof(eChanGotoConnected));
            this.receives.Add(nameof(eComposetFix));
            this.receives.Add(nameof(eComposetHdr));
            this.receives.Add(nameof(eComposetMsg));
            this.receives.Add(nameof(eComposetPara));
            this.receives.Add(nameof(eComposetPlist));
            this.receives.Add(nameof(eComposetVar));
            this.receives.Add(nameof(eConfReq));
            this.receives.Add(nameof(eConfResp));
            this.receives.Add(nameof(eConnReq));
            this.receives.Add(nameof(eConnResp));
            this.receives.Add(nameof(eGetDefaultValueResp));
            this.receives.Add(nameof(eL2CmdReq));
            this.receives.Add(nameof(eParsetFix));
            this.receives.Add(nameof(eParsetHdr));
            this.receives.Add(nameof(eParsetMsg));
            this.receives.Add(nameof(eParsetPara));
            this.receives.Add(nameof(eParsetPlist));
            this.receives.Add(nameof(eParsetVar));
            this.receives.Add(nameof(eSpecGetDefaultValueReq));
            this.receives.Add(nameof(eStartTimer));
            this.receives.Add(nameof(eTimeOut));
            this.receives.Add(nameof(PHalt));
        }
        
        public void Anon_15(Event currentMachine_dequeuedEvent)
        {
            VarInitMachine currentMachine = this;
            PrtInt TMP_tmp0_18 = ((PrtInt)0);
            PrtInt TMP_tmp1_15 = ((PrtInt)0);
            PrtInt TMP_tmp2_15 = ((PrtInt)0);
            PrtSeq TMP_tmp3_12 = new PrtSeq();
            PrtNamedTuple TMP_tmp4_9 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtInt TMP_tmp5_9 = ((PrtInt)0);
            PrtInt TMP_tmp6_9 = ((PrtInt)0);
            PrtInt TMP_tmp7_8 = ((PrtInt)0);
            PrtSeq TMP_tmp8_8 = new PrtSeq();
            PrtNamedTuple TMP_tmp9_8 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtInt TMP_tmp10_7 = ((PrtInt)0);
            PrtNamedTuple TMP_tmp11_7 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtNamedTuple TMP_tmp12_7 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtNamedTuple TMP_tmp13_7 = (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PrtInt TMP_tmp14_7 = ((PrtInt)0);
            PrtSeq TMP_tmp15_5 = new PrtSeq();
            PrtNamedTuple TMP_tmp16_5 = (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq()));
            PrtNamedTuple TMP_tmp17_5 = (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PrtInt TMP_tmp18_5 = ((PrtInt)0);
            PrtInt TMP_tmp19_5 = ((PrtInt)0);
            PrtInt TMP_tmp20_5 = ((PrtInt)0);
            PrtSeq TMP_tmp21_5 = new PrtSeq();
            PrtNamedTuple TMP_tmp22_5 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtSeq TMP_tmp23_5 = new PrtSeq();
            PrtInt TMP_tmp24_5 = ((PrtInt)0);
            PrtInt TMP_tmp25_4 = ((PrtInt)0);
            PrtInt TMP_tmp26_4 = ((PrtInt)0);
            PrtInt TMP_tmp27_4 = ((PrtInt)0);
            PrtInt TMP_tmp28_4 = ((PrtInt)0);
            PrtSeq TMP_tmp29_4 = new PrtSeq();
            PrtNamedTuple TMP_tmp30_3 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtNamedTuple TMP_tmp31_3 = (new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PrtNamedTuple TMP_tmp32_3 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtInt TMP_tmp33_3 = ((PrtInt)0);
            PrtInt TMP_tmp34_3 = ((PrtInt)0);
            PrtInt TMP_tmp35_3 = ((PrtInt)0);
            PrtSeq TMP_tmp36_3 = new PrtSeq();
            PrtNamedTuple TMP_tmp37_3 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtInt TMP_tmp38_3 = ((PrtInt)0);
            PrtInt TMP_tmp39_3 = ((PrtInt)0);
            PrtInt TMP_tmp40_3 = ((PrtInt)0);
            PrtSeq TMP_tmp41_3 = new PrtSeq();
            PrtNamedTuple TMP_tmp42_3 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtInt TMP_tmp43_3 = ((PrtInt)0);
            PrtNamedTuple TMP_tmp44_3 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtNamedTuple TMP_tmp45_3 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtNamedTuple TMP_tmp46_3 = (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PrtInt TMP_tmp47_3 = ((PrtInt)0);
            PrtInt TMP_tmp48_3 = ((PrtInt)0);
            PrtInt TMP_tmp49_3 = ((PrtInt)0);
            PrtSeq TMP_tmp50_3 = new PrtSeq();
            PrtNamedTuple TMP_tmp51_3 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtInt TMP_tmp52_3 = ((PrtInt)0);
            PrtInt TMP_tmp53_3 = ((PrtInt)0);
            PrtInt TMP_tmp54_3 = ((PrtInt)0);
            PrtSeq TMP_tmp55_3 = new PrtSeq();
            PrtNamedTuple TMP_tmp56_3 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtInt TMP_tmp57_3 = ((PrtInt)0);
            PrtNamedTuple TMP_tmp58_3 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtNamedTuple TMP_tmp59_3 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtNamedTuple TMP_tmp60_3 = (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PrtInt TMP_tmp61_3 = ((PrtInt)0);
            PrtInt TMP_tmp62_3 = ((PrtInt)0);
            PrtInt TMP_tmp63_3 = ((PrtInt)0);
            PrtSeq TMP_tmp64_2 = new PrtSeq();
            PrtNamedTuple TMP_tmp65_2 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtSeq TMP_tmp66_2 = new PrtSeq();
            PrtInt TMP_tmp67_2 = ((PrtInt)0);
            PrtInt TMP_tmp68_2 = ((PrtInt)0);
            PrtInt TMP_tmp69_2 = ((PrtInt)0);
            PrtInt TMP_tmp70_2 = ((PrtInt)0);
            PrtInt TMP_tmp71_2 = ((PrtInt)0);
            PrtSeq TMP_tmp72_2 = new PrtSeq();
            PrtNamedTuple TMP_tmp73_2 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtNamedTuple TMP_tmp74_2 = (new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PrtNamedTuple TMP_tmp75_2 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtInt TMP_tmp76_2 = ((PrtInt)0);
            PrtNamedTuple TMP_tmp77_2 = (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtNamedTuple TMP_tmp78_2 = (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PrtSeq TMP_tmp79_2 = new PrtSeq();
            PrtNamedTuple TMP_tmp80_2 = (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq()));
            PrtNamedTuple TMP_tmp81_2 = (new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PrtNamedTuple TMP_tmp82_2 = (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq()));
            PrtNamedTuple TMP_tmp83_2 = (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq()))));
            PrtNamedTuple TMP_tmp84_2 = (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()));
            PrtNamedTuple TMP_tmp85_2 = (new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())))), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()))));
            PrtInt TMP_tmp86_2 = ((PrtInt)0);
            PrtNamedTuple TMP_tmp87_2 = (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtNamedTuple TMP_tmp88_2 = (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PrtSeq TMP_tmp89_2 = new PrtSeq();
            PrtNamedTuple TMP_tmp90_2 = (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq()));
            PrtNamedTuple TMP_tmp91_2 = (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null));
            PrtNamedTuple TMP_tmp92_2 = (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()));
            PrtNamedTuple TMP_tmp93_1 = (new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null)), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()))));
            PrtInt TMP_tmp94_1 = ((PrtInt)0);
            PrtNamedTuple TMP_tmp95_1 = (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtNamedTuple TMP_tmp96_1 = (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PrtSeq TMP_tmp97_1 = new PrtSeq();
            PrtNamedTuple TMP_tmp98_1 = (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq()));
            PrtNamedTuple TMP_tmp99_1 = (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null));
            PrtNamedTuple TMP_tmp100_1 = (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()));
            PrtNamedTuple TMP_tmp101_1 = (new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null)), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()))));
            PrtNamedTuple TMP_tmp102_1 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtNamedTuple TMP_tmp103_1 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtInt TMP_tmp104_1 = ((PrtInt)0);
            PrtNamedTuple TMP_tmp105_1 = (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtNamedTuple TMP_tmp106_1 = (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PrtSeq TMP_tmp107_1 = new PrtSeq();
            PrtNamedTuple TMP_tmp108_1 = (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq()));
            PrtNamedTuple TMP_tmp109_1 = (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null));
            PrtNamedTuple TMP_tmp110_1 = (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()));
            PrtNamedTuple TMP_tmp111_1 = (new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null)), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()))));
            PrtInt TMP_tmp112_1 = ((PrtInt)0);
            PrtNamedTuple TMP_tmp113_1 = (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtNamedTuple TMP_tmp114_1 = (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PrtSeq TMP_tmp115_1 = new PrtSeq();
            PrtNamedTuple TMP_tmp116_1 = (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq()));
            PrtNamedTuple TMP_tmp117_1 = (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null));
            PrtNamedTuple TMP_tmp118_1 = (new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PrtSeq TMP_tmp119_1 = new PrtSeq();
            PrtNamedTuple TMP_tmp120_1 = (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()));
            PrtNamedTuple TMP_tmp121_1 = (new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null)), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()))));
            PrtInt TMP_tmp122_1 = ((PrtInt)0);
            PrtNamedTuple TMP_tmp123_1 = (new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null)), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()))));
            PrtNamedTuple TMP_tmp124_1 = (new PrtNamedTuple(new string[]{"nType","msub"},((PrtInt)0), (new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null)), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()))))));
            PrtInt TMP_tmp125_1 = ((PrtInt)0);
            PrtNamedTuple TMP_tmp126 = (new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null)), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()))));
            PrtNamedTuple TMP_tmp127 = (new PrtNamedTuple(new string[]{"nType","msub"},((PrtInt)0), (new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null)), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()))))));
            TMP_tmp0_18 = (PrtInt)(((PrtInt)1));
            TMP_tmp1_15 = (PrtInt)(((PrtInt)10));
            TMP_tmp2_15 = (PrtInt)(((PrtInt)10));
            TMP_tmp3_12 = (PrtSeq)(new PrtSeq());
            TMP_tmp4_9 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"}, TMP_tmp0_18, TMP_tmp1_15, TMP_tmp2_15, TMP_tmp3_12)));
            vmtuType = TMP_tmp4_9;
            TMP_tmp5_9 = (PrtInt)(((PrtInt)2));
            TMP_tmp6_9 = (PrtInt)(((PrtInt)16));
            TMP_tmp7_8 = (PrtInt)(((PrtInt)1024));
            TMP_tmp8_8 = (PrtSeq)(new PrtSeq());
            TMP_tmp9_8 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"}, TMP_tmp5_9, TMP_tmp6_9, TMP_tmp7_8, TMP_tmp8_8)));
            vmtuVal = TMP_tmp9_8;
            TMP_tmp10_7 = (PrtInt)(((PrtInt)10));
            TMP_tmp11_7 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)vmtuType)?.Clone()));
            TMP_tmp12_7 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)vmtuVal)?.Clone()));
            TMP_tmp13_7 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"nKey","fKey","fVal"}, TMP_tmp10_7, TMP_tmp11_7, TMP_tmp12_7)));
            vmtuPara = TMP_tmp13_7;
            TMP_tmp14_7 = (PrtInt)(((PrtInt)8));
            TMP_tmp15_5 = (PrtSeq)(new PrtSeq());
            TMP_tmp16_5 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"nSize","pP"}, TMP_tmp14_7, TMP_tmp15_5)));
            voptPlist = TMP_tmp16_5;
            TMP_tmp17_5 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)vmtuPara)?.Clone()));
            ((PrtSeq)((PrtNamedTuple)voptPlist)["pP"]).Insert(((PrtInt)0), TMP_tmp17_5);
            TMP_tmp18_5 = (PrtInt)(((PrtInt)2));
            TMP_tmp19_5 = (PrtInt)(((PrtInt)1));
            TMP_tmp20_5 = (PrtInt)(((PrtInt)65535));
            TMP_tmp21_5 = (PrtSeq)(new PrtSeq());
            TMP_tmp22_5 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"}, TMP_tmp18_5, TMP_tmp19_5, TMP_tmp20_5, TMP_tmp21_5)));
            vsrcChanID = TMP_tmp22_5;
            TMP_tmp23_5 = (PrtSeq)(new PrtSeq());
            TMP_tmp24_5 = (PrtInt)(((PrtInt)1));
            TMP_tmp25_4 = (PrtInt)(((PrtInt)0));
            TMP_tmp26_4 = (PrtInt)(((PrtInt)255));
            TMP_tmp27_4 = (PrtInt)(((PrtInt)1));
            TMP_tmp28_4 = (PrtInt)(((PrtInt)1));
            TMP_tmp29_4 = (PrtSeq)(GlobalFunctions.writeBuffer(TMP_tmp27_4, TMP_tmp28_4, currentMachine));
            TMP_tmp30_3 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"}, TMP_tmp24_5, TMP_tmp25_4, TMP_tmp26_4, TMP_tmp29_4)));
            TMP_tmp31_3 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"f","fLen"}, TMP_tmp23_5, TMP_tmp30_3)));
            vconfReqHdr = TMP_tmp31_3;
            TMP_tmp32_3 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)vsrcChanID)?.Clone()));
            ((PrtSeq)((PrtNamedTuple)vconfReqHdr)["f"]).Insert(((PrtInt)0), TMP_tmp32_3);
            TMP_tmp33_3 = (PrtInt)(((PrtInt)1));
            TMP_tmp34_3 = (PrtInt)(((PrtInt)1));
            TMP_tmp35_3 = (PrtInt)(((PrtInt)23));
            TMP_tmp36_3 = (PrtSeq)(new PrtSeq());
            TMP_tmp37_3 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"}, TMP_tmp33_3, TMP_tmp34_3, TMP_tmp35_3, TMP_tmp36_3)));
            vl2Psm = TMP_tmp37_3;
            TMP_tmp38_3 = (PrtInt)(((PrtInt)1));
            TMP_tmp39_3 = (PrtInt)(((PrtInt)2));
            TMP_tmp40_3 = (PrtInt)(((PrtInt)2));
            TMP_tmp41_3 = (PrtSeq)(new PrtSeq());
            TMP_tmp42_3 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"}, TMP_tmp38_3, TMP_tmp39_3, TMP_tmp40_3, TMP_tmp41_3)));
            vl2PsmType = TMP_tmp42_3;
            TMP_tmp43_3 = (PrtInt)(((PrtInt)2));
            TMP_tmp44_3 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)vl2PsmType)?.Clone()));
            TMP_tmp45_3 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)vl2Psm)?.Clone()));
            TMP_tmp46_3 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"nKey","fKey","fVal"}, TMP_tmp43_3, TMP_tmp44_3, TMP_tmp45_3)));
            vl2PsmPara = TMP_tmp46_3;
            TMP_tmp47_3 = (PrtInt)(((PrtInt)2));
            TMP_tmp48_3 = (PrtInt)(((PrtInt)1));
            TMP_tmp49_3 = (PrtInt)(((PrtInt)65535));
            TMP_tmp50_3 = (PrtSeq)(new PrtSeq());
            TMP_tmp51_3 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"}, TMP_tmp47_3, TMP_tmp48_3, TMP_tmp49_3, TMP_tmp50_3)));
            vdstChanID = TMP_tmp51_3;
            TMP_tmp52_3 = (PrtInt)(((PrtInt)1));
            TMP_tmp53_3 = (PrtInt)(((PrtInt)1));
            TMP_tmp54_3 = (PrtInt)(((PrtInt)1));
            TMP_tmp55_3 = (PrtSeq)(new PrtSeq());
            TMP_tmp56_3 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"}, TMP_tmp52_3, TMP_tmp53_3, TMP_tmp54_3, TMP_tmp55_3)));
            vdstChanIDType = TMP_tmp56_3;
            TMP_tmp57_3 = (PrtInt)(((PrtInt)1));
            TMP_tmp58_3 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)vdstChanIDType)?.Clone()));
            TMP_tmp59_3 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)vdstChanID)?.Clone()));
            TMP_tmp60_3 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"nKey","fKey","fVal"}, TMP_tmp57_3, TMP_tmp58_3, TMP_tmp59_3)));
            vdstChanIDPara = TMP_tmp60_3;
            TMP_tmp61_3 = (PrtInt)(((PrtInt)1));
            TMP_tmp62_3 = (PrtInt)(((PrtInt)1));
            TMP_tmp63_3 = (PrtInt)(((PrtInt)22));
            TMP_tmp64_2 = (PrtSeq)(new PrtSeq());
            TMP_tmp65_2 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"}, TMP_tmp61_3, TMP_tmp62_3, TMP_tmp63_3, TMP_tmp64_2)));
            vcmdType = TMP_tmp65_2;
            TMP_tmp66_2 = (PrtSeq)(new PrtSeq());
            TMP_tmp67_2 = (PrtInt)(((PrtInt)1));
            TMP_tmp68_2 = (PrtInt)(((PrtInt)0));
            TMP_tmp69_2 = (PrtInt)(((PrtInt)255));
            TMP_tmp70_2 = (PrtInt)(((PrtInt)1));
            TMP_tmp71_2 = (PrtInt)(((PrtInt)1));
            TMP_tmp72_2 = (PrtSeq)(GlobalFunctions.writeBuffer(TMP_tmp70_2, TMP_tmp71_2, currentMachine));
            TMP_tmp73_2 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"}, TMP_tmp67_2, TMP_tmp68_2, TMP_tmp69_2, TMP_tmp72_2)));
            TMP_tmp74_2 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"f","fLen"}, TMP_tmp66_2, TMP_tmp73_2)));
            vcmdHdr = TMP_tmp74_2;
            TMP_tmp75_2 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)vcmdType)?.Clone()));
            ((PrtSeq)((PrtNamedTuple)vcmdHdr)["f"]).Insert(((PrtInt)0), TMP_tmp75_2);
            TMP_tmp76_2 = (PrtInt)(((PrtInt)4));
            TMP_tmp77_2 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())));
            TMP_tmp78_2 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))));
            TMP_tmp79_2 = (PrtSeq)(new PrtSeq());
            TMP_tmp80_2 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())));
            TMP_tmp81_2 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)vconfReqHdr)?.Clone()));
            TMP_tmp82_2 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)voptPlist)?.Clone()));
            TMP_tmp83_2 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"h","msub"}, TMP_tmp81_2, TMP_tmp82_2)));
            TMP_tmp84_2 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq())));
            TMP_tmp85_2 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"}, TMP_tmp76_2, TMP_tmp77_2, TMP_tmp78_2, TMP_tmp79_2, TMP_tmp80_2, TMP_tmp83_2, TMP_tmp84_2)));
            vmsgConfReq = (PrtNamedTuple)TMP_tmp85_2;
            TMP_tmp86_2 = (PrtInt)(((PrtInt)0));
            TMP_tmp87_2 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())));
            TMP_tmp88_2 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))));
            TMP_tmp89_2 = (PrtSeq)(new PrtSeq());
            TMP_tmp90_2 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())));
            TMP_tmp91_2 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null)));
            TMP_tmp92_2 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq())));
            TMP_tmp93_1 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"}, TMP_tmp86_2, TMP_tmp87_2, TMP_tmp88_2, TMP_tmp89_2, TMP_tmp90_2, TMP_tmp91_2, TMP_tmp92_2)));
            vmsgConfRsp = TMP_tmp93_1;
            TMP_tmp94_1 = (PrtInt)(((PrtInt)2));
            TMP_tmp95_1 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())));
            TMP_tmp96_1 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))));
            TMP_tmp97_1 = (PrtSeq)(new PrtSeq());
            TMP_tmp98_1 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())));
            TMP_tmp99_1 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null)));
            TMP_tmp100_1 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq())));
            TMP_tmp101_1 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"}, TMP_tmp94_1, TMP_tmp95_1, TMP_tmp96_1, TMP_tmp97_1, TMP_tmp98_1, TMP_tmp99_1, TMP_tmp100_1)));
            vmsgConnReq = TMP_tmp101_1;
            TMP_tmp102_1 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)vl2Psm)?.Clone()));
            ((PrtSeq)((PrtNamedTuple)vmsgConnReq)["fp"]).Insert(((PrtInt)0), TMP_tmp102_1);
            TMP_tmp103_1 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)vdstChanID)?.Clone()));
            ((PrtSeq)((PrtNamedTuple)vmsgConnReq)["fp"]).Insert(((PrtInt)1), TMP_tmp103_1);
            TMP_tmp104_1 = (PrtInt)(((PrtInt)0));
            TMP_tmp105_1 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())));
            TMP_tmp106_1 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))));
            TMP_tmp107_1 = (PrtSeq)(new PrtSeq());
            TMP_tmp108_1 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())));
            TMP_tmp109_1 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null)));
            TMP_tmp110_1 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq())));
            TMP_tmp111_1 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"}, TMP_tmp104_1, TMP_tmp105_1, TMP_tmp106_1, TMP_tmp107_1, TMP_tmp108_1, TMP_tmp109_1, TMP_tmp110_1)));
            vmsgConnRsp = TMP_tmp111_1;
            TMP_tmp112_1 = (PrtInt)(((PrtInt)5));
            TMP_tmp113_1 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())));
            TMP_tmp114_1 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))));
            TMP_tmp115_1 = (PrtSeq)(new PrtSeq());
            TMP_tmp116_1 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())));
            TMP_tmp117_1 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null)));
            TMP_tmp118_1 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)vcmdHdr)?.Clone()));
            TMP_tmp119_1 = (PrtSeq)(new PrtSeq());
            TMP_tmp120_1 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"h","msub"}, TMP_tmp118_1, TMP_tmp119_1)));
            TMP_tmp121_1 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"}, TMP_tmp112_1, TMP_tmp113_1, TMP_tmp114_1, TMP_tmp115_1, TMP_tmp116_1, TMP_tmp117_1, TMP_tmp120_1)));
            vmsgL2Cmd_1 = TMP_tmp121_1;
            TMP_tmp122_1 = (PrtInt)(((PrtInt)2));
            TMP_tmp123_1 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)vmsgConnReq)?.Clone()));
            TMP_tmp124_1 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"nType","msub"}, TMP_tmp122_1, TMP_tmp123_1)));
            ((PrtSeq)((PrtNamedTuple)((PrtNamedTuple)vmsgL2Cmd_1)["hcmsub"])["msub"]).Insert(((PrtInt)0), TMP_tmp124_1);
            TMP_tmp125_1 = (PrtInt)(((PrtInt)4));
            TMP_tmp126 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)vmsgConfReq)?.Clone()));
            TMP_tmp127 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"nType","msub"}, TMP_tmp125_1, TMP_tmp126)));
            ((PrtSeq)((PrtNamedTuple)((PrtNamedTuple)vmsgL2Cmd_1)["hcmsub"])["msub"]).Insert(((PrtInt)1), TMP_tmp127);
            BT_CONFIG_timeout_1 = (PrtInt)(((PrtInt)2000));
            BT_CONNECTED_timeout_1 = (PrtInt)(((PrtInt)2000));
            currentMachine.TryGotoState<WaitForMsgDefaultValueRequest>();
            return;
        }
        public void Anon_16(Event currentMachine_dequeuedEvent)
        {
            VarInitMachine currentMachine = this;
            PMachineValue wReq_3 = (PMachineValue)(gotoPayload ?? ((PEvent)currentMachine_dequeuedEvent).Payload);
            this.gotoPayload = null;
            PrtSeq ret_2 = new PrtSeq();
            PrtNamedTuple TMP_tmp0_19 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtNamedTuple TMP_tmp1_16 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtNamedTuple TMP_tmp2_16 = (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PrtNamedTuple TMP_tmp3_13 = (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq()));
            PrtNamedTuple TMP_tmp4_10 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtNamedTuple TMP_tmp5_10 = (new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PrtNamedTuple TMP_tmp6_10 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtNamedTuple TMP_tmp7_9 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtNamedTuple TMP_tmp8_9 = (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PrtNamedTuple TMP_tmp9_9 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtNamedTuple TMP_tmp10_8 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtNamedTuple TMP_tmp11_8 = (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PrtNamedTuple TMP_tmp12_8 = (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()));
            PrtNamedTuple TMP_tmp13_8 = (new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq()))));
            PrtNamedTuple TMP_tmp14_8 = (new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null)), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()))));
            PrtNamedTuple TMP_tmp15_6 = (new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null)), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()))));
            PrtNamedTuple TMP_tmp16_6 = (new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null)), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()))));
            PrtNamedTuple TMP_tmp17_6 = (new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null)), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()))));
            PrtNamedTuple TMP_tmp18_6 = (new PrtNamedTuple(new string[]{"chosen","v","p","fp","l","hmsub","hcmsub"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nKey","fKey","fVal"},((PrtInt)0), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","pP"},((PrtInt)0), new PrtSeq())), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), null)), (new PrtNamedTuple(new string[]{"h","msub"},(new PrtNamedTuple(new string[]{"f","fLen"},new PrtSeq(), (new PrtNamedTuple(new string[]{"nSize","nLow","nHigh","value"},((PrtInt)0), ((PrtInt)0), ((PrtInt)0), new PrtSeq())))), new PrtSeq()))));
            PrtInt TMP_tmp19_6 = ((PrtInt)0);
            PrtInt TMP_tmp20_6 = ((PrtInt)0);
            PMachineValue TMP_tmp21_6 = null;
            PEvent TMP_tmp22_6 = null;
            PrtSeq TMP_tmp23_6 = new PrtSeq();
            TMP_tmp0_19 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)vmtuType)?.Clone()));
            ((PrtSeq)ret_2).Insert(((PrtInt)0), TMP_tmp0_19);
            TMP_tmp1_16 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)vmtuVal)?.Clone()));
            ((PrtSeq)ret_2).Insert(((PrtInt)1), TMP_tmp1_16);
            TMP_tmp2_16 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)vmtuPara)?.Clone()));
            ((PrtSeq)ret_2).Insert(((PrtInt)2), TMP_tmp2_16);
            TMP_tmp3_13 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)voptPlist)?.Clone()));
            ((PrtSeq)ret_2).Insert(((PrtInt)3), TMP_tmp3_13);
            TMP_tmp4_10 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)vsrcChanID)?.Clone()));
            ((PrtSeq)ret_2).Insert(((PrtInt)4), TMP_tmp4_10);
            TMP_tmp5_10 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)vconfReqHdr)?.Clone()));
            ((PrtSeq)ret_2).Insert(((PrtInt)5), TMP_tmp5_10);
            TMP_tmp6_10 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)vl2Psm)?.Clone()));
            ((PrtSeq)ret_2).Insert(((PrtInt)6), TMP_tmp6_10);
            TMP_tmp7_9 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)vl2PsmType)?.Clone()));
            ((PrtSeq)ret_2).Insert(((PrtInt)7), TMP_tmp7_9);
            TMP_tmp8_9 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)vl2PsmPara)?.Clone()));
            ((PrtSeq)ret_2).Insert(((PrtInt)8), TMP_tmp8_9);
            TMP_tmp9_9 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)vdstChanID)?.Clone()));
            ((PrtSeq)ret_2).Insert(((PrtInt)9), TMP_tmp9_9);
            TMP_tmp10_8 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)vdstChanIDType)?.Clone()));
            ((PrtSeq)ret_2).Insert(((PrtInt)10), TMP_tmp10_8);
            TMP_tmp11_8 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)vdstChanIDPara)?.Clone()));
            ((PrtSeq)ret_2).Insert(((PrtInt)11), TMP_tmp11_8);
            TMP_tmp12_8 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)vcmdType)?.Clone()));
            ((PrtSeq)ret_2).Insert(((PrtInt)12), TMP_tmp12_8);
            TMP_tmp13_8 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)vcmdHdr)?.Clone()));
            ((PrtSeq)ret_2).Insert(((PrtInt)13), TMP_tmp13_8);
            TMP_tmp14_8 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)vmsgConfReq)?.Clone()));
            ((PrtSeq)ret_2).Insert(((PrtInt)14), TMP_tmp14_8);
            TMP_tmp15_6 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)vmsgConfRsp)?.Clone()));
            ((PrtSeq)ret_2).Insert(((PrtInt)15), TMP_tmp15_6);
            TMP_tmp16_6 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)vmsgConnReq)?.Clone()));
            ((PrtSeq)ret_2).Insert(((PrtInt)16), TMP_tmp16_6);
            TMP_tmp17_6 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)vmsgConnRsp)?.Clone()));
            ((PrtSeq)ret_2).Insert(((PrtInt)17), TMP_tmp17_6);
            TMP_tmp18_6 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)vmsgL2Cmd_1)?.Clone()));
            ((PrtSeq)ret_2).Insert(((PrtInt)18), TMP_tmp18_6);
            TMP_tmp19_6 = (PrtInt)(((PrtInt)((IPrtValue)BT_CONFIG_timeout_1)?.Clone()));
            ((PrtSeq)ret_2).Insert(((PrtInt)19), TMP_tmp19_6);
            TMP_tmp20_6 = (PrtInt)(((PrtInt)((IPrtValue)BT_CONNECTED_timeout_1)?.Clone()));
            ((PrtSeq)ret_2).Insert(((PrtInt)20), TMP_tmp20_6);
            TMP_tmp21_6 = (PMachineValue)(((PMachineValue)((IPrtValue)wReq_3)?.Clone()));
            TMP_tmp22_6 = (PEvent)(new eGetDefaultValueResp(new PrtSeq()));
            TMP_tmp23_6 = (PrtSeq)(((PrtSeq)((IPrtValue)ret_2)?.Clone()));
            currentMachine.TrySendEvent(TMP_tmp21_6, (Event)TMP_tmp22_6, TMP_tmp23_6);
        }
        [Start]
        [OnEntry(nameof(InitializeParametersFunction))]
        [OnEventGotoState(typeof(ConstructorEvent), typeof(Init_4))]
        class __InitState__ : State { }
        
        [OnEntry(nameof(Anon_15))]
        class Init_4 : State
        {
        }
        [OnEventDoAction(typeof(eSpecGetDefaultValueReq), nameof(Anon_16))]
        class WaitForMsgDefaultValueRequest : State
        {
        }
    }
}
namespace PImplementation
{
    internal partial class L2CAPFormatIsCorrect : PMonitor
    {
        static L2CAPFormatIsCorrect() {
            observes.Add(nameof(eComposetFix));
            observes.Add(nameof(eComposetHdr));
            observes.Add(nameof(eComposetMsg));
            observes.Add(nameof(eComposetPara));
            observes.Add(nameof(eComposetPlist));
            observes.Add(nameof(eComposetVar));
            observes.Add(nameof(eParsetFix));
            observes.Add(nameof(eParsetHdr));
            observes.Add(nameof(eParsetMsg));
            observes.Add(nameof(eParsetPara));
            observes.Add(nameof(eParsetPlist));
            observes.Add(nameof(eParsetVar));
        }
        
        public void Anon_17(Event currentMachine_dequeuedEvent)
        {
            L2CAPFormatIsCorrect currentMachine = this;
            currentMachine.TryGotoState<Observe>();
            return;
        }
        public void Anon_18(Event currentMachine_dequeuedEvent)
        {
            L2CAPFormatIsCorrect currentMachine = this;
            PrtNamedTuple value = (PrtNamedTuple)(gotoPayload ?? ((PEvent)currentMachine_dequeuedEvent).Payload);
            this.gotoPayload = null;
            return ;
        }
        public void Anon_19(Event currentMachine_dequeuedEvent)
        {
            L2CAPFormatIsCorrect currentMachine = this;
            PrtNamedTuple value_1 = (PrtNamedTuple)(gotoPayload ?? ((PEvent)currentMachine_dequeuedEvent).Payload);
            this.gotoPayload = null;
            return ;
        }
        public void Anon_20(Event currentMachine_dequeuedEvent)
        {
            L2CAPFormatIsCorrect currentMachine = this;
            PrtNamedTuple value_2 = (PrtNamedTuple)(gotoPayload ?? ((PEvent)currentMachine_dequeuedEvent).Payload);
            this.gotoPayload = null;
            return ;
        }
        public void Anon_21(Event currentMachine_dequeuedEvent)
        {
            L2CAPFormatIsCorrect currentMachine = this;
            PrtNamedTuple value_3 = (PrtNamedTuple)(gotoPayload ?? ((PEvent)currentMachine_dequeuedEvent).Payload);
            this.gotoPayload = null;
            return ;
        }
        public void Anon_22(Event currentMachine_dequeuedEvent)
        {
            L2CAPFormatIsCorrect currentMachine = this;
            PrtNamedTuple value_4 = (PrtNamedTuple)(gotoPayload ?? ((PEvent)currentMachine_dequeuedEvent).Payload);
            this.gotoPayload = null;
            return ;
        }
        public void Anon_23(Event currentMachine_dequeuedEvent)
        {
            L2CAPFormatIsCorrect currentMachine = this;
            PrtNamedTuple value_5 = (PrtNamedTuple)(gotoPayload ?? ((PEvent)currentMachine_dequeuedEvent).Payload);
            this.gotoPayload = null;
            return ;
        }
        public void Anon_24(Event currentMachine_dequeuedEvent)
        {
            L2CAPFormatIsCorrect currentMachine = this;
            PrtNamedTuple value_6 = (PrtNamedTuple)(gotoPayload ?? ((PEvent)currentMachine_dequeuedEvent).Payload);
            this.gotoPayload = null;
            return ;
        }
        public void Anon_25(Event currentMachine_dequeuedEvent)
        {
            L2CAPFormatIsCorrect currentMachine = this;
            PrtNamedTuple value_7 = (PrtNamedTuple)(gotoPayload ?? ((PEvent)currentMachine_dequeuedEvent).Payload);
            this.gotoPayload = null;
            return ;
        }
        public void Anon_26(Event currentMachine_dequeuedEvent)
        {
            L2CAPFormatIsCorrect currentMachine = this;
            PrtNamedTuple value_8 = (PrtNamedTuple)(gotoPayload ?? ((PEvent)currentMachine_dequeuedEvent).Payload);
            this.gotoPayload = null;
            return ;
        }
        public void Anon_27(Event currentMachine_dequeuedEvent)
        {
            L2CAPFormatIsCorrect currentMachine = this;
            PrtNamedTuple value_9 = (PrtNamedTuple)(gotoPayload ?? ((PEvent)currentMachine_dequeuedEvent).Payload);
            this.gotoPayload = null;
            return ;
        }
        public void Anon_28(Event currentMachine_dequeuedEvent)
        {
            L2CAPFormatIsCorrect currentMachine = this;
            PrtNamedTuple value_10 = (PrtNamedTuple)(gotoPayload ?? ((PEvent)currentMachine_dequeuedEvent).Payload);
            this.gotoPayload = null;
            return ;
        }
        public void Anon_29(Event currentMachine_dequeuedEvent)
        {
            L2CAPFormatIsCorrect currentMachine = this;
            PrtNamedTuple value_11 = (PrtNamedTuple)(gotoPayload ?? ((PEvent)currentMachine_dequeuedEvent).Payload);
            this.gotoPayload = null;
            return ;
        }
        [Start]
        [OnEntry(nameof(Anon_17))]
        [IgnoreEvents(typeof(eParsetFix), typeof(eParsetVar), typeof(eParsetHdr), typeof(eParsetPara), typeof(eParsetPlist), typeof(eParsetMsg), typeof(eComposetFix), typeof(eComposetVar), typeof(eComposetHdr), typeof(eComposetPara), typeof(eComposetPlist), typeof(eComposetMsg))]
        class Init_5 : State
        {
        }
        [OnEventDoAction(typeof(eParsetFix), nameof(Anon_18))]
        [OnEventDoAction(typeof(eParsetVar), nameof(Anon_19))]
        [OnEventDoAction(typeof(eParsetHdr), nameof(Anon_20))]
        [OnEventDoAction(typeof(eParsetPara), nameof(Anon_21))]
        [OnEventDoAction(typeof(eParsetPlist), nameof(Anon_22))]
        [OnEventDoAction(typeof(eParsetMsg), nameof(Anon_23))]
        [OnEventDoAction(typeof(eComposetFix), nameof(Anon_24))]
        [OnEventDoAction(typeof(eComposetVar), nameof(Anon_25))]
        [OnEventDoAction(typeof(eComposetHdr), nameof(Anon_26))]
        [OnEventDoAction(typeof(eComposetPara), nameof(Anon_27))]
        [OnEventDoAction(typeof(eComposetPlist), nameof(Anon_28))]
        [OnEventDoAction(typeof(eComposetMsg), nameof(Anon_29))]
        class Observe : State
        {
        }
    }
}
namespace PImplementation
{
    internal partial class TestWithSingleClient : PMachine
    {
        public class ConstructorEvent : PEvent{public ConstructorEvent(IPrtValue val) : base(val) { }}
        
        protected override Event GetConstructorEvent(IPrtValue value) { return new ConstructorEvent((IPrtValue)value); }
        public TestWithSingleClient() {
            this.sends.Add(nameof(eChanGotoConfig));
            this.sends.Add(nameof(eChanGotoConnected));
            this.sends.Add(nameof(eComposetFix));
            this.sends.Add(nameof(eComposetHdr));
            this.sends.Add(nameof(eComposetMsg));
            this.sends.Add(nameof(eComposetPara));
            this.sends.Add(nameof(eComposetPlist));
            this.sends.Add(nameof(eComposetVar));
            this.sends.Add(nameof(eConfReq));
            this.sends.Add(nameof(eConfResp));
            this.sends.Add(nameof(eConnReq));
            this.sends.Add(nameof(eConnResp));
            this.sends.Add(nameof(eGetDefaultValueResp));
            this.sends.Add(nameof(eL2CmdReq));
            this.sends.Add(nameof(eParsetFix));
            this.sends.Add(nameof(eParsetHdr));
            this.sends.Add(nameof(eParsetMsg));
            this.sends.Add(nameof(eParsetPara));
            this.sends.Add(nameof(eParsetPlist));
            this.sends.Add(nameof(eParsetVar));
            this.sends.Add(nameof(eSpecGetDefaultValueReq));
            this.sends.Add(nameof(eStartTimer));
            this.sends.Add(nameof(eTimeOut));
            this.sends.Add(nameof(PHalt));
            this.receives.Add(nameof(eChanGotoConfig));
            this.receives.Add(nameof(eChanGotoConnected));
            this.receives.Add(nameof(eComposetFix));
            this.receives.Add(nameof(eComposetHdr));
            this.receives.Add(nameof(eComposetMsg));
            this.receives.Add(nameof(eComposetPara));
            this.receives.Add(nameof(eComposetPlist));
            this.receives.Add(nameof(eComposetVar));
            this.receives.Add(nameof(eConfReq));
            this.receives.Add(nameof(eConfResp));
            this.receives.Add(nameof(eConnReq));
            this.receives.Add(nameof(eConnResp));
            this.receives.Add(nameof(eGetDefaultValueResp));
            this.receives.Add(nameof(eL2CmdReq));
            this.receives.Add(nameof(eParsetFix));
            this.receives.Add(nameof(eParsetHdr));
            this.receives.Add(nameof(eParsetMsg));
            this.receives.Add(nameof(eParsetPara));
            this.receives.Add(nameof(eParsetPlist));
            this.receives.Add(nameof(eParsetVar));
            this.receives.Add(nameof(eSpecGetDefaultValueReq));
            this.receives.Add(nameof(eStartTimer));
            this.receives.Add(nameof(eTimeOut));
            this.receives.Add(nameof(PHalt));
            this.creates.Add(nameof(I_ClientMachine));
            this.creates.Add(nameof(I_ConnMachine));
            this.creates.Add(nameof(I_VarInitMachine));
        }
        
        public void Anon_30(Event currentMachine_dequeuedEvent)
        {
            TestWithSingleClient currentMachine = this;
            PrtInt TMP_tmp0_20 = ((PrtInt)0);
            TMP_tmp0_20 = (PrtInt)(((PrtInt)1));
            GlobalFunctions.SetupClientServerSystem(TMP_tmp0_20, currentMachine);
        }
        [Start]
        [OnEntry(nameof(InitializeParametersFunction))]
        [OnEventGotoState(typeof(ConstructorEvent), typeof(Init_6))]
        class __InitState__ : State { }
        
        [OnEntry(nameof(Anon_30))]
        class Init_6 : State
        {
        }
    }
}
namespace PImplementation
{
    public class singleClient {
        public static void InitializeLinkMap() {
            PModule.linkMap.Clear();
            PModule.linkMap[nameof(I_ClientMachine)] = new Dictionary<string, string>();
            PModule.linkMap[nameof(I_ChanMachine)] = new Dictionary<string, string>();
            PModule.linkMap[nameof(I_ChanMachine)].Add(nameof(I_TimerMachine), nameof(I_TimerMachine));
            PModule.linkMap[nameof(I_ConnMachine)] = new Dictionary<string, string>();
            PModule.linkMap[nameof(I_ConnMachine)].Add(nameof(I_ChanMachine), nameof(I_ChanMachine));
            PModule.linkMap[nameof(I_TimerMachine)] = new Dictionary<string, string>();
            PModule.linkMap[nameof(I_VarInitMachine)] = new Dictionary<string, string>();
            PModule.linkMap[nameof(I_TestWithSingleClient)] = new Dictionary<string, string>();
            PModule.linkMap[nameof(I_TestWithSingleClient)].Add(nameof(I_ClientMachine), nameof(I_ClientMachine));
            PModule.linkMap[nameof(I_TestWithSingleClient)].Add(nameof(I_ConnMachine), nameof(I_ConnMachine));
            PModule.linkMap[nameof(I_TestWithSingleClient)].Add(nameof(I_VarInitMachine), nameof(I_VarInitMachine));
        }
        
        public static void InitializeInterfaceDefMap() {
            PModule.interfaceDefinitionMap.Clear();
            PModule.interfaceDefinitionMap.Add(nameof(I_ClientMachine), typeof(ClientMachine));
            PModule.interfaceDefinitionMap.Add(nameof(I_ChanMachine), typeof(ChanMachine));
            PModule.interfaceDefinitionMap.Add(nameof(I_ConnMachine), typeof(ConnMachine));
            PModule.interfaceDefinitionMap.Add(nameof(I_TimerMachine), typeof(TimerMachine));
            PModule.interfaceDefinitionMap.Add(nameof(I_VarInitMachine), typeof(VarInitMachine));
            PModule.interfaceDefinitionMap.Add(nameof(I_TestWithSingleClient), typeof(TestWithSingleClient));
        }
        
        public static void InitializeMonitorObserves() {
            PModule.monitorObserves.Clear();
            PModule.monitorObserves[nameof(L2CAPFormatIsCorrect)] = new List<string>();
            PModule.monitorObserves[nameof(L2CAPFormatIsCorrect)].Add(nameof(eComposetFix));
            PModule.monitorObserves[nameof(L2CAPFormatIsCorrect)].Add(nameof(eComposetHdr));
            PModule.monitorObserves[nameof(L2CAPFormatIsCorrect)].Add(nameof(eComposetMsg));
            PModule.monitorObserves[nameof(L2CAPFormatIsCorrect)].Add(nameof(eComposetPara));
            PModule.monitorObserves[nameof(L2CAPFormatIsCorrect)].Add(nameof(eComposetPlist));
            PModule.monitorObserves[nameof(L2CAPFormatIsCorrect)].Add(nameof(eComposetVar));
            PModule.monitorObserves[nameof(L2CAPFormatIsCorrect)].Add(nameof(eParsetFix));
            PModule.monitorObserves[nameof(L2CAPFormatIsCorrect)].Add(nameof(eParsetHdr));
            PModule.monitorObserves[nameof(L2CAPFormatIsCorrect)].Add(nameof(eParsetMsg));
            PModule.monitorObserves[nameof(L2CAPFormatIsCorrect)].Add(nameof(eParsetPara));
            PModule.monitorObserves[nameof(L2CAPFormatIsCorrect)].Add(nameof(eParsetPlist));
            PModule.monitorObserves[nameof(L2CAPFormatIsCorrect)].Add(nameof(eParsetVar));
        }
        
        public static void InitializeMonitorMap(IActorRuntime runtime) {
            PModule.monitorMap.Clear();
            PModule.monitorMap[nameof(I_ClientMachine)] = new List<Type>();
            PModule.monitorMap[nameof(I_ClientMachine)].Add(typeof(L2CAPFormatIsCorrect));
            PModule.monitorMap[nameof(I_ChanMachine)] = new List<Type>();
            PModule.monitorMap[nameof(I_ChanMachine)].Add(typeof(L2CAPFormatIsCorrect));
            PModule.monitorMap[nameof(I_ConnMachine)] = new List<Type>();
            PModule.monitorMap[nameof(I_ConnMachine)].Add(typeof(L2CAPFormatIsCorrect));
            PModule.monitorMap[nameof(I_TimerMachine)] = new List<Type>();
            PModule.monitorMap[nameof(I_TimerMachine)].Add(typeof(L2CAPFormatIsCorrect));
            PModule.monitorMap[nameof(I_VarInitMachine)] = new List<Type>();
            PModule.monitorMap[nameof(I_VarInitMachine)].Add(typeof(L2CAPFormatIsCorrect));
            PModule.monitorMap[nameof(I_TestWithSingleClient)] = new List<Type>();
            PModule.monitorMap[nameof(I_TestWithSingleClient)].Add(typeof(L2CAPFormatIsCorrect));
            runtime.RegisterMonitor<L2CAPFormatIsCorrect>();
        }
        
        
        [Microsoft.Coyote.SystematicTesting.Test]
        public static void Execute(IActorRuntime runtime) {
            runtime.RegisterLog(new PLogFormatter());
            PModule.runtime = runtime;
            PHelper.InitializeInterfaces();
            PHelper.InitializeEnums();
            InitializeLinkMap();
            InitializeInterfaceDefMap();
            InitializeMonitorMap(runtime);
            InitializeMonitorObserves();
            runtime.CreateActor(typeof(_GodMachine), new _GodMachine.Config(typeof(TestWithSingleClient)));
        }
    }
}
// TODO: NamedModule L2CAPServer
// TODO: NamedModule L2CAPClient
namespace PImplementation
{
    public class I_ClientMachine : PMachineValue {
        public I_ClientMachine (ActorId machine, List<string> permissions) : base(machine, permissions) { }
    }
    
    public class I_ChanMachine : PMachineValue {
        public I_ChanMachine (ActorId machine, List<string> permissions) : base(machine, permissions) { }
    }
    
    public class I_TimerMachine : PMachineValue {
        public I_TimerMachine (ActorId machine, List<string> permissions) : base(machine, permissions) { }
    }
    
    public class I_ConnMachine : PMachineValue {
        public I_ConnMachine (ActorId machine, List<string> permissions) : base(machine, permissions) { }
    }
    
    public class I_VarInitMachine : PMachineValue {
        public I_VarInitMachine (ActorId machine, List<string> permissions) : base(machine, permissions) { }
    }
    
    public class I_TestWithSingleClient : PMachineValue {
        public I_TestWithSingleClient (ActorId machine, List<string> permissions) : base(machine, permissions) { }
    }
    
    public partial class PHelper {
        public static void InitializeInterfaces() {
            PInterfaces.Clear();
            PInterfaces.AddInterface(nameof(I_ClientMachine), nameof(eChanGotoConfig), nameof(eChanGotoConnected), nameof(eComposetFix), nameof(eComposetHdr), nameof(eComposetMsg), nameof(eComposetPara), nameof(eComposetPlist), nameof(eComposetVar), nameof(eConfReq), nameof(eConfResp), nameof(eConnReq), nameof(eConnResp), nameof(eGetDefaultValueResp), nameof(eL2CmdReq), nameof(eParsetFix), nameof(eParsetHdr), nameof(eParsetMsg), nameof(eParsetPara), nameof(eParsetPlist), nameof(eParsetVar), nameof(eSpecGetDefaultValueReq), nameof(eStartTimer), nameof(eTimeOut), nameof(PHalt));
            PInterfaces.AddInterface(nameof(I_ChanMachine), nameof(eChanGotoConfig), nameof(eChanGotoConnected), nameof(eComposetFix), nameof(eComposetHdr), nameof(eComposetMsg), nameof(eComposetPara), nameof(eComposetPlist), nameof(eComposetVar), nameof(eConfReq), nameof(eConfResp), nameof(eConnReq), nameof(eConnResp), nameof(eGetDefaultValueResp), nameof(eL2CmdReq), nameof(eParsetFix), nameof(eParsetHdr), nameof(eParsetMsg), nameof(eParsetPara), nameof(eParsetPlist), nameof(eParsetVar), nameof(eSpecGetDefaultValueReq), nameof(eStartTimer), nameof(eTimeOut), nameof(PHalt));
            PInterfaces.AddInterface(nameof(I_TimerMachine), nameof(eChanGotoConfig), nameof(eChanGotoConnected), nameof(eComposetFix), nameof(eComposetHdr), nameof(eComposetMsg), nameof(eComposetPara), nameof(eComposetPlist), nameof(eComposetVar), nameof(eConfReq), nameof(eConfResp), nameof(eConnReq), nameof(eConnResp), nameof(eGetDefaultValueResp), nameof(eL2CmdReq), nameof(eParsetFix), nameof(eParsetHdr), nameof(eParsetMsg), nameof(eParsetPara), nameof(eParsetPlist), nameof(eParsetVar), nameof(eSpecGetDefaultValueReq), nameof(eStartTimer), nameof(eTimeOut), nameof(PHalt));
            PInterfaces.AddInterface(nameof(I_ConnMachine), nameof(eChanGotoConfig), nameof(eChanGotoConnected), nameof(eComposetFix), nameof(eComposetHdr), nameof(eComposetMsg), nameof(eComposetPara), nameof(eComposetPlist), nameof(eComposetVar), nameof(eConfReq), nameof(eConfResp), nameof(eConnReq), nameof(eConnResp), nameof(eGetDefaultValueResp), nameof(eL2CmdReq), nameof(eParsetFix), nameof(eParsetHdr), nameof(eParsetMsg), nameof(eParsetPara), nameof(eParsetPlist), nameof(eParsetVar), nameof(eSpecGetDefaultValueReq), nameof(eStartTimer), nameof(eTimeOut), nameof(PHalt));
            PInterfaces.AddInterface(nameof(I_VarInitMachine), nameof(eChanGotoConfig), nameof(eChanGotoConnected), nameof(eComposetFix), nameof(eComposetHdr), nameof(eComposetMsg), nameof(eComposetPara), nameof(eComposetPlist), nameof(eComposetVar), nameof(eConfReq), nameof(eConfResp), nameof(eConnReq), nameof(eConnResp), nameof(eGetDefaultValueResp), nameof(eL2CmdReq), nameof(eParsetFix), nameof(eParsetHdr), nameof(eParsetMsg), nameof(eParsetPara), nameof(eParsetPlist), nameof(eParsetVar), nameof(eSpecGetDefaultValueReq), nameof(eStartTimer), nameof(eTimeOut), nameof(PHalt));
            PInterfaces.AddInterface(nameof(I_TestWithSingleClient), nameof(eChanGotoConfig), nameof(eChanGotoConnected), nameof(eComposetFix), nameof(eComposetHdr), nameof(eComposetMsg), nameof(eComposetPara), nameof(eComposetPlist), nameof(eComposetVar), nameof(eConfReq), nameof(eConfResp), nameof(eConnReq), nameof(eConnResp), nameof(eGetDefaultValueResp), nameof(eL2CmdReq), nameof(eParsetFix), nameof(eParsetHdr), nameof(eParsetMsg), nameof(eParsetPara), nameof(eParsetPlist), nameof(eParsetVar), nameof(eSpecGetDefaultValueReq), nameof(eStartTimer), nameof(eTimeOut), nameof(PHalt));
        }
    }
    
}
namespace PImplementation
{
    public partial class PHelper {
        public static void InitializeEnums() {
            PrtEnum.Clear();
        }
    }
    
}
#pragma warning restore 162, 219, 414
