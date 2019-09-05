//Copyright Alice Framework, All Rights Reserved
#pragma once
#include <Core/Forward.hpp>
#include <Core/Exception.hpp>
#include <Concepts/IsSame.hpp>
#include <Concepts/EnableIf.hpp>

namespace Alice
{
    template<class T, u64 size = 1> class Array
    {
    private:
        T arr[size];

        bool readonly = false;

        template<class From, class To> AliceInline To UglyButNecessaryCast(From& f) noexcept
        {
            return static_cast<To>(f);
        }
    public:
        template<typename ...U> AliceInline Array(U&&... initial) noexcept : arr{Forward<T>(UglyButNecessaryCast<typename Concepts::EnableIf<Concepts::IsSame<U, T>, U>, T>(initial))...}{}

        AliceInline T operator[](u64 id) const noexcept
        {
            if(id >= size)
            {
                Exception::Raise(ExceptionType::IndexOverflow);
                return arr[0];
            }
            else
                return arr[id];
        }

        AliceInline T& operator[](u64 id) noexcept
        {
            if(readonly)
                Exception::Raise(ExceptionType::IsReadOnly);
            else if(id >= size)
                Exception::Raise(ExceptionType::IndexOverflow);
            else
                return arr[id];
            return arr[0];
        }

        template<u64 OtherSize> AliceInline void Copy(Array<T, OtherSize>& Other) noexcept
        {
            for(u64 i = 0; i < (Other.Size() < size ? Other.Size() : size); i++)
                arr[i] = Alice::Forward<T>(Other[i]);
        }

        template<u64 OtherSize> AliceInline void Copy(const Array<T, OtherSize>& Other) noexcept
        {
            for(u64 i = 0; i < (Other.Size() < size ? Other.Size() : size); i++)
                arr[i] = Alice::Forward<T>(Other[i]);
        }
        
        AliceInline void AsReadOnly() noexcept
        {
            readonly = true;
        }

        AliceInline bool IsReadOnly() const noexcept
        {
            return readonly;
        }

        AliceInline u64 Size() const noexcept
        {
            return size;
        }

        AliceInline u64 Length() const noexcept
        {
            return size * sizeof(T);
        }

        template<u64 CopyArraySize> AliceInline void Copy(Array<T, CopyArraySize>& copy) const noexcept
        {
            for(u64 i = 0; i < (CopyArraySize < size ? CopyArraySize : size); i++)
                copy[i] = arr[i];
        }

        AliceInline u64 BinarySearch(const T& Element) const noexcept
        {
            for(u64 i = 0; i < size; i++)
                if(arr[i] == Element)
                    return i;
            Exception::Raise(ExceptionType::OperationWithoutSuccess);
            return 0;
        }

        AliceInline void Clear(const u64 From = 0, const u64 To = size - 1) noexcept
        {
            if(readonly)
                Exception::Raise(ExceptionType::IsReadOnly);
            else if(From > To)
                Exception::Raise(ExceptionType::FromIsGreaterThanTo);
            else if(size < To)
                Exception::Raise(ExceptionType::IndexOverflow);
            else
                for(u64 i = From; i <= To; i++)
                    arr[i] = T();
        }

        AliceInline bool Exists(const T& Element) const noexcept
        {
            for(u64 i = 0; i < size; i++)
                if(arr[i] == Element)
                    return true;
            return false;
        }
    };
}