test singleClient [main=TestWithSingleClient]:
  assert L2CAPFormatIsCorrect in
  (union L2CAPClient, L2CAPServer, {TestWithSingleClient});