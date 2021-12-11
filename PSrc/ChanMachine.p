event eChanGotoConnected;
event eChanGotoConfig;
event eChanDead;
event eChanStarted;
event eChanConnected;

// payload is the state id.
event eStartTimer: int;
event eTimeOut: int;

machine ChanMachine
{
    var ConfigReqID: int;
    var ConnectedReqID: int;
    var ConfigTimer: machine;
    var ConnectedTimer: machine;
    var InitServer : VarInitMachine;
    var BT_CONFIG_timeout: int;
    var BT_CONNECTED_timeout: int;

    start state Init{
        entry (_InitServer : VarInitMachine){
            InitServer = _InitServer;
            ConfigReqID = 0;
            ConfigReqID = 0;
            send InitServer, eSpecGetDefaultValueReq, this;
            receive {
                case eGetDefaultValueResp: (resp: seq[data]){
                     BT_CONFIG_timeout= resp[19] as int;
                     BT_CONNECTED_timeout= resp[20] as int;
                }
            }
            ConfigTimer = new TimerMachine((_client=this, _timeout=BT_CONFIG_timeout));
            ConnectedTimer = new TimerMachine((_client=this, _timeout=BT_CONNECTED_timeout));
            goto BT_START;
        }
    }
    state BT_START{
        entry{
//            print "Channel Started";
        }
        on eChanGotoConfig do{
            send ConfigTimer, eStartTimer, 0;
            goto BT_CONFIG;
        }
        ignore eChanGotoConnected, eTimeOut;
    }
    state BT_CONFIG{
        entry{
            announce eChanStarted;
//            print "Channel Config Success";
        }
        //state id = 0
        on eChanGotoConnected do{
            send ConnectedTimer, eStartTimer, 1;
            goto BT_CONNECTED;
        }
        on eTimeOut do (stateid: int){
            if(stateid == 0)
                goto BT_DEAD;
        }
        ignore eChanGotoConfig;
    }

    state BT_CONNECTED{
        entry{
            announce eChanConnected;
//            print "Channel Connect Success";
        }
        // state id = 1
        on eTimeOut do (stateid: int){
            if(stateid == 1)
                goto BT_DEAD;
        }
        ignore eChanGotoConnected;
    }

    state BT_DEAD{
        entry{
            announce eChanDead;
        }
        ignore eChanGotoConnected, eTimeOut;
    }

}

machine TimerMachine
{
    var client: machine;
    var timeout: int;
    start state Init {
        entry(input:(_client : machine, _timeout : int)) {
            client = input._client;
            timeout = input._timeout;
            goto WaitForTimerRequests;
        }
    }

    state WaitForTimerRequests {
        on eStartTimer do (stateid: int){
            goto TimerStarted, stateid;
        }
    }

    state TimerStarted {
        entry(stateid: int) {
            if(timeout != 0){
                sleepFor(timeout);
//                sleepFor_counter(timeout);
                send client, eTimeOut, stateid;
                goto WaitForTimerRequests;
            }
        }
        ignore eStartTimer;
    }
}

fun sleepFor(sleeptime: int) : bool ;

fun sleepFor_counter(sleeptime: int): bool
{
    var counter : int;
    counter = 0;
    while(counter < sleeptime){
        counter = counter + 1;
    }
    return true;
}

