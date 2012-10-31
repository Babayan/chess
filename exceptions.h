#include <string>

class error
{
private:
	const std::string message;

public:
	error(const std::string&);
	const std::string& getMessage() const;
};