#ifndef VECTOR_H
#define VECTOR_H


class Vector {
    public:
        Vector();
        Vector(int capasity);
        Vector(const Vector& other);
        Vector(Vector&& other)noexcept;
        ~Vector();

        int size();
        int capacity();

        Vector& operator=(const Vector& other);
        Vector& operator=(Vector&& other);
        int& operator[](int index);

        void push_back(const int objrct);
        void push_front(const int objrct);
        void insert(int index, int objrct);

        void pop_back();
        int& at(int index);
    private:
        int m_size;
        int m_capasity;
        int* m_ptr;
};

#endif