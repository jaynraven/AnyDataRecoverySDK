#include <iostream>
#include <string>
#include "version/version.h"
#include "code_cvt_sdk.hpp"

std::string GetLine() 
{
    printf("DISKPARTPRO> ");
    std::string str;
    std::getline(std::cin, str);
    return str;
}

void PrintfGBK(const char* format, ...)
{
    std::string prefix = "[Prefix] ";

    // 创建可变参数列表
    va_list args;
    va_start(args, format);

    // 添加前缀并输出
    std::vprintf(Utf8ToGBK(format).c_str(), args);

    // 清理可变参数列表
    va_end(args);
}

void PrintVersion()
{
    PrintfGBK("\nDiskPart Pro 版本 %s\n\n", SDK_VERSION);
}

void PrintHelp() 
{
    PrintVersion();
    PrintfGBK("ENUM     - 枚举所有磁盘和分区信息\n");    
    PrintfGBK("\n");    
}

int main()
{
    PrintVersion();

    while (true) {
        std::string str = GetLine();
        str = ToUpperCase(Trim(str));

        if (strcmp(str.c_str(), "ENUM") == 0) {
            printf("\ntodo...\n\n");
        } 
        else if (strcmp(str.c_str(), "EXIT") == 0)  {
            break;
        }
        else {
            PrintHelp();
        }
    }

    return 0;
}