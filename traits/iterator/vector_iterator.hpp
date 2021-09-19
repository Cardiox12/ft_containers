#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

namespace ft {
	template<class T>
	class random_access_iterator;

	template<class T>
	class const_random_access_iterator {
		public:
			typedef std::random_access_iterator_tag iterator_category;
			typedef std::size_t						size_type;
			typedef std::ptrdiff_t					difference_type;
			typedef T								value_type;
			typedef T*								pointer;
			typedef T&								reference;
			typedef const T&						const_reference;

			/* Constructors */
			const_random_access_iterator() : m_ptr( NULL ) { }
			const_random_access_iterator(pointer p) : m_ptr( p ) { }
			const_random_access_iterator(const_random_access_iterator const &it) : m_ptr( it.m_ptr ) { }
			const_random_access_iterator(random_access_iterator<T> const &it) : m_ptr( it.operator->() ) { }
			const_random_access_iterator &operator=(const_random_access_iterator const &it) {
				if ( &it == this )
					return *this;
				m_ptr = it.m_ptr;
				return *this;
			}
			~const_random_access_iterator() {}

			/* Accesses operators */
			const_reference operator*() const { return *m_ptr; }
			pointer operator->() { return m_ptr; }
			pointer operator->() const { return m_ptr; }
			const_reference operator[](difference_type offset) const { return m_ptr[offset]; }

			/* Increment / Decrement */
			const_random_access_iterator &operator++() { m_ptr++; return *this; };
			const_random_access_iterator operator++(int) { const_random_access_iterator tmp = *this; ++(*this); return tmp; }
			const_random_access_iterator &operator--() { m_ptr--; return *this; }
			const_random_access_iterator operator--(int) { const_random_access_iterator tmp = *this; --(*this); return tmp; }

			/* Arithmetic */
			const_random_access_iterator &operator+=(difference_type offset) { m_ptr += offset; return *this; }
			const_random_access_iterator &operator-=(difference_type offset) { m_ptr -= offset; return *this; }
			
			const_random_access_iterator operator+(difference_type offset) { return const_random_access_iterator( m_ptr + offset ); }
			friend const_random_access_iterator operator+(difference_type offset, const const_random_access_iterator &it) { return const_random_access_iterator( it.m_ptr + offset ); }

			const_random_access_iterator operator-(difference_type offset) { return const_random_access_iterator( m_ptr - offset ); }
			friend const_random_access_iterator operator-(difference_type offset, const const_random_access_iterator &it) { return const_random_access_iterator( it.m_ptr - offset ); }
			difference_type operator-(const_random_access_iterator other) { return m_ptr - other.m_ptr; }


			/* Comparison operators */
			bool operator<(const_random_access_iterator const &it) const { return m_ptr < it.m_ptr; }
			bool operator>(const_random_access_iterator const &it) const { return m_ptr > it.m_ptr; }
			bool operator>=(const_random_access_iterator const &it) const { return m_ptr >= it.m_ptr; }
			bool operator<=(const_random_access_iterator const &it) const { return m_ptr <= it.m_ptr; }
			bool operator!=(const_random_access_iterator const &it) const { return m_ptr != it.m_ptr; }
			bool operator==(const_random_access_iterator const &it) const { return m_ptr == it.m_ptr; }
		private:
			pointer m_ptr;
	};

	template<class T>
	class random_access_iterator {
		public:
			typedef std::random_access_iterator_tag iterator_category;
			typedef std::size_t						size_type;
			typedef std::ptrdiff_t					difference_type;
			typedef T								value_type;
			typedef T*								pointer;
			typedef T&								reference;

			/* Constructors */
			random_access_iterator() : m_ptr( NULL ) { }
			random_access_iterator(pointer p) : m_ptr( p ) { }
			random_access_iterator(random_access_iterator const &it) : m_ptr( it.m_ptr ) { }
			random_access_iterator &operator=(random_access_iterator const &it) {
				if ( &it == this )
					return *this;
				m_ptr = it.m_ptr;
				return *this;
			}
			~random_access_iterator() {}

			/* Accesses operators */
			reference operator*() const { return *m_ptr; }
			pointer operator->() { return m_ptr; }
			pointer operator->() const { return m_ptr; }
			reference operator[](difference_type offset) const { return m_ptr[offset]; }

			/* Increment / Decrement */
			random_access_iterator &operator++() { m_ptr++; return *this; };
			random_access_iterator operator++(int) { random_access_iterator tmp = *this; ++(*this); return tmp; }
			random_access_iterator &operator--() { m_ptr--; return *this; }
			random_access_iterator operator--(int) { random_access_iterator tmp = *this; --(*this); return tmp; }

			/* Arithmetic */
			random_access_iterator &operator+=(difference_type offset) { m_ptr += offset; return *this; }
			random_access_iterator &operator-=(difference_type offset) { m_ptr -= offset; return *this; }
			
			random_access_iterator operator+(difference_type offset) { return random_access_iterator( m_ptr + offset ); }
			friend random_access_iterator operator+(difference_type offset, const random_access_iterator &it) { return random_access_iterator( it.m_ptr + offset ); }

			random_access_iterator operator-(difference_type offset) { return random_access_iterator( m_ptr - offset ); }
			friend random_access_iterator operator-(difference_type offset, const random_access_iterator &it) { return random_access_iterator( it.m_ptr - offset ); }
			difference_type operator-(random_access_iterator other) { return m_ptr - other.m_ptr; }


			/* Comparison operators */
			bool operator<(random_access_iterator const &it) const { return m_ptr < it.m_ptr; }
			bool operator>(random_access_iterator const &it) const { return m_ptr > it.m_ptr; }
			bool operator>=(random_access_iterator const &it) const { return m_ptr >= it.m_ptr; }
			bool operator<=(random_access_iterator const &it) const { return m_ptr <= it.m_ptr; }
			bool operator!=(random_access_iterator const &it) const { return m_ptr != it.m_ptr; }
			bool operator==(random_access_iterator const &it) const { return m_ptr == it.m_ptr; }
		private:
			pointer m_ptr;
	};

	template<typename T>
	class reverse_iterator {
		public:
			typedef T								iterator_type;
			typedef std::bidirectional_iterator_tag iterator_category;
			typedef std::size_t						size_type;
			typedef std::ptrdiff_t					difference_type;
			typedef T								value_type;
			typedef T*								pointer;
			typedef T&								reference;

			/* Constructors */
			reverse_iterator() : m_ptr( NULL ) { }
			reverse_iterator(pointer p) : m_ptr( p ) { }
			reverse_iterator(reverse_iterator const &it) : m_ptr( it.m_ptr ) { }
			reverse_iterator(random_access_iterator<T> const &it) : m_ptr( it.operator->() ) {}
			reverse_iterator(const_random_access_iterator<T> const &it) : m_ptr( it.operator->() ) {}
			reverse_iterator &operator=(reverse_iterator const &it) {
				if ( &it == this )
					return *this;
				m_ptr = it.m_ptr;
				return *this;
			}
			~reverse_iterator() {}

			/* Accesses operators */
			iterator_type base() const { return m_ptr; }
			reference operator*() const { return *m_ptr; }
			pointer operator->() const { return m_ptr; }
			reference operator[](difference_type offset) const { return m_ptr[offset]; }

			/* Increment / Decrement (which is inverted with reverse iterator) */
			reverse_iterator &operator++() { m_ptr--; return *this; };
			reverse_iterator operator++(int) { reverse_iterator tmp = *this; ++(*this); return tmp; }
			reverse_iterator &operator--() { m_ptr++; return *this; }
			reverse_iterator operator--(int) { reverse_iterator tmp = *this; --(*this); return tmp; }

			/* Arithmetic */
			reverse_iterator &operator+=(difference_type offset) { m_ptr -= offset; return *this; }
			reverse_iterator &operator-=(difference_type offset) { m_ptr += offset; return *this; }
			
			reverse_iterator operator+(difference_type offset) { return reverse_iterator( m_ptr - offset ); }
			friend reverse_iterator operator+(difference_type offset, const reverse_iterator &it) { return reverse_iterator( it.m_ptr - offset ); }

			reverse_iterator operator-(difference_type offset) { return reverse_iterator( m_ptr + offset ); }
			friend reverse_iterator operator-(difference_type offset, const reverse_iterator &it) { return reverse_iterator( it.m_ptr + offset ); }
			difference_type operator-(reverse_iterator other) { return m_ptr + other.m_ptr; }

			/* Comparison operators */
			bool operator<(reverse_iterator const &it) const { return m_ptr > it.m_ptr; }
			bool operator>(reverse_iterator const &it) const { return m_ptr < it.m_ptr; }
			bool operator>=(reverse_iterator const &it) const { return m_ptr <= it.m_ptr; }
			bool operator<=(reverse_iterator const &it) const { return m_ptr >= it.m_ptr; }
			bool operator!=(reverse_iterator const &it) const { return m_ptr != it.m_ptr; }
			bool operator==(reverse_iterator const &it) const { return m_ptr == it.m_ptr; }
		private:
			pointer	m_ptr;
	};

		template<typename T>
	class const_reverse_iterator {
		public:
			typedef T								iterator_type;
			typedef std::bidirectional_iterator_tag iterator_category;
			typedef std::size_t						size_type;
			typedef std::ptrdiff_t					difference_type;
			typedef T								value_type;
			typedef T*								pointer;
			typedef T&								reference;
			typedef const T&						const_reference;

			/* Constructors */
			const_reverse_iterator() : m_ptr( NULL ) { }
			const_reverse_iterator(pointer p) : m_ptr( p ) { }
			const_reverse_iterator(const_reverse_iterator const &it) : m_ptr( it.m_ptr ) { }
			const_reverse_iterator(reverse_iterator<T> const &it) : m_ptr( it.operator->() ) {}
			const_reverse_iterator(random_access_iterator<T> const &it) : m_ptr( it.operator->() ) {}
			const_reverse_iterator(const_random_access_iterator<T> const &it) : m_ptr( it.operator->() ) {}
			const_reverse_iterator &operator=(const_reverse_iterator const &it) {
				if ( &it == this )
					return *this;
				m_ptr = it.m_ptr;
				return *this;
			}
			~const_reverse_iterator() {}

			/* Accesses operators */
			iterator_type base() const { return m_ptr; }
			const_reference operator*() const { return *m_ptr; }
			pointer operator->() const { return m_ptr; }
			const_reference operator[](difference_type offset) const { return m_ptr[offset]; }

			/* Increment / Decrement (which is inverted with reverse iterator) */
			const_reverse_iterator &operator++() { m_ptr--; return *this; };
			const_reverse_iterator operator++(int) { const_reverse_iterator tmp = *this; ++(*this); return tmp; }
			const_reverse_iterator &operator--() { m_ptr++; return *this; }
			const_reverse_iterator operator--(int) { const_reverse_iterator tmp = *this; --(*this); return tmp; }

			/* Arithmetic */
			const_reverse_iterator &operator+=(difference_type offset) { m_ptr -= offset; return *this; }
			const_reverse_iterator &operator-=(difference_type offset) { m_ptr += offset; return *this; }
			
			const_reverse_iterator operator+(difference_type offset) { return const_reverse_iterator( m_ptr - offset ); }
			friend const_reverse_iterator operator+(difference_type offset, const const_reverse_iterator &it) { return const_reverse_iterator( it.m_ptr - offset ); }

			const_reverse_iterator operator-(difference_type offset) { return const_reverse_iterator( m_ptr + offset ); }
			friend const_reverse_iterator operator-(difference_type offset, const const_reverse_iterator &it) { return const_reverse_iterator( it.m_ptr + offset ); }
			difference_type operator-(const_reverse_iterator other) { return m_ptr + other.m_ptr; }

			/* Comparison operators */
			bool operator<(const_reverse_iterator const &it) const { return m_ptr > it.m_ptr; }
			bool operator>(const_reverse_iterator const &it) const { return m_ptr < it.m_ptr; }
			bool operator>=(const_reverse_iterator const &it) const { return m_ptr <= it.m_ptr; }
			bool operator<=(const_reverse_iterator const &it) const { return m_ptr >= it.m_ptr; }
			bool operator!=(const_reverse_iterator const &it) const { return m_ptr != it.m_ptr; }
			bool operator==(const_reverse_iterator const &it) const { return m_ptr == it.m_ptr; }
		private:
			pointer	m_ptr;
	};
}

#endif