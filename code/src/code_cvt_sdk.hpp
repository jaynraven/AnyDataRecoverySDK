#ifndef __CODESVTSDK_HPP__
#define __CODESVTSDK_HPP__

#include <string>
#include <codecvt>
#include <windows.h>

std::wstring StrToUtf16(const std::string& str)
{
	if (str.empty())
	{
		return std::wstring();
	}
    try
	{
		std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>, wchar_t> conv;
		return conv.from_bytes(str);
    }
    catch (const std::exception&)
	{
		std::wstring_convert<std::codecvt_utf16<wchar_t>, wchar_t> conv;
		return conv.from_bytes(str);
    }
}

std::string WstrToUtf8(const std::wstring& wstr)
{
	if (wstr.empty())
	{
		return std::string();
	}
    try
	{
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> conv;
        return conv.to_bytes(wstr);
    }
    catch (const std::exception&)
	{
        std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
		return conv.to_bytes(wstr);
    }
}

std::string Utf8ToGBK(const std::string& utf8String)
{
    int gbkLength = MultiByteToWideChar(CP_UTF8, 0, utf8String.c_str(), -1, nullptr, 0);
    if (gbkLength == 0)
    {
        return std::string(); // 转换失败
    }

    wchar_t* wideStr = new wchar_t[gbkLength];
    MultiByteToWideChar(CP_UTF8, 0, utf8String.c_str(), -1, wideStr, gbkLength);

    int gbkSize = WideCharToMultiByte(CP_ACP, 0, wideStr, -1, nullptr, 0, nullptr, nullptr);
    if (gbkSize == 0)
    {
        delete[] wideStr;
        return std::string(); // 转换失败
    }

    char* gbkStr = new char[gbkSize];
    WideCharToMultiByte(CP_ACP, 0, wideStr, -1, gbkStr, gbkSize, nullptr, nullptr);

    std::string gbkString(gbkStr);

    delete[] wideStr;
    delete[] gbkStr;

    return gbkString;
}

std::string ToLowerCase(const std::string& str) {
    std::string result = str;
    for (char& c : result) {
        if (c >= 'A' && c <= 'Z') {
            c = c - 'A' + 'a'; // 转换为小写字母
        }
    }
    return result;
}

std::string ToUpperCase(const std::string& str) {
    std::string result = str;
    for (char& c : result) {
        if (c >= 'a' && c <= 'z') {
            c = c - 'a' + 'A'; // 转换为大写字母
        }
    }
    return result;
}

std::string Trim(const std::string& str) {
    std::string result = str;
    size_t start = 0;
    size_t end = result.length();

    // 去除开头的空格
    while (start < end && result[start] == ' ') {
        ++start;
    }

    // 去除末尾的空格
    while (end > start && result[end - 1] == ' ') {
        --end;
    }

    // 返回去除空格后的子串
    return result.substr(start, end - start);
}

#endif // __CODESVTSDK_HPP__