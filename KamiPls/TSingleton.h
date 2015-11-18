#pragma once

template <typename T, int addy>
class TSingleton
{
	TSingleton() = delete;
	~TSingleton() = delete;
public:
	static T* GetInstance()
	{
		return *reinterpret_cast<T**>(addy);
	}

	static bool IsInitialized()
	{
		return GetInstance() != nullptr;
	}
};
