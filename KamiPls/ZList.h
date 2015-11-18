#pragma once

template <typename T>
class ZListIterator : public std::iterator<std::forward_iterator_tag, T>
{
	T* p;

public:
	explicit ZListIterator(T* x) : p(x) {}

	ZListIterator(const ZListIterator& mit) : p(mit.p) {}

	ZListIterator& operator++()
	{
		void* v2 = p ? reinterpret_cast<char *>(p) - 16 : nullptr;

		void* v3 = *(reinterpret_cast<void**>(v2) + 1);

		p = v3 ? reinterpret_cast<T*>(reinterpret_cast<char *>(v3) + 16) : nullptr;

		return *this;
	}

	ZListIterator operator++(int)
	{
		ZListIterator tmp(p);
		operator++();
		return tmp;
	}

	bool operator==(const ZListIterator& rhs) const
	{
		return p == rhs.p;
	}

	bool operator!=(const ZListIterator& rhs) const
	{
		return p != rhs.p;
	}

	T& operator*()
	{
		return *p;
	}
};


template <class T>
class ZList : public ZRefCountedAccessor<T>, public ZRefCountedAccessor<ZRefCountedDummy<T>>
{
	unsigned int count_;
	T* head_;
	T* tail_;

public:
	using iterator = ZListIterator<T>;

	virtual ~ZList() {};

	unsigned int count()
	{
		return count_;
	}

	T& operator[](unsigned idx)
	{
		iterator begin = begin(), end = end();
		for (int i = 0; i < idx; i++) {
			if (begin == end) return *tail_;
			++begin;
		}
		return *begin;
	}

	iterator begin()
	{
		return iterator(head_);
	}

	iterator end()
	{
		return iterator(nullptr);
	}
};

static_assert(sizeof(ZList<void*>) == 0x14, "ZList is the wrong size!");
