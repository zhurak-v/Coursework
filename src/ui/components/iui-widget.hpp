#pragma once

class IUIWidget
{
public:
    ~IUIWidget() = default;
public:
    virtual void render() = 0;
};
