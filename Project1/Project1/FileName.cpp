#include <iostream>


class smart_array {
private:
	int size;
	int* arr;
	int y = 0;
public:
	smart_array(int size) {
		this->size = size;
		arr = new int[size];
	}

	void add_element(int a) {
		if (this->y >= this->size) {
			throw std::length_error("You cannot add new element, you already reached the size of array");
		}
		arr[y] = a;
		this->y++;
	}

	int get_element(int a) {
		if (a >= this->size || a < 0)
			throw std::out_of_range("You cannot get this element, because it does not exist");
		return arr[a];
	}



	smart_array& operator=(const smart_array& other) {
		if (this != &other) {
			delete[] arr;

			size = other.size;
			arr = new int[size];

			for (int i = 0; i < size; ++i) {
				arr[i] = other.arr[i];
			}
			y = other.y;
		}
		return *this;
	}


	~smart_array() {
		delete[] arr;
	}

};




int main() {

	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);

		smart_array new_array(2);
		new_array.add_element(44);
		new_array.add_element(34);

		arr = new_array;

	}

	catch (const std::length_error& ex)
	{
		std::cout << "Length_error: " << ex.what() << std::endl;
	}

	catch (const std::out_of_range& ex)
	{
		std::cout << "Out_of_range_error: " << ex.what() << std::endl;
	}

	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}



	return 0;
}