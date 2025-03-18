#pragma once

class StateListener
{
public:
    ~StateListener() = default;
public:
    virtual void update(const Props& properties) = 0;
};
