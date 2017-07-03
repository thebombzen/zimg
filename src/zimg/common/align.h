#pragma once

#ifndef ZIMG_ALIGN_H_
#define ZIMG_ALIGN_H_

namespace zimg {

/**
 * 64-byte alignment allows the use of instructions up to AVX-512.
 */
constexpr int ALIGNMENT = 64;

/**
 * Round up the argument x to the nearest multiple of n.
 * x must be non-negative and n must be positive.
 */
template <class T, class U>
constexpr T ceil_n(T x, U n) { return x % n ? x + n - (x % n) : x; }

/**
 * Round down the argument x to the nearest multiple of n.
 * x must be non-negative and n must be positive.
 */
template <class T, class U>
constexpr T floor_n(T x, U n) { return x - (x % n); }

/**
 * Helper struct that computes alignment in units of object count.
 *
 * @tparam T type of object
 */
template <class T>
struct AlignmentOf {
	static constexpr unsigned value = ALIGNMENT / sizeof(T);
};

} // namespace zimg

#endif // ZIMG_ALIGN_H_
