//Copyright Alice Framework, All Rights Reserved
#pragma once
/**
namespace Alice
{
    namespace Concepts
    {
        template<class> class IsFunctionClass
        {
        public:
            constexpr static bool Value = false;
        };

        template<class T, class ...Args> class IsFunctionClass<T(Args...)>
        {
        public:
            constexpr static bool Value  = true;
        };

        template<class T, class ...Args> class IsFunctionClass<T(Args......)>
        {
        public:
            constexpr static bool Value  = true;
        };

        template<class T, class ...Args> class IsFunctionClass<T(Args...) const>
        {
        public:
            constexpr static bool Value  = true;
        };

        template<class T, class ...Args> class IsFunctionClass<T(Args...) volatile>
        {
        public:
            constexpr static bool Value  = true;
        };

        template<class T, class ...Args> class IsFunctionClass<T(Args...) const volatile>
        {
        public:
            constexpr static bool Value  = true;
        };

        template<class T, class ...Args> class IsFunctionClass<T(Args......) const>
        {
        public:
            constexpr static bool Value  = true;
        };

        template<class T, class ...Args> class IsFunctionClass<T(Args......) volatile>
        {
        public:
            constexpr static bool Value  = true;
        };

        template<class T, class ...Args> class IsFunctionClass<T(Args......) const volatile>
        {
        public:
            constexpr static bool Value  = true;
        };

        template<class T, class ...Args> class IsFunctionClass<T(Args...)&>
        {
        public:
            constexpr static bool Value  = true;
        };

        template<class T, class ...Args> class IsFunctionClass<T(Args...) const&>
        {
        public:
            constexpr static bool Value  = true;
        };

        template<class T, class ...Args> class IsFunctionClass<T(Args...) volatile&>
        {
        public:
            constexpr static bool Value  = true;
        };

        template<class T, class ...Args> class IsFunctionClass<T(Args...)const volatile&>
        {
        public:
            constexpr static bool Value  = true;
        };

        template<class T, class ...Args> class IsFunctionClass<T(Args......)&>
        {
        public:
            constexpr static bool Value  = true;
        };

        template<class T, class ...Args> class IsFunctionClass<T(Args......) const&>
        {
        public:
            constexpr static bool Value  = true;
        };

        template<class T, class ...Args> class IsFunctionClass<T(Args......) volatile&>
        {
        public:
            constexpr static bool Value  = true;
        };

        template<class T, class ...Args> class IsFunctionClass<T(Args......) const volatile&>
        {
        public:
            constexpr static bool Value  = true;
        };

        template<class T, class ...Args> class IsFunctionClass<T(Args...)&&>
        {
        public:
            constexpr static bool Value  = true;
        };

        template<class T, class ...Args> class IsFunctionClass<T(Args...) const&&>
        {
        public:
            constexpr static bool Value  = true;
        };

        template<class T, class ...Args> class IsFunctionClass<T(Args...) volatile&&>
        {
        public:
            constexpr static bool Value  = true;
        };

        template<class T, class ...Args> class IsFunctionClass<T(Args...) const volatile&&>
        {
        public:
            constexpr static bool Value  = true;
        };

        template<class T, class ...Args> class IsFunctionClass<T(Args......)&&>
        {
        public:
            constexpr static bool Value  = true;
        };

        template<class T, class ...Args> class IsFunctionClass<T(Args......) const&&>
        {
        public:
            constexpr static bool Value  = true;
        };

        template<class T, class ...Args> class IsFunctionClass<T(Args......) volatile&&>
        {
        public:
            constexpr static bool Value  = true;
        };

        template<class T, class ...Args> class IsFunctionClass<T(Args......) const volatile&&>
        {
        public:
            constexpr static bool Value  = true;
        };

        template<class T, class ...Args> class IsFunctionClass<T(Args...) noexcept>
        {
        public:
            constexpr static bool Value  = true;
        };

        template<class T, class ...Args> class IsFunctionClass<T(Args...) const noexcept>
        {
        public:
            constexpr static bool Value  = true;
        };

        template<class T, class ...Args> class IsFunctionClass<T(Args...) volatile noexcept>
        {
        public:
            constexpr static bool Value  = true;
        };

        template<class T, class ...Args> class IsFunctionClass<T(Args...) const volatile noexcept>
        {
        public:
            constexpr static bool Value  = true;
        };

        template<class T, class ...Args> class IsFunctionClass<T(Args......) noexcept>
        {
        public:
            constexpr static bool Value  = true;
        };

        template<class T, class ...Args> class IsFunctionClass<T(Args......) const noexcept>
        {
        public:
            constexpr static bool Value  = true;
        };

        template<class T, class ...Args> class IsFunctionClass<T(Args......) volatile noexcept>
        {
        public:
            constexpr static bool Value  = true;
        };

        template<class T, class ...Args> class IsFunctionClass<T(Args......) const volatile noexcept>
        {
        public:
            constexpr static bool Value  = true;
        };

        template<class T, class ...Args> class IsFunctionClass<T(Args...)& noexcept>
        {
        public:
            constexpr static bool Value  = true;
        };

        template<class T, class ...Args> class IsFunctionClass<T(Args...) const& noexcept>
        {
        public:
            constexpr static bool Value  = true;
        };

        template<class T, class ...Args> class IsFunctionClass<T(Args...) volatile& noexcept>
        {
        public:
            constexpr static bool Value  = true;
        };

        template<class T, class ...Args> class IsFunctionClass<T(Args...) const volatile& noexcept>
        {
        public:
            constexpr static bool Value  = true;
        };

        template<class T, class ...Args> class IsFunctionClass<T(Args......)& noexcept>
        {
        public:
            constexpr static bool Value  = true;
        };

        template<class T, class ...Args> class IsFunctionClass<T(Args......) const& noexcept>
        {
        public:
            constexpr static bool Value  = true;
        };

        template<class T, class ...Args> class IsFunctionClass<T(Args......) volatile& noexcept>
        {
        public:
            constexpr static bool Value  = true;
        };

        template<class T, class ...Args> class IsFunctionClass<T(Args......) const volatile& noexcept>
        {
        public:
            constexpr static bool Value  = true;
        };

        template<class T, class ...Args> class IsFunctionClass<T(Args...)&& noexcept>
        {
        public:
            constexpr static bool Value  = true;
        };

        template<class T, class ...Args> class IsFunctionClass<T(Args...) const&& noexcept>
        {
        public:
            constexpr static bool Value  = true;
        };

        template<class T, class ...Args> class IsFunctionClass<T(Args...) volatile&& noexcept>
        {
        public:
            constexpr static bool Value  = true;
        };

        template<class T, class ...Args> class IsFunctionClass<T(Args...) const volatile&& noexcept>
        {
        public:
            constexpr static bool Value  = true;
        };

        template<class T, class ...Args> class IsFunctionClass<T(Args......)&& noexcept>
        {
        public:
            constexpr static bool Value  = true;
        };

        template<class T, class ...Args> class IsFunctionClass<T(Args......) const&& noexcept>
        {
        public:
            constexpr static bool Value  = true;
        };

        template<class T, class ...Args> class IsFunctionClass<T(Args......) volatile&& noexcept>
        {
        public:
            constexpr static bool Value  = true;
        };

        template<class T, class ...Args> class IsFunctionClass<T(Args......) const volatile&& noexcept>
        {
        public:
            constexpr static bool Value  = true;
        };

        template<class T> constexpr bool IsFunction = IsFunctionClass<T>::Value;
    }
}
*/