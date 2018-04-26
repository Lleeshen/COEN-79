#include <cstdlib>

#ifndef SEQUENCE
#define SEQUENCE value

namespace mySeq
{
	class sequence {
		public:
			typedef double value_type;
			typedef std::size_t size_type;
			static const size_type CAPACITY = 50;

			sequence();
			sequence(const sequence& s1);

			void start( );
			void advance( );
			void insert(const value_type& entry);
			void attach(const value_type& entry);
			void remove_current( );
			void insert_front(const value_type& entry);
			void remove_front();
			void attach_back(const value_type& entry);
			void end();
			sequence& operator = (const sequence& s1);
			sequence& operator += (const sequence& s1);
			value_type operator [] (size_type index) const;

			size_type size() const;
			bool is_item( ) const;
			value_type current( ) const;


			friend sequence operator+ (const sequence& s1, const sequence& s2);
		private:
			value_type data[CAPACITY];
			size_type used;
			size_type current_index;
	};

	sequence operator+ (const sequence& s1, const sequence& s2);
}

#endif