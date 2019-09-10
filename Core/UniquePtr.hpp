//Copyright Alice Framework, All Rights Reserved
#pragma once
#include <Core/Forward.hpp>
#include <Core/Exception.hpp>
#include <Core/DefaultDelete.hpp>

namespace Alice
{
    template<class T, class D = DefaultDelete<T>> class UniquePtr
    {
    private:
        T* ptr = nullptr;
    public:
        explicit AliceInline UniquePtr(T*&& Pointer) noexcept : ptr(Pointer)
        {
            Pointer = nullptr;
        }

        //Exceptions: MemoryAllocationFailed
        explicit AliceInline UniquePtr(T& Variable) noexcept : ptr(new T(Variable))
        {
            if (ptr == nullptr)
                Exception::Raise(ExceptionType::MemoryAllocationFailed);
        }

        //Exceptions: MemoryAllocationFailed
        explicit AliceInline UniquePtr(const T&& Value) noexcept : ptr(new T(Value))
        {
            if(ptr == nullptr)
                Exception::Raise(ExceptionType::MemoryAllocationFailed);
        }

        AliceInline UniquePtr(UniquePtr<T>&& Other) noexcept : ptr(Other.Release()){}

        AliceInline ~UniquePtr() noexcept
        {
            D();
        }

        AliceInline T& operator*() const noexcept
        {
            return *ptr;
        }

        AliceInline T* operator->() const noexcept
        {
            return ptr;
        }

        //Exceptions: MemoryAllocationFailed
        AliceInline void Reset(T&& Value) noexcept
        {
            D();
            ptr = new T(Value);
        }

        AliceInline void Reset(T& Variable) noexcept
        {
            D();
            ptr = new T(Variable);
        }

        AliceInline void Reset(const T& Variable) noexcept
        {
            D();
            ptr = new T(Variable);
        }

        AliceInline void Reset(T* Pointer) noexcept
        {
            D();
            ptr = Pointer;
        }

        AliceInline T*&& Release() noexcept
        {
            T*&& aux = Forward<T*>(ptr);
            ptr = nullptr;
            return aux;
        }

        AliceInline void Swap(UniquePtr<T>& Other) noexcept
        {
            T*&& aux = Forward<T*>(Other.ptr);
            Other.ptr = ptr;
            ptr = aux;
        }
    };

    template<class T, class D> class UniquePtr<T[], D>
    {
    private:
        T* ptr = nullptr;

        bool readonly = false;
    public:
        explicit AliceInline UniquePtr(T*&& Pointer) noexcept : ptr(Pointer)
        {
            Pointer = nullptr;
        }

        AliceInline T*& operator->() noexcept
        {
            return *ptr;
        }

        AliceInline T operator[](u64 id) const noexcept
        {
            return ptr[id];
        }

        AliceInline T& operator[](u64 id) noexcept
        {
            if(readonly)
            {
                Exception::Raise(ExceptionType::IsReadOnly);
                return ptr[0];
            }
            else
                return ptr[id];
        }

        AliceInline bool IsReadOnly() const noexcept
        {
            return readonly;
        }

        AliceInline void AsReadOnly() noexcept
        {
            readonly = true;
        }
    };
}