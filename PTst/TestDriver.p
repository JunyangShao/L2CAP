// Test driver that checks the system with a single Client.
machine TestWithSingleClient
{
    start state Init {
        entry {
            SetupClientServerSystem(1);
        }
    }
}

// setup the client server system with one  ConnServer and `numClients` clients.
fun SetupClientServerSystem(numClients: int)
{
    var ConnServer: ConnMachine;
    var InitServer: VarInitMachine;
    var InitConnetcion: tConn;
    var InitChannel: tChan;
    var tmpPara: tPara;
    var counter: int;

    InitServer = new VarInitMachine();
    InitConnetcion = default(tConn);
    InitChannel = default(tChan);
    tmpPara = default(tPara);

    tmpPara.nKey = 1;
    tmpPara.fKey.nSize = 1;
    tmpPara.fKey.nLow = 1;
    tmpPara.fKey.nHigh = 1;
    tmpPara.fKey.value = writeBuffer(1, 1);
    tmpPara.fVal.nSize = 2;
    tmpPara.fVal.nLow = 1;
    tmpPara.fVal.nHigh = 65535;
    tmpPara.fVal.value = writeBuffer(2, choose(65535) + 1);
    InitChannel += (0, tmpPara);

    tmpPara.nKey = 2;
    tmpPara.fKey.nSize = 1;
    tmpPara.fKey.nLow = 2;
    tmpPara.fKey.nHigh = 2;
    tmpPara.fKey.value = writeBuffer(1, 2);
    tmpPara.fVal.nSize = 1;
    tmpPara.fVal.nLow = 1;
    tmpPara.fVal.nHigh = 23;
    tmpPara.fVal.value = writeBuffer(1, choose(23) + 1);
    InitChannel += (1, tmpPara);

    InitConnetcion += (0, InitChannel);

    ConnServer = new ConnMachine((serv=InitServer, conn=InitConnetcion));

    while(counter < numClients){
        new ClientMachine((_InitServer=InitServer, _ConnServer=ConnServer));
    }
}