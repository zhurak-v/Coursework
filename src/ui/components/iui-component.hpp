#pragma once

class IUIComponent
{
public:
    virtual ~IUIComponent() = default;
public:
    virtual void render() = 0;
};
