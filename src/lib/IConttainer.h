#include <istream>
#include <vector>

namespace s21{

    template <typename T>
    class IConttainer {
     public:
        using value_type = T;
        using reference = T&;
        using const_reference = const T&;
        using iterator = T*;
        using const_iterator = const T*;
        using size_type = size_t;

        // IConttainer() = 0;
        // IConttainer(std::initializer_list<value_type> const& items) = 0;
        // IConttainer(const IConttainer& i_container) = 0;
        // IConttainer(const IConttainer&& i_container) = 0;
        // ~IConttainer() = default;

        // virtual iterator begin() = 0;
        // virtual iterator end() = 0;
        virtual bool empty() = 0;
        virtual size_type size() = 0;
        // virtual size_type max_size() = 0;
        // virtual void clear() = 0;
    };
}
