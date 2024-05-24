#pragma once

#include <string>
using String = std::string;

#include <print>
#include <optional>
#include <expected>
#include <ranges>
using std::views::iota;
#include <vector>

template<typename T>
using Vector = std::vector<T>;
#include <unordered_map>

template<typename K, typename V>
using Dictionary = std::unordered_map<K,V>;

#include <cstdint>
using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;

using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;

#include <functional>