#include <iostream>

#ifdef __GLIBC__
#include <gnu/libc-version.h>
#endif

int main() {
#ifdef _LIBCPP_VERSION
	std::cout << "libc++: " << _LIBCPP_VERSION << std::endl;
#endif

#ifdef __GLIBCXX__
	std::cout << "GLIBCXX: " << __GLIBCXX__ << std::endl;
#endif

#ifdef __GLIBC__
	std::cout << "glibc runtime version: " << gnu_get_libc_version()
		  << std::endl;
	std::cout << "glibc headers version: " << __GLIBC__ << "."
		  << __GLIBC_MINOR__ << std::endl;
#else
	std::cout << "not using glibc" << std::endl;
#endif
	return 0;
}
