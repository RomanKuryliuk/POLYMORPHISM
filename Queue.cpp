#include "Queue.h"

template<class Type>
inline Queue<Type>* Queue<Type>::first(Type d)
{
	Queue<Type>* pv = new Queue<Type>;
	pv->d = 0;
	pv->p = 0;
	return pv;
}

template<class Type>
void Queue<Type>::add(Queue<Type>** pend, Type d)
{
	Queue<Type>* pv = new Queue<Type>;
	pv->d = d;
	pv->p = 0;
	(*pend)->p = pv;
	*pend = pv;
}

template<class Type>
Type Queue<Type>::del(Queue<Type>**pbeg)
{
	Type temp = (*pbeg)->d;
	Queue<Type>* pv = *pbeg;
	*pbeg = (*pbeg)->p;
	delete pv;
	return temp;
}
