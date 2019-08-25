//Copyright Alice Framework, All Rights Reserved
#pragma once

namespace Alice
{
    namespace Concepts
    {
        template<class T> class RemoveReferences
        {
        public:
            typedef T Type;
        };

        template<class T> class RemoveReferences<T&>
        {
        public:
            typedef T Type;
        };

        template<class T> class RemoveReferences<T&&>
        {
        public:
            typedef T Type;
        };
    }
}