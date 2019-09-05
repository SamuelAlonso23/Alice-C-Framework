//Copyright Alice Framework, All Rights Reserved
#pragma once
#include <initializer_list>
#include <Core/Forward.hpp>
#include <Core/Exception.hpp>

namespace Alice
{
    namespace Collections
    {
        namespace Generic
        {
            template<class T> class List
            {
            private:
                T* Pointer = nullptr;

                u64 capacity = 0;

                u64 size = 0;

                bool readonly = false;
            public:
                AliceInline List() noexcept{}

                AliceInline List(const std::initializer_list<T>&& il) noexcept : List<T>(il.size())
                {
                    u64 i = 0;
                    for(auto& Element : il)
                    {
                        Pointer[i] = Element;
                        ++i;
                    }
                }

                AliceInline List(u64 Capacity) noexcept : Pointer(new T[Capacity]), capacity(Capacity), size(Capacity){}

                AliceInline List(List<T>& Other) noexcept : Pointer(new T[Other.capacity]), capacity(Other.capacity), size(Other.size)
                {
                    for(u64 i = 0; i < Other.capacity; ++i)
                        Pointer[i] = Other[i];
                }

                AliceInline List(const List<T>& Other) noexcept : Pointer(new T[Other.capacity]), capacity(Other.capacity), size(Other.size)
                {
                    for(u64 i = 0; i < Other.capacity; ++i)
                        Pointer[i] = Other[i];
                }

                AliceInline List(List<T>&& Other) noexcept : Pointer(Other.Pointer), capacity(Other.capacity), size(Other.size)
                {
                    Other.Pointer = nullptr;
                }

                AliceInline T operator[](u64 id) const noexcept
                {
                    if(id >= capacity)
                    {
                        Exception::Raise(ExceptionType::IndexOverflow);
                        return T();
                    }
                    return Pointer[id];
                }

                AliceInline T& operator[](u64 id) noexcept
                {
                    if(readonly)
                        Exception::Raise(ExceptionType::IsReadOnly);
                    else if(id >= capacity)
                        Exception::Raise(ExceptionType::IndexOverflow);
                    else
                        return Pointer[id];
                    return Pointer[0];
                }

                AliceInline void operator=(const std::initializer_list<T>&& il) noexcept
                {
                    if(il.size() > capacity)
                        Exception::Raise(ExceptionType::IndexOverflow);
                    else
                    {
                        u64 i = 0;
                        for(auto& Element : il)
                        {
                            Pointer[i] = Element;
                            ++i;
                        }
                    }
                }

                AliceInline void operator=(List<T>& Other) noexcept
                {
                    size = Other.size;
                    capacity = Other.capacity;
                    delete[] Pointer;
                    Pointer = new T[Other.capacity];
                    for(u64 i = 0; i < Other.size; ++i)
                        Pointer[i] = Other[i];
                }

                AliceInline void operator=(const List<T>& Other) noexcept
                {
                    size = Other.size;
                    capacity = Other.capacity;
                    delete[] Pointer;
                    Pointer = new T[Other.capacity];
                    for(u64 i = 0; i < Other.size; ++i)
                        Pointer[i] = Other[i];
                }

                AliceInline void operator=(List<T>&& Other) noexcept
                {
                    size = Other.size;
                    capacity = Other.capacity;
                    Pointer = Other.Pointer;
                    Other.Pointer = nullptr;
                }

                AliceInline T* operator->() const noexcept
                {
                    return Pointer;
                }

                AliceInline ~List() noexcept
                {
                    delete[] Pointer;
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

                AliceInline u64 Capacity() const noexcept
                {
                    return capacity;
                }

                AliceInline u64 Length() const noexcept
                {
                    return sizeof(T) * capacity;
                }

                AliceInline void Reserve(u64 NewReservation) noexcept
                {
                    if(NewReservation != capacity)
                    {
                        if(!readonly)
                        {
                            T* NewList = new T[NewReservation];
                            for(u64 i = 0; i < (size < NewReservation ? size : NewReservation); ++i)
                                NewList[i] = Alice::Forward<T>(Pointer[i]);
                            delete[] Pointer;
                            capacity = NewReservation;
                            Pointer = NewList;
                        }
                        else
                            Exception::Raise(ExceptionType::IsReadOnly);
                    }
                }

                AliceInline void Resize(u64 NewSize) noexcept
                {
                    if(NewSize != size)
                    {
                        if(!readonly)
                        {
                            size = NewSize;
                            if(NewSize > capacity)
                                Reserve(NewSize);
                        }
                        else
                            Exception::Raise(ExceptionType::IsReadOnly);
                    }
                }

                AliceInline void Clear(u64 From, u64 To) noexcept
                {
                    if(From > To)
                        Exception::Raise(ExceptionType::FromIsGreaterThanTo);
                    else if(readonly)
                        Exception::Raise(ExceptionType::IsReadOnly);
                    else
                        for(u64 i = From; !(i > To); ++i)
                            Pointer[i] = Forward<T>(T());
                }

                AliceInline void Destroy() noexcept
                {
                    readonly = false;
                    capacity = 0;
                    size = 0;
                    delete[] Pointer;
                }

                AliceInline void Add(T& Element) noexcept
                {
                    if(readonly)
                        Exception::Raise(ExceptionType::IsReadOnly);
                    else
                    {
                        const u64 tsize = size;
                        Resize(size + 1);
                        Pointer[tsize] = Element;
                    }
                }

                AliceInline void Add(T&& Element) noexcept
                {
                    if(readonly)
                        Exception::Raise(ExceptionType::IsReadOnly);
                    else
                    {
                        const u64 tsize = size;
                        Resize(size + 1);
                        Pointer[tsize] = Forward<T>(Element);
                    }
                }

                AliceInline void Remove() noexcept
                {
                    if(readonly)
                        Exception::Raise(ExceptionType::IsReadOnly);
                    else
                    {
                        --size;
                        (reinterpret_cast<T*>(Pointer)[size]).~T();
                    }
                }

                AliceInline void Add(T& Element, u64 ID) noexcept
                {
                    if(readonly)
                        Exception::Raise(ExceptionType::IsReadOnly);
                    else if(ID > size)
                        Exception::Raise(ExceptionType::IndexOverflow);
                    else
                    {
                        Resize(size + 1);
                        for(u64 i = ID; i < size; ++i)
                            Pointer[i + 1] = Forward<T>(Pointer[i]);
                        Pointer[ID] = Element;
                    }
                }

                AliceInline void Add(T&& Element, u64 ID) noexcept
                {
                    if(readonly)
                        Exception::Raise(ExceptionType::IsReadOnly);
                    else if(ID > size)
                        Exception::Raise(ExceptionType::IndexOverflow);
                    else
                    {
                        Resize(size + 1);
                        for(u64 i = ID; i < size; ++i)
                            Pointer[i + 1] = Forward<T>(Pointer[i]);
                        Pointer[ID] = Forward<T>(Element);
                    }
                }

                AliceInline void Swap(List<T>& Other) noexcept
                {
                    const u64&& tcap = Forward<u64>(Other.capacity), tsiz = Forward<u64>(Other.size);
                    T*&& tptr = Forward<T*>(Other.Pointer);
                    Other.capacity = Forward<u64>(capacity);
                    Other.size = Forward<u64>(size);
                    Other.Pointer = Forward<T*>(Pointer);
                    capacity = tcap;
                    size = tsiz;
                    Pointer = tptr;
                }

                AliceInline bool Exists(T value) const noexcept
                {
                    for(u64 i = 0; i < capacity; ++i)
                        if(Pointer[i] == value)
                            return true;
                    return false;
                }

                AliceInline u64 BinarySearch(T value) const noexcept
                {
                    for(u64 i = 0; i < capacity; ++i)
                        if(Pointer[i] == value)
                            return i;
                    Exception::Raise(ExceptionType::OperationWithoutSuccess);
                    return 0;
                }
            };
        }
    }
}