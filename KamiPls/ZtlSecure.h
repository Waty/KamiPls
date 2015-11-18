#pragma once

template <class T>
class ZtlSecure
{
	T data[2];
	unsigned int checksum_;

public:
	T Fuse()
	{
		T result = data[0] ^ _rotl(data[1], 5);

		if (data[1] + _rotr(data[0] ^ 0xBAADF00D, 5) != checksum_) {
			throw std::exception("checksum didn't match!!!");
		}
		return result;
	}

	unsigned Tear(T value)
	{
		auto randValue = rand();
		data[0] = randValue;
		data[1] = _rotr(value ^ randValue, 5);
		checksum_ = data[1] + _rotr(randValue ^ 0xBAADF00D, 5);
		return checksum_;
	}

	operator T()
	{
		return Fuse();
	}
	unsigned operator=(T value)
	{
		return Tear(value);
	}
};

static_assert(sizeof(ZtlSecure<unsigned>) == 0xC, "ZtlSecure is the wrong size");
