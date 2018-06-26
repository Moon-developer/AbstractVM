/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 13:45:38 by mafernan          #+#    #+#             */
/*   Updated: 2018/06/26 13:38:34 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include <iostream>

template <class T>
class Stack {
	public:
		Stack():top(0) {
			std::cout << "Stack constructor" << std::endl;
		}
		~Stack() {
			std::cout << "Stack destructor" << std::endl;
			while ( !isEmpty() ) {
				pop();
			}
			isEmpty();
		}

		void push (const T& object);
		T pop();
		const T& topElement();
		bool isEmpty();

	private:
		struct StackNode {              // linked list node
			T data;                     // data at this node
			StackNode *next;            // next node in list

			// StackNode constructor initializes both fields
			StackNode(const T& newData, StackNode *nextNode)
				: data(newData), next(nextNode) {}
		};

		// My Stack should not allow copy of entire stack
		Stack(const Stack& lhs) {
			(void)lhs;
		}

		// My Stack should not allow assignment of one stack to another
		Stack& operator=(const Stack& rhs) {
			(void)rhs;
		}
		StackNode *top;                 // top of stack

};

template <class T>
void Stack<T>::push(const T& obj) {
	std::cout << "PUSH Operation" << std::endl;
	top = new StackNode(obj, top);
}

template <class T>
T Stack<T>::pop() {
	std::cout << "POP Operation" << std::endl;
	if ( !isEmpty() ) {
		StackNode *topNode = top;
		top = top->next;
		T data = topNode->data;
		delete topNode;
		return data;
	}
	else
		return 0;
}

template <class T>
const T& Stack<T>::topElement() {
	std::cout << "topElement Operation" << std::endl;
	if ( !isEmpty() ) {
		return top->data;
	}
}

template <class T>
bool Stack<T>::isEmpty() {
	if (top == 0) {
		return true;
	}
	else {
		return false;
	}
}

#endif
