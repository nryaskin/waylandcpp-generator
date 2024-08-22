#pragma once

#include <string>
#include <variant>

namespace language {
    class static_keyword_t {
    public:
        constexpr static_keyword_t() {}
        static constexpr std::string keyword = "static";
    };

    class extern_keyword_t {
    public:
        constexpr extern_keyword_t() {}
        static constexpr std::string keyword = "extern";
    };

    class constexpr_keyword_t {
    public:
        constexpr constexpr_keyword_t() {}
        static constexpr std::string keyword = "constexpr";
    };

    class volatile_keyword_t {
    public:
        constexpr volatile_keyword_t() {}
        static constexpr std::string keyword = "volatile";
    };

    class const_keyword_t {
    public:
        constexpr const_keyword_t() {}
        static constexpr std::string keyword = "const";
    };

    class if_keyword_t {
    public:
        constexpr if_keyword_t() {}
        static constexpr std::string keyword = "if";
    };

    class switch_keyword_t {
    public:
        constexpr switch_keyword_t() {}
        static constexpr std::string keyword = "switch";
    };

    class case_keyword_t {
    public:
        constexpr case_keyword_t() {}
        static constexpr std::string keyword = "case";
    };

    class for_keyword_t {
    public:
        constexpr for_keyword_t() {}
        static constexpr std::string keyword = "for";
    };

    class while_keyword_t {
    public:
        constexpr while_keyword_t() {}
        static constexpr std::string keyword = "while";
    };

    class default_keyword_t {
    public:
        constexpr default_keyword_t() {}
        static constexpr std::string keyword = "default";
    };

    class goto_keyword_t {
    public:
        constexpr goto_keyword_t() {}
        static constexpr std::string keyword = "goto";
    };
    
    class break_keyword_t {
    public:
        constexpr break_keyword_t() {}
        static constexpr std::string keyword = "break";
    };

    class continue_keyword_t {
    public:
        constexpr continue_keyword_t() {}
        static constexpr std::string keyword = "continue";
    };

    class return_keyword_t {
    public:
        constexpr return_keyword_t() {}
        static constexpr std::string keyword = "return";
    };

    class public_keyword_t {
    public:
        constexpr public_keyword_t() {}
        static constexpr std::string keyword = "public";
    };

    class protected_keyword_t {
    public:
        constexpr protected_keyword_t() {}
        static constexpr std::string keyword = "protected";
    };

    class private_keyword_t {
    public:
        constexpr private_keyword_t() {}
        static constexpr std::string keyword = "private";
    };

    class class_keyword_t {
    public:
        constexpr class_keyword_t() {}
        static constexpr std::string keyword = "class";
    };

    class struct_keyword_t {
    public:
        constexpr struct_keyword_t() {}
        static constexpr std::string keyword = "struct";
    };

    class union_keyword_t {
    public:
        constexpr union_keyword_t() {}
        static constexpr std::string keyword = "union";
    };

    class enum_keyword_t {
    public:
        constexpr enum_keyword_t() {}
        static constexpr std::string keyword = "enum";
    };

    class virtual_keyword_t {
    public:
        constexpr virtual_keyword_t() {}
        static constexpr std::string keyword = "virtual";

    };
    class namespace_keyword_t {
    public:
        constexpr namespace_keyword_t() {}
        static constexpr std::string keyword = "namespace";
    };

    class using_keyword_t {
    public:
        constexpr using_keyword_t() {}
        static constexpr std::string keyword = "using";
    };

    using keyword_t = std::variant<static_keyword_t, extern_keyword_t,
                                   constexpr_keyword_t, volatile_keyword_t,
                                   const_keyword_t,
                                   if_keyword_t, switch_keyword_t,
                                   case_keyword_t,
                                   for_keyword_t, while_keyword_t,
                                   default_keyword_t, goto_keyword_t,
                                   break_keyword_t, continue_keyword_t, return_keyword_t,
                                   public_keyword_t, protected_keyword_t, private_keyword_t,
                                   namespace_keyword_t, class_keyword_t, struct_keyword_t, union_keyword_t, enum_keyword_t,
                                   virtual_keyword_t, using_keyword_t>;

    static constexpr keyword_t static_keyword = static_keyword_t {};
    static constexpr keyword_t extern_keyword = extern_keyword_t {};
    static constexpr keyword_t constexpr_keyword = constexpr_keyword_t {};
    static constexpr keyword_t volatile_keyword = volatile_keyword_t {};
    static constexpr keyword_t const_keyword = const_keyword_t {};
    static constexpr keyword_t if_keyword = if_keyword_t {};
    static constexpr keyword_t switch_keyword = switch_keyword_t {};
    static constexpr keyword_t case_keyword = case_keyword_t {};
    static constexpr keyword_t for_keyword = for_keyword_t {};
    static constexpr keyword_t while_keyword = while_keyword_t {};
    static constexpr keyword_t default_keyword = default_keyword_t {};
    static constexpr keyword_t goto_keyword = goto_keyword_t {};
    static constexpr keyword_t break_keyword = break_keyword_t {};
    static constexpr keyword_t continue_keyword = continue_keyword_t {};
    static constexpr keyword_t return_keyword = return_keyword_t {};
    static constexpr keyword_t public_keyword = public_keyword_t {};
    static constexpr keyword_t protected_keyword = protected_keyword_t {};
    static constexpr keyword_t private_keyword = private_keyword_t {};
    static constexpr keyword_t class_keyword = class_keyword_t {};
    static constexpr keyword_t struct_keyword = struct_keyword_t {};
    static constexpr keyword_t union_keyword = union_keyword_t {};
    static constexpr keyword_t virtual_keyword = virtual_keyword_t {};
    static constexpr keyword_t enum_keyword = enum_keyword_t {};
    static constexpr keyword_t namespace_keyword = namespace_keyword_t {};
    static constexpr keyword_t using_keyword = using_keyword_t {};
};
