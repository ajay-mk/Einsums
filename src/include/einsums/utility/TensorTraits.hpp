#pragma once

#include <cstddef>
#include <type_traits>

namespace einsums {

template <typename T, size_t Rank>
struct Tensor;

template <typename T, size_t Rank>
struct TensorView;

template <typename T, size_t Rank>
struct DiskTensor;

template <typename T, size_t ViewRank, size_t Rank>
struct DiskView;

namespace detail {

template <typename D, size_t Rank, typename T>
struct IsIncoreRankTensor
    : public std::bool_constant<std::is_same_v<std::decay_t<D>, Tensor<T, Rank>> || std::is_same_v<std::decay_t<D>, TensorView<T, Rank>>> {
};
template <typename D, size_t Rank, typename T>
inline constexpr bool IsIncoreRankTensorV = IsIncoreRankTensor<D, Rank, T>::value;

template <typename D, size_t Rank, size_t ViewRank = Rank, typename T = double>
struct IsOndiskTensor
    : public std::bool_constant<std::is_same_v<D, DiskTensor<T, Rank>> || std::is_same_v<D, DiskView<T, ViewRank, Rank>>> {};
template <typename D, size_t Rank, size_t ViewRank = Rank, typename T = double>
inline constexpr bool IsOndiskTensorV = IsOndiskTensor<D, Rank, ViewRank, T>::value;

} // namespace detail

/**
 * @brief Concept that requires a tensor to be in core.
 *
 * Example usage:
 *
 * @code
 * template <template <typename, size_t> typename AType, typename ADataType, size_t ARank>
 *    requires CoreRankTensor<AType<ADataType, ARank>, 1, ADataType>
 * void sum_square(const AType<ADataType, ARank> &a, RemoveComplexT<ADataType> *scale, RemoveComplexT<ADataType> *sumsq) {}
 * @endcode
 *
 * @tparam Input
 * @tparam Rank
 * @tparam DataType
 */
template <typename Input, size_t Rank, typename DataType = double>
concept CoreRankTensor = detail::IsIncoreRankTensorV<Input, Rank, DataType>;

template <typename Input, size_t Rank, size_t ViewRank = Rank, typename DataType = double>
concept DiskRankTensor = detail::IsOndiskTensorV<Input, Rank, ViewRank, DataType>;

} // namespace einsums