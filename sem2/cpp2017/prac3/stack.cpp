
#include "stack.h"

void stack::ensure_capacity( size_t c )
{
	if( current_capacity < c )
	{
		// New capacity will be the greater of c and
		// 2 * current_capacity.
		if( c < 2 * current_capacity )
			c = 2 * current_capacity;

		double* newtab = new double[ c ];
		for( size_t i = 0; i < current_size; ++ i )
			newtab[i] = tab[i];

			current_capacity = c;
			delete[] tab;
			tab = newtab;
	}
}


void stack::operator = ( const stack& s ){

	current_size = s.current_size;
	current_capacity = s.current_capacity;

	double* newtab = new double[ current_size ];
	for( size_t i = 0; i < current_size; ++ i )
		newtab[i] = s.tab[i];

		delete[] tab;
		tab = newtab;
}
	// These are the essential methods.
	// Later we will also encounter
	// void operator = ( stack&& s ) and
	// stack( stack&& s ).

void stack::push( double d ){

	ensure_capacity(current_size+1);
	current_size++;

	tab[current_size-1] = d;

}  // Use ensure_capacity, so that
	// pushing is always possible, as
	// long as memory is not full.

void stack::pop( ){
	if ( current_size ) current_size--;
}
	// Remove one element from the stack. It’s OK to write
	// code that crashes, as long as you write clearly what are
	// your preconditions, so:
	// PRECONDITION:  The stack is not empty.
	// Concerning preconditions, there are two reasonable
	// behaviors: (1) state them, and leave all responsibility t
	//                the caller.
	//            (2) state them, and throw std::runtime_error when
	//                not met. Don’t use assert.

void stack::reset( size_t s ){
		while (current_size > s)
			this->pop();
}
	// Pops element until stack has size s.
	// PRECONDITION: s <= current_size.

double& stack::top( ){
	if (current_size==0)
		throw new std::runtime_error("Stack is empty.");
	return tab[current_size-1];
}

double stack::top( ) const {
	if (current_size==0)
		throw new std::runtime_error("Stack is empty.");
	return tab[current_size-1];	


}	// The second one is used when stack was declared const.
	// The first one allows assignment.
	// Both have precondition that the stack is non-empty.