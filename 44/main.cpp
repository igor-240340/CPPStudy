#include <string>
#include <print>
#include <string_view>

enum class Language { English, Dutch };

std::string_view get_localized_format(Language language) {
	switch (language) {
	case Language::English:
		return "Numbers: {0} and {1}.";
	case Language::Dutch:
		return "Getallen: {0} en {1}.";
	}
}

int main() {
	Language language{ Language::English };
	int a = 1;
	int b = 2;
	std::vprint_unicode(stdout, get_localized_format(language), std::make_format_args(a, b));
	
	std::println("");

	language = Language::Dutch;
	std::vprint_unicode(stdout, get_localized_format(language), std::make_format_args(a, b));
}
