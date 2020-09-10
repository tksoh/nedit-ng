
#ifndef READER_H_
#define READER_H_

#include <cstddef>
#include <string>
#include "Util/string_view.h"

class Reader {
public:
	explicit Reader(view::string_view input);
	Reader() = default;
	Reader(const Reader &) = default;
	Reader& operator=(const Reader &) = default;


public:
	bool eof() const;
	char peek() const;
	char read();
	bool match(char ch);
	bool match(view::string_view s);
	view::string_view read_until(char ch);

	size_t index() const;
	void putback();

public:
	explicit operator bool() const;

private:
	view::string_view input_;
	size_t index_  = 0;
};

#endif
