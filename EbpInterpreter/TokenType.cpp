enum class TokenType {
    
    // Single character tokens.
    LEFT_PARENTH, RIGHT_PARENTH, LEFT_BRACE, RIGHT_BRACE,
    COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,

    // One or two character tokens.
    BANG, BANG_EQUAL, EQUAL, EQUAL_EQUAL, GREATER,
    GREATER_EQUAL, LESS, LESS_EQUAL,

    // Literals.
    IDENTIFIER, STRING, NUMBER,

    // Keywords.
    AND, CLASS, ELSE, FALSE, FUN, FOR,
    IF, NULL, OR, PRINT, RETURN, SUPRER,
    THIS, TRUE, VAR, WHILE, 

    EOF

};