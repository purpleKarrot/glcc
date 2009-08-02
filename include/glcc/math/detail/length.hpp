//template<typename T, std::size_t N>
//class lenght
//{
//	lenght(const vector<N>& vec)
//	{
//	}
//
//private:
//	T v[N];
//};

template<typename T, std::size_t N>
class length
{

private:
	T d;
};

template<typename T>
class length<T, 0>
{
	T squared() const
	{
		return 0;
	}
};

template<typename T>
DistanceProxy<T> length(const Vector<T>&);

template<typename T>
DistanceProxy<T> distance(const Vector<T>&, const Vector<T>&);

template<typename T>
class DistanceProxy: boost::less_than_comparable<DistanceProxy<T> ,
		boost::less_than_comparable<DistanceProxy<T> , T> >
{
	T dx, dy, dz;

	/// private c'tor
	DistanceProxy(T dx_, T dy_, T dz_) :
		dx(dx_), dy(dy_), dz(dz_)
	{
	}

	friend DistanceProxy length<T> (const Vector<T>&);
	friend DistanceProxy distance<T> (const Vector<T>&, const Vector<T>&);

public:
	/// implizite Umwandlung
	operator T() const
	{
		return sqrt(squared());
	}

	T squared() const
	{
		return dx * dx + dy * dy + dz * dz;
	}

	bool operator<(const DistanceProxy& other) const
	{
		return squared() < other.squared();
	}

	bool operator<(T d) const
	{
		return dx < d && dy < d && dz < d && (squared() < d * d);
	}

	bool operator>(T d) const
	{
		return dx > d || dy > d || dz > d || (squared() > d * d);
	}
};

/// berechne die Strecke zwischen zwei Punkten
template<typename T>
DistanceProxy<T> distance(const Vector<T>& a, const Vector<T>& b)
{
	return DistanceProxy<T> (a.x - b.x, a.y - b.y, a.z - b.z);
}

/// berechne die Länge eines Vektors
template<typename T>
DistanceProxy<T> length(const Vector<T>& v)
{
	return DistanceProxy<T> (v.x, v.y, v.z);
}
