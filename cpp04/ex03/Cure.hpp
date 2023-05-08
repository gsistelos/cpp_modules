#ifndef CURE_HPP
#define CURE_HPP

class Cure : public AMateria
{
public:
	Cure(void);

	AMateria* clone() const;
};

#endif /* CURE_HPP */
