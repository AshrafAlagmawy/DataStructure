#include <iostream>

using namespace std;

template <class t >

class Stack {

private:

	int top, length, max_size;
	t* array;

public:

	Stack(int s = 0) {
		max_size = s;
		length = 0;
		top = -1; // Becouse the first element starts by index 0 
		array = new t[max_size]; // Dynamic Array 
	}

	bool IsEmpty() {
		return length == 0;
	}

	bool IsFull() {
		return length >= max_size; // or use :: return top >= max_size - 1; 
	}

	void Push(t element) {

		if (IsFull())
			cout << "The Stack Is Full On Push ...! " << endl;
		else {
			array[++top] = element; // = top++; array[top] = element;
			length++;
		}
	}

	void Pop() {

		if (IsEmpty())
			cout << "The Stack Is Empty ...! " << endl;
		else {
			top--;
			length--;
		}
	}

	void Pop(t& item) {

		if (IsEmpty())
			cout << "The Stack Is Empty ...! " << endl;
		else {
			item = array[top];
			top--;
			length--;
		}
	}

	void Search_Element(t element) {

		if (IsEmpty())
			cout << "The Stack Is Empty ...! " << endl;
		else {
			bool found = false;
			int index;
			for (int i = top; i >= 0; i--) {
				if (array[i] == element) {
					found = true;
					index = i;
					break;
				}
			}
			if (found)
				cout << "The Element Is Found at index [" << index << "] . " << endl;
			else
				cout << "The Element Is Not Found . " << endl;
		}
	}

	void Get_Length() {

		if (IsEmpty())
			cout << "The Stack Is Empty ...! " << endl;
		else
			cout << "The Length Of The Elements Of The Stack = " << length << endl;
	}

	void Get_Size() {
		cout << "The Size Of The Stack = " << max_size << endl;
	}

	void Get_Top() {

		if (IsEmpty())
			cout << "The Stack Is Empty ...! " << endl;
		else
			cout << "The Top Value Of The Stack = " << array[top] << endl;
	}

	void Get_Last() {

		if (IsEmpty())
			cout << "The Stack Is Empty ...! " << endl;
		else
			cout << "The Last Value Of The Stack = " << array[0] << endl;
	}

	void ResizeStack(int NewSize) {
		if (NewSize <= max_size)
			cout << "The New Size Of The Stack Must Be Bigger Than The Old Size ...! " << endl;
		else {
			max_size = NewSize;
			t* PtrArray = array;
			array = new t[max_size];
			for (int i = 0; i <max_size; i++) {
				array[i] = PtrArray[i];
			}
			delete[]PtrArray;
		}
	}

	void Print() {

		if (IsEmpty())
			cout << "The Stack Is Empty ...! " << endl;
		else {
			cout << "The Values Of The Elemenst Of The Stack = [ ";
			for (int i = top; i >= 0; i--)
				cout << array[i] << " , ";
			cout << "\b\b] . " << endl;
		}
	}

	~Stack() { delete[]array; }

};

int main() { // Stck => L I F O - Last In First Out

	Stack <int> S(5); // Determine The Data Type Of The Stack-Implementation

	S.Push(10);
	S.Push(2);
	S.Push(30);
	S.Push(40);
	S.Push(50);
	S.Pop();
	S.Print();
	S.Get_Length();
	S.Search_Element(40);
	S.Get_Top();
	S.Get_Last();
	S.ResizeStack(7);
	S.Get_Size();
	S.Get_Length();

}
