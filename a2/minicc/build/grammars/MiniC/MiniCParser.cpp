
#include <vector>
#include "Program.h"
#include "Declarations.h"
#include "Statements.h"
#include "Exprs.h"
#include "Terms.h"


// Generated from /home/tangzhen/csc488/a2/minicc/grammars/MiniC.g4 by ANTLR 4.11.1


#include "MiniCListener.h"
#include "MiniCVisitor.h"

#include "MiniCParser.h"


using namespace antlrcpp;
using namespace minicc;

using namespace antlr4;

namespace {

struct MiniCParserStaticData final {
  MiniCParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  MiniCParserStaticData(const MiniCParserStaticData&) = delete;
  MiniCParserStaticData(MiniCParserStaticData&&) = delete;
  MiniCParserStaticData& operator=(const MiniCParserStaticData&) = delete;
  MiniCParserStaticData& operator=(MiniCParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag minicParserOnceFlag;
MiniCParserStaticData *minicParserStaticData = nullptr;

void minicParserInitialize() {
  assert(minicParserStaticData == nullptr);
  auto staticData = std::make_unique<MiniCParserStaticData>(
    std::vector<std::string>{
      "prog", "preamble", "decl", "vardecl", "scope", "stmt", "stmt_list", 
      "varlist", "varlistentry", "vartype", "rettype", "parameters", "parameterlist", 
      "parameterentry", "expropt", "expr", "var", "arguments", "argumentlist", 
      "varname", "funcname", "parametername"
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
  	4,1,37,304,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,1,0,1,0,1,0,1,1,1,1,1,1,3,1,51,8,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,
  	1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,69,8,2,1,2,1,2,4,2,73,8,2,11,2,12,
  	2,74,5,2,77,8,2,10,2,12,2,80,9,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,4,3,89,8,
  	3,11,3,12,3,90,5,3,93,8,3,10,3,12,3,96,9,3,1,4,1,4,1,4,1,4,1,4,1,4,1,
  	4,1,4,1,4,1,4,1,4,3,4,109,8,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,
  	1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,
  	5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,3,5,153,8,5,
  	1,6,4,6,156,8,6,11,6,12,6,157,1,7,1,7,1,7,1,7,1,7,1,7,1,7,3,7,167,8,7,
  	1,7,1,7,1,7,5,7,172,8,7,10,7,12,7,175,9,7,1,8,1,8,1,9,1,9,1,10,1,10,3,
  	10,183,8,10,1,11,1,11,3,11,187,8,11,1,12,1,12,1,12,1,12,1,12,1,12,1,12,
  	5,12,196,8,12,10,12,12,12,199,9,12,1,13,1,13,1,14,1,14,3,14,205,8,14,
  	1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,
  	1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,3,15,230,8,15,1,15,1,15,
  	1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,
  	1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,
  	1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,5,15,270,8,15,10,15,12,15,273,
  	9,15,1,16,1,16,1,16,1,16,1,16,1,16,3,16,281,8,16,1,17,1,17,3,17,285,8,
  	17,1,18,1,18,1,18,1,18,1,18,1,18,5,18,293,8,18,10,18,12,18,296,9,18,1,
  	19,1,19,1,20,1,20,1,21,1,21,1,21,0,6,4,6,14,24,30,36,22,0,2,4,6,8,10,
  	12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,0,1,1,0,17,18,329,0,44,
  	1,0,0,0,2,50,1,0,0,0,4,68,1,0,0,0,6,81,1,0,0,0,8,108,1,0,0,0,10,152,1,
  	0,0,0,12,155,1,0,0,0,14,166,1,0,0,0,16,176,1,0,0,0,18,178,1,0,0,0,20,
  	182,1,0,0,0,22,186,1,0,0,0,24,188,1,0,0,0,26,200,1,0,0,0,28,204,1,0,0,
  	0,30,229,1,0,0,0,32,280,1,0,0,0,34,284,1,0,0,0,36,286,1,0,0,0,38,297,
  	1,0,0,0,40,299,1,0,0,0,42,301,1,0,0,0,44,45,3,2,1,0,45,46,3,4,2,0,46,
  	1,1,0,0,0,47,48,5,1,0,0,48,51,5,2,0,0,49,51,1,0,0,0,50,47,1,0,0,0,50,
  	49,1,0,0,0,51,3,1,0,0,0,52,53,6,2,-1,0,53,69,3,6,3,0,54,55,3,20,10,0,
  	55,56,3,40,20,0,56,57,5,3,0,0,57,58,3,22,11,0,58,59,5,4,0,0,59,60,3,8,
  	4,0,60,69,1,0,0,0,61,62,3,20,10,0,62,63,3,40,20,0,63,64,5,3,0,0,64,65,
  	3,22,11,0,65,66,5,4,0,0,66,67,5,5,0,0,67,69,1,0,0,0,68,52,1,0,0,0,68,
  	54,1,0,0,0,68,61,1,0,0,0,69,78,1,0,0,0,70,72,10,1,0,0,71,73,3,4,2,0,72,
  	71,1,0,0,0,73,74,1,0,0,0,74,72,1,0,0,0,74,75,1,0,0,0,75,77,1,0,0,0,76,
  	70,1,0,0,0,77,80,1,0,0,0,78,76,1,0,0,0,78,79,1,0,0,0,79,5,1,0,0,0,80,
  	78,1,0,0,0,81,82,6,3,-1,0,82,83,3,18,9,0,83,84,3,14,7,0,84,85,5,5,0,0,
  	85,94,1,0,0,0,86,88,10,1,0,0,87,89,3,6,3,0,88,87,1,0,0,0,89,90,1,0,0,
  	0,90,88,1,0,0,0,90,91,1,0,0,0,91,93,1,0,0,0,92,86,1,0,0,0,93,96,1,0,0,
  	0,94,92,1,0,0,0,94,95,1,0,0,0,95,7,1,0,0,0,96,94,1,0,0,0,97,98,5,6,0,
  	0,98,99,3,6,3,0,99,100,3,12,6,0,100,101,5,7,0,0,101,109,1,0,0,0,102,103,
  	5,6,0,0,103,104,3,12,6,0,104,105,5,7,0,0,105,109,1,0,0,0,106,107,5,6,
  	0,0,107,109,5,7,0,0,108,97,1,0,0,0,108,102,1,0,0,0,108,106,1,0,0,0,109,
  	9,1,0,0,0,110,111,3,30,15,0,111,112,5,5,0,0,112,153,1,0,0,0,113,114,5,
  	8,0,0,114,115,5,3,0,0,115,116,3,30,15,0,116,117,5,4,0,0,117,118,3,10,
  	5,0,118,153,1,0,0,0,119,120,5,8,0,0,120,121,5,3,0,0,121,122,3,30,15,0,
  	122,123,5,4,0,0,123,124,3,10,5,0,124,125,5,9,0,0,125,126,3,10,5,0,126,
  	153,1,0,0,0,127,128,5,10,0,0,128,129,5,3,0,0,129,130,3,28,14,0,130,131,
  	5,5,0,0,131,132,3,28,14,0,132,133,5,5,0,0,133,134,3,28,14,0,134,135,5,
  	4,0,0,135,136,3,10,5,0,136,153,1,0,0,0,137,138,5,11,0,0,138,139,5,3,0,
  	0,139,140,3,30,15,0,140,141,5,4,0,0,141,142,3,10,5,0,142,153,1,0,0,0,
  	143,144,5,12,0,0,144,153,5,5,0,0,145,146,5,13,0,0,146,153,5,5,0,0,147,
  	148,5,13,0,0,148,149,3,30,15,0,149,150,5,5,0,0,150,153,1,0,0,0,151,153,
  	3,8,4,0,152,110,1,0,0,0,152,113,1,0,0,0,152,119,1,0,0,0,152,127,1,0,0,
  	0,152,137,1,0,0,0,152,143,1,0,0,0,152,145,1,0,0,0,152,147,1,0,0,0,152,
  	151,1,0,0,0,153,11,1,0,0,0,154,156,3,10,5,0,155,154,1,0,0,0,156,157,1,
  	0,0,0,157,155,1,0,0,0,157,158,1,0,0,0,158,13,1,0,0,0,159,160,6,7,-1,0,
  	160,167,3,38,19,0,161,162,3,38,19,0,162,163,5,14,0,0,163,164,5,35,0,0,
  	164,165,5,15,0,0,165,167,1,0,0,0,166,159,1,0,0,0,166,161,1,0,0,0,167,
  	173,1,0,0,0,168,169,10,1,0,0,169,170,5,16,0,0,170,172,3,14,7,2,171,168,
  	1,0,0,0,172,175,1,0,0,0,173,171,1,0,0,0,173,174,1,0,0,0,174,15,1,0,0,
  	0,175,173,1,0,0,0,176,177,1,0,0,0,177,17,1,0,0,0,178,179,7,0,0,0,179,
  	19,1,0,0,0,180,183,5,19,0,0,181,183,3,18,9,0,182,180,1,0,0,0,182,181,
  	1,0,0,0,183,21,1,0,0,0,184,187,1,0,0,0,185,187,3,24,12,0,186,184,1,0,
  	0,0,186,185,1,0,0,0,187,23,1,0,0,0,188,189,6,12,-1,0,189,190,3,18,9,0,
  	190,191,3,42,21,0,191,197,1,0,0,0,192,193,10,1,0,0,193,194,5,16,0,0,194,
  	196,3,24,12,2,195,192,1,0,0,0,196,199,1,0,0,0,197,195,1,0,0,0,197,198,
  	1,0,0,0,198,25,1,0,0,0,199,197,1,0,0,0,200,201,1,0,0,0,201,27,1,0,0,0,
  	202,205,3,30,15,0,203,205,1,0,0,0,204,202,1,0,0,0,204,203,1,0,0,0,205,
  	29,1,0,0,0,206,207,6,15,-1,0,207,230,5,35,0,0,208,209,5,20,0,0,209,230,
  	3,30,15,21,210,230,5,24,0,0,211,230,5,25,0,0,212,213,5,26,0,0,213,230,
  	3,30,15,14,214,215,5,3,0,0,215,216,3,30,15,0,216,217,5,4,0,0,217,230,
  	1,0,0,0,218,230,3,32,16,0,219,220,3,40,20,0,220,221,5,3,0,0,221,222,3,
  	34,17,0,222,223,5,4,0,0,223,230,1,0,0,0,224,225,3,32,16,0,225,226,5,33,
  	0,0,226,227,3,30,15,2,227,230,1,0,0,0,228,230,3,42,21,0,229,206,1,0,0,
  	0,229,208,1,0,0,0,229,210,1,0,0,0,229,211,1,0,0,0,229,212,1,0,0,0,229,
  	214,1,0,0,0,229,218,1,0,0,0,229,219,1,0,0,0,229,224,1,0,0,0,229,228,1,
  	0,0,0,230,271,1,0,0,0,231,232,10,20,0,0,232,233,5,21,0,0,233,270,3,30,
  	15,21,234,235,10,19,0,0,235,236,5,22,0,0,236,270,3,30,15,20,237,238,10,
  	18,0,0,238,239,5,23,0,0,239,270,3,30,15,19,240,241,10,17,0,0,241,242,
  	5,20,0,0,242,270,3,30,15,18,243,244,10,13,0,0,244,245,5,27,0,0,245,270,
  	3,30,15,14,246,247,10,12,0,0,247,248,5,28,0,0,248,270,3,30,15,13,249,
  	250,10,11,0,0,250,251,5,29,0,0,251,270,3,30,15,12,252,253,10,10,0,0,253,
  	254,5,30,0,0,254,270,3,30,15,11,255,256,10,9,0,0,256,257,5,31,0,0,257,
  	270,3,30,15,10,258,259,10,8,0,0,259,260,5,32,0,0,260,270,3,30,15,9,261,
  	262,10,7,0,0,262,263,5,31,0,0,263,264,5,33,0,0,264,270,3,30,15,8,265,
  	266,10,6,0,0,266,267,5,32,0,0,267,268,5,33,0,0,268,270,3,30,15,7,269,
  	231,1,0,0,0,269,234,1,0,0,0,269,237,1,0,0,0,269,240,1,0,0,0,269,243,1,
  	0,0,0,269,246,1,0,0,0,269,249,1,0,0,0,269,252,1,0,0,0,269,255,1,0,0,0,
  	269,258,1,0,0,0,269,261,1,0,0,0,269,265,1,0,0,0,270,273,1,0,0,0,271,269,
  	1,0,0,0,271,272,1,0,0,0,272,31,1,0,0,0,273,271,1,0,0,0,274,281,3,38,19,
  	0,275,276,3,38,19,0,276,277,5,14,0,0,277,278,3,30,15,0,278,279,5,15,0,
  	0,279,281,1,0,0,0,280,274,1,0,0,0,280,275,1,0,0,0,281,33,1,0,0,0,282,
  	285,1,0,0,0,283,285,3,36,18,0,284,282,1,0,0,0,284,283,1,0,0,0,285,35,
  	1,0,0,0,286,287,6,18,-1,0,287,288,3,30,15,0,288,294,1,0,0,0,289,290,10,
  	1,0,0,290,291,5,16,0,0,291,293,3,36,18,2,292,289,1,0,0,0,293,296,1,0,
  	0,0,294,292,1,0,0,0,294,295,1,0,0,0,295,37,1,0,0,0,296,294,1,0,0,0,297,
  	298,5,34,0,0,298,39,1,0,0,0,299,300,5,34,0,0,300,41,1,0,0,0,301,302,5,
  	34,0,0,302,43,1,0,0,0,21,50,68,74,78,90,94,108,152,157,166,173,182,186,
  	197,204,229,269,271,280,284,294
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  minicParserStaticData = staticData.release();
}

}

MiniCParser::MiniCParser(TokenStream *input) : MiniCParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

MiniCParser::MiniCParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  MiniCParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *minicParserStaticData->atn, minicParserStaticData->decisionToDFA, minicParserStaticData->sharedContextCache, options);
}

MiniCParser::~MiniCParser() {
  delete _interpreter;
}

const atn::ATN& MiniCParser::getATN() const {
  return *minicParserStaticData->atn;
}

std::string MiniCParser::getGrammarFileName() const {
  return "MiniC.g4";
}

const std::vector<std::string>& MiniCParser::getRuleNames() const {
  return minicParserStaticData->ruleNames;
}

const dfa::Vocabulary& MiniCParser::getVocabulary() const {
  return minicParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView MiniCParser::getSerializedATN() const {
  return minicParserStaticData->serializedATN;
}


//----------------- ProgContext ------------------------------------------------------------------

MiniCParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::PreambleContext* MiniCParser::ProgContext::preamble() {
  return getRuleContext<MiniCParser::PreambleContext>(0);
}

MiniCParser::DeclContext* MiniCParser::ProgContext::decl() {
  return getRuleContext<MiniCParser::DeclContext>(0);
}


size_t MiniCParser::ProgContext::getRuleIndex() const {
  return MiniCParser::RuleProg;
}

void MiniCParser::ProgContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProg(this);
}

void MiniCParser::ProgContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProg(this);
}


std::any MiniCParser::ProgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitProg(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::ProgContext* MiniCParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 0, MiniCParser::RuleProg);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(44);
    preamble();
    setState(45);
    decl(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PreambleContext ------------------------------------------------------------------

MiniCParser::PreambleContext::PreambleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MiniCParser::PreambleContext::getRuleIndex() const {
  return MiniCParser::RulePreamble;
}

void MiniCParser::PreambleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPreamble(this);
}

void MiniCParser::PreambleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPreamble(this);
}


std::any MiniCParser::PreambleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitPreamble(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::PreambleContext* MiniCParser::preamble() {
  PreambleContext *_localctx = _tracker.createInstance<PreambleContext>(_ctx, getState());
  enterRule(_localctx, 2, MiniCParser::RulePreamble);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(50);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MiniCParser::T__0: {
        enterOuterAlt(_localctx, 1);
        setState(47);
        match(MiniCParser::T__0);
        setState(48);
        match(MiniCParser::T__1);
        break;
      }

      case MiniCParser::T__16:
      case MiniCParser::T__17:
      case MiniCParser::T__18: {
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclContext ------------------------------------------------------------------

MiniCParser::DeclContext::DeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::VardeclContext* MiniCParser::DeclContext::vardecl() {
  return getRuleContext<MiniCParser::VardeclContext>(0);
}

MiniCParser::RettypeContext* MiniCParser::DeclContext::rettype() {
  return getRuleContext<MiniCParser::RettypeContext>(0);
}

MiniCParser::FuncnameContext* MiniCParser::DeclContext::funcname() {
  return getRuleContext<MiniCParser::FuncnameContext>(0);
}

MiniCParser::ParametersContext* MiniCParser::DeclContext::parameters() {
  return getRuleContext<MiniCParser::ParametersContext>(0);
}

MiniCParser::ScopeContext* MiniCParser::DeclContext::scope() {
  return getRuleContext<MiniCParser::ScopeContext>(0);
}

std::vector<MiniCParser::DeclContext *> MiniCParser::DeclContext::decl() {
  return getRuleContexts<MiniCParser::DeclContext>();
}

MiniCParser::DeclContext* MiniCParser::DeclContext::decl(size_t i) {
  return getRuleContext<MiniCParser::DeclContext>(i);
}


size_t MiniCParser::DeclContext::getRuleIndex() const {
  return MiniCParser::RuleDecl;
}

void MiniCParser::DeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDecl(this);
}

void MiniCParser::DeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDecl(this);
}


std::any MiniCParser::DeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitDecl(this);
  else
    return visitor->visitChildren(this);
}


MiniCParser::DeclContext* MiniCParser::decl() {
   return decl(0);
}

MiniCParser::DeclContext* MiniCParser::decl(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniCParser::DeclContext *_localctx = _tracker.createInstance<DeclContext>(_ctx, parentState);
  MiniCParser::DeclContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 4;
  enterRecursionRule(_localctx, 4, MiniCParser::RuleDecl, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(68);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      setState(53);
      vardecl(0);
      break;
    }

    case 2: {
      setState(54);
      rettype();
      setState(55);
      funcname();
      setState(56);
      match(MiniCParser::T__2);
      setState(57);
      parameters();
      setState(58);
      match(MiniCParser::T__3);
      setState(59);
      scope();
      break;
    }

    case 3: {
      setState(61);
      rettype();
      setState(62);
      funcname();
      setState(63);
      match(MiniCParser::T__2);
      setState(64);
      parameters();
      setState(65);
      match(MiniCParser::T__3);
      setState(66);
      match(MiniCParser::T__4);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(78);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<DeclContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleDecl);
        setState(70);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(72); 
        _errHandler->sync(this);
        alt = 1;
        do {
          switch (alt) {
            case 1: {
                  setState(71);
                  decl(0);
                  break;
                }

          default:
            throw NoViableAltException(this);
          }
          setState(74); 
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
        } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER); 
      }
      setState(80);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- VardeclContext ------------------------------------------------------------------

MiniCParser::VardeclContext::VardeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::VartypeContext* MiniCParser::VardeclContext::vartype() {
  return getRuleContext<MiniCParser::VartypeContext>(0);
}

MiniCParser::VarlistContext* MiniCParser::VardeclContext::varlist() {
  return getRuleContext<MiniCParser::VarlistContext>(0);
}

std::vector<MiniCParser::VardeclContext *> MiniCParser::VardeclContext::vardecl() {
  return getRuleContexts<MiniCParser::VardeclContext>();
}

MiniCParser::VardeclContext* MiniCParser::VardeclContext::vardecl(size_t i) {
  return getRuleContext<MiniCParser::VardeclContext>(i);
}


size_t MiniCParser::VardeclContext::getRuleIndex() const {
  return MiniCParser::RuleVardecl;
}

void MiniCParser::VardeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVardecl(this);
}

void MiniCParser::VardeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVardecl(this);
}


std::any MiniCParser::VardeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitVardecl(this);
  else
    return visitor->visitChildren(this);
}


MiniCParser::VardeclContext* MiniCParser::vardecl() {
   return vardecl(0);
}

MiniCParser::VardeclContext* MiniCParser::vardecl(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniCParser::VardeclContext *_localctx = _tracker.createInstance<VardeclContext>(_ctx, parentState);
  MiniCParser::VardeclContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 6;
  enterRecursionRule(_localctx, 6, MiniCParser::RuleVardecl, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(82);
    vartype();
    setState(83);
    varlist(0);
    setState(84);
    match(MiniCParser::T__4);
    _ctx->stop = _input->LT(-1);
    setState(94);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<VardeclContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleVardecl);
        setState(86);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(88); 
        _errHandler->sync(this);
        alt = 1;
        do {
          switch (alt) {
            case 1: {
                  setState(87);
                  vardecl(0);
                  break;
                }

          default:
            throw NoViableAltException(this);
          }
          setState(90); 
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
        } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER); 
      }
      setState(96);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ScopeContext ------------------------------------------------------------------

MiniCParser::ScopeContext::ScopeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::VardeclContext* MiniCParser::ScopeContext::vardecl() {
  return getRuleContext<MiniCParser::VardeclContext>(0);
}

MiniCParser::Stmt_listContext* MiniCParser::ScopeContext::stmt_list() {
  return getRuleContext<MiniCParser::Stmt_listContext>(0);
}


size_t MiniCParser::ScopeContext::getRuleIndex() const {
  return MiniCParser::RuleScope;
}

void MiniCParser::ScopeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterScope(this);
}

void MiniCParser::ScopeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitScope(this);
}


std::any MiniCParser::ScopeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitScope(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::ScopeContext* MiniCParser::scope() {
  ScopeContext *_localctx = _tracker.createInstance<ScopeContext>(_ctx, getState());
  enterRule(_localctx, 8, MiniCParser::RuleScope);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(108);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(97);
      match(MiniCParser::T__5);
      setState(98);
      vardecl(0);
      setState(99);
      stmt_list();
      setState(100);
      match(MiniCParser::T__6);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(102);
      match(MiniCParser::T__5);
      setState(103);
      stmt_list();
      setState(104);
      match(MiniCParser::T__6);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(106);
      match(MiniCParser::T__5);
      setState(107);
      match(MiniCParser::T__6);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

MiniCParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::ExprContext* MiniCParser::StmtContext::expr() {
  return getRuleContext<MiniCParser::ExprContext>(0);
}

std::vector<MiniCParser::StmtContext *> MiniCParser::StmtContext::stmt() {
  return getRuleContexts<MiniCParser::StmtContext>();
}

MiniCParser::StmtContext* MiniCParser::StmtContext::stmt(size_t i) {
  return getRuleContext<MiniCParser::StmtContext>(i);
}

std::vector<MiniCParser::ExproptContext *> MiniCParser::StmtContext::expropt() {
  return getRuleContexts<MiniCParser::ExproptContext>();
}

MiniCParser::ExproptContext* MiniCParser::StmtContext::expropt(size_t i) {
  return getRuleContext<MiniCParser::ExproptContext>(i);
}

MiniCParser::ScopeContext* MiniCParser::StmtContext::scope() {
  return getRuleContext<MiniCParser::ScopeContext>(0);
}


size_t MiniCParser::StmtContext::getRuleIndex() const {
  return MiniCParser::RuleStmt;
}

void MiniCParser::StmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmt(this);
}

void MiniCParser::StmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmt(this);
}


std::any MiniCParser::StmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitStmt(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::StmtContext* MiniCParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 10, MiniCParser::RuleStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(152);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(110);
      expr(0);
      setState(111);
      match(MiniCParser::T__4);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(113);
      match(MiniCParser::T__7);
      setState(114);
      match(MiniCParser::T__2);
      setState(115);
      expr(0);
      setState(116);
      match(MiniCParser::T__3);
      setState(117);
      stmt();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(119);
      match(MiniCParser::T__7);
      setState(120);
      match(MiniCParser::T__2);
      setState(121);
      expr(0);
      setState(122);
      match(MiniCParser::T__3);
      setState(123);
      stmt();
      setState(124);
      match(MiniCParser::T__8);
      setState(125);
      stmt();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(127);
      match(MiniCParser::T__9);
      setState(128);
      match(MiniCParser::T__2);
      setState(129);
      expropt();
      setState(130);
      match(MiniCParser::T__4);
      setState(131);
      expropt();
      setState(132);
      match(MiniCParser::T__4);
      setState(133);
      expropt();
      setState(134);
      match(MiniCParser::T__3);
      setState(135);
      stmt();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(137);
      match(MiniCParser::T__10);
      setState(138);
      match(MiniCParser::T__2);
      setState(139);
      expr(0);
      setState(140);
      match(MiniCParser::T__3);
      setState(141);
      stmt();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(143);
      match(MiniCParser::T__11);
      setState(144);
      match(MiniCParser::T__4);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(145);
      match(MiniCParser::T__12);
      setState(146);
      match(MiniCParser::T__4);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(147);
      match(MiniCParser::T__12);
      setState(148);
      expr(0);
      setState(149);
      match(MiniCParser::T__4);
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(151);
      scope();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Stmt_listContext ------------------------------------------------------------------

MiniCParser::Stmt_listContext::Stmt_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MiniCParser::StmtContext *> MiniCParser::Stmt_listContext::stmt() {
  return getRuleContexts<MiniCParser::StmtContext>();
}

MiniCParser::StmtContext* MiniCParser::Stmt_listContext::stmt(size_t i) {
  return getRuleContext<MiniCParser::StmtContext>(i);
}


size_t MiniCParser::Stmt_listContext::getRuleIndex() const {
  return MiniCParser::RuleStmt_list;
}

void MiniCParser::Stmt_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmt_list(this);
}

void MiniCParser::Stmt_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmt_list(this);
}


std::any MiniCParser::Stmt_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitStmt_list(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::Stmt_listContext* MiniCParser::stmt_list() {
  Stmt_listContext *_localctx = _tracker.createInstance<Stmt_listContext>(_ctx, getState());
  enterRule(_localctx, 12, MiniCParser::RuleStmt_list);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(155); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(154);
      stmt();
      setState(157); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 51658112328) != 0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarlistContext ------------------------------------------------------------------

MiniCParser::VarlistContext::VarlistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::VarnameContext* MiniCParser::VarlistContext::varname() {
  return getRuleContext<MiniCParser::VarnameContext>(0);
}

tree::TerminalNode* MiniCParser::VarlistContext::INT() {
  return getToken(MiniCParser::INT, 0);
}

std::vector<MiniCParser::VarlistContext *> MiniCParser::VarlistContext::varlist() {
  return getRuleContexts<MiniCParser::VarlistContext>();
}

MiniCParser::VarlistContext* MiniCParser::VarlistContext::varlist(size_t i) {
  return getRuleContext<MiniCParser::VarlistContext>(i);
}


size_t MiniCParser::VarlistContext::getRuleIndex() const {
  return MiniCParser::RuleVarlist;
}

void MiniCParser::VarlistContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarlist(this);
}

void MiniCParser::VarlistContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarlist(this);
}


std::any MiniCParser::VarlistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitVarlist(this);
  else
    return visitor->visitChildren(this);
}


MiniCParser::VarlistContext* MiniCParser::varlist() {
   return varlist(0);
}

MiniCParser::VarlistContext* MiniCParser::varlist(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniCParser::VarlistContext *_localctx = _tracker.createInstance<VarlistContext>(_ctx, parentState);
  MiniCParser::VarlistContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 14;
  enterRecursionRule(_localctx, 14, MiniCParser::RuleVarlist, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(166);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      setState(160);
      varname();
      break;
    }

    case 2: {
      setState(161);
      varname();
      setState(162);
      match(MiniCParser::T__13);
      setState(163);
      match(MiniCParser::INT);
      setState(164);
      match(MiniCParser::T__14);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(173);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<VarlistContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleVarlist);
        setState(168);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(169);
        match(MiniCParser::T__15);
        setState(170);
        varlist(2); 
      }
      setState(175);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- VarlistentryContext ------------------------------------------------------------------

MiniCParser::VarlistentryContext::VarlistentryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MiniCParser::VarlistentryContext::getRuleIndex() const {
  return MiniCParser::RuleVarlistentry;
}

void MiniCParser::VarlistentryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarlistentry(this);
}

void MiniCParser::VarlistentryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarlistentry(this);
}


std::any MiniCParser::VarlistentryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitVarlistentry(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::VarlistentryContext* MiniCParser::varlistentry() {
  VarlistentryContext *_localctx = _tracker.createInstance<VarlistentryContext>(_ctx, getState());
  enterRule(_localctx, 16, MiniCParser::RuleVarlistentry);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);

   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VartypeContext ------------------------------------------------------------------

MiniCParser::VartypeContext::VartypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MiniCParser::VartypeContext::getRuleIndex() const {
  return MiniCParser::RuleVartype;
}

void MiniCParser::VartypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVartype(this);
}

void MiniCParser::VartypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVartype(this);
}


std::any MiniCParser::VartypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitVartype(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::VartypeContext* MiniCParser::vartype() {
  VartypeContext *_localctx = _tracker.createInstance<VartypeContext>(_ctx, getState());
  enterRule(_localctx, 18, MiniCParser::RuleVartype);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(178);
    _la = _input->LA(1);
    if (!(_la == MiniCParser::T__16

    || _la == MiniCParser::T__17)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RettypeContext ------------------------------------------------------------------

MiniCParser::RettypeContext::RettypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::VartypeContext* MiniCParser::RettypeContext::vartype() {
  return getRuleContext<MiniCParser::VartypeContext>(0);
}


size_t MiniCParser::RettypeContext::getRuleIndex() const {
  return MiniCParser::RuleRettype;
}

void MiniCParser::RettypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRettype(this);
}

void MiniCParser::RettypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRettype(this);
}


std::any MiniCParser::RettypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitRettype(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::RettypeContext* MiniCParser::rettype() {
  RettypeContext *_localctx = _tracker.createInstance<RettypeContext>(_ctx, getState());
  enterRule(_localctx, 20, MiniCParser::RuleRettype);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(182);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MiniCParser::T__18: {
        enterOuterAlt(_localctx, 1);
        setState(180);
        match(MiniCParser::T__18);
        break;
      }

      case MiniCParser::T__16:
      case MiniCParser::T__17: {
        enterOuterAlt(_localctx, 2);
        setState(181);
        vartype();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParametersContext ------------------------------------------------------------------

MiniCParser::ParametersContext::ParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::ParameterlistContext* MiniCParser::ParametersContext::parameterlist() {
  return getRuleContext<MiniCParser::ParameterlistContext>(0);
}


size_t MiniCParser::ParametersContext::getRuleIndex() const {
  return MiniCParser::RuleParameters;
}

void MiniCParser::ParametersContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameters(this);
}

void MiniCParser::ParametersContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameters(this);
}


std::any MiniCParser::ParametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitParameters(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::ParametersContext* MiniCParser::parameters() {
  ParametersContext *_localctx = _tracker.createInstance<ParametersContext>(_ctx, getState());
  enterRule(_localctx, 22, MiniCParser::RuleParameters);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(186);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MiniCParser::T__3: {
        enterOuterAlt(_localctx, 1);

        break;
      }

      case MiniCParser::T__16:
      case MiniCParser::T__17: {
        enterOuterAlt(_localctx, 2);
        setState(185);
        parameterlist(0);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterlistContext ------------------------------------------------------------------

MiniCParser::ParameterlistContext::ParameterlistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::VartypeContext* MiniCParser::ParameterlistContext::vartype() {
  return getRuleContext<MiniCParser::VartypeContext>(0);
}

MiniCParser::ParameternameContext* MiniCParser::ParameterlistContext::parametername() {
  return getRuleContext<MiniCParser::ParameternameContext>(0);
}

std::vector<MiniCParser::ParameterlistContext *> MiniCParser::ParameterlistContext::parameterlist() {
  return getRuleContexts<MiniCParser::ParameterlistContext>();
}

MiniCParser::ParameterlistContext* MiniCParser::ParameterlistContext::parameterlist(size_t i) {
  return getRuleContext<MiniCParser::ParameterlistContext>(i);
}


size_t MiniCParser::ParameterlistContext::getRuleIndex() const {
  return MiniCParser::RuleParameterlist;
}

void MiniCParser::ParameterlistContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterlist(this);
}

void MiniCParser::ParameterlistContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterlist(this);
}


std::any MiniCParser::ParameterlistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitParameterlist(this);
  else
    return visitor->visitChildren(this);
}


MiniCParser::ParameterlistContext* MiniCParser::parameterlist() {
   return parameterlist(0);
}

MiniCParser::ParameterlistContext* MiniCParser::parameterlist(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniCParser::ParameterlistContext *_localctx = _tracker.createInstance<ParameterlistContext>(_ctx, parentState);
  MiniCParser::ParameterlistContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 24;
  enterRecursionRule(_localctx, 24, MiniCParser::RuleParameterlist, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(189);
    vartype();
    setState(190);
    parametername();
    _ctx->stop = _input->LT(-1);
    setState(197);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ParameterlistContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleParameterlist);
        setState(192);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(193);
        match(MiniCParser::T__15);
        setState(194);
        parameterlist(2); 
      }
      setState(199);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ParameterentryContext ------------------------------------------------------------------

MiniCParser::ParameterentryContext::ParameterentryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MiniCParser::ParameterentryContext::getRuleIndex() const {
  return MiniCParser::RuleParameterentry;
}

void MiniCParser::ParameterentryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterentry(this);
}

void MiniCParser::ParameterentryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterentry(this);
}


std::any MiniCParser::ParameterentryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitParameterentry(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::ParameterentryContext* MiniCParser::parameterentry() {
  ParameterentryContext *_localctx = _tracker.createInstance<ParameterentryContext>(_ctx, getState());
  enterRule(_localctx, 26, MiniCParser::RuleParameterentry);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);

   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExproptContext ------------------------------------------------------------------

MiniCParser::ExproptContext::ExproptContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::ExprContext* MiniCParser::ExproptContext::expr() {
  return getRuleContext<MiniCParser::ExprContext>(0);
}


size_t MiniCParser::ExproptContext::getRuleIndex() const {
  return MiniCParser::RuleExpropt;
}

void MiniCParser::ExproptContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpropt(this);
}

void MiniCParser::ExproptContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpropt(this);
}


std::any MiniCParser::ExproptContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitExpropt(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::ExproptContext* MiniCParser::expropt() {
  ExproptContext *_localctx = _tracker.createInstance<ExproptContext>(_ctx, getState());
  enterRule(_localctx, 28, MiniCParser::RuleExpropt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(204);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MiniCParser::T__2:
      case MiniCParser::T__19:
      case MiniCParser::T__23:
      case MiniCParser::T__24:
      case MiniCParser::T__25:
      case MiniCParser::ID:
      case MiniCParser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(202);
        expr(0);
        break;
      }

      case MiniCParser::T__3:
      case MiniCParser::T__4: {
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

MiniCParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniCParser::ExprContext::INT() {
  return getToken(MiniCParser::INT, 0);
}

std::vector<MiniCParser::ExprContext *> MiniCParser::ExprContext::expr() {
  return getRuleContexts<MiniCParser::ExprContext>();
}

MiniCParser::ExprContext* MiniCParser::ExprContext::expr(size_t i) {
  return getRuleContext<MiniCParser::ExprContext>(i);
}

MiniCParser::VarContext* MiniCParser::ExprContext::var() {
  return getRuleContext<MiniCParser::VarContext>(0);
}

MiniCParser::FuncnameContext* MiniCParser::ExprContext::funcname() {
  return getRuleContext<MiniCParser::FuncnameContext>(0);
}

MiniCParser::ArgumentsContext* MiniCParser::ExprContext::arguments() {
  return getRuleContext<MiniCParser::ArgumentsContext>(0);
}

MiniCParser::ParameternameContext* MiniCParser::ExprContext::parametername() {
  return getRuleContext<MiniCParser::ParameternameContext>(0);
}


size_t MiniCParser::ExprContext::getRuleIndex() const {
  return MiniCParser::RuleExpr;
}

void MiniCParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void MiniCParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


std::any MiniCParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}


MiniCParser::ExprContext* MiniCParser::expr() {
   return expr(0);
}

MiniCParser::ExprContext* MiniCParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniCParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  MiniCParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 30;
  enterRecursionRule(_localctx, 30, MiniCParser::RuleExpr, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(229);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      setState(207);
      match(MiniCParser::INT);
      break;
    }

    case 2: {
      setState(208);
      match(MiniCParser::T__19);
      setState(209);
      expr(21);
      break;
    }

    case 3: {
      setState(210);
      match(MiniCParser::T__23);
      break;
    }

    case 4: {
      setState(211);
      match(MiniCParser::T__24);
      break;
    }

    case 5: {
      setState(212);
      match(MiniCParser::T__25);
      setState(213);
      expr(14);
      break;
    }

    case 6: {
      setState(214);
      match(MiniCParser::T__2);
      setState(215);
      expr(0);
      setState(216);
      match(MiniCParser::T__3);
      break;
    }

    case 7: {
      setState(218);
      var();
      break;
    }

    case 8: {
      setState(219);
      funcname();
      setState(220);
      match(MiniCParser::T__2);
      setState(221);
      arguments();
      setState(222);
      match(MiniCParser::T__3);
      break;
    }

    case 9: {
      setState(224);
      var();
      setState(225);
      match(MiniCParser::T__32);
      setState(226);
      expr(2);
      break;
    }

    case 10: {
      setState(228);
      parametername();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(271);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(269);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(231);

          if (!(precpred(_ctx, 20))) throw FailedPredicateException(this, "precpred(_ctx, 20)");
          setState(232);
          match(MiniCParser::T__20);
          setState(233);
          expr(21);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(234);

          if (!(precpred(_ctx, 19))) throw FailedPredicateException(this, "precpred(_ctx, 19)");
          setState(235);
          match(MiniCParser::T__21);
          setState(236);
          expr(20);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(237);

          if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
          setState(238);
          match(MiniCParser::T__22);
          setState(239);
          expr(19);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(240);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(241);
          match(MiniCParser::T__19);
          setState(242);
          expr(18);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(243);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(244);
          match(MiniCParser::T__26);
          setState(245);
          expr(14);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(246);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(247);
          match(MiniCParser::T__27);
          setState(248);
          expr(13);
          break;
        }

        case 7: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(249);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(250);
          match(MiniCParser::T__28);
          setState(251);
          expr(12);
          break;
        }

        case 8: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(252);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(253);
          match(MiniCParser::T__29);
          setState(254);
          expr(11);
          break;
        }

        case 9: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(255);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(256);
          match(MiniCParser::T__30);
          setState(257);
          expr(10);
          break;
        }

        case 10: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(258);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(259);
          match(MiniCParser::T__31);
          setState(260);
          expr(9);
          break;
        }

        case 11: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(261);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(262);
          match(MiniCParser::T__30);
          setState(263);
          match(MiniCParser::T__32);
          setState(264);
          expr(8);
          break;
        }

        case 12: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(265);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(266);
          match(MiniCParser::T__31);
          setState(267);
          match(MiniCParser::T__32);
          setState(268);
          expr(7);
          break;
        }

        default:
          break;
        } 
      }
      setState(273);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- VarContext ------------------------------------------------------------------

MiniCParser::VarContext::VarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::VarnameContext* MiniCParser::VarContext::varname() {
  return getRuleContext<MiniCParser::VarnameContext>(0);
}

MiniCParser::ExprContext* MiniCParser::VarContext::expr() {
  return getRuleContext<MiniCParser::ExprContext>(0);
}


size_t MiniCParser::VarContext::getRuleIndex() const {
  return MiniCParser::RuleVar;
}

void MiniCParser::VarContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar(this);
}

void MiniCParser::VarContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar(this);
}


std::any MiniCParser::VarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitVar(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::VarContext* MiniCParser::var() {
  VarContext *_localctx = _tracker.createInstance<VarContext>(_ctx, getState());
  enterRule(_localctx, 32, MiniCParser::RuleVar);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(280);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(274);
      varname();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(275);
      varname();
      setState(276);
      match(MiniCParser::T__13);
      setState(277);
      expr(0);
      setState(278);
      match(MiniCParser::T__14);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentsContext ------------------------------------------------------------------

MiniCParser::ArgumentsContext::ArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::ArgumentlistContext* MiniCParser::ArgumentsContext::argumentlist() {
  return getRuleContext<MiniCParser::ArgumentlistContext>(0);
}


size_t MiniCParser::ArgumentsContext::getRuleIndex() const {
  return MiniCParser::RuleArguments;
}

void MiniCParser::ArgumentsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArguments(this);
}

void MiniCParser::ArgumentsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArguments(this);
}


std::any MiniCParser::ArgumentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitArguments(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::ArgumentsContext* MiniCParser::arguments() {
  ArgumentsContext *_localctx = _tracker.createInstance<ArgumentsContext>(_ctx, getState());
  enterRule(_localctx, 34, MiniCParser::RuleArguments);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(284);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MiniCParser::T__3: {
        enterOuterAlt(_localctx, 1);

        break;
      }

      case MiniCParser::T__2:
      case MiniCParser::T__19:
      case MiniCParser::T__23:
      case MiniCParser::T__24:
      case MiniCParser::T__25:
      case MiniCParser::ID:
      case MiniCParser::INT: {
        enterOuterAlt(_localctx, 2);
        setState(283);
        argumentlist(0);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentlistContext ------------------------------------------------------------------

MiniCParser::ArgumentlistContext::ArgumentlistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::ExprContext* MiniCParser::ArgumentlistContext::expr() {
  return getRuleContext<MiniCParser::ExprContext>(0);
}

std::vector<MiniCParser::ArgumentlistContext *> MiniCParser::ArgumentlistContext::argumentlist() {
  return getRuleContexts<MiniCParser::ArgumentlistContext>();
}

MiniCParser::ArgumentlistContext* MiniCParser::ArgumentlistContext::argumentlist(size_t i) {
  return getRuleContext<MiniCParser::ArgumentlistContext>(i);
}


size_t MiniCParser::ArgumentlistContext::getRuleIndex() const {
  return MiniCParser::RuleArgumentlist;
}

void MiniCParser::ArgumentlistContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgumentlist(this);
}

void MiniCParser::ArgumentlistContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgumentlist(this);
}


std::any MiniCParser::ArgumentlistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitArgumentlist(this);
  else
    return visitor->visitChildren(this);
}


MiniCParser::ArgumentlistContext* MiniCParser::argumentlist() {
   return argumentlist(0);
}

MiniCParser::ArgumentlistContext* MiniCParser::argumentlist(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniCParser::ArgumentlistContext *_localctx = _tracker.createInstance<ArgumentlistContext>(_ctx, parentState);
  MiniCParser::ArgumentlistContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 36;
  enterRecursionRule(_localctx, 36, MiniCParser::RuleArgumentlist, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(287);
    expr(0);
    _ctx->stop = _input->LT(-1);
    setState(294);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ArgumentlistContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleArgumentlist);
        setState(289);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(290);
        match(MiniCParser::T__15);
        setState(291);
        argumentlist(2); 
      }
      setState(296);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- VarnameContext ------------------------------------------------------------------

MiniCParser::VarnameContext::VarnameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniCParser::VarnameContext::ID() {
  return getToken(MiniCParser::ID, 0);
}


size_t MiniCParser::VarnameContext::getRuleIndex() const {
  return MiniCParser::RuleVarname;
}

void MiniCParser::VarnameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarname(this);
}

void MiniCParser::VarnameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarname(this);
}


std::any MiniCParser::VarnameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitVarname(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::VarnameContext* MiniCParser::varname() {
  VarnameContext *_localctx = _tracker.createInstance<VarnameContext>(_ctx, getState());
  enterRule(_localctx, 38, MiniCParser::RuleVarname);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(297);
    match(MiniCParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncnameContext ------------------------------------------------------------------

MiniCParser::FuncnameContext::FuncnameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniCParser::FuncnameContext::ID() {
  return getToken(MiniCParser::ID, 0);
}


size_t MiniCParser::FuncnameContext::getRuleIndex() const {
  return MiniCParser::RuleFuncname;
}

void MiniCParser::FuncnameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncname(this);
}

void MiniCParser::FuncnameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncname(this);
}


std::any MiniCParser::FuncnameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitFuncname(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::FuncnameContext* MiniCParser::funcname() {
  FuncnameContext *_localctx = _tracker.createInstance<FuncnameContext>(_ctx, getState());
  enterRule(_localctx, 40, MiniCParser::RuleFuncname);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(299);
    match(MiniCParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameternameContext ------------------------------------------------------------------

MiniCParser::ParameternameContext::ParameternameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniCParser::ParameternameContext::ID() {
  return getToken(MiniCParser::ID, 0);
}


size_t MiniCParser::ParameternameContext::getRuleIndex() const {
  return MiniCParser::RuleParametername;
}

void MiniCParser::ParameternameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParametername(this);
}

void MiniCParser::ParameternameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParametername(this);
}


std::any MiniCParser::ParameternameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitParametername(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::ParameternameContext* MiniCParser::parametername() {
  ParameternameContext *_localctx = _tracker.createInstance<ParameternameContext>(_ctx, getState());
  enterRule(_localctx, 42, MiniCParser::RuleParametername);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(301);
    match(MiniCParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool MiniCParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 2: return declSempred(antlrcpp::downCast<DeclContext *>(context), predicateIndex);
    case 3: return vardeclSempred(antlrcpp::downCast<VardeclContext *>(context), predicateIndex);
    case 7: return varlistSempred(antlrcpp::downCast<VarlistContext *>(context), predicateIndex);
    case 12: return parameterlistSempred(antlrcpp::downCast<ParameterlistContext *>(context), predicateIndex);
    case 15: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);
    case 18: return argumentlistSempred(antlrcpp::downCast<ArgumentlistContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool MiniCParser::declSempred(DeclContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool MiniCParser::vardeclSempred(VardeclContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool MiniCParser::varlistSempred(VarlistContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool MiniCParser::parameterlistSempred(ParameterlistContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool MiniCParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 20);
    case 5: return precpred(_ctx, 19);
    case 6: return precpred(_ctx, 18);
    case 7: return precpred(_ctx, 17);
    case 8: return precpred(_ctx, 13);
    case 9: return precpred(_ctx, 12);
    case 10: return precpred(_ctx, 11);
    case 11: return precpred(_ctx, 10);
    case 12: return precpred(_ctx, 9);
    case 13: return precpred(_ctx, 8);
    case 14: return precpred(_ctx, 7);
    case 15: return precpred(_ctx, 6);

  default:
    break;
  }
  return true;
}

bool MiniCParser::argumentlistSempred(ArgumentlistContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 16: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

void MiniCParser::initialize() {
  ::antlr4::internal::call_once(minicParserOnceFlag, minicParserInitialize);
}
