#pragma once

// інтерфейс для постачальників вікна
class IWindowProvider
{
public:
    virtual void createWindow();
};
