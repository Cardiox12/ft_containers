#ifndef VECTOR_HPP
#define VECTOR_HPP

# include <memory>
# include <limits>

namespace ft {
	/**
	 * The documentation of this vector implementation comes from
	 * https://www.cplusplus.com/reference/vector/vector/?kw=vector
	 * 
	 */
	template<class T, class Allocator = std::allocator<T>>
	class vector {
		public:
			using size_type = size_t;
		private:

			size_type	m_capacity;
			size_type	m_size;
			T			*items;
		public:
			vector();

			/**
			 * Return size
			 * 
			 * Returns the number of elements in the vector.
			 * This is the number of actual objects held in the vector,
			 * which is not necessarily equal to its storage capacity.
			 * 
			 */
			size_type size() const {
				return m_size;
			}

			/**
			 * Return capacity
			 * 
			 * Returns the size of the storage space currently allocated
			 * for the vector, expressed in terms of elements.
			 * 
			 * This capacity is not necessarily equal to the vector size.
			 * It can be equal or greater, with the extra space allowing
			 * to accommodate for growth without the need to reallocate on each insertion.
			 * 
			 * Notice that this capacity does not suppose a limit on the size of the vector.
			 * When this capacity is exhausted and more is needed,
			 * it is automatically expanded by the container (reallocating it storage space). 
			 * The theoretical limit on the size of a vector is given by member max_size.
			 * 
			 * The capacity of a vector can be explicitly altered by calling member vector::reserve.
			 */
			size_type capacity() const {
				return m_capacity;
			}

			/**
			 * Return maximum size
			 * 
			 * Returns the maximum number of elements that the vector can hold.
			 * 
			 * This is the maximum potential size the container can reach 
			 * due to known system or library implementation limitations, 
			 * but the container is by no means guaranteed to be able to reach 
			 * that size: it can still fail to allocate storage at any point before that size is reached.
			 * 
			 */
			size_type max_size() const {
				return ( std::numeric_limits<size_type>::max() );
			}

			/**
			 * Test whether vector is empty
			 * 
			 * Returns whether the vector is empty (i.e. whether its size is 0).
			 * This function does not modify the container in any way.
			 * To clear the content of a vector, see vector::clear.
			 * 
			 */
			bool empty() const {
				return m_size == 0;
			}
	};
}


#endif
