#pragma once

#include <string>
#include <memory>

// властивості
class Properties
{
private:
    std::unordered_map<std::string, std::shared_ptr<std::any>> m_props;
public:
    Properties(std::unordered_map<std::string, std::any> props);
public:

};
