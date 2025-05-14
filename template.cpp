#include <climits>
#include <cmath>
#include <concepts>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <ranges>
#include <utility>
#include <vector>

// NOLINTBEGIN(misc-unused-using-decls)
using ::std::ranges::views::iota;
// NOLINTEND(misc-unused-using-decls)
using namespace ::std;
namespace views = ::std::ranges::views;	 // NOLINT(misc-unused-alias-decls)

#define debug(x)                                                        \
	do {                                                            \
		std::cerr << "\033[33m(line " << __LINE__ << ") " << #x \
			  << " = " << (x) << "\033[m" << std::endl;     \
	} while (0)
#define zzz IGNORE_INDIRECT(__LINE__)
#define IGNORE_INDIRECT(id) IGNORE_INNER(id)
#define IGNORE_INNER(id) dummy_unused_##id [[maybe_unused]]

namespace util {

using i8 = std::int8_t;
using s8 = std::byte;
using i16 = std::int16_t;
using s16 = std::uint16_t;
using i32 = std::int32_t;
using s32 = std::uint32_t;
using i64 = std::int64_t;
using s64 = std::uint64_t;

using f32 = float;
using f64 = double;

constexpr char nl [[maybe_unused]] = '\n';
constexpr i32 INF [[maybe_unused]] = INT_MAX / 2;
constexpr i64 INFL [[maybe_unused]] = LONG_MAX / 2;
constexpr f64 EPS [[maybe_unused]] = 1e-10;

template <std::floating_point T, std::floating_point S>
[[nodiscard]]
inline auto fequal(T f, S g) -> bool {
	return std::abs(f - g) < EPS;
}

template <std::totally_ordered T>
inline auto assign_max(T& lhs, T rhs) -> bool {
	if (lhs < rhs) {
		lhs = rhs;
		return true;
	}
	return false;
}

template <std::totally_ordered T>
inline auto assign_min(T& lhs, T rhs) -> bool {
	if (lhs > rhs) {
		lhs = rhs;
		return true;
	}
	return false;
}

constexpr std::array<std::pair<i32, i32>, 4> around [[maybe_unused]]{
    std::pair{-1, 0}, std::pair{1, 0}, std::pair{0, -1}, std::pair{0, 1}};

}  // namespace util
using namespace ::util;

int main(int argc [[maybe_unused]], char* argv [[maybe_unused]][]) {
	i32 sum{0};
	for (auto i : iota(0, 10)) {
		debug(i);
		sum += i;
	}
	cout << sum << nl;

	// TODO
	std::cout << std::flush;
	return 0;
}
