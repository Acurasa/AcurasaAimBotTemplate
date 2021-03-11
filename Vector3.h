
class Vector3
{
public:
	float x = 0, y = 0, z = 0;
	Vector3()
	{
		x = y = z = 0;
	}

	Vector3(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Vector3& operator+(Vector3 arg)
	{
		x += arg.x;
		y += arg.y;
		z += arg.z;
		return *this;
	}
};

template <class T>
T RPM(DWORD address)
{
	T read;
	ReadProcessMemory(HANDLE hmod, (DWORD*)address, &read, sizeof(T), 0);
	return read;
}
/*template <class T>
void WPM(DWORD address, T value)
{
	WriteProcessMemory(HANDLE hMod, (DWORD*)address, &value, sizeof(T), 0);
}*/
