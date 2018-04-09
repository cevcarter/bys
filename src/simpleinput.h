

#ifndef INPUT_H
#define INPUT_H

template <class T>
class SimpleInput {
private:
    vector<T> buffer;

public:
    vector<T> getBuffer() { return buffer; }
};

#endif
