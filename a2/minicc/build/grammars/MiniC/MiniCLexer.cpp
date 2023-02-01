
#include <vector>
#include "Program.h"
#include "Declarations.h"
#include "Statements.h"
#include "Exprs.h"
#include "Terms.h"


// Generated from /home/tangzhen/csc488/a2/minicc/grammars/MiniC.g4 by ANTLR 4.11.1


#include "MiniCLexer.h"


using namespace antlr4;

using namespace minicc;


using namespace antlr4;

namespace {

struct MiniCLexerStaticData final {
  MiniCLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  MiniCLexerStaticData(const MiniCLexerStaticData&) = delete;
  MiniCLexerStaticData(MiniCLexerStaticData&&) = delete;
  MiniCLexerStaticData& operator=(const MiniCLexerStaticData&) = delete;
  MiniCLexerStaticData& operator=(MiniCLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag miniclexerLexerOnceFlag;
MiniCLexerStaticData *miniclexerLexerStaticData = nullptr;

void miniclexerLexerInitialize() {
  assert(miniclexerLexerStaticData == nullptr);
  auto staticData = std::make_unique<MiniCLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
      "T__9", "T__10", "T__11", "T__12", "T__13", "T__14", "T__15", "T__16", 
      "T__17", "T__18", "T__19", "T__20", "T__21", "T__22", "T__23", "T__24", 
      "T__25", "T__26", "T__27", "T__28", "T__29", "T__30", "T__31", "T__32", 
      "ID", "INT", "WS", "COMMENT"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'#include'", "'\"minicio.h\"'", "'('", "')'", "';'", "'{'", "'}'", 
      "'if'", "'else'", "'for'", "'while'", "'break'", "'return'", "'['", 
      "']'", "','", "'int'", "'bool'", "'void'", "'-'", "'*'", "'/'", "'+'", 
      "'true'", "'false'", "'!'", "'&&'", "'||'", "'=='", "'!='", "'<'", 
      "'>'", "'='"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "ID", "INT", "WS", "COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,37,231,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,3,1,3,1,4,1,4,1,5,1,5,1,6,1,6,
  	1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,10,1,10,1,10,1,10,1,
  	10,1,10,1,11,1,11,1,11,1,11,1,11,1,11,1,12,1,12,1,12,1,12,1,12,1,12,1,
  	12,1,13,1,13,1,14,1,14,1,15,1,15,1,16,1,16,1,16,1,16,1,17,1,17,1,17,1,
  	17,1,17,1,18,1,18,1,18,1,18,1,18,1,19,1,19,1,20,1,20,1,21,1,21,1,22,1,
  	22,1,23,1,23,1,23,1,23,1,23,1,24,1,24,1,24,1,24,1,24,1,24,1,25,1,25,1,
  	26,1,26,1,26,1,27,1,27,1,27,1,28,1,28,1,28,1,29,1,29,1,29,1,30,1,30,1,
  	31,1,31,1,32,1,32,1,33,1,33,5,33,199,8,33,10,33,12,33,202,9,33,1,34,1,
  	34,1,34,5,34,207,8,34,10,34,12,34,210,9,34,3,34,212,8,34,1,35,4,35,215,
  	8,35,11,35,12,35,216,1,35,1,35,1,36,1,36,1,36,1,36,5,36,225,8,36,10,36,
  	12,36,228,9,36,1,36,1,36,0,0,37,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,
  	9,19,10,21,11,23,12,25,13,27,14,29,15,31,16,33,17,35,18,37,19,39,20,41,
  	21,43,22,45,23,47,24,49,25,51,26,53,27,55,28,57,29,59,30,61,31,63,32,
  	65,33,67,34,69,35,71,36,73,37,1,0,7,2,0,65,90,97,122,4,0,48,57,65,90,
  	95,95,97,122,1,0,48,48,1,0,49,57,1,0,48,57,3,0,9,10,13,13,32,32,2,0,10,
  	10,13,13,235,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,
  	0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,
  	0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,
  	1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,
  	0,0,0,43,1,0,0,0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,
  	0,53,1,0,0,0,0,55,1,0,0,0,0,57,1,0,0,0,0,59,1,0,0,0,0,61,1,0,0,0,0,63,
  	1,0,0,0,0,65,1,0,0,0,0,67,1,0,0,0,0,69,1,0,0,0,0,71,1,0,0,0,0,73,1,0,
  	0,0,1,75,1,0,0,0,3,84,1,0,0,0,5,96,1,0,0,0,7,98,1,0,0,0,9,100,1,0,0,0,
  	11,102,1,0,0,0,13,104,1,0,0,0,15,106,1,0,0,0,17,109,1,0,0,0,19,114,1,
  	0,0,0,21,118,1,0,0,0,23,124,1,0,0,0,25,130,1,0,0,0,27,137,1,0,0,0,29,
  	139,1,0,0,0,31,141,1,0,0,0,33,143,1,0,0,0,35,147,1,0,0,0,37,152,1,0,0,
  	0,39,157,1,0,0,0,41,159,1,0,0,0,43,161,1,0,0,0,45,163,1,0,0,0,47,165,
  	1,0,0,0,49,170,1,0,0,0,51,176,1,0,0,0,53,178,1,0,0,0,55,181,1,0,0,0,57,
  	184,1,0,0,0,59,187,1,0,0,0,61,190,1,0,0,0,63,192,1,0,0,0,65,194,1,0,0,
  	0,67,196,1,0,0,0,69,211,1,0,0,0,71,214,1,0,0,0,73,220,1,0,0,0,75,76,5,
  	35,0,0,76,77,5,105,0,0,77,78,5,110,0,0,78,79,5,99,0,0,79,80,5,108,0,0,
  	80,81,5,117,0,0,81,82,5,100,0,0,82,83,5,101,0,0,83,2,1,0,0,0,84,85,5,
  	34,0,0,85,86,5,109,0,0,86,87,5,105,0,0,87,88,5,110,0,0,88,89,5,105,0,
  	0,89,90,5,99,0,0,90,91,5,105,0,0,91,92,5,111,0,0,92,93,5,46,0,0,93,94,
  	5,104,0,0,94,95,5,34,0,0,95,4,1,0,0,0,96,97,5,40,0,0,97,6,1,0,0,0,98,
  	99,5,41,0,0,99,8,1,0,0,0,100,101,5,59,0,0,101,10,1,0,0,0,102,103,5,123,
  	0,0,103,12,1,0,0,0,104,105,5,125,0,0,105,14,1,0,0,0,106,107,5,105,0,0,
  	107,108,5,102,0,0,108,16,1,0,0,0,109,110,5,101,0,0,110,111,5,108,0,0,
  	111,112,5,115,0,0,112,113,5,101,0,0,113,18,1,0,0,0,114,115,5,102,0,0,
  	115,116,5,111,0,0,116,117,5,114,0,0,117,20,1,0,0,0,118,119,5,119,0,0,
  	119,120,5,104,0,0,120,121,5,105,0,0,121,122,5,108,0,0,122,123,5,101,0,
  	0,123,22,1,0,0,0,124,125,5,98,0,0,125,126,5,114,0,0,126,127,5,101,0,0,
  	127,128,5,97,0,0,128,129,5,107,0,0,129,24,1,0,0,0,130,131,5,114,0,0,131,
  	132,5,101,0,0,132,133,5,116,0,0,133,134,5,117,0,0,134,135,5,114,0,0,135,
  	136,5,110,0,0,136,26,1,0,0,0,137,138,5,91,0,0,138,28,1,0,0,0,139,140,
  	5,93,0,0,140,30,1,0,0,0,141,142,5,44,0,0,142,32,1,0,0,0,143,144,5,105,
  	0,0,144,145,5,110,0,0,145,146,5,116,0,0,146,34,1,0,0,0,147,148,5,98,0,
  	0,148,149,5,111,0,0,149,150,5,111,0,0,150,151,5,108,0,0,151,36,1,0,0,
  	0,152,153,5,118,0,0,153,154,5,111,0,0,154,155,5,105,0,0,155,156,5,100,
  	0,0,156,38,1,0,0,0,157,158,5,45,0,0,158,40,1,0,0,0,159,160,5,42,0,0,160,
  	42,1,0,0,0,161,162,5,47,0,0,162,44,1,0,0,0,163,164,5,43,0,0,164,46,1,
  	0,0,0,165,166,5,116,0,0,166,167,5,114,0,0,167,168,5,117,0,0,168,169,5,
  	101,0,0,169,48,1,0,0,0,170,171,5,102,0,0,171,172,5,97,0,0,172,173,5,108,
  	0,0,173,174,5,115,0,0,174,175,5,101,0,0,175,50,1,0,0,0,176,177,5,33,0,
  	0,177,52,1,0,0,0,178,179,5,38,0,0,179,180,5,38,0,0,180,54,1,0,0,0,181,
  	182,5,124,0,0,182,183,5,124,0,0,183,56,1,0,0,0,184,185,5,61,0,0,185,186,
  	5,61,0,0,186,58,1,0,0,0,187,188,5,33,0,0,188,189,5,61,0,0,189,60,1,0,
  	0,0,190,191,5,60,0,0,191,62,1,0,0,0,192,193,5,62,0,0,193,64,1,0,0,0,194,
  	195,5,61,0,0,195,66,1,0,0,0,196,200,7,0,0,0,197,199,7,1,0,0,198,197,1,
  	0,0,0,199,202,1,0,0,0,200,198,1,0,0,0,200,201,1,0,0,0,201,68,1,0,0,0,
  	202,200,1,0,0,0,203,212,7,2,0,0,204,208,7,3,0,0,205,207,7,4,0,0,206,205,
  	1,0,0,0,207,210,1,0,0,0,208,206,1,0,0,0,208,209,1,0,0,0,209,212,1,0,0,
  	0,210,208,1,0,0,0,211,203,1,0,0,0,211,204,1,0,0,0,212,70,1,0,0,0,213,
  	215,7,5,0,0,214,213,1,0,0,0,215,216,1,0,0,0,216,214,1,0,0,0,216,217,1,
  	0,0,0,217,218,1,0,0,0,218,219,6,35,0,0,219,72,1,0,0,0,220,221,5,47,0,
  	0,221,222,5,47,0,0,222,226,1,0,0,0,223,225,8,6,0,0,224,223,1,0,0,0,225,
  	228,1,0,0,0,226,224,1,0,0,0,226,227,1,0,0,0,227,229,1,0,0,0,228,226,1,
  	0,0,0,229,230,6,36,0,0,230,74,1,0,0,0,6,0,200,208,211,216,226,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  miniclexerLexerStaticData = staticData.release();
}

}

MiniCLexer::MiniCLexer(CharStream *input) : Lexer(input) {
  MiniCLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *miniclexerLexerStaticData->atn, miniclexerLexerStaticData->decisionToDFA, miniclexerLexerStaticData->sharedContextCache);
}

MiniCLexer::~MiniCLexer() {
  delete _interpreter;
}

std::string MiniCLexer::getGrammarFileName() const {
  return "MiniC.g4";
}

const std::vector<std::string>& MiniCLexer::getRuleNames() const {
  return miniclexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& MiniCLexer::getChannelNames() const {
  return miniclexerLexerStaticData->channelNames;
}

const std::vector<std::string>& MiniCLexer::getModeNames() const {
  return miniclexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& MiniCLexer::getVocabulary() const {
  return miniclexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView MiniCLexer::getSerializedATN() const {
  return miniclexerLexerStaticData->serializedATN;
}

const atn::ATN& MiniCLexer::getATN() const {
  return *miniclexerLexerStaticData->atn;
}




void MiniCLexer::initialize() {
  ::antlr4::internal::call_once(miniclexerLexerOnceFlag, miniclexerLexerInitialize);
}