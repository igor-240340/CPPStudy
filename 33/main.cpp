#include <print>
#include <vector>

struct odds_and_evens {
	std::vector<int> odds;
	std::vector<int> evens;
};

odds_and_evens separate_odds_and_evens(const std::vector<int>& arr);

int main() {
	std::vector<int> vec_un_split{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	odds_and_evens oae = separate_odds_and_evens(vec_un_split);

	for (int i : oae.evens)
		std::println("{}", i);

	std::println("");

	for (int i : oae.odds)
		std::println("{}", i);
}

odds_and_evens separate_odds_and_evens(const std::vector<int>& arr) {
	std::vector<int> odds;
	std::vector<int> evens;

	for (int i : arr) {
		if (i % 2 == 1)
			odds.push_back(i);
		else
			evens.push_back(i);
	}

	return odds_and_evens{
		.odds = odds,
		.evens = evens
	};
}
