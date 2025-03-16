#include <imgui.h>
#include <string>

ImVec4 HexToImVec4(const std::string& hex)
{
    int r, g, b;

    if (hex.length() == 4)
    {
        r = std::stoi(hex.substr(1, 1), nullptr, 16) * 17;
        g = std::stoi(hex.substr(2, 1), nullptr, 16) * 17;
        b = std::stoi(hex.substr(3, 1), nullptr, 16) * 17;
    }
    else if (hex.length() == 7)
    {
        r = std::stoi(hex.substr(1, 2), nullptr, 16);
        g = std::stoi(hex.substr(3, 2), nullptr, 16);
        b = std::stoi(hex.substr(5, 2), nullptr, 16);
    }
    else
    {
        return ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
    }

    return ImVec4(r / 255.0f, g / 255.0f, b / 255.0f, 1.0f);
}