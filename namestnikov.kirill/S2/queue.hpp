#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <list>

namespace namestnikov
{
  template< class T >
  class Queue
  {
    using queue_t = Queue< T >;
  public:
    Queue() = default;
    Queue(const queue_t & other) = default;
    queue_t & operator=(const queue_t & other) = default;
    Queue(queue_t && other) noexcept:
      data_(std::move(other.data_))
    {}
    queue_t & operator=(queue_t && other)
    {
      if (std::addressof(other) != this)
      {
        std::swap(data_, other.data_);
      }
      return *this;
    }
    T & front()
    {
      return data_.front();
    }
    const T & front() const
    {
      return data_.front();
    }
    T & back()
    {
      return data_.back();
    }
    const T & back() const
    {
      return data_.back();
    }
    void push(const T & value)
    {
      data_.push_back(value);
    }
    void pop()
    {
      data_.pop_front();
    }
    size_t size() const noexcept
    {
      return data_.size();
    }
    bool empty() const noexcept
    {
      return data_.empty();
    }
    ~Queue() = default;
  private:
    std::list< T > data_;
  };
}

#endif