#pragma once

#include <cstdint>
#include <set>
#include <string>

namespace types {
struct Login {
    std::string value;
};

struct Password {
    std::string value;  // don't mind that, obviously super stupid code
};

struct User {
    const Login login;
    const Password password;
    const std::set<std::uint32_t>
        taxpayers;  // tax payers' ids on behalf of which the user can submit
                    // reports
};

bool operator==(const Login&, const Login&);
bool operator<(const User&, const User&);
bool operator<(const User&, const Login&);
bool operator<(const Login&, const User&);
}  // namespace types