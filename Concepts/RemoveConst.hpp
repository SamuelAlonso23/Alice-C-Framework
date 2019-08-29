//Copyright Alice Framework, All Rights Reserved
#pragma once

namespace Alice
{
    namespace Concepts
    {
        template<class T> class RemoveConstClass
        {
        public:
            typedef T Type;
        };

        template<class T> class RemoveConstClass<const T>
        {
        public:
            typedef T Type;
        };

        template<class T> using RemoveConst = typename RemoveConstClass<T>::Type;
    }
}