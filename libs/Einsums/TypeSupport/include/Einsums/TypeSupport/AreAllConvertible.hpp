//----------------------------------------------------------------------------------------------
// Copyright (c) The Einsums Developers. All rights reserved.
// Licensed under the MIT License. See LICENSE.txt in the project root for license information.
//----------------------------------------------------------------------------------------------

#pragma once

#include <type_traits>

namespace einsums {

// From: https://stackoverflow.com/questions/29671643/checking-type-of-parameter-pack-using-enable-if
namespace detail {
template <bool...>
struct bool_pack;
template <bool... bs>
using all_true = std::is_same<bool_pack<bs..., true>, bool_pack<true, bs...>>;
} // namespace detail

/**
 * @typedef are_all_convertible
 *
 * @brief Checks to see if all arguments can be converted to the first argument.
 *
 * @tparam R The target type. The rest of the parameters should be convertible to this.
 * @tparam Ts The types to test.
 */
template <class R, class... Ts>
using are_all_convertible = detail::all_true<std::is_convertible_v<Ts, R>...>;

/**
 * @property are_all_convertible_v
 *
 * @brief Checks to see if all arguments can be converted to the first argument.
 *
 * Equivalent to are_all_convertible::value.
 *
 * @tparam R The target type. The rest of the parameters should be convertible to this.
 * @tparam Ts The types to test.
 */
template <class R, class... Ts>
inline constexpr bool are_all_convertible_v = detail::all_true<std::is_convertible_v<Ts, R>...>::value;

} // namespace einsums