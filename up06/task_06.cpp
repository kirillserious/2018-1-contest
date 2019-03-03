class String
{
private:
    struct Buffer;
    Buffer buffer;
public:
    String (const char *buf = NULL);
    String (const String &);

    String & operator =  (const String &);
    String & operator += (const String &);

    char &   operator [] (int);
    operator std::string () const;
private:
};