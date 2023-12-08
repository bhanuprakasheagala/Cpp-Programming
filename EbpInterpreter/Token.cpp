#include "TokenType.cpp"

class Token {
    public:
        const TokenType type;
        const std::string lexeme;
        const std::string literal;
        const int line;

        Token(TokenType type, const std::string& lexeme, const std::string& literal, int line)
        : type(type), lexeme(lexeme), literal(literal), line(line) {}

        friend std::ostream& operator<<(std::ostream& os, const Token& token) {
            os << static_cast<int>(token.type) << " " << token.lexeme << " " << token.literal;
            return os;
        }
};