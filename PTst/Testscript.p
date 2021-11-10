test singleClient [main=TestWithSingleClient]:
  assert MessageFormatSpecMachine, LivenessSpecMachine in
  (union L2CAPClient, L2CAPServer, {TestWithSingleClient});