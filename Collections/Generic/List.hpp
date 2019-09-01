//Copyright Alice Framework, All Rights Reserved
#pragma once
#include <Core\Exception.hpp>

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

                bool readonly = false;
            public:
                AliceInline List() noexcept{}

                AliceInline List(u64 Capacity) noexcept : Pointer(new T[Capacity]), capacity(Capacity){}
            
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

                AliceInline u64 Capacity() const noexcept
                {
                    return capacity;
                }

                AliceInline u64 Length() const noexcept
                {
                    return sizeof(T) * capacity;
                }

                AliceInline void Resize(u64 NewSize) noexcept
                {
                    if(!readonly)
                    {
                        T* NewList = new T[NewSize];
                        for(u64 i = 0; i < (capacity < NewSize ? capacity : NewSize); i++)
                            NewList[i] = Pointer[i];
                        delete[] Pointer;
                        Pointer = NewList;
                        capacity = NewSize;
                    }
                    else
                        Exception::Raise(ExceptionType::IsReadOnly);
                }
            };
        }
    }
}