#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	protected:
		std::string	type;

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal & other);
		WrongAnimal & operator=(WrongAnimal const & other);
		virtual ~WrongAnimal();

		void makeSound() const;
		std::string getType( void ) const;
};

#endif