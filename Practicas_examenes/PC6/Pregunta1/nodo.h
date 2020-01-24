#pragma once

template <typename T>
struct nodoBin{
    T dato;
    nodoBin<T>* hd;
    nodoBin<T>* hi;
};