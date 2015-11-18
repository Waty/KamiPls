#pragma once
#include "ZArray.h"
#include "ZXString.h"

#define __POSITION void

#define TEAR(x) long _ZtlSecureTear_##x##[2]; \
	unsigned int _ZtlSecureTear_##x##_CS;
#define Ztl_bstr_t BSTR

#define TEARS(x) short _ZtlSecureTear_##x##[2]; \
	unsigned int _ZtlSecureTear_##x##_CS;

#define LAYER_ALPHA -3

#define Padding(x) struct { unsigned char __padding##x[(x)]; };

struct SECRECT
{
	TEAR(left);
	TEAR(top);
	TEAR(right);
	TEAR(bottom);
};

struct RANGE
{
	long low;
	long high;
};

struct UINT128
{
	unsigned long m_data[4];
};

class IGObj
{
	~IGObj() = default;

public:
	virtual void Update() { }
};

template <typename T>
class ZList;

class IUIMsgHandler
{
	~IUIMsgHandler() = default;

public:
	virtual void OnKey(unsigned int wParam, unsigned int lParam) = 0;

	virtual int OnSetFocus(int) = 0;
	virtual void OnMouseButton(unsigned int msg, unsigned int wParam, int rx, int ry) = 0;
	virtual int OnMouseMove(int rx, int ry) = 0;
	virtual int OnMouseWheel(int, int, int) = 0;
	virtual void OnMouseEnter(bool bEnter) = 0;
	virtual void OnDraggableMove(int, void*, int, int) = 0;
	virtual void SetEnable(bool bEnable) = 0;
	virtual bool IsEnabled() = 0;
	virtual void SetShow(bool bShow) = 0;
	virtual bool IsShown() = 0;
	virtual int GetAbsLeft(IUIMsgHandler*) = 0;
	virtual int* GetAbsTop(IUIMsgHandler*) = 0;
	virtual void ClearToolTip(IUIMsgHandler*) = 0;
	virtual void OnIMEModeChange(IUIMsgHandler*, char) = 0;
	virtual void OnIMEResult(IUIMsgHandler*, const char*) = 0;
	virtual void OnIMEComp(IUIMsgHandler*, const char*, ZArray<unsigned long>*, unsigned int, int, ZList<ZXString<char>>*, int, int, int) = 0;
};

class ZRefCounted
{
public:
	union
	{
		long _m_nRef;
		ZRefCounted* _m_pNext;
	};

	ZRefCounted* _m_pPrev;

	bool IsLastRef()
	{
		return false;
	} // dummy

protected:
	virtual ~ZRefCounted() = delete; // dummy
	ZRefCounted() = delete; // dummy
};

class ZAllocBase {};

template <class T, int L, class B>
class ZRecyclable : public ZAllocBase
{
	//static ZRecyclableAvBuffer<T, L, B> *_Av();

public:
	//static void *operator new(size_t len);
	//static void *operator new[](size_t len);
	//static void operator delete(void *p);
	//static void operator delete[](void *p);
	ZRecyclable(const ZRecyclable&) { }

	ZRecyclable& operator=(const ZRecyclable&) { }

protected:
	virtual ~ZRecyclable() {}

	ZRecyclable() {}
};

template <class T>
class ZRefCountedDummy : public ZRefCounted, public ZRecyclable<ZRefCountedDummy<T>, sizeof(ZRefCounted), T>
{
	T t;

public:
	static ZRefCountedDummy* From(T* from)
	{
		int offset = sizeof(ZRefCountedDummy) - sizeof(T);
		return reinterpret_cast<ZRefCountedDummy *>(reinterpret_cast<unsigned int>(from) - offset);
	}

	operator T*()
	{
		return &t;
	}

	ZRefCountedDummy(const ZRefCountedDummy&) { }

	ZRefCountedDummy() { }

	ZRefCountedDummy& operator=(const ZRefCountedDummy&) { }

	virtual ~ZRefCountedDummy() { };
};

class ZRefCountedAccessorBase
{
protected:
	static ZRefCounted* _Set1(ZRefCounted* ref);
	static void _Delete(ZRefCounted* ref);
	static long _AddRef(ZRefCounted* ref);
	static long _Release(ZRefCounted* ref);

	static ZRefCounted* & _GetPrev(ZRefCounted* ref)
	{
		return ref->_m_pPrev;
	}

	static ZRefCounted* & _GetNext(ZRefCounted* ref)
	{
		return ref->_m_pNext;
	}

	static long& _GetLong(const ZRefCounted*);
};

template <class T>
class ZRefCountedAccessor : public ZRefCountedAccessorBase
{
protected:
	static void _Delete(T* ref)
	{
		if (ref) delete ref;
	}

	static long _AddRef(T* ref)
	{
		if (ref) return InterlockedIncrement(&ref->_m_nRef); else return 0;
	}

	static long _Release(T* ref)
	{
		if (ref) return InterlockedDecrement(&ref->_m_nRef); else return 0;
	}

	static long& _GetLong(T* ref)
	{
		return ref->_m_nRef;
	}
};

template <class T>
class ZRef
{
public:
	ZRef() { }

	operator T *()
	{
		return p;
	}

	T& operator *()
	{
		return *p;
	}

	T* operator ->()
	{
		return p;
	}

	ZRef(ZRef<T> const& rhs)
	{
		p = rhs.p;
	}

private:
	Padding(0x4);

	T* p;
};
