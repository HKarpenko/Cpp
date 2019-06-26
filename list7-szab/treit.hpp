#ifndef CLASS_TREIT
#define CLASS_TREIT

template <class T>
class first_type_traits {
public:
    static bool compare(const T &lt,const T &rt){ //Like: operator >
        return lt>rt;
    }
};

template <typename T>
class second_type_traits {
public:
    static bool compare(const T &lt,const T &rt){ //Like: operator >
        return lt<rt;
    }
};

template <>
class first_type_traits<const char*> {
public:
    static bool compare(const char* lt,const char* rt); //Like: operator >
};

template <>
class second_type_traits<const char*> {
public:
    static bool compare(const char* lt,const char* rt); //Like: operator >
};

#endif // CLASS_TREIT
