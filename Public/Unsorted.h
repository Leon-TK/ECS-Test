class Packer
{

};

class Separator
{

};

class ComponentsManager
{
	public:
		void RequestBigArray()
		{

		};
	private:
};

class SystemsManager
{
	public:
	private:
};

class BigArrayManager()
{

};

class BigArrayFactory()
{

};
class Serializer
{

};

class BigArrayPartitial
{

};

class BigArrayMerge
{

};

struct BigArray
{
	std::vector<BigChunk*> elements; //virtual paging, stack memory, dynamyc memry dont guanrantyy that any kind of data will be continius placed in memory.

};

struct BigChunk
{

};

struct RawArray
{

};

struct BigChunkSystem
{
	//todo: you cant polymorphs rawarray into bigchunk! 
	std::vector<BigChunk*> BreakRawArray(RawArray* array, uint64_t chunkSize)
	{
		std::vector<BigChunk*> chunks;
		//get array size in bytes
		size_t aSize = sizeof(array);
		//calculate chunk count
		size_t cCount = std::ceil(aSize/chunkSize); //remaing bytes will live at unfull chunk
		//get array pointer
		RawArray* curPtr = array;

		chunks.add(curPtr); //adds 0 index of array

		for (size_t i = 0; y < cCount; i++) //
		{
			curPtr += chunkSize;
			chunks.add(curPtr);
		}

	};
};


template<typedef Component, int entityCount = 0>
class Chunk_t
{
	std:vector<Component>(entityCount);
	Chunk_t()
	{
	};
};


template<typedef Chunk, int chunkCount = 0>
std::vector<Chunk>> CreateBigArray()
{
	std::vector<Chunk> bigArray;

	for (size_t i = 0; i < chunkCount; i++)
	{
		bigArray.add(new Chunk());
	}

	return bigArray;
};


Chunk_t<MovementComponent, 1600> array = CreateBigArray<Chunk_t<MovementComponent, 1600>, 100>;

//todo: do multiply component with variadic template
template<class Component1, class Component2> //<, ...>
class CombinedComponent
{
	Component1 component1;
	Component2 component2;
};

//todo: do multiply component
//combines 2 components. return copy.
template<class Component1, class Component2>
CombinedComponent<T1, T2>* AsynchCombineComponents(Component* c1, COmponent* c2)
{
	CombinedComponent<T1, T2>* combinedComponent = new CombinedComponent<T1, T2>();
	combinedComponent.component1 = *c1; //copy or move
	combinedComponent.component2 = *c2; //copy or move

	return combinedComponent

}

