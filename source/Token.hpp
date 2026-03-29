#pragma once

#include <cstdint>
#include <string_view>


namespace token {
namespace detail {
template<typename... Fs>
struct Overload : Fs... {
    using Fs::operator()...;
};

enum class Type {
    Number,
    Integer,
    UnsignedInteger,
    Identifier,

    LeftParen,
    RightParen,
    LeftBracket,
    RightBracket,
    LeftBrace,
    RightBrace,

    Equals,
    NotEquals,
    Greater,
    GreaterEquals,
    Less,
    LessEquals,

    Plus,
    Minus,
    Asteriks,
    Slash,
};
}

struct Token {
    template<typename... Fs>
    decltype(auto) match(Fs &&... cases) {
        auto f = detail::Overload<Fs...>{std::forward<Fs>(cases)...};
        switch (type) {
            case detail::Type::Number:
                return f(data.number);
            case detail::Type::Integer:
                return f(data.integer);
            case detail::Type::UnsignedInteger:
                return f(data.unsigned_integer);
            case detail::Type::Identifier:
                return f(data.identifier);
            case detail::Type::LeftParen:
                return f(data.left_paren);
            case detail::Type::RightParen:
                return f(data.right_paren);
            case detail::Type::LeftBracket:
                return f(data.left_bracket);
            case detail::Type::RightBracket:
                return f(data.right_bracket);
            case detail::Type::LeftBrace:
                return f(data.left_brace);
            case detail::Type::RightBrace:
                return f(data.right_brace);
            case detail::Type::Equals:
                return f(data.equals);
            case detail::Type::NotEquals:
                return f(data.not_equals);
            case detail::Type::Greater:
                return f(data.greater);
            case detail::Type::GreaterEquals:
                return f(data.greater_equals);
            case detail::Type::Less:
                return f(data.less);
            case detail::Type::LessEquals:
                return f(data.less_equals);
            case detail::Type::Plus:
                return f(data.plus);
            case detail::Type::Minus:
                return f(data.minus);
            case detail::Type::Asteriks:
                return f(data.asteriks);
            case detail::Type::Slash:
                return f(data.slash);
        }
    }

    struct Number {
        double data;
    };

    struct Integer {
        int64_t data;
    };

    struct UnsignedInteger {
        uint64_t data;
    };

    struct Identifier {
        std::string_view data;
    };

    struct LeftParen {
    };

    struct RightParen {
    };

    struct LeftBracket {
    };

    struct RightBracket {
    };

    struct LeftBrace {
    };

    struct RightBrace {
    };

    struct Equals {
    };

    struct NotEquals {
    };

    struct Greater {
    };

    struct GreaterEquals {
    };

    struct Less {
    };

    struct LessEquals {
    };

    struct Plus {
    };

    struct Minus {
    };

    struct Asteriks {
    };

    struct Slash {
    };

    static Token number(double data) {
        Token ret;
        ret.type = detail::Type::Number;
        ret.data.number = {data};
        return ret;
    }

    static Token integer(int64_t data) {
        Token ret;
        ret.type = detail::Type::Integer;
        ret.data.integer = {data};
        return ret;
    }

    static Token unsignedInteger(uint64_t data) {
        Token ret;
        ret.type = detail::Type::UnsignedInteger;
        ret.data.unsigned_integer = {data};
        return ret;
    }

    static Token identifier(std::string_view data) {
        Token ret;
        ret.type = detail::Type::Identifier;
        ret.data.identifier = {data};
        return ret;
    }

    static Token leftParen() {
        Token ret;
        ret.type = detail::Type::LeftParen;
        ret.data.left_paren = {};
        return ret;
    }

    static Token rightParen() {
        Token ret;
        ret.type = detail::Type::RightParen;
        ret.data.right_paren = {};
        return ret;
    }

    static Token leftBracket() {
        Token ret;
        ret.type = detail::Type::LeftBracket;
        ret.data.left_bracket = {};
        return ret;
    }

    static Token rightBracket() {
        Token ret;
        ret.type = detail::Type::RightBracket;
        ret.data.right_bracket = {};
        return ret;
    }

    static Token leftBrace() {
        Token ret;
        ret.type = detail::Type::LeftBrace;
        ret.data.left_brace = {};
        return ret;
    }

    static Token rightBrace() {
        Token ret;
        ret.type = detail::Type::RightBrace;
        ret.data.right_brace = {};
        return ret;
    }

    static Token equals() {
        Token ret;
        ret.type = detail::Type::Equals;
        ret.data.equals = {};
        return ret;
    }

    static Token notEquals() {
        Token ret;
        ret.type = detail::Type::NotEquals;
        ret.data.not_equals = {};
        return ret;
    }

    static Token greater() {
        Token ret;
        ret.type = detail::Type::Greater;
        ret.data.greater = {};
        return ret;
    }

    static Token greater_equals() {
        Token ret;
        ret.type = detail::Type::GreaterEquals;
        ret.data.greater_equals = {};
        return ret;
    }

    static Token plus() {
        Token ret;
        ret.type = detail::Type::Plus;
        ret.data.plus = {};
        return ret;
    }

    static Token minus() {
        Token ret;
        ret.type = detail::Type::Minus;
        ret.data.minus = {};
        return ret;
    }

    static Token asteriks() {
        Token ret;
        ret.type = detail::Type::Asteriks;
        ret.data.asteriks = {};
        return ret;
    }

    static Token slash() {
        Token ret;
        ret.type = detail::Type::Slash;
        ret.data.slash = {};
        return ret;
    }

private:
    detail::Type type = {};

    union {
        Number number;
        Integer integer;
        UnsignedInteger unsigned_integer;
        Identifier identifier;

        LeftParen left_paren;
        RightParen right_paren;
        LeftBracket left_bracket;
        RightBracket right_bracket;
        LeftBrace left_brace;
        RightBrace right_brace;

        Equals equals;
        NotEquals not_equals;
        Greater greater;
        GreaterEquals greater_equals;
        Less less;
        LessEquals less_equals;

        Plus plus;
        Minus minus;
        Asteriks asteriks;
        Slash slash;
    } data = {};
};
}
