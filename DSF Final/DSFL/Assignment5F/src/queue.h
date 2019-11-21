#ifndef QUEUE_H
#define QUEUE_H

template <class T>
struct QNode
{
    T data;
    struct QNode<T> *next;
};
template<class T>
class queue
{
	public:
		struct QNode<T> *front;
    	struct QNode<T> *rear;
		void enqueue(T);
	    T dequeue();
		bool IsEmpty();
		queue();
		~queue();
	protected:
};

#endif
