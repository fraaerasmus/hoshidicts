#pragma once

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

struct TextVariant {
  std::string text;
  int steps;
  // Bounds on how many trailing characters a deinflection may rewrite; see Lookup::lookup.
  size_t min_rewrite = 0;
  size_t max_rewrite = SIZE_MAX;
};

namespace text_processor {
std::vector<TextVariant> process(const std::string& src);
// next_char is the character after src in the scanned text, or 0 at the end.
std::vector<TextVariant> process(const std::string& src, const std::string& language, char32_t next_char = 0);
std::vector<TextVariant> postprocess(const std::string& src, const std::string& language);
}
