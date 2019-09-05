//Copyright Alice Framework, All Rights Reserved
#pragma once
#include <Basic/Likely.hpp>
#include <Basic/Inline.hpp>

namespace Alice
{
    template<class T> class Lazy
    {
    private:
        T value;

        bool valuecreated = false;
    public:
        AliceInline Lazy() noexcept{}

        AliceInline Lazy(T& object) noexcept : value(object), valuecreated(true){}

        AliceInline Lazy(const T& object) noexcept : value(object), valuecreated(true){}

        AliceInline Lazy(T&& object) noexcept : value(object), valuecreated(true){}

        AliceInline Lazy(Lazy<T>& object) noexcept : value(object.value), valuecreated(true){}

        AliceInline Lazy(const Lazy<T>& object) noexcept : value(object.value), valuecreated(true){}

        AliceInline Lazy(Lazy<T>&& object) noexcept : value(object.value), valuecreated(true)
        {
            object.value = 0;
            object.valuecreated = false;
        }

        AliceInline void operator=(T& object) noexcept
        {
            value = object;
            if(AliceUnlikely(!valuecreated))
                valuecreated = true;
        }

        AliceInline void operator=(const T& object) noexcept
        {
            value = object;
            if(AliceUnlikely(!valuecreated))
                valuecreated = true;
        }

        AliceInline void operator=(T&& object) noexcept
        {
            value = object;
            if(AliceUnlikely(!valuecreated))
                valuecreated = true;
        }

        AliceInline T& Object() const noexcept
        {
            return value;
        }

        AliceInline T Object() noexcept
        {
            return value;
        }

        AliceInline bool IsObjectCreated() const noexcept
        {
            return valuecreated;
        }
    };
}