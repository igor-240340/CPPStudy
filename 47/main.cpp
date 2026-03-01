#include <string>
#include <vector>
#include <print>
#include <format>

class KeyValue {
public:
	KeyValue(std::string_view key, int value) : key{ key }, value{ value } {}

	const std::string& get_key() const { return key; }
	int get_value() const { return value; }

private:
	std::string key;
	int value{ 0 };
};

template <>
class std::formatter<KeyValue> {
public:
	constexpr auto parse(auto& context) {
		string key_format, value_format;
		size_t number_of_parsed_colons{ 0 };

		auto iter{ begin(context) };
		for (; iter != end(context); ++iter) {
			if (*iter == '}') {
				break;
			}

			if (number_of_parsed_colons == 0) {
				switch (*iter) {
				case 'k': case 'K':
					output_type = OutputType::KeyOnly;
					break;
				case 'v': case 'V':
					output_type = OutputType::ValueOnly;
					break;
				case 'b': case 'B':
					output_type = OutputType::KeyAndValue;
					break;
				case ':':
					++number_of_parsed_colons;
					break;
				default:
					throw format_error{ "Invalid KeyValue format." };
				}
			}
			else if (number_of_parsed_colons == 1) {
				if (*iter == ':') {
					++number_of_parsed_colons;
				}
				else {
					key_format += *iter;
				}
			}
			else if (number_of_parsed_colons == 2) {
				value_format += *iter;
			}
		}

		if (!key_format.empty()) {
			format_parse_context key_formatter_context{
				key_format
			};
			key_formatter.parse(key_formatter_context);
		}

		if (!value_format.empty()) {
			format_parse_context value_formatter_context{
				value_format
			};
			value_formatter.parse(value_formatter_context);
		}

		if (iter != end(context) && *iter != '}') {
			throw format_error{ "Invalid KeyValue format." };
		}

		return iter;
	};

	auto format(const KeyValue& kv, auto& ctx) const {
		switch (output_type) {
			using enum OutputType;
		case KeyOnly:
			ctx.advance_to(key_formatter.format(kv.get_key(), ctx));
			break;
		case ValueOnly:
			ctx.advance_to(value_formatter.format(kv.get_value(), ctx));
			break;
		default:
			ctx.advance_to(key_formatter.format(kv.get_key(), ctx));
			ctx.advance_to(format_to(ctx.out(), " -  "));
			ctx.advance_to(value_formatter.format(kv.get_value(), ctx));
			break;
		}

		return ctx.out();
	}

private:
	enum class OutputType { KeyOnly, ValueOnly, KeyAndValue };
	OutputType output_type{ OutputType::KeyAndValue };
	formatter<string> key_formatter;
	formatter<int> value_formatter;
};

int main() {
	const size_t len{ 34 };
	KeyValue kv{ "Key 1", 255 };

	std::println("{:>{}} {}", "Default:", len, kv);
	std::println("{:>{}} {:k}", "Key only:", len, kv);
	std::println("{:>{}} {:v}", "Value only:", len, kv);
	std::println("{:>{}} {:b}", "Key and value with default format:", len, kv);
	std::println("{:>{}} {:k:*^11}", "Key only with special format:", len, kv);
	std::println("{:>{}} {:v::#06X}", "Value only with special format:", len, kv);
	std::println("{:>{}} {::*^11:#06X}", "Key and value with special format:", len, kv);

	try {
		auto formatted{ std::vformat("{:cd}", std::make_format_args(kv)) };
		std::println("{}", formatted);
	}
	catch (const std::format_error& caught_exception) {
		std::println("{}", caught_exception.what());
	}
}
