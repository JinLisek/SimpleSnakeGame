class FileReaderException
{
public:
    virtual ~FileReaderException() = default;
};

class FileNotFoundException : public FileReaderException
{
public:
    ~FileNotFoundException() override = default;
};