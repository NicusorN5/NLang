#pragma once
/// <summary>
/// "Maybe" Monad wrapping a pointer T.
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T>
class Ptr
{
private:
	T* _ptr;
public:
	// return operation: T -> Ptr(T).
	Ptr(T* ptr) : _ptr(ptr) {}

	/// <summary>
	/// bind operation : Ptr(T) x (T -> Ptr(T)) -> Ptr(U)
	/// </summary>
	/// <typeparam name="U"></typeparam>
	/// <param name="value"></param>
	/// <param name="fn"></param>
	/// <returns></returns>
	template<typename U>
	auto Bind(Ptr value, Ptr<U>(*fn)(T t))
	{
		return fn(*this);
	}

	/// <summary>
	/// If this doesn't have a value, return fn(), otherwise return *this.
	/// </summary>
	/// <param name="fn">Non-null value</param>
	/// <returns>*this or fn()</returns>
	Ptr OrElse(Ptr<T>(*fn)())
	{
		if (HasValue()) return *this;
		else return fn();
	}

	/// <summary>
	/// True if T exists, false otherwise.
	/// </summary>
	/// <returns>Existance of T.</returns>
	bool HasValue() const noexcept
	{
		return _ptr != nullptr;
	}

	/// <summary>
	/// Implicit boolean conversion. Useful for if(ptr) statements.
	/// </summary>
	operator bool()
	{
		return _ptr != nullptr;
	}

	/// <summary>
	/// Returns T. No null checking.
	/// </summary>
	/// <returns>Address of T.</returns>
	T* Unwrap() const noexcept
	{
		return _ptr;
	}
};