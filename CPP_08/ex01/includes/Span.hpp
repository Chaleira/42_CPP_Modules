#ifndef Span_HPP
# define Span_HPP

# include <iostream>
# include <string>
# include <vector>
# include <exception>
# include <climits>

class Span
{
	private:
		std::vector<int> _arr;
		int				 _max;
		int				 _min;

	public:
		Span(unsigned int n);	
		Span(const Span &copy);
		Span &operator=(const Span &copy);
		~Span();

		void	addNumber(int n);
		int		shortestSpan();
		int		longestSpan();
		void	SpanFill(std::vector<int>::iterator begin, std::vector<int>::iterator end);

		class SpanFullException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class InvalidSpanException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif
