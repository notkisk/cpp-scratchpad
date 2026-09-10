#include <chrono>
#include <iostream>
#include <random>


// int main(){
//   // std::mt19937 mt {}; // intitntiate a 32-bit mersene twister
//   //
//   // for (int count {1}; count <=40; ++count){
//   //   std::cout << mt() << '\t'; // calling mt() generates a random 32bit number
//   //   if(count % 5 == 0)
//   //     std::cout << '\n';
//   // }
//
//   // std::mt19937_64 mt_64{static_cast<std::mt19937_64::result_type>(
//     // std::chrono::steady_clock().now().time_since_epoch().count())
//   }; // intitntiate a 64-bit mersene twister, use system clock to initlize the seed
//   // std::mt19937_64 mt_64_random_device{std::random_device{}()};
//
//   // for (int count {1}; count <=40; ++count){
//   //   std::cout << mt_64() << '\t'; // calling mt() generates a random 32bit number
//   //   if(count % 5 == 0)
//   //     std::cout << '\n';
//   // }
//   // std::uniform_int_distribution<int> die6{1,6};
//
// 	//  for (int count{ 1 }; count <= 40; ++count)
// 	// {
// 	// 	std::cout << die6(mt_64) << '\t'; // generate a roll of the die here
// 	//
// 	// 	// If we've printed 10 numbers, start a new row
// 	// 	if (count % 10 == 0)
// 	// 		std::cout << '\n';
// 	// }
//   // while (true){
//   //   std::cout << std::chrono::steady_clock::now().time_since_epoch().count() << '\n';
//   // }
//   //
//   std::random_device rd{};
// 	std::seed_seq ss{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() }; // get 8 integers of random numbers from std::random_device for our seed
// 	std::mt19937 mt{ ss }; // initialize our Mersenne Twister with the std::seed_seq
//
// 	// Create a reusable random number generator that generates uniform numbers between 1 and 6
// 	std::uniform_int_distribution<int> die6{ 1, 6 }; // for C++14, use std::uniform_int_distribution<> die6{ 1, 6 };
//
// 	// Print a bunch of random numbers
// 	for (int count{ 1 }; count <= 40; ++count)
// 	{
// 		std::cout << die6(mt) << '\t'; // generate a roll of the die here
//
// 		// If we've printed 10 numbers, start a new row
// 		if (count % 10 == 0)
// 			std::cout << '\n';
// 	}
//   return 0;
// }


int main()
{
	std::random_device rd{};
	std::seed_seq ss{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() }; // get 8 integers of random numbers from std::random_device for our seed
	std::mt19937 mt{ ss }; // initialize our Mersenne Twister with the std::seed_seq

	// Create a reusable random number generator that generates uniform numbers between 1 and 6
	std::uniform_int_distribution die6{ 1, 6 }; // for C++14, use std::uniform_int_distribution<> die6{ 1, 6 };

	// Print a bunch of random numbers
	for (int count{ 1 }; count <= 40; ++count)
	{
		std::cout << die6(mt) << '\t'; // generate a roll of the die here

		// If we've printed 10 numbers, start a new row
		if (count % 10 == 0)
			std::cout << '\n';
	}

	return 0;
}
