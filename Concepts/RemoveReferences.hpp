//Copyright Alice Framework, All Rights Reserved
#pragma once

namespace Alice
{
    namespace Concepts
    {
        template<class T> class RemoveReferencesClass
        {
        public:
            typedef T Type;
        };

        template<class T> class RemoveReferencesClass<T&>
        {
        public:
            typedef T Type;
        };

        template<class T> class RemoveReferencesClass<T&&>
        {
        public:
            typedef T Type;
        };

        template<class T> using RemoveReferences = typename RemoveReferencesClass<T>::Type;
    }
}