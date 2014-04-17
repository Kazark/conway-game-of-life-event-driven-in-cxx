#ifndef _CONWAYGAMEOFLIFE_VECTOR_HPP_
#define _CONWAYGAMEOFLIFE_VECTOR_HPP_

#include "ArrayIterator.hpp"

#include <initializer_list>
#include <algorithm>

namespace ConwayGameOfLife {
    template<typename T>
	class FixedLengthArray {
	public:
        FixedLengthArray() :
            _length(0),
            _storage(nullptr)
        {}

        FixedLengthArray(int length) :
            _length(length),
            _storage(new T[length])
        {
            std::fill_n(_storage, _length, T());
        }

        FixedLengthArray(const FixedLengthArray& that) :
            _length(that._length),
            _storage(nullptr)
        {
            if (that._storage != nullptr) {
                _storage = new T[that._length];
                std::copy_n(that._storage, _length, _storage);
            }
        }

        FixedLengthArray(FixedLengthArray&& that) :
            _length(that._length),
            _storage(that._storage)
        {
            that._storage = nullptr;
        }

        FixedLengthArray& operator=(const FixedLengthArray& that)
        {
            length = that._length;
            if (_storage == nullptr)
            {
                _storage = new T[_length];
            }
            else if (length() != that.length()) {
                deleteStorage();
                _storage = new T[_length];
            }
            std::copy_n(that._storage, _length, _storage);
            return *this;
        }

        FixedLengthArray& operator=(FixedLengthArray&& that)
        {
            _length = that._length;
            if (_storage != nullptr) {
                deleteStorage();
            }
            _storage = that._storage;
            that._storage = nullptr;
            return *this;
        }

        FixedLengthArray(std::initializer_list<T> initlist)
        {
            _length = initlist.size();
            _storage = new T[_length];
            int i = 0;
            for (auto item : initlist) {
                _storage[i] = item;
                i++;
            }
        }

        ~FixedLengthArray()
        {
            deleteStorage();
        }

        bool operator==(const FixedLengthArray& that) const
        {
            if (length() != that.length()) {
                return false;
            }
            for (int i = 0; i < _length; ++i) {
                if (this[i] != that[i]) {
                    return false;
                }
            }
            return true;
        }

        bool operator!=(const FixedLengthArray& that) const
        {
            return !(*this == that);
        }

        ArrayIterator<const T&, FixedLengthArray> iterator() const {
            return *this;
        }

        T& operator[](int i) {
            return _storage[i];
        }

        const T& operator[](int i) const {
            return _storage[i];
        }

        int length() const {
            return _length;
        }

	private:
        void deleteStorage() {
            delete[] _storage;
        }

        int _length;
        T* _storage;
	};
}
#endif
