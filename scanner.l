%{
#include "include/tokens.h"
#include "src/main.c"
#include "include/comp_dict.h"
%}

DIGIT [0-9]
ID [a-zA-Z"_"][a-zA-Z"_"{DIGIT}]*
LIT_INT "-"?{DIGIT}+
LIT_FLOAT {LIT_INT}"."{DIGIT}+
LIT_FALSE false
LIT_TRUE true
LIT_CHAR '(\\.|[^\\'])+\'
LIT_STRING \"(\\.|[^\\"])*\"

%%
int { return TK_PR_INT; }
float { return TK_PR_FLOAT; }
bool { return TK_PR_BOOL; }
char { return TK_PR_CHAR; }
string { return TK_PR_STRING; }
if { return TK_PR_IF; }
then { return TK_PR_THEN; }
else { return TK_PR_ELSE; }
while { return TK_PR_WHILE; }
do { return TK_PR_DO; }
input { return TK_PR_INPUT; }
output { return TK_PR_OUTPUT; }
return { return TK_PR_RETURN; }

[-,;:\(\)\[\]\{\}+*/<>=!&$] { return yytext[0]; }

"<=" { return TK_OC_LE; }
">=" { return TK_OC_GE; }
"==" { return TK_OC_EQ; }
"!=" { return TK_OC_NE; }
"&&" { return TK_OC_AND; }
"||" { return TK_OC_OR; }

{LIT_INT} { if(dicionarioProcuraChave(dicionario,yytext) == 0)
			{
				dicionarioInsereItem(dicionario,TK_LIT_INT);
				return TK_LIT_INT;
			} else return TK_LIT_INT; }
			
{LIT_FLOAT} {if(dicionarioProcuraChave(dicionario,yytext) == 0)
			{
				dicionarioInsereItem(dicionario,TK_LIT_FLOAT);
				return TK_LIT_FLOAT;
			} else return TK_LIT_FLOAT; }
			
{LIT_FALSE} { if(dicionarioProcuraChave(dicionario,yytext) == 0)
			{
				dicionarioInsereItem(dicionario,TK_LIT_FALSE);
				return TK_LIT_FALSE;
			} else return TK_LIT_FALSE; }
			
{LIT_TRUE} { if(dicionarioProcuraChave(dicionario,yytext) == 0)
			{
				dicionarioInsereItem(dicionario,TK_LIT_TRUE);
				return TK_LIT_TRUE;
			} else return TK_LIT_TRUE; }
			
{LIT_CHAR} { if(dicionarioProcuraChave(dicionario,yytext) == 0)
			{
				dicionarioInsereItem(dicionario,TK_LIT_CHAR);
				return TK_LIT_CHAR;
			} else return TK_LIT_CHAR; }
			
{LIT_STRING} {if(dicionarioProcuraChave(dicionario,yytext) == 0)
			{
				dicionarioInsereItem(dicionario,TK_LIT_STRING);
				return TK_LIT_STRING;
			} else return TK_LIT_STRING; }

{ID} {if(dicionarioProcuraChave(dicionario,yytext) == 0)
			{
				dicionarioInsereItem(dicionario,TK_IDENTIFICADOR);
				return TK_IDENTIFICADOR;
			} else return TK_IDENTIFICADOR; }




. { return TOKEN_ERRO; }
%%
