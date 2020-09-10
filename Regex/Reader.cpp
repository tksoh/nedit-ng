
#include "Reader.h"

/**
 * @brief Reader
 * @param source
 * @param input
 */
Reader::Reader(view::string_view input)
	: input_(input) {
}

/**
 * @brief Reader::peek
 * @return
 */
char Reader::peek() const {

	if (eof()) {
		return '\0';
	}

	return input_[index_];
}

/**
 * @brief Reader::putback
 */
void Reader::putback() {
	if(index_ != 0) {
		--index_;
	}
}

/**
 * @brief Reader::read
 * @return
 */
char Reader::read() {

	if (eof()) {
		return '\0';
	}

	return input_[index_++];
}

/**
 * @brief Reader::eof
 * @return
 */
bool Reader::eof() const {
	return index_ == input_.size();
}

/**
 * @brief Reader::match
 * @param s
 * @return
 */
bool Reader::match(view::string_view s) {

	if (index_ + s.size() > input_.size()) {
		return false;
	}

	for (size_t i = 0; i < s.size(); ++i) {
		if (input_[index_ + i] != s[i]) {
			return false;
		}
	}

	index_ += s.size();
	return true;
}

/**
 * @brief Reader::match
 * @param ch
 * @return
 */
bool Reader::match(char ch) {

	if (peek() != ch) {
		return false;
	}

	++index_;
	return true;
}

view::string_view Reader::read_until(char ch) {

	size_t start_index = index_;

	while (char c = read()) {
		if (c == ch) {
			break;
		}
	}

	size_t end_index = index_;
	return view::string_view(&input_[start_index], end_index - start_index);
}

/**
 * @brief Reader::index
 * @return
 */
size_t Reader::index() const {
	return index_;
}

Reader::operator bool() const {
	return !eof();
}

