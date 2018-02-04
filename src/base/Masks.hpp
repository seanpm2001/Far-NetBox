#pragma once

#include <Classes.hpp>

namespace Masks {

class NB_CORE_EXPORT TMask : public TObject
{
public:
  explicit TMask(const UnicodeString Mask);
  bool Matches(const UnicodeString Str) const;

private:
  UnicodeString FMask;
};

int CmpName(const wchar_t *pattern, const wchar_t *str, bool CmpNameSearchMode = false);

} // namespace Masks

