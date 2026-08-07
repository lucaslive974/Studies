#pragma once
#include <cassert>

namespace Error {
template <typename = void> static constexpr void errorNYI(const char *msg) { static_assert(false); }

} // namespace Error
