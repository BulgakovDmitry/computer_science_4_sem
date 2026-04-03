// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.hpp"


// Unqualified %code blocks.
#line 44 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/frontend/src/parser.y"

  #include "config.hpp"
  #include "lexer.hpp"
  #include "error_collector.hpp"
  #include "my_parser.hpp"
  #include <iostream>
  #include <string>

  template<typename T>
  void push_scope(T* parser, nametable_t&& nametable) {
    parser->scopes.push(nametable);
  }

  template<typename T>
  void pop_scope(T* parser) {
    parser->scopes.pop();
  }

  template<typename T>
  bool find_in_scopes(T* parser, std::string& var_name) {
    return parser->scopes.find(var_name);
  }

  template<typename T>
  void add_var_to_scope(T* parser, std::string& var_name, bool defined) {
    parser->scopes.add_variable(var_name, defined);
  }

  int yylex(yy::parser::semantic_type* yylval,
            yy::parser::location_type* yylloc,
            language::Lexer*           scanner) {
    int line_before = scanner->get_line();

    auto tt = scanner->yylex();

    yylloc->begin.line = line_before;
    yylloc->begin.column = scanner->get_column() - scanner->get_yyleng();
    yylloc->end.line = scanner->get_line();
    yylloc->end.column = scanner->get_column();

    if (tt == yy::parser::token::TOK_NUMBER)
        yylval->build<int>() = std::stoi(scanner->YYText());

    if (tt == yy::parser::token::TOK_ID)
        yylval->build<std::string>() = scanner->YYText();

    return tt;
  }

  void yy::parser::error(const location& loc, const std::string& msg) {
    my_parser->error_collector.add_error(loc, msg, my_parser->get_line_content(loc.begin.line));
  }

#line 100 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/build/frontend/parser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 192 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/build/frontend/parser.cpp"

  /// Build a parser object.
  parser::parser (language::Lexer* scanner_yyarg, std::unique_ptr<language::Program> &root_yyarg, language::My_parser* my_parser_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
      root (root_yyarg),
      my_parser (my_parser_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_TOK_NUMBER: // "number"
        value.copy< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression: // expression
      case symbol_kind::S_bitwise_op: // bitwise_op
      case symbol_kind::S_equality: // equality
      case symbol_kind::S_relational: // relational
      case symbol_kind::S_add_sub: // add_sub
      case symbol_kind::S_mul_div: // mul_div
      case symbol_kind::S_unary: // unary
      case symbol_kind::S_primary: // primary
      case symbol_kind::S_assignment_expr: // assignment_expr
        value.copy< language::Expression_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_empty_stmt: // empty_stmt
      case symbol_kind::S_block_stmt: // block_stmt
      case symbol_kind::S_assignment_stmt: // assignment_stmt
      case symbol_kind::S_if_stmt: // if_stmt
      case symbol_kind::S_while_stmt: // while_stmt
      case symbol_kind::S_print_stmt: // print_stmt
        value.copy< language::Statement_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_list: // stmt_list
        value.copy< language::StmtList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TOK_ID: // "identifier"
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  parser::symbol_kind_type
  parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_TOK_NUMBER: // "number"
        value.move< int > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_expression: // expression
      case symbol_kind::S_bitwise_op: // bitwise_op
      case symbol_kind::S_equality: // equality
      case symbol_kind::S_relational: // relational
      case symbol_kind::S_add_sub: // add_sub
      case symbol_kind::S_mul_div: // mul_div
      case symbol_kind::S_unary: // unary
      case symbol_kind::S_primary: // primary
      case symbol_kind::S_assignment_expr: // assignment_expr
        value.move< language::Expression_ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_empty_stmt: // empty_stmt
      case symbol_kind::S_block_stmt: // block_stmt
      case symbol_kind::S_assignment_stmt: // assignment_stmt
      case symbol_kind::S_if_stmt: // if_stmt
      case symbol_kind::S_while_stmt: // while_stmt
      case symbol_kind::S_print_stmt: // print_stmt
        value.move< language::Statement_ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_stmt_list: // stmt_list
        value.move< language::StmtList > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_TOK_ID: // "identifier"
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  parser::symbol_kind_type
  parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  parser::symbol_kind_type
  parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_TOK_NUMBER: // "number"
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression: // expression
      case symbol_kind::S_bitwise_op: // bitwise_op
      case symbol_kind::S_equality: // equality
      case symbol_kind::S_relational: // relational
      case symbol_kind::S_add_sub: // add_sub
      case symbol_kind::S_mul_div: // mul_div
      case symbol_kind::S_unary: // unary
      case symbol_kind::S_primary: // primary
      case symbol_kind::S_assignment_expr: // assignment_expr
        value.YY_MOVE_OR_COPY< language::Expression_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_empty_stmt: // empty_stmt
      case symbol_kind::S_block_stmt: // block_stmt
      case symbol_kind::S_assignment_stmt: // assignment_stmt
      case symbol_kind::S_if_stmt: // if_stmt
      case symbol_kind::S_while_stmt: // while_stmt
      case symbol_kind::S_print_stmt: // print_stmt
        value.YY_MOVE_OR_COPY< language::Statement_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_list: // stmt_list
        value.YY_MOVE_OR_COPY< language::StmtList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TOK_ID: // "identifier"
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_TOK_NUMBER: // "number"
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression: // expression
      case symbol_kind::S_bitwise_op: // bitwise_op
      case symbol_kind::S_equality: // equality
      case symbol_kind::S_relational: // relational
      case symbol_kind::S_add_sub: // add_sub
      case symbol_kind::S_mul_div: // mul_div
      case symbol_kind::S_unary: // unary
      case symbol_kind::S_primary: // primary
      case symbol_kind::S_assignment_expr: // assignment_expr
        value.move< language::Expression_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_empty_stmt: // empty_stmt
      case symbol_kind::S_block_stmt: // block_stmt
      case symbol_kind::S_assignment_stmt: // assignment_stmt
      case symbol_kind::S_if_stmt: // if_stmt
      case symbol_kind::S_while_stmt: // while_stmt
      case symbol_kind::S_print_stmt: // print_stmt
        value.move< language::Statement_ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt_list: // stmt_list
        value.move< language::StmtList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TOK_ID: // "identifier"
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_TOK_NUMBER: // "number"
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_expression: // expression
      case symbol_kind::S_bitwise_op: // bitwise_op
      case symbol_kind::S_equality: // equality
      case symbol_kind::S_relational: // relational
      case symbol_kind::S_add_sub: // add_sub
      case symbol_kind::S_mul_div: // mul_div
      case symbol_kind::S_unary: // unary
      case symbol_kind::S_primary: // primary
      case symbol_kind::S_assignment_expr: // assignment_expr
        value.copy< language::Expression_ptr > (that.value);
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_empty_stmt: // empty_stmt
      case symbol_kind::S_block_stmt: // block_stmt
      case symbol_kind::S_assignment_stmt: // assignment_stmt
      case symbol_kind::S_if_stmt: // if_stmt
      case symbol_kind::S_while_stmt: // while_stmt
      case symbol_kind::S_print_stmt: // print_stmt
        value.copy< language::Statement_ptr > (that.value);
        break;

      case symbol_kind::S_stmt_list: // stmt_list
        value.copy< language::StmtList > (that.value);
        break;

      case symbol_kind::S_TOK_ID: // "identifier"
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_TOK_NUMBER: // "number"
        value.move< int > (that.value);
        break;

      case symbol_kind::S_expression: // expression
      case symbol_kind::S_bitwise_op: // bitwise_op
      case symbol_kind::S_equality: // equality
      case symbol_kind::S_relational: // relational
      case symbol_kind::S_add_sub: // add_sub
      case symbol_kind::S_mul_div: // mul_div
      case symbol_kind::S_unary: // unary
      case symbol_kind::S_primary: // primary
      case symbol_kind::S_assignment_expr: // assignment_expr
        value.move< language::Expression_ptr > (that.value);
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_empty_stmt: // empty_stmt
      case symbol_kind::S_block_stmt: // block_stmt
      case symbol_kind::S_assignment_stmt: // assignment_stmt
      case symbol_kind::S_if_stmt: // if_stmt
      case symbol_kind::S_while_stmt: // while_stmt
      case symbol_kind::S_print_stmt: // print_stmt
        value.move< language::Statement_ptr > (that.value);
        break;

      case symbol_kind::S_stmt_list: // stmt_list
        value.move< language::StmtList > (that.value);
        break;

      case symbol_kind::S_TOK_ID: // "identifier"
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, &yyla.location, scanner));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_TOK_NUMBER: // "number"
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_expression: // expression
      case symbol_kind::S_bitwise_op: // bitwise_op
      case symbol_kind::S_equality: // equality
      case symbol_kind::S_relational: // relational
      case symbol_kind::S_add_sub: // add_sub
      case symbol_kind::S_mul_div: // mul_div
      case symbol_kind::S_unary: // unary
      case symbol_kind::S_primary: // primary
      case symbol_kind::S_assignment_expr: // assignment_expr
        yylhs.value.emplace< language::Expression_ptr > ();
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_empty_stmt: // empty_stmt
      case symbol_kind::S_block_stmt: // block_stmt
      case symbol_kind::S_assignment_stmt: // assignment_stmt
      case symbol_kind::S_if_stmt: // if_stmt
      case symbol_kind::S_while_stmt: // while_stmt
      case symbol_kind::S_print_stmt: // print_stmt
        yylhs.value.emplace< language::Statement_ptr > ();
        break;

      case symbol_kind::S_stmt_list: // stmt_list
        yylhs.value.emplace< language::StmtList > ();
        break;

      case symbol_kind::S_TOK_ID: // "identifier"
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // program: stmt_list TOK_EOF
#line 155 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/frontend/src/parser.y"
                {
                  root = AST_Factory::makeProgram(std::move(yystack_[1].value.as < language::StmtList > ()));
                }
#line 923 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/build/frontend/parser.cpp"
    break;

  case 3: // stmt_list: %empty
#line 161 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/frontend/src/parser.y"
                {
                  yylhs.value.as < language::StmtList > () = language::StmtList{};
                }
#line 931 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/build/frontend/parser.cpp"
    break;

  case 4: // stmt_list: stmt_list statement
#line 165 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/frontend/src/parser.y"
                {
                  yystack_[1].value.as < language::StmtList > ().push_back(std::move(yystack_[0].value.as < language::Statement_ptr > ()));
                  yylhs.value.as < language::StmtList > () = std::move(yystack_[1].value.as < language::StmtList > ());
                }
#line 940 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/build/frontend/parser.cpp"
    break;

  case 5: // statement: assignment_stmt ";"
#line 172 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/frontend/src/parser.y"
                 { yylhs.value.as < language::Statement_ptr > () = std::move(yystack_[1].value.as < language::Statement_ptr > ()); }
#line 946 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/build/frontend/parser.cpp"
    break;

  case 6: // statement: if_stmt
#line 174 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/frontend/src/parser.y"
                 { yylhs.value.as < language::Statement_ptr > () = std::move(yystack_[0].value.as < language::Statement_ptr > ()); }
#line 952 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/build/frontend/parser.cpp"
    break;

  case 7: // statement: while_stmt
#line 176 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/frontend/src/parser.y"
                 { yylhs.value.as < language::Statement_ptr > () = std::move(yystack_[0].value.as < language::Statement_ptr > ()); }
#line 958 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/build/frontend/parser.cpp"
    break;

  case 8: // statement: print_stmt ";"
#line 178 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/frontend/src/parser.y"
                 { yylhs.value.as < language::Statement_ptr > () = std::move(yystack_[1].value.as < language::Statement_ptr > ()); }
#line 964 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/build/frontend/parser.cpp"
    break;

  case 9: // statement: block_stmt
#line 180 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/frontend/src/parser.y"
                 { yylhs.value.as < language::Statement_ptr > () = std::move(yystack_[0].value.as < language::Statement_ptr > ()); }
#line 970 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/build/frontend/parser.cpp"
    break;

  case 10: // statement: empty_stmt
#line 182 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/frontend/src/parser.y"
                 { yylhs.value.as < language::Statement_ptr > () = std::move(yystack_[0].value.as < language::Statement_ptr > ()); }
#line 976 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/build/frontend/parser.cpp"
    break;

  case 11: // empty_stmt: ";"
#line 186 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/frontend/src/parser.y"
                {
                  yylhs.value.as < language::Statement_ptr > () = AST_Factory::makeEmpty();
                }
#line 984 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/build/frontend/parser.cpp"
    break;

  case 12: // $@1: %empty
#line 191 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/frontend/src/parser.y"
                {
                  push_scope(my_parser, nametable_t{});
                }
#line 992 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/build/frontend/parser.cpp"
    break;

  case 13: // block_stmt: "{" $@1 stmt_list "}"
#line 196 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/frontend/src/parser.y"
                {
                  pop_scope(my_parser);
                  yylhs.value.as < language::Statement_ptr > () = AST_Factory::makeBlock(std::move(yystack_[1].value.as < language::StmtList > ()));
                }
#line 1001 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/build/frontend/parser.cpp"
    break;

  case 14: // assignment_stmt: "identifier" "=" expression
#line 203 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/frontend/src/parser.y"
                {
                  auto variable = AST_Factory::makeVariable(std::move(yystack_[2].value.as < std::string > ()));
                  auto var_name = variable->get_name();

                  if (!find_in_scopes(my_parser, var_name))
                    add_var_to_scope(my_parser, var_name, true);

                  yylhs.value.as < language::Statement_ptr > () = AST_Factory::makeAssignmentStmt(
                    std::move(variable),
                    std::move(yystack_[0].value.as < language::Expression_ptr > ()));
                }
#line 1017 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/build/frontend/parser.cpp"
    break;

  case 15: // if_stmt: "if" "(" expression ")" statement
#line 217 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/frontend/src/parser.y"
                {
                  yylhs.value.as < language::Statement_ptr > () = AST_Factory::makeIf(std::move(yystack_[2].value.as < language::Expression_ptr > ()), std::move(yystack_[0].value.as < language::Statement_ptr > ()));
                }
#line 1025 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/build/frontend/parser.cpp"
    break;

  case 16: // if_stmt: "if" "(" expression ")" statement "else" statement
#line 221 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/frontend/src/parser.y"
                {
                  yylhs.value.as < language::Statement_ptr > () = AST_Factory::makeIf(std::move(yystack_[4].value.as < language::Expression_ptr > ()), std::move(yystack_[2].value.as < language::Statement_ptr > ()), std::move(yystack_[0].value.as < language::Statement_ptr > ()));
                }
#line 1033 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/build/frontend/parser.cpp"
    break;

  case 17: // while_stmt: "while" "(" expression ")" statement
#line 227 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/frontend/src/parser.y"
                {
                  yylhs.value.as < language::Statement_ptr > () = AST_Factory::makeWhile(std::move(yystack_[2].value.as < language::Expression_ptr > ()), std::move(yystack_[0].value.as < language::Statement_ptr > ()));
                }
#line 1041 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/build/frontend/parser.cpp"
    break;

  case 18: // print_stmt: "print" expression
#line 233 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/frontend/src/parser.y"
                {
                  yylhs.value.as < language::Statement_ptr > () = AST_Factory::makePrint(std::move(yystack_[0].value.as < language::Expression_ptr > ()));
                }
#line 1049 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/build/frontend/parser.cpp"
    break;

  case 19: // expression: bitwise_op
#line 239 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/frontend/src/parser.y"
                  { yylhs.value.as < language::Expression_ptr > () = std::move(yystack_[0].value.as < language::Expression_ptr > ()); }
#line 1055 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/build/frontend/parser.cpp"
    break;

  case 20: // expression: assignment_expr
#line 241 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/frontend/src/parser.y"
                  { yylhs.value.as < language::Expression_ptr > () = std::move(yystack_[0].value.as < language::Expression_ptr > ()); }
#line 1061 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/build/frontend/parser.cpp"
    break;

  case 21: // bitwise_op: equality
#line 245 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/frontend/src/parser.y"
                  { yylhs.value.as < language::Expression_ptr > () = std::move(yystack_[0].value.as < language::Expression_ptr > ()); }
#line 1067 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/build/frontend/parser.cpp"
    break;

  case 22: // bitwise_op: bitwise_op "&" equality
#line 247 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/frontend/src/parser.y"
                  { yylhs.value.as < language::Expression_ptr > () = AST_Factory::makeBinaryOp(Binary_operators::And, std::move(yystack_[2].value.as < language::Expression_ptr > ()), std::move(yystack_[0].value.as < language::Expression_ptr > ())); }
#line 1073 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/build/frontend/parser.cpp"
    break;

  case 23: // bitwise_op: bitwise_op "^" equality
#line 249 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/frontend/src/parser.y"
                  { yylhs.value.as < language::Expression_ptr > () = AST_Factory::makeBinaryOp(Binary_operators::Xor, std::move(yystack_[2].value.as < language::Expression_ptr > ()), std::move(yystack_[0].value.as < language::Expression_ptr > ())); }
#line 1079 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/build/frontend/parser.cpp"
    break;

  case 24: // bitwise_op: bitwise_op "|" equality
#line 251 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/frontend/src/parser.y"
                  { yylhs.value.as < language::Expression_ptr > () = AST_Factory::makeBinaryOp(Binary_operators::Or, std::move(yystack_[2].value.as < language::Expression_ptr > ()), std::move(yystack_[0].value.as < language::Expression_ptr > ())); }
#line 1085 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/build/frontend/parser.cpp"
    break;

  case 25: // equality: relational
#line 255 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/frontend/src/parser.y"
                 { yylhs.value.as < language::Expression_ptr > () = std::move(yystack_[0].value.as < language::Expression_ptr > ()); }
#line 1091 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/build/frontend/parser.cpp"
    break;

  case 26: // equality: equality "==" relational
#line 257 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/frontend/src/parser.y"
                 { yylhs.value.as < language::Expression_ptr > () = AST_Factory::makeBinaryOp(Binary_operators::Eq,  std::move(yystack_[2].value.as < language::Expression_ptr > ()), std::move(yystack_[0].value.as < language::Expression_ptr > ())); }
#line 1097 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/build/frontend/parser.cpp"
    break;

  case 27: // equality: equality "!=" relational
#line 259 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/frontend/src/parser.y"
                 { yylhs.value.as < language::Expression_ptr > () = AST_Factory::makeBinaryOp(Binary_operators::Neq,  std::move(yystack_[2].value.as < language::Expression_ptr > ()), std::move(yystack_[0].value.as < language::Expression_ptr > ())); }
#line 1103 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/build/frontend/parser.cpp"
    break;

  case 28: // relational: add_sub
#line 263 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/frontend/src/parser.y"
                 { yylhs.value.as < language::Expression_ptr > () = std::move(yystack_[0].value.as < language::Expression_ptr > ()); }
#line 1109 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/build/frontend/parser.cpp"
    break;

  case 29: // relational: relational "<" add_sub
#line 265 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/frontend/src/parser.y"
                 { yylhs.value.as < language::Expression_ptr > () = AST_Factory::makeBinaryOp(Binary_operators::Less, std::move(yystack_[2].value.as < language::Expression_ptr > ()), std::move(yystack_[0].value.as < language::Expression_ptr > ())); }
#line 1115 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/build/frontend/parser.cpp"
    break;

  case 30: // relational: relational "<=" add_sub
#line 267 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/frontend/src/parser.y"
                 { yylhs.value.as < language::Expression_ptr > () = AST_Factory::makeBinaryOp(Binary_operators::LessEq, std::move(yystack_[2].value.as < language::Expression_ptr > ()), std::move(yystack_[0].value.as < language::Expression_ptr > ())); }
#line 1121 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/build/frontend/parser.cpp"
    break;

  case 31: // relational: relational ">" add_sub
#line 269 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/frontend/src/parser.y"
                 { yylhs.value.as < language::Expression_ptr > () = AST_Factory::makeBinaryOp(Binary_operators::Greater, std::move(yystack_[2].value.as < language::Expression_ptr > ()), std::move(yystack_[0].value.as < language::Expression_ptr > ())); }
#line 1127 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/build/frontend/parser.cpp"
    break;

  case 32: // relational: relational ">=" add_sub
#line 271 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/frontend/src/parser.y"
                 { yylhs.value.as < language::Expression_ptr > () = AST_Factory::makeBinaryOp(Binary_operators::GreaterEq, std::move(yystack_[2].value.as < language::Expression_ptr > ()), std::move(yystack_[0].value.as < language::Expression_ptr > ())); }
#line 1133 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/build/frontend/parser.cpp"
    break;

  case 33: // add_sub: mul_div
#line 275 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/frontend/src/parser.y"
                 { yylhs.value.as < language::Expression_ptr > () = std::move(yystack_[0].value.as < language::Expression_ptr > ()); }
#line 1139 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/build/frontend/parser.cpp"
    break;

  case 34: // add_sub: add_sub "+" mul_div
#line 277 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/frontend/src/parser.y"
                 { yylhs.value.as < language::Expression_ptr > () = AST_Factory::makeBinaryOp(Binary_operators::Add, std::move(yystack_[2].value.as < language::Expression_ptr > ()), std::move(yystack_[0].value.as < language::Expression_ptr > ())); }
#line 1145 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/build/frontend/parser.cpp"
    break;

  case 35: // add_sub: add_sub "-" mul_div
#line 279 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/frontend/src/parser.y"
                 { yylhs.value.as < language::Expression_ptr > () = AST_Factory::makeBinaryOp(Binary_operators::Sub, std::move(yystack_[2].value.as < language::Expression_ptr > ()), std::move(yystack_[0].value.as < language::Expression_ptr > ())); }
#line 1151 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/build/frontend/parser.cpp"
    break;

  case 36: // mul_div: unary
#line 283 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/frontend/src/parser.y"
                 { yylhs.value.as < language::Expression_ptr > () = std::move(yystack_[0].value.as < language::Expression_ptr > ()); }
#line 1157 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/build/frontend/parser.cpp"
    break;

  case 37: // mul_div: mul_div "*" unary
#line 285 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/frontend/src/parser.y"
                 { yylhs.value.as < language::Expression_ptr > () = AST_Factory::makeBinaryOp(Binary_operators::Mul, std::move(yystack_[2].value.as < language::Expression_ptr > ()), std::move(yystack_[0].value.as < language::Expression_ptr > ())); }
#line 1163 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/build/frontend/parser.cpp"
    break;

  case 38: // mul_div: mul_div "/" unary
#line 287 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/frontend/src/parser.y"
                 { yylhs.value.as < language::Expression_ptr > () = AST_Factory::makeBinaryOp(Binary_operators::Div, std::move(yystack_[2].value.as < language::Expression_ptr > ()), std::move(yystack_[0].value.as < language::Expression_ptr > ())); }
#line 1169 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/build/frontend/parser.cpp"
    break;

  case 39: // mul_div: mul_div "%" unary
#line 289 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/frontend/src/parser.y"
                 { yylhs.value.as < language::Expression_ptr > () = AST_Factory::makeBinaryOp(Binary_operators::RemDiv, std::move(yystack_[2].value.as < language::Expression_ptr > ()), std::move(yystack_[0].value.as < language::Expression_ptr > ())); }
#line 1175 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/build/frontend/parser.cpp"
    break;

  case 40: // unary: "-" unary
#line 293 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/frontend/src/parser.y"
                { yylhs.value.as < language::Expression_ptr > () = AST_Factory::makeUnaryOp(Unary_operators::Neg, std::move(yystack_[0].value.as < language::Expression_ptr > ())); }
#line 1181 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/build/frontend/parser.cpp"
    break;

  case 41: // unary: "+" unary
#line 295 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/frontend/src/parser.y"
                { yylhs.value.as < language::Expression_ptr > () = AST_Factory::makeUnaryOp(Unary_operators::Neg, std::move(yystack_[0].value.as < language::Expression_ptr > ())); }
#line 1187 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/build/frontend/parser.cpp"
    break;

  case 42: // unary: "!" unary
#line 297 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/frontend/src/parser.y"
                { yylhs.value.as < language::Expression_ptr > () = AST_Factory::makeUnaryOp(Unary_operators::Not, std::move(yystack_[0].value.as < language::Expression_ptr > ())); }
#line 1193 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/build/frontend/parser.cpp"
    break;

  case 43: // unary: primary
#line 299 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/frontend/src/parser.y"
                { yylhs.value.as < language::Expression_ptr > () = std::move(yystack_[0].value.as < language::Expression_ptr > ()); }
#line 1199 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/build/frontend/parser.cpp"
    break;

  case 44: // primary: "number"
#line 303 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/frontend/src/parser.y"
                { yylhs.value.as < language::Expression_ptr > () = AST_Factory::makeNumber(yystack_[0].value.as < int > ()); }
#line 1205 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/build/frontend/parser.cpp"
    break;

  case 45: // primary: "identifier"
#line 305 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/frontend/src/parser.y"
                {
                  auto variable = AST_Factory::makeVariable(std::move(yystack_[0].value.as < std::string > ()));
                  if (!find_in_scopes(my_parser, variable->get_name())) {
                    error(yystack_[0].location, "\'" + variable->get_name() + "\' was not declared in this scope");
                  }

                  yylhs.value.as < language::Expression_ptr > () = std::move(variable);
                }
#line 1218 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/build/frontend/parser.cpp"
    break;

  case 46: // primary: "(" expression ")"
#line 314 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/frontend/src/parser.y"
                { yylhs.value.as < language::Expression_ptr > () = std::move(yystack_[1].value.as < language::Expression_ptr > ()); }
#line 1224 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/build/frontend/parser.cpp"
    break;

  case 47: // primary: "?"
#line 316 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/frontend/src/parser.y"
                { yylhs.value.as < language::Expression_ptr > () = AST_Factory::makeInput(); }
#line 1230 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/build/frontend/parser.cpp"
    break;

  case 48: // assignment_expr: "identifier" "=" expression
#line 320 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/frontend/src/parser.y"
                {
                  auto variable = AST_Factory::makeVariable(std::move(yystack_[2].value.as < std::string > ()));
                  auto var_name = variable->get_name();

                  if (!find_in_scopes(my_parser, var_name))
                    add_var_to_scope(my_parser, var_name, true);

                  yylhs.value.as < language::Expression_ptr > () = AST_Factory::makeAssignmentExpr(
                    std::move(variable),
                    std::move(yystack_[0].value.as < language::Expression_ptr > ()));
                }
#line 1246 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/build/frontend/parser.cpp"
    break;


#line 1250 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/build/frontend/parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  const char *
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    static const char *const yy_sname[] =
    {
    "TOK_EOF", "error", "invalid token", "PREC_IFX", "if", "else", "while",
  "print", "?", "+", "-", "*", "/", "%", "&", "^", "|", "!", "=", "==",
  "!=", "<", ">", "<=", ">=", "(", ")", "{", "}", ";", "identifier",
  "number", "$accept", "program", "stmt_list", "statement", "empty_stmt",
  "block_stmt", "$@1", "assignment_stmt", "if_stmt", "while_stmt",
  "print_stmt", "expression", "bitwise_op", "equality", "relational",
  "add_sub", "mul_div", "unary", "primary", "assignment_expr", YY_NULLPTR
    };
    return yy_sname[yysymbol];
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -51;

  const signed char parser::yytable_ninf_ = -1;

  const signed char
  parser::yypact_[] =
  {
     -51,     4,     3,   -51,   -51,   -17,    -6,    42,   -51,   -51,
      27,   -51,   -51,   -51,     2,   -51,   -51,    18,    42,    42,
     -51,    45,    45,    45,    42,    43,   -51,   -51,    13,    -7,
      56,     7,    70,   -51,   -51,   -51,   -51,    42,   -51,   -51,
      -4,    34,   -51,   -51,   -51,   -51,    48,    42,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    14,   -51,    19,    19,   -51,   -51,    -7,    -7,
      -7,    56,    56,     7,     7,     7,     7,    70,    70,   -51,
     -51,   -51,   -51,    66,   -51,    19,   -51
  };

  const signed char
  parser::yydefact_[] =
  {
       3,     0,     0,     1,     2,     0,     0,     0,    12,    11,
       0,     4,    10,     9,     0,     6,     7,     0,     0,     0,
      47,     0,     0,     0,     0,    45,    44,    18,    19,    21,
      25,    28,    33,    36,    43,    20,     3,     0,     5,     8,
       0,     0,    45,    41,    40,    42,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    14,     0,     0,    46,    48,    22,    23,
      24,    26,    27,    29,    31,    30,    32,    34,    35,    37,
      38,    39,    13,    15,    17,     0,    16
  };

  const signed char
  parser::yypgoto_[] =
  {
     -51,   -51,    49,   -50,   -51,   -51,   -51,   -51,   -51,   -51,
     -51,   -13,   -51,     8,   -15,    10,    11,   -21,   -51,   -51
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     1,     2,    11,    12,    13,    36,    14,    15,    16,
      17,    27,    28,    29,    30,    31,    32,    33,    34,    35
  };

  const signed char
  parser::yytable_[] =
  {
      43,    44,    45,     4,     3,    40,    41,     5,    18,     6,
       7,    46,    51,    52,    83,    84,    57,    58,     5,    19,
       6,     7,    64,     5,    63,     6,     7,    48,    49,    50,
       8,    38,     9,    10,    67,    86,    71,    72,    79,    80,
      81,     8,    82,     9,    10,    37,     8,    39,     9,    10,
      20,    21,    22,    20,    21,    22,    68,    69,    70,    23,
      65,    47,    23,    73,    74,    75,    76,    24,    77,    78,
      24,    85,    25,    26,    66,    42,    26,    53,    54,    55,
      56,    59,    60,    61,     0,    62
  };

  const signed char
  parser::yycheck_[] =
  {
      21,    22,    23,     0,     0,    18,    19,     4,    25,     6,
       7,    24,    19,    20,    64,    65,     9,    10,     4,    25,
       6,     7,    26,     4,    37,     6,     7,    14,    15,    16,
      27,    29,    29,    30,    47,    85,    51,    52,    59,    60,
      61,    27,    28,    29,    30,    18,    27,    29,    29,    30,
       8,     9,    10,     8,     9,    10,    48,    49,    50,    17,
      26,    18,    17,    53,    54,    55,    56,    25,    57,    58,
      25,     5,    30,    31,    26,    30,    31,    21,    22,    23,
      24,    11,    12,    13,    -1,    36
  };

  const signed char
  parser::yystos_[] =
  {
       0,    33,    34,     0,     0,     4,     6,     7,    27,    29,
      30,    35,    36,    37,    39,    40,    41,    42,    25,    25,
       8,     9,    10,    17,    25,    30,    31,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    38,    18,    29,    29,
      43,    43,    30,    49,    49,    49,    43,    18,    14,    15,
      16,    19,    20,    21,    22,    23,    24,     9,    10,    11,
      12,    13,    34,    43,    26,    26,    26,    43,    45,    45,
      45,    46,    46,    47,    47,    47,    47,    48,    48,    49,
      49,    49,    28,    35,    35,     5,    35
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    32,    33,    34,    34,    35,    35,    35,    35,    35,
      35,    36,    38,    37,    39,    40,    40,    41,    42,    43,
      43,    44,    44,    44,    44,    45,    45,    45,    46,    46,
      46,    46,    46,    47,    47,    47,    48,    48,    48,    48,
      49,    49,    49,    49,    50,    50,    50,    50,    51
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     2,     0,     2,     2,     1,     1,     2,     1,
       1,     1,     0,     4,     3,     5,     7,     5,     2,     1,
       1,     1,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       2,     2,     2,     1,     1,     1,     3,     1,     3
  };




#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   154,   154,   161,   164,   171,   173,   175,   177,   179,
     181,   185,   191,   190,   202,   216,   220,   226,   232,   238,
     240,   244,   246,   248,   250,   254,   256,   258,   262,   264,
     266,   268,   270,   274,   276,   278,   282,   284,   286,   288,
     292,   294,   296,   298,   302,   304,   313,   315,   319
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  parser::symbol_kind_type
  parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31
    };
    // Last valid token kind.
    const int code_max = 286;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // yy
#line 1772 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/build/frontend/parser.cpp"

#line 332 "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/frontend/src/parser.y"

