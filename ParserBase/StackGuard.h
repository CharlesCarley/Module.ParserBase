/*
-------------------------------------------------------------------------------
    Copyright (c) Charles Carley.

  This software is provided 'as-is', without any express or implied
  warranty. In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
-------------------------------------------------------------------------------
*/
#pragma once

#include "Utils/Definitions.h"
#include "Utils/Exception.h"

namespace Rt2
{
    class StackGuard
    {
    private:
        const U16 _max;
        U16       _depth{0};

        StackGuard(const StackGuard&) = default;

    public:
        explicit StackGuard(const U16& max) :
            _max(max)
        {
        }

        void depthGuard();

        void resetGuard();

        U16 depth() const;
    };

    inline void StackGuard::depthGuard()
    {
        if (++_depth > _max)
        {
            throw Exception(
                "maximum recursion depth exceeded");
        }
    }

    inline void StackGuard::resetGuard()
    {
        _depth = 0;
    }

    inline U16 StackGuard::depth() const
    {
        return _depth;
    }

}  // namespace Rt2
