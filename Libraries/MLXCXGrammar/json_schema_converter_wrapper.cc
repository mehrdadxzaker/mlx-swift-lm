#include "xgrammar/cpp/regex_converter.h"

namespace xgrammar {
namespace {
// xgrammar v0.1.30 joins regex fragments directly to JSON quotes.
// Group the fragment so the quotes enclose every alternative.
std::string GroupedRegexToEBNF(const std::string& regex, bool with_rule_name = true) {
  auto ebnf = RegexToEBNF(regex, with_rule_name);
  return with_rule_name ? ebnf : "(" + ebnf + ")";
}
}  // namespace
}  // namespace xgrammar

#define RegexToEBNF GroupedRegexToEBNF
#include "xgrammar/cpp/json_schema_converter.cc"  // NOLINT(build/include)
#undef RegexToEBNF
