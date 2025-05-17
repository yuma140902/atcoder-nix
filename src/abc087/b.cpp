#include <algorithm>
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

[[maybe_unused]] constexpr char nl = '\n';
[[maybe_unused]] constexpr i32 INF = INT_MAX / 2;
[[maybe_unused]] constexpr i64 INFL = LONG_MAX / 2;
[[maybe_unused]] constexpr f64 EPS = 1e-10;

template <std::floating_point T, std::floating_point S>
[[nodiscard]]
constexpr inline auto fequal(T f, S g) -> bool {
	return std::abs(f - g) < EPS;
}

template <std::totally_ordered T>
constexpr inline auto assign_max(T& lhs, T rhs) -> bool {
	if (lhs < rhs) {
		lhs = rhs;
		return true;
	}
	return false;
}

template <std::totally_ordered T>
constexpr inline auto assign_min(T& lhs, T rhs) -> bool {
	if (lhs > rhs) {
		lhs = rhs;
		return true;
	}
	return false;
}

template <class T, class Id>
struct newtype {
	T value;
	explicit constexpr newtype(T&& v) : value{std::forward<T>(v)} {}

	constexpr newtype() = default;
	~newtype() = default;
	constexpr newtype(const newtype&) = default;
	constexpr newtype(newtype&&) = default;
	constexpr newtype& operator=(const newtype&) = default;
	constexpr newtype& operator=(newtype&&) = default;
};

#define NEWTYPE_OP(newtype, ty, op)                           \
	constexpr inline ty operator op(const newtype& lhs,   \
					const newtype& rhs) { \
		return lhs.value op rhs.value;                \
	}

[[maybe_unused]] constexpr std::array<std::pair<i32, i32>, 4> around{
    std::pair{-1, 0}, std::pair{1, 0}, std::pair{0, -1}, std::pair{0, 1}};

}  // namespace util
using namespace ::util;

int solve(const int a, const int b, const int c, const int x) {
	int count{0};

	for (int a_num = 0; a_num <= a; ++a_num) {
		for (int b_num = 0; b_num <= b; ++b_num) {
			for (int c_num = 0; c_num <= c; ++c_num) {
				if (x ==
				    500 * a_num + 100 * b_num + 50 * c_num) {
					++count;
				}
			}
		}
	}
	return count;
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
	int a, b, c, x;
	cin >> a >> b >> c >> x;
	auto ret = solve(a, b, c, x);
	cout << ret << nl;
	std::cout << std::flush;
	return 0;
}
