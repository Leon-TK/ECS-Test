struct Entity
{
private:
	friend EntityManager;
	uint64_t id;
};

class EntityCompound
{
	Entity* entity;
	std::vector<Component*> components;
};

class SystemCompound
{
	EntityCompound* entityCompound;
	std::vector<System*> system;
};

class EntityManager
{
	void IncrementEntityId(Entity* entity)
	{
		entity->id++;
	}
	void AddEntityToPackage
};
