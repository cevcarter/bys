

#ifndef INPUT_H
#define INPUT_H

template <class T>
class SimpleInput {
private:
    vector<T>* buffer = new vector<T>();

public:
    vector<T> getBuffer() { return *buffer; }
    void push(T x) { buffer->push_back(x); }
};

#endif
