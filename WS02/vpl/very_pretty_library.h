#pragma once

#include <memory>
// this is a very pretty library!

namespace vpl
{
    class object
    {
    public:
        object(int value)
        {
            m_pSharedValue = std::make_shared<int>(++value);
        };
        ~object()
        {
        }
        auto getSharedValue()
        {
            return m_pSharedValue;
        };
    private:
        std::shared_ptr<int> m_pSharedValue;
    };
}
