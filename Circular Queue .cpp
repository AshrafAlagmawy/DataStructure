#include <iostream>

using namespace std;

template <class t >

class Queue {

private:

	int first, last, max_size, length;
	t* array;

public:
	Queue() {}

	Queue(int s) {
		max_size = s;
		length = 0;
		first = 0;
		last = max_size - 1;
	}

	bool IsEmpty() {
		return length == 0;
	}

	bool IsFull() {
		return length >= max_size; 
	}

	void EnQueue(t element) {

		if (IsFull())
			cout << "The Queue Is Full On Push ...! " << endl;
		else {
			last = (last + 1) % max_size;
			array[last] = element;
			length++;
		}
	}

	void DeQueue() {

		if (IsEmpty())
			cout << "The Queue Is Empty On Pop ...! " << endl;
		else {
			first = (first + 1) % max_size;
			length--;
		}
	}

	void DeQueue(t& item) {

		if (IsEmpty())
			cout << "The Queue Is Empty On Pop ...! " << endl;
		else {
			item = array[first];
			first = (first + 1) % max_size;
			length--;
		}
	}

	void Get_Length() {

		if (length == 0)
			cout << "The Queue Is Empty ...! " << endl;
		else
			cout << "The Length Of The Queue = " << length << endl;
	}

	void Get_First() {

		if (IsEmpty())
			cout << "The Queue Is Empty On Pop ...! " << endl;
		else
			cout << "The First Element Of The Queue = " << array[first] << endl;
	}

	void Get_Last() {

		if (IsEmpty())
			cout << "The Queue Is Empty On Pop ...! " << endl;
		else
			cout << "The Last Element Of The Queue = " << array[last] << endl;
	}

	void Search_Elements(t element) {

		if (IsEmpty())
			cout << "The Queue Is Empty On Pop ...! " << endl;
		else {

			bool found = false;
			
			for (int i = first; i != last; i = (i + 1) % max_size) {
				if (array[i] == element) {
					found = true;
					break;
				}
			}
			if (array[last] == element)
				found = true;

			if (found)
				cout << "The Element Is Found . " << endl;
			else
				cout << "The Element Is Not Found . " << endl;
		}
	}

	void Print() {

		if (IsEmpty())
			cout << "The Queue Is Empty On Pop ...! " << endl;
		else {
			cout << "The Values Of The Elements Of The Queue = [ ";
			for (int i = first; i != last; i = (i + 1) % max_size)
				cout << array[i] << " , ";
			cout << array[last] << " ] . " << endl;
		}
	}

};

int main() {

	Queue <int> Q(7);

	Q.EnQueue(1);
	Q.EnQueue(2);
	Q.EnQueue(3);
	Q.EnQueue(4);
	Q.EnQueue(5);
	Q.EnQueue(6);
	Q.Get_First();
	Q.Get_Last();
	Q.Get_Length();
	Q.Print();
}