
class fexception {
public:
    fexception(const char* fmt, ...);

    const char* what() { return _what; };

private:
    char* _what;
};
