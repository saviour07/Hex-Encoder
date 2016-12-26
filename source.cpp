#include <string>

const std::wstring hex = L"0123456789abcdef";
std::wstring encode(std::wstring toEncode)
{
    std::wstring encode;
    for (const auto& c : toEncode)
    {
        if (('a' <= c && c <= 'z') ||
            ('A' <= c && c <= 'Z') ||
            ('0' <= c && c <= '9'))
        {
            encode.append(std::wstring(1, c));
        }
        else if (c == ' ')
        {
            encode.append(L"%20");
        }
        else
        {
            encode.append(L"%");
            encode.append(std::wstring(1, hex[c >> 4]));
            encode.append(std::wstring(1, [c & 15]));
        }
    }

    return encode;
}