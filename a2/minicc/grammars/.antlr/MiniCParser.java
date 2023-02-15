// Generated from /home/tangzhen/csc488/a2/minicc/grammars/MiniC.g4 by ANTLR 4.9.2

#include <vector>
#include "Program.h"
#include "Declarations.h"
#include "Statements.h"
#include "Exprs.h"
#include "Terms.h"

import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class MiniCParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.9.2", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, T__7=8, T__8=9, 
		T__9=10, T__10=11, T__11=12, T__12=13, T__13=14, T__14=15, T__15=16, T__16=17, 
		T__17=18, T__18=19, T__19=20, T__20=21, T__21=22, T__22=23, T__23=24, 
		T__24=25, T__25=26, T__26=27, T__27=28, T__28=29, T__29=30, T__30=31, 
		T__31=32, T__32=33, T__33=34, T__34=35, ID=36, INT=37, WS=38, COMMENT=39;
	public static final int
		RULE_prog = 0, RULE_preamble = 1, RULE_decl = 2, RULE_declentry = 3, RULE_vardecl = 4, 
		RULE_scope = 5, RULE_stmt = 6, RULE_varlist = 7, RULE_varlistentry = 8, 
		RULE_vartype = 9, RULE_rettype = 10, RULE_parameters = 11, RULE_parameterlist = 12, 
		RULE_parameterentry = 13, RULE_expropt = 14, RULE_expr = 15, RULE_var = 16, 
		RULE_arguments = 17, RULE_argumentlist = 18, RULE_varname = 19, RULE_funcname = 20, 
		RULE_parametername = 21;
	private static String[] makeRuleNames() {
		return new String[] {
			"prog", "preamble", "decl", "declentry", "vardecl", "scope", "stmt", 
			"varlist", "varlistentry", "vartype", "rettype", "parameters", "parameterlist", 
			"parameterentry", "expropt", "expr", "var", "arguments", "argumentlist", 
			"varname", "funcname", "parametername"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'#include'", "'\"minicio.h\"'", "'('", "')'", "';'", "'{'", "'}'", 
			"'if'", "'else'", "'for'", "'while'", "'break'", "'return'", "','", "'['", 
			"']'", "'int'", "'bool'", "'void'", "'-'", "'!'", "'*'", "'/'", "'+'", 
			"'true'", "'false'", "'=='", "'!='", "'<'", "'<='", "'>'", "'>='", "'&&'", 
			"'||'", "'='"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			"ID", "INT", "WS", "COMMENT"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "MiniC.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public MiniCParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	public static class ProgContext extends ParserRuleContext {
		public minicc::Program * val;
		public PreambleContext preamble() {
			return getRuleContext(PreambleContext.class,0);
		}
		public DeclContext decl() {
			return getRuleContext(DeclContext.class,0);
		}
		public TerminalNode EOF() { return getToken(MiniCParser.EOF, 0); }
		public ProgContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_prog; }
	}

	public final ProgContext prog() throws RecognitionException {
		ProgContext _localctx = new ProgContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_prog);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(44);
			preamble();
			setState(45);
			decl();
			setState(46);
			match(EOF);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class PreambleContext extends ParserRuleContext {
		public PreambleContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_preamble; }
	}

	public final PreambleContext preamble() throws RecognitionException {
		PreambleContext _localctx = new PreambleContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_preamble);
		try {
			setState(51);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__0:
				enterOuterAlt(_localctx, 1);
				{
				setState(48);
				match(T__0);
				setState(49);
				match(T__1);
				}
				break;
			case T__16:
			case T__17:
			case T__18:
				enterOuterAlt(_localctx, 2);
				{
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class DeclContext extends ParserRuleContext {
		public List<DeclentryContext> declentry() {
			return getRuleContexts(DeclentryContext.class);
		}
		public DeclentryContext declentry(int i) {
			return getRuleContext(DeclentryContext.class,i);
		}
		public DeclContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_decl; }
	}

	public final DeclContext decl() throws RecognitionException {
		DeclContext _localctx = new DeclContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_decl);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(54); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(53);
				declentry();
				}
				}
				setState(56); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( (((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__16) | (1L << T__17) | (1L << T__18))) != 0) );
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class DeclentryContext extends ParserRuleContext {
		public List<VardeclContext> vardecl() {
			return getRuleContexts(VardeclContext.class);
		}
		public VardeclContext vardecl(int i) {
			return getRuleContext(VardeclContext.class,i);
		}
		public RettypeContext rettype() {
			return getRuleContext(RettypeContext.class,0);
		}
		public FuncnameContext funcname() {
			return getRuleContext(FuncnameContext.class,0);
		}
		public ParametersContext parameters() {
			return getRuleContext(ParametersContext.class,0);
		}
		public ScopeContext scope() {
			return getRuleContext(ScopeContext.class,0);
		}
		public DeclentryContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_declentry; }
	}

	public final DeclentryContext declentry() throws RecognitionException {
		DeclentryContext _localctx = new DeclentryContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_declentry);
		try {
			int _alt;
			setState(77);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,3,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(59); 
				_errHandler.sync(this);
				_alt = 1;
				do {
					switch (_alt) {
					case 1:
						{
						{
						setState(58);
						vardecl();
						}
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					setState(61); 
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,2,_ctx);
				} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(63);
				rettype();
				setState(64);
				funcname();
				setState(65);
				match(T__2);
				setState(66);
				parameters();
				setState(67);
				match(T__3);
				setState(68);
				scope();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(70);
				rettype();
				setState(71);
				funcname();
				setState(72);
				match(T__2);
				setState(73);
				parameters();
				setState(74);
				match(T__3);
				setState(75);
				match(T__4);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class VardeclContext extends ParserRuleContext {
		public VartypeContext vartype() {
			return getRuleContext(VartypeContext.class,0);
		}
		public VarlistContext varlist() {
			return getRuleContext(VarlistContext.class,0);
		}
		public VardeclContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_vardecl; }
	}

	public final VardeclContext vardecl() throws RecognitionException {
		VardeclContext _localctx = new VardeclContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_vardecl);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(79);
			vartype();
			setState(80);
			varlist();
			setState(81);
			match(T__4);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ScopeContext extends ParserRuleContext {
		public List<VardeclContext> vardecl() {
			return getRuleContexts(VardeclContext.class);
		}
		public VardeclContext vardecl(int i) {
			return getRuleContext(VardeclContext.class,i);
		}
		public List<StmtContext> stmt() {
			return getRuleContexts(StmtContext.class);
		}
		public StmtContext stmt(int i) {
			return getRuleContext(StmtContext.class,i);
		}
		public ScopeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_scope; }
	}

	public final ScopeContext scope() throws RecognitionException {
		ScopeContext _localctx = new ScopeContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_scope);
		int _la;
		try {
			setState(106);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,7,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(83);
				match(T__5);
				setState(85); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(84);
					vardecl();
					}
					}
					setState(87); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==T__16 || _la==T__17 );
				setState(90); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(89);
					stmt();
					}
					}
					setState(92); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( (((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__2) | (1L << T__5) | (1L << T__7) | (1L << T__9) | (1L << T__10) | (1L << T__11) | (1L << T__12) | (1L << T__19) | (1L << T__20) | (1L << T__24) | (1L << T__25) | (1L << ID) | (1L << INT))) != 0) );
				setState(94);
				match(T__6);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(96);
				match(T__5);
				setState(98); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(97);
					stmt();
					}
					}
					setState(100); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( (((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__2) | (1L << T__5) | (1L << T__7) | (1L << T__9) | (1L << T__10) | (1L << T__11) | (1L << T__12) | (1L << T__19) | (1L << T__20) | (1L << T__24) | (1L << T__25) | (1L << ID) | (1L << INT))) != 0) );
				setState(102);
				match(T__6);
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(104);
				match(T__5);
				setState(105);
				match(T__6);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StmtContext extends ParserRuleContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public List<StmtContext> stmt() {
			return getRuleContexts(StmtContext.class);
		}
		public StmtContext stmt(int i) {
			return getRuleContext(StmtContext.class,i);
		}
		public List<ExproptContext> expropt() {
			return getRuleContexts(ExproptContext.class);
		}
		public ExproptContext expropt(int i) {
			return getRuleContext(ExproptContext.class,i);
		}
		public ScopeContext scope() {
			return getRuleContext(ScopeContext.class,0);
		}
		public StmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_stmt; }
	}

	public final StmtContext stmt() throws RecognitionException {
		StmtContext _localctx = new StmtContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_stmt);
		try {
			setState(150);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,8,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(108);
				expr(0);
				setState(109);
				match(T__4);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(111);
				match(T__7);
				setState(112);
				match(T__2);
				setState(113);
				expr(0);
				setState(114);
				match(T__3);
				setState(115);
				stmt();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(117);
				match(T__7);
				setState(118);
				match(T__2);
				setState(119);
				expr(0);
				setState(120);
				match(T__3);
				setState(121);
				stmt();
				setState(122);
				match(T__8);
				setState(123);
				stmt();
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(125);
				match(T__9);
				setState(126);
				match(T__2);
				setState(127);
				expropt();
				setState(128);
				match(T__4);
				setState(129);
				expropt();
				setState(130);
				match(T__4);
				setState(131);
				expropt();
				setState(132);
				match(T__3);
				setState(133);
				stmt();
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(135);
				match(T__10);
				setState(136);
				match(T__2);
				setState(137);
				expr(0);
				setState(138);
				match(T__3);
				setState(139);
				stmt();
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(141);
				match(T__11);
				setState(142);
				match(T__4);
				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(143);
				match(T__12);
				setState(144);
				match(T__4);
				}
				break;
			case 8:
				enterOuterAlt(_localctx, 8);
				{
				setState(145);
				match(T__12);
				setState(146);
				expr(0);
				setState(147);
				match(T__4);
				}
				break;
			case 9:
				enterOuterAlt(_localctx, 9);
				{
				setState(149);
				scope();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class VarlistContext extends ParserRuleContext {
		public List<VarlistentryContext> varlistentry() {
			return getRuleContexts(VarlistentryContext.class);
		}
		public VarlistentryContext varlistentry(int i) {
			return getRuleContext(VarlistentryContext.class,i);
		}
		public VarlistContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_varlist; }
	}

	public final VarlistContext varlist() throws RecognitionException {
		VarlistContext _localctx = new VarlistContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_varlist);
		int _la;
		try {
			setState(160);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,10,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(152);
				varlistentry();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(153);
				varlistentry();
				setState(156); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(154);
					match(T__13);
					setState(155);
					varlistentry();
					}
					}
					setState(158); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==T__13 );
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class VarlistentryContext extends ParserRuleContext {
		public VarnameContext varname() {
			return getRuleContext(VarnameContext.class,0);
		}
		public TerminalNode INT() { return getToken(MiniCParser.INT, 0); }
		public VarlistentryContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_varlistentry; }
	}

	public final VarlistentryContext varlistentry() throws RecognitionException {
		VarlistentryContext _localctx = new VarlistentryContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_varlistentry);
		try {
			setState(168);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,11,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(162);
				varname();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(163);
				varname();
				setState(164);
				match(T__14);
				setState(165);
				match(INT);
				setState(166);
				match(T__15);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class VartypeContext extends ParserRuleContext {
		public VartypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_vartype; }
	}

	public final VartypeContext vartype() throws RecognitionException {
		VartypeContext _localctx = new VartypeContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_vartype);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(170);
			_la = _input.LA(1);
			if ( !(_la==T__16 || _la==T__17) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class RettypeContext extends ParserRuleContext {
		public VartypeContext vartype() {
			return getRuleContext(VartypeContext.class,0);
		}
		public RettypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_rettype; }
	}

	public final RettypeContext rettype() throws RecognitionException {
		RettypeContext _localctx = new RettypeContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_rettype);
		try {
			setState(174);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__18:
				enterOuterAlt(_localctx, 1);
				{
				setState(172);
				match(T__18);
				}
				break;
			case T__16:
			case T__17:
				enterOuterAlt(_localctx, 2);
				{
				setState(173);
				vartype();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ParametersContext extends ParserRuleContext {
		public ParameterlistContext parameterlist() {
			return getRuleContext(ParameterlistContext.class,0);
		}
		public ParametersContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameters; }
	}

	public final ParametersContext parameters() throws RecognitionException {
		ParametersContext _localctx = new ParametersContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_parameters);
		try {
			setState(178);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__3:
				enterOuterAlt(_localctx, 1);
				{
				}
				break;
			case T__16:
			case T__17:
				enterOuterAlt(_localctx, 2);
				{
				setState(177);
				parameterlist();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ParameterlistContext extends ParserRuleContext {
		public List<ParameterentryContext> parameterentry() {
			return getRuleContexts(ParameterentryContext.class);
		}
		public ParameterentryContext parameterentry(int i) {
			return getRuleContext(ParameterentryContext.class,i);
		}
		public ParameterlistContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameterlist; }
	}

	public final ParameterlistContext parameterlist() throws RecognitionException {
		ParameterlistContext _localctx = new ParameterlistContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_parameterlist);
		int _la;
		try {
			setState(188);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,15,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(180);
				parameterentry();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(181);
				parameterentry();
				setState(184); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(182);
					match(T__13);
					setState(183);
					parameterentry();
					}
					}
					setState(186); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==T__13 );
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ParameterentryContext extends ParserRuleContext {
		public VartypeContext vartype() {
			return getRuleContext(VartypeContext.class,0);
		}
		public ParameternameContext parametername() {
			return getRuleContext(ParameternameContext.class,0);
		}
		public ParameterentryContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameterentry; }
	}

	public final ParameterentryContext parameterentry() throws RecognitionException {
		ParameterentryContext _localctx = new ParameterentryContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_parameterentry);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(190);
			vartype();
			setState(191);
			parametername();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ExproptContext extends ParserRuleContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public ExproptContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expropt; }
	}

	public final ExproptContext expropt() throws RecognitionException {
		ExproptContext _localctx = new ExproptContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_expropt);
		try {
			setState(195);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__2:
			case T__19:
			case T__20:
			case T__24:
			case T__25:
			case ID:
			case INT:
				enterOuterAlt(_localctx, 1);
				{
				setState(193);
				expr(0);
				}
				break;
			case T__3:
			case T__4:
				enterOuterAlt(_localctx, 2);
				{
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ExprContext extends ParserRuleContext {
		public TerminalNode INT() { return getToken(MiniCParser.INT, 0); }
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public VarContext var() {
			return getRuleContext(VarContext.class,0);
		}
		public FuncnameContext funcname() {
			return getRuleContext(FuncnameContext.class,0);
		}
		public ArgumentsContext arguments() {
			return getRuleContext(ArgumentsContext.class,0);
		}
		public ParameternameContext parametername() {
			return getRuleContext(ParameternameContext.class,0);
		}
		public ExprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expr; }
	}

	public final ExprContext expr() throws RecognitionException {
		return expr(0);
	}

	private ExprContext expr(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ExprContext _localctx = new ExprContext(_ctx, _parentState);
		ExprContext _prevctx = _localctx;
		int _startState = 30;
		enterRecursionRule(_localctx, 30, RULE_expr, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(220);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,17,_ctx) ) {
			case 1:
				{
				setState(198);
				match(INT);
				}
				break;
			case 2:
				{
				setState(199);
				match(T__19);
				setState(200);
				expr(14);
				}
				break;
			case 3:
				{
				setState(201);
				match(T__20);
				setState(202);
				expr(13);
				}
				break;
			case 4:
				{
				setState(203);
				match(T__24);
				}
				break;
			case 5:
				{
				setState(204);
				match(T__25);
				}
				break;
			case 6:
				{
				setState(205);
				match(T__2);
				setState(206);
				expr(0);
				setState(207);
				match(T__3);
				}
				break;
			case 7:
				{
				setState(209);
				var();
				}
				break;
			case 8:
				{
				setState(210);
				funcname();
				setState(211);
				match(T__2);
				setState(212);
				arguments();
				setState(213);
				match(T__3);
				}
				break;
			case 9:
				{
				setState(215);
				var();
				setState(216);
				match(T__34);
				setState(217);
				expr(2);
				}
				break;
			case 10:
				{
				setState(219);
				parametername();
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(239);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,19,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(237);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,18,_ctx) ) {
					case 1:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(222);
						if (!(precpred(_ctx, 12))) throw new FailedPredicateException(this, "precpred(_ctx, 12)");
						setState(223);
						_la = _input.LA(1);
						if ( !(_la==T__21 || _la==T__22) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(224);
						expr(13);
						}
						break;
					case 2:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(225);
						if (!(precpred(_ctx, 11))) throw new FailedPredicateException(this, "precpred(_ctx, 11)");
						setState(226);
						_la = _input.LA(1);
						if ( !(_la==T__19 || _la==T__23) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(227);
						expr(12);
						}
						break;
					case 3:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(228);
						if (!(precpred(_ctx, 8))) throw new FailedPredicateException(this, "precpred(_ctx, 8)");
						setState(229);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__26) | (1L << T__27) | (1L << T__28) | (1L << T__29) | (1L << T__30) | (1L << T__31))) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(230);
						expr(9);
						}
						break;
					case 4:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(231);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(232);
						match(T__32);
						setState(233);
						expr(8);
						}
						break;
					case 5:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(234);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(235);
						match(T__33);
						setState(236);
						expr(7);
						}
						break;
					}
					} 
				}
				setState(241);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,19,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class VarContext extends ParserRuleContext {
		public VarnameContext varname() {
			return getRuleContext(VarnameContext.class,0);
		}
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public VarContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_var; }
	}

	public final VarContext var() throws RecognitionException {
		VarContext _localctx = new VarContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_var);
		try {
			setState(248);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,20,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(242);
				varname();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(243);
				varname();
				setState(244);
				match(T__14);
				setState(245);
				expr(0);
				setState(246);
				match(T__15);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ArgumentsContext extends ParserRuleContext {
		public ArgumentlistContext argumentlist() {
			return getRuleContext(ArgumentlistContext.class,0);
		}
		public ArgumentsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_arguments; }
	}

	public final ArgumentsContext arguments() throws RecognitionException {
		ArgumentsContext _localctx = new ArgumentsContext(_ctx, getState());
		enterRule(_localctx, 34, RULE_arguments);
		try {
			setState(252);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__3:
				enterOuterAlt(_localctx, 1);
				{
				}
				break;
			case T__2:
			case T__19:
			case T__20:
			case T__24:
			case T__25:
			case ID:
			case INT:
				enterOuterAlt(_localctx, 2);
				{
				setState(251);
				argumentlist();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ArgumentlistContext extends ParserRuleContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public ArgumentlistContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_argumentlist; }
	}

	public final ArgumentlistContext argumentlist() throws RecognitionException {
		ArgumentlistContext _localctx = new ArgumentlistContext(_ctx, getState());
		enterRule(_localctx, 36, RULE_argumentlist);
		int _la;
		try {
			setState(262);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,23,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(254);
				expr(0);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(255);
				expr(0);
				setState(258); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(256);
					match(T__13);
					setState(257);
					expr(0);
					}
					}
					setState(260); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==T__13 );
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class VarnameContext extends ParserRuleContext {
		public TerminalNode ID() { return getToken(MiniCParser.ID, 0); }
		public VarnameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_varname; }
	}

	public final VarnameContext varname() throws RecognitionException {
		VarnameContext _localctx = new VarnameContext(_ctx, getState());
		enterRule(_localctx, 38, RULE_varname);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(264);
			match(ID);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class FuncnameContext extends ParserRuleContext {
		public TerminalNode ID() { return getToken(MiniCParser.ID, 0); }
		public FuncnameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_funcname; }
	}

	public final FuncnameContext funcname() throws RecognitionException {
		FuncnameContext _localctx = new FuncnameContext(_ctx, getState());
		enterRule(_localctx, 40, RULE_funcname);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(266);
			match(ID);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ParameternameContext extends ParserRuleContext {
		public TerminalNode ID() { return getToken(MiniCParser.ID, 0); }
		public ParameternameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parametername; }
	}

	public final ParameternameContext parametername() throws RecognitionException {
		ParameternameContext _localctx = new ParameternameContext(_ctx, getState());
		enterRule(_localctx, 42, RULE_parametername);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(268);
			match(ID);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 15:
			return expr_sempred((ExprContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean expr_sempred(ExprContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 12);
		case 1:
			return precpred(_ctx, 11);
		case 2:
			return precpred(_ctx, 8);
		case 3:
			return precpred(_ctx, 7);
		case 4:
			return precpred(_ctx, 6);
		}
		return true;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3)\u0111\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\3\2\3\2\3\2\3\2\3\3"+
		"\3\3\3\3\5\3\66\n\3\3\4\6\49\n\4\r\4\16\4:\3\5\6\5>\n\5\r\5\16\5?\3\5"+
		"\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\5\5P\n\5\3\6\3\6"+
		"\3\6\3\6\3\7\3\7\6\7X\n\7\r\7\16\7Y\3\7\6\7]\n\7\r\7\16\7^\3\7\3\7\3\7"+
		"\3\7\6\7e\n\7\r\7\16\7f\3\7\3\7\3\7\3\7\5\7m\n\7\3\b\3\b\3\b\3\b\3\b\3"+
		"\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b"+
		"\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3"+
		"\b\3\b\5\b\u0099\n\b\3\t\3\t\3\t\3\t\6\t\u009f\n\t\r\t\16\t\u00a0\5\t"+
		"\u00a3\n\t\3\n\3\n\3\n\3\n\3\n\3\n\5\n\u00ab\n\n\3\13\3\13\3\f\3\f\5\f"+
		"\u00b1\n\f\3\r\3\r\5\r\u00b5\n\r\3\16\3\16\3\16\3\16\6\16\u00bb\n\16\r"+
		"\16\16\16\u00bc\5\16\u00bf\n\16\3\17\3\17\3\17\3\20\3\20\5\20\u00c6\n"+
		"\20\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3"+
		"\21\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3\21\5\21\u00df\n\21\3\21"+
		"\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3\21"+
		"\7\21\u00f0\n\21\f\21\16\21\u00f3\13\21\3\22\3\22\3\22\3\22\3\22\3\22"+
		"\5\22\u00fb\n\22\3\23\3\23\5\23\u00ff\n\23\3\24\3\24\3\24\3\24\6\24\u0105"+
		"\n\24\r\24\16\24\u0106\5\24\u0109\n\24\3\25\3\25\3\26\3\26\3\27\3\27\3"+
		"\27\2\3 \30\2\4\6\b\n\f\16\20\22\24\26\30\32\34\36 \"$&(*,\2\6\3\2\23"+
		"\24\3\2\30\31\4\2\26\26\32\32\3\2\35\"\2\u0126\2.\3\2\2\2\4\65\3\2\2\2"+
		"\68\3\2\2\2\bO\3\2\2\2\nQ\3\2\2\2\fl\3\2\2\2\16\u0098\3\2\2\2\20\u00a2"+
		"\3\2\2\2\22\u00aa\3\2\2\2\24\u00ac\3\2\2\2\26\u00b0\3\2\2\2\30\u00b4\3"+
		"\2\2\2\32\u00be\3\2\2\2\34\u00c0\3\2\2\2\36\u00c5\3\2\2\2 \u00de\3\2\2"+
		"\2\"\u00fa\3\2\2\2$\u00fe\3\2\2\2&\u0108\3\2\2\2(\u010a\3\2\2\2*\u010c"+
		"\3\2\2\2,\u010e\3\2\2\2./\5\4\3\2/\60\5\6\4\2\60\61\7\2\2\3\61\3\3\2\2"+
		"\2\62\63\7\3\2\2\63\66\7\4\2\2\64\66\3\2\2\2\65\62\3\2\2\2\65\64\3\2\2"+
		"\2\66\5\3\2\2\2\679\5\b\5\28\67\3\2\2\29:\3\2\2\2:8\3\2\2\2:;\3\2\2\2"+
		";\7\3\2\2\2<>\5\n\6\2=<\3\2\2\2>?\3\2\2\2?=\3\2\2\2?@\3\2\2\2@P\3\2\2"+
		"\2AB\5\26\f\2BC\5*\26\2CD\7\5\2\2DE\5\30\r\2EF\7\6\2\2FG\5\f\7\2GP\3\2"+
		"\2\2HI\5\26\f\2IJ\5*\26\2JK\7\5\2\2KL\5\30\r\2LM\7\6\2\2MN\7\7\2\2NP\3"+
		"\2\2\2O=\3\2\2\2OA\3\2\2\2OH\3\2\2\2P\t\3\2\2\2QR\5\24\13\2RS\5\20\t\2"+
		"ST\7\7\2\2T\13\3\2\2\2UW\7\b\2\2VX\5\n\6\2WV\3\2\2\2XY\3\2\2\2YW\3\2\2"+
		"\2YZ\3\2\2\2Z\\\3\2\2\2[]\5\16\b\2\\[\3\2\2\2]^\3\2\2\2^\\\3\2\2\2^_\3"+
		"\2\2\2_`\3\2\2\2`a\7\t\2\2am\3\2\2\2bd\7\b\2\2ce\5\16\b\2dc\3\2\2\2ef"+
		"\3\2\2\2fd\3\2\2\2fg\3\2\2\2gh\3\2\2\2hi\7\t\2\2im\3\2\2\2jk\7\b\2\2k"+
		"m\7\t\2\2lU\3\2\2\2lb\3\2\2\2lj\3\2\2\2m\r\3\2\2\2no\5 \21\2op\7\7\2\2"+
		"p\u0099\3\2\2\2qr\7\n\2\2rs\7\5\2\2st\5 \21\2tu\7\6\2\2uv\5\16\b\2v\u0099"+
		"\3\2\2\2wx\7\n\2\2xy\7\5\2\2yz\5 \21\2z{\7\6\2\2{|\5\16\b\2|}\7\13\2\2"+
		"}~\5\16\b\2~\u0099\3\2\2\2\177\u0080\7\f\2\2\u0080\u0081\7\5\2\2\u0081"+
		"\u0082\5\36\20\2\u0082\u0083\7\7\2\2\u0083\u0084\5\36\20\2\u0084\u0085"+
		"\7\7\2\2\u0085\u0086\5\36\20\2\u0086\u0087\7\6\2\2\u0087\u0088\5\16\b"+
		"\2\u0088\u0099\3\2\2\2\u0089\u008a\7\r\2\2\u008a\u008b\7\5\2\2\u008b\u008c"+
		"\5 \21\2\u008c\u008d\7\6\2\2\u008d\u008e\5\16\b\2\u008e\u0099\3\2\2\2"+
		"\u008f\u0090\7\16\2\2\u0090\u0099\7\7\2\2\u0091\u0092\7\17\2\2\u0092\u0099"+
		"\7\7\2\2\u0093\u0094\7\17\2\2\u0094\u0095\5 \21\2\u0095\u0096\7\7\2\2"+
		"\u0096\u0099\3\2\2\2\u0097\u0099\5\f\7\2\u0098n\3\2\2\2\u0098q\3\2\2\2"+
		"\u0098w\3\2\2\2\u0098\177\3\2\2\2\u0098\u0089\3\2\2\2\u0098\u008f\3\2"+
		"\2\2\u0098\u0091\3\2\2\2\u0098\u0093\3\2\2\2\u0098\u0097\3\2\2\2\u0099"+
		"\17\3\2\2\2\u009a\u00a3\5\22\n\2\u009b\u009e\5\22\n\2\u009c\u009d\7\20"+
		"\2\2\u009d\u009f\5\22\n\2\u009e\u009c\3\2\2\2\u009f\u00a0\3\2\2\2\u00a0"+
		"\u009e\3\2\2\2\u00a0\u00a1\3\2\2\2\u00a1\u00a3\3\2\2\2\u00a2\u009a\3\2"+
		"\2\2\u00a2\u009b\3\2\2\2\u00a3\21\3\2\2\2\u00a4\u00ab\5(\25\2\u00a5\u00a6"+
		"\5(\25\2\u00a6\u00a7\7\21\2\2\u00a7\u00a8\7\'\2\2\u00a8\u00a9\7\22\2\2"+
		"\u00a9\u00ab\3\2\2\2\u00aa\u00a4\3\2\2\2\u00aa\u00a5\3\2\2\2\u00ab\23"+
		"\3\2\2\2\u00ac\u00ad\t\2\2\2\u00ad\25\3\2\2\2\u00ae\u00b1\7\25\2\2\u00af"+
		"\u00b1\5\24\13\2\u00b0\u00ae\3\2\2\2\u00b0\u00af\3\2\2\2\u00b1\27\3\2"+
		"\2\2\u00b2\u00b5\3\2\2\2\u00b3\u00b5\5\32\16\2\u00b4\u00b2\3\2\2\2\u00b4"+
		"\u00b3\3\2\2\2\u00b5\31\3\2\2\2\u00b6\u00bf\5\34\17\2\u00b7\u00ba\5\34"+
		"\17\2\u00b8\u00b9\7\20\2\2\u00b9\u00bb\5\34\17\2\u00ba\u00b8\3\2\2\2\u00bb"+
		"\u00bc\3\2\2\2\u00bc\u00ba\3\2\2\2\u00bc\u00bd\3\2\2\2\u00bd\u00bf\3\2"+
		"\2\2\u00be\u00b6\3\2\2\2\u00be\u00b7\3\2\2\2\u00bf\33\3\2\2\2\u00c0\u00c1"+
		"\5\24\13\2\u00c1\u00c2\5,\27\2\u00c2\35\3\2\2\2\u00c3\u00c6\5 \21\2\u00c4"+
		"\u00c6\3\2\2\2\u00c5\u00c3\3\2\2\2\u00c5\u00c4\3\2\2\2\u00c6\37\3\2\2"+
		"\2\u00c7\u00c8\b\21\1\2\u00c8\u00df\7\'\2\2\u00c9\u00ca\7\26\2\2\u00ca"+
		"\u00df\5 \21\20\u00cb\u00cc\7\27\2\2\u00cc\u00df\5 \21\17\u00cd\u00df"+
		"\7\33\2\2\u00ce\u00df\7\34\2\2\u00cf\u00d0\7\5\2\2\u00d0\u00d1\5 \21\2"+
		"\u00d1\u00d2\7\6\2\2\u00d2\u00df\3\2\2\2\u00d3\u00df\5\"\22\2\u00d4\u00d5"+
		"\5*\26\2\u00d5\u00d6\7\5\2\2\u00d6\u00d7\5$\23\2\u00d7\u00d8\7\6\2\2\u00d8"+
		"\u00df\3\2\2\2\u00d9\u00da\5\"\22\2\u00da\u00db\7%\2\2\u00db\u00dc\5 "+
		"\21\4\u00dc\u00df\3\2\2\2\u00dd\u00df\5,\27\2\u00de\u00c7\3\2\2\2\u00de"+
		"\u00c9\3\2\2\2\u00de\u00cb\3\2\2\2\u00de\u00cd\3\2\2\2\u00de\u00ce\3\2"+
		"\2\2\u00de\u00cf\3\2\2\2\u00de\u00d3\3\2\2\2\u00de\u00d4\3\2\2\2\u00de"+
		"\u00d9\3\2\2\2\u00de\u00dd\3\2\2\2\u00df\u00f1\3\2\2\2\u00e0\u00e1\f\16"+
		"\2\2\u00e1\u00e2\t\3\2\2\u00e2\u00f0\5 \21\17\u00e3\u00e4\f\r\2\2\u00e4"+
		"\u00e5\t\4\2\2\u00e5\u00f0\5 \21\16\u00e6\u00e7\f\n\2\2\u00e7\u00e8\t"+
		"\5\2\2\u00e8\u00f0\5 \21\13\u00e9\u00ea\f\t\2\2\u00ea\u00eb\7#\2\2\u00eb"+
		"\u00f0\5 \21\n\u00ec\u00ed\f\b\2\2\u00ed\u00ee\7$\2\2\u00ee\u00f0\5 \21"+
		"\t\u00ef\u00e0\3\2\2\2\u00ef\u00e3\3\2\2\2\u00ef\u00e6\3\2\2\2\u00ef\u00e9"+
		"\3\2\2\2\u00ef\u00ec\3\2\2\2\u00f0\u00f3\3\2\2\2\u00f1\u00ef\3\2\2\2\u00f1"+
		"\u00f2\3\2\2\2\u00f2!\3\2\2\2\u00f3\u00f1\3\2\2\2\u00f4\u00fb\5(\25\2"+
		"\u00f5\u00f6\5(\25\2\u00f6\u00f7\7\21\2\2\u00f7\u00f8\5 \21\2\u00f8\u00f9"+
		"\7\22\2\2\u00f9\u00fb\3\2\2\2\u00fa\u00f4\3\2\2\2\u00fa\u00f5\3\2\2\2"+
		"\u00fb#\3\2\2\2\u00fc\u00ff\3\2\2\2\u00fd\u00ff\5&\24\2\u00fe\u00fc\3"+
		"\2\2\2\u00fe\u00fd\3\2\2\2\u00ff%\3\2\2\2\u0100\u0109\5 \21\2\u0101\u0104"+
		"\5 \21\2\u0102\u0103\7\20\2\2\u0103\u0105\5 \21\2\u0104\u0102\3\2\2\2"+
		"\u0105\u0106\3\2\2\2\u0106\u0104\3\2\2\2\u0106\u0107\3\2\2\2\u0107\u0109"+
		"\3\2\2\2\u0108\u0100\3\2\2\2\u0108\u0101\3\2\2\2\u0109\'\3\2\2\2\u010a"+
		"\u010b\7&\2\2\u010b)\3\2\2\2\u010c\u010d\7&\2\2\u010d+\3\2\2\2\u010e\u010f"+
		"\7&\2\2\u010f-\3\2\2\2\32\65:?OY^fl\u0098\u00a0\u00a2\u00aa\u00b0\u00b4"+
		"\u00bc\u00be\u00c5\u00de\u00ef\u00f1\u00fa\u00fe\u0106\u0108";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}