//Copyright Alice Framework, All Rights Reserved
#pragma once

namespace Alice
{
    namespace Concepts
    {
        template<class T> class AddPointerClass
        {
        public:
            typedef T* Type;
        };

        template<class T> using AddPointer = typename AddPointerClass<T>::Type;
    }
}