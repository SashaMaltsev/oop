#include <iostream>
#include <string>


class Hex {
private: 
    unsigned char* data_;
    size_t size_;

public:
    Hex();
    Hex(const size_t& n, unsigned char t = '0');
    Hex(const std::initializer_list<unsigned char>& t);
    Hex(const std::string& t);
    Hex(const Hex& other);
    Hex(Hex&& other) noexcept;
    virtual ~Hex() noexcept;

    void Swap(Hex& other);

    bool operator== (const Hex& other) const; 
    bool operator< (const Hex& other) const; 
    bool operator> (const Hex& other) const; 
    bool operator= (const Hex& other) const; 
    void operator= (const Hex& other);

    size_t Size();
    unsigned char* Data();

};


Hex::Hex() : data_(new unsigned char[1]), size_(1) {
    this->data_[0] = '0';
}


Hex::Hex(const size_t& n, unsigned char t) : data_(new unsigned char[n]), size_(n) {
    for (int i = 0; i < this->size_; ++i) {
        this->data_[i] = t;
    }
}


Hex::Hex(const std::initializer_list<unsigned char>& t) : size_(t.size()) {
    this->data_ = new unsigned char[this->size_];
    std::copy(t.begin(), t.end(), this->data_);
}


Hex::Hex(const std::string& t) : size_(t.size()) {

    this->data_ = new unsigned char[this->size_];

    for (size_t i = 0; i < this->size_; ++i) {
        if (!std::isxdigit(t[i])) {
            throw std::invalid_argument("");
        }
        this->data_[i] = static_cast<unsigned char>(std::tolower(t[i]));
    }
}


Hex::Hex(const Hex& other) : data_(new unsigned char[other.size_]), size_(other.size_) {
    std::copy(other.data_, other.data_ + this->size_, this->data_);
}


Hex::Hex(Hex&& other) noexcept : data_(other.data_), size_(other.size_) {
    other.data_ = nullptr;
    other.size_ = 0;
}


Hex::~Hex() noexcept {
    delete[] this->data_;
}


void Hex::Swap(Hex& other) {
    std::swap(this->data_, other.data_);
    std::swap(this->size_, other.size_);
}


bool Hex::operator== (const Hex& other) const {
    if (this->size_ != other.size_) {
        return false;
    }

    for (size_t i = 0; i < size_; ++i) {
        if (this->data_[i] != other.data_[i]) {
            return false;
        }
    }

    return true;
}


bool Hex::operator< (const Hex& other) const {
    if (this->size_ < other.size_) {
        return true;
    } else if (this->size_ > other.size_) {
        return false;
    } else {
        for (int i = this->size_ - 1; i >= 0; --i) {
            if (this->data_[i] < other.data_[i]) {
                return true;
            } else if (this->data_[i] > other.data_[i]) {
                return false;
            }
        }
        return false;
    }
}


bool Hex::operator> (const Hex& other) const {
    return !(*this < other) && !(*this == other);
}


void Hex::operator=(const Hex &other) {
    auto copy = Hex(other);
    Swap(copy);
}

size_t Hex::Size() {
    return this->size_;
}

unsigned char *Hex::Data() {
    return this->data_;
}
