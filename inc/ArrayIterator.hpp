#ifndef _OOG_CORE_ARRAYITERATOR_HPP_
#define _OOG_CORE_ARRAYITERATOR_HPP_
namespace ConwayGameOfLife {
    template<typename TElement, template<typename> class TArray>
	class ArrayIterator {
	public:
        ArrayIterator(TArray<TElement> array) : array(array) {}

        class const_iterator {
        public:
            const_iterator(const TArray<TElement>* arrayPtr, int index) :
                arrayPtr(arrayPtr),
                index(index)
            {}
            bool operator!=(const const_iterator& that) {
                return this->index != that.index;
            }
            const_iterator operator++() {
                auto i = *this;
                index++;
                return i;
            }
            TElement& operator*() {
                return (*arrayPtr)[index];
            }
        private:
            const TArray<TElement>* arrayPtr;
            int index;
        };

        const_iterator begin() const {
            return const_iterator(&array, 0);
        }
        const_iterator end() const {
            return const_iterator(nullptr, array.length());
        }
	private:
        TArray<TElement> array;
	};
}
#endif
