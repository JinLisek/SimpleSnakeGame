template<typename T, typename UniqueParameter>
class StrongType
{
public:
    explicit StrongType(const T& val) : _value(val) {}
    explicit StrongType(T&& val) : _value(std::move(val)) {}
    
    T& get()
    {
        return _value;
    }

    const T& get() const
    {
        return _value;
    }

private:
    T _value;
};