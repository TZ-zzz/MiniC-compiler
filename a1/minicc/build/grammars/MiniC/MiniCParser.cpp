
#include <vector>
#include "Program.h"
#include "Declarations.h"
#include "Statements.h"
#include "Exprs.h"
#include "Terms.h"


// Generated from /home/tangzhen/csc488/a1/minicc/grammars/MiniC.g4 by ANTLR 4.11.1


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
      "prog", "preamble", "decl", "vardecl", "scope", "stmt", "varlist", 
      "varlistentry", "vartype", "rettype", "parameters", "parameterlist", 
      "parameterentry", "expropt", "expr", "var", "arguments", "argumentlist", 
      "varname", "funcname", "parametername"
    },
    std::vector<std::string>{
    },
    std::vector<std::string>{
      "", "ID", "INT", "WS", "COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,4,85,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,7,
  	7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,14,
  	2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,1,0,1,0,1,
  	1,1,1,1,2,1,2,1,3,1,3,1,4,1,4,1,5,1,5,1,6,1,6,1,7,1,7,1,8,1,8,1,9,1,9,
  	1,10,1,10,1,11,1,11,1,12,1,12,1,13,1,13,1,14,1,14,1,15,1,15,1,16,1,16,
  	1,17,1,17,1,18,1,18,1,19,1,19,1,20,1,20,1,20,0,0,21,0,2,4,6,8,10,12,14,
  	16,18,20,22,24,26,28,30,32,34,36,38,40,0,0,63,0,42,1,0,0,0,2,44,1,0,0,
  	0,4,46,1,0,0,0,6,48,1,0,0,0,8,50,1,0,0,0,10,52,1,0,0,0,12,54,1,0,0,0,
  	14,56,1,0,0,0,16,58,1,0,0,0,18,60,1,0,0,0,20,62,1,0,0,0,22,64,1,0,0,0,
  	24,66,1,0,0,0,26,68,1,0,0,0,28,70,1,0,0,0,30,72,1,0,0,0,32,74,1,0,0,0,
  	34,76,1,0,0,0,36,78,1,0,0,0,38,80,1,0,0,0,40,82,1,0,0,0,42,43,1,0,0,0,
  	43,1,1,0,0,0,44,45,1,0,0,0,45,3,1,0,0,0,46,47,1,0,0,0,47,5,1,0,0,0,48,
  	49,1,0,0,0,49,7,1,0,0,0,50,51,1,0,0,0,51,9,1,0,0,0,52,53,1,0,0,0,53,11,
  	1,0,0,0,54,55,1,0,0,0,55,13,1,0,0,0,56,57,1,0,0,0,57,15,1,0,0,0,58,59,
  	1,0,0,0,59,17,1,0,0,0,60,61,1,0,0,0,61,19,1,0,0,0,62,63,1,0,0,0,63,21,
  	1,0,0,0,64,65,1,0,0,0,65,23,1,0,0,0,66,67,1,0,0,0,67,25,1,0,0,0,68,69,
  	1,0,0,0,69,27,1,0,0,0,70,71,1,0,0,0,71,29,1,0,0,0,72,73,1,0,0,0,73,31,
  	1,0,0,0,74,75,1,0,0,0,75,33,1,0,0,0,76,77,1,0,0,0,77,35,1,0,0,0,78,79,
  	1,0,0,0,79,37,1,0,0,0,80,81,1,0,0,0,81,39,1,0,0,0,82,83,1,0,0,0,83,41,
  	1,0,0,0,0
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
    enterOuterAlt(_localctx, 1);

   
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
  DeclContext *_localctx = _tracker.createInstance<DeclContext>(_ctx, getState());
  enterRule(_localctx, 4, MiniCParser::RuleDecl);

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

//----------------- VardeclContext ------------------------------------------------------------------

MiniCParser::VardeclContext::VardeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
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
  VardeclContext *_localctx = _tracker.createInstance<VardeclContext>(_ctx, getState());
  enterRule(_localctx, 6, MiniCParser::RuleVardecl);

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

//----------------- ScopeContext ------------------------------------------------------------------

MiniCParser::ScopeContext::ScopeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
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
    enterOuterAlt(_localctx, 1);

   
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
    enterOuterAlt(_localctx, 1);

   
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
  VarlistContext *_localctx = _tracker.createInstance<VarlistContext>(_ctx, getState());
  enterRule(_localctx, 12, MiniCParser::RuleVarlist);

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
  enterRule(_localctx, 14, MiniCParser::RuleVarlistentry);

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
  enterRule(_localctx, 16, MiniCParser::RuleVartype);

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

//----------------- RettypeContext ------------------------------------------------------------------

MiniCParser::RettypeContext::RettypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
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
  enterRule(_localctx, 18, MiniCParser::RuleRettype);

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

//----------------- ParametersContext ------------------------------------------------------------------

MiniCParser::ParametersContext::ParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
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
  enterRule(_localctx, 20, MiniCParser::RuleParameters);

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

//----------------- ParameterlistContext ------------------------------------------------------------------

MiniCParser::ParameterlistContext::ParameterlistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
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
  ParameterlistContext *_localctx = _tracker.createInstance<ParameterlistContext>(_ctx, getState());
  enterRule(_localctx, 22, MiniCParser::RuleParameterlist);

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
  enterRule(_localctx, 24, MiniCParser::RuleParameterentry);

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
  enterRule(_localctx, 26, MiniCParser::RuleExpropt);

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

//----------------- ExprContext ------------------------------------------------------------------

MiniCParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
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
  ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, getState());
  enterRule(_localctx, 28, MiniCParser::RuleExpr);

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

//----------------- VarContext ------------------------------------------------------------------

MiniCParser::VarContext::VarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
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
  enterRule(_localctx, 30, MiniCParser::RuleVar);

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

//----------------- ArgumentsContext ------------------------------------------------------------------

MiniCParser::ArgumentsContext::ArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
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
  enterRule(_localctx, 32, MiniCParser::RuleArguments);

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

//----------------- ArgumentlistContext ------------------------------------------------------------------

MiniCParser::ArgumentlistContext::ArgumentlistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
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
  ArgumentlistContext *_localctx = _tracker.createInstance<ArgumentlistContext>(_ctx, getState());
  enterRule(_localctx, 34, MiniCParser::RuleArgumentlist);

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

//----------------- VarnameContext ------------------------------------------------------------------

MiniCParser::VarnameContext::VarnameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
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
  enterRule(_localctx, 36, MiniCParser::RuleVarname);

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

//----------------- FuncnameContext ------------------------------------------------------------------

MiniCParser::FuncnameContext::FuncnameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
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
  enterRule(_localctx, 38, MiniCParser::RuleFuncname);

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

//----------------- ParameternameContext ------------------------------------------------------------------

MiniCParser::ParameternameContext::ParameternameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
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
  enterRule(_localctx, 40, MiniCParser::RuleParametername);

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

void MiniCParser::initialize() {
  ::antlr4::internal::call_once(minicParserOnceFlag, minicParserInitialize);
}
