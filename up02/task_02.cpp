namespace numbers
{
    class complex_stack
    {
        struct Container 
        {
            complex *data;
            size_t size;

            void
            deleteData ()
            {
                if (data != nullptr) {
                    delete[] data;
                    data = nullptr;
                }
                size = 0;
            }

            void
            createData (size_t size_)
            {
                data = (size_ == 0) ? nullptr : new complex[size_];
                size = size_;
            }

            Container (size_t size_)
            {
                createData(size_);
            }

            ~Container ()
            {
                deleteData();
            }
        } container_;
               
        size_t size_;

        void
        fillData (const complex_stack & stack, size_t size)
        {
            for (size_t i = 0; i < size; ++i) {
                    container_.data[i] = stack[i];
            }
        }        

    public:
            complex_stack (size_t sz = 0):
            container_ (sz), size_ (sz) {}

            complex_stack (const complex_stack & stack):
            container_ (stack.size_), size_ (stack.size_)
            {
                fillData(stack, stack.size_);
            }

            complex_stack &
            operator= (const complex_stack & stack)
            {
                if (container_.size < stack.size_) {
                    container_.deleteData();
                    container_.createData(2 * stack.size_);
                }
                fillData(stack, stack.size_);
                size_ = stack.size_;
                return *this;
            }

            size_t
            size () const
            {
                return size_;
            }

            complex &
            operator[] (size_t i) const
            {
                return container_.data[i];
            }

            complex_stack
            operator<< (const complex &z) const
            {
                complex_stack result (size_ + 1);
                result.fillData(*this, size_);
                result[size_] = z;
                return result;
            }

            complex
            operator+ () const
            {
                return (*this)[size_ - 1];
            }

            complex_stack
            operator~ () const
            {
                complex_stack result (size_ - 1);
                result.fillData(*this, size_ - 1);
                return result;
            }
    };
}