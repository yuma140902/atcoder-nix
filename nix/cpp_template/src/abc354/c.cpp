#include <algorithm>
#include <climits>
#include <cmath>
#include <concepts>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <ranges>
#include <type_traits>
#include <unordered_set>
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
inline auto fequal(T f, S g) -> bool {
	return std::abs(f - g) < EPS;
}

template <class T>
inline auto assign_max(T& lhs, T rhs) -> bool {
	if (lhs < rhs) {
		lhs = rhs;
		return true;
	}
	return false;
}

template <class T>
inline auto assign_min(T& lhs, T rhs) -> bool {
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

#define NEWTYPE_OP(nt, ty, op)                                          \
	constexpr inline ty operator op(const nt& lhs, const nt& rhs) { \
		return lhs.value op rhs.value;                          \
	}

[[maybe_unused]] constexpr std::array<std::pair<i32, i32>, 4> around{
    std::pair{-1, 0}, std::pair{1, 0}, std::pair{0, -1}, std::pair{0, 1}};

}  // namespace util
using namespace ::util;

using A = newtype<i32, struct A_>;
using Cost = newtype<i32, struct Cost_>;
NEWTYPE_OP(A, bool, <)
NEWTYPE_OP(Cost, bool, <)

void solve(i32 n, const vector<A>& a, const vector<Cost>& c, vector<i32>& ret) {
	vector<tuple<A, Cost, i32>> cards(n);
	for (auto i : iota(0, n)) {
		cards[i] = tuple{a[i], c[i], i};
	}
	sort(begin(cards), end(cards),
	     [](const tuple<A, Cost, i32>& a, const tuple<A, Cost, i32>& b) {
		     return get<1>(a) < get<1>(b);
	     });

	unordered_set<i32> indices;
	A max_a{0};
	for (const auto& card : cards) {
		if (assign_max(max_a, get<0>(card))) {
			indices.insert(get<2>(card));
		}
	}
	for (auto i : indices) {
		ret.push_back(i + 1);
	}
	sort(begin(ret), end(ret));
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
	i32 n;
	cin >> n;
	vector<A> a(n);
	vector<Cost> c(n);
	for (auto i : iota(0, n)) {
		cin >> a[i].value >> c[i].value;
	}

	vector<i32> ret;
	solve(n, a, c, ret);

	cout << ret.size() << nl;
	if (!ret.empty())
		cout << ret[0];
	for (auto& item : ret | views::drop(1)) {
		cout << ' ' << item;
	}
	cout << nl;

	std::cout << std::flush;
	return 0;
}
