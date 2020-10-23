/*
 * Copyright (c) 2020 Gustavo Valiente gustavo.valiente@protonmail.com
 * zlib License, see LICENSE file.
 */

#ifndef BTN_VECTOR_FWD_H
#define BTN_VECTOR_FWD_H

#include "btn_common.h"

namespace btn
{
    /**
     * @brief Base class of vector.
     *
     * Can be used as a reference type for all vector containers containing a specific type.
     *
     * @tparam Type Element type.
     *
     * @ingroup vector
     */
    template<typename Type>
    class ivector;

    /**
     * @brief Implementation that uses a fixed size buffer.
     *
     * @tparam Type Element type.
     * @tparam MaxSize Maximum number of elements that can be stored.
     *
     * @ingroup vector
     */
    template<typename Type, int MaxSize>
    class vector;
}

#endif
