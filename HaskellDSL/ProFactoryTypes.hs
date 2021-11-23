-- ProFactory DSL Data Types
-- Fei Wang, Nov 2020
-- This module defines all the data types used in ProFactory
-- Developers could define redundant protocol elements but only select to emit some of them

module ProFactoryTypes
where

import Data.Char
import Data.List
-- import L2CAPClassicInterfaceNames

-- Define some protocol-specific interfaces
-- These interfaces are supposed to be hardcoded
-- Protocol name
protoName = "l2cap"

-- Protocol channel
protoChan = "l2cap_chan"

-- Protocol connection
protoConn = "l2cap_conn"

-- Protocol family socket buffer allocation
protoFamilySkbAlloc = "bt_skb_alloc(1600, GFP_KERNEL);\n"

-- Lower-layer device connection management
lowLayerDevConnMgmt = "hci_dev_connect_mgmt(pconn);\n"

-- lock the iteration of channel list
lockChanList = "mutex_lock(&pconn->chan_lock);\n"

-- unlock the iteration of channel list
unlockChanList = "mutex_unlock(&pconn->chan_lock);\n"

-- lock the channel
lockChan = "l2cap_chan_lock(pchan);\n"

-- unlock the channel
unlockChan = "l2cap_chan_unlock(pchan);\n"

-- lower-layer delivery
lowLayerDeliver = ""

-- higher-leayer receive
highLayerReceive = ""

-- Define typeclass for printing names in code generation
-- Then define instances for each type
-- Default instance for all the class functions is an error message
class PfCode a where
    pfSigGen :: a -> String -- Generate struct data structure
    pfCodeGen :: a -> String -- Generate code string
    pfGetMacro :: a -> String -- Get macro name
    pfMacroGen :: a -> String -- Generate macro definition
    pfExtractGen :: a -> String -- Generate field extraction and bound check
    pfLocalGen :: a -> String -- Generate local definitions of fields in parsers
    pfConstructLocalGen :: a -> String -- Generate local definitions of field in construction
    pfConstructExtractGen :: a -> String -- Generate field extraction for construction
    pfSigGen x = error("Function pfSigGen is not implemented for this type")
    pfCodeGen x = error("Function pfCodeGen is not implemented for this type")
    pfGetMacro x = error("Function pfGetMacro is not implemented for this type")
    pfMacroGen x = error("Function pfMacroGen is not implemented for this type")
    pfExtractGen x = error("Function pfMacroGen is not implemented for this type")
    pfLocalGen x = error("Function pfLocalGen is not implemented for this type")
    pfConstructLocalGen x = error("Function pfConstructLocalGen is not implemented for this type")
    pfConstructExtractGen x = error("Function pfConstructExtractGen is not implemented for this type")

-- Selectively emit code blocks according to protocol element definitions
class PfEmit a where
    pfEmitMacro :: a -> String -- Emit macro definitions
    pfEmitDeclare :: a -> String -- Emit declarations
    pfEmitBlock :: a -> String -- Generic code block emission
    pfEmitFunc :: a -> String -- Specialized function base emission
    pfEmitMacro x = error("Function pfEmitMacro is not implemented for this type")
    pfEmitDeclare x = error("Function pfEmitDeclare is not implemented for this type")
    pfEmitBlock x = error("Function pfEmitBlock is not implemented for this type")
    pfEmitFunc x = error("Function pfEmitFunc is not implemented for this type")

-- Define operators. Note that we define customized operators because we need to hold
-- expression instead of direct semantic evaluation or code transformation. Those expressions
-- will be properly generated when developers decide to emit the code.
data Bop = PfADD -- +
         | PfMIN -- -
         | PfMUL -- *
         | PfDIV -- /
         | PfMOD -- %
         | PfEQ -- ==
         | PfGT -- >
         | PfGE -- >=
         | PfLT -- <
         | PfLE -- <=
         | PfAND -- &&
         | PfOR -- ||
         | PfBAND -- &
         | PfBOR -- |
         | PfBXOR -- ^
         | PfACC -- ->

instance PfCode Bop where
    pfCodeGen PfADD = "+"
    pfCodeGen PfMIN = "-"
    pfCodeGen PfMUL = "*"
    pfCodeGen PfDIV = "/"
    pfCodeGen PfMOD = "%"
    pfCodeGen PfEQ = "=="
    pfCodeGen PfGT = ">"
    pfCodeGen PfGE = ">="
    pfCodeGen PfLT = "<"
    pfCodeGen PfLE = "<="
    pfCodeGen PfAND = "&&"
    pfCodeGen PfOR = "||"
    pfCodeGen PfBAND = "&"
    pfCodeGen PfBOR = "|"
    pfCodeGen PfBXOR = "^"
    pfCodeGen PfACC = "->"

data Uop = PfNeg -- !

instance PfCode Uop where
    pfCodeGen PfNeg = "!"

-- Define fixed-sized field
data Fix = Fix { nameFix :: String
               , sizeFix :: Int
			   , lowFix :: Int
			   , highFix :: Int
			   }
-- Get variable types based on their sizes
pfVarType :: Int -> String
pfVarType x | x == 1 = "__u8 "
            | x == 2 = "__u16 "
			| x == 4 = "__u32 "
            | otherwise = error("The size is not supported")

subFixValueCheck :: String -> Fix -> String
subFixValueCheck m (Fix x y z k)
    | z > k = ""
    | z <= k = "if(" ++ fName ++ ">" ++ show k ++ "||" ++ fName ++ "<" ++ show z
               ++ ") goto drop;\n"
        where fName = m ++ "->" ++ x
			
instance PfCode Fix where
    pfSigGen (Fix x y z k) = pfVarType y ++ x ++ ";\n"
    pfCodeGen (Fix x y z k) = x

-- Define a sequence of fixed-sized fields
-- This particular field type is used for formatting messages
data FixSeq = FixSeq { nameFixSeq :: String
                     , fixSeqBody :: [Fix]
                     }					 

instance PfCode FixSeq where
    pfSigGen (FixSeq x y) = "struct __attribute__((packed)) " ++ x ++ "_fseq {\n" ++ concat (map pfSigGen y) ++ "};\n"
    pfCodeGen (FixSeq x y) = x
    pfGetMacro (FixSeq x y) = "FSEQ_" ++ map toUpper x ++ "_SIZE"
    pfMacroGen (FixSeq x y) = "#define FSEQ_" ++ map toUpper x ++ "_SIZE "
                             ++ show (sum (map sizeFix y)) ++ "\n"
    pfExtractGen (FixSeq x y) = "if(skb_in->len<" ++ k ++ ") goto drop;\n"
	                           ++ x ++ "=(void*)skb_in->data;\n" ++ "skb_pull(skb_in,"
                               ++ k ++ ");\n"
                               ++ concat (map (subFixValueCheck x) y)
		where k = pfGetMacro (FixSeq x y)
    pfLocalGen (FixSeq x y) = "struct " ++ x ++ "_fseq* " ++ x ++ "=NULL;\n"
    pfConstructLocalGen x = pfLocalGen x
    pfConstructExtractGen (FixSeq x y) = x ++ "=(void*)skb_put(skb_out," ++ pfGetMacro (FixSeq x y) ++ ");\n"

instance PfEmit FixSeq where
    pfEmitMacro x = pfMacroGen x
    pfEmitDeclare x = pfSigGen x
	
-- Define variable-sized field
data Var = Var { nameVar :: String
               , lowSizeVar :: Int
			   , highSizeVar :: Int
			   }

instance PfCode Var where
    pfCodeGen (Var x y z) = x
    pfExtractGen (Var x y z) = "if(skb_in->len>" ++ show z ++ " || skb_in->len<" ++ show y ++ ") goto drop;\n"
    pfLocalGen x = ""
    pfConstructLocalGen x = ""
    pfConstructExtractGen x = ""

-- Define message header
-- Do not reuse any header in a message but hearders must be unique
data Hdr = Hdr { nameHdr :: String
               , hdrFixFields :: [Fix]
			   , hdrLenField :: Fix
			   }

instance PfCode Hdr where
    pfSigGen (Hdr x y z) = "struct __attribute__((packed)) " ++ x ++ "_hdr {\n" ++ vL ++ "};\n"
        where vL = concat (map pfSigGen y) ++ pfSigGen z
    pfCodeGen (Hdr x y z) = x
    pfGetMacro (Hdr x y z) = "H_" ++ map toUpper x ++ "_SIZE"
    pfMacroGen (Hdr x y z) = "#define H_" ++ map toUpper x ++ "_SIZE "
                             ++ show (sum (map sizeFix y) + sizeFix z) ++ "\n"
    pfExtractGen (Hdr x y z) = "if(skb_in->len<=" ++ k ++ ") goto drop;\n"
	                           ++ x ++ "=(void*)skb_in->data;\n" ++ "skb_pull(skb_in,"
                               ++ k ++ ");\n" ++ "if(" ++ x ++ "->len!=skb_in->len) goto drop;\n"
                               ++ subFixValueCheck x z
                               ++ concat (map (subFixValueCheck x) y)
        where k = pfGetMacro (Hdr x y z)
    pfLocalGen (Hdr x y z) = "struct " ++ x ++ "_hdr* " ++ x ++ "=NULL;\n"
    pfConstructLocalGen x = pfLocalGen x
    pfConstructExtractGen (Hdr x y z) = x ++ "=(void*)skb_put(skb_out," ++ pfGetMacro (Hdr x y z) ++ ");\n"

instance PfEmit Hdr where
    pfEmitMacro x = pfMacroGen x
    pfEmitDeclare x = pfSigGen x

-- Define parameter
-- MTU is a preset parameter with the name of "mtu"
-- The keys should be unique for each defined parameter, occupying 4 bytes
-- We do not assign a length field to a parameter as ProFactory currently only supports
-- fixed-sized parameter
data Para = Para { namePara :: String
                 , keyVal :: Int -- a key occupies 4 bytes
		         , paraFixField :: Fix
		         }
-- Declare a parameter in channel or connection
paraDeclareInStruct :: Para -> String
paraDeclareInStruct (Para x y z) = pfVarType (sizeFix z) ++ x ++ ";\n"

-- Get parameter body size
paraGetBodySize :: Para -> Int
paraGetBodySize (Para x y z) = 4 + sizeFix z

instance PfCode Para where
    pfSigGen (Para x y z) = "struct __attribute__((packed)) " ++ x ++ "_para {\n" ++ vL ++ "};\n"
        where vL = "__u32 key;\n" ++ pfSigGen z
    pfCodeGen (Para x y z) = x
    pfGetMacro (Para x y z) = "P_" ++ map toUpper x ++ "_SIZE"
    pfMacroGen (Para x y z) = "#define P_" ++ map toUpper x ++ "_SIZE "
                              ++ show (4 + sizeFix z) ++ "\n"
    pfExtractGen (Para x y z) = "case " ++ show y ++ ":\n"
	                            ++ "if(skb->len<" ++ k ++ ") goto drop;\n"
								++ x ++ "=(void*)skb->data;\n" ++ "skb_pull(skb_in,"
								++ k ++ ");\n" ++ subFixValueCheck x z ++ "break;\n"
		where k = pfGetMacro (Para x y z)
    pfLocalGen (Para x y z) = "struct " ++ x ++ "_para* " ++ x ++ "=NULL;\n"
    pfConstructLocalGen x = pfLocalGen x
    pfConstructExtractGen (Para x y z) = x ++ "=(void*)skb_put(skb_out," ++ pfGetMacro (Para x y z) ++ ");\n"

-- Generate channel search functions
genChanSearchFunction :: Para -> String
genChanSearchFunction x = "struct " ++ protoName ++ "_chan* " ++ "_get_chan_by_" ++ pfCodeGen x
                          ++ "(struct " ++ protoName ++ "_conn* pconn, __u32 val){\n"
						  ++ "struct " ++ protoName ++ "_chan* pchan=NULL;\n"
                          ++ "list_for_each_entry(pchan, &pconn->chan_list, list){\n"
						  ++ "if(pchan->" ++ pfCodeGen x ++ "==val) return pchan;\n}\n"
						  ++ "return NULL;\n"
						  ++ "}\n"
                          ++ "struct " ++ protoName ++ "_chan* " ++ "get_chan_by_" ++ pfCodeGen x
                          ++ "(struct " ++ protoName ++ "_conn* pconn, __u32 val){\n"
						  ++ "struct " ++ protoName ++ "_chan* pchan=NULL;\n"
						  ++ "mutex_lock(pconn->chan_lock)"
						  ++ "pchan=_get_chan_by_" ++ pfCodeGen x ++ "(pconn, val);\n"
						  ++ "if(pchan) lock_chan_nesting(pchan);\n"
						  ++ "mutex_unlock(pconn->chan_lock);\n"
						  ++ "return pchan;\n"
						  ++ "}\n"

instance PfEmit Para where
    pfEmitMacro x = pfMacroGen x
    pfEmitDeclare x  = pfSigGen x
    pfEmitBlock x = genChanSearchFunction x

-- Define parameter list
data Plist = Plist { namePlist :: String
                   , maxSizeOfList :: Int
                   , paraCandidate :: [Para] -- Candidate parameters in a Plist
		           }
instance PfCode Plist where
    pfCodeGen (Plist x y z) = x
--    pfGetMacro (Plist x y z) = "MAX_PL_" ++ map toUpper x ++ "_SIZE"
--    pfMacroGen (Plist x y z) = "#define MAX_PL_" ++ map toUpper x ++ "_SIZE "
--                               ++ show (y * maximum (map paraGetBodySize z))
    pfExtractGen (Plist x y z) = "if(skb->len<=4) goto drop;\n" ++ "key = *((__u32*)skb->data);\n"
	                             ++ "switch(key){\n" ++ concat (map pfExtractGen z)
								 ++ "default:\nbreak;\n}\n"
    pfLocalGen (Plist x y z) = "__u32 key;\n" ++ "int count_in=0;\n" ++ concat (map pfLocalGen z)
    pfConstructLocalGen (Plist x y z) = "__u32 key;\n" ++ "int count_out=0;\n" ++ concat (map pfConstructLocalGen z)
    pfConstructExtractGen (Plist x y z) = ""

-- Define channel data structure
-- It holds a group of parameters
data Chan = Chan { paraChan :: [Para]
                 }
instance PfCode Chan where
    pfCodeGen x = protoName ++ "_chan"
    pfSigGen x = "struct " ++ pfCodeGen x ++ "{\n" ++ vL ++ "};\n"
        where vL = concat (map paraDeclareInStruct (paraChan x))

instance PfEmit Chan where
    pfEmitDeclare x = pfSigGen x

-- Define connection data structure shared by channels
-- It holds a group of parameters
data Conn = Conn { paraConn :: [Para]
                 }
instance PfCode Conn where
    pfCodeGen x = protoName ++ "_conn"
    pfSigGen x = "struct " ++ pfCodeGen x ++ "{\n" ++ vL ++ "};\n"
        where vL = concat (map paraDeclareInStruct (paraConn x))

instance PfEmit Conn where
    pfEmitDeclare x = pfSigGen x

-- Define expressions. Currently, ProFactory only supports integers, booleans and fixed-sized
-- fields in arithmetic expressions. Other types would be supported later.
data PfExpr = EmptyExpr -- An empty expression
            | DeliverExpr -- Deliver the current data in skb buffer
	        | ConstBoolExpr Bool -- A constant boolean
            | ConstIntExpr Int -- A constant integer
	        | FixExpr Fix -- A fixed-sized field
            | HdrExpr Hdr -- A header field
	        | ParaExpr Para -- A parameter
			| FixSeqExpr FixSeq -- A sequence of fixed-sized fields
            | UnaryExpr { uOp :: Uop
                        , uExpr :: PfExpr
                        } -- Unary expression
	        | BinaryExpr { bLeft :: PfExpr
                         , bOp :: Bop
                         , bRight :: PfExpr
                         } -- Binary expression
            | PriorExpr PfExpr -- (PfExpr)
			| SetChanParaExpr { paraChanSet :: Para
			                  , paraChanSetExpr :: PfExpr
							  } -- Set a channel parameter
			| SetConnParaExpr { paraConnSet :: Para
			                  , paraConnSetExpr :: PfExpr
							  } -- Set a connection parameter
			| FindChanByParaExpr { paraToFind :: Para
			                     , paraFindExpr :: PfExpr
								 } -- Find a channel by a parameter

instance PfCode PfExpr where
    pfCodeGen DeliverExpr = ""
    pfCodeGen (ConstBoolExpr x) | x == True = "true"
                                | x == False = "false"
    pfCodeGen (ConstIntExpr x) = show x
    pfCodeGen (FixExpr x) = pfCodeGen x
    pfCodeGen (HdrExpr x) = pfCodeGen x
    pfCodeGen (ParaExpr x) = pfCodeGen x
    pfCodeGen (FixSeqExpr x) = pfCodeGen x
    pfCodeGen (UnaryExpr x y) = pfCodeGen x ++ pfCodeGen y
    pfCodeGen (BinaryExpr x y z) = pfCodeGen x ++ pfCodeGen y ++ pfCodeGen z
    pfCodeGen (PriorExpr x) = "(" ++ pfCodeGen x ++ ")"
    pfCodeGen (SetChanParaExpr x y) = "pchan->" ++ pfCodeGen x ++ "=" ++ pfCodeGen y
    pfCodeGen (SetConnParaExpr x y) = "pconn->" ++ pfCodeGen x ++ "=" ++ pfCodeGen y
    pfCodeGen (FindChanByParaExpr x y) = "pchan=get_chan_by_" ++ pfCodeGen x ++ "(pconn, " ++ pfCodeGen y ++ ")"

-- Define state
data State = State { stateName :: String
                   , stateKey :: Int
                   , stateTimeout :: Int
                   }

instance PfCode State where
    pfGetMacro (State x y z) = "ST_" ++ map toUpper x
    pfMacroGen (State x y z) = "#define ST_" ++ map toUpper x ++ " " ++ show y
    pfCodeGen x = "pchan->state==" ++ pfGetMacro x

instance PfEmit State where
    pfEmitMacro x = pfMacroGen x

-- Define Statement
data PfStmt = EmptyStmt -- An empty statement
            | AssignStmt { assLeft :: PfExpr
                         , assRight :: PfExpr
                         } -- An assignment expression
            | ForStmt { forInitExpr :: PfExpr
                      , forCondExpr :: PfExpr
                      , forIterExpr :: PfExpr
                      , forStmt :: PfStmt
                      } -- For loop
	        | IteStmt { iteCondExpr :: PfExpr
                      , tStmt :: PfStmt
                      , eStmt :: PfStmt
                      } -- If-Then-Else
            | SeqStmt { preStmt :: PfStmt
                      , postStmt :: PfStmt
                      } -- Statement sequence
			| IterPlistStmt { iterPlist :: Plist
			                , iterBody :: PfStmt
							} -- Iterate a parameter list
            | AppendParaStmt { appendPlist :: Plist
			                 , appendPara :: Para
			                 , appendBody :: PfStmt
							 } -- Append a parameter to message body

instance PfCode PfStmt where
    pfCodeGen EmptyStmt = ""
    pfCodeGen (AssignStmt x y) = pfCodeGen x ++ "=" ++ pfCodeGen y ++ ";"
    pfCodeGen (ForStmt x y z k) = "for(" ++ pfCodeGen x ++ pfCodeGen y ++ pfCodeGen z ++ ") {\n"
                                  ++ pfCodeGen k ++ "\n}"
    pfCodeGen (IteStmt x y z) = "if(" ++ pfCodeGen x ++ ") {\n" ++ pfCodeGen y ++ "\n} else {\n"
                                ++ pfCodeGen z ++ "\n}"
    pfCodeGen (SeqStmt x y) = pfCodeGen x ++ "\n" ++ pfCodeGen y
    pfCodeGen (IterPlistStmt x y) = "while(skb_in->len>0&&count_in<" ++ show (maxSizeOfList x) ++ "){\n"
	                                ++ pfExtractGen x ++ pfCodeGen y
									++ "}\n"
    pfCodeGen (AppendParaStmt x y z) = "if(count_out<" ++ show (maxSizeOfList x) ++ "){\n"
	                                   ++ pfConstructExtractGen y ++ pfCodeGen z
									   ++ "}\n"

-- Define message format types
data MsgFmt = MsgFmtVar { msgFmtVarName :: String
                        , msgFmtVarBody :: Var
                        }
            | MsgFmtFixSeq { msgFmtFixSeqName :: String
                           , msgFmtFixSeqBody :: FixSeq
                           }
            | MsgFmtPlist { msgFmtPlistName :: String
                          , msgFmtPlistBody :: Plist
                          }
	        | MsgFmtLayer { msgFmtLayerName :: String
                          , msgFmtHdr :: Hdr
                          , msgFmtLayerBranch :: [(PfExpr, MsgFmt)] -- submessage branches 
                          } -- A layered message tree

getFmtName :: MsgFmt -> String
getFmtName (MsgFmtVar x y) = x
getFmtName (MsgFmtFixSeq x y) = x
getFmtName (MsgFmtPlist x y) = x
getFmtName (MsgFmtLayer x y z) = x

genFmtBaseBranch :: (PfExpr, MsgFmt) -> String
genFmtBaseBranch (x, y) = "(" ++ pfCodeGen x ++ ") return parse_" ++ getFmtName y
		                  ++ "(pconn, pchan, skb_in);\n"

genFmtIfBranch :: (PfExpr, MsgFmt) -> String
genFmtIfBranch (x, y) = "if" ++ genFmtBaseBranch (x, y)

genFmtElseIfBranch :: (PfExpr, MsgFmt) -> String
genFmtElseIfBranch (x, y) = "else if" ++ genFmtBaseBranch (x, y)

genFmtBranches :: [(PfExpr, MsgFmt)] -> String
genFmtBranches (x : xs) = genFmtIfBranch x ++ sBranches ++ "else goto drop;\n"
    where
        sBranches | length xs == 0 = ""
                  | otherwise = concat (map genFmtElseIfBranch xs)

-- Only define parser for layered messages, but other types are generated in receiving routines
-- For each of the other types, only a callsite is generated
instance PfCode MsgFmt where
    pfCodeGen (MsgFmtVar x y) = ""
    pfCodeGen (MsgFmtFixSeq x y) = ""
    pfCodeGen (MsgFmtPlist x y) = ""
    pfCodeGen (MsgFmtLayer x y z) = "static int parse_" ++ x
                                    ++ "(struct " ++ protoName ++"_conn* pconn,"
                                    ++ "struct " ++ protoName ++ "_chan* pchan,"
                                    ++ "struct sk_buff* skb_in) {\n"
                                    ++ pfLocalGen y
									++ pfExtractGen y
                                    ++ genFmtBranches z
                                    ++ "drop:\n" ++ "kfree_skb(skb_in);\n" ++ "return -1;\n}\n"
                                    ++ concat (map pfCodeGen (map snd z))

instance PfEmit MsgFmt where
    pfEmitBlock x = pfCodeGen x

-- Define messages as paths on the format tree
-- All the messages are unique, do not reuse any message
data Msg = MsgEmpty -- An empty message
         | MsgSymbol { msgSymbolFmt :: MsgFmt
		             , msgSymbolPath :: [Int]
                     }

getMsgInnerParser :: Msg -> String
getMsgInnerParser MsgEmpty = error("Cannot find a parser for an empty message")
getMsgInnerParser (MsgSymbol x []) = "parse_" ++ getFmtName x
getMsgInnerParser (MsgSymbol (MsgFmtLayer x y z) (k : rk)) =
	getMsgInnerParser (MsgSymbol (snd (z!!k)) rk)

instance PfCode Msg where
    pfCodeGen MsgEmpty = ""
    pfCodeGen (MsgSymbol x y) = getFmtName x
-- pfExtractGen and pfLocalGen are for incoming message parsing, where MsgEmpty is invalid
    pfExtractGen MsgEmpty = error("Cannot extract a message body base for an empty message")
    pfExtractGen (MsgSymbol (MsgFmtVar x y) []) = pfExtractGen y
    pfExtractGen (MsgSymbol (MsgFmtFixSeq x y) []) = pfExtractGen y
    pfExtractGen (MsgSymbol (MsgFmtPlist x y) []) = "" -- Plist should be extracted in a loop but not a generic extraction
    pfExtractGen (MsgSymbol (MsgFmtLayer x y z) (k : rk)) = pfExtractGen (MsgSymbol (snd (z!!k)) rk)
    pfLocalGen MsgEmpty = error("Cannot generate a local segment for an empty message")
    pfLocalGen (MsgSymbol (MsgFmtVar x y) []) = pfLocalGen y
    pfLocalGen (MsgSymbol (MsgFmtFixSeq x y) []) = pfLocalGen y
    pfLocalGen (MsgSymbol (MsgFmtPlist x y) []) = pfLocalGen y
    pfLocalGen (MsgSymbol (MsgFmtLayer x y z) (k : rk)) = pfLocalGen (MsgSymbol (snd (z!!k)) rk)
-- pfConstructLocalGen and pfConstructExtractGen are for outgoing message construction, where MsgEmpty is legitimate
    pfConstructLocalGen MsgEmpty = ""
    pfConstructLocalGen (MsgSymbol (MsgFmtVar x y) []) = pfConstructLocalGen y
    pfConstructLocalGen (MsgSymbol (MsgFmtFixSeq x y) []) = pfConstructLocalGen y
    pfConstructLocalGen (MsgSymbol (MsgFmtPlist x y) []) = pfConstructLocalGen y
    pfConstructLocalGen (MsgSymbol (MsgFmtLayer x y z) (k : rk)) = pfConstructLocalGen y ++ pfConstructLocalGen (MsgSymbol (snd (z!!k)) rk)
    pfConstructExtractGen MsgEmpty = ""
    pfConstructExtractGen (MsgSymbol (MsgFmtVar x y) []) = pfConstructExtractGen y
    pfConstructExtractGen (MsgSymbol (MsgFmtFixSeq x y) []) = pfConstructExtractGen y
    pfConstructExtractGen (MsgSymbol (MsgFmtPlist x y) []) = pfConstructExtractGen y
    pfConstructExtractGen (MsgSymbol (MsgFmtLayer x y z) (k : rk)) = pfConstructExtractGen y ++ pfConstructExtractGen (MsgSymbol (snd (z!!k)) rk)

-- A buffer is allocated the constant 1600 bytes
allocOutMsg :: Msg -> String
allocOutMsg MsgEmpty = ""
allocOutMsg (MsgSymbol x y) = "skb_out=" ++ protoFamilySkbAlloc

sendOutMsg :: Msg -> String
sendOutMsg MsgEmpty = ""
sendOutMsg (MsgSymbol x y) = protoName ++ "_do_send(pconn, pchan, skb_out);\n"

freeOutMsg :: Msg -> String
freeOutMsg MsgEmpty = ""
freeOutMsg (MsgSymbol x y) = "kfree_skb(skb_out);\n"
	
-- A message processing routine
data Routine = Routine { routineCondExpr :: PfExpr -- Pre-Condition
--                       routinePostCondExpr :: PfExpr -- Post-Condition
                       , routineFrom :: [State] -- Start state(s)
			           , routineTo :: State -- End state
			           , routineAction :: PfStmt -- Parsing
			           }

genCondExpr :: PfExpr -> String
genCondExpr EmptyExpr = ""
genCondExpr x = pfCodeGen x ++ "&&"

genRoutineConditionExpr :: PfExpr -> [State] -> String
genRoutineConditionExpr x y = "(" ++ genCondExpr x ++ intercalate "||" (map pfCodeGen y) ++ ")" 

genRoutineStateUpdate :: State -> String
genRoutineStateUpdate (State x y z) = "pchan->state=" ++ pfGetMacro (State x y z) ++ ";\n"
                                      ++ "schedule_delayed_work(pchan->timer," ++ show z ++ ");\n"

genRoutineBaseBranch :: Routine -> String
genRoutineBaseBranch (Routine x y z k) = genRoutineConditionExpr x y ++ "{\n"
                                       ++ genRoutineStateUpdate z ++ pfCodeGen k ++ "}\n"

genRoutineIfBranch :: Routine -> String
genRoutineIfBranch x = "if" ++ genRoutineBaseBranch x

genRoutineElseIfBranch :: Routine -> String
genRoutineElseIfBranch x = "else if" ++ genRoutineBaseBranch x

genRoutineBranches :: [Routine] -> String
genRoutineBranches (x : xs) = genRoutineIfBranch x ++ sBranches ++ "else goto drop;\n"
    where
        sBranches | length xs == 0 = ""
                  | otherwise = concat (map genRoutineElseIfBranch xs)

-- Currently, we cannot fully virtualize the complete set of hardware features.
-- Hence, we now use some routine procedures that are BT-L2CAP-specific to bridge the gap.
-- This is highly coupled with our use case
-- Note that it is a temporary workaround but it could be improved later by a full Bluetooth hardwere virtualization effort
-- For testing our use case, we just choose to hardcode this in l2cap_core.c
-- Again, this is a workaround for testing or framework assessment, also compatible with existing BT applications, but this temporary solution could be further improved through hardware feature genralization and virtualization
connectOneRoutine = "" 
connectTwoRoutine = ""
configOneRoutine = ""
configTwoRoutine = ""
closeOneRoutine = ""
closeTwoRoutine = ""

genFuncRoutine :: Int -> String
genFuncRoutine x | x == 1 = connectOneRoutine
                 | x == 2 = connectTwoRoutine
	         | x == 3 = configOneRoutine
	         | x == 4 = configTwoRoutine
	         | x == 5 = closeOneRoutine
	         | x == 6 = closeTwoRoutine

-- Define message receving actions
data Recv = Recv { recvMsg :: Msg -- Incoming message
                 , sendOut :: Msg -- Response message, maybe empty
                 , recvRoutineList :: [Routine]
                 , recvInterface :: Int
                 }

instance PfCode Recv where
    pfCodeGen (Recv x y z k) = "static int " ++ getMsgInnerParser x
                             ++ "(struct " ++ protoName ++"_conn* pconn,"
                             ++ "struct " ++ protoName ++ "_chan* pchan,"
                             ++ "struct sk_buff* skb_in) {\n"
							 ++ pfLocalGen x
							 ++ pfConstructLocalGen y
							 ++ pfExtractGen x
							 ++ allocOutMsg y
							 ++ pfConstructExtractGen y
						     ++ genRoutineBranches z
							 ++ sendOutMsg y
						     ++ "kfree_skb(skb_in);\n" ++ "return 0;\n"
						     ++ "drop:\n" ++ freeOutMsg y ++ "kfree_skb(skb_in);\n" ++ "return -1;\n"
                             ++ "}\n"

instance PfEmit Recv where
    pfEmitBlock x = pfCodeGen x
    pfEmitFunc (Recv x y z k) = "static int " ++ getMsgInnerParser x
                                ++ "(struct " ++ protoConn ++ "* pconn,"
                                ++ "struct " ++ protoChan ++ "* pchan,"
                                ++ "struct sk_buff* skb_in) {\n"
			        ++ pfLocalGen x
			        ++ pfConstructLocalGen y
				++ pfExtractGen x
				++ allocOutMsg y
				++ pfConstructExtractGen y
--				++ genRoutineBranches z
				++ genFuncRoutine k
				++ sendOutMsg y
				++ "kfree_skb(skb_in);\n" ++ "return 0;\n"
			        ++ "drop:\n" ++ freeOutMsg y ++ "kfree_skb(skb_in);\n" ++ "return -1;\n"
                                ++ "}\n"
  

-- Define message sending actions
data Send = Send { sendMsg :: Msg -- Outgoing message
		         , sendRoutineList :: [Routine]
		         }

instance PfCode Send where
    pfCodeGen (Send x y) = "static int send_" ++ pfCodeGen x
	                       ++ "(struct " ++ protoName ++"_conn* pconn,"
                           ++ "struct " ++ protoName ++ "_chan* pchan,"
                           ++ "void* data, __u32 data_len) {\n"
						   ++ pfConstructLocalGen x
						   ++ allocOutMsg x
						   ++ pfConstructExtractGen x
						   ++ genRoutineBranches y
						   ++ "memcpy((void*)skb_put(skb_out, data_len), data, data_len);\n"
						   ++ sendOutMsg x ++ "return 0;\n"
						   ++ "drop:\n" ++ freeOutMsg x ++ "return -1;\n"
						   ++ "}\n"

instance PfEmit Send where
    pfEmitBlock x = pfCodeGen x
