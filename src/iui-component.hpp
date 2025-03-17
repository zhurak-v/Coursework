#pragma once

template <typename Derived>
class IUIComponent
{
private:
    friend Derived;
    IUIComponent() = default;

public:
    void render()
    {
        static_cast<Derived*>(this)->renderImpl();
    }

};
