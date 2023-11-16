#include <iostream>
#include <string.h>

//библиотека algorithm
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <list>
#include <deque>
#include <random>


int GetNum() {

	static int val{};
	return ++val;

	
}

int GetNum2() {

	return std::random_device()()%100;
}

int Solution() {
	static std::random_device rd;
	std::uniform_int_distribution<int> distr(-10, 10);

	return distr(rd);
}

int AnotherSolution() {
	static std::random_device rd;
	std::uniform_int_distribution<int> distr(0, 20);

	return distr(rd);
}

int main() {

	setlocale(LC_ALL, "ru");
	srand(time(NULL));


	//зополнение коллекции
	std::vector<int> arr(10);
	for (auto &i : arr)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;


	//заполняет все что было между началом и концом пятерками
	std::fill(arr.begin(), arr.end(), 5); 
	for (auto& i : arr)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;


	//брат-близнец фила (заполняет тем что было в функции)
	std::generate(arr.begin(), arr.end(), GetNum); 
	for (auto& i : arr)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	//заполняет рандомными числами
	std::shuffle(arr.begin(), arr.end(), std::random_device());
	for (auto& i : arr)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	//ещё что-то
	std::generate(arr.begin(), arr.end(), GetNum2);
	for (auto& i : arr)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	//по возрастанию
	std::stable_sort(arr.begin(), arr.end());
	for (auto& i : arr)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;


	//std::cout << std::max(3,-4) << "\n";

	//std::rfinf -> мщет справо на лево и если ниче не найдёт но выдаст конец с права 

	auto res = std::find(arr.begin(), arr.end(), 5);
	if (res != arr.end()) {
		std::cout << *res << " was found on place " << &(*res);
	}




	std::cout << "\n\nзадание: \n";
	std::vector<int> arrFirst(20);
	std::generate(arrFirst.begin(), arrFirst.end(), Solution);
	for (auto& i1 : arrFirst)
	{
		std::cout << i1 << " ";
	}
	std::cout << std::endl;


	std::vector<int> arrSecond(20);
	std::generate(arrSecond.begin(), arrSecond.end(), AnotherSolution);
	for (auto& i2 : arrSecond)
	{
		std::cout << i2 << " ";
	}
	std::cout << std::endl;
	

	std::vector<int> FullArr;

	for (auto& i1 : arrFirst)
	{
		for (auto& i2 : arrSecond) {

			if (i1 == i2) {
				FullArr.push_back(i1);
				
			}

		}
	}
	for (auto& i1 : FullArr) {
		std::cout << i1 << " ";
	}
	std::cout << std::endl;





	return 0;
}