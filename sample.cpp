#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <ranges>
#include <utility>
#include <vector>

// NOLINTBEGIN(misc-unused-using-decls)
using std::cerr;
using std::cout;
using std::pair;
using std::tuple;
using std::vector;
using std::ranges::views::iota;
// NOLINTEND(misc-unused-using-decls)
namespace ranges = ::std::ranges;	 // NOLINT(misc-unused-alias-decls)
namespace views = ::std::ranges::views;	 // NOLINT(misc-unused-alias-decls)

#define debug(x)                                              \
	do {                                                  \
		std::cerr << #x << " = " << (x) << std::endl; \
	} while (0)

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

constexpr char endl = '\n';
constexpr i32 INF = INT_MAX / 2;
constexpr i64 INFL = LONG_MAX / 2;
constexpr f64 EPS = 1e-10;

template <class T, class S>
inline auto fequal(T f, S g) -> bool {
	return std::abs(f - g) < EPS;
}

template <class T, class S>
inline auto assign_max(T& lhs, S&& rhs) -> bool {
	bool compare = lhs < rhs;
	if (compare) {
		lhs = rhs;
	}
	return compare;
}

template <class T, class S>
inline auto assign_min(T& lhs, S&& rhs) -> bool {
	bool compare = lhs > rhs;
	if (compare) {
		lhs = rhs;
	}
	return compare;
}

constexpr std::array<std::pair<i32, i32>, 4> around{
    std::pair{-1, 0}, std::pair{1, 0}, std::pair{0, -1}, std::pair{0, 1}};

}  // namespace util
using namespace ::util;

int main(int argc, char* argv[]) {
	for (auto i : iota(0, 10)) {
		debug(i);
	}

	f32 a{1.0};
	f32 b{10001.0};
	for (auto i : iota(0, 10000)) {
		b -= 1.0;
	}
	if (fequal(b, a)) {
		cout << "yes\n";
	} else {
		cout << "no\n";
	}

	i32 max{0};
	for (auto i : iota(0, 100)) {
		assign_max(max, i % 4);
	}
	debug(max);

	i32 ar[]{4, 5, 6};
	i32* first = ranges::begin(ar);
	i32* end = ranges::end(ar);
	for (auto i : ar) {
		debug(i);
	}

	cout << endl;
	for (auto& [dx, dy] : around) {
		debug(dx);
		debug(dy);
		cout << endl;
	}

	// TODO
	std::cout << std::flush;
	return 0;

	(void)INF;
	(void)INFL;
	(void)EPS;
	(void)argc;
	(void)argv;
}
