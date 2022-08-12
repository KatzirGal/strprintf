#include<stdio.h>
#include<string>

template<typename... ARGS>
class strprintf : public std::basic_string<char>
{
public:
	strprintf(const char* format, ARGS... args)
	{
		int len = _scprintf(format, args...) + 1;
		resize(len);
		sprintf_s((char* const)c_str(), len, format, args...);
	}

	operator const char* ()
	{
		return &this->at(0);
	}
};

template<typename... ARGS>
class wstrprintf : public std::basic_string<wchar_t>
{
public:
	wstrprintf(const wchar_t* format, ARGS... args)
	{
		int len = _scwprintf(format, args...) + 1;
		resize(len);
		swprintf_s((wchar_t* const)c_str(), len, format, args...);
	}

	operator const wchar_t* ()
	{
		return &this->at(0);
	}
};

int main()
{
	std::string ex1 = strprintf("first %s %d", "string", 240);
	printf("%s\n", ex1.c_str());

	std::wstring ex2 = wstrprintf(L"second %s %f", L"string", 0.3f);
	wprintf(L"%s\n", ex2.c_str());

	return 0;
}