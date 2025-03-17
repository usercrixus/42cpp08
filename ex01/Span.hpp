#include <iostream>
#include <vector>
#include <algorithm> // For std::min_element, std::max_element, std::sort
#include <stdexcept> // For std::runtime_error

class Span
{
private:
	std::vector<int> _data;
	int _max;

public:
	Span(int n);
	~Span();

	void addNumber(int n);
	int shortestSpan();
	int longestSpan();
};

Span::Span(int n)
{
	_max = n;
}

Span::~Span()
{
}

inline void Span::addNumber(int n)
{
	if (_data.size() < n)
		_data.push_back(n);
	else
		throw std::runtime_error("List is full");
}

int Span::shortestSpan() {
	if (_data.size() < 2)
		throw std::runtime_error("Error: Not enough elements for a span!");

	// Sort the numbers to easily calculate differences
	std::vector<int> sortedNumbers = _data;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());

	// Find the minimum difference between consecutive elements
	int minSpan = sortedNumbers[1] - sortedNumbers[0];
	for (size_t i = 1; i < sortedNumbers.size() - 1; ++i) {
		int diff = sortedNumbers[i + 1] - sortedNumbers[i];
		if (diff < minSpan) {
			minSpan = diff;
		}
	}

	return minSpan;
}

int Span::longestSpan() {
	if (_data.size() < 2)
		throw std::runtime_error("Error: Not enough elements for a span!");

	int minValue = *std::min_element(_data.begin(), _data.end());
	int maxValue = *std::max_element(_data.begin(), _data.end());

	return maxValue - minValue;
}