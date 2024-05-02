%{
int COMMENT = 0;
%}

identifier [a-zA-Z_][a-zA-Z0-9_]*

%%

#.*\n { printf("%s - This is a PREPROCESSOR DIRECTIVE\n", yytext); }

auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while {
    printf("%s - This is a KEYWORD\n", yytext);
}

{COMMENT = 1;}
\/\* {COMMENT = 1;}

\*\/ {COMMENT = 0;}

{identifier}\( { if (!COMMENT) printf("%s - FUNCTION\n", yytext); }
{identifier}(\[[0-9]*\])? { if (!COMMENT) printf("%s - IDENTIFIER\n", yytext); }

\".*\" { if (!COMMENT) printf("%s - STRING\n", yytext); }

[0-9]+ { if (!COMMENT) printf("%s - NUMBER\n", yytext); }

\( { if (!COMMENT) printf("BLOCK BEGINS\n"); }

\{ { if (!COMMENT) printf("BLOCK BEGINS\n"); }

\} { if (!COMMENT) printf("BLOCK ENDS\n"); }

\) { if (!COMMENT) printf(")\n"); }

= { if (!COMMENT) printf("%s - ASSIGNMENT OPERATOR\n", yytext); }
\+=|\-=|\/=|%=|<<=|>>=|&=|\^=|\|=|=\* { if (!COMMENT) printf("%s - ASSIGNMENT OPERATOR\n", yytext); }

\<=|\>=|==|!= { if (!COMMENT) printf("%s - RELATIONAL OPERATOR\n", yytext); }

\&\&|\|\| { if (!COMMENT) printf("%s - LOGICAL OPERATOR\n", yytext); }

\+|\-|\*|\/|\% { if (!COMMENT) printf("%s - ARITHMETIC OPERATOR\n", yytext); }

\<|\> { if (!COMMENT) printf("%s - RELATIONAL OPERATOR\n", yytext); }

\,|; { if (!COMMENT) printf("%s - SEPARATOR\n", yytext); }

[ \t]+ {}

\n { if (!COMMENT) printf("NEWLINE\n"); }

. { if (!COMMENT) printf("INVALID CHARACTER\n"); }

%%

int main(int argc, char **argv) {
    FILE *file;
    file = fopen("input.c", "r");
    if (!file) {
        printf("Could not open the file\n");
        exit(0);
    }
    yyin = file;
    yylex();
    printf("\n");
    return 0;
}

int yywrap() {
    return 1;
}
